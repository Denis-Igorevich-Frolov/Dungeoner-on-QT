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
    const InventoryCell* itemCell;
    QStringList myFormats;
};

#endif // ITEMMIMEDATA_H
