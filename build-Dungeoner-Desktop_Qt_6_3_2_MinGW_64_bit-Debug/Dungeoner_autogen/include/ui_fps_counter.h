/********************************************************************************
** Form generated from reading UI file 'fps_counter.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPS_COUNTER_H
#define UI_FPS_COUNTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FPS_Counter
{
public:
    QLabel *FPSLabel;

    void setupUi(QWidget *FPS_Counter)
    {
        if (FPS_Counter->objectName().isEmpty())
            FPS_Counter->setObjectName(QString::fromUtf8("FPS_Counter"));
        FPS_Counter->resize(60, 30);
        FPSLabel = new QLabel(FPS_Counter);
        FPSLabel->setObjectName(QString::fromUtf8("FPSLabel"));
        FPSLabel->setGeometry(QRect(0, 0, 60, 30));
        FPSLabel->setStyleSheet(QString::fromUtf8("background: white;\n"
"color: black;"));

        retranslateUi(FPS_Counter);

        QMetaObject::connectSlotsByName(FPS_Counter);
    } // setupUi

    void retranslateUi(QWidget *FPS_Counter)
    {
        FPS_Counter->setWindowTitle(QCoreApplication::translate("FPS_Counter", "Form", nullptr));
        FPSLabel->setText(QCoreApplication::translate("FPS_Counter", "00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FPS_Counter: public Ui_FPS_Counter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPS_COUNTER_H
