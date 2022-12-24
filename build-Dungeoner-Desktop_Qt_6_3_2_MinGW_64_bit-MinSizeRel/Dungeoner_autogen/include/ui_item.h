/********************************************************************************
** Form generated from reading UI file 'item.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEM_H
#define UI_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Item
{
public:
    QLabel *Image;
    QLabel *Quantity;

    void setupUi(QWidget *Item)
    {
        if (Item->objectName().isEmpty())
            Item->setObjectName(QString::fromUtf8("Item"));
        Item->resize(68, 68);
        Image = new QLabel(Item);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(0, 0, 68, 68));
        Quantity = new QLabel(Item);
        Quantity->setObjectName(QString::fromUtf8("Quantity"));
        Quantity->setGeometry(QRect(6, 46, 56, 20));
        Quantity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Item);

        QMetaObject::connectSlotsByName(Item);
    } // setupUi

    void retranslateUi(QWidget *Item)
    {
        Item->setWindowTitle(QCoreApplication::translate("Item", "Form", nullptr));
        Image->setText(QString());
        Quantity->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Item: public Ui_Item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEM_H
