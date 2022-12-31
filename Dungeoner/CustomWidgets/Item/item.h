/********************************************************************************
 *Данный класс является классом вещи. Здесь хранятся все её характеристики
 *и имеются все необходимые методы визуализации предметов в инвентаре.
 ********************************************************************************/

#ifndef ITEM_H
#define ITEM_H

//#include "CustomWidgets/InventoryCell/inventorycell.h"
#include "Global/global.h"
#include "Person/MagicDefense/magicdefensebonus.h"
#include "Person/Stat/bonus.h"
#include "System/OutlineEffect/outlineeffect.h"
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
        BROKEN,
        CRASHPROOF
    };

    //Все возможные типы слотов инвентаря
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

    Item(QString folderName, QVector<ItemType> itemTypes, QString itemName = "Name", int quantity = 1, double weight = 0, double volume = 0,
         int price = 0, int maxDurability = -1, int currentDurability = -1, QVector<Slots> cellSlots = {},
         QVector<Slots> occupiedCellSlots = {}, QVector<Bonus*> bonuses = {}, QVector<MagicDefenseBonus *> magicDefenseBonuses = {},
         int minDamage = 0, int maxDamage = 0, bool isPressable = false, bool isDisabled = false, bool isNew = false, int currentStyle = 0);

    void setShadow(bool hasShadow, int shadowBlurRadius = 7, int shadowXOffset = 3, int shadowYOffset = 3, QColor color = Qt::black);
    void setStyleButtonsStyle();

    struct Damage
    {
        Damage(int value, Global::DamageType damageType) {
            this->value = value;
            this->damageType = damageType;
        }
        int value;
        Global::DamageType damageType;
    };

    bool isNew = false;
    bool isDisabled = false;
    //Первый стиль - всегда исходный предмет
    QVector<Item*> styles {this};

    QString folderName;
    bool isPressable = false;
    bool hasShadow = true;
    QVector<ItemType> itemTypes;
    QVector<Bonus*> bonuses;
    QVector<MagicDefenseBonus*> magicDefenseBonuses;

    QImage image;
    int shadowBlurRadius = 7;
    int shadowXOffset = 3;
    int shadowYOffset = 3;
    QColor hoverColor = QColor(255, 255, 255, 40);
    QColor pressedColor = QColor(0, 0, 0, 50);
    QColor disabledColor = QColor(0, 0, 0, 140);
    QColor brokenColor = QColor(255, 0, 0, 50);

    int getId() const;

    //Установка/отключение стиля заглушенного итема
    void setDisabledSyle(bool isDisabled);
    //Установка/отключение стиля сломанного итема
    void setBrokenSyle(bool isBroken);

    bool getIsBroken();

    int getQuantity() const;
    void setQuantity(int newQuantity);

    double getWeight() const;
    void setWeight(double newWeight);

    double getVolume() const;
    void setVolume(double newVolume);

    int getPrice() const;
    void setPrice(int newPrice);

    QString getItemName() const;
    void setItemName(const QString &newItemName);

    int getMaxDurability() const;
    void setMaxDurability(int newMaxDurability);

    int getCurrentDurability() const;
    void setCurrentDurability(int newCurrentDurability);

    int getMinDamage() const;
    void setDamage(int newMinDamage, int newMaxDamage);

    int getMaxDamage() const;

    QVector<Slots> getCellSlots() const;
    void setCellSlots(QVector<Slots> newCellSlots, QVector<Slots> newOccupiedCellSlots);

    int getCurrentStyle() const;
    void setCurrentStyle(int newCurrentStyle);

    void init(QPixmap pixMap);

    void setId(int newId);

    QVector<Slots> getOccupiedCellSlots() const;

private slots:
    //Эффекты при прожатии итема
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::Item *ui;

    int id = -1;
    double weight = 0;
    double volume = 0;
    int price = 0;
    QString itemName;
    int maxDurability = -1;
    int currentDurability = -1;
    ItemCondition itemCondition = CRASHPROOF;
    int minDamage = 0;
    int maxDamage = 0;
    int quantity = 1;
    QVector<Slots> cellSlots;
    QVector<Slots> occupiedCellSlots;
    int currentStyle = 0;
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    OutlineEffect* border = new OutlineEffect;
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect;
    /*Нужны ещё:
     *1) Вектор навыков
     *2) Вектор эффектов при прожатии
     *3) Вектор эффектов при экиперовке
     *4) Требования*/

    virtual bool eventFilter(QObject* object, QEvent* event) override;

    int isHovered = false;
};

#endif // ITEM_H
