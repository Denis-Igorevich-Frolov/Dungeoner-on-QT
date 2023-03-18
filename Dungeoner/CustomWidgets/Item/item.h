/********************************************************************************
 *Данный класс является классом вещи. Здесь хранятся все её характеристики
 *и имеются все необходимые методы визуализации предметов в инвентаре.
 ********************************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include "Global/global.h"
#include "Person/MagicDefense/magicdefensebonus.h"
#include "Person/Stat/bonus.h"
#include "System/OutlineEffect/outlineeffect.h"
#include "qdir.h"
#include "qpushbutton.h"
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
        R_GREAVE,//Правый наголенник
        L_GREAVE,//Левый наголенник
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
        ADDITIONAL_SLOT,//Дополнительный слот

        ONE_OF_THE_GLOVE,
        ONE_OF_THE_SHOULDER,
        ONE_OF_THE_BRACE,
        ONE_OF_THE_GAUNTLET,
        ONE_OF_THE_GREAVE,
        ONE_OF_THE_BOOT,
        ONE_OF_THE_HAND,
        ONE_OF_THE_DECORATION,
    };

    //Конструктор, применяемый для создания независимого клона или полностью настроенного экземпляра Item
    Item(QString folderName, QVector<ItemType> itemTypes, QString itemName = "Name", int quantity = 1, double weight = 0, double volume = 0,
         int price = 0, int maxDurability = -1, int currentDurability = -1, QVector<Slots> cellSlots = {},  QVector<Slots> occupiedCellSlots = {},
         QVector<Bonus*> bonuses = {}, QVector<MagicDefenseBonus *> magicDefenseBonuses = {}, int minDamage = 0, int maxDamage = 0,
         bool isPressable = false, int maxCharges = -1, int currentCharges = 0, bool isDisabled = false, bool isNew = false, int currentStyle = 0,
         bool itemIsEmpty = false, QVector<Item*> styles = {}, QString SoundDrag = "", QString SoundDrop = "", QString SoundPress = "",
         QString SoundPressWithOutOfCharge = "qrc:/Sounds/Sounds/Error.mp3");

    //Конструктор независимого клона итема по константной ссылке. Пока используется только в Drag&Drop
    Item(const Item* item);

    void setShadow(bool hasShadow, int shadowBlurRadius = 7, int shadowXOffset = 3, int shadowYOffset = 3, QColor color = Qt::black);
    //Установка стиля для кнопки, переключающей стили предмета
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
    bool itemIsEmpty = false;
    QVector<ItemType> itemTypes;
    QVector<Bonus*> bonuses;
    QVector<MagicDefenseBonus*> magicDefenseBonuses;

    QString SoundDrag = "";
    QString SoundDrop = "";
    QString SoundPress = "";
    QString SoundPressWithOutOfCharge = "qrc:/Sounds/Sounds/Error.mp3";

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

    //Проверка сломана ли вещь
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
    //Передаваемое имя не может быть пустым. При попытке передачии "" в функцию не произойдёт ничего
    void setItemName(const QString &newItemName);

    int getMaxDurability() const;
    void setMaxDurability(int newMaxDurability);

    int getCurrentDurability() const;
    void setCurrentDurability(int newCurrentDurability);

    int getMinDamage() const;
    void setDamage(int newMinDamage, int newMaxDamage);

    int getMaxDamage() const;

    QVector<Slots> getCellSlots() const;
    /*Установка векторов ячеек доступных для этой вещи и её занимаемых слотов. В занимаемых
     *слотах нужно указывать ячейки только если предмет всегда занимает их несколько*/
    void setCellSlots(QVector<Slots> newCellSlots, QVector<Slots> newOccupiedCellSlots = QVector<Slots>());

    int getCurrentStyle() const;
    //Метод устанавливающий текущий стиль итемов на основе вектора styles
    void setCurrentStyle(int newCurrentStyle);

    void setId(int newId);

    QVector<Slots> getOccupiedCellSlots() const;

    //Класс для оптимизации полностью скрывающий итем и его стили. Вызывается только когда итема и так не должно быть видно
    void hidenEffects(bool hiden);

    //Загрузка всех стилей из папки Styles в папке итема
    bool loadStyles(QDir dir);

    QPushButton *getItemButton();

    QWidget *getStyleButtonsWrapper();

    int getMaxCharges();
    void setMaxCharges(int newMaxCharges);

    int getCurrentCharges() const;
    void setCurrentCharges(int newCurrentCharges);

signals:
    void moveItemToEquipment();

private slots:
    //Эффекты при прожатии итема
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_StyleButton_1_clicked();

    void on_StyleButton_2_clicked();

    void on_StyleButton_3_clicked();

    void on_StyleButton_4_clicked();

    void on_StyleButton_5_clicked();

private:
    Ui::Item *ui;

    //id должен быть уникальным. -1 означает, что в ячейке итема нет.
    int id = -1;
    double weight = 0;
    double volume = 0;
    int price = 0;
    QString itemName = "Item";

    //Прочность -1 означает, что предмет неразрушим и ему сразу присваивается состояние CRASHPROOF
    int maxDurability = -1;
    int currentDurability = -1;
    ItemCondition itemCondition = CRASHPROOF;

    /*Метод устанавливающий стиль кнопок стилей итема в соответствии с текущим стилем. Так гасятся
     *все кнопки кроме той, которая соответствует текущему стилю, она же в свою очередь зажигается*/
    void setChosenStyleButtonStyle();

    int minDamage = 0;
    int maxDamage = 0;
    int quantity = 1;
    //Вектор слотов, в которые может быть помещён предмет. Некоторые предметы можно помещать в разные слоты на выбор
    QVector<Slots> cellSlots;
    /*Вектор слотов, которые займёт вещь. Как правило одна вещь может занимать лишь один
     *слот, но некоторые занимают несколько. Так например двуручный меч займёт обе руки*/
    QVector<Slots> occupiedCellSlots;
    //Этот стиль является одним из переключаемых состояний предмета
    int currentStyle = 0;
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect;
    OutlineEffect* border = new OutlineEffect;
    //Заряды предмета. -1 означает, что предмет прожимается неограниченное количество раз
    int maxCharges = -1;
    int currentCharges = 0;
    /*Нужны ещё:
     *1) Вектор навыков
     *2) Вектор эффектов при прожатии
     *3) Вектор эффектов при экиперовке
     *4) Требования*/

    bool eventFilter(QObject* object, QEvent* event) override;

    int isHovered = false;
};

#endif // ITEM_H
