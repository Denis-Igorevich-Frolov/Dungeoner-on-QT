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
        connect(cell, &InventoryCell::dragStarted, this, &CharacterEquipment::dragStarted);
        connect(cell, &InventoryCell::dragEnded, this, &CharacterEquipment::dragEnded);
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

InventoryCell *CharacterEquipment::findCell(QVector<Item::Slots> itemSlots, bool findCellAnyway)
{
    InventoryCell* firstMatch = nullptr;

    QVectorIterator<Item::Slots> iterator(itemSlots);
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        for(InventoryCell* cell : equipmentCells){
            if(cell->acceptedSlot == searchedSlot){
                if(cell->getItem()->itemIsEmpty && !cell->getIsLocked())
                    return cell;
                else if(firstMatch == nullptr && findCellAnyway)
                    firstMatch = cell;
            }
        }
    }
    if(firstMatch->getCellWithLockingItem()!=nullptr)
        emit moveCellFromEquipment(firstMatch->getCellWithLockingItem(), false);
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
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_PAULDRON){
            InventoryCell* rightCell = bothPauldrons.getRightCell();
            InventoryCell* leftCell = bothPauldrons.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_BRACE){
            InventoryCell* rightCell = bothBraces.getRightCell();
            InventoryCell* leftCell = bothBraces.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_GAUNTLET){
            InventoryCell* rightCell = bothGauntlets.getRightCell();
            InventoryCell* leftCell = bothGauntlets.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_GREAVE){
            InventoryCell* rightCell = bothGreaves.getRightCell();
            InventoryCell* leftCell = bothGreaves.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_BOOT){
            InventoryCell* rightCell = bothBoots.getRightCell();
            InventoryCell* leftCell = bothBoots.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_HAND){
            InventoryCell* rightCell = bothHands.getRightCell();
            InventoryCell* leftCell = bothHands.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else if(slot == Item::ONE_OF_THE_DECORATION){
            InventoryCell* rightCell = bothDecorations.getRightCell();
            InventoryCell* leftCell = bothDecorations.getLeftCell();
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(rightCell, false);
            }
        }else{
            for(InventoryCell* destinationCell : equipmentCells){
                if(destinationCell->acceptedSlot == slot){
                    if(!destinationCell->getItem()->itemIsEmpty)
                        emit moveCellFromEquipment(destinationCell, false);
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
        if(slot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
        }else if(slot == Item::ONE_OF_THE_PAULDRON){
            InventoryCell* rightCell = bothPauldrons.getRightCell();
            InventoryCell* leftCell = bothPauldrons.getLeftCell();
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
    ui->Arrows->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Bow.png"));
    ui->Bag->acceptedSlot = Item::Slots::BAG;
    ui->Bag->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Bag.png"));
    ui->Bolts->acceptedSlot = Item::Slots::BOLTS;
    ui->Bolts->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Crossbow.png"));
    ui->Bullets->acceptedSlot = Item::Slots::BULLETS;
    ui->Bullets->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Pistol-Muzzle.png"));
    ui->Breastplate->acceptedSlot = Item::Slots::BREASTPLATE;
    ui->Gorget->acceptedSlot = Item::Slots::GORGET;
    ui->Gorget->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Neck.png"));
    ui->Helmet->acceptedSlot = Item::Slots::HELMET;
    ui->Helmet->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Head.png"));
    ui->LeftBoot->acceptedSlot = Item::Slots::L_BOOT;
    ui->LeftBoot->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-L-Foot.png"));
    ui->LeftGauntlet->acceptedSlot = Item::Slots::L_GAUNTLET;
    ui->LeftGauntlet->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-L-Hand.png"));
    ui->LeftGreave->acceptedSlot = Item::Slots::L_GREAVE;
    ui->LeftGreave->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-L-Knee.png"));
    ui->LeftPauldron->acceptedSlot = Item::Slots::L_PAULDRON;
    ui->LeftPauldron->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-L-Shoulder.png"));
    ui->LeftBrace->acceptedSlot = Item::Slots::L_BRACE;
    ui->LeftBrace->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-L-Forearm.png"));
    ui->RightBoot->acceptedSlot = Item::Slots::R_BOOT;
    ui->RightBoot->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-R-Foot.png"));
    ui->RightBrace->acceptedSlot = Item::Slots::R_BRACE;
    ui->RightBrace->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-R-Forearm.png"));
    ui->RightGauntlet->acceptedSlot = Item::Slots::R_GAUNTLET;
    ui->RightGauntlet->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-R-Hand.png"));
    ui->RightGreave->acceptedSlot = Item::Slots::R_GREAVE;
    ui->RightGreave->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-R-Knee.png"));
    ui->RightPauldron->acceptedSlot = Item::Slots::R_PAULDRON;
    ui->RightPauldron->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-R-Shoulder.png"));
    ui->Cap->acceptedSlot = Item::Slots::CAP;
    ui->Cap->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Head.png"));
    ui->Cloak->acceptedSlot = Item::Slots::CLOAK;
    ui->Cloak->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Cloak.png"));
    ui->Mantle->acceptedSlot = Item::Slots::MANTLE;
    ui->BalaclavaHelmet->acceptedSlot = Item::Slots::BALACLAVA_HELMET;
    ui->BalaclavaHelmet->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Head.png"));
    ui->Clothes->acceptedSlot = Item::Slots::CLOTHES;
    ui->LeftGlove->acceptedSlot = Item::Slots::L_GLOVE;
    ui->LeftGlove->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-L-Hand.png"));
    ui->Pants->acceptedSlot = Item::Slots::PANTS;
    ui->RightGlove->acceptedSlot = Item::Slots::R_GLOVE;
    ui->RightGlove->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-R-Hand.png"));
    ui->Gunpowder->acceptedSlot = Item::Slots::GUNPOWDER;
    ui->Gunpowder->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Pistol-Grip.png"));
    ui->LeftDecoration->acceptedSlot = Item::Slots::L_DECORATION;
    ui->LeftHand->acceptedSlot = Item::Slots::L_HAND;
    ui->LeftHand->setSubstrateDollsPixmap(QPixmap(":/Substrate-Dolls/Textures PNG/Substrate-Dolls-Piece-Of-Cloak.png"));
    ui->RightDecoration->acceptedSlot = Item::Slots::R_DECORATION;
    ui->RightHand->acceptedSlot = Item::Slots::R_HAND;

    bothGloves = PairCells(ui->RightGlove, ui->LeftGlove);
    bothPauldrons = PairCells(ui->RightPauldron, ui->LeftPauldron);
    bothBraces = PairCells(ui->RightBrace, ui->LeftBrace);
    bothGauntlets = PairCells(ui->RightGauntlet, ui->LeftGauntlet);
    bothGreaves = PairCells(ui->RightGreave, ui->LeftGreave);
    bothBoots = PairCells(ui->RightBoot, ui->LeftBoot);
    bothHands = PairCells(ui->RightHand, ui->LeftHand);
    bothDecorations = PairCells(ui->RightDecoration, ui->LeftDecoration);
}

bool CharacterEquipment::itemDrop(InventoryCell *cell, Item::Slots searchedSlot, bool playSound)
{
    if(cell->acceptedSlot == searchedSlot){
        if(cell->getIsLocked() && !cell->getIsManualLock()){
            emit moveCellFromEquipment(cell->getCellWithLockingItem(), playSound);

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
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_GLOVE, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_GLOVE, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_PAULDRON){
            InventoryCell* rightCell = bothPauldrons.getRightCell();
            InventoryCell* leftCell = bothPauldrons.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_PAULDRON, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_PAULDRON, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_BRACE){
            InventoryCell* rightCell = bothBraces.getRightCell();
            InventoryCell* leftCell = bothBraces.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_BRACE, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_BRACE, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_GAUNTLET){
            InventoryCell* rightCell = bothGauntlets.getRightCell();
            InventoryCell* leftCell = bothGauntlets.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_GAUNTLET, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_GAUNTLET, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_GREAVE){
            InventoryCell* rightCell = bothGreaves.getRightCell();
            InventoryCell* leftCell = bothGreaves.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_GREAVE, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_GREAVE, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_BOOT){
            InventoryCell* rightCell = bothBoots.getRightCell();
            InventoryCell* leftCell = bothBoots.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_BOOT, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_BOOT, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_HAND){
            InventoryCell* rightCell = bothHands.getRightCell();
            InventoryCell* leftCell = bothHands.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_HAND, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_HAND, false);
            }
        }else if(searchedSlot == Item::ONE_OF_THE_DECORATION){
            InventoryCell* rightCell = bothDecorations.getRightCell();
            InventoryCell* leftCell = bothDecorations.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDropped = itemDrop(rightCell, Item::R_DECORATION, false);
            }else{
                ItemsHaveBeenDropped = itemDrop(leftCell, Item::L_DECORATION, false);
            }
        }else{
            for(InventoryCell* cell : equipmentCells){
                bool ItemsHaveBeenDroppedBuf = itemDrop(cell, searchedSlot, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }
    }

    return ItemsHaveBeenDropped;
}

void CharacterEquipment::dragStarted(QVector<Item::Slots> cellSlots)
{
    for(Item::Slots cellSlot : cellSlots){
        for(InventoryCell* equipmentCell : equipmentCells){
            if(equipmentCell->acceptedSlot == cellSlot){
                equipmentCell->setAvailableStyle(true);
                break;
            }
        }
    }
}

void CharacterEquipment::dragEnded()
{
    for(InventoryCell* equipmentCell : equipmentCells){
        if(equipmentCell->getIsAvailable())
            equipmentCell->setAvailableStyle(false);
    }
}

