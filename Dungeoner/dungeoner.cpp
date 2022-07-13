#include "dungeoner.h"
#include "./ui_dungeoner.h"

Dungeoner::Dungeoner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dungeoner)
{
    ui->setupUi(this);
}

Dungeoner::~Dungeoner()
{
    delete ui;
}

