#include "windowborder_1.h"
#include "ui_windowborder_1.h"
#include "stylemaster.h"

WindowBorder_1::WindowBorder_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowBorder_1)
{
    ui->setupUi(this);

    ui->BottomLeftCorner->setStyleSheet(stylemaster::BottomLeftCornerStyle());
    ui->BottomRightCorner->setStyleSheet(stylemaster::BottomRightCornerStyle());
    ui->TopLeftCorner->setStyleSheet(stylemaster::TopLeftCornerStyle());
    ui->TopRightCorner->setStyleSheet(stylemaster::TopRightCornerStyle());

    ui->BottomBorder->setStyleSheet(stylemaster::BottomBorderStyle());
    ui->TopBorder->setStyleSheet(stylemaster::TopBorderStyle());
    ui->LeftBorder->setStyleSheet(stylemaster::LeftBorderStyle());
    ui->RightBorder->setStyleSheet(stylemaster::RightBorderStyle());
}

WindowBorder_1::~WindowBorder_1()
{
    delete ui;
}
