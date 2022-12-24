/****************************
 *Главный класс приложения
 ****************************/

#include "dungeoner.h"
#include "./ui_dungeoner.h"

#include <QFontDatabase>

//#include <QFontDatabase>

Dungeoner::Dungeoner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dungeoner)
{
    QFontDatabase::addApplicationFont(":/Fonts/TextFont.ttf");
    QFontDatabase::addApplicationFont(":/Fonts/NumbersFont.ttf");

    characterWindow = new CharacterWindow();
    characterWindow->show();

    Global::numberOfBackups = 10;
}

Dungeoner::~Dungeoner()
{
    delete ui;
    delete characterWindow;
}
