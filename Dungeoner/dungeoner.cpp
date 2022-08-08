/****************************
 *Главный класс приложения
 ****************************/

#include "dungeoner.h"
#include "./ui_dungeoner.h"

//#include <QFontDatabase>

Dungeoner::Dungeoner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dungeoner)
{
//    ui->setupUi(this);

//    this->close();

    characterWindow = new CharacterWindow();
    characterWindow->show();

//    int id = QFontDatabase::addApplicationFont(":/Fonts/TextFont.ttf");
//    QString f = QFontDatabase::applicationFontFamilies(id).at(0);
//    qDebug()<<f;
}

Dungeoner::~Dungeoner()
{
    delete ui;
    delete characterWindow;
}
