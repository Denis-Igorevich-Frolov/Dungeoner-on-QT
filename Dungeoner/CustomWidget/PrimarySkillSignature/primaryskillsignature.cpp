/*
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 */

#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "stylemaster.h"
#include <QMouseEvent>
#include <QMutableVectorIterator>

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
 *Ctrl: +10, Ctrl+Shift: +100, Ctrl+Shift+Alt: +1000. Обычное нажатие: +1. Во вложенных циклах
 *поиска прибавка написана как +90 и +900 из-за того, что если код дошёл до этой позиции,
 *то соответственно все вышестоящие прибавки уже были произведены.
 */
void PrimarySkillSignature::on_ButtonTop_released()
{
    QVector<int>::iterator iterator = std::find(pressedKeys.begin(), pressedKeys.end(), 16777249);
    if(iterator!=pressedKeys.end()){
        for(int key : pressedKeys){
            //Ctrl
            if(key == 16777249){
                SpinBoxValue->setValue(SpinBoxValue->value() + 10);
                for(int key : pressedKeys){
                    //Ctrl+Shift
                    if(key == 16777248){
                        SpinBoxValue->setValue(SpinBoxValue->value() + 90);
                        for(int key : pressedKeys){
                            //Ctrl+Shift+Alt
                            if(key == 16777251){
                                SpinBoxValue->setValue(SpinBoxValue->value() + 900);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }else
        SpinBoxValue->setValue(SpinBoxValue->value() + 1);
}

/*Метод реализации нажатия кнопки убавления стата. Он обрабатывает нажатия с учётом модификаторов:
 *Ctrl: -10, Ctrl+Shift: -100, Ctrl+Shift+Alt: -1000. Обычное нажатие: -1. Во вложенных циклах
 *поиска убавление написано как -90 и -900 из-за того, что если код дошёл до этой позиции, то
 *соответственно все вышестоящие вычеты уже были произведены.
 */
void PrimarySkillSignature::on_ButtonBottom_released()
{
    QVector<int>::iterator iterator = std::find(pressedKeys.begin(), pressedKeys.end(), 16777249);
    if(iterator!=pressedKeys.end()){
        for(int key : pressedKeys){
            //Ctrl
            if(key == 16777249){
                SpinBoxValue->setValue(SpinBoxValue->value() - 10);
                for(int key : pressedKeys){
                    //Ctrl+Shift
                    if(key == 16777248){
                        SpinBoxValue->setValue(SpinBoxValue->value() - 90);
                        for(int key : pressedKeys){
                            //Ctrl+Shift+Alt
                            if(key == 16777251){
                                SpinBoxValue->setValue(SpinBoxValue->value() - 900);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }else
        SpinBoxValue->setValue(SpinBoxValue->value() - 1);
}

/*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
 *Считаются только Ctrl,Shift и Alt
 */
void PrimarySkillSignature::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    if(key==16777249||key==16777248||key==16777251)
        pressedKeys.append(key);
}

//Эвент отжатия клавиши, который находит и удаляет код клавиши из вектора pressedKeys
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

