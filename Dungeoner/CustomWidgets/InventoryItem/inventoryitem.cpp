#include "II_stylemaster.h"

#include "inventoryitem.h"
#include "qpainter.h"
#include "ui_inventoryitem.h"

InventoryItem::InventoryItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryItem)
{
    ui->setupUi(this);
}

InventoryItem::~InventoryItem()
{
    delete ui;
}

void InventoryItem::setEmptyStyle()
{
    ui->inventoryItemNew->setVisible(false);
    inventoryItemNew.stop();
    ui->inventoryItemBG->setStyleSheet("");
    ui->Locked->setStyleSheet("");
    ui->inventoryItemBorder->setStyleSheet(II_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(II_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(II_stylemaster::centralElementStyle());
    ui->DropdownButton->move(3, 56);
}

void InventoryItem::setNoEmptyStyle()
{
    ui->inventoryItemNew->setVisible(false);
    inventoryItemNew.stop();
    ui->Locked->setStyleSheet("");
    ui->CentralElement->setStyleSheet("");
    ui->inventoryItemBorder->setStyleSheet(II_stylemaster::notEmptyBorderStyle());
    ui->inventoryItemBG->setStyleSheet(II_stylemaster::notEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(II_stylemaster::dropdownButtonNotEmptyStyle());
    ui->DropdownButton->move(3, 57);
}

void InventoryItem::setNewStyle()
{
    inventoryItemNew.stop();
    ui->Locked->setStyleSheet("");
    ui->CentralElement->setStyleSheet("");
    ui->inventoryItemNew->setVisible(true);
    inventoryItemNew.setFileName(":/Inventory/GIF/InventoryItemNew.gif");
    inventoryItemNew.setScaledSize(QSize(68,68));
    ui->inventoryItemNew->setMovie(&inventoryItemNew);
    inventoryItemNew.start();
}

void InventoryItem::setLockedNewStyle()
{
    inventoryItemNew.stop();
    ui->Locked->setStyleSheet("");
    ui->CentralElement->setStyleSheet("");
    ui->inventoryItemNew->setVisible(true);
    inventoryItemNew.setFileName(":/Inventory/GIF/DisabledInventoryItemNew.gif");
    inventoryItemNew.setScaledSize(QSize(68,68));
    ui->inventoryItemNew->setMovie(&inventoryItemNew);
    inventoryItemNew.start();
}

void InventoryItem::setCentralElementStyle(bool isVisible)
{
    ui->CentralElement->setVisible(isVisible);
}

void InventoryItem::setDropdownButtonVisible(bool isVisible)
{
    ui->DropdownButton->setVisible(isVisible);
}

void InventoryItem::setLockedStyle()
{
    ui->inventoryItemNew->setVisible(false);
    inventoryItemNew.stop();
    ui->inventoryItemBG->setStyleSheet("");
    ui->inventoryItemBorder->setStyleSheet(II_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(II_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(II_stylemaster::centralElementStyle());
    ui->DropdownButton->move(3, 56);
    ui->Locked->setStyleSheet(II_stylemaster::lockedStyle());
}

void InventoryItem::setDisabledStyle()
{
    ui->inventoryItemNew->setVisible(false);
    inventoryItemNew.stop();
    ui->Locked->setStyleSheet("");
    ui->inventoryItemBorder->setStyleSheet(II_stylemaster::disabledNotEmptyBorderStyle());
    ui->inventoryItemBG->setStyleSheet(II_stylemaster::disabledNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(II_stylemaster::dropdownButtonDisabledNotEmptyStyle());
    ui->CentralElement->setStyleSheet(II_stylemaster::centralElementStyle());
    ui->DropdownButton->move(3, 57);
}
