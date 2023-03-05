#include "abstractinventory.h"

void AbstractInventory::setPos(int XPos, int YPos)
{
    this->XPos = XPos;
    this->YPos = YPos;
}

void AbstractInventory::setPos(QPoint pos)
{
    XPos = pos.x();
    YPos = pos.y();
}

/*inventory - это непосредственно ссылка на конечный инвентарь, inventoryLayout - лейаут с ячейками
 *инвентаря, scrollAreaWidgetContents - виджет-обёртка, по ней считаются размеры рабочей области
 *инвентаря, scrollAreaScrollBar - скроллбар внутри области прокрутки, который у меня везде будет скрыт,
 *inventoryScrollBar - отдельный от области прокрутки скроллбар, который связан с ней ивентам,
 *фактически это тот скроллбар, который и управляет областью прокрутки*/
void AbstractInventory::addRowOfCellsToInventory(QWidget *inventory, QGridLayout *inventoryLayout, QWidget *scrollAreaWidgetContents,
                                                         QScrollBar *scrollAreaScrollBar, QScrollBar *inventoryScrollBar)
{
    if(maxColumns <=0)
        return;

    /*В строке всегда maxColumns ячеек, так что вычислить количество строк легко. Преимущество такого способа перед
     *rowCount в том, что rowCount возвращет 1, даже если строк вообще нет, а тут результат однозначный.*/
    int row = inventoryLayout->count()/maxColumns;

    /*row показывает текущее количество строк. Учитывая, что одна сейчас прибавися, row numberOfVisibleRows-1 означает, что в таблице
     *будет numberOfVisibleRows строки, а numberOfVisibleRows строки - это тот размер таблицы, который прокрутки не требует.*/
    if(row>(numberOfVisibleRows-1)){
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        scrollAreaWidgetContents->setFixedHeight(308 + 70*(row-(numberOfVisibleRows-1)) + 4*(row-numberOfVisibleRows));
        //Установка максимума скроллбаров равного суммарной высоте с учётом отствупов всех строк после четвёртой.
        int maximum = 70*(row-(numberOfVisibleRows-1)) + 4*(row-numberOfVisibleRows);
        scrollAreaScrollBar->setMaximum(maximum);
        inventoryScrollBar->setMaximum(maximum);
    }else{
        //Иначе прокрутка не требуется, и максимум скроллбаров обнуляется
        scrollAreaScrollBar->setMaximum(0);
        inventoryScrollBar->setMaximum(0);
    }

    //Создание новой строки ячеек
    for(int i = 0; i<maxColumns; i++){
        InventoryCell* cell = new InventoryCell();
        cell->installEventFilter(inventory);
        cell->setFixedSize(68, 68);
        /*Учитывая что row всегда показывает текущее количество ячеек, то есть на
         *1 меньше, чем будет, то его можно вставлять как индекс с отсчётом от 0*/
        inventoryLayout->addWidget(cell, row, i, Qt::AlignTop);

        QRect rect = cell->geometry();
        rect.setY(5 + 74*row);
        cell->setGeometry(rect);
    }
}

/*inventory - это непосредственно ссылка на конечный инвентарь, inventoryLayout - лейаут с ячейками
 *инвентаря, scrollAreaWidgetContents - виджет-обёртка, по ней считаются размеры рабочей области
 *инвентаря, scrollAreaScrollBar - скроллбар внутри области прокрутки, который у меня везде будет скрыт,
 *inventoryScrollBar - отдельный от области прокрутки скроллбар, который связан с ней ивентам,
 *фактически это тот скроллбар, который и управляет областью прокрутки*/
void AbstractInventory::removeRowOfCellsFromInventory(QWidget *inventory, QGridLayout *inventoryLayout, QWidget *scrollAreaWidgetContents,
                                                      QScrollBar *scrollAreaScrollBar, QScrollBar *inventoryScrollBar)
{
    if(maxColumns <=0)
        return;

    /*В строке всегда maxColumns ячеек, так что вычислить количество строк легко. Преимущество такого способа перед
     *rowCount в том, что rowCount возвращет 1, даже если строк вообще нет, а тут результат однозначный.*/
    int row = inventoryLayout->count()/10;

    /*row показывает текущее количество строк. Учитывая, что одна сейчас удалится, row numberOfVisibleRows+1 означает, что в таблице
     *останется numberOfVisibleRows строки, а numberOfVisibleRows строки - это тот размер таблицы, который прокрутки не требует.*/
    if(row>(numberOfVisibleRows+1)){
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        scrollAreaWidgetContents->setFixedHeight(308 + 70*(row-(numberOfVisibleRows+1)) + 4*(row-(numberOfVisibleRows+2)));
        //Установка максимума скроллбаров равного суммарной высоте с учётом отствупов всех строк после четвёртой.
        int maximum = 70*(row-(numberOfVisibleRows+1)) + 4*(row-(numberOfVisibleRows+2));
        scrollAreaScrollBar->setMaximum(maximum);
        inventoryScrollBar->setMaximum(maximum);
    }else{
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        scrollAreaWidgetContents->setFixedHeight(304);
        //Иначе прокрутка не требуется, и максимум скроллбаров обнуляется
        scrollAreaScrollBar->setMaximum(0);
        inventoryScrollBar->setMaximum(0);
    }

    //В инвентаре не может быть менее numberOfVisibleRows строк
    if(row<=numberOfVisibleRows)
        return;

    //Удаление строки ячеек
    for(int i = 0; i<maxColumns; i++){
        //Учитывая что row всегда показывает текущее количество ячеек, то его надо привести к индексу с отсчётом от 0
        delete inventoryLayout->itemAtPosition(row-1, i)->widget();
        inventoryLayout->removeItem(inventoryLayout->itemAtPosition(row-1, i));
    }
}
