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
    if(!dir.exists("Items/"+folderName))
        dir.mkpath("Items/"+folderName);
    image = QImage("Items/"+folderName+"/image.png");

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
    if(event->type() == QEvent::HoverEnter){
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.fillRect(pixmap.rect(), hoverColor);

        ui->Image->setPixmap(pixmap);

        isHovered = true;
    }
    if(event->type() == QEvent::HoverLeave){
        ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));

        isHovered = false;
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

