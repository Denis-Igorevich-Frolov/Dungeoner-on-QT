/************************************************************************************************************
 *Данный класс является прогрессбаром разделённым на ячейки. Он предназначен пока что только для
 *магической защиты. Общее значение складывается из векторов фрагментов прогрессбара (Сhunk).
 *Максимальное количество родных чанков 50, но бонусные чанки могут расширить предел до 60. Всё,
 *что не влезло в эти пределы усекается.
 *
 *Важно то, что частично заполненным может быть только один чанк, если такой чанк не первый, то
 *все чанки до него должны быть полностью заполненными, а все чанки после - полностью пустыми.
 *По этому, хоть вектор chunks и имеет сеттер, он предназначен только для первичной инициализации,
 *все же последующие вычисления производятся при помощи методов addValue, subtractValue, HealOneChunk,
 *spendLastChunk и т.д.
 *
 *addBonusChunk добавляет незаполненные ячейки в конец прогрессбара. Медод добавит незаполненную
 *ячейку даже если передать заполненную. Бонусные чанки добавляются всегда в конец, всегда уже
 *после родных чанков. При удалении бонусных чанков итератор делает обход с конца вектора.
 *
 *Надпись прогрессбара выводит информацию в формате
 *Текущий чанк / Всего чанков(текущее значение чанка / Максимальное значение чанка)
 ************************************************************************************************************/

#include "progressbar_2.h"
#include "qpainter.h"
#include "qvector.h"
#include "ui_progressbar_2.h"
#include "PB2_stylemaster.h"

#include <QDate>
#include <QFile>

ProgressBar_2::ProgressBar_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar_2)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->BordersWrapper->setStyleSheet(PB2_StyleMaster::BordersStyle());
    ui->TipsWrapper->setStyleSheet(PB2_StyleMaster::TipsStyle());
    ui->ShadowWrapper->setStyleSheet(PB2_StyleMaster::ShadowStyle());
    //Задаётся стиль текста лейбла с подсказкой как "ЧИСЛА"
    ui->labelWithTooltip->setFontType(LabelWithTooltip::NUMBERS);
    ui->labelWithTooltip->setOutlineThickness(2);
}

