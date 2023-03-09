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
    ItemIndex getIndexOfLastNonEmptyCell() override;

public slots:
    //Добавление новой линии пустых ячеек в инвентарь
    void addRowOfCellsToInventory() override;
    //Удаление последней линии ячеек в инвентаре
    void removeRowOfCellsFromInventory() override;

signals:
    //При скролле скроллбара подсказка должна пропадать
    void RemoveTooltip();

private slots:
    void InventoryScrollAreaScrolled(int value);

    void on_InventoryScrollBar_valueChanged(int value);
    void on_InventoryScrollBar_actionTriggered(int action);
    //Функция вызываемая по окончании задержки startScrollTimer. Запускает начало скролла
    void inventoryScrollingStarted();
    void checkingInventorySizeChange(int col, int row);

private:
    Ui::CharacterWindowInventory *ui;

    //метод реализующий логику прокрутки перетаскиваемым итемом
    void scrolling() override;

    bool eventFilter(QObject* object, QEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
};

#endif // CHARACTERWINDOWINVENTORY_H
