/**********************************************************************************************************************
 *Данный класс является экиперовкой персонажа с "куклой", на которую одеваются различные итемы. У экиперовки
 *есть 3 слоя: под доспехом, доспех и над доспехом. Нажатием с зажатым шифтом из виджета инвентаря можно быстро
 *экиперовывать итемы на куклу и также сбрасывать назад в инвентарь. Если начать перетаскивать итем, то на кукле
 *загорятся доступные к экиперовке ячейки для этой вещи.
 **********************************************************************************************************************/

#include "characterequipment.h"
#include "ui_characterequipment.h"

CharacterEquipment::CharacterEquipment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterEquipment)
{
    ui->setupUi(this);

    connect(ui->weaponGripButton, &WeaponGripButton::takeTwoHandedGripRightHandItem, this, &CharacterEquipment::takeTwoHandedGripRightHandItem);
    connect(ui->weaponGripButton, &WeaponGripButton::takeTwoHandedGripLeftHandItem, this, &CharacterEquipment::takeTwoHandedGripLeftHandItem);
    connect(ui->weaponGripButton, &WeaponGripButton::useOneHandedGrip, this, &CharacterEquipment::useOneHandedGrip);
    connect(ui->weaponGripButton, &WeaponGripButton::checkFreeHands, this, &CharacterEquipment::checkFreeHands);
    connect(ui->weaponGripButton, &WeaponGripButton::checkBusyHands, this, &CharacterEquipment::checkBusyHands);

    //Забивается вектор всех ячеек
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
        connect(cell, &InventoryCell::moveCell, this, &CharacterEquipment::moveCellFromEquipment);
        connect(cell, &InventoryCell::lockOccupiedCells, this, &CharacterEquipment::lockOccupiedCells);
        connect(cell, &InventoryCell::unlockOccupiedCells, this, &CharacterEquipment::unlockOccupiedCells);
        connect(cell, &InventoryCell::checkLockedCells, this, &CharacterEquipment::checkingLockedCells);
        connect(cell, &InventoryCell::dragStarted, this, &CharacterEquipment::dragStarted);
        connect(cell, &InventoryCell::dragEnded, this, &CharacterEquipment::dragEnded);
        connect(cell, &InventoryCell::reviseItemPositionInEquipment, this, &CharacterEquipment::reviseItemPositionInEquipment);
        connect(cell, &InventoryCell::switchEquipmentLayer, this, &CharacterEquipment::switchEquipmentLayer);
        connect(cell, &InventoryCell::applyGrip, this, &CharacterEquipment::applyGrip);
        connect(cell, &InventoryCell::checkUsedTwoHandedGrip, this, &CharacterEquipment::checkUsedTwoHandedGrip);
        connect(cell, &InventoryCell::checkUsedOneHandedGrip, this, &CharacterEquipment::checkUsedOneHandedGrip);
    }

    for(QObject* inventoryCell : ui->OverArmor->children()){
        if(dynamic_cast <InventoryCell*> (inventoryCell)){
            InventoryCell* cell = qobject_cast <InventoryCell*> (inventoryCell);
            cell->equipmentLayer = InventoryCell::OVER_ARMOR;
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                    "CharacterEquipment выдал предупреждение в методе CharacterEquipment.\n"
                    "Объект " + inventoryCell->objectName() + " не является InventoryCell.\n\n";
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

    for(QObject* inventoryCell : ui->Armor->children()){
        if(dynamic_cast <InventoryCell*> (inventoryCell)){
            InventoryCell* cell = qobject_cast <InventoryCell*> (inventoryCell);
            cell->equipmentLayer = InventoryCell::ARMOR;
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                    "CharacterEquipment выдал предупреждение в методе CharacterEquipment.\n"
                    "Объект " + inventoryCell->objectName() + " не является InventoryCell.\n\n";
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

    for(QObject* inventoryCell : ui->UnderArmor->children()){
        if(dynamic_cast <InventoryCell*> (inventoryCell)){
            InventoryCell* cell = qobject_cast <InventoryCell*> (inventoryCell);
            cell->equipmentLayer = InventoryCell::UNDER_ARMOR;
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                    "CharacterEquipment выдал предупреждение в методе CharacterEquipment.\n"
                    "Объект " + inventoryCell->objectName() + " не является InventoryCell.\n\n";
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

    //Некоторые из ячеек представляют собой ячейки-списки, которые можно развернуть. У этих ячеек активируется кнопка отображения списка
    ui->RightDecoration->setDropdownButtonVisible(true);
    ui->LeftDecoration->setDropdownButtonVisible(true);
    ui->Bag->setDropdownButtonVisible(true);
    ui->Necklace->setDropdownButtonVisible(true);

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

/*Функция поиска первой подходящей ячейки по переданому вектору слотов экиперовки. Переменная
 *findCellAnyway заставляет возвращать ячейку даже если все подходящие заняты*/
InventoryCell *CharacterEquipment::findCell(QVector<Item::Slots> itemSlots, bool findCellAnyway)
{
    /*Переменная храняещее первую подходящую, но занятую ячейку экиперовки. Если все ячейки окажутся
     *занятыми, будет возвращено первое нахождение. Работает только при findCellAnyway = true*/
    InventoryCell* firstMatch = nullptr;

    QVectorIterator<Item::Slots> iterator(itemSlots);
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        for(InventoryCell* cell : equipmentCells){
            if(cell->acceptedSlot == searchedSlot){
                //Если найдена свободная незаблокированая ячейка, то она сразу возвращается
                if(cell->getItem()->itemIsEmpty && !cell->getIsLocked())
                    return cell;
                /*Иначе если если нужно найти ячейку в любом случае, то сохраняется первое
                 *нахождение, при условии что это не вручную заблокированая ячейка*/
                else if(firstMatch == nullptr && findCellAnyway && !cell->getIsManualLock())
                    firstMatch = cell;
            }
        }
    }
    //Если найдена ячейка, которую блокирует другой итем, то этот итем сбрасывается
    if(firstMatch->getCellWithLockingItem()!=nullptr)
        emit moveCellFromEquipment(firstMatch->getCellWithLockingItem(), false);
    /*Если программа дошла до сюда, то возвращается первое нахождение. Стоит учитывать,
     *что возможен возврат ячейки равной nullptr, если ничего найдено небыло*/
    return firstMatch;
}

/*Метод, блокирующий указанные в итеме из cell ячейки переданной ячейкой с итемом. Это необходимо, например, когда итем занимает сразу несколько слотов.
 *Также передаётся слот ячейки из которой был произведён запрос на блокирование итемов, чтобы вызывающая ячейка не могла заблокировать саму себя.*/
void CharacterEquipment::lockOccupiedCells (InventoryCell* cell, Item::Slots acceptedSlot)
{
    QVector<Item::Slots> occupiedSlots = QVector<Item::Slots>(cell->getItem()->getOccupiedCellSlots());

    //Из занимаемых слотов удаляется слот той ячейки, из которой произошёл вызов для предотвращения возможности итема заблокировать самого себя
    QMutableVectorIterator<Item::Slots> iterator(occupiedSlots);
    while (iterator.hasNext()){
        if(iterator.next() == acceptedSlot){
            iterator.remove();
            break;
        }
    }

    for(Item::Slots slot : occupiedSlots){
        //Если слот указан как один из пары, то происходит блок ячейки с преоритетом на левую ячейку пары
        if(slot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            //Левая ячейка блокируется либо если она просто пуста, либо если обе ячейки не пусты, при условии что левая ячейка не заблокирует саму себя
            if(leftCell->getItem()->itemIsEmpty || (!leftCell->getItem()->itemIsEmpty && leftCell!=cell && !rightCell->getItem()->itemIsEmpty)){
                leftCell->setLockedStyle(true, cell);
                //Если ячейка не была пуста, то происходит сброс итема из блокируемой ячейки
                if(!leftCell->getItem()->itemIsEmpty)
                    emit moveCellFromEquipment(leftCell, false);
            }else{
                rightCell->setLockedStyle(true, cell);
                if(!rightCell->getItem()->itemIsEmpty)
                    //Если ячейка не была пуста, то происходит сброс итема из блокируемой ячейки
                    emit moveCellFromEquipment(rightCell, false);
            }
            //Ниже всё тоже самое
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
            //Если слот не был парным, то происходит обычный поиск по всем ячейкам экиперовки
            for(InventoryCell* destinationCell : equipmentCells){
                if(destinationCell->acceptedSlot == slot){
                    if(!destinationCell->getItem()->itemIsEmpty)
                        //Если ячейка не была пуста, то происходит сброс итема из блокируемой ячейки
                        emit moveCellFromEquipment(destinationCell, false);
                    destinationCell->setLockedStyle(true, cell);
                }
            }
        }
    }

    if(cell->getIsTakenInTwoHandedGrip()){
        if(ui->RightHand == cell)
            ui->LeftHand->setLockedStyle(true, cell);
        else if(ui->LeftHand == cell)
            ui->RightHand->setLockedStyle(true, cell);
    }
}

//Метод разблокирующий все блокируемые ячейки из вектора занимаемых ячеек из итема из cell
void CharacterEquipment::unlockOccupiedCells(InventoryCell* cell)
{
    QVector<Item::Slots> oldOccupiedSlots = QVector<Item::Slots>(cell->getItem()->getOccupiedCellSlots());

    for(Item::Slots slot : oldOccupiedSlots){
        //Если слот указан как парный то ищется какая ячейка из пары была заблокирована
        if(slot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            //Ячейки разблокируются только если они были заблокированы итемом, а не вручную
            if(!rightCell->getIsManualLock() && rightCell->getCellWithLockingItem() == cell){
                rightCell->setLockedStyle(false);
            }else if(!leftCell->getIsManualLock() && leftCell->getCellWithLockingItem() == cell){
                leftCell->setLockedStyle(false);
            }
            //Ниже всё тоже самое
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
                //Ячейки разблокируются только если они были заблокированы итемом, а не вручную
                if(cell->acceptedSlot == slot && !cell->getIsManualLock()){
                    cell->setLockedStyle(false);
                }
            }
        }
    }

    if(cell->getIsTakenInTwoHandedGrip()){
        if(ui->RightHand->getCellWithLockingItem() == ui->LeftHand)
            ui->RightHand->setLockedStyle(false);
        else if(ui->LeftHand->getCellWithLockingItem() == ui->RightHand)
            ui->LeftHand->setLockedStyle(false);
    }
}

//Метод устанавливающий всем ячейкам экиперовки соответствующие слоты и подложки
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
    ui->LeftHand->isHand = true;
    ui->RightDecoration->acceptedSlot = Item::Slots::R_DECORATION;
    ui->RightHand->acceptedSlot = Item::Slots::R_HAND;
    ui->RightHand->isHand = true;

    //Задание всех пар слотов
    bothGloves = PairCells(ui->RightGlove, ui->LeftGlove);
    bothPauldrons = PairCells(ui->RightPauldron, ui->LeftPauldron);
    bothBraces = PairCells(ui->RightBrace, ui->LeftBrace);
    bothGauntlets = PairCells(ui->RightGauntlet, ui->LeftGauntlet);
    bothGreaves = PairCells(ui->RightGreave, ui->LeftGreave);
    bothBoots = PairCells(ui->RightBoot, ui->LeftBoot);
    bothHands = PairCells(ui->RightHand, ui->LeftHand);
    bothDecorations = PairCells(ui->RightDecoration, ui->LeftDecoration);
}

//Метод, сбрасывающий блокирующий переданую ячейку итем, если она соответствует переданому слоту. Метод возвращает был ли выполнен сброс
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

/*Метод, проверяющий есль ли среди ячеек соответствующих переданым слотам ячйки заблокированые другими итемами. Если
 *такие ячейки находятся, то итем блокирующий их сбрасывается. Метод возвращает true если был сброшен хотя бы 1 итем*/
bool CharacterEquipment::checkingLockedCells(QVector<Item::Slots> occupiedCellSlots)
{
    bool ItemsHaveBeenDropped = false;
    bool ItemsHaveBeenDroppedBuf = false;

    QVectorIterator<Item::Slots> iterator(occupiedCellSlots);
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        if(searchedSlot == Item::ONE_OF_THE_GLOVE){
            InventoryCell* rightCell = bothGloves.getRightCell();
            InventoryCell* leftCell = bothGloves.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_GLOVE, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_GLOVE, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_PAULDRON){
            InventoryCell* rightCell = bothPauldrons.getRightCell();
            InventoryCell* leftCell = bothPauldrons.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_PAULDRON, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_PAULDRON, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_BRACE){
            InventoryCell* rightCell = bothBraces.getRightCell();
            InventoryCell* leftCell = bothBraces.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_BRACE, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_BRACE, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_GAUNTLET){
            InventoryCell* rightCell = bothGauntlets.getRightCell();
            InventoryCell* leftCell = bothGauntlets.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_GAUNTLET, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_GAUNTLET, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_GREAVE){
            InventoryCell* rightCell = bothGreaves.getRightCell();
            InventoryCell* leftCell = bothGreaves.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_GREAVE, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_GREAVE, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_BOOT){
            InventoryCell* rightCell = bothBoots.getRightCell();
            InventoryCell* leftCell = bothBoots.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_BOOT, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_BOOT, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_HAND){
            InventoryCell* rightCell = bothHands.getRightCell();
            InventoryCell* leftCell = bothHands.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_HAND, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_HAND, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else if(searchedSlot == Item::ONE_OF_THE_DECORATION){
            InventoryCell* rightCell = bothDecorations.getRightCell();
            InventoryCell* leftCell = bothDecorations.getLeftCell();
            if(rightCell->getIsLocked() && !rightCell->getIsManualLock()){
                ItemsHaveBeenDroppedBuf = itemDrop(rightCell, Item::R_DECORATION, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }else{
                ItemsHaveBeenDroppedBuf = itemDrop(leftCell, Item::L_DECORATION, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }else{
            for(InventoryCell* cell : equipmentCells){
                ItemsHaveBeenDroppedBuf = itemDrop(cell, searchedSlot, false);
                if(!ItemsHaveBeenDropped)
                    ItemsHaveBeenDropped = ItemsHaveBeenDroppedBuf;
            }
        }
    }

    return ItemsHaveBeenDropped;
}

//Слот, вызаваемый при начале перетаскивания любого итема. Подсвечивает все ячейки, в который данный итем можно положить
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

//Слот, вызаваемый при окончании перетаскивания любого итема. Гасит посвеченые ячейки
void CharacterEquipment::dragEnded()
{
    for(InventoryCell* equipmentCell : equipmentCells){
        if(equipmentCell->getIsAvailable())
            equipmentCell->setAvailableStyle(false);
    }
}

void CharacterEquipment::takeTwoHandedGripRightHandItem()
{
    if(!ui->RightHand->getItem()->itemIsEmpty && ui->RightHand->getItem()->getIsWeaponOrShield()){
        if(!ui->LeftHand->getItem()->itemIsEmpty)
            emit moveCellFromEquipment(ui->LeftHand);
        ui->LeftHand->setLockedStyle(true, ui->RightHand);
        ui->RightHand->setIsTakenInTwoHandedGrip(true);
    }else if(!ui->LeftHand->getItem()->itemIsEmpty && ui->LeftHand->getItem()->getIsWeaponOrShield()){
        if(!ui->RightHand->getItem()->itemIsEmpty)
            emit moveCellFromEquipment(ui->RightHand);
        ui->RightHand->setLockedStyle(true, ui->LeftHand);
        ui->LeftHand->setIsTakenInTwoHandedGrip(true);
    }
    usedTwoHandedGrip = true;
}

void CharacterEquipment::takeTwoHandedGripLeftHandItem()
{
    if(!ui->LeftHand->getItem()->itemIsEmpty && ui->LeftHand->getItem()->getIsWeaponOrShield()){
        if(!ui->RightHand->getItem()->itemIsEmpty)
            emit moveCellFromEquipment(ui->RightHand);
        ui->RightHand->setLockedStyle(true, ui->LeftHand, false);
        ui->LeftHand->setIsTakenInTwoHandedGrip(true);
    }else if(!ui->RightHand->getItem()->itemIsEmpty && ui->RightHand->getItem()->getIsWeaponOrShield()){
        if(!ui->LeftHand->getItem()->itemIsEmpty)
            emit moveCellFromEquipment(ui->LeftHand);
        ui->LeftHand->setLockedStyle(true, ui->RightHand);
        ui->RightHand->setIsTakenInTwoHandedGrip(true);
    }
    usedTwoHandedGrip = true;
}

void CharacterEquipment::useOneHandedGrip()
{
    if(ui->RightHand->getIsLocked()){
        if(ui->RightHand->getCellWithLockingItem() == ui->LeftHand && ui->LeftHand->getIsTakenInTwoHandedGrip()){
            for(Item::Slots slot : ui->LeftHand->getItem()->getOccupiedCellSlots())
                if(slot == Item::ONE_OF_THE_HAND || slot == Item::R_HAND || slot == Item::L_HAND)
                    return;
            ui->RightHand->setLockedStyle(false);
            ui->LeftHand->setIsTakenInTwoHandedGrip(false);
        }
    }else if(ui->LeftHand->getIsLocked()){
        if(ui->LeftHand->getCellWithLockingItem() == ui->RightHand && ui->RightHand->getIsTakenInTwoHandedGrip()){
            for(Item::Slots slot : ui->RightHand->getItem()->getOccupiedCellSlots())
                if(slot == Item::ONE_OF_THE_HAND || slot == Item::R_HAND || slot == Item::L_HAND)
                    return;
            ui->LeftHand->setLockedStyle(false);
            ui->RightHand->setIsTakenInTwoHandedGrip(false);
        }
    }
    usedTwoHandedGrip = false;
}

bool CharacterEquipment::checkFreeHands(bool isRightHand)
{
    if(ui->RightHand->getItem()->itemIsEmpty && !ui->LeftHand->getItem()->itemIsEmpty)
        if(!ui->LeftHand->getItem()->getTwoHandedGripAllowed())
            return false;
    if(!ui->RightHand->getItem()->itemIsEmpty && ui->LeftHand->getItem()->itemIsEmpty)
        if(!ui->RightHand->getItem()->getTwoHandedGripAllowed())
            return false;
    if(isRightHand){
        if(!ui->RightHand->getItem()->itemIsEmpty && !ui->RightHand->getItem()->getTwoHandedGripAllowed())
            return false;
    }else if(!ui->LeftHand->getItem()->itemIsEmpty && !ui->LeftHand->getItem()->getTwoHandedGripAllowed())
        return false;

    return (!ui->LeftHand->getIsLocked()&&!ui->RightHand->getIsLocked());
}

bool CharacterEquipment::checkBusyHands()
{
    if(ui->RightHand->getCellWithLockingItem() == ui->LeftHand)
        if(!ui->LeftHand->getItem()->getOneHandedGripAllowed())
            return false;
    if(ui->LeftHand->getCellWithLockingItem() == ui->RightHand)
        if(!ui->RightHand->getItem()->getOneHandedGripAllowed())
            return false;
    for(Item::Slots slot : ui->LeftHand->getItem()->getOccupiedCellSlots())
        if(slot == Item::ONE_OF_THE_HAND || slot == Item::R_HAND || slot == Item::L_HAND)
            return false;
    for(Item::Slots slot : ui->RightHand->getItem()->getOccupiedCellSlots())
        if(slot == Item::ONE_OF_THE_HAND || slot == Item::R_HAND || slot == Item::L_HAND)
            return false;
    return true;
}

void CharacterEquipment::applyGrip(InventoryCell *cell)
{
    if(!cell->getItem()->getOneHandedGripAllowed()){
        ui->weaponGripButton->setTwoHandedGrip();
        usedTwoHandedGrip = true;
    }
    if(!cell->getItem()->getTwoHandedGripAllowed()){
        ui->weaponGripButton->setOneHandedGrip();
        usedTwoHandedGrip = false;
    }

    if(usedTwoHandedGrip)
        takeTwoHandedGripRightHandItem();
    else
        useOneHandedGrip();
}

void CharacterEquipment::switchEquipmentLayer(InventoryCell::EquipmentLayer equipmentLayer)
{
    if(equipmentLayer == InventoryCell::OVER_ARMOR)
        ui->CellsStackedWidget->setCurrentIndex(2);
    else if(equipmentLayer == InventoryCell::ARMOR)
        ui->CellsStackedWidget->setCurrentIndex(1);
    else if(equipmentLayer == InventoryCell::UNDER_ARMOR)
        ui->CellsStackedWidget->setCurrentIndex(0);
}

void CharacterEquipment::checkUsedTwoHandedGrip(InventoryCell *cell)
{
    QVectorIterator<Item::Slots> iterator(cell->getItem()->getOccupiedCellSlots());
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        if(searchedSlot == Item::ONE_OF_THE_HAND){
            if(usedTwoHandedGrip){
                ui->weaponGripButton->setOneHandedGrip();
            }
        }else{
            for(InventoryCell* cell : equipmentCells){
                if(cell->acceptedSlot == Item::R_HAND || cell->acceptedSlot == Item::L_HAND){
                    if(usedTwoHandedGrip){
                        ui->weaponGripButton->setOneHandedGrip();
                    }
                }
            }
        }
    }
}

void CharacterEquipment::checkUsedOneHandedGrip(InventoryCell *cell)
{
    if(!cell->getItem()->getOneHandedGripAllowed()){
        if(!ui->RightHand->getItem()->itemIsEmpty && ui->RightHand!=cell)
            emit moveCellFromEquipment(ui->RightHand, false);
        else if(ui->RightHand->getIsLocked() && ui->RightHand->getCellWithLockingItem() != ui->LeftHand)
            emit moveCellFromEquipment(ui->RightHand->getCellWithLockingItem(), false);
        if(!ui->LeftHand->getItem()->itemIsEmpty && ui->LeftHand!=cell)
            emit moveCellFromEquipment(ui->LeftHand, false);
        else if(ui->LeftHand->getIsLocked() && ui->LeftHand->getCellWithLockingItem() != ui->RightHand)
            emit moveCellFromEquipment(ui->LeftHand->getCellWithLockingItem(), false);
    }
    QVectorIterator<Item::Slots> iterator(cell->getItem()->getOccupiedCellSlots());
    while (iterator.hasNext()){
        Item::Slots searchedSlot = iterator.next();
        if(searchedSlot == Item::R_HAND || searchedSlot == Item::L_HAND || searchedSlot == Item::ONE_OF_THE_HAND){
            if(ui->RightHand->getIsLocked() && ui->RightHand->getCellWithLockingItem() != ui->LeftHand)
                emit moveCellFromEquipment(ui->RightHand->getCellWithLockingItem(), false);
            if(ui->LeftHand->getIsLocked() && ui->LeftHand->getCellWithLockingItem() != ui->RightHand)
                emit moveCellFromEquipment(ui->LeftHand->getCellWithLockingItem(), false);

            if(!usedTwoHandedGrip){
                ui->weaponGripButton->setTwoHandedGrip();
            }
            break;
        }
    }
}
