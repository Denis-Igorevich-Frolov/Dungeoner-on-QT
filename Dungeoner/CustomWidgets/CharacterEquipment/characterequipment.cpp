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
        connect(cell, &InventoryCell::reviseItemPositionInEquipment, this, &CharacterEquipment::reviseItemPositionInEquipment);
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

CharacterEquipment::PairCells::PairCells(InventoryCell *rightCell, InventoryCell *leftCell):
    rightCell(rightCell), leftCell(leftCell)
{}

InventoryCell *CharacterEquipment::PairCells::getLeftCell() const
{
    return leftCell;
}

void CharacterEquipment::PairCells::setLeftCell(InventoryCell *newLeftCell)
{
    leftCell = newLeftCell;
}

InventoryCell *CharacterEquipment::PairCells::getRightCell() const
{
    return rightCell;
}

void CharacterEquipment::PairCells::setRightCell(InventoryCell *newRightCell)
{
    rightCell = newRightCell;
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
        if(slot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_SHOULDER){
            InventoryCell* rightCell = bothShoulders.getRightCell();
            InventoryCell* leftCell = bothShoulders.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_BRACE){
            InventoryCell* rightCell = bothBraces.getRightCell();
            InventoryCell* leftCell = bothBraces.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_GAUNTLET){
            InventoryCell* rightCell = bothGauntlets.getRightCell();
            InventoryCell* leftCell = bothGauntlets.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_GREAVE){
            InventoryCell* rightCell = bothGreaves.getRightCell();
            InventoryCell* leftCell = bothGreaves.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_BOOT){
            InventoryCell* rightCell = bothBoots.getRightCell();
            InventoryCell* leftCell = bothBoots.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_HAND){
            InventoryCell* rightCell = bothHands.getRightCell();
            InventoryCell* leftCell = bothHands.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else if(slot == Item::ONE_OF_THE_DECORATION){
            InventoryCell* rightCell = bothDecorations.getRightCell();
            InventoryCell* leftCell = bothDecorations.getLeftCell();
            if(rightCell->getItem()->itemIsEmpty || (!rightCell->getItem()->itemIsEmpty && rightCell!=cell && !leftCell->getItem()->itemIsEmpty)){
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell);
            }else{
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell);
            }
        }else{
            for(InventoryCell* destinationCell : equipmentCells){
                if(destinationCell->acceptedSlot == slot){
                    destinationCell->setLockedStyle(true, cell);
                    if(!destinationCell->getItem()->itemIsEmpty)
                        emit moveCellFromEquipment(destinationCell);
                }
            }
        }
    }
}

void CharacterEquipment::unlockOccupiedCells(InventoryCell* cell)
{
    QVector<Item::Slots> oldOccupiedSlots = QVector<Item::Slots>(cell->getItem()->getOccupiedCellSlots());

    for(Item::Slots slot : oldOccupiedSlots){
        if(slot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_SHOULDER){
            InventoryCell* rightCell = bothShoulders.getRightCell();
            InventoryCell* leftCell = bothShoulders.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_BRACE){
            InventoryCell* rightCell = bothBraces.getRightCell();
            InventoryCell* leftCell = bothBraces.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_GAUNTLET){
            InventoryCell* rightCell = bothGauntlets.getRightCell();
            InventoryCell* leftCell = bothGauntlets.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_GREAVE){
            InventoryCell* rightCell = bothGreaves.getRightCell();
            InventoryCell* leftCell = bothGreaves.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_BOOT){
            InventoryCell* rightCell = bothBoots.getRightCell();
            InventoryCell* leftCell = bothBoots.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_HAND){
            InventoryCell* rightCell = bothHands.getRightCell();
            InventoryCell* leftCell = bothHands.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_DECORATION){
            InventoryCell* rightCell = bothDecorations.getRightCell();
            InventoryCell* leftCell = bothDecorations.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else{
            for(InventoryCell* cell : equipmentCells){
                if(cell->acceptedSlot == slot && !cell->getIsManualLock()){
                    cell->setLockedStyle(false);
                }
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
    ui->LeftGreave->acceptedSlot = Item::Slots::L_GREAVE;
    ui->LeftShoulder->acceptedSlot = Item::Slots::L_SHOULDER;
    ui->LeftBrace->acceptedSlot = Item::Slots::L_BRACE;
    ui->RightBoot->acceptedSlot = Item::Slots::R_BOOT;
    ui->RightBrace->acceptedSlot = Item::Slots::R_BRACE;
    ui->RightGauntlet->acceptedSlot = Item::Slots::R_GAUNTLET;
    ui->RightGreave->acceptedSlot = Item::Slots::R_GREAVE;
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

    bothGloves = PairCells(ui->RightGlove, ui->LeftGlove);
    bothShoulders = PairCells(ui->RightShoulder, ui->LeftShoulder);
    bothBraces = PairCells(ui->RightBrace, ui->LeftBrace);
    bothGauntlets = PairCells(ui->RightGauntlet, ui->LeftGauntlet);
    bothGreaves = PairCells(ui->RightGreave, ui->LeftGreave);
    bothBoots = PairCells(ui->RightBoot, ui->LeftBoot);
    bothHands = PairCells(ui->RightHand, ui->LeftHand);
    bothDecorations = PairCells(ui->RightDecoration, ui->LeftDecoration);
}

bool CharacterEquipment::itemDrop(InventoryCell *cell, Item::Slots searchedSlot)
{
    if(cell->acceptedSlot == searchedSlot){
        if(cell->getIsLocked() && !cell->getIsManualLock()){
            emit moveCellFromEquipment(cell->getCellWithLockingItem());

            return true;
        }
    }

    return false;
}

bool CharacterEquipment::checkingLockedCells(QVector<Item::Slots> occupiedCellSlots)
{
    bool ItemsHaveBeenDropped = false;

    QVectorIterator<Item::Slots> iterator(occupiedCellSlots);
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        if(searchedSlot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_GLOVE);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_GLOVE);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_SHOULDER){
            InventoryCell* rightCell = bothShoulders.getRightCell();
            InventoryCell* leftCell = bothShoulders.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_SHOULDER);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_SHOULDER);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_BRACE){
            InventoryCell* rightCell = bothBraces.getRightCell();
            InventoryCell* leftCell = bothBraces.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_BRACE);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_BRACE);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_GAUNTLET){
            InventoryCell* rightCell = bothGauntlets.getRightCell();
            InventoryCell* leftCell = bothGauntlets.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_GAUNTLET);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_GAUNTLET);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_GREAVE){
            InventoryCell* rightCell = bothGreaves.getRightCell();
            InventoryCell* leftCell = bothGreaves.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_GREAVE);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_GREAVE);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_BOOT){
            InventoryCell* rightCell = bothBoots.getRightCell();
            InventoryCell* leftCell = bothBoots.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_BOOT);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_BOOT);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_HAND){
            InventoryCell* rightCell = bothHands.getRightCell();
            InventoryCell* leftCell = bothHands.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_HAND);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_HAND);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_DECORATION){
            InventoryCell* rightCell = bothDecorations.getRightCell();
            InventoryCell* leftCell = bothDecorations.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_DECORATION);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_DECORATION);
            }
        }else{
            for(InventoryCell* cell : equipmentCells){
                ItemsHaveBeenDropped = itemDrop(cell, searchedSlot);
            }
        }
    }

    return ItemsHaveBeenDropped;
}

