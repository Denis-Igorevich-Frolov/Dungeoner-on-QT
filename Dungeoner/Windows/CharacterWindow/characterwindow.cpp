#include "characterwindow.h"
#include "ui_characterwindow.h"

CharacterWindow::CharacterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

CharacterWindow::~CharacterWindow()
{
    delete ui;
}
