#include "tooltip.h"
#include "ui_tooltip.h"

Tooltip::Tooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tooltip)
{
    ui->setupUi(this);
}

Tooltip::~Tooltip()
{
    delete ui;
}
