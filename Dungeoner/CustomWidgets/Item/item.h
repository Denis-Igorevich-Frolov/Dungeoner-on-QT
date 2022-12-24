#ifndef ITEM_H
#define ITEM_H

#include "CustomWidgets/InventoryCell/inventorycell.h"
#include "Global/global.h"
#include "Person/MagicDefense/magicdefensebonus.h"
#include "Person/Stat/bonus.h"
#include <QGraphicsDropShadowEffect>
#include <QWidget>

namespace Ui {
class Item;
}

class Item : public QWidget
{
    Q_OBJECT

public:
    explicit Item(QWidget *parent = nullptr);
    ~Item();

    enum ItemType{
        SUNDRIES,//Разное
        ONE_HANDED_SWORD,//Одноручный меч
        TWO_HANDED_SWORD//Двуручный меч
    };

    enum ItemCondition{
        IDEAL,
        DAMAGED,
        BROKEN
    };

    struct Damage
    {
        Damage(int value, Global::DamageType damageType) {
            this->value = value;
            this->damageType = damageType;
        }
        int value;
        Global::DamageType damageType;
    };

    int getId() const;

private:
    Ui::Item *ui;

    int id = -1;
    double weight = 0;
    double volume = 0;
    int price = 0;
    QString itemName;
    QVector<ItemType> itemTypes;
    int durability = 0;
    ItemCondition itemCondition = IDEAL;
    int damage = -1;
    int amount = 1;
    QVector<InventoryCell::Slots> cellSlots;
    QVector<InventoryCell::Slots> occupiedCellSlots;
    QVector<Bonus*> bonuses;
    QVector<MagicDefenseBonus*> magicDefenseBonuses;
    QVector<Item*> styles{this};
    int currentStyle = 0;
    QString folderName;
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    bool hasShadow = true;
    int shadowBlurRadius = 7;
    int shadowXOffset = 3;
    int shadowYOffset = 3;

    /*Нужны ещё:
     *1) Вектор навыков
     *2) Вектор эффектов при прожатии
     *3) Вектор эффектов при экиперовке
     *4) Требования*/
};

#endif // ITEM_H
