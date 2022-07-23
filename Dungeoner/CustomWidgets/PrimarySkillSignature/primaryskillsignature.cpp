/*Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.*/

#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "stylemaster.h"
#include <QMouseEvent>
#include <QMutableVectorIterator>

QVector<int> PrimarySkillSignature::pressedKeys;

PrimarySkillSignature::PrimarySkillSignature(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimarySkillSignature)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->labelCenter->setStyleSheet(StyleMaster::CenterTextureStyle());
    ui->ButtonTop->setStyleSheet(StyleMaster::topTextureStyle());
    ui->ButtonBottom->setStyleSheet(StyleMaster::bottomTextureStyle());
    ui->labelRight->setStyleSheet(StyleMaster::RightTextureStyle());
    ui->labelLeft->setStyleSheet(StyleMaster::LeftTextureStyle());
}

PrimarySkillSignature::~PrimarySkillSignature()
{
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
    Global::mediaplaer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click2.wav"), MediaPlayer::SoundsGroup::SOUNDS);

    int plus = 1;

    if(!pressedKeys.empty()){
        //Ctrl
        if(pressedKeys.last() == 16777249){
            plus = 10;
        }
        //Shift
        if(pressedKeys.last() == 16777248){
            plus = 100;
        }
        //Alt
        if(pressedKeys.last() == 16777251){
            plus = 1000;
        }
    }

    SpinBoxValue->setValue(SpinBoxValue->value() + plus);
}

/*Метод реализации нажатия кнопки вычета стата. Он обрабатывает нажатия с учётом модификаторов:
 *Ctrl: -10, Shift: -100, Alt: -1000. Обычное нажатие: -1. Модификатором считается последняя нажатая клавиша.*/
void PrimarySkillSignature::on_ButtonBottom_released()
{
    Global::mediaplaer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click2.wav"), MediaPlayer::SoundsGroup::SOUNDS);

    int minus = 1;

    if(!pressedKeys.empty()){
        //Ctrl
        if(pressedKeys.last() == 16777249){
            minus = 10;
        }
        //Shift
        if(pressedKeys.last() == 16777248){
            minus = 100;
        }
        //Alt
        if(pressedKeys.last() == 16777251){
            minus = 1000;
        }
    }

    SpinBoxValue->setValue(SpinBoxValue->value() - minus);
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
        pressedKeys.append(key);
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
    QMutableVectorIterator<int> keyIterator(pressedKeys);

    while(keyIterator.hasNext()) {
      int currentValue=keyIterator.next();

      if(currentValue==key)
        keyIterator.remove();
    }
}

