#include "itemmimedata.h"

ItemMimeData::ItemMimeData(Item *item, InventoryCell* itemCell)
{
    this->item = item;
    this->itemCell = itemCell;
    myFormats << "Item";
}

const Item *ItemMimeData::getItem() const
{
    return item;
}

QStringList ItemMimeData::getMyFormats() const
{
    return myFormats;
}

QStringList ItemMimeData::formats() const
{
    return myFormats;
}

const InventoryCell *ItemMimeData::getItemCell() const
{
    return itemCell;
}
