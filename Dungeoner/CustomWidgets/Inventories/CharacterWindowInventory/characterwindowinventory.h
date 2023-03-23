/******************************************************
 *Данный класс является инвентарём в окне персонажа.
 ******************************************************/

#ifndef CHARACTERWINDOWINVENTORY_H
#define CHARACTERWINDOWINVENTORY_H

#include <QWidget>
#include "CustomWidgets/Inventories/AbstractInventory/abstractinventory.h"
#include "CustomWidgets/InventoryCell/inventorycell.h"

namespace Ui {
class CharacterWindowInventory;
}

class CharacterWindowInventory : public QWidget, public AbstractInventory
{
    Q_OBJECT

public:
    explicit CharacterWindowInventory(QWidget *parent = nullptr);
    ~CharacterWindowInventory();

    InventoryCell* getCell(int row, int column) override;
    //Метод возвращающий адрес последней непустой ячейки. Последней считается самая правая нижняя ячейка
    ItemIndex getIndexOfLastNonEmptyCell() override;
    //Метод возвращающий адрес последней пустой ячейки. Последней считается самая правая нижняя ячейка
    ItemIndex getIndexOfLastEmptyCell() override;
    //Метод возвращающий последнюю пустую ячейку. Последней считается самая правая нижняя ячейка
    InventoryCell* getLastEmptyCell() override;

public slots:
    //Добавление новой линии пустых ячеек в инвентарь
    void addRowOfCellsToInventory() override;
    //Удаление последней линии ячеек в инвентаре
    void removeRowOfCellsFromInventory() override;
    /*Проверка того стоит ли изменять размер инвентаря. Если в последнюю ячейку положат итем,
     *то прибавится ещё одна пустая строка. Если из предпоследней ячейки уберут итем, то все
     *строки нижние кроме одной удалятся. Таким образом под итемами всегда будет одна пустая
     *строка. Количество строк в инвентаре окна персонажа не может быть меньше 4.*/
    void checkingInventorySizeChange(int col, int row);

signals:
    //При скролле скроллбара подсказка должна пропадать
    void RemoveTooltip();
    //Сигнал, переносящий итем из инвентаря в экиперовку. Переменная moveItemAnyway говорит о том, будет ли указаный итем вытеснять другие или нет
    void moveCellToEquipment(InventoryCell* cell, bool moveItemAnyway = true);
    //Сигнал, блокирующий занимаемые слоты итема в экиперовке
    void lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot);
    //Сигнал, разблокирующий занимаемые слоты итема в экиперовке
    void unlockOccupiedCells (InventoryCell* cell);
    /*Сигнал, проверяющий есль ли среди ячеек соответствующих переданым слотам, ячейки заблокированые другими итемами. Если
     *такие ячейки находятся, то итем блокирующий их сбрасывается. Метод возвращает true если был сброшен хотя бы 1 итем*/
    bool checkLockedCells (QVector<Item::Slots> occupiedCellSlots);
    //Сигнал, вызаваемый при начале перетаскивания любого итема. Подсвечивает все ячейки, в который данный итем можно положить
    void dragStarted(QVector<Item::Slots> cellSlots);
    //Слот, вызаваемый при окончании перетаскивания любого итема. Гасит посвеченые ячейки
    void dragEnded();

private slots:
    void InventoryScrollAreaScrolled(int value);

    void on_InventoryScrollBar_valueChanged(int value);
    void on_InventoryScrollBar_actionTriggered(int action);
    //Функция вызываемая по окончании задержки startScrollTimer. Запускает начало скролла
    void inventoryScrollingStarted();

private:
    Ui::CharacterWindowInventory *ui;

    //метод реализующий логику прокрутки перетаскиваемым итемом
    void scrolling() override;

    bool eventFilter(QObject* object, QEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
};

#endif // CHARACTERWINDOWINVENTORY_H
