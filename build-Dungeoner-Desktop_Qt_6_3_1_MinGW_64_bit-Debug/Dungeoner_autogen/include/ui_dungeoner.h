/********************************************************************************
** Form generated from reading UI file 'dungeoner.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
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
            Dungeoner->setObjectName(QString::fromUtf8("Dungeoner"));
        Dungeoner->resize(800, 600);
        centralwidget = new QWidget(Dungeoner);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Dungeoner->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dungeoner);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Dungeoner->setMenuBar(menubar);
        statusbar = new QStatusBar(Dungeoner);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
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
