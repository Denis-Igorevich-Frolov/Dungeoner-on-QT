#include "inventoryitem.h"
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
