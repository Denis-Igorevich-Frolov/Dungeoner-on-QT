#include "characterequipment.h"
#include "ui_characterequipment.h"

CharacterEquipment::CharacterEquipment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterEquipment)
{
    ui->setupUi(this);

    for(QObject* layer : ui->CellsStackedWidget->children()){
        for(auto autoCell : layer->children()){
            if(dynamic_cast <InventoryCell*> (autoCell)){
                InventoryCell* cell = qobject_cast <InventoryCell*> (autoCell);
                equipmentCells.append(cell);
            }else{
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                        "CharacterEquipment выдал предупреждение в методе CharacterEquipment.\n"
                        "Объект " + autoCell->objectName() + " не является InventoryCell.\n\n";
                qDebug()<<error;

                QFile errorFile("error log.txt");
                if (!errorFile.open(QIODevice::Append))
                {
                    qDebug() << "Ошибка при открытии файла логов";
                }else{
                    errorFile.open(QIODevice::Append  | QIODevice::Text);
                    QTextStream writeStream(&errorFile);
                    writeStream<<error;
                    errorFile.close();
                }
            }
        }
    }

    for(auto autoCell : ui->EquipmentWrapper->children()){
        if(dynamic_cast <InventoryCell*> (autoCell)){
            InventoryCell* cell = qobject_cast <InventoryCell*> (autoCell);
            equipmentCells.append(cell);
        }
    }

    for(InventoryCell* cell : equipmentCells){
        cell->setCentralElementStyle(false);
        connect(cell, &InventoryCell::moveCellToEquipment, this, &CharacterEquipment::moveCellFromEquipment);
        connect(cell, &InventoryCell::lockOccupiedCells, this, &CharacterEquipment::lockOccupiedCells);
        connect(cell, &InventoryCell::unlockOccupiedCells, this, &CharacterEquipment::unlockOccupiedCells);
        connect(cell, &InventoryCell::checkLockedCells, this, &CharacterEquipment::checkingLockedCells);
    }

    ui->RightDecoration->setDropdownButtonVisible(true);
    ui->LeftDecoration->setDropdownButtonVisible(true);
    ui->Bag->setDropdownButtonVisible(true);

    setCellsAcceptedSlots();
}

CharacterEquipment::~CharacterEquipment()
{
    delete ui;
}

void CharacterEquipment::on_OverArmorButton_clicked()
{
    ui->CellsStackedWidget->setCurrentIndex(2);
}


void CharacterEquipment::on_ArmorButton_clicked()
{
    ui->CellsStackedWidget->setCurrentIndex(1);
}


void CharacterEquipment::on_UnderArmorButton_clicked()
{
    ui->CellsStackedWidget->setCurrentIndex(0);
}

QVector<InventoryCell *> CharacterEquipment::getEquipmentCells() const
{
    return equipmentCells;
}

InventoryCell *CharacterEquipment::findCell(QVector<Item::Slots> itemSlots, QVector<Item::Slots> occupiedCellSlots)
{
    InventoryCell* firstMatch = nullptr;

    QVectorIterator<Item::Slots> iterator(itemSlots);
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        for(InventoryCell* cell : equipmentCells){
            if(cell->acceptedSlot == searchedSlot && !cell->getIsLocked()){
                if(cell->getItem()->itemIsEmpty)
                    return cell;
                else if(firstMatch == nullptr)
                    firstMatch = cell;
            }
        }
    }
    return firstMatch;
}

void CharacterEquipment::lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot)
{
    QVector<Item::Slots> occupiedSlots = QVector<Item::Slots>(cell->getItem()->getOccupiedCellSlots());

    QMutableVectorIterator<Item::Slots> iterator(occupiedSlots);
    while (iterator.hasNext()){
        if(iterator.next() == acceptedSlot){
            iterator.remove();
            break;
        }
    }

    for(Item::Slots slot : occupiedSlots){
        for(InventoryCell* destinationCell : equipmentCells){
            if(destinationCell->acceptedSlot == slot){
                if(destinationCell->getItem()->itemIsEmpty)
                    destinationCell->setLockedStyle(true, cell);
                else{
                    emit moveCellFromEquipment(destinationCell);
                    destinationCell->setLockedStyle(true, cell);
                }
            }
        }
    }
}

