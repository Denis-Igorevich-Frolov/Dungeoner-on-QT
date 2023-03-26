/**********************************************************************************************************************
 *Данный класс является экиперовкой персонажа с "куклой", на которую одеваются различные итемы. У экиперовки
 *есть 3 слоя: под доспехом, доспех и над доспехом. Нажатием с зажатым шифтом из виджета инвентаря можно быстро
 *экиперовывать итемы на куклу и также сбрасывать назад в инвентарь. Если начать перетаскивать итем, то на кукле
 *загорятся доступные к экиперовке ячейки для этой вещи.
 **********************************************************************************************************************/

#ifndef CHARACTEREQUIPMENT_H
#define CHARACTEREQUIPMENT_H

#include "CustomWidgets/InventoryCell/inventorycell.h"
#include <QWidget>

#include <CustomWidgets/Item/item.h>

namespace Ui {
class CharacterEquipment;
}

class CharacterEquipment : public QWidget
{
    Q_OBJECT

public:
    /*Структура парных ячеек. Данная стуктура нужна например для обоих рук. Если одна вещь может
     *занимать любую из ячеек в паре, например, любую из рук, то ей задаётся занимаемый слот такой
     *как ONE_OF_THE_HAND и с помощью парной структуры bothHands может быть выбрана любая рука.*/
    struct PairCells{
    public:
        PairCells(){};
        PairCells(InventoryCell *rightCell, InventoryCell *leftCell);

        InventoryCell *getRightCell() const;
        void setRightCell(InventoryCell *newRightCell);

        InventoryCell *getLeftCell() const;
        void setLeftCell(InventoryCell *newLeftCell);

    private:
        //У всех парных ячеек есть правая ячейка и левая, как правый и левый ботинок
        InventoryCell* rightCell;
        InventoryCell* leftCell;
    };

    explicit CharacterEquipment(QWidget *parent = nullptr);
    ~CharacterEquipment();

    QVector<InventoryCell *> getEquipmentCells() const;
    /*Функция поиска первой подходящей ячейки по переданому вектору слотов экиперовки. Переменная
     *findCellAnyway заставляет возвращать ячейку даже если все подходящие заняты*/
    InventoryCell* findCell(QVector<Item::Slots> itemSlots, bool findCellAnyway = true);

signals:
    /*Сигнал, говорящий о том, что итем нужно сбросить из экиперовки. Переменная
     *playSound отвечает за то, будет ли проигрываться при этом звук сброса. Это
     *важно для предотвращения конфликтов медиаплеера при одновременном запросе
     *воспроизведение нескольких звуков сразу.*/
    void moveCellFromEquipment(InventoryCell* cell, bool playSound = true);
    /*Сигнал, говорящий том, что у итема нужно пересмотреть позицию в экиперовке. При переменной
     *moveItemAnyway равной true итем скорее вытеснит другой итем, а иначе он скорее сам сбросится*/
    void reviseItemPositionInEquipment(InventoryCell* cell, bool moveItemAnyway = true);

public slots:
    /*Метод, блокирующий указанные в итеме из cell ячейки переданной ячейкой с итемом. Это необходимо, например, когда итем занимает сразу несколько слотов.
     *Также передаётся слот ячейки из которой был произведён запрос на блокирование итемов, чтобы вызывающая ячейка не могла заблокировать саму себя.*/
    void lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot);
    //Метод, разблокирующий все блокируемые ячейки из вектора занимаемых ячеек из итема из cell
    void unlockOccupiedCells (InventoryCell* cell);
    /*Метод, проверяющий есль ли среди ячеек соответствующих переданым слотам, ячейки заблокированые другими итемами. Если
     *такие ячейки находятся, то итем блокирующий их сбрасывается. Метод возвращает true если был сброшен хотя бы 1 итем*/
    bool checkingLockedCells (QVector<Item::Slots> occupiedCellSlots);
    //Слот, вызаваемый при начале перетаскивания любого итема. Подсвечивает все ячейки, в который данный итем можно положить
    void dragStarted(QVector<Item::Slots> cellSlots);
    //Слот, вызаваемый при окончании перетаскивания любого итема. Гасит посвеченые ячейки
    void dragEnded();

    void takeTwoHandedGripRightHandItem();
    void takeTwoHandedGripLeftHandItem();
    void useOneHandedGrip();
    bool checkFreeHands();
    bool checkBusyHands();
    void applyGrip();

    void switchEquipmentLayer(InventoryCell::EquipmentLayer equipmentLayer);
    void checkUsedTwoHandedGrip(InventoryCell* cell);
    void checkUsedOneHandedGrip(InventoryCell* cell);

private slots:
    void on_OverArmorButton_clicked();
    void on_ArmorButton_clicked();
    void on_UnderArmorButton_clicked();

private:
    Ui::CharacterEquipment *ui;

    //Вектор всех ячеек экиперовки
    QVector<InventoryCell*> equipmentCells;

    //Все пары ячеек
    PairCells bothGloves;
    PairCells bothPauldrons;
    PairCells bothBraces;
    PairCells bothGauntlets;
    PairCells bothGreaves;
    PairCells bothBoots;
    PairCells bothHands;
    PairCells bothDecorations;

    //Метод устанавливающий всем ячейкам экиперовки соответствующие слоты и подложки
    void setCellsAcceptedSlots();
    //Метод, сбрасывающий блокирующий переданую ячейку итем, если она соответствует переданому слоту. Метод возвращает был ли выполнен сброс
    bool itemDrop(InventoryCell* cell, Item::Slots searchedSlot, bool playSound = true);

    bool usedTwoHandedGrip = false;
};

#endif // CHARACTEREQUIPMENT_H
