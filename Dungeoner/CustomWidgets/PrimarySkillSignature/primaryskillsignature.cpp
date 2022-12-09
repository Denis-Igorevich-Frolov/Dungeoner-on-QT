/***********************************************************
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 ***********************************************************/

#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "PSS_stylemaster.h"

#include <QDate>
#include <QFile>
#include <QMouseEvent>
#include <QMutableVectorIterator>

PrimarySkillSignature::PrimarySkillSignature(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimarySkillSignature)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->labelCenter->setStyleSheet(PSS_StyleMaster::CenterTextureStyle());
    ui->ButtonTop->setStyleSheet(PSS_StyleMaster::topTextureStyle());
    ui->ButtonBottom->setStyleSheet(PSS_StyleMaster::bottomTextureStyle());
    ui->labelRight->setStyleSheet(PSS_StyleMaster::RightTextureStyle());
    ui->labelLeft->setStyleSheet(PSS_StyleMaster::LeftTextureStyle());

    bonusesLabel->setLayout(bonusesLayout);

    ui->ButtonTop->installEventFilter(this);
    ui->ButtonBottom->installEventFilter(this);

    connect(clickModifierTooltipTimer, SIGNAL(timeout()), this, SLOT(clickModifierTooltipTimerAlarm()));

    buttonTooltipContentLabel->setFont(QFont("TextFont"));
    buttonTooltipContentLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(20, "bdc440"));
    buttonTooltipContent.append(buttonTooltipContentLabel);
}

PrimarySkillSignature::~PrimarySkillSignature()
{
    qDeleteAll(bonusesLabel->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    delete bonusesLayout;

    for(QLabel* label : tooltipContent)
        delete label;
    for(QLabel* label : buttonTooltipContent)
        delete label;
    delete SpinBoxValue;
    delete clickModifierTooltipTimer;

    delete ui;
}

//Устанавливает текст для LabelWithTooltip
void PrimarySkillSignature::setText(QString text)
{
    ui->labelWithTooltip->setText(text);
}

/*Метод реализации нажатия кнопки прибавки стата. Он обрабатывает нажатия с учётом модификаторов:
 *Alt: +5, Ctrl: +10, Shift: +100. Обычное нажатие: +1. Модификатором считается последняя нажатая клавиша.*/
void PrimarySkillSignature::on_ButtonTop_released()
{
    Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);

    int plus = 1;

    if(!Global::pressedKeys.empty()){
        //Alt
        if(Global::pressedKeys.last() == 16777251){
            plus = 5;
        }else
        //Ctrl
        if(Global::pressedKeys.last() == 16777249){
            plus = 10;
        }else
        //Shift
        if(Global::pressedKeys.last() == 16777248){
            plus = 100;
        }
    }
    stat->setValue(stat->getValue() + plus);

    SpinBoxValue->setValue(stat->getFinalValue());
}

/*Метод реализации нажатия кнопки вычета стата. Он обрабатывает нажатия с учётом модификаторов:
 *Alt: -5, Ctrl: -10, Shift: -100. Обычное нажатие: -1. Модификатором считается последняя нажатая клавиша.*/
void PrimarySkillSignature::on_ButtonBottom_released()
{
    Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);

    int minus = 1;

    if(!Global::pressedKeys.empty()){
        //Alt
        if(Global::pressedKeys.last() == 16777251){
            minus = 5;
        }else
        //Ctrl
        if(Global::pressedKeys.last() == 16777249){
            minus = 10;
        }else
        //Shift
        if(Global::pressedKeys.last() == 16777248){
            minus = 100;
        }
    }
    stat->setValue(stat->getValue() - minus);

    SpinBoxValue->setValue(stat->getFinalValue());
}

void PrimarySkillSignature::clickModifierTooltipTimerAlarm()
{
    isShowTooltip = true;
    clickModifierTooltipTimer->stop();
    emit ShowTooltip(buttonTooltipContent);
}

void PrimarySkillSignature::valueChanged(int value)
{
    valueLabel->setText(QVariant(SpinBoxValue->value()).toString());
    bonusesChanged();
}

void PrimarySkillSignature::bonusesChanged()
{
    /*Следует помнить, что лейбл бонусов всегда находится в векторе tooltipContent
     *на 3 позиции, если это изменится, то надо поменять это и здесь*/
    if(!stat->getBonuses().isEmpty()){
        CreatingBonusTooltip();

        if(!bonusesLableIsAppend){
            tooltipContent.insert(3, bonusesLabel);
            bonusesLableIsAppend = true;
            ui->labelWithTooltip->setTooltipContent(tooltipContent);
        }
    }else if(bonusesLabel){
        if(bonusesLableIsAppend){
            tooltipContent.removeAt(3);
            bonusesLableIsAppend = false;
            ui->labelWithTooltip->setTooltipContent(tooltipContent);
        }
    }
}

//Генерация лейбла с информацией по всем бонусам для его дальнейшего добавления в tooltipContent
void PrimarySkillSignature::CreatingBonusTooltip()
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
                bonusLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(50, "cad160"));
                break;
            }
        }

        bonusLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(17, color));
    }
    bonusesLabel->setMaximumWidth(450);
}

Stat *PrimarySkillSignature::getStat() const
{
    return stat;
}

