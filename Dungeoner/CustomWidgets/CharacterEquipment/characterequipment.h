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
    explicit CharacterEquipment(QWidget *parent = nullptr);
    ~CharacterEquipment();

    QVector<InventoryCell *> getEquipmentCells() const;
    InventoryCell* findCell(QVector<Item::Slots> itemSlots, QVector<Item::Slots> occupiedCellSlots);

signals:
    void moveCellFromEquipment(InventoryCell* cell);

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

    void setCellsAcceptedSlots();
};

#endif // CHARACTEREQUIPMENT_H
