#include "inventoryitem.h"
#include "ui_inventoryitem.h"

InventoryItem::InventoryItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryItem)
{
    ui->setupUi(this);

    ui->DropdownButton->setVisible(false);
//    inventoryItemNew.setFileName(":/Inventory/GIF/InventoryItemNew.gif");
//    inventoryItemNew.setScaledSize(QSize(68,68));
//    inventoryItemNew.setSpeed(0);
//    ui->inventoryItemNew->setMovie(&inventoryItemNotEmpty);
//    inventoryItemNew.start();
}

InventoryItem::~InventoryItem()
{
    delete ui;
}

InventoryItem::InventoryItem(bool hasDropdownList, bool hasCentralElement)
{
    if(!hasDropdownList)
        ui->DropdownButton->setVisible(false);

    if(!hasCentralElement)
        ui->CentralElement->setVisible(false);
}

void InventoryItem::setEmptyStyle()
{

}

void InventoryItem::setNoEmptyStyle()
{

}

void InventoryItem::setNewStyle()
{

}