ProgressBar_2::~ProgressBar_2()
{
    /*Достаточно очистить только вектор nativeChunks так как содержимое
     *bonusChunks очищается в классах, которые передали сюда ссылки*/
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    //SeparatorWrapper нужно очистить так как эллементам в нём память вызывалась динамически
    qDeleteAll(ui->SeparatorWrapper->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

    delete ui;
}

void ProgressBar_2::setColor(const QColor &newColor)
{
    color = newColor;
}

const QVector<Chunk*> &ProgressBar_2::getChunks() const
{
    return chunks;
}

//Метод задаёт родные чанки (nativeChunks)
void ProgressBar_2::setChunks(const QVector<Chunk*> &newChunks)
{
    //Вызов этого метода означает переинициализацию и следовательно необходимо уничтожить все старые ссылки
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    /*Максимальная длина вектора родных чанков равна 50, если
     *она привышена, то вектор усекается до 50 значений*/
    if(newChunks.size()>50){
        QVector<Chunk*> newNChunks;
        for(int i = 0; i<50; i++)
            newNChunks.append(newChunks.at(i));
        nativeChunks = newNChunks;

        /*Так как вектор родных чанков динамически генерируется каждый раз заного и неуместившиеся ячейки
         *никогда не понадобятся, необходимо высвобождение памяти у остатка переданного вектора*/
        QVectorIterator<Chunk*> iterator(newChunks);
        iterator.toBack();
        Chunk* c;
        for(int i = newChunks.size(); i>50; i--){
            c = iterator.previous();
            delete c;
        }
    }else
        nativeChunks = newChunks;

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

/*Метод задаёт бонусные чанки (bonusChunks). Новые чанки будут иметь текущие значения 0,
 *так как все бонусы дают прибавку только к максимальному значению,а не к текущему.*/
void ProgressBar_2::setBonusChunks(const QVector<Chunk*> &newChunks)
{
    /*Так как ссылки на бонусные чанки хранятся и удаляются в классах,
     *которые их сюда направили, высвобождение памяти не требуется*/

    //обнуление значений
    for(Chunk* chunk : newChunks)
        chunk->setValue(0);

    bonusChunks = newChunks;

    /*Все усечения векторов и заполнение finalBonusChunks происходят в методе
     *recalculationChunks, который вызывается в recalculationChunkWidth*/

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

LabelWithTooltip* ProgressBar_2::getLabelWithTooltip()
{
    return ui->labelWithTooltip;
}

/*Метод возвращает индекс текущего активного чанка. Текущим чанком
 *считается последний чанк, имеющий ненулевое значение.*/
int ProgressBar_2::getCurrentChunkIndex()
{
    int currentChunk = 0;

    for(int i = 0; i<chunks.size(); i++)
        if(chunks.at(i)->getValue()!=0)
           currentChunk++;
        /*Если значение чанка равно нулю, то и значения всех последующих
         *чанков будут также равны нулю и нет смысла дальше гонять цикл*/
        else break;

    /*Если полученное значение равно 0, то прогрессбар пуст,
     *просто возвращается 0, как индекс самого первого чанка*/
    if(currentChunk == 0)
        return 0;

    /*Если же полученное значение нулю не равно, то порядковый
     *номер (отсчёт с 1) приводится к индексу (отсчёт с 0).*/
    return currentChunk-1;
}

/*Метод добавляет значение к текущему чанку. Если максимальное значение чанка не позволяет
 *переданному значению уместиться в нём полностью, то остаток переходит на следующий чанк,
 *и так пока либо не кончится значение, либо не кончатся чанки.*/
void ProgressBar_2::addValue(int value)
{
    //Предотвращение попадания в метод отрицательных значений
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    //Цикл идёт либо пока не кончится всё значение прибавки, либо пока не кончатся сами чанки
    while(value>0){
        //Если цикл дошёл до конца вектора чанков, то прибавка сразу прекращается
        if(currentChunk+1 > chunks.size())
            break;

        chunk = chunks.at(currentChunk);
        //Вычисляется разница максимального и текущего значения у текущего чанка
        int difference = chunk->getMaxValue() - chunk->getValue();

        /*Если эта разница меньше прибавляемого значения, то чанк полностью заполняется, а из
         *прибавляемого значения вычитается разница. То есть итоговое значение прибавки после
         *этого равняется остатку от максимального заполнения одного чанка переданным значением.*/
        if(value>difference){
            chunk->setValue(chunk->getMaxValue());
            value-=difference;
        }else{
            /*Если же разница больше прибавляемого значения, то это значение просто
             *прибавляется к текущему значению чанка и обнуляется завершая цикл.*/
            chunk->setValue(chunk->getValue()+value);
            value = 0;
        }
        currentChunk++;
    }

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

void ProgressBar_2::subtractValue(int value)
{
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    while(value>0){
        if(currentChunk == -1)
            break;

        chunk = chunks.at(currentChunk);

        if(chunk->getValue()==0)
            break;

        if(value>chunk->getValue()){
            value-=chunk->getValue();
            chunk->setValue(0);
        }else{
            chunk->setValue(chunk->getValue()-value);
            value = 0;
        }
        currentChunk--;
    }

    recalculationChunkWidth();
}

void ProgressBar_2::addBonusChunk(Chunk* chunk)
{
    chunk->setValue(0);
    bonusChunks.append(chunk);
    recalculationChunkWidth();
}

void ProgressBar_2::addBonusChunk(QVector<Chunk *> chunks)
{
    for(Chunk* chunk : chunks)
        chunk->setValue(0);
    bonusChunks.append(chunks);
    recalculationChunkWidth();
}

bool ProgressBar_2::removeBonusChunk(Chunk *chunk)
{
    QMutableVectorIterator<Chunk*> iterator(bonusChunks);
    iterator.toBack();
    Chunk* c;
    while(iterator.hasPrevious()){
        c = iterator.previous();
        if(c->getMaxValue()==chunk->getMaxValue()){
            delete c;
            iterator.remove();
            recalculationChunkWidth();
            return true;
        }
    }
    /*Если ничего найдено небыло, то выводится предупреждение. Вызывающему классу следует
     *запросить полный пересчёт всех векторов чанков и провести их полную переинициализацию.*/

    //Вывод предупреждения в консоль и файл
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    QString error =
    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
    "\nПРЕДУПРЕЖДЕНИЕ: не найден Chunk\n"
    "ProgressBar_2 выдал предупреждение в методе removeBonusChunk.\n"
    "При попытке удалить Chunk, он не был обнаружен.\n\n";
    qDebug()<<error;

    QFile errorFile("error log.txt");
    if (!errorFile.open(QIODevice::Append))
    {
        qDebug() << "Ошибка при открытии файла логов";
    }else{
        errorFile.open(QIODevice::Append  | QIODevice::Text);
        QTextStream writeStream(&errorFile);
        writeStream<<error;
        errorFile.close();
    }
    return false;
}

bool ProgressBar_2::removeBonusChunk(int maxValue)
{
    QMutableVectorIterator<Chunk*> iterator(bonusChunks);
    iterator.toBack();
    Chunk* c;
    while(iterator.hasPrevious()){
        c = iterator.previous();
        if(c->getMaxValue()==maxValue){
            delete c;
            iterator.remove();
            recalculationChunkWidth();
            return true;
        }
    }
    /*Если ничего найдено небыло, то выводится предупреждение. Вызывающему классу следует
     *запросить полный пересчёт всех векторов чанков и провести их полную переинициализацию.*/

    //Вывод предупреждения в консоль и файл
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    QString error =
    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
    "\nПРЕДУПРЕЖДЕНИЕ: не найден Chunk\n"
    "ProgressBar_2 выдал предупреждение в методе removeBonusChunk.\n"
    "При попытке удалить Chunk, он не был обнаружен.\n\n";
    qDebug()<<error;

    QFile errorFile("error log.txt");
    if (!errorFile.open(QIODevice::Append))
    {
        qDebug() << "Ошибка при открытии файла логов";
    }else{
        errorFile.open(QIODevice::Append  | QIODevice::Text);
        QTextStream writeStream(&errorFile);
        writeStream<<error;
        errorFile.close();
    }
    return false;
}

bool ProgressBar_2::removeBonusChunk(QVector<Chunk *> chunks)
{
    int successfulFinds = 0;
    for(Chunk* chunk : chunks){
        QMutableVectorIterator<Chunk*> iterator(bonusChunks);
        iterator.toBack();
        Chunk* c;
        while(iterator.hasPrevious()){
            c = iterator.previous();
            if(c->getMaxValue()==chunk->getMaxValue()){
                delete c;
                iterator.remove();
                successfulFinds++;
                break;
            }
        }
    }

    recalculationChunkWidth();

    if(successfulFinds==chunks.size())
        return true;
    else
    {
        /*Если не были найдены все переданные чанки, то выводится предупреждение. Вызывающему классу следует
         *запросить полный пересчёт всех векторов чанков и провести их полную переинициализацию.*/

        //Вывод предупреждения в консоль и файл
        QDate cd = QDate::currentDate();
        QTime ct = QTime::currentTime();

        QString error =
        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
        "\nПРЕДУПРЕЖДЕНИЕ: не найден Chunk\n"
        "ProgressBar_2 выдал предупреждение в методе removeBonusChunk.\n"
        "При попытке удалить Chunk, он не был обнаружен.\n\n";
        qDebug()<<error;

        QFile errorFile("error log.txt");
        if (!errorFile.open(QIODevice::Append))
        {
            qDebug() << "Ошибка при открытии файла логов";
        }else{
            errorFile.open(QIODevice::Append  | QIODevice::Text);
            QTextStream writeStream(&errorFile);
            writeStream<<error;
            errorFile.close();
        }
        return false;
    }
}

bool ProgressBar_2::removeBonusChunk(QVector<int> maxValues)
{
    int successfulFinds = 0;
    for(int i : maxValues){
        QMutableVectorIterator<Chunk*> iterator(bonusChunks);
        iterator.toBack();
        Chunk* c;
        while(iterator.hasPrevious()){
            c = iterator.previous();
            if(c->getMaxValue()==i){
                delete c;
                iterator.remove();
                successfulFinds++;
                break;
            }
        }
    }

    recalculationChunkWidth();

    if(successfulFinds==maxValues.size())
        return true;
    else
    {
        /*Если не были найдены все переданные чанки, то выводится предупреждение. Вызывающему классу следует
         *запросить полный пересчёт всех векторов чанков и провести их полную переинициализацию.*/

        //Вывод предупреждения в консоль и файл
        QDate cd = QDate::currentDate();
        QTime ct = QTime::currentTime();

        QString error =
        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
        "\nПРЕДУПРЕЖДЕНИЕ: не найден Chunk\n"
        "ProgressBar_2 выдал предупреждение в методе removeBonusChunk.\n"
        "При попытке удалить Chunk, он не был обнаружен.\n\n";
        qDebug()<<error;

        QFile errorFile("error log.txt");
        if (!errorFile.open(QIODevice::Append))
        {
            qDebug() << "Ошибка при открытии файла логов";
        }else{
            errorFile.open(QIODevice::Append  | QIODevice::Text);
            QTextStream writeStream(&errorFile);
            writeStream<<error;
            errorFile.close();
        }
        return false;
    }
}

bool ProgressBar_2::spendLastChunk()
{
    if(chunks.size()>0){
        int chunkIndex = getCurrentChunkIndex();
        if(chunks.at(chunkIndex)->getValue()!=0){
            chunks.at(chunkIndex)->setValue(0);
            return true;
        }else
            return false;
    }else
        return false;
}

void ProgressBar_2::HealOneChunk()
{
    for(Chunk* chunk : chunks)
        if (chunk->getValue()!=chunk->getMaxValue()){
            chunk->setValue(chunk->getMaxValue());
            break;
        }
    recalculationChunkWidth();
}

void ProgressBar_2::HealAllChunk()
{
    for(Chunk* chunk : chunks)
        chunk->setValue(chunk->getMaxValue());
    recalculationChunkWidth();
}

void ProgressBar_2::recalculationChunks()
{
    /*Если суммарное количество родных и бонусных чанков превышает 60,
     *то родные чанки вытесняют бонусные. В конечном итоге общая сумма
     *родных и бонусных чанков никогда не превышает 60.*/
    if(nativeChunks.size()+bonusChunks.size() > 60){
        finalBonusChunks.clear();
        for(int i = 0; i<60-nativeChunks.size(); i++){
            finalBonusChunks.append(bonusChunks.at(i));
        }
    }else
        finalBonusChunks = bonusChunks;

    chunks.clear();

    chunks.append(nativeChunks);
    chunks.append(finalBonusChunks);
}

//Пересчёт размера заполненной области
void ProgressBar_2::recalculationChunkWidth()
{
    recalculationChunks();

    if(chunks.size()!=0){
        //Вычисляется общее количество значений
        int totalValues = 0;
        for(Chunk* chunk : chunks)
            totalValues+=chunk->getMaxValue();
        //Если не проверить, то может получиться деление на 0
        if(totalValues!=0)
            /*86 - это суммарные горизонтальные отступы тела прогрессбара от краёв виджета.
         *Деля размер тела прогрессбара на общее количество значений узнаём размер
         *изменения заполненной области при изменении значения на 1.*/
            stepSize = (this->width()-86.0)/totalValues;
        else
            stepSize = 0.0;

        qDeleteAll(ui->SeparatorWrapper->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

        int value = 0;
        int offset = 0;
        for(int i = 0; i<chunks.size(); i++){
            value+=chunks.at(i)->getValue();
            offset+=chunks.at(i)->getMaxValue();
            if(i<chunks.size()-1){
                QLabel* separator = new QLabel(ui->SeparatorWrapper);
                separator->setGeometry(43+ceil(offset*stepSize)-5, 0, 9, 43);
                separator->setStyleSheet(PB2_StyleMaster::SeparatorStyle());
            }
        }

        ui->ProgressBarChunk->setFixedWidth(ceil(value*stepSize));

        int currentChunk = getCurrentChunkIndex();

        ui->labelWithTooltip->setText(QString::number(currentChunk+1)+" / "+QString::number(chunks.size())+
                                      " ("+QString::number(chunks.at(currentChunk)->getValue())+" / "+
                                      QString::number(chunks.at(currentChunk)->getMaxValue())+")");
    }else
        ui->labelWithTooltip->setText("0 / 0 (0 / 0)");
}

//Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
void ProgressBar_2::redrawChunk()
{
    QImage new_image(":/Text-Block-1/Textures PNG/ProgressBarBody-1.jpg");
    QPixmap pixmap(this->width(), ui->ProgressBarChunk->height());
    QPainter painter(&pixmap);
    //Тайлинг текстуры
    int drawedWidth = 0;
    int drawedHeight = 0;
    while (true) {
        drawedWidth = 0;
        while (true) {
            painter.drawImage(drawedWidth, drawedHeight, new_image);
            drawedWidth += new_image.width();
            if (drawedWidth >= pixmap.width()) {
                break;
            }
        }
        drawedHeight += new_image.height();
        if (drawedHeight >= pixmap.height()) {
            break;
        }
    }
    //Стиль наложение цвета - умножение, чтобы окрашивать текстуру
    painter.setCompositionMode(QPainter::CompositionMode_Multiply);
    //Наложение цвета
    painter.fillRect(QRect(0, 0, this->width(), this->height()), color);
    painter.end();

    ui->ProgressBarChunk->setPixmap(pixmap);
}

/*Переопределённая виртуальная функция класса QWidget. Во время этого эвента
 *происходит подгонка всех обёрток(wrapper) под размер виджета.*/
void ProgressBar_2::resizeEvent(QResizeEvent *event)
{
    ui->ChunkWrapper->setFixedWidth(this->width());
    ui->TipsWrapper->setFixedWidth(this->width());
    ui->BordersWrapper->setFixedWidth(this->width());
    ui->ShadowWrapper->setFixedWidth(this->width());
    ui->LabelWithTooltipWrapper->setFixedWidth(this->width());
    ui->SeparatorWrapper->setFixedWidth(this->width());

    //После изменения размера нужно перерисовать тело прогрессбара
    recalculationChunkWidth();
    redrawChunk();
}
