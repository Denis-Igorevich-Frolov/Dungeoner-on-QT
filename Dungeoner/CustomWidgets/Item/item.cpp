/********************************************************************************
 *Данный класс является классом вещи. Здесь хранятся все её характеристики
 *и имеются все необходимые методы визуализации предметов в инвентаре.
 ********************************************************************************/

#include "I_stylemaster.h"
#include "item.h"
#include "qpainter.h"
#include "ui_item.h"

#include <qdir.h>

Item::Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->pushButton->installEventFilter(this);

    shadow->setColor(Qt::black);
    shadow->setBlurRadius(shadowBlurRadius);
    shadow->setOffset(shadowXOffset, shadowYOffset);

//    styles.append({this, this, this, this});

    //Если у предмета несколько стилей, то включаются кнопки смены стилей
    if(styles.size()>1){
        /*Жёстко задаётся размер области кнопок стилей, чтобы как можно меньше перекрывать этим блоком виджет итема.
         *
         *2 - это нижний отступ, который учтён в размере, отдаваемом на каждую ячейку, но у последней кнопки нижний отступ не нужен.*/
        ui->StyleButtonsWrapper->setFixedHeight(14*styles.size()-2);
        //Получают стили и видимость столько кнопок, сколько стилей есть у вещи
        for(int i = 0; i < ui->StyleButtonsWrapper->children().size()-1; i++){
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setStyleSheet(I_stylemaster::StyleButtonStile());
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setFont(QFont("TextFont"));
        }
        for(int i = 4; i>styles.size()-1; i--)
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setVisible(false);
        //По умолчанию область кнопок стилей полупрозрачная
        opacity->setOpacity(0.3);
        ui->StyleButtonsWrapper->setGraphicsEffect(opacity);
        ui->StyleButtonsWrapper->installEventFilter(this);
    }else
        ui->StyleButtonsWrapper->setVisible(false);

    ui->Quantity->setFont(QFont("TextFont"));
    ui->Quantity->setStyleSheet(I_stylemaster::TextFontStyle(17));
    border->setOutlineThickness(2);
    ui->Quantity->setMargin(2);
    ui->Quantity->setGraphicsEffect(border);

    folderName = "Test";
    id = 0;
    isPressable = true;
    isNew = true;
    quantity=999;

    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Game Saves/" + Global::DungeonName + "/Items/"+folderName))
        dir.mkpath("Game Saves/" + Global::DungeonName + "/Items/"+folderName);

    if(QFile("Game Saves/" + Global::DungeonName + "/Items/"+folderName+"/image.png").exists())
        image = QImage("Game Saves/" + Global::DungeonName + "/Items/"+folderName+"/image.png");
    else{
        image = QImage(":/Inventory/Textures PNG/Unknown-Item.png");
        hoverColor = QColor(255, 255, 255, 30);
        pressedColor = QColor(0, 0, 0, 50);
    }

    ui->Image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
    if(hasShadow)
        ui->Image->setGraphicsEffect(shadow);

    ui->Quantity->setText(QString::number(quantity));
}

Item::~Item()
{
    delete shadow;
    delete border;
    delete ui;
}

int Item::getId() const
{
    return id;
}

//Установка/отключение стиля заглушенного итема
void Item::setDisabledSyle(bool isDisabled)
{
    QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

    if(isDisabled){
        //Если вещь сломана, то устанавливается стиль заглушенной сломанной вещи
        if(isBroken)
            //В таком случае накладываемый цвет представляет из себя средний цвет между сломанным и заглушенным
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                   (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
        //Иначе просто заглушенной вещи
        else
            painter.fillRect(pixmap.rect(), disabledColor);

        ui->Image->setPixmap(pixmap);
        this->isDisabled = true;
    //Если стиль выключается, то просто все воздействия наложения заглушенного цвета снимаются
    }else{
        if(isBroken){
            painter.fillRect(pixmap.rect(), brokenColor);
            ui->Image->setPixmap(pixmap);
        }else
            ui->Image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
        this->isDisabled = false;
    }
}

//Установка/отключение стиля сломанного итема
void Item::setBrokenSyle(bool isBroken)
{
    QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

    if(isBroken){
        //Если вещь заглушена, то устанавливается стиль заглушенной сломанной вещи
        if(isDisabled)
            //В таком случае накладываемый цвет представляет из себя средний цвет между сломанным и заглушенным
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                   (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
        //Иначе просто сломанной вещи
        else
            painter.fillRect(pixmap.rect(), brokenColor);

        ui->Image->setPixmap(pixmap);
        this->isBroken = true;
    //Если стиль выключается, то просто все воздействия наложения сломанного цвета снимаются
    }else{
        if(isDisabled){
            painter.fillRect(pixmap.rect(), disabledColor);
            ui->Image->setPixmap(pixmap);
        }else
            ui->Image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
        this->isBroken = false;
    }
}

bool Item::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->pushButton){
        if(isPressable){
            //Наложение на итем цета наведения
            if(event->type() == QEvent::HoverEnter){
                QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
                QPainter painter(&pixmap);
                painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
                //Если вещь сломана и заглушена, то находится средний цвет между заглушенным, сломанным и наведённым цветами
                if(isDisabled && isBroken)
                    painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red() + hoverColor.red())/3,
                                                           (disabledColor.green() + brokenColor.green() + hoverColor.green())/3,
                                                           (disabledColor.blue() + brokenColor.blue() + hoverColor.blue())/3,
                                                           (disabledColor.alpha() + brokenColor.alpha() + hoverColor.alpha())/3));
                //Если вещь заглушена, то находится средний цвет между заглушенным и наведённым цветами
                else if(isDisabled)
                    painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + hoverColor.red())/2, (disabledColor.green() + hoverColor.green())/2,
                                                           (disabledColor.blue() + hoverColor.blue())/2, (disabledColor.alpha() + hoverColor.alpha())/2));
                //Если вещь сломана, то находится средний цвет между ломанным и наведённым цветами
                else if(isBroken)
                    painter.fillRect(pixmap.rect(), QColor((brokenColor.red() + hoverColor.red())/2, (brokenColor.green() + hoverColor.green())/2,
                                                           (brokenColor.blue() + hoverColor.blue())/2, (brokenColor.alpha() + hoverColor.alpha())/2));
                else
                    painter.fillRect(pixmap.rect(), hoverColor);

                ui->Image->setPixmap(pixmap);

                isHovered = true;
            }
            //Возвращение исходных цветов
            else if(event->type() == QEvent::HoverLeave){
                QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
                QPainter painter(&pixmap);
                painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
                //Если вещь сломана и заглушена, то находится средний цвет между заглушенным и сломанным цветами
                if(isDisabled && isBroken){
                    painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                           (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
                    ui->Image->setPixmap(pixmap);
                }else if(isDisabled){
                    painter.fillRect(pixmap.rect(), disabledColor);
                    ui->Image->setPixmap(pixmap);
                }else if(isBroken){
                    painter.fillRect(pixmap.rect(), brokenColor);
                    ui->Image->setPixmap(pixmap);
                }
                else
                    ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));

                isHovered = false;
            }
        }
    }
    if(object == ui->StyleButtonsWrapper){
        //При наведении, область кнопок стилей итема становится полностью непрозрачной
        if(event->type() == QEvent::Enter){
            opacity->setOpacity(1);
        }
        else if(event->type() == QEvent::Leave){
            opacity->setOpacity(0.3);
        }
    }

    return false;
}

