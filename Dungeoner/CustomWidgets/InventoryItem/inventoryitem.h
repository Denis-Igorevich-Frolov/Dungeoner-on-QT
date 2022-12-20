#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "qmovie.h"
#include <QWidget>

namespace Ui {
class InventoryItem;
}

class InventoryItem : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryItem(QWidget *parent = nullptr);
    ~InventoryItem();

    InventoryItem(bool hasDropdownList, bool hasCentralElement);

    void setEmptyStyle();
    void setNoEmptyStyle();
    void setNewStyle();

private:
    Ui::InventoryItem *ui;

    QMovie inventoryItemNew;
};

#endif // INVENTORYITEM_H
