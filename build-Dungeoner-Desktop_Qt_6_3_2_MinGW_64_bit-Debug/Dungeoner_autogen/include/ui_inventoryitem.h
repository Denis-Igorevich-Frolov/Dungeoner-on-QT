/********************************************************************************
** Form generated from reading UI file 'inventoryitem.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYITEM_H
#define UI_INVENTORYITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryItem
{
public:
    QLabel *label;

    void setupUi(QWidget *InventoryItem)
    {
        if (InventoryItem->objectName().isEmpty())
            InventoryItem->setObjectName(QString::fromUtf8("InventoryItem"));
        InventoryItem->resize(400, 300);
        label = new QLabel(InventoryItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 100, 91, 81));

        retranslateUi(InventoryItem);

        QMetaObject::connectSlotsByName(InventoryItem);
    } // setupUi

    void retranslateUi(QWidget *InventoryItem)
    {
        InventoryItem->setWindowTitle(QCoreApplication::translate("InventoryItem", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InventoryItem: public Ui_InventoryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYITEM_H