void CharacterEquipment::unlockOccupiedCells(InventoryCell* cell)
{
    QVector<Item::Slots> oldOccupiedSlots = QVector<Item::Slots>(cell->getItem()->getOccupiedCellSlots());

    for(Item::Slots slot : oldOccupiedSlots){
        for(InventoryCell* cell : equipmentCells){
            if(cell->acceptedSlot == slot && !cell->getIsManualLock()){
                cell->setLockedStyle(false);
            }
        }
    }
}

void CharacterEquipment::setCellsAcceptedSlots()
{
    ui->Arrows->acceptedSlot = Item::Slots::ARROWS;
    ui->Bag->acceptedSlot = Item::Slots::BAG;
    ui->Bolts->acceptedSlot = Item::Slots::BOLTS;
    ui->Bullets->acceptedSlot = Item::Slots::BULLETS;
    ui->Breastplate->acceptedSlot = Item::Slots::BREASTPLATE;
    ui->Gorget->acceptedSlot = Item::Slots::GORGET;
    ui->Helmet->acceptedSlot = Item::Slots::HELMET;
    ui->LeftBoot->acceptedSlot = Item::Slots::L_BOOT;
    ui->LeftGauntlet->acceptedSlot = Item::Slots::L_GAUNTLET;
    ui->LeftGreaves->acceptedSlot = Item::Slots::L_GREAVES;
    ui->LeftShoulder->acceptedSlot = Item::Slots::L_SHOULDER;
    ui->LefttBrace->acceptedSlot = Item::Slots::L_BRACE;
    ui->RightBoot->acceptedSlot = Item::Slots::R_BOOT;
    ui->RightBrace->acceptedSlot = Item::Slots::R_BRACE;
    ui->RightGauntlet->acceptedSlot = Item::Slots::R_GAUNTLET;
    ui->RightGreaves->acceptedSlot = Item::Slots::R_GREAVES;
    ui->RightShoulder->acceptedSlot = Item::Slots::R_SHOULDER;
    ui->Cap->acceptedSlot = Item::Slots::CAP;
    ui->Cloak->acceptedSlot = Item::Slots::CLOAK;
    ui->Mantle->acceptedSlot = Item::Slots::MANTLE;
    ui->BalaclavaHelmet->acceptedSlot = Item::Slots::BALACLAVA_HELMET;
    ui->Clothes->acceptedSlot = Item::Slots::CLOTHES;
    ui->LeftGlove->acceptedSlot = Item::Slots::L_GLOVE;
    ui->Pants->acceptedSlot = Item::Slots::PANTS;
    ui->RightGlove->acceptedSlot = Item::Slots::R_GLOVE;
    ui->Gunpowder->acceptedSlot = Item::Slots::GUNPOWDER;
    ui->LeftDecoration->acceptedSlot = Item::Slots::L_DECORATION;
    ui->LeftHand->acceptedSlot = Item::Slots::L_HAND;
    ui->RightDecoration->acceptedSlot = Item::Slots::R_DECORATION;
    ui->RightHand->acceptedSlot = Item::Slots::R_HAND;
}

bool CharacterEquipment::checkingLockedCells(QVector<Item::Slots> occupiedCellSlots)
{
    bool ItemsHaventBeenDropped = true;

    QVectorIterator<Item::Slots> iterator(occupiedCellSlots);
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        for(InventoryCell* cell : equipmentCells){
            if(cell->acceptedSlot == searchedSlot){
                if(cell->getIsLocked() && !cell->getIsManualLock()){
                    emit moveCellFromEquipment(cell->getCellWithLockingItem());
                }

                ItemsHaventBeenDropped = false;
            }
        }
    }

    return ItemsHaventBeenDropped;
}

