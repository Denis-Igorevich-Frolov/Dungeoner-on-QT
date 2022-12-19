#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

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

private:
    Ui::InventoryItem *ui;
};

#endif // INVENTORYITEM_H
