/***********************************************************************************************************
 *Данный класс является наследником QMimeData, который позволяет использовать Drag&Drop итемов. Так как
 *любое перемещение итема не просто копирует его, а свапает местами с итемом из конечной ячейки, в этом
 *классе также хранится указатель на ячейку инвентаря из которо начался Drag&Drop для последующей замены.
 *
 *Формат итема - "Item"
 ***********************************************************************************************************/

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
