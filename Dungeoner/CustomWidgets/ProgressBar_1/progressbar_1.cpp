/************************************************************************************************
 *Да, это переизобретённый прогрессбар. Сделанно это было во-первых для визуального вида, а
 *во-вторых потому что я не нашёл очевидного способа задать бэкграунд заполненной области
 *стандартного прогрессбара при помощи QPixmap. Важно было задать бэкграунд именно при помощи
 *pixmap так как текстура заполненной области должна иметь функцию окраски в необходимый цвет,
 *когда как сама изначальная текстура серая. Окраска происходит при помощи метода fillRect у
 *QPainter, которому очевидно нужен QPixmap. Также реализован механизм вызова всплывающей
 *подсказки. В остальном же это обычный прогрессбар с отличием в том, что его надпись выводит
 *информацию в формате "value/maxValue"
 ************************************************************************************************/

#include "progressbar_1.h"
#include "ui_progressbar_1.h"
#include "PB1_stylemaster.h"

#include <QPainter>

ProgressBar_1::ProgressBar_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar_1)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->BordersWrapper->setStyleSheet(PB1_StyleMaster::BordersStyle());
    ui->TipsWrapper->setStyleSheet(PB1_StyleMaster::TipsStyle());
    ui->ShadowWrapper->setStyleSheet(PB1_StyleMaster::ShadowStyle());
    //Задаётся стиль текста лейбла с подсказкой как "ЧИСЛА"
    ui->labelWithTooltip->setFontType(LabelWithTooltip::NUMBERS);
    ui->labelWithTooltip->setOutlineThickness(2);

    bonusesLabel->setLayout(bonusesLayout);
}

