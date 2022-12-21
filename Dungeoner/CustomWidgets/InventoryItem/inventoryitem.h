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

    void setEmptyStyle();
    void setNoEmptyStyle();
    void setNewStyle();
    void setLockedNewStyle();
    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);
    void setLockedStyle();
    void setDisabledStyle();

private:
    Ui::InventoryItem *ui;

    QMovie inventoryItemNew;
};

#endif // INVENTORYITEM_H
