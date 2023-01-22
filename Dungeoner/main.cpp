#include "QtTest/qtestcase.h"
#include "dungeoner.h"

#include <QApplication>

#include <System/UnitTests/SecondarySkillsTest/secondarySkillsTest.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Юнит тесты
    QTest::qExec(new SecondarySkillsTest, argc, argv);

    Dungeoner dungeoner;

    return a.exec();
}
