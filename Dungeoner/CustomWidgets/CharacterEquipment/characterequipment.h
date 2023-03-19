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
    struct PairCells{
    public:
        PairCells(){};
        PairCells(InventoryCell *rightCell, InventoryCell *leftCell);

        InventoryCell *getRightCell() const;
        void setRightCell(InventoryCell *newRightCell);

        InventoryCell *getLeftCell() const;
        void setLeftCell(InventoryCell *newLeftCell);

    private:
        InventoryCell* rightCell;
        InventoryCell* leftCell;
    };

    explicit CharacterEquipment(QWidget *parent = nullptr);
    ~CharacterEquipment();

    QVector<InventoryCell *> getEquipmentCells() const;
    InventoryCell* findCell(QVector<Item::Slots> itemSlots);

signals:
    void moveCellFromEquipment(InventoryCell* cell);
    void reviseItemPositionInEquipment(InventoryCell* cell);

public slots:
    void lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot);
    void unlockOccupiedCells (InventoryCell* cell);
    bool checkingLockedCells (QVector<Item::Slots> occupiedCellSlots);

private slots:
    void on_OverArmorButton_clicked();
    void on_ArmorButton_clicked();
    void on_UnderArmorButton_clicked();

private:
    Ui::CharacterEquipment *ui;

    QVector<InventoryCell*> equipmentCells;

    PairCells bothGloves;
    PairCells bothShoulders;
    PairCells bothBraces;
    PairCells bothGauntlets;
    PairCells bothGreaves;
    PairCells bothBoots;
    PairCells bothHands;
    PairCells bothDecorations;

    void setCellsAcceptedSlots();
    bool itemDrop(InventoryCell* cell, Item::Slots searchedSlot);
};

#endif // CHARACTEREQUIPMENT_H
