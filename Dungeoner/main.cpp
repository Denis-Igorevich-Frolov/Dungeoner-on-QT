#include "dungeoner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dungeoner dungeoner;
//    dungeoner.show();
    return a.exec();
}