//Эффекты при прожатии итема
void Item::on_pushButton_clicked()
{
    if(isPressable){
        qDebug()<<"Делаю штуку";
    }
}

void Item::on_pushButton_pressed()
{
    if(isPressable){
        //Наложение на итем цвета нажатия
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

        //Если вещь сломана и заглушена, то находится средний цвет между заглушенным, сломанным и нажатым цветами
        if(isDisabled && isBroken)
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red() + pressedColor.red())/3,
                                                   (disabledColor.green() + brokenColor.green() + pressedColor.green())/3,
                                                   (disabledColor.blue() + brokenColor.blue() + pressedColor.blue())/3,
                                                   (disabledColor.alpha() + brokenColor.alpha() + pressedColor.alpha())/3));
        //Если вещь заглушена, то находится средний цвет между заглушенным и нажатым цветами
        else if(isDisabled)
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + pressedColor.red())/2, (disabledColor.green() + pressedColor.green())/2,
                                                   (disabledColor.blue() + pressedColor.blue())/2, (disabledColor.alpha() + pressedColor.alpha())/2));
        //Если вещь сломана, то находится средний цвет между ломанным и нажатым цветами
        else if(isBroken)
            painter.fillRect(pixmap.rect(), QColor((brokenColor.red() + pressedColor.red())/2, (brokenColor.green() + pressedColor.green())/2,
                                                   (brokenColor.blue() + pressedColor.blue())/2, (brokenColor.alpha() + pressedColor.alpha())/2));
        else
            painter.fillRect(pixmap.rect(), pressedColor);

        ui->Image->setPixmap(pixmap);
    }
}


void Item::on_pushButton_released()
{
    if(isPressable){
        //Возвращение исходных цветов
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

        //Если на итем всё ещё наведена мышь, то ей возвращаются цвета наведения
        if(isHovered){
            //Если вещь сломана и заглушена, то находится средний цвет между заглушенным, сломанным и наведённым цветами
            if(isDisabled && isBroken)
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red() + hoverColor.red())/3,
                                                       (disabledColor.green() + brokenColor.green() + hoverColor.green())/3,
                                                       (disabledColor.blue() + brokenColor.blue() + hoverColor.blue())/3,
                                                       (disabledColor.alpha() + brokenColor.alpha() + hoverColor.alpha())/3));
            //Если вещь заглушена, то находится средний цвет между заглушенным и наведённым цветами
            else if(isDisabled)
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + hoverColor.red())/2, (disabledColor.green() + hoverColor.green())/2,
                                                       (disabledColor.blue() + hoverColor.blue())/2, (disabledColor.alpha() + hoverColor.alpha())/2));
            //Если вещь сломана, то находится средний цвет между ломанным и наведённым цветами
            else if(isBroken)
                painter.fillRect(pixmap.rect(), QColor((brokenColor.red() + hoverColor.red())/2, (brokenColor.green() + hoverColor.green())/2,
                                                       (brokenColor.blue() + hoverColor.blue())/2, (brokenColor.alpha() + hoverColor.alpha())/2));
            else
                painter.fillRect(pixmap.rect(), hoverColor);

            ui->Image->setPixmap(pixmap);
        //Иначе возвращаются обычные цвета
        }else
            //Если вещь сломана и заглушена, то находится средний цвет между заглушенным и сломанным цветами
            if(isDisabled && isBroken){
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                       (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
                ui->Image->setPixmap(pixmap);
            }else if(isDisabled){
                painter.fillRect(pixmap.rect(), disabledColor);

                ui->Image->setPixmap(pixmap);
            }else if(isBroken){
                painter.fillRect(pixmap.rect(), brokenColor);

                ui->Image->setPixmap(pixmap);
            }
            else
                ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
    }
}

bool Item::getIsBroken() const
{
    return isBroken;
}