ProgressBar_1::~ProgressBar_1()
{
    qDeleteAll(bonusesLabel->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    delete bonusesLayout;

    for(QLabel* label : tooltipContent)
        delete label;

    delete ui;
}

int ProgressBar_1::getMinValue() const
{
    return minValue;
}

void ProgressBar_1::setMinValue(int newMinValue)
{
    //Минимальное значение не может быть больше максимального
    if(newMinValue>maxValue)
        minValue = maxValue;
    else
        minValue = newMinValue;

    /*Если после изменения значение оказывается меньше
     *минимального, то оно усекается до минимального*/
    if(value < minValue)
        setValue(minValue);

    //После изменения диапазона нужно перезаписать текст подсказки
    valueLabel->setText(QVariant(value).toString() + " / " + QVariant(maxValue).toString());

    //После изменения диапазона нужно пересчитать размер заполненной области
    recalculationChunkWidth();
}

int ProgressBar_1::getMaxValue() const
{
    return maxValue;
}

void ProgressBar_1::setMaxValue(int newMaxValue)
{
    //Ограничение стата для уменьшения шанса возможных переполнений
    if(newMaxValue>9999999)
        newMaxValue = 9999999;

    //Максимальное значение не может быть меньше минимального
    if(newMaxValue<minValue)
        maxValue = minValue;
    else
        maxValue = newMaxValue;

    /*Если после изменения значение оказывается больше
     *максимального, то оно усекается до максимального*/
    if(value > maxValue)
        setValue(maxValue);

    //После изменения диапазона нужно перезаписать текст подсказки
    valueLabel->setText(QVariant(value).toString() + " / " + QVariant(maxValue).toString());

    //После изменения диапазона нужно пересчитать размер заполненной области
    recalculationChunkWidth();

    bonusesChanged();
}

int ProgressBar_1::getValue() const
{
    return value;
}

void ProgressBar_1::setValue(int newValue)
{
    //Значение находится в диапазоне от минимального до максимального
    if(newValue>maxValue)
        value = maxValue;
    else if(newValue<minValue)
        value = minValue;
    else
        value = newValue;

    //После изменения диапазона нужно перезаписать текст подсказки
    valueLabel->setText(QVariant(value).toString() + " / " + QVariant(maxValue).toString());

    //После изменения диапазона нужно пересчитать размер заполненной области
    recalculationChunkWidth();

    //Если есть процентные бонусы, то от изменения значения они тоже изменятся
    bonusesChanged();
}

void ProgressBar_1::setColor(const QColor &newColor)
{
    color = newColor;

    //После изменения цвета нужно перерисовать заполненную область
    redrawChunk();
}

LabelWithTooltip* ProgressBar_1::getLabelWithTooltip()
{
    return ui->labelWithTooltip;
}

//Генерация лейбла с информацией по всем бонусам для его дальнейшего добавления в tooltipContent
void ProgressBar_1::setTooltipContent(QString fullName, QString formula, int formulaFontSize, QString description)
{
    QLabel* fullNameLabel = new QLabel;
    fullNameLabel->setFont(QFont("TextFont"));
    fullNameLabel->setStyleSheet(PB1_StyleMaster::TooltipTextStyle(27, "bdc440"));
    fullNameLabel->setText(fullName);
    fullNameLabel->setMaximumWidth(450);
    fullNameLabel->setWordWrap(true);
    tooltipContent.append(fullNameLabel);

    QLabel* separator = new QLabel;
    separator->setFixedSize(450, 1);
    separator->setStyleSheet("background: #bdc440;");
    tooltipContent.append(separator);

    valueLabel = new QLabel;
    valueLabel->setFont(QFont("NumbersFont"));
    valueLabel->setStyleSheet(PB1_StyleMaster::TooltipTextStyle(27, "cad160"));
    valueLabel->setText(QVariant(value).toString() + " / " + QVariant(maxValue).toString());
    valueLabel->setMaximumWidth(450);
    valueLabel->setWordWrap(true);
    tooltipContent.append(valueLabel);

    QLabel* formulaLabel = new QLabel;
    formulaLabel->setFont(QFont("TextFont"));
    formulaLabel->setStyleSheet(PB1_StyleMaster::TooltipTextStyle(formulaFontSize, "bdc440"));
    formulaLabel->setText(formula);
    formulaLabel->setMaximumWidth(450);
    formulaLabel->setWordWrap(true);
    tooltipContent.append(formulaLabel);

    //Если есть бонусы, то они будут внесены в подсказку
    if(!stat->getBonuses().isEmpty()){
        CreatingBonusTooltip();

        tooltipContent.append(bonusesLabel);
        bonusesLableIsAppend = true;
    }

    QLabel* separator2 = new QLabel;
    formulaLabel->setMaximumWidth(450);
    separator2->setStyleSheet(PB1_StyleMaster::SeparatorStyle());
    tooltipContent.append(separator2);

    QLabel* descriptionLabel = new QLabel;
    descriptionLabel->setFont(QFont("TextFont"));
    descriptionLabel->setStyleSheet(PB1_StyleMaster::TooltipTextStyle(18, "cad160"));
    descriptionLabel->setText(description);
    descriptionLabel->setMaximumWidth(450);
    descriptionLabel->setWordWrap(true);
    tooltipContent.append(descriptionLabel);

    ui->labelWithTooltip->setTooltipContent(tooltipContent);
}

void ProgressBar_1::setStat(Stat *newStat)
{
    stat = newStat;
    connect(stat, &Stat::bonusesChanged, this, &ProgressBar_1::bonusesChanged);
}

void ProgressBar_1::bonusesChanged()
{
    /*Следует помнить, что лейбл бонусов всегда находится в векторе tooltipContent
     *на 4 позиции, если это изменится, то надо поменять это и здесь*/
    if(!stat->getBonuses().isEmpty()){
        value = stat->getProgressBarCurrentValue();
        maxValue = stat->getFinalValue();

        //После изменения диапазона нужно пересчитать размер заполненной области
        recalculationChunkWidth();

        CreatingBonusTooltip();

        if(!bonusesLableIsAppend){
            tooltipContent.insert(4, bonusesLabel);
            bonusesLableIsAppend = true;
            ui->labelWithTooltip->setTooltipContent(tooltipContent);
        }
    }else if(bonusesLabel){
        if(bonusesLableIsAppend){
            tooltipContent.removeAt(4);
            bonusesLableIsAppend = false;
            ui->labelWithTooltip->setTooltipContent(tooltipContent);
            qDeleteAll(bonusesLabel->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
        }
    }
}

void ProgressBar_1::CreatingBonusTooltip()
{
    //Сначала следует очистить лейбл от всей предыдущей информации
    qDeleteAll(bonusesLabel->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    int row = 0;
    int col = 0;
    //Переменная показывающая после какого значения row следует сделать перенос на новую col
    int maxRow = 10;
    /*Если количество бонусов больше 10, то maxRow пытается разделить столбец
     *пополам с приоритетом на првый столбец, если количество бонусов нечётное*/
    if(stat->getBonuses().size() > 10)
        maxRow = ceil((float)stat->getBonuses().size()/2);
    //Также столбец никогда не должен превышать 10 строк
    if(maxRow > 10)
        maxRow = 10;
    for(Bonus* bonus : stat->getBonuses()){
        QString text;
        /*Знак, говорящий о положительности числа. Если '-' очевидно добавляется к числу сам, то '+'
         *следует добавить вручную. Можно было бы это сделать и с помощью валидатора или с помощью
         *лямбд, но эти способы кажутся излишним переусложнением простой и единичной задачи.*/
        QString sign = "";

        if(bonus->getFinalValue() > 0){
            numberSign = PLUS;
            sign = '+';
        }else if(bonus->getFinalValue() < 0){
            numberSign = MINUS;
        }else
            numberSign = ZERO;

        QLabel* bonusLabel = new QLabel(bonusesLabel);

        //Число символов в строке до переноса слова
        int numberOfCharactersBeforeLineBreak;

        //Если бонусов меньше 11, то они пишутся в 1 столбец и им доступен весь размер окна подсказки
        if(stat->getBonuses().size()<11){
            numberOfCharactersBeforeLineBreak = 35;
            bonusLabel->setFixedWidth(450);
        }else{
        //Если же больше, то они пишутся в 2 сотбца и им доступна только половина
            numberOfCharactersBeforeLineBreak = 16;
            bonusLabel->setFixedWidth(225);
        }

        //Перенос строки
        if(bonus->bonusName.size()>numberOfCharactersBeforeLineBreak){
            for(int i = 0; i<bonus->bonusName.size(); i++){
                //Если имя бонуса превышает 35 символов, то оно усекается
                if(i>35){
                    text.append("... ");
                    break;
                }
                text.append(bonus->bonusName.at(i));
                if(i%numberOfCharactersBeforeLineBreak==0 && i!=0 && i!=bonus->bonusName.size()-1){
                    //Если текущий или следующий символ является пробелом, то тире, показывающее перенос, не нужно
                    if(bonus->bonusName.at(i+1)!=' '&&bonus->bonusName.at(i)!=' '){
                        text.append('-');
                    }
                    text.append("\n");
                }
            }
        }else
            text.append(bonus->bonusName);
        text.append(": " + sign + QVariant(bonus->getFinalValue()).toString());

        //Если бонус процентный, то его процент выводится в скобочках после значения
        if(bonus->isPercentage)
            text.append(" (" + QVariant(bonus->getValue()).toString() + "%)");

        //В зависимости от положительности значения, его лейбл красится в определённый цвет
        QString color;
        //Зелёный
        if(numberSign == PLUS)
            color = "77DB46";
        //Красный
        else if(numberSign == MINUS)
            color = "FF7F4F";
        //Блёкло-жёлтый
        else
            color = "C9CF82";

        bonusLabel->setFont(QFont("TextFont"));
        bonusLabel->setText(text);
        bonusLabel->setWordWrap(true);
        bonusesLayout->addWidget(bonusLabel, row, col, Qt::AlignCenter);

        row++;
        if(row>=maxRow){
            row = 0;
            col++;
            /*Если бонусов больше 20, то последний двацатый просто заменяется на многоточие,
             *говорящее о том, что все бонусы не влезли в подсказку, и цикл прерывается*/
            if(col > 1 && maxRow==10 && stat->getBonuses().size()>20){
                bonusLabel->setText("...");
                bonusLabel->setStyleSheet(PB1_StyleMaster::TooltipTextStyle(50, "cad160"));
                break;
            }
        }

        bonusLabel->setStyleSheet(PB1_StyleMaster::TooltipTextStyle(17, color));
    }
    bonusesLabel->setMaximumWidth(450);

    /*Если после применения всех бонусов текущее значение отличается от родного,
     *то в подсказке в пишется Текущее_Значение (Исходное_Значение+Бонус)*/
    if(stat->getValue()!=stat->getFinalValue()){
        QString value;
        value.append(QVariant(stat->getProgressBarCurrentValue()).toString() + " / " + QVariant(stat->getFinalValue()).toString()
                     + " (" + QVariant(stat->getValue()).toString());
        //Эта разница отражает то, на сколько изменился стат при применении бонусов
        int difference = stat->getFinalValue() - stat->getValue();
        if(difference>0)
            value.append("+");
        value.append(QVariant(difference).toString() +")");
        valueLabel->setText(value);
    }
}

//Пересчёт размера заполненной области
void ProgressBar_1::recalculationChunkWidth()
{
    //Вычисляется общее количество значений
    long totalValues = maxValue - minValue;
    //Если не проверить, то может получиться деление на 0
    if(totalValues!=0)
        /*86 - это суммарные горизонтальные отступы тела прогрессбара от краёв виджета.
         *Деля размер тела прогрессбара на общее количество значений узнаём размер
         *изменения заполненной области при изменении значения на 1.*/
        stepSize = (this->width()-86.0)/totalValues;
    else
        stepSize = 0.0;

    ui->ProgressBarChunk->setFixedWidth(ceil(value*stepSize));

    ui->labelWithTooltip->setText(QString::number(value)+" / "+QString::number(maxValue));
}

//Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
void ProgressBar_1::redrawChunk()
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
void ProgressBar_1::resizeEvent(QResizeEvent *event)
{
    ui->ChunkWrapper->setFixedWidth(this->width());
    ui->TipsWrapper->setFixedWidth(this->width());
    ui->BordersWrapper->setFixedWidth(this->width());
    ui->ShadowWrapper->setFixedWidth(this->width());
    ui->LabelWithTooltipWrapper->setFixedWidth(this->width());

    //После изменения размера нужно перерисовать и пересчитать размер заполненной области
    recalculationChunkWidth();
    redrawChunk();
}
