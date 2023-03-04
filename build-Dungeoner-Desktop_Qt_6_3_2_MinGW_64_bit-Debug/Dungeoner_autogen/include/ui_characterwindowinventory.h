/********************************************************************************
** Form generated from reading UI file 'characterwindowinventory.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERWINDOWINVENTORY_H
#define UI_CHARACTERWINDOWINVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterWindowInventory
{
public:
    QFrame *InventoryWrapper;
    QScrollArea *InventoryScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *Inventory;
    QScrollBar *InventoryScrollBar;

    void setupUi(QWidget *CharacterWindowInventory)
    {
        if (CharacterWindowInventory->objectName().isEmpty())
            CharacterWindowInventory->setObjectName(QString::fromUtf8("CharacterWindowInventory"));
        CharacterWindowInventory->resize(785, 349);
        CharacterWindowInventory->setMouseTracking(true);
        CharacterWindowInventory->setAcceptDrops(true);
        InventoryWrapper = new QFrame(CharacterWindowInventory);
        InventoryWrapper->setObjectName(QString::fromUtf8("InventoryWrapper"));
        InventoryWrapper->setGeometry(QRect(0, 0, 785, 349));
        InventoryWrapper->setFrameShape(QFrame::StyledPanel);
        InventoryWrapper->setFrameShadow(QFrame::Raised);
        InventoryScrollArea = new QScrollArea(InventoryWrapper);
        InventoryScrollArea->setObjectName(QString::fromUtf8("InventoryScrollArea"));
        InventoryScrollArea->setGeometry(QRect(0, 45, 734, 308));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InventoryScrollArea->sizePolicy().hasHeightForWidth());
        InventoryScrollArea->setSizePolicy(sizePolicy);
        InventoryScrollArea->setMouseTracking(true);
        InventoryScrollArea->setAcceptDrops(true);
        InventoryScrollArea->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        InventoryScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        InventoryScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        InventoryScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 734, 304));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 304));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        Inventory = new QGridLayout();
        Inventory->setSpacing(6);
        Inventory->setObjectName(QString::fromUtf8("Inventory"));
        Inventory->setSizeConstraint(QLayout::SetFixedSize);
        Inventory->setContentsMargins(0, 5, 0, 9);

        verticalLayout_8->addLayout(Inventory);

        InventoryScrollArea->setWidget(scrollAreaWidgetContents);
        InventoryScrollBar = new QScrollBar(InventoryWrapper);
        InventoryScrollBar->setObjectName(QString::fromUtf8("InventoryScrollBar"));
        InventoryScrollBar->setGeometry(QRect(751, 83, 24, 246));
        InventoryScrollBar->setCursor(QCursor(Qt::PointingHandCursor));
        InventoryScrollBar->setMaximum(0);
        InventoryScrollBar->setSingleStep(74);
        InventoryScrollBar->setPageStep(18);
        InventoryScrollBar->setOrientation(Qt::Vertical);

        retranslateUi(CharacterWindowInventory);

        QMetaObject::connectSlotsByName(CharacterWindowInventory);
    } // setupUi

    void retranslateUi(QWidget *CharacterWindowInventory)
    {
        CharacterWindowInventory->setWindowTitle(QCoreApplication::translate("CharacterWindowInventory", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharacterWindowInventory: public Ui_CharacterWindowInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOWINVENTORY_H
