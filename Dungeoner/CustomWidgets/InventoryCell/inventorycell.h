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
    void setLockedStyle();
    //Стиль ячейки, в которую нельзя поместить выбранный итем
    void setBlockedStyle(bool isBlocked);

    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);

    void setScrollAreaHeight(int newScrollAreaHeight);
    void setScrollAreaOffset(int newScrollAreaOffset);

    //Если ячейка находится вне границ скроллбара, то для оптимизации она очищается от стилей и скрывается
    void cellHidingCheck();

    bool swapItems(InventoryCell *sourceCell);

signals:
    void dragSourceObtained(InventoryCell* sourceCell);
    void dropTargetObtained(InventoryCell* targetCell);

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

    QPoint dragStart;

    bool isLoked = false;

    //Высота скроллбара, в который помещён вторичный навык
    int ScrollAreaHeight = 0;
    //Сдвиг скроллбара, в который помещён вторичный навык
    int ScrollAreaOffset = 0;

    Ui::InventoryCell *ui;

    QMovie inventoryCellNew;

    bool eventFilter(QObject* object, QEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
};

#endif // INVENTORYCELL_H
