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
 *после родных чанков. При удалении бонусных чанков итератор делает обход с конца вектора. То
 *есть если имеются 2 одинаковых бонусных чанка, вне зовисимости от причины вызываемого удаления,
 *будет удалён последний подходящий.
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

    //После изменения цвета нужно перерисовать заполненную область
    redrawChunk();
}

const QVector<Chunk*> &ProgressBar_2::getChunks() const
{
    return chunks;
}

//Метод задаёт родные чанки (nativeChunks)
void ProgressBar_2::setChunks(const QVector<Chunk*> &newChunks)
{
    //Вызов этого метода означает переинициализацию и следовательно необходимо уничтожить все старые ссылки
    clearNativeChunks();

    /*Максимальная длина вектора родных чанков равна 50, если
     *она привышена, то вектор усекается до 50 значений*/
    if(newChunks.size()>50){
        QVector<Chunk*> newNChunks;
        for(int i = 0; i<50; i++)
            newNChunks.append(newChunks.at(i));
        nativeChunks = newNChunks;

        /*Так как вектор родных чанков динамически генерируется каждый раз заного, и неуместившиеся ячейки
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

void ProgressBar_2::setTooltipContent(QString fullName, QString numberOfChunksFormula, QString chunkValueFormula, QString description)
{
    QLabel* fullNameLabel = new QLabel;
    fullNameLabel->setFont(QFont("TextFont"));
    fullNameLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(27, "bdc440"));
    fullNameLabel->setText(fullName);
    fullNameLabel->setMaximumWidth(450);
    fullNameLabel->setWordWrap(true);
    tooltipContent.append(fullNameLabel);

    QLabel* separator = new QLabel;
    separator->setFixedSize(450, 1);
    separator->setStyleSheet("background: #bdc440;");
    tooltipContent.append(separator);

    chunkNumber = new QLabel;
    chunkNumber->setFont(QFont("TextFont"));
    chunkNumber->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(25, "cad160"));
    chunkNumber->setMaximumWidth(450);
    chunkNumber->setWordWrap(true);
    tooltipContent.append(chunkNumber);

    generalValueLabel = new QLabel;
    generalValueLabel->setFont(QFont("TextFont"));
    generalValueLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(25, "cad160"));
    generalValueLabel->setMaximumWidth(450);
    generalValueLabel->setWordWrap(true);
    tooltipContent.append(generalValueLabel);

    valueLabel = new QLabel;
    valueLabel->setFont(QFont("TextFont"));
    valueLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(25, "cad160"));
    valueLabel->setMaximumWidth(450);
    valueLabel->setWordWrap(true);
    tooltipContent.append(valueLabel);

    QLabel* separator2 = new QLabel;
    separator2->setFixedSize(450, 1);
    separator2->setStyleSheet("background: #bdc440;");
    tooltipContent.append(separator2);

    QLabel* numberOfChunksFormulalaLabel = new QLabel;
    numberOfChunksFormulalaLabel->setFont(QFont("TextFont"));
    numberOfChunksFormulalaLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(20, "bdc440"));
    numberOfChunksFormulalaLabel->setText(numberOfChunksFormula);
    numberOfChunksFormulalaLabel->setMaximumWidth(450);
    numberOfChunksFormulalaLabel->setWordWrap(true);
    tooltipContent.append(numberOfChunksFormulalaLabel);

    newChunkRequirementsLabel = new QLabel;
    newChunkRequirementsLabel->setFont(QFont("TextFont"));
    newChunkRequirementsLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(21, "cad160"));
    newChunkRequirementsLabel->setText("До следующего фрагмента " + QVariant(willUntilNextChunk).toString() + " Воли");
    newChunkRequirementsLabel->setMaximumWidth(450);
    newChunkRequirementsLabel->setWordWrap(true);
    tooltipContent.append(newChunkRequirementsLabel);

    QLabel* detailedInformationHint = new QLabel;
    detailedInformationHint->setFont(QFont("TextFont"));
    detailedInformationHint->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(14, "bdc440"));
    detailedInformationHint->setText("Вывод подробной сводки фрагментов магической защиты: Alt + ПКМ");
    detailedInformationHint->setMaximumWidth(450);
    detailedInformationHint->setWordWrap(true);
    tooltipContent.append(detailedInformationHint);

    QLabel* separator3 = new QLabel;
    separator3->setFixedSize(450, 1);
    separator3->setStyleSheet("background: #bdc440;");
    tooltipContent.append(separator3);

    QLabel* FormulaSignatureLabel = new QLabel;
    FormulaSignatureLabel->setFont(QFont("TextFont"));
    FormulaSignatureLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(24, "bdc440"));
    FormulaSignatureLabel->setText("Размер фрагмента вычисляется по формуле:");
    FormulaSignatureLabel->setMaximumWidth(450);
    FormulaSignatureLabel->setWordWrap(true);
    tooltipContent.append(FormulaSignatureLabel);

    QLabel* chunkValueFormulaLabel = new QLabel;
    chunkValueFormulaLabel->setFont(QFont("TextFont"));
    chunkValueFormulaLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(24, "bdc440"));
    chunkValueFormulaLabel->setText(chunkValueFormula);
    chunkValueFormulaLabel->setMaximumWidth(450);
    chunkValueFormulaLabel->setWordWrap(true);
    tooltipContent.append(chunkValueFormulaLabel);

    QLabel* separator4 = new QLabel;
    separator4->setMaximumWidth(450);
    separator4->setStyleSheet(PB2_StyleMaster::SeparatorStyle());
    tooltipContent.append(separator4);

    QLabel* descriptionLabel = new QLabel;
    descriptionLabel->setFont(QFont("TextFont"));
    descriptionLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(18, "cad160"));
    descriptionLabel->setText(description);
    descriptionLabel->setMaximumWidth(450);
    descriptionLabel->setWordWrap(true);
    tooltipContent.append(descriptionLabel);

    ui->labelWithTooltip->setTooltipContent(tooltipContent);


    QLabel* AltFullNameLabel = new QLabel();
    AltFullNameLabel->setFont(fullNameLabel->font());
    AltFullNameLabel->setText(fullNameLabel->text());
    AltFullNameLabel->setStyleSheet(fullNameLabel->styleSheet());
    AltFullNameLabel->setWordWrap(fullNameLabel->wordWrap());
    AltTooltipContent.append(AltFullNameLabel);

    QLabel* AltSeparator = new QLabel();
    AltSeparator->setFixedHeight(1);
    AltSeparator->setStyleSheet(separator->styleSheet());
    AltTooltipContent.append(AltSeparator);

    detailedInformationLabel = new QLabel;
    detailedInformationLabel->setFont(QFont("TextFont"));
    detailedInformationLabel->setStyleSheet(PB2_StyleMaster::TooltipTextStyle(25, "E8E23C"));
    detailedInformationLabel->setWordWrap(false);
    AltTooltipContent.append(detailedInformationLabel);

    QLabel* AltSeparator2 = new QLabel();
    AltSeparator2->setStyleSheet(separator4->styleSheet());
    AltTooltipContent.append(AltSeparator2);

    QLabel* AltDescriptionLabel = new QLabel();
    AltDescriptionLabel->setFont(descriptionLabel->font());
    AltDescriptionLabel->setText(descriptionLabel->text());
    AltDescriptionLabel->setStyleSheet(descriptionLabel->styleSheet());
    AltDescriptionLabel->setWordWrap(descriptionLabel->wordWrap());
    AltTooltipContent.append(AltDescriptionLabel);

    ui->labelWithTooltip->setAltTooltipContent(AltTooltipContent);
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

        /*Если прибавляемое значение больше, чем эта разница, то чанк полностью заполняется, а из
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

    //После изменения значений нужно пересчетать общее заполненное значение всех векторов
    calculateValue();

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

/*Метод вычитает значение из текущего чанка. Если значение чанка меньше переданного вычитаемого
 *значения, то текущий чанк обнуляется, а остаток вычитается из предыдущего чанка, и так пока
 *либо не кончится значение, либо не кончатся чанки.*/
void ProgressBar_2::subtractValue(int value)
{
    //Предотвращение попадания в метод отрицательных значений
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    //Цикл идёт либо пока не кончится всё вычитаемое значение, либо пока не кончатся сами чанки
    while(value>0){
        //Если цикл дошёл до начала вектора чанков, то вычитание сразу прекращается
        if(currentChunk == -1)
            break;

        chunk = chunks.at(currentChunk);
        /*Значение текущего чанка может быть равно нулю только в ситуации, когда этот чанк
         *первый и он пуст, соответственно нет надобности в дальнейших вычислениях*/
        if(chunk->getValue()==0)
            break;
        /*Если вычитаемое значение больше значения текущего чанка, то от вычитаемого значения
         *отнимается значение чанка, и чанк обнуляется. То есть итоговое вычитаемое значение
         *после этого равняется остатку от обнуления одного чанка переданным значением.*/
        if(value>chunk->getValue()){
            value-=chunk->getValue();
            chunk->setValue(0);
        }else{
            /*Если же значение чанка больше вычитаемого значения, то это значение просто
             *вычитается из текущего значения чанка и обнуляется завершая цикл.*/
            chunk->setValue(chunk->getValue()-value);
            value = 0;
        }
        currentChunk--;
    }

    //После изменения значений нужно пересчетать общее заполненное значение всех векторов
    calculateValue();

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

/*Добавление чанка в вектор бонусных чанков. В метод передаётся указатель на новый чанк, затем его
 *текущее значение обнуляется и указатель добавляется в конец вектора бонусных чанков. Новый чанк
 *будет иметь текущее значение 0, так как все бонусы дают прибавку только к максимальному значению,
 *а не к текущему.*/
void ProgressBar_2::addBonusChunk(Chunk* chunk)
{
    chunk->setValue(0);
    bonusChunks.append(chunk);
    recalculationChunkWidth();
}

/*Перегрузка идентичная по функционалу вышестоящему методу, только
 *эта функция добавляет переданный вектор к вектору бонусных чанков*/
void ProgressBar_2::addBonusChunk(QVector<Chunk *> chunks)
{
    for(Chunk* chunk : chunks)
        chunk->setValue(0);
    bonusChunks.append(chunks);
    recalculationChunkWidth();
}

//Добавление одного чанка в вектор родных чанков
void ProgressBar_2::addChunk(Chunk *chunk)
{
    if(nativeChunks.size()<50){
        chunk->setValue(0);
        nativeChunks.append(chunk);
    }

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

/*Метод устанавливает общее значение всему прогрессбару, последовательно заполняя все чанки пока
 *не кончится переданное значение. Используется для первичной инициализации и сохранения значения
 *при перерасчёте векторов прогрессбара из переменной value, чтобы оно не сбрасывалось при любом
 *изменении.*/
void ProgressBar_2::setValue(int value)
{
    if(value<0)
        value = 0;

    for(Chunk* chunk : chunks){
        int difference = chunk->getMaxValue()-chunk->getValue();
        if(difference<=value){
            chunk->setValue(chunk->getMaxValue());
            value-=difference;
        }else{
            chunk->setValue(chunk->getValue()+value);
            break;
        }
        if(value<=0)
            break;
    }
}

/*Очистка вектора родных чанков. Нужно быть осторожным в вызове этого метода, ведь он сам
 *не перерисовывает прогрессбар. После его вызова ОБЯЗАТЕЛЬНО должна быть переинициализация
 *вектора родных чанков, даже пустым вектором, если то нужно. Безопасен только вызов из
 *начала метода setChunks, потому что он сам и переинициализирует вектор родных чанков.*/
void ProgressBar_2::clearNativeChunks()
{
    /*Так как вектор родных чанков динамически генерируется каждый раз заного, и его ячейки никогда
     *повторно не понадобятся, необходимо высвобождение памяти у элементов этого вектора*/
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    nativeChunks.clear();
}

/*Удаление бонусного чанка, первая перегрузка.
 *
 *В ней передаётся указатель на чанк, затем итератор ищет первый с конца
 *чанк из вектора бонусных чанков, максимальное значение которого совпадёт
 *с переданным чанком и удаляет указатель на него.*/
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
            //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
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

/*Удаление бонусного чанка, вторая перегрузка.
 *
 *В ней просто передаётся число, являющееся максимальным значением
 *вектора, которое итератор будет искать среди максимальных значений
 *вектора бонусных чанков и удалять соответствующий указатель. Обход
 *так же идёт с конца.*/
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
            //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
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

/*Удаление бонусного чанка, третяя перегрузка.
 *
 *Идентична первой, только ищуются все значения из переданного вектора*/
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

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();

    //Если количество удачных нахождений соответствует количеству переданных элементов, то поиск прошёл удачно
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

/*Удаление бонусного чанка, четвёртая перегрузка.
 *
 *Идентична второй, только ищуются все значения из переданного вектора*/
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

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();

    //Если количество удачных нахождений соответствует количеству переданных элементов, то поиск прошёл удачно
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

/*Обнуляет текущий активный чанк. Если обнуление было произведено, то водвращает true, если
 *нет то это означает, что весь прогрессбар уже полностью обнулён и возвращается false*/
bool ProgressBar_2::spendLastChunk()
{
    //Проверка не пуст ли вектор чанков
    if(chunks.size()>0){
        int chunkIndex = getCurrentChunkIndex();
        /*Значение текущего чанка может быть равно нулю только в ситуации,
         *когда этот чанк первый и он пуст, соответственно обнулять нечего*/
        if(chunks.at(chunkIndex)->getValue()!=0){
            chunks.at(chunkIndex)->setValue(0);
            //После изменения значений нужно пересчетать общее заполненное значение всех векторов
            calculateValue();

            //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
            recalculationChunkWidth();
            return true;
        }else{
            //После изменения значений нужно пересчетать общее заполненное значение всех векторов
            calculateValue();
            return false;
        }
    }else{
        //После изменения значений нужно пересчетать общее заполненное значение всех векторов
        calculateValue();
        return false;
    }
}

//Приравнивает значение текущего активного чанка к его максимальному значению
void ProgressBar_2::HealOneChunk()
{
    for(Chunk* chunk : chunks)
        if (chunk->getValue()!=chunk->getMaxValue()){
            chunk->setValue(chunk->getMaxValue());
            break;
        }
    calculateValue();

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

//Приравнивает значение всех чанков к их максимальному значению
void ProgressBar_2::HealAllChunk()
{
    for(Chunk* chunk : chunks)
        chunk->setValue(chunk->getMaxValue());
    calculateValue();

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunkWidth();
}

//Перерасчёт общего вектора всех чанков, который включает в себя и родные и бонусные чанки
void ProgressBar_2::recalculationChunks()
{
    /*Если суммарное количество родных и бонусных чанков превышает 60,
     *то родные чанки вытесняют бонусные. В конечном итоге общая сумма
     *родных и бонусных чанков никогда не превышает 60.*/
    if(nativeChunks.size()+bonusChunks.size() > 60){
        finalBonusChunks.clear();
        /*Добавление бонусных чанков в общий вектор продолжается пока его
         *размер не достигнет 60, оставшиеся чанки считаются вытеснеными*/
        for(int i = 0; i<60-nativeChunks.size(); i++){
            /*Необходимо сбросить все значения, у родных чанков это происходит автоматически, а у
             *бонусных здесь. Прогрессбар помнит своё общее значение в переменной value и позже
             *заполнит им чанки в методе setValue. Делается это для ситуации когда бонусные чанки
             *заполнены, а вектор родных расширяется пустыми новыми чанками. Получается разрыв в
             *заполнении чанков, чего происходить не должно, а так заполнение как бы перетечёт в
             *новые пустые чанки.*/
            bonusChunks.at(i)->setValue(0);

            finalBonusChunks.append(bonusChunks.at(i));
        }
    }else{
        /*Необходимо сбросить все значения, у родных чанков это происходит автоматически, а у
         *бонусных здесь. Прогрессбар помнит своё общее значение в переменной value и позже
         *заполнит им чанки в методе setValue. Делается это для ситуации когда бонусные чанки
         *заполнены, а вектор родных расширяется пустыми новыми чанками. Получается разрыв в
         *заполнении чанков, чего происходить не должно, а так заполнение как бы перетечёт в
         *новые пустые чанки.*/
        for(Chunk* chunk : bonusChunks)
            chunk->setValue(0);

        finalBonusChunks = bonusChunks;
    }

    chunks.clear();

    //Добавляются сначала рордные, а затем бонусные чанки
    chunks.append(nativeChunks);
    chunks.append(finalBonusChunks);

    //Вычисляется общее максимальное значение всех чанков
    totalValue = 0;
    for(Chunk* chunk : chunks)
        totalValue+=chunk->getMaxValue();

    //Если значение больше максимального, то оно усекается до максимального
    if(value > totalValue)
        value = totalValue;
}

//Пересчёт размера заполненной области и позиций разделителей
void ProgressBar_2::recalculationChunkWidth()
{
    //Вызов перерасчёта общего вектора всех чанков
    recalculationChunks();

    //Если не проверить, то может получиться деление на 0
    if(totalValue!=0)
        /*86 - это суммарные горизонтальные отступы тела прогрессбара от краёв виджета.
             *Деля размер тела прогрессбара на общее количество значений узнаём размер
             *изменения заполненной области при изменении значения на 1.*/
        stepSize = (this->width()-86.0)/totalValue;
    else
        stepSize = 0.0;

    //После перерасчёта общего вектора всех чанков значение теряется, и его надо снова передать
    setValue(this->value);

    //Очистка врапера разделителей
    qDeleteAll(ui->SeparatorWrapper->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

    //Общее текущее значение всех чанков
    int value = 0;
    /*Переменная с помощью которой вычисляется величина отступа
         *от левого края на который должен быть смещён разделитель*/
    long offset = 0;
    //Установка разделителей и подсчёт общего текущего значения
    for(int i = 0; i<chunks.size(); i++){
        value+=chunks.at(i)->getValue();
        /*Смещение возрастает на максимальное значение текущего чанка,
         *затем при умножении на stepSize узнаётся фактическое смещение*/
        offset+=chunks.at(i)->getMaxValue();
        /*Разделитель устанавливается по левую сторону чанка, и соответственно
         *последнему чанку нет смысла устанавливать разделитель*/
        if(i<chunks.size()-1){
            /*Лейбл-разделитель создаётся просто как потомок SeparatorWrapper
             *и помещается в него без какого-либо лейаута*/
            QLabel* separator = new QLabel(ui->SeparatorWrapper);
            /*Решение не использовать лейауты было принято по причине того, что
             *stepSize - дробный множитель, а координаты всегда целочисленные.
             *Соответственно если бы отсчёт вёлся не от края виджета, а от конца
             *предедущего разделителя, то координаты бы прилось округлять столько
             *раз, сколько разделителей в виджете. Погрешность бы накапливалась, и
             *скоро разделители бы уже перестали попадать в нужные места. А с
             *отсчётом с края виджета округление происходит только 1 раз, при этом
             *точно также, как и у заполненной области, что гарантирует, что
             *заполненная область при полном значении любого чанка будет идеально
             *попадать на середину разделителя.
             *
             *Также по причине накопления погрешности при множественных округлениях
             *заполненная область и не была чётко разделена на чанки, а просто
             *синхронизирована с ними.
             *
             *43 - это отступ от края виджета, до него место занимает декоративный
             *элемент. В конце вычитается 5 - большая половина от разделителя для
             *того, чтобы он попадал на необходимое значение центром, а не краем.
             *Нечётная ширина разделителя не с проста - это декоративная задумка.*/
            separator->setGeometry(43+ceil(offset*stepSize)-5, 1, 9, 43);
            //Установка текстуры разделителя
            separator->setStyleSheet(PB2_StyleMaster::ProgressBarSeparatorStyle());
            separator->setVisible(true);
        }
    }

    ui->ProgressBarChunk->setFixedWidth(ceil(value*stepSize));

    //Заполнение лейбла подсказки контентом
    int currentChunk = getCurrentChunkIndex();
    if(chunks.size()!=0){
        ui->labelWithTooltip->setText(QString::number(currentChunk+1)+" / "+QString::number(chunks.size())+
                                      " ("+QString::number(chunks.at(currentChunk)->getValue())+" / "+
                                      QString::number(chunks.at(currentChunk)->getMaxValue())+")");
    }else
        if(chunks.isEmpty())
            ui->labelWithTooltip->setText("0 / 0");
        else
            ui->labelWithTooltip->setText("1 / "+QString::number(chunks.at(currentChunk)->getMaxValue()));

    generalValueLabel->setText("Общее текущее значение:\n" + QVariant(this->value).toString() + " / " + QVariant(totalValue).toString());

    if(nativeChunks.size()<50)
        if(willUntilNextChunk>1)
            newChunkRequirementsLabel->setText("До следующего фрагмента " + QVariant(willUntilNextChunk).toString() + " Воли");
        else
            newChunkRequirementsLabel->setText("До следующего фрагмента " + QVariant(willUntilNextChunk).toString() + " Воля");
    else
        if(chunks.size()<60)
            if(10-bonusChunks.size()!=1)
                newChunkRequirementsLabel->setText("Достигнуто максимальное количество небонусных фрагментов защиты\n Можно получить ещё " +
                                                   QVariant(10-bonusChunks.size()).toString() + " бонусных фрагментов");
            else
                newChunkRequirementsLabel->setText("Достигнуто максимальное количество небонусных фрагментов защиты\n Можно получить ещё 1 бонусный фрагмент");
        else
            newChunkRequirementsLabel->setText("Достигнуто максимальное количество фрагментов защиты");

    if (currentChunk != 0){
        chunkNumber->setText(QString::number(currentChunk+1)+" фрагмент из "+QString::number(chunks.size()));
        valueLabel->setText("В текущем фрагменте:\n" + QString::number(chunks.at(currentChunk)->getValue())+" / "+
                            QString::number(chunks.at(currentChunk)->getMaxValue()));
    }else{
        chunkNumber->setText("0 фрагмент из " + QString::number(chunks.size()));
        if(chunks.isEmpty())
            valueLabel->setText("В текущем фрагменте:\n0 / 0");
        else
            valueLabel->setText("В текущем фрагменте:\n" + QString::number(chunks.at(currentChunk)->getValue())+" / "+
                                QString::number(chunks.at(currentChunk)->getMaxValue()));
    }

    QString detailedInformationLabelText;
    if(!chunks.isEmpty())
        for(int i = 0; i < chunks.size(); i++){
            detailedInformationLabelText.append("<span");
            if(chunks.at(i)->getValue() == 0)
                detailedInformationLabelText.append(" style=\"color: #FF7F4F;\"");
            else if(chunks.at(i)->getValue() == chunks.at(i)->getMaxValue())
                if(i!=getCurrentChunkIndex())
                    detailedInformationLabelText.append(" style=\"color: #77DB46;\"");
            detailedInformationLabelText.append(">");
            detailedInformationLabelText.append("(" + QVariant(chunks.at(i)->getValue()).toString() + "/");
            detailedInformationLabelText.append(QVariant(chunks.at(i)->getMaxValue()).toString() + ")</span>");
            if(i!=chunks.size()-1)
                detailedInformationLabelText.append(", ");
            if(i!=0 && i!=chunks.size()-1 && ((i+1)%5)==0 && chunks.size()>5)
                detailedInformationLabelText.append("<br>");
        }
    else
        detailedInformationLabelText = "Магическая защита отсутствует";

    detailedInformationLabel->setText("<p>" + detailedInformationLabelText + "</p>");

    int detailedInformationWidth = detailedInformationLabel->sizeHint().width();
    if(detailedInformationWidth<450)
        detailedInformationWidth = 450;

    for(QLabel* label : AltTooltipContent)
        label->setMinimumWidth(detailedInformationWidth);
}

//Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
void ProgressBar_2::redrawChunk()
{
    QImage new_image(":/Text-Block-1/Textures PNG/ProgressBarBody-1.jpg");
    QPixmap pixmap(this->width(), ui->ProgressBarChunk->height());
    QPainter painter(&pixmap);
    //Тайлинг текстуры
    int drawedWidth = 0;
    while (true) {
        painter.drawImage(drawedWidth, 0, new_image);
        drawedWidth += new_image.width();
        if (drawedWidth >= pixmap.width()) {
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

//Вычисление текущего общего заполненного значения всех чанков прогрессбара
void ProgressBar_2::calculateValue()
{
    value = 0;

    for(int i = 0; i<chunks.size(); i++){
        value+=chunks.at(i)->getValue();
    }
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

    //После изменения размера нужно перерисовать тело прогрессбара и разделители
    recalculationChunkWidth();
    redrawChunk();
}
