#include "I_stylemaster.h"
#include "item.h"
#include "ui_item.h"

#include <qdir.h>

Item::Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item)
{
    ui->setupUi(this);

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

    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Items/"+folderName))
        dir.mkpath("Items/"+folderName);
    QImage image = QImage("Items/"+folderName+"/image.png");

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
