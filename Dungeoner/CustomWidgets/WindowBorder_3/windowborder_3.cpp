#include "windowborder_3.h"
#include "ui_windowborder_3.h"

WindowBorder_3::WindowBorder_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowBorder_3)
{
    ui->setupUi(this);
}

WindowBorder_3::~WindowBorder_3()
{
    delete ui;
}

void WindowBorder_3::resizeEvent(QResizeEvent *event)
{
    ui->Wrapper1->setFixedSize(this->size());
    ui->Wrapper2->setFixedSize(this->size());
    ui->Wrapper3->setFixedSize(this->size());
    ui->Wrapper4->setFixedSize(this->size());
}
