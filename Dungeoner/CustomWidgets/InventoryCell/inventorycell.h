#ifndef INVENTORYCELL_H
#define INVENTORYCELL_H

#include "qmovie.h"
#include <QWidget>

namespace Ui {
class InventoryCell;
}

class InventoryCell : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryCell(QWidget *parent = nullptr);
    ~InventoryCell();

    void setEmptyStyle();
    void setNoEmptyStyle();
    void setNewStyle();
    void setLockedNewStyle();
    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);
    void setLockedStyle();
    void setDisabledStyle();

private:
    Ui::InventoryCell *ui;

    QMovie inventoryCellNew;
};

#endif // INVENTORYCELL_H
