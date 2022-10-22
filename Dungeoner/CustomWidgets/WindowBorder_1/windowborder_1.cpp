/*********************************************************
 *Данный класс является виджетом рамки. Просто рамка,
 *от остальных отличается только внешним видом
 *********************************************************/

#include "windowborder_1.h"
#include "ui_windowborder_1.h"
#include "WB1_stylemaster.h"

WindowBorder_1::WindowBorder_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowBorder_1)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->BottomLeftCorner->setStyleSheet(WB1_Stylemaster::BottomLeftCornerStyle());
    ui->BottomRightCorner->setStyleSheet(WB1_Stylemaster::BottomRightCornerStyle());
    ui->TopLeftCorner->setStyleSheet(WB1_Stylemaster::TopLeftCornerStyle());
    ui->TopRightCorner->setStyleSheet(WB1_Stylemaster::TopRightCornerStyle());

    ui->BottomBorder->setStyleSheet(WB1_Stylemaster::BottomBorderStyle());
    ui->TopBorder->setStyleSheet(WB1_Stylemaster::TopBorderStyle());
    ui->LeftBorder->setStyleSheet(WB1_Stylemaster::LeftBorderStyle());
    ui->RightBorder->setStyleSheet(WB1_Stylemaster::RightBorderStyle());
}

WindowBorder_1::~WindowBorder_1()
{
    delete ui;
}
