/***********************************************************************************************************
 *Данный класс является наследником QMimeData, который позволяет использовать Drag&Drop итемов. Так как
 *любое перемещение итема не просто копирует его, а свапает местами с итемом из конечной ячейки, в этом
 *классе также хранится указатель на ячейку инвентаря из которо начался Drag&Drop для последующей замены.
 *
 *Формат итема - "Item"
 ***********************************************************************************************************/

#ifndef ITEMMIMEDATA_H
#define ITEMMIMEDATA_H

#include "CustomWidgets/InventoryCell/inventorycell.h"
#include "item.h"
#include "qmimedata.h"

class ItemMimeData: public QMimeData
{
    Q_OBJECT
public:
    ItemMimeData(Item *item, InventoryCell* itemCell);

    const Item *getItem() const;

    QStringList getMyFormats() const;

    QStringList formats() const override;

    const InventoryCell *getItemCell() const;

protected:
    QVariant retrieveData(Item *item) const;

private:
    const Item* item;
    /*Указатель на стартовую ячейку из которой начался перенос. Когда итем будет перенесён в целевую
     *ячейку, старый итем из неё будет перенесён в стартовую. Таким образом они поменяются местами*/
    const InventoryCell* itemCell;
    QStringList myFormats;
};

#endif // ITEMMIMEDATA_H
