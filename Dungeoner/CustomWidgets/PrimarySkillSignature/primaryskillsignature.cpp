/***********************************************************
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 ***********************************************************/

#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "PSS_stylemaster.h"
#include "Windows/CharacterWindow/characterwindow.h"

#include <QFontDatabase>
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

    ui->ButtonTop->installEventFilter(this);
    ui->ButtonBottom->installEventFilter(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

    tooltipContentLabel->setFont(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/Fonts/TextFont.ttf")).at(0));
    tooltipContentLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(20, "bdc440"));
    buttonTooltipContent.append(tooltipContentLabel);
}

PrimarySkillSignature::~PrimarySkillSignature()
{
    for(QLabel* label : tooltipContent)
        delete label;
    delete tooltipContentLabel;
    delete ui;
}

//Устанавливает текст для LabelWithTooltip
void PrimarySkillSignature::setText(QString text)
{
    ui->labelWithTooltip->setText(text);
}

/*Метод реализации нажатия кнопки прибавки стата. Он обрабатывает нажатия с учётом модификаторов:
 *Ctrl: +10, Shift: +100, Alt: +1000. Обычное нажатие: +1. Модификатором считается последняя нажатая клавиша.*/
void PrimarySkillSignature::on_ButtonTop_released()
{
    Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);

    int plus = 1;

    if(!CharacterWindow::pressedKeys.empty()){
        //Ctrl
        if(CharacterWindow::pressedKeys.last() == 16777249){
            plus = 10;
        }
        //Shift
        if(CharacterWindow::pressedKeys.last() == 16777248){
            plus = 100;
        }
        //Alt
        if(CharacterWindow::pressedKeys.last() == 16777251){
            plus = 1000;
        }
    }

    SpinBoxValue->setValue(SpinBoxValue->value() + plus);
}

/*Метод реализации нажатия кнопки вычета стата. Он обрабатывает нажатия с учётом модификаторов:
 *Ctrl: -10, Shift: -100, Alt: -1000. Обычное нажатие: -1. Модификатором считается последняя нажатая клавиша.*/
void PrimarySkillSignature::on_ButtonBottom_released()
{
    Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);

    int minus = 1;

    if(!CharacterWindow::pressedKeys.empty()){
        //Ctrl
        if(CharacterWindow::pressedKeys.last() == 16777249){
            minus = 10;
        }
        //Shift
        if(CharacterWindow::pressedKeys.last() == 16777248){
            minus = 100;
        }
        //Alt
        if(CharacterWindow::pressedKeys.last() == 16777251){
            minus = 1000;
        }
    }

    SpinBoxValue->setValue(SpinBoxValue->value() - minus);
}

void PrimarySkillSignature::slotTimerAlarm()
{
    isShowTooltip = true;
    timer->stop();
    emit ShowTooltip(buttonTooltipContent);
}

void PrimarySkillSignature::setTooltipContent(QString fullName, QString description)
{
    QLabel* fullNameLabel = new QLabel;
    fullNameLabel->setFont(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/Fonts/TextFont.ttf")).at(0));
    fullNameLabel->setStyleSheet(PSS_StyleMaster::TooltipTextStyle(27, "bdc440"));
    fullNameLabel->setText(fullName);
    fullNameLabel->setMaximumWidth(400);
    tooltipContent.append(fullNameLabel);

    QLabel* separator = new QLabel;
    separator->setFixedSize(400, 1);
    separator->setStyleSheet("background: #bdc440;");
    tooltipContent.append(separator);

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
        CharacterWindow::pressedKeys.append(key);
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
    QMutableVectorIterator<int> keyIterator(CharacterWindow::pressedKeys);

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
        timer->start(2300);
        tooltipContentLabel->setText("Ctrl: +10\nShift: +100\nAlt: +1000");
    }else if(object == ui->ButtonBottom && event->type() == QEvent::HoverEnter){
        timer->start(2300);
        tooltipContentLabel->setText("Ctrl: -10\nShift: -100\nAlt: -1000");
    }else if(event->type() == QEvent::HoverLeave||event->type() == QEvent::MouseButtonPress){
        timer->stop();
        if(isShowTooltip)
            emit RemoveTooltip();
        isShowTooltip = false;
    }

    return false;
}