void PrimarySkillSignature::setStat(Stat *newStat)
{
    stat = newStat;
    connect(stat, &Stat::bonusesChanged, this, &PrimarySkillSignature::bonusesChanged);
}

QSpinBox *PrimarySkillSignature::getSpinBoxValue() const
{
    return SpinBoxValue;
}

/*Метод связвания QSpinBox (значение стата) с PrimarySkillSignature (подпись).
 *Само связываниепроизводится непосредственно в классе окна.*/
void PrimarySkillSignature::setSpinBoxValue(QSpinBox *newSpinBoxValue)
{
    SpinBoxValue = newSpinBoxValue;
    /*Связывание сигналов изменения значения стата для синхронизации отображения
     *характеристики в подсказке PrimarySkillSignature и в теле QSpinBox.*/
    connect(SpinBoxValue, &QSpinBox::valueChanged, this, &PrimarySkillSignature::valueChanged);
}

//Установка контента подсказки по нажатию на правую нопку мыши по подписи
void PrimarySkillSignature::setTooltipContent(QString fullName, QString description)
{
    QLabel* fullNameLabel = new QLabel;
    fullNameLabel->setFont(QFont("TextFont"));
    fullNameLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(27, "bdc440"));
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
    valueLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(27, "cad160"));
    valueLabel->setText(QVariant(SpinBoxValue->value()).toString());
    valueLabel->setMaximumWidth(450);
    valueLabel->setWordWrap(true);
    tooltipContent.append(valueLabel);

    if(!stat->getBonuses().isEmpty()){
        CreatingBonusTooltip();

        tooltipContent.append(bonusesLabel);
        bonusesLableIsAppend = true;
    }

    QLabel* separator2 = new QLabel;
    valueLabel->setMaximumWidth(450);
    separator2->setStyleSheet(PSS_StyleMaster::SeparatorStyle());
    tooltipContent.append(separator2);

    QLabel* descriptionLabel = new QLabel;
    descriptionLabel->setFont(QFont("TextFont"));
    descriptionLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(18, "cad160"));
    descriptionLabel->setText(description);
    descriptionLabel->setMaximumWidth(450);
    descriptionLabel->setWordWrap(true);
    tooltipContent.append(descriptionLabel);

    ui->labelWithTooltip->setTooltipContent(tooltipContent);
}

LabelWithTooltip* PrimarySkillSignature::getlabelWithTooltip()
{
    return ui->labelWithTooltip;
}

/*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
 *Считаются только Ctrl,Shift и Alt*/
void PrimarySkillSignature::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    if(key==16777249||key==16777248||key==16777251)
        Global::pressedKeys.append(key);
}

/*Эвент отжатия клавиши, который находит и удаляет код клавиши из вектора pressedKeys.
 *Сделано это для того, чтобы обрабатывать случай, когда зажато несколько модификаторов
 *одновременно. Они не будут последовательно обработаны, считаться будет только последний,
 *но если просто сбрасывать int переменную, то может возникать случай, когда второй
 *модификатор будет зажат до отжатия предыдущего, а затем первый будет отжат, и управление
 *как бы "заест", модификатор придётся жать вновь. Для избежания этого и создан этот вектор.*/
void PrimarySkillSignature::keyReleaseEvent(QKeyEvent *event)
{
    int key=event->key();
    QMutableVectorIterator<int> keyIterator(Global::pressedKeys);

    /*Так как вектор pressedKeys доступен многим виджетам одновременно, гипотетически
     *возможна ситуация когда фокус получат одновременно несколько виджетов, и они
     *начнут отправлять в вектор дубликаты ключей зажатых клавиш. Для просчёта
     *модификаторов это никакой проблемы не создаст, но возможна ситуация когда до
     *отжатия клавиши один или несколько таких виджетов, передавших ключи клавиш,
     *потеряют фокус, соответственно ключи переданные ими не удалятся из вектора.
     *И для избежания такой ситуации итератор проходит по всему вектору, удаляя из
     *него все вхождения переданного ключа, а не первое. Подразумевается что этот
     *метод будет вызван хотя бы 1 раз из любого виджета в фокусе.*/
    while(keyIterator.hasNext()) {
      int currentValue=keyIterator.next();

      if(currentValue==key)
        keyIterator.remove();
    }
}

int i = 0;
bool PrimarySkillSignature::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::HoverMove){
        if(isShowTooltip)
            emit ShowTooltip(buttonTooltipContent);
    }else if(object == ui->ButtonTop && event->type() == QEvent::HoverEnter){
        clickModifierTooltipTimer->start(2300);
        buttonTooltipContentLabel->setText("Alt: +5\nCtrl: +10\nShift: +100");
    }else if(object == ui->ButtonBottom && event->type() == QEvent::HoverEnter){
        clickModifierTooltipTimer->start(2300);
        buttonTooltipContentLabel->setText("Alt: -5\nCtrl: -10\nShift: -100");
    }else if(event->type() == QEvent::HoverLeave||event->type() == QEvent::MouseButtonPress){
        clickModifierTooltipTimer->stop();
        if(isShowTooltip)
            emit RemoveTooltip();
        isShowTooltip = false;
    }

    return false;
}

