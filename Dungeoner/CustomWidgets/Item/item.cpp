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

    quantity=999;
    styles.append({this, this, this, this});

    if(styles.size()>1){
        ui->StyleButtonsWrapper->setFixedHeight(14*styles.size()-2);
        for(int i = 0; i < ui->StyleButtonsWrapper->children().size()-1; i++){
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setStyleSheet(I_stylemaster::StyleButtonStile());
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setFont(QFont("TextFont"));
        }
        for(int i = 4; i>styles.size()-1; i--)
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setVisible(false);
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

void Item::setDisabledSyle(bool isDisabled)
{
    if(isDisabled){
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.fillRect(pixmap.rect(), disabledColor);

        ui->Image->setPixmap(pixmap);
        this->isDisabled = true;
    }else{
        ui->Image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
        this->isDisabled = false;
    }

}

bool Item::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->pushButton){
        if(event->type() == QEvent::HoverEnter){
            QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
            QPainter painter(&pixmap);
            painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
            if(isDisabled)
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + hoverColor.red())/2, (disabledColor.green() + hoverColor.green())/2,
                                                       (disabledColor.blue() + hoverColor.blue())/2, (disabledColor.alpha() + hoverColor.alpha())/2));
            else
                painter.fillRect(pixmap.rect(), hoverColor);

            ui->Image->setPixmap(pixmap);

            isHovered = true;
        }
        else if(event->type() == QEvent::HoverLeave){
            if(isDisabled){
                QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
                QPainter painter(&pixmap);
                painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
                painter.fillRect(pixmap.rect(), disabledColor);

                ui->Image->setPixmap(pixmap);
            }else
                ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));

            isHovered = false;
        }
    }
    if(object == ui->StyleButtonsWrapper){
        if(event->type() == QEvent::Enter){
            opacity->setOpacity(1);
        }
        else if(event->type() == QEvent::Leave){
            opacity->setOpacity(0.3);
        }
    }

    return false;
}

void Item::on_pushButton_clicked()
{
    qDebug()<<"Делаю штуку";
}


void Item::on_pushButton_pressed()
{
    QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

    if(isDisabled){
        painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + pressedColor.red())/2, (disabledColor.green() + pressedColor.green())/2,
                                               (disabledColor.blue() + pressedColor.blue())/2, (disabledColor.alpha() + pressedColor.alpha())/2));
        ui->Image->setPixmap(pixmap);
    }else{
        painter.fillRect(pixmap.rect(), pressedColor);
        ui->Image->setPixmap(pixmap);
    }
}


void Item::on_pushButton_released()
{
    QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

    if(isHovered){
        if(isDisabled){
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + hoverColor.red())/2, (disabledColor.green() + hoverColor.green())/2,
                                                   (disabledColor.blue() + hoverColor.blue())/2, (disabledColor.alpha() + hoverColor.alpha())/2));

            ui->Image->setPixmap(pixmap);
        }else{
            painter.fillRect(pixmap.rect(), hoverColor);

            ui->Image->setPixmap(pixmap);
        }
    }else
        if(isDisabled){
            painter.fillRect(pixmap.rect(), disabledColor);

            ui->Image->setPixmap(pixmap);
        }else
            ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
}

