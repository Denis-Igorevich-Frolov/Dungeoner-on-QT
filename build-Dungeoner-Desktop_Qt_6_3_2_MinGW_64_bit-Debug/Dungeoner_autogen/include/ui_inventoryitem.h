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
    QLabel *inventoryItemBorder;
    QLabel *CentralElement;
    QLabel *inventoryItemNew;
    QPushButton *DropdownButton;
    QLabel *inventoryItemBG;
    QLabel *Locked;

    void setupUi(QWidget *InventoryItem)
    {
        if (InventoryItem->objectName().isEmpty())
            InventoryItem->setObjectName(QString::fromUtf8("InventoryItem"));
        InventoryItem->resize(68, 84);
        inventoryItemBorder = new QLabel(InventoryItem);
        inventoryItemBorder->setObjectName(QString::fromUtf8("inventoryItemBorder"));
        inventoryItemBorder->setGeometry(QRect(0, 0, 68, 68));
        inventoryItemBorder->setStyleSheet(QString::fromUtf8(""));
        CentralElement = new QLabel(InventoryItem);
        CentralElement->setObjectName(QString::fromUtf8("CentralElement"));
        CentralElement->setGeometry(QRect(0, 0, 68, 68));
        CentralElement->setStyleSheet(QString::fromUtf8(""));
        inventoryItemNew = new QLabel(InventoryItem);
        inventoryItemNew->setObjectName(QString::fromUtf8("inventoryItemNew"));
        inventoryItemNew->setGeometry(QRect(0, 0, 68, 68));
        inventoryItemNew->setStyleSheet(QString::fromUtf8(""));
        DropdownButton = new QPushButton(InventoryItem);
        DropdownButton->setObjectName(QString::fromUtf8("DropdownButton"));
        DropdownButton->setGeometry(QRect(4, 56, 60, 27));
        DropdownButton->setCursor(QCursor(Qt::PointingHandCursor));
        DropdownButton->setStyleSheet(QString::fromUtf8(""));
        inventoryItemBG = new QLabel(InventoryItem);
        inventoryItemBG->setObjectName(QString::fromUtf8("inventoryItemBG"));
        inventoryItemBG->setGeometry(QRect(3, 3, 62, 62));
        inventoryItemBG->setStyleSheet(QString::fromUtf8(""));
        Locked = new QLabel(InventoryItem);
        Locked->setObjectName(QString::fromUtf8("Locked"));
        Locked->setGeometry(QRect(5, 5, 58, 58));
        Locked->setStyleSheet(QString::fromUtf8(""));
        CentralElement->raise();
        inventoryItemBG->raise();
        inventoryItemBorder->raise();
        Locked->raise();
        inventoryItemNew->raise();
        DropdownButton->raise();

        retranslateUi(InventoryItem);

        QMetaObject::connectSlotsByName(InventoryItem);
    } // setupUi

    void retranslateUi(QWidget *InventoryItem)
    {
        InventoryItem->setWindowTitle(QCoreApplication::translate("InventoryItem", "Form", nullptr));
        inventoryItemBorder->setText(QString());
        CentralElement->setText(QString());
        inventoryItemNew->setText(QString());
        DropdownButton->setText(QString());
        inventoryItemBG->setText(QString());
        Locked->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InventoryItem: public Ui_InventoryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYITEM_H
