#include "IC_stylemaster.h"

#include "inventorycell.h"
#include "ui_inventorycell.h"

InventoryCell::InventoryCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryCell)
{
    ui->setupUi(this);
}

InventoryCell::~InventoryCell()
{
    delete ui;
}

void InventoryCell::setEmptyStyle()
{
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    ui->inventoryCellBG->setStyleSheet("");
    ui->Locked->setStyleSheet("");
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(IC_stylemaster::centralElementStyle());
    ui->DropdownButton->move(3, 56);
}

void InventoryCell::setNoEmptyStyle()
{
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    ui->Locked->setStyleSheet("");
    ui->CentralElement->setStyleSheet("");
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::notEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::notEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonNotEmptyStyle());
    ui->DropdownButton->move(3, 57);
}

void InventoryCell::setNewStyle()
{
    inventoryCellNew.stop();
    ui->Locked->setStyleSheet("");
    ui->CentralElement->setStyleSheet("");
    ui->inventoryCellNew->setVisible(true);
    inventoryCellNew.setFileName(":/Inventory/GIF/InventoryItemNew.gif");
    inventoryCellNew.setScaledSize(QSize(68,68));
    ui->inventoryCellNew->setMovie(&inventoryCellNew);
    inventoryCellNew.start();
}

void InventoryCell::setLockedNewStyle()
{
    inventoryCellNew.stop();
    ui->Locked->setStyleSheet("");
    ui->CentralElement->setStyleSheet("");
    ui->inventoryCellNew->setVisible(true);
    inventoryCellNew.setFileName(":/Inventory/GIF/DisabledInventoryItemNew.gif");
    inventoryCellNew.setScaledSize(QSize(68,68));
    ui->inventoryCellNew->setMovie(&inventoryCellNew);
    inventoryCellNew.start();
}

void InventoryCell::setCentralElementStyle(bool isVisible)
{
    ui->CentralElement->setVisible(isVisible);
}

void InventoryCell::setDropdownButtonVisible(bool isVisible)
{
    ui->DropdownButton->setVisible(isVisible);
}

void InventoryCell::setLockedStyle()
{
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    ui->inventoryCellBG->setStyleSheet("");
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(IC_stylemaster::centralElementStyle());
    ui->DropdownButton->move(3, 56);
    ui->Locked->setStyleSheet(IC_stylemaster::lockedStyle());
}

void InventoryCell::setDisabledStyle()
{
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    ui->Locked->setStyleSheet("");
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::disabledNotEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::disabledNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonDisabledNotEmptyStyle());
    ui->CentralElement->setStyleSheet(IC_stylemaster::centralElementStyle());
    ui->DropdownButton->move(3, 57);
}
