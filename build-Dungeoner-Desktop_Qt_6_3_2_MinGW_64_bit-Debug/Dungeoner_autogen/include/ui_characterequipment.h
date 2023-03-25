/********************************************************************************
** Form generated from reading UI file 'characterequipment.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTEREQUIPMENT_H
#define UI_CHARACTEREQUIPMENT_H

#include <CustomWidgets/InventoryCell/inventorycell.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterEquipment
{
public:
    QFrame *EquipmentWrapper;
    QLabel *CharacterDoll;
    QStackedWidget *CellsStackedWidget;
    QWidget *UnderArmor;
    InventoryCell *BalaclavaHelmet;
    InventoryCell *Clothes;
    InventoryCell *Pants;
    InventoryCell *LeftGlove;
    InventoryCell *RightGlove;
    InventoryCell *Necklace;
    QWidget *Armor;
    InventoryCell *Helmet;
    InventoryCell *Gorget;
    InventoryCell *RightPauldron;
    InventoryCell *LeftPauldron;
    InventoryCell *Breastplate;
    InventoryCell *RightBrace;
    InventoryCell *LeftBrace;
    InventoryCell *RightGauntlet;
    InventoryCell *LeftGauntlet;
    InventoryCell *RightGreave;
    InventoryCell *LeftGreave;
    InventoryCell *RightBoot;
    InventoryCell *LeftBoot;
    QWidget *OverArmor;
    InventoryCell *Cap;
    InventoryCell *Mantle;
    InventoryCell *Cloak;
    QLabel *PistolLabel;
    QLabel *CrossbowBoltsLabel;
    QLabel *ArrowsLabel;
    QLabel *BagLabel;
    InventoryCell *Gunpowder;
    InventoryCell *Bullets;
    InventoryCell *Arrows;
    InventoryCell *Bolts;
    InventoryCell *Bag;
    InventoryCell *RightDecoration;
    InventoryCell *LeftDecoration;
    InventoryCell *RightHand;
    InventoryCell *LeftHand;
    QPushButton *OverArmorButton;
    QPushButton *ArmorButton;
    QPushButton *UnderArmorButton;
    QPushButton *WeaponGripButton;

    void setupUi(QWidget *CharacterEquipment)
    {
        if (CharacterEquipment->objectName().isEmpty())
            CharacterEquipment->setObjectName(QString::fromUtf8("CharacterEquipment"));
        CharacterEquipment->resize(714, 472);
        EquipmentWrapper = new QFrame(CharacterEquipment);
        EquipmentWrapper->setObjectName(QString::fromUtf8("EquipmentWrapper"));
        EquipmentWrapper->setGeometry(QRect(89, 0, 440, 472));
        EquipmentWrapper->setFrameShape(QFrame::StyledPanel);
        EquipmentWrapper->setFrameShadow(QFrame::Raised);
        CharacterDoll = new QLabel(EquipmentWrapper);
        CharacterDoll->setObjectName(QString::fromUtf8("CharacterDoll"));
        CharacterDoll->setGeometry(QRect(162, 3, 240, 454));
        CharacterDoll->setStyleSheet(QString::fromUtf8("background-image: url(:/Character-Equipment/Textures PNG/Character-Equipment.png);"));
        CellsStackedWidget = new QStackedWidget(EquipmentWrapper);
        CellsStackedWidget->setObjectName(QString::fromUtf8("CellsStackedWidget"));
        CellsStackedWidget->setGeometry(QRect(77, 0, 354, 472));
        CellsStackedWidget->setStyleSheet(QString::fromUtf8("background: transparent;"));
        UnderArmor = new QWidget();
        UnderArmor->setObjectName(QString::fromUtf8("UnderArmor"));
        BalaclavaHelmet = new InventoryCell(UnderArmor);
        BalaclavaHelmet->setObjectName(QString::fromUtf8("BalaclavaHelmet"));
        BalaclavaHelmet->setGeometry(QRect(144, 0, 68, 68));
        BalaclavaHelmet->setMouseTracking(true);
        BalaclavaHelmet->setAcceptDrops(true);
        Clothes = new InventoryCell(UnderArmor);
        Clothes->setObjectName(QString::fromUtf8("Clothes"));
        Clothes->setGeometry(QRect(144, 156, 68, 68));
        Clothes->setMouseTracking(true);
        Clothes->setAcceptDrops(true);
        Pants = new InventoryCell(UnderArmor);
        Pants->setObjectName(QString::fromUtf8("Pants"));
        Pants->setGeometry(QRect(144, 233, 68, 68));
        Pants->setMouseTracking(true);
        Pants->setAcceptDrops(true);
        LeftGlove = new InventoryCell(UnderArmor);
        LeftGlove->setObjectName(QString::fromUtf8("LeftGlove"));
        LeftGlove->setGeometry(QRect(216, 225, 68, 68));
        LeftGlove->setMouseTracking(true);
        LeftGlove->setAcceptDrops(true);
        RightGlove = new InventoryCell(UnderArmor);
        RightGlove->setObjectName(QString::fromUtf8("RightGlove"));
        RightGlove->setGeometry(QRect(72, 225, 68, 68));
        RightGlove->setMouseTracking(true);
        RightGlove->setAcceptDrops(true);
        Necklace = new InventoryCell(UnderArmor);
        Necklace->setObjectName(QString::fromUtf8("Necklace"));
        Necklace->setGeometry(QRect(144, 69, 68, 84));
        Necklace->setMouseTracking(true);
        Necklace->setAcceptDrops(true);
        CellsStackedWidget->addWidget(UnderArmor);
        Armor = new QWidget();
        Armor->setObjectName(QString::fromUtf8("Armor"));
        Helmet = new InventoryCell(Armor);
        Helmet->setObjectName(QString::fromUtf8("Helmet"));
        Helmet->setGeometry(QRect(144, 0, 68, 68));
        Helmet->setMouseTracking(true);
        Helmet->setAcceptDrops(true);
        Gorget = new InventoryCell(Armor);
        Gorget->setObjectName(QString::fromUtf8("Gorget"));
        Gorget->setGeometry(QRect(144, 69, 68, 68));
        Gorget->setMouseTracking(true);
        Gorget->setAcceptDrops(true);
        RightPauldron = new InventoryCell(Armor);
        RightPauldron->setObjectName(QString::fromUtf8("RightPauldron"));
        RightPauldron->setGeometry(QRect(75, 73, 68, 68));
        RightPauldron->setMouseTracking(true);
        RightPauldron->setAcceptDrops(true);
        LeftPauldron = new InventoryCell(Armor);
        LeftPauldron->setObjectName(QString::fromUtf8("LeftPauldron"));
        LeftPauldron->setGeometry(QRect(212, 73, 68, 68));
        LeftPauldron->setMouseTracking(true);
        LeftPauldron->setAcceptDrops(true);
        Breastplate = new InventoryCell(Armor);
        Breastplate->setObjectName(QString::fromUtf8("Breastplate"));
        Breastplate->setGeometry(QRect(144, 151, 68, 68));
        Breastplate->setMouseTracking(true);
        Breastplate->setAcceptDrops(true);
        RightBrace = new InventoryCell(Armor);
        RightBrace->setObjectName(QString::fromUtf8("RightBrace"));
        RightBrace->setGeometry(QRect(72, 157, 68, 68));
        RightBrace->setMouseTracking(true);
        RightBrace->setAcceptDrops(true);
        LeftBrace = new InventoryCell(Armor);
        LeftBrace->setObjectName(QString::fromUtf8("LeftBrace"));
        LeftBrace->setGeometry(QRect(216, 157, 68, 68));
        LeftBrace->setMouseTracking(true);
        LeftBrace->setAcceptDrops(true);
        RightGauntlet = new InventoryCell(Armor);
        RightGauntlet->setObjectName(QString::fromUtf8("RightGauntlet"));
        RightGauntlet->setGeometry(QRect(72, 225, 68, 68));
        RightGauntlet->setMouseTracking(true);
        RightGauntlet->setAcceptDrops(true);
        LeftGauntlet = new InventoryCell(Armor);
        LeftGauntlet->setObjectName(QString::fromUtf8("LeftGauntlet"));
        LeftGauntlet->setGeometry(QRect(216, 225, 68, 68));
        LeftGauntlet->setMouseTracking(true);
        LeftGauntlet->setAcceptDrops(true);
        RightGreave = new InventoryCell(Armor);
        RightGreave->setObjectName(QString::fromUtf8("RightGreave"));
        RightGreave->setGeometry(QRect(113, 295, 68, 68));
        RightGreave->setMouseTracking(true);
        RightGreave->setAcceptDrops(true);
        LeftGreave = new InventoryCell(Armor);
        LeftGreave->setObjectName(QString::fromUtf8("LeftGreave"));
        LeftGreave->setGeometry(QRect(181, 295, 68, 68));
        LeftGreave->setMouseTracking(true);
        LeftGreave->setAcceptDrops(true);
        RightBoot = new InventoryCell(Armor);
        RightBoot->setObjectName(QString::fromUtf8("RightBoot"));
        RightBoot->setGeometry(QRect(113, 396, 68, 68));
        RightBoot->setMouseTracking(true);
        RightBoot->setAcceptDrops(true);
        LeftBoot = new InventoryCell(Armor);
        LeftBoot->setObjectName(QString::fromUtf8("LeftBoot"));
        LeftBoot->setGeometry(QRect(181, 396, 68, 68));
        LeftBoot->setMouseTracking(true);
        LeftBoot->setAcceptDrops(true);
        CellsStackedWidget->addWidget(Armor);
        OverArmor = new QWidget();
        OverArmor->setObjectName(QString::fromUtf8("OverArmor"));
        OverArmor->setEnabled(true);
        OverArmor->setStyleSheet(QString::fromUtf8(""));
        Cap = new InventoryCell(OverArmor);
        Cap->setObjectName(QString::fromUtf8("Cap"));
        Cap->setGeometry(QRect(144, 0, 68, 68));
        Cap->setMouseTracking(true);
        Cap->setAcceptDrops(true);
        Mantle = new InventoryCell(OverArmor);
        Mantle->setObjectName(QString::fromUtf8("Mantle"));
        Mantle->setGeometry(QRect(144, 151, 68, 68));
        Mantle->setMouseTracking(true);
        Mantle->setAcceptDrops(true);
        Cloak = new InventoryCell(OverArmor);
        Cloak->setObjectName(QString::fromUtf8("Cloak"));
        Cloak->setGeometry(QRect(267, 314, 68, 68));
        Cloak->setMouseTracking(true);
        Cloak->setAcceptDrops(true);
        CellsStackedWidget->addWidget(OverArmor);
        PistolLabel = new QLabel(EquipmentWrapper);
        PistolLabel->setObjectName(QString::fromUtf8("PistolLabel"));
        PistolLabel->setGeometry(QRect(26, 322, 69, 123));
        PistolLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/Character-Equipment/Textures PNG/Equipment-Pistol.png);"));
        CrossbowBoltsLabel = new QLabel(EquipmentWrapper);
        CrossbowBoltsLabel->setObjectName(QString::fromUtf8("CrossbowBoltsLabel"));
        CrossbowBoltsLabel->setGeometry(QRect(72, 395, 73, 77));
        CrossbowBoltsLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/Character-Equipment/Textures PNG/Equipment-Crossbow-Bolts.png);"));
        ArrowsLabel = new QLabel(EquipmentWrapper);
        ArrowsLabel->setObjectName(QString::fromUtf8("ArrowsLabel"));
        ArrowsLabel->setGeometry(QRect(107, 321, 72, 77));
        ArrowsLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/Character-Equipment/Textures PNG/Equipment-Arrow.png);"));
        BagLabel = new QLabel(EquipmentWrapper);
        BagLabel->setObjectName(QString::fromUtf8("BagLabel"));
        BagLabel->setGeometry(QRect(355, 21, 84, 82));
        BagLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/Character-Equipment/Textures PNG/Equipment-Bag.png);"));
        Gunpowder = new InventoryCell(EquipmentWrapper);
        Gunpowder->setObjectName(QString::fromUtf8("Gunpowder"));
        Gunpowder->setGeometry(QRect(0, 385, 68, 68));
        Gunpowder->setMouseTracking(true);
        Gunpowder->setAcceptDrops(true);
        Bullets = new InventoryCell(EquipmentWrapper);
        Bullets->setObjectName(QString::fromUtf8("Bullets"));
        Bullets->setGeometry(QRect(39, 313, 68, 68));
        Bullets->setMouseTracking(true);
        Bullets->setAcceptDrops(true);
        Arrows = new InventoryCell(EquipmentWrapper);
        Arrows->setObjectName(QString::fromUtf8("Arrows"));
        Arrows->setGeometry(QRect(118, 313, 68, 68));
        Arrows->setMouseTracking(true);
        Arrows->setAcceptDrops(true);
        Bolts = new InventoryCell(EquipmentWrapper);
        Bolts->setObjectName(QString::fromUtf8("Bolts"));
        Bolts->setGeometry(QRect(79, 385, 68, 68));
        Bolts->setMouseTracking(true);
        Bolts->setAcceptDrops(true);
        Bag = new InventoryCell(EquipmentWrapper);
        Bag->setObjectName(QString::fromUtf8("Bag"));
        Bag->setGeometry(QRect(369, 43, 68, 84));
        Bag->setMouseTracking(true);
        Bag->setAcceptDrops(true);
        RightDecoration = new InventoryCell(EquipmentWrapper);
        RightDecoration->setObjectName(QString::fromUtf8("RightDecoration"));
        RightDecoration->setGeometry(QRect(79, 148, 68, 84));
        RightDecoration->setMouseTracking(true);
        RightDecoration->setAcceptDrops(true);
        LeftDecoration = new InventoryCell(EquipmentWrapper);
        LeftDecoration->setObjectName(QString::fromUtf8("LeftDecoration"));
        LeftDecoration->setGeometry(QRect(365, 148, 68, 84));
        LeftDecoration->setMouseTracking(true);
        LeftDecoration->setAcceptDrops(true);
        RightHand = new InventoryCell(EquipmentWrapper);
        RightHand->setObjectName(QString::fromUtf8("RightHand"));
        RightHand->setGeometry(QRect(79, 231, 68, 68));
        RightHand->setMouseTracking(true);
        RightHand->setAcceptDrops(true);
        LeftHand = new InventoryCell(EquipmentWrapper);
        LeftHand->setObjectName(QString::fromUtf8("LeftHand"));
        LeftHand->setGeometry(QRect(365, 231, 68, 68));
        LeftHand->setMouseTracking(true);
        LeftHand->setAcceptDrops(true);
        BagLabel->raise();
        ArrowsLabel->raise();
        CrossbowBoltsLabel->raise();
        PistolLabel->raise();
        CharacterDoll->raise();
        CellsStackedWidget->raise();
        Gunpowder->raise();
        Bullets->raise();
        Arrows->raise();
        Bolts->raise();
        Bag->raise();
        RightDecoration->raise();
        LeftDecoration->raise();
        RightHand->raise();
        LeftHand->raise();
        OverArmorButton = new QPushButton(CharacterEquipment);
        OverArmorButton->setObjectName(QString::fromUtf8("OverArmorButton"));
        OverArmorButton->setGeometry(QRect(10, 80, 80, 24));
        ArmorButton = new QPushButton(CharacterEquipment);
        ArmorButton->setObjectName(QString::fromUtf8("ArmorButton"));
        ArmorButton->setGeometry(QRect(10, 120, 80, 24));
        UnderArmorButton = new QPushButton(CharacterEquipment);
        UnderArmorButton->setObjectName(QString::fromUtf8("UnderArmorButton"));
        UnderArmorButton->setGeometry(QRect(10, 160, 80, 24));
        WeaponGripButton = new QPushButton(CharacterEquipment);
        WeaponGripButton->setObjectName(QString::fromUtf8("WeaponGripButton"));
        WeaponGripButton->setGeometry(QRect(95, 227, 65, 77));
        WeaponGripButton->setCursor(QCursor(Qt::PointingHandCursor));
        WeaponGripButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: none;\n"
"	background:url(:/Character-Equipment/Textures PNG/One-Handed-Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border: none;\n"
"	background:url(:/Character-Equipment/Textures PNG/One-Handed-Button-Hovered.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border: none;\n"
"	background:url(:/Character-Equipment/Textures PNG/One-Handed-Button-Pressed.png);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	border: none;\n"
"	background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button.png);\n"
"}\n"
"\n"
"QPushButton:checked:hover{\n"
"	border: none;\n"
"	background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button-Hovered.png);\n"
"}\n"
"\n"
"QPushButton:checked:pressed{\n"
"	border: none;\n"
"	background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button-Pressed.png);\n"
"}"));
        WeaponGripButton->setCheckable(true);
        WeaponGripButton->setChecked(false);

        retranslateUi(CharacterEquipment);

        CellsStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CharacterEquipment);
    } // setupUi

    void retranslateUi(QWidget *CharacterEquipment)
    {
        CharacterEquipment->setWindowTitle(QCoreApplication::translate("CharacterEquipment", "Form", nullptr));
        CharacterDoll->setText(QString());
        PistolLabel->setText(QString());
        CrossbowBoltsLabel->setText(QString());
        ArrowsLabel->setText(QString());
        BagLabel->setText(QString());
        OverArmorButton->setText(QCoreApplication::translate("CharacterEquipment", "\320\235\320\260\320\264 \320\264\320\276\321\201\320\277\320\265\321\205\320\276\320\274", nullptr));
        ArmorButton->setText(QCoreApplication::translate("CharacterEquipment", "\320\224\320\276\321\201\320\277\320\265\321\205", nullptr));
        UnderArmorButton->setText(QCoreApplication::translate("CharacterEquipment", "\320\237\320\276\320\264 \320\264\320\276\321\201\320\277\320\265\321\205\320\276\320\274", nullptr));
        WeaponGripButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CharacterEquipment: public Ui_CharacterEquipment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTEREQUIPMENT_H
