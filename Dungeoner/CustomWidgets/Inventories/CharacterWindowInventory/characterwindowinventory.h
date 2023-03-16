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
    ItemIndex getIndexOfLastEmptyCell() override;
    InventoryCell* getLastEmptyCell() override;

public slots:
    //Добавление новой линии пустых ячеек в инвентарь
    void addRowOfCellsToInventory() override;
    //Удаление последней линии ячеек в инвентаре
    void removeRowOfCellsFromInventory() override;

signals:
    //При скролле скроллбара подсказка должна пропадать
    void RemoveTooltip();
    void moveCellToEquipment(InventoryCell* cell);

private slots:
    void InventoryScrollAreaScrolled(int value);

    void on_InventoryScrollBar_valueChanged(int value);
    void on_InventoryScrollBar_actionTriggered(int action);
    //Функция вызываемая по окончании задержки startScrollTimer. Запускает начало скролла
    void inventoryScrollingStarted();
    /*Проверка того стоит ли изменять размер инвентаря. Если в последнюю ячейку положат итем,
     *то прибавится ещё одна пустая строка. Если из предпоследней ячейки уберут итем, то все
     *строки нижние кроме одной удалятся. Таким образом под итемами всегда будет одна пустая
     *строка. Количество строк в инвентаре окна персонажа не может быть меньше 4.*/
    void checkingInventorySizeChange(int col, int row);

private:
    Ui::CharacterWindowInventory *ui;

    //метод реализующий логику прокрутки перетаскиваемым итемом
    void scrolling() override;

    bool eventFilter(QObject* object, QEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
};

#endif // CHARACTERWINDOWINVENTORY_H
