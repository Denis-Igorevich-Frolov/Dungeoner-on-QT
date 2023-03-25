/********************************************************************************
** Form generated from reading UI file 'weapongripbutton.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEAPONGRIPBUTTON_H
#define UI_WEAPONGRIPBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeaponGripButton
{
public:
    QPushButton *GripButton;

    void setupUi(QWidget *WeaponGripButton)
    {
        if (WeaponGripButton->objectName().isEmpty())
            WeaponGripButton->setObjectName(QString::fromUtf8("WeaponGripButton"));
        WeaponGripButton->resize(65, 77);
        GripButton = new QPushButton(WeaponGripButton);
        GripButton->setObjectName(QString::fromUtf8("GripButton"));
        GripButton->setGeometry(QRect(0, 0, 65, 77));
        GripButton->setCursor(QCursor(Qt::PointingHandCursor));
        GripButton->setStyleSheet(QString::fromUtf8(""));
        GripButton->setCheckable(true);
        GripButton->setChecked(false);

        retranslateUi(WeaponGripButton);

        QMetaObject::connectSlotsByName(WeaponGripButton);
    } // setupUi

    void retranslateUi(QWidget *WeaponGripButton)
    {
        WeaponGripButton->setWindowTitle(QCoreApplication::translate("WeaponGripButton", "Form", nullptr));
        GripButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeaponGripButton: public Ui_WeaponGripButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEAPONGRIPBUTTON_H
