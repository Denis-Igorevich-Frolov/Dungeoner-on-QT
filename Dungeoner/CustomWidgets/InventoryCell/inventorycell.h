/********************************************************************************************
 *Данный класс является виджетом ячейки инвентаря, где хранятся любые итемы инвентаря.
 ********************************************************************************************/

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

    //Стиль пустой ячейки
    void setEmptyStyle();
    //Стиль ячейки с предметом
    void setNoEmptyStyle();
    //Стиль ячейки с новым предметом
    void setNewStyle();
    //Стиль ячейки с новым заглушенным предметом
    void setLockedNewStyle();
    //Стиль ячейки с заглушенным предметом
    void setLockedStyle();
    //Стиль неактивной (заблокированной) ячейки
    void setDisabledStyle();

    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);

private:
    Ui::InventoryCell *ui;

    QMovie inventoryCellNew;
};

#endif // INVENTORYCELL_H
