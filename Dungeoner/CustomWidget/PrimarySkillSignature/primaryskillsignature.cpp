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

void PrimarySkillSignature::on_ButtonTop_released()
{
    QVector<int>::iterator iterator = std::find(pressedKeys.begin(), pressedKeys.end(), 16777249);
    if(iterator!=pressedKeys.end()){
        for(int key : pressedKeys){
            if(key == 16777249){
                SpinBoxValue->setValue(SpinBoxValue->value() + 10);
                for(int key : pressedKeys){
                    if(key == 16777248){
                        SpinBoxValue->setValue(SpinBoxValue->value() + 90);
                        for(int key : pressedKeys){
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


void PrimarySkillSignature::on_ButtonBottom_released()
{
    QVector<int>::iterator iterator = std::find(pressedKeys.begin(), pressedKeys.end(), 16777249);
    if(iterator!=pressedKeys.end()){
        for(int key : pressedKeys){
            if(key == 16777249){
                SpinBoxValue->setValue(SpinBoxValue->value() - 10);
                for(int key : pressedKeys){
                    if(key == 16777248){
                        SpinBoxValue->setValue(SpinBoxValue->value() - 90);
                        for(int key : pressedKeys){
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

void PrimarySkillSignature::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    pressedKeys.append(key);
}

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

