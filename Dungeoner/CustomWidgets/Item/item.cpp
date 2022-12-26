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

    quantity=33;
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

bool Item::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->pushButton){
        if(event->type() == QEvent::HoverEnter){
            QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
            QPainter painter(&pixmap);
            painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
            painter.fillRect(pixmap.rect(), hoverColor);

            ui->Image->setPixmap(pixmap);

            isHovered = true;
        }
        else if(event->type() == QEvent::HoverLeave){
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
    painter.fillRect(pixmap.rect(), pressedColor);

    ui->Image->setPixmap(pixmap);
}


void Item::on_pushButton_released()
{
    if(isHovered){
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.fillRect(pixmap.rect(), QColor(255, 255, 255, 40));

        ui->Image->setPixmap(pixmap);
    }else
        ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
}

