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
    //SeparatorWrapper нужно очистить так как эллементам в нём память вызывалась динамически
    qDeleteAll(ui->SeparatorWrapper->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

    for(QLabel* label : tooltipContent)
        delete label;
    for(QLabel* label : AltTooltipContent)
        delete label;

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
void ProgressBar_2::setChunks(const QVector<Chunk*> &newChunks, int totalValue, int amountOfNativeChunks, int amountOfBonusChunks, int value)
{
    chunks.clear();
    chunks = newChunks;

    this->totalValue = totalValue;
    this->amountOfNativeChunks = amountOfNativeChunks;
    this->amountOfBonusChunks = amountOfBonusChunks;
    setValue(value);

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

    /*Далее задаётся контент подсказки с зажатым альтом. Практически все её элементы -
     *это дубликаты некоторых предыдущих лейблов. Те же лейблы не переиспользовать так
     *как у обычной подсказки ширина статичная, а у альт-подсказки - динамичная, и
     *получается что передавая те же лейблы, альт-подсказка постоянно меняла бы их
     *ширину.
     *Копирование производится просто передачей необходимых пораметров из старого лейбла
     *новому. Я знаю и про глубокое копирование, и про патерн прототип, но использование
     *этого для копирования четырёх односложных лейблов не выигрывает ничего.*/

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
    //В этом лейбле мы сами управляем переносом строк и автоперенос нам не нужен
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

/*Метод устанавливает общее значение всему прогрессбару, последовательно заполняя все чанки пока
 *не кончится переданное значение. Используется для первичной инициализации и сохранения значения
 *при перерасчёте векторов прогрессбара из переменной value, чтобы оно не сбрасывалось при любом
 *изменении.*/
void ProgressBar_2::setValue(int value)
{
    for(Chunk* chunk : chunks){
        chunk->setValue(0);
    }

    if(value<0)
        value = 0;

    this->value = value;

    for(Chunk* chunk : chunks){
        int difference = chunk->getFinalMaxValue()-chunk->getValue();
        if(difference<=value){
            chunk->setValue(chunk->getFinalMaxValue());
            value-=difference;
        }else{
            chunk->setValue(chunk->getValue()+value);
            break;
        }
        if(value<=0)
            break;
    }

    recalculationChunkWidth();
}

//Пересчёт размера заполненной области и позиций разделителей
void ProgressBar_2::recalculationChunkWidth()
{
    //Если не проверить, то может получиться деление на 0
    if(totalValue!=0)
        /*86 - это суммарные горизонтальные отступы тела прогрессбара от краёв виджета.
             *Деля размер тела прогрессбара на общее количество значений узнаём размер
             *изменения заполненной области при изменении значения на 1.*/
        stepSize = (this->width()-86.0)/totalValue;
    else
        stepSize = 0.0;

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
        offset+=chunks.at(i)->getFinalMaxValue();
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
                                      QString::number(chunks.at(currentChunk)->getFinalMaxValue())+")");
    }else
        if(chunks.isEmpty())
            ui->labelWithTooltip->setText("0 / 0");
        else
            ui->labelWithTooltip->setText("1 / "+QString::number(chunks.at(currentChunk)->getFinalMaxValue()));

    generalValueLabel->setText("Общее текущее значение:\n" + QVariant(this->value).toString() + " / " + QVariant(totalValue).toString());

    if(amountOfNativeChunks<50)
        if(willUntilNextChunk>1)
            newChunkRequirementsLabel->setText("До следующего фрагмента " + QVariant(willUntilNextChunk).toString() + " Воли");
        else
            newChunkRequirementsLabel->setText("До следующего фрагмента " + QVariant(willUntilNextChunk).toString() + " Воля");
    else
        if(chunks.size()<60)
            if(10-amountOfBonusChunks!=1)
                newChunkRequirementsLabel->setText("Достигнуто максимальное количество небонусных фрагментов защиты\n Можно получить ещё " +
                                                   QVariant(10-amountOfBonusChunks).toString() + " бонусных фрагментов");
            else
                newChunkRequirementsLabel->setText("Достигнуто максимальное количество небонусных фрагментов защиты\n Можно получить ещё 1 бонусный фрагмент");
        else
            newChunkRequirementsLabel->setText("Достигнуто максимальное количество фрагментов защиты");

    if (currentChunk != 0){
        chunkNumber->setText(QString::number(currentChunk+1)+" фрагмент из "+QString::number(chunks.size()));
        valueLabel->setText("В текущем фрагменте:\n" + QString::number(chunks.at(currentChunk)->getValue())+" / "+
                            QString::number(chunks.at(currentChunk)->getFinalMaxValue()));
    }else{
        chunkNumber->setText("0 фрагмент из " + QString::number(chunks.size()));
        if(chunks.isEmpty())
            valueLabel->setText("В текущем фрагменте:\n0 / 0");
        else
            valueLabel->setText("В текущем фрагменте:\n" + QString::number(chunks.at(currentChunk)->getValue())+" / "+
                                QString::number(chunks.at(currentChunk)->getFinalMaxValue()));
    }

    /*Подробная информация по чанкам задаётся при помощи HTML абзаца с CSS стилями. Здесь показатели по каждому
     *чанку оборачиваются в span, которому, в заисимости от статуса, задаётся цвет: зелёный - для полностью
     *заполненных, красный - для пустых и неизменным - жёлтым - отмечается текущий чанк. Каждые 5 чанков делается
     *перенос строки для простоты подсчёта.*/
    QString detailedInformationLabelText;
    if(!chunks.isEmpty())
        for(int i = 0; i < chunks.size(); i++){
            detailedInformationLabelText.append("<span");
            if(chunks.at(i)->getValue() == 0)
                //Красный
                detailedInformationLabelText.append(" style=\"color: #FF7F4F;\"");
            else if(chunks.at(i)->getValue() == chunks.at(i)->getFinalMaxValue())
                //Цвет текущего чанка остаётся обычным жёлтым
                if(i!=getCurrentChunkIndex())
                    //Зелёный
                    detailedInformationLabelText.append(" style=\"color: #77DB46;\"");
            detailedInformationLabelText.append(">");
            detailedInformationLabelText.append("(" + QVariant(chunks.at(i)->getValue()).toString() + "/");
            detailedInformationLabelText.append(QVariant(chunks.at(i)->getFinalMaxValue()).toString() + ")</span>");
            if(i!=chunks.size()-1)
                detailedInformationLabelText.append(", ");
            if(i!=0 && i!=chunks.size()-1 && ((i+1)%5)==0 && chunks.size()>5)
                detailedInformationLabelText.append("<br>");
        }
    else
        detailedInformationLabelText = "Магическая защита отсутствует";

    detailedInformationLabel->setText("<p>" + detailedInformationLabelText + "</p>");

    /*Ширина подсказки подробной информации высчитывается исходя из ширины лейбла detailedInformationLabel,
     *но она не может быть меньше стандартного обычного размера подсказки в 450 пикселей, иначе описание и
     *имя могут не влезть в блок.*/
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
