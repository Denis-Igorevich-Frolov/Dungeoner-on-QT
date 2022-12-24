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

    folderName = "Test";
    id = 0;

    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Items/"+folderName))
        dir.mkpath("Items/"+folderName);
    QImage image = QImage("Items/"+folderName+"/image.png");

    ui->image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
    if(hasShadow)
        ui->image->setGraphicsEffect(shadow);
}

Item::~Item()
{
    delete shadow;
    delete ui;
}

int Item::getId() const
{
    return id;
}
