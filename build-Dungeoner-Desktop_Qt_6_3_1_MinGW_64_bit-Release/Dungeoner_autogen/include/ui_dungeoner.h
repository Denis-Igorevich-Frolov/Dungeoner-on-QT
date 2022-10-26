/********************************************************************************
** Form generated from reading UI file 'dungeoner.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUNGEONER_H
#define UI_DUNGEONER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dungeoner
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dungeoner)
    {
        if (Dungeoner->objectName().isEmpty())
            Dungeoner->setObjectName("Dungeoner");
        Dungeoner->resize(800, 600);
        Dungeoner->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Dungeoner);
        centralwidget->setObjectName("centralwidget");
        Dungeoner->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dungeoner);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Dungeoner->setMenuBar(menubar);
        statusbar = new QStatusBar(Dungeoner);
        statusbar->setObjectName("statusbar");
        Dungeoner->setStatusBar(statusbar);

        retranslateUi(Dungeoner);

        QMetaObject::connectSlotsByName(Dungeoner);
    } // setupUi

    void retranslateUi(QMainWindow *Dungeoner)
    {
        Dungeoner->setWindowTitle(QCoreApplication::translate("Dungeoner", "Dungeoner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dungeoner: public Ui_Dungeoner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUNGEONER_H
