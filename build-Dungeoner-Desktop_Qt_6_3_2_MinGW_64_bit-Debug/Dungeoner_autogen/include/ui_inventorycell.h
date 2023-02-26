/********************************************************************************
** Form generated from reading UI file 'inventorycell.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYCELL_H
#define UI_INVENTORYCELL_H

#include <CustomWidgets/Item/item.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryCell
{
public:
    QLabel *inventoryCellBorder;
    QLabel *CentralElement;
    QLabel *inventoryCellNew;
    QPushButton *DropdownButton;
    QLabel *inventoryCellBG;
    QLabel *Locked;
    QLabel *Blocked;
    Item *item;

    void setupUi(QWidget *InventoryCell)
    {
        if (InventoryCell->objectName().isEmpty())
            InventoryCell->setObjectName(QString::fromUtf8("InventoryCell"));
        InventoryCell->resize(68, 84);
        InventoryCell->setMouseTracking(true);
        inventoryCellBorder = new QLabel(InventoryCell);
        inventoryCellBorder->setObjectName(QString::fromUtf8("inventoryCellBorder"));
        inventoryCellBorder->setGeometry(QRect(0, 0, 68, 68));
        inventoryCellBorder->setStyleSheet(QString::fromUtf8(""));
        CentralElement = new QLabel(InventoryCell);
        CentralElement->setObjectName(QString::fromUtf8("CentralElement"));
        CentralElement->setGeometry(QRect(0, 0, 68, 68));
        CentralElement->setStyleSheet(QString::fromUtf8(""));
        inventoryCellNew = new QLabel(InventoryCell);
        inventoryCellNew->setObjectName(QString::fromUtf8("inventoryCellNew"));
        inventoryCellNew->setGeometry(QRect(0, 0, 68, 68));
        inventoryCellNew->setStyleSheet(QString::fromUtf8(""));
        DropdownButton = new QPushButton(InventoryCell);
        DropdownButton->setObjectName(QString::fromUtf8("DropdownButton"));
        DropdownButton->setGeometry(QRect(4, 56, 60, 27));
        DropdownButton->setCursor(QCursor(Qt::PointingHandCursor));
        DropdownButton->setStyleSheet(QString::fromUtf8(""));
        inventoryCellBG = new QLabel(InventoryCell);
        inventoryCellBG->setObjectName(QString::fromUtf8("inventoryCellBG"));
        inventoryCellBG->setGeometry(QRect(3, 3, 62, 62));
        inventoryCellBG->setStyleSheet(QString::fromUtf8(""));
        Locked = new QLabel(InventoryCell);
        Locked->setObjectName(QString::fromUtf8("Locked"));
        Locked->setGeometry(QRect(5, 5, 58, 58));
        Locked->setStyleSheet(QString::fromUtf8(""));
        Blocked = new QLabel(InventoryCell);
        Blocked->setObjectName(QString::fromUtf8("Blocked"));
        Blocked->setGeometry(QRect(1, 1, 66, 66));
        Blocked->setStyleSheet(QString::fromUtf8(""));
        item = new Item(InventoryCell);
        item->setObjectName(QString::fromUtf8("item"));
        item->setGeometry(QRect(0, 0, 68, 68));
        item->setMouseTracking(true);
        item->setFocusPolicy(Qt::StrongFocus);
        CentralElement->raise();
        inventoryCellBG->raise();
        inventoryCellBorder->raise();
        Locked->raise();
        inventoryCellNew->raise();
        DropdownButton->raise();
        Blocked->raise();
        item->raise();

        retranslateUi(InventoryCell);

        QMetaObject::connectSlotsByName(InventoryCell);
    } // setupUi

    void retranslateUi(QWidget *InventoryCell)
    {
        InventoryCell->setWindowTitle(QCoreApplication::translate("InventoryCell", "Form", nullptr));
        inventoryCellBorder->setText(QString());
        CentralElement->setText(QString());
        inventoryCellNew->setText(QString());
        DropdownButton->setText(QString());
        inventoryCellBG->setText(QString());
        Locked->setText(QString());
        Blocked->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InventoryCell: public Ui_InventoryCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYCELL_H
