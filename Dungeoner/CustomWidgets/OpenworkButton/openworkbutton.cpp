#include "openworkbutton.h"
#include "ui_openworkbutton.h"
#include "Global/globalstylemaster.h"
#include "CustomWidgets/WindowBorder_3/WB3_stylemaster.h"
#include "OB_stylemaster.h"

OpenworkButton::OpenworkButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenworkButton)
{
    ui->setupUi(this);

    ui->Border->setStyleSheet(WB3_Stylemaster::setRegularStyle());
    this->setStyleSheet(OB_Stylemaster::setRegularStyle());
    ui->pushButton->setFont(QFont("TextFont"));
    ui->pushButton->setStyleSheet(GlobalStyleMaster::TooltipTextStyle(20, "bdc440"));
}

OpenworkButton::~OpenworkButton()
{
    delete ui;
}

void OpenworkButton::setTextSize(int size)
{
    ui->pushButton->setStyleSheet(GlobalStyleMaster::TooltipTextStyle(size, "bdc440"));
}

void OpenworkButton::resizeEvent(QResizeEvent *event)
{
    ui->Border->setFixedSize(this->size());
    ui->DecorativeElementWraper->setFixedSize(this->size());
    ui->BackgroundWraper->setFixedSize(this->size());
    ui->pushButton->setFixedSize(this->size());
}

void OpenworkButton::on_pushButton_clicked()
{

}


void OpenworkButton::on_pushButton_pressed()
{

}


void OpenworkButton::on_pushButton_released()
{

}


void OpenworkButton::on_pushButton_toggled(bool checked)
{

}

