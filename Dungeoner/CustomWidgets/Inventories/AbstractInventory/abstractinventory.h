/****************************************************************************************************************
 *Данный класс является наследником всех инвентарей. Больше подробностей в каждом отдельно взятом инвентаре
 ****************************************************************************************************************/

#ifndef ABSTRACTINVENTORY_H
#define ABSTRACTINVENTORY_H

#include "CustomWidgets/InventoryCell/inventorycell.h"
#include "qgridlayout.h"
#include "qpoint.h"
#include "qscrollbar.h"
#include "qscrollerproperties.h"
#include "qtimer.h"

class AbstractInventory
{
public:
    void setPos(int XPos, int YPos);
    void setPos(QPoint pos);

    virtual InventoryCell* getCell(int row, int column){return nullptr;};

    //Структура хранящая позицию ячейки инвентаря
    struct ItemIndex{
    public:
        int col;
        int row;

        ItemIndex(int col, int row);
    };

public slots:
    //Добавление новой линии пустых ячеек в инвентарь
    virtual void addRowOfCellsToInventory(){};
    //Удаление последней линии ячеек в инвентаре
    virtual void removeRowOfCellsFromInventory(){};
    //Метод возвращающий адрес последней непустой ячейки. Последней считается самая правая нижняя ячейка
    virtual ItemIndex getIndexOfLastNonEmptyCell(){return ItemIndex(-1, -1);};
    virtual ItemIndex getIndexOfLastEmptyCell(){return ItemIndex(-1, -1);};
    virtual InventoryCell* getLastEmptyCell(){return nullptr;};

protected:
    enum inventoryScrollerState{
        STOPPED,
        FAST_SPEED,
        SLOW_SPEED
    };

    inventoryScrollerState inventoryScrollerState = STOPPED;

    /*Чтобы корректно работал скролл инвентаря перетаскиваемым итемом, ему нужно знать
     *свою позицию на экране. Дело в том, что проверка положения курсора берётся из
     *QCursor::pos(), а не из QMouseEvent так, как перетаскивание производится при
     *помощи зажатия  ЛКМ, а QMouseEvent никогда не вызовет MouseMove при зажатой
     *кнопке. Следовательно инвентарь вынужден знать свою глобальную позицию*/
    int XPos = 0;
    int YPos = 0;

    //Это число строк/стобцов, которые видны без надобности в прокрутке
    int numberOfVisibleRows = 0;
    int numberOfVisibleColumns = 0;

    //Количество строк и столбцов в инвентаре. Значение -1 означает полное отсутствиве ячеек
    int row = -1;
    int col = -1;

    int maxRows = 0;
    int maxColumns = 0;

    /*inventory - это непосредственно ссылка на конечный инвентарь, inventoryLayout - лейаут с ячейками
     *инвентаря, scrollAreaWidgetContents - виджет-обёртка, по ней считаются размеры рабочей области
     *инвентаря, scrollAreaScrollBar - скроллбар внутри области прокрутки, который у меня везде будет скрыт,
     *inventoryScrollBar - отдельный от области прокрутки скроллбар, который связан с ней ивентам,
     *фактически это тот скроллбар, который и управляет областью прокрутки*/
    void addRowOfCellsToInventory(QWidget *inventory, QGridLayout* inventoryLayout, QWidget* scrollAreaWidgetContents,
                                          QScrollBar* scrollAreaScrollBar, QScrollBar* inventoryScrollBar);
    /*inventory - это непосредственно ссылка на конечный инвентарь, inventoryLayout - лейаут с ячейками
     *инвентаря, scrollAreaWidgetContents - виджет-обёртка, по ней считаются размеры рабочей области
     *инвентаря, scrollAreaScrollBar - скроллбар внутри области прокрутки, который у меня везде будет скрыт,
     *inventoryScrollBar - отдельный от области прокрутки скроллбар, который связан с ней ивентам,
     *фактически это тот скроллбар, который и управляет областью прокрутки*/
    void removeRowOfCellsFromInventory(QWidget *inventory, QGridLayout* inventoryLayout, QWidget* scrollAreaWidgetContents,
                                       QScrollBar* scrollAreaScrollBar, QScrollBar* inventoryScrollBar);

    //Метод возвращающий адрес последней непустой ячейки. Последней считается самая правая нижняя ячейка
    ItemIndex getIndexOfLastNonEmptyCell(QGridLayout* inventoryLayout);
    ItemIndex getIndexOfLastEmptyCell(QGridLayout* inventoryLayout);

    virtual void scrolling(){};

    QScroller* inventoryScroller;
    QScrollerProperties inventoryScrollerProperties;
    //Для избежания ненужного скролла во время перетаскивания итема за пределы инвентаря, скролл инициируется не сразу, а с небольшой задержкой
    QTimer* startScrollTimer = new QTimer();
    //Переменная, которую startScrollTimer меняет на true после окончания таймера
    bool inventoryScrollingIsStarted = false;
};

#endif // ABSTRACTINVENTORY_H
