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
    /*Стиль неактивной (заблокированной) ячейки. Если ячейка блокируется, в метод передаётся та ячейка, которая
     *спровоцировала блокировку. Также есть ручная блокировка, которая может быть только также вручную и снята*/
    void setLockedStyle(bool isLocked, InventoryCell* cellWithLockingItem = nullptr, bool isManualLock = false);
    //Стиль ячейки, в которую нельзя поместить выбранный итем
    void setBlockedStyle(bool isBlocked);
    //Стиль ячейки, в которую возможно поместить перетаскиваемый итем
    void setAvailableStyle(bool isAvailable);
    //Метод задающий значения переменным col и row. Он не изменит позицию и требуется только для инициализации
    void setCellPosition(int col, int row);

    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);
    void setSubstrateDollsVisible(bool isVisible);
    /*Установка подложки куклы персонажа на ячейку. Так как и маски и гифки не имеют полупрозрачности,
     *а только бинарную прозрачность, что очень некрасиво, то чтобы кукла была видна всегда на ячейке,
     *в неё помещается подложка, дублирущая необходимый фрагмент куклы*/
    void setSubstrateDollsPixmap (QPixmap pixmMap);

    //Текущий слот ячейки. По умолчанию это просто ячейка инвенторя. Не стоит оставлять такой слот в любом месте, где требуются ограничения на Drag&Drop
    Item::Slots acceptedSlot = Item::Slots::INVENTORY;

    bool getIsLocked() const;
    bool getIsBlocked() const;
    bool getIsAvailable() const;

    /*Метод меняющий местами итемы между ячейками. Следует помнить, что для правильного порядка
     *вызова сигналов данный метод следует вызывать у целевой ячейки, а передовать перемещаемую*/
    void swapItems(InventoryCell* cell, bool playSound = true);

    bool getIsManualLock() const;

    InventoryCell *getCellWithLockingItem() const;

    int getCol() const;

    int getRow() const;

signals:
    //Эвент говорящий в какую ячейку был перенесён итем при помощи Drag&Drop
    void itemIsDropped(int col, int row);
    /*Сигнал, говорящий о том, что итем из ячейки следует переместить. За то куда
     *именно он будет перемещен отвечает связь сигналов-слотов тех классов, где
     *расположена ячейка. Переменная moveItemAnyway отвечает за то, что будет
     *ли ячейка вытеснять другие итемы, если все доступные слоты заняты или нет*/
    void moveCell(InventoryCell* cell, bool moveItemAnyway = true);
    /*Сигнал, говорящий том, что у итема в данной ячейке нужно пересмотреть позицию в экиперовке. При переменной
     *moveItemAnyway равной true итем скорее вытеснит другой итем, а иначе он скорее сам сбросится*/
    void reviseItemPositionInEquipment(InventoryCell* cell, bool moveItemAnyway = true);
    /*Сигнал, блокирующий указанные в итеме из текущей ячейки слоты. Также передаётся слот ячейки из которой
     *был произведён запрос на блокирование итемов, чтобы вызывающая ячейка не могла заблокировать саму себя*/
    void lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot);
    //Сигнал, разблокирующий все блокируемые ячейки из вектора занимаемых слотов итема текущей ячейки
    void unlockOccupiedCells (InventoryCell* cell);
    /*Сигнал, проверяющий есль ли среди ячеек соответствующих переданым слотам, ячейки заблокированые другими итемами. Если
     *такие ячейки находятся, то итем блокирующий их сбрасывается. Метод возвращает true если был сброшен хотя бы 1 итем*/
    bool checkLockedCells (QVector<Item::Slots> occupiedCellSlots);
    void dragStarted(QVector<Item::Slots> cellSlots);
    void dragEnded();
    /*Проверка того стоит ли изменять размер инвентаря. Если в последнюю ячейку положат итем,
     *то прибавится ещё одна пустая строка. Если из предпоследней ячейки уберут итем, то все
     *строки нижние кроме одной удалятся. Таким образом под итемами всегда будет одна пустая
     *строка. Количество строк в инвентаре окна персонажа не может быть меньше 4.*/
    void checkingInventorySizeChange(int col, int row);

private slots:
    /*Слот связывающий сигналы moveItem и moveCell. Обычным connect это не сделать
     *так как moveCell передаёт ссылку на себя, а moveItem ничего не передаёт*/
    void moveItem();
    //Слот, снимающий блокировку со всех занимаемых ячеек старого стиля итема
    void styleRemoved();
    //Слот, устанавлявающий блокировку для всех занимаемых ячеек нового стиля итема
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
    //Указатель на ту ячейку, которая блокирует текущую. Если ячейку ничего не блокирует, переменная всегда равна nullptr
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
