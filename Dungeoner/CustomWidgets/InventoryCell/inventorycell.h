/********************************************************************************************
 *Данный класс является виджетом ячейки инвентаря, где хранятся любые итемы инвентаря.
 ********************************************************************************************/

#ifndef INVENTORYCELL_H
#define INVENTORYCELL_H

#include "CustomWidgets/Item/item.h"
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

    void setItem(Item* item);
    Item* getItem();

    //Метод, выставляющий стиль автоматически исходя из характеристик предмета
    void setAutoStyle();
    //Стиль неактивной (заблокированной) ячейки
    void setLockedStyle(bool isLocked, InventoryCell* cellWithLockingItem = nullptr, bool isManualLock = false);
    //Стиль ячейки, в которую нельзя поместить выбранный итем
    void setBlockedStyle(bool isBlocked);
    void setAvailableStyle(bool isAvailable);
    //Метод задающий значения переменным col и row. Он не изменит позицию и требуется только для инициализации
    void setCellPosition(int col, int row);

    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);
    void setSubstrateDollsVisible(bool isVisible);
    void setSubstrateDollsPixmap (QPixmap pixmMap);

    Item::Slots acceptedSlot = Item::Slots::INVENTORY;

    bool getIsLocked() const;
    bool getIsBlocked() const;
    bool getIsAvailable() const;

    void swapItems(InventoryCell* cell);

    bool getIsManualLock() const;

    InventoryCell *getCellWithLockingItem() const;


signals:
    //Эвент говорящий в какую ячейку был перенесён итем при помощи Drag&Drop
    void itemIsDropped(int col, int row);
    void moveCellToEquipment(InventoryCell* cell, bool moveItemAnyway = true);
    void reviseItemPositionInEquipment(InventoryCell* cell, bool moveItemAnyway = true);
    void lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot);
    void unlockOccupiedCells (InventoryCell* cell);
    bool checkLockedCells (QVector<Item::Slots> occupiedCellSlots);
    void dragStarted(QVector<Item::Slots> cellSlots);
    void dragEnded();

private slots:
    void moveItemToEquipment();
    void styleRemoved();
    void styleAssigned();

private:
    //Стиль пустой ячейки
    void setEmptyStyle();
    //Стиль ячейки с предметом
    void setNoEmptyStyle();
    //Стиль ячейки с новым предметом
    void setNewStyle();
    //Стиль ячейки с новым заглушенным предметом
    void setDisabledNewStyle();
    //Стиль ячейки с новым сломанным пребметом
    void setBrokenNewStyle();
    //Стиль ячейки с новым заглушенным сломанным пребметом
    void setDisabledBrokenNewStyle();
    //Стиль ячейки с заглушенным предметом
    void setDisabledStyle();
    //Стиль ячейки со сломанным пребметом
    void setBrokenStyle();
    //Стиль ячейки с заглушенным сломанным пребметом
    void setDisabledBrokenStyle();

    //Позиция ячейки
    int col = 0;
    int row = 0;

    //Позиция начала перетакивания итема
    QPoint dragStart;

    bool isLocked = false;
    bool isManualLock = false;
    InventoryCell* cellWithLockingItem = nullptr;
    bool isBlocked = false;
    bool isAvailable = false;

    Ui::InventoryCell *ui;

    QMovie inventoryCellNew;

    bool eventFilter(QObject* object, QEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;

    bool CentralElementIsVisible = false;
};

#endif // INVENTORYCELL_H
