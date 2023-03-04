#ifndef ABSTRACTINVENTORY_H
#define ABSTRACTINVENTORY_H

#include "CustomWidgets/InventoryCell/inventorycell.h"
#include "qpoint.h"
#include "qscrollerproperties.h"
#include "qtimer.h"
class AbstractInventory
{
public:
    void setPos(int XPos, int YPos);
    void setPos(QPoint pos);

    virtual InventoryCell* getCell(int row, int column){return nullptr;};

public slots:
    //Добавление новой линии пустых ячеек в инвентарь
    virtual void addRowOfCellsToInventory(){};
    //Удаление последней линии ячеек в инвентаре
    virtual void removeRowOfCellsFromInventory(){};

protected:
    enum inventoryScrollerState{
        STOPPED,
        FAST_SPEED,
        SLOW_SPEED
    };
    inventoryScrollerState inventoryScrollerState = STOPPED;

    int XPos = 0;
    int YPos = 0;

    virtual void scrollInventory(int Ypos){};
    bool inventoryIsScrolled = false;

    QScroller* inventoryScroller;
    QScrollerProperties inventoryScrollerProperties;
    QTimer* startScrollTimer = new QTimer();
    bool inventoryScrollingIsStarted = false;
};

#endif // ABSTRACTINVENTORY_H
