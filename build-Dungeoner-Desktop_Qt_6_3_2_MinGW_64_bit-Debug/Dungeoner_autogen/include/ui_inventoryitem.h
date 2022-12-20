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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryItem
{
public:
    QLabel *inventoryItemBG;
    QLabel *CentralElement;
    QLabel *inventoryItemNew;
    QPushButton *DropdownButton;

    void setupUi(QWidget *InventoryItem)
    {
        if (InventoryItem->objectName().isEmpty())
            InventoryItem->setObjectName(QString::fromUtf8("InventoryItem"));
        InventoryItem->resize(68, 83);
        inventoryItemBG = new QLabel(InventoryItem);
        inventoryItemBG->setObjectName(QString::fromUtf8("inventoryItemBG"));
        inventoryItemBG->setGeometry(QRect(0, 0, 68, 68));
        inventoryItemBG->setStyleSheet(QString::fromUtf8("background-image: url(:/Inventory/Textures PNG/Inventory-Item-BG.png);\n"
"background-repeat: no-repiat;\n"
"background-position: center center;"));
        CentralElement = new QLabel(InventoryItem);
        CentralElement->setObjectName(QString::fromUtf8("CentralElement"));
        CentralElement->setGeometry(QRect(0, 0, 68, 68));
        CentralElement->setStyleSheet(QString::fromUtf8("background-image: url(:/Inventory/Textures PNG/Inventory-Item-Central-Element.png);\n"
"background-repeat: no-repiat;\n"
"background-position: center center;"));
        inventoryItemNew = new QLabel(InventoryItem);
        inventoryItemNew->setObjectName(QString::fromUtf8("inventoryItemNew"));
        inventoryItemNew->setGeometry(QRect(0, 0, 68, 68));
        inventoryItemNew->setStyleSheet(QString::fromUtf8(""));
        DropdownButton = new QPushButton(InventoryItem);
        DropdownButton->setObjectName(QString::fromUtf8("DropdownButton"));
        DropdownButton->setGeometry(QRect(4, 56, 59, 27));
        DropdownButton->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"background-image: url(:/Text-Block-2/Textures PNG/DecorativeElement-2-D.png);\n"
"background-repeat: no-repiat;\n"
"background-position: center center;"));

        retranslateUi(InventoryItem);

        QMetaObject::connectSlotsByName(InventoryItem);
    } // setupUi

    void retranslateUi(QWidget *InventoryItem)
    {
        InventoryItem->setWindowTitle(QCoreApplication::translate("InventoryItem", "Form", nullptr));
        inventoryItemBG->setText(QString());
        CentralElement->setText(QString());
        inventoryItemNew->setText(QString());
        DropdownButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InventoryItem: public Ui_InventoryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYITEM_H
