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

    enum Slots{
        INVENTORY,//Слот инвентаря
        //Под доспехом
        BALACLAVA_HELMET,//Подшлемник
        CLOTHES,//Одежда
        PANTS,//Штаны
        R_GLOVE,//Правая перчатка
        L_GLOVE,//Левая перчатка
        //Доспех
        HELMET,//Шлем
        GORGET,//Горжет
        R_SHOULDER,//Правый наплечник
        L_SHOULDER,//Левый наплечник
        BREASTPLATE,//Нагрудник
        R_BRACE,//Правый наруч
        L_BRACE,//Левый наруч
        R_GAUNTLET,//Правая рукавица
        L_GAUNTLET,//Левая рукавица
        R_GREAVES,//Правый наголенник
        L_GREAVES,//Левый наголенник
        R_BOOT,//Правый ботинок
        L_BOOT,//Левый ботинок
        //Над доспехом
        CAP,//Шапка
        MANTLE,//Накидка
        CLOAK,//Плащ
        //Другое
        R_HAND,//Вещь в правой руке
        L_HAND,//Вещь в левой руке
        NECKLACE,//Ожерелье
        R_DECORATION,//Украшение правой руки
        L_DECORATION,//Украшение левой руки
        BAG,//Сумка
        GUNPOWDER,//Порох
        BULLETS,//Пули
        ARROWS,//Стрелы
        BOLTS,//Болты
        ADDITIONAL_SLOT//Дополнительный слот
    };

    //Стиль пустой ячейкиSS
    void setEmptyStyle();
    //Стиль ячейки с предметом
    void setNoEmptyStyle();
    //Стиль ячейки с новым предметом
    void setNewStyle();
    //Стиль ячейки с новым заглушенным предметом
    void setLockedNewStyle();
    //Стиль неактивной (заблокированной) ячейки
    void setLockedStyle();
    //Стиль ячейки с заглушенным предметом
    void setDisabledStyle();
    //Стиль ячейки, в которую нельзя поместить выбранный итем
    void setBlockedStyle(bool isBlocked);
    void setBrokenStyle();
    void setLockedBrokenStyle();

    void setCentralElementStyle(bool isVisible);
    void setDropdownButtonVisible(bool isVisible);

private:
    Ui::InventoryCell *ui;

    QMovie inventoryCellNew;
};

#endif // INVENTORYCELL_H
