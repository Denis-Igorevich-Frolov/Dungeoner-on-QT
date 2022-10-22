/*********************************************************
 *Данный класс является виджетом рамки. Просто рамка,
 *от остальных отличается только внешним видом
 *********************************************************/

#include "windowborder_2.h"
#include "ui_windowborder_2.h"
#include "WB2_stylemaster.h"

WindowBorder_2::WindowBorder_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowBorder_2)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->BottomLeftCorner->setStyleSheet(WB2_Stylemaster::BottomLeftCornerStyle());
    ui->BottomRightCorner->setStyleSheet(WB2_Stylemaster::BottomRightCornerStyle());
    ui->TopLeftCorner->setStyleSheet(WB2_Stylemaster::TopLeftCornerStyle());
    ui->TopRightCorner->setStyleSheet(WB2_Stylemaster::TopRightCornerStyle());

    ui->BottomBorder->setStyleSheet(WB2_Stylemaster::BottomBorderStyle());
    ui->TopBorder->setStyleSheet(WB2_Stylemaster::TopBorderStyle());
    ui->LeftBorder->setStyleSheet(WB2_Stylemaster::LeftBorderStyle());
    ui->RightBorder->setStyleSheet(WB2_Stylemaster::RightBorderStyle());
}

WindowBorder_2::~WindowBorder_2()
{
    delete ui;
}
