/********************************************************************************************
 *Данный класс является виджетом ячейки инвентаря, где хранятся любые итемы инвентаря.
 ********************************************************************************************/

#include "CustomWidgets/Item/itemmimedata.h"
#include "IC_stylemaster.h"

#include "inventorycell.h"
#include "qevent.h"
#include "qpainter.h"
#include "ui_inventorycell.h"

#include <QDrag>
#include <QMimeData>

InventoryCell::InventoryCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryCell)
{
    ui->setupUi(this);

    ui->item->getItemButton()->installEventFilter(this);
    ui->item->getStyleButtonsWrapper()->installEventFilter(this);

    connect(ui->item, &Item::moveItem, this, &InventoryCell::moveItem);
    connect(ui->item, &Item::styleRemoved, this, &InventoryCell::styleRemoved);
    connect(ui->item, &Item::styleAssigned, this, &InventoryCell::styleAssigned);

    setDropdownButtonVisible(false);
    ui->SubstrateDolls->setVisible(false);

    QSizePolicy sp_retain = sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    setSizePolicy(sp_retain);

    setAutoStyle();
    ui->item->setStyleButtonsStyle();
    ui->item->setCursor(QCursor(Qt::ArrowCursor));
    setAcceptDrops(true);

    ui->item->itemIsEmpty = true;
}

InventoryCell::~InventoryCell()
{
    delete ui;
}

void InventoryCell::setItem(Item *item)
{
    ui->item->setId(item->getId());
    ui->item->itemIsEmpty = item->itemIsEmpty;
    ui->item->folderName = item->folderName;
    ui->item->isNew = item->isNew;
    ui->item->isDisabled = item->isDisabled;
    ui->item->styles = item->styles;
    ui->item->isPressable = item->isPressable;
    ui->item->itemTypes = item->itemTypes;
    ui->item->bonuses = item->bonuses;
    ui->item->magicDefenseBonuses = item->magicDefenseBonuses;
    ui->item->image = item->image;
    ui->item->hoverColor = item->hoverColor;
    ui->item->pressedColor = item->pressedColor;
    ui->item->disabledColor = item->disabledColor;
    ui->item->brokenColor = item->brokenColor;
    ui->item->setWeight(item->getWeight());
    ui->item->setVolume(item->getVolume());
    ui->item->setPrice(item->getPrice());
    ui->item->setItemName(item->getItemName());
    ui->item->setMaxDurability(item->getMaxDurability());
    ui->item->setCurrentDurability(item->getCurrentDurability());
    ui->item->setDamage(item->getMinDamage(), item->getMaxDamage());
    ui->item->setQuantity(item->getQuantity());
    ui->item->setCellSlots(item->getCellSlots(), item->getOccupiedCellSlots());
    ui->item->setCurrentStyle(item->getCurrentStyle());
    ui->item->setMaxCharges(item->getMaxCharges());
    ui->item->setCurrentCharges(item->getCurrentCharges());
    ui->item->SoundDrag = item->SoundDrag;
    ui->item->SoundDrop = item->SoundDrop;
    ui->item->SoundPress = item->SoundPress;
    ui->item->SoundPressWithOutOfCharge = item->SoundPressWithOutOfCharge;

    ui->item->setShadow(item->hasShadow, item->shadowBlurRadius, item->shadowXOffset, item->shadowYOffset);
    ui->item->itemIsEmpty = item->itemIsEmpty;
    ui->item->setStyleButtonsStyle();

    setAutoStyle();

    if(ui->item->getId()!=-1)
        ui->item->setCursor(QCursor(Qt::PointingHandCursor));
    else
        ui->item->setCursor(QCursor(Qt::ArrowCursor));
}

Item *InventoryCell::getItem()
{
    return ui->item;
}

//Метод, выставляющий стиль автоматически исходя из характеристик предмета
void InventoryCell::setAutoStyle()
{
    if(isAvailable)
        setAvailableStyle(true);
    else if(isLocked)
        setLockedStyle(true, cellWithLockingItem);
    //id -1 только у пустого неинициализированного предмета
    else if(ui->item->getId() == -1)
        setEmptyStyle();
    else if(ui->item->isNew && ui->item->isDisabled && ui->item->getIsBroken())
        setDisabledBrokenNewStyle();
    else if(ui->item->isNew && ui->item->isDisabled)
        setDisabledNewStyle();
    else if(ui->item->isNew && ui->item->getIsBroken())
        setBrokenNewStyle();
    else if(ui->item->isNew)
        setNewStyle();
    else if(ui->item->isDisabled && ui->item->getIsBroken())
        setDisabledBrokenStyle();
    else if(ui->item->isDisabled)
        setDisabledStyle();
    else if(ui->item->getIsBroken())
        setBrokenStyle();
    else
        setNoEmptyStyle();

    if(ui->item->getId()!=-1)
        ui->item->setCursor(QCursor(Qt::PointingHandCursor));
    else
        ui->item->setCursor(QCursor(Qt::ArrowCursor));
}

//Стиль пустой ячейки
void InventoryCell::setEmptyStyle()
{
    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Задний фон и лейбл заблокированной ячейки не участвуют в этом стиле, так что их следует скрыть
    ui->inventoryCellBG->setVisible(false);
    ui->Locked->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    ui->SubstrateDolls->setVisible(true);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(IC_stylemaster::centralElementStyle());
    ui->CentralElement->setVisible(CentralElementIsVisible);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 56);
}

//Стиль ячейки с предметом
void InventoryCell::setNoEmptyStyle()
{
    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    ui->SubstrateDolls->setVisible(true);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::notEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::notEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

//Стиль ячейки с новым предметом
void InventoryCell::setNewStyle()
{
    inventoryCellNew.stop();
    //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Включается отображение анимации ячейки с новым предметом
    ui->inventoryCellNew->setVisible(true);
    inventoryCellNew.setFileName(":/Inventory/GIF/InventoryItemNew.gif");
    inventoryCellNew.setScaledSize(QSize(68,68));
    ui->inventoryCellNew->setMovie(&inventoryCellNew);
    inventoryCellNew.start();
    /*Чтобы анимация не перерисовывала виджет итема с кучей эффектов, был создан лейбл оптимизации,
     *который запечатлевает Pixmap итема. Виджету итема обновляться запрещается, а вместо него
     *перисовываться будет один только Pixmap, что существенно улучшает производительность*/
    ui->ItemPixmapGrab->setPixmap(ui->item->grab());
    ui->ItemPixmapGrab->setVisible(true);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
    //Запрет обновления виджета итема для оптимизации отображения вместе с анимацией
    ui->item->setUpdatesEnabled(false);
}

//Стиль ячейки с новым заглушенным предметом
void InventoryCell::setDisabledNewStyle()
{
    inventoryCellNew.stop();
    //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Включается отображение анимации ячейки с новым предметом
    ui->inventoryCellNew->setVisible(true);
    inventoryCellNew.setFileName(":/Inventory/GIF/DisabledInventoryItemNew.gif");
    inventoryCellNew.setScaledSize(QSize(68,68));
    ui->inventoryCellNew->setMovie(&inventoryCellNew);
    inventoryCellNew.start();
    /*Чтобы анимация не перерисовывала виджет итема с кучей эффектов, был создан лейбл оптимизации,
     *который запечатлевает Pixmap итема. Виджету итема обновляться запрещается, а вместо него
     *перисовываться будет один только Pixmap, что существенно улучшает производительность*/
    ui->ItemPixmapGrab->setPixmap(ui->item->grab());
    ui->ItemPixmapGrab->setVisible(true);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(false);
    //Запрет обновления виджета итема для оптимизации отображения вместе с анимацией
    ui->item->setUpdatesEnabled(false);
}

//Стиль ячейки с новым сломанным пребметом
void InventoryCell::setBrokenNewStyle()
{
    inventoryCellNew.stop();
    //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Включается отображение анимации ячейки с новым предметом
    ui->inventoryCellNew->setVisible(true);
    inventoryCellNew.setFileName(":/Inventory/GIF/BrokenInventoryItemNew.gif");
    inventoryCellNew.setScaledSize(QSize(68,68));
    ui->inventoryCellNew->setMovie(&inventoryCellNew);
    inventoryCellNew.start();
    /*Чтобы анимация не перерисовывала виджет итема с кучей эффектов, был создан лейбл оптимизации,
     *который запечатлевает Pixmap итема. Виджету итема обновляться запрещается, а вместо него
     *перисовываться будет один только Pixmap, что существенно улучшает производительность*/
    ui->ItemPixmapGrab->setPixmap(ui->item->grab());
    ui->ItemPixmapGrab->setVisible(true);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(true);
    //Запрет обновления виджета итема для оптимизации отображения вместе с анимацией
    ui->item->setUpdatesEnabled(false);
}

//Стиль ячейки с новым заглушенным сломанным пребметом
void InventoryCell::setDisabledBrokenNewStyle()
{
    inventoryCellNew.stop();
    //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Включается отображение анимации ячейки с новым предметом
    ui->inventoryCellNew->setVisible(true);
    inventoryCellNew.setFileName(":/Inventory/GIF/DisabledBrokenInventoryItemNew.gif");
    inventoryCellNew.setScaledSize(QSize(68,68));
    ui->inventoryCellNew->setMovie(&inventoryCellNew);
    inventoryCellNew.start();
    /*Чтобы анимация не перерисовывала виджет итема с кучей эффектов, был создан лейбл оптимизации,
     *который запечатлевает Pixmap итема. Виджету итема обновляться запрещается, а вместо него
     *перисовываться будет один только Pixmap, что существенно улучшает производительность*/
    ui->ItemPixmapGrab->setPixmap(ui->item->grab());
    ui->ItemPixmapGrab->setVisible(true);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(true);
    //Запрет обновления виджета итема для оптимизации отображения вместе с анимацией
    ui->item->setUpdatesEnabled(false);
}

void InventoryCell::setCentralElementStyle(bool isVisible)
{
    CentralElementIsVisible = isVisible;
    ui->CentralElement->setVisible(isVisible);
}

void InventoryCell::setDropdownButtonVisible(bool isVisible)
{
    ui->DropdownButton->setVisible(isVisible);
}

void InventoryCell::setSubstrateDollsVisible(bool isVisible)
{
    ui->SubstrateDolls->setVisible(isVisible);
}

/*Установка подложки куклы персонажа на ячейку. Так как и маски и гифки не имеют полупрозрачности,
 *а только бинарную прозрачность, что очень некрасиво, то чтобы кукла была видна всегда на ячейке,
 *в неё помещается подложка, дублирущая необходимый фрагмент куклы*/
void InventoryCell::setSubstrateDollsPixmap(QPixmap pixmMap)
{
     ui->SubstrateDolls->setPixmap(pixmMap);
}

/*Слот связывающий сигналы moveItem и moveCell. Обычным connect это не сделать
 *так как moveCell передаёт ссылку на себя, а moveItem ничего не передаёт*/
void InventoryCell::moveItem()
{
    emit moveCell(this);
}

//Слот снимающий блокировку со всех занимаемых ячеек старого стиля итема
void InventoryCell::styleRemoved()
{
    //Переключение стилей в инвентаре ни к чему не приводит
    if(acceptedSlot != Item::INVENTORY){
        emit unlockOccupiedCells(this);
    }
}

void InventoryCell::styleAssigned()
{
    //Переключение стилей в инвентаре ни к чему не приводит
    if(acceptedSlot != Item::INVENTORY){
        /*После смены стиля предмета, он может поменять свои целевые слоты, так
         *что следует пересчитать находится ли итем всё ещй в своём слоте*/
        bool itemInItsSlot = false;
        for(Item::Slots slot : getItem()->getCellSlots()){
            if(slot == acceptedSlot){
                itemInItsSlot = true;
                break;
            }
        }
        //Если итем больше не всвоём слоте, его положение в экиперовке пересматривается
        if(!itemInItsSlot)
            emit reviseItemPositionInEquipment(this, false);

        //Для нового стиля сбрасываются все конфликтующие вещи и блокируются занимаемые ячейки
        emit checkLockedCells(getItem()->getOccupiedCellSlots());
        emit lockOccupiedCells(this, acceptedSlot);
    }
}

bool InventoryCell::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->item->getItemButton()||object == ui->item->getStyleButtonsWrapper()){

        //При наведении новый стиль пропадает
        if(event->type() == QEvent::HoverEnter||event->type() == QEvent::Enter){
            if(ui->item->isNew){
                ui->item->isNew = false;
                setAutoStyle();
            }
        }

        if(event->type() == QEvent::MouseButtonPress)
            dragStart = QCursor::pos();

        if(event->type() == QEvent::MouseMove){
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            /*Drag&Drop начинается если: итем не пуст, зажата ЛКМ и позиция курсора сдвинулась на 20 пикселей от стартовой позиции перетаскивания.
             *Посленее нужно для избежания раздражающей случайной идициации перетаскивания во время обычной попытки нажатия по итему*/
            if(!ui->item->itemIsEmpty && (mouseEvent->buttons() & Qt::LeftButton) && (QCursor::pos()-dragStart).manhattanLength()>20){
                if(ui->item->SoundDrag != "")
                    Global::mediaplayer.playSound(QUrl::fromLocalFile(ui->item->SoundDrag), MediaPlayer::SoundsGroup::DRAG_AND_DROP);

                QDrag* drag = new QDrag(this);
                ItemMimeData* mimeData = new ItemMimeData(ui->item, this);

                //Установка позиции перетаскиваемого объекта относительно курсора
                drag->setHotSpot(QPoint(8, 8));
                drag->setMimeData(mimeData);

                //Pixmap перетаскиваемого объекта сложится из Pixmap'ов итема, бекграунда и рамки ячейки
                QPixmap pixmap(68, 68);
                pixmap.fill(Qt::transparent);
                QPixmap itemPixmap = ui->item->grab();
                QPixmap BGPixmap = ui->inventoryCellBG->grab();
                QPixmap borderPixmap = ui->inventoryCellBorder->grab();

                //С помощью пеинтера Pixmap'ы объединяются
                QPainter painter(&pixmap);
                painter.drawPixmap(3, 3, BGPixmap);
                painter.drawPixmap(0, 0, borderPixmap);
                painter.drawPixmap(0, 0, itemPixmap);
                painter.end();

                drag->setPixmap(pixmap);
                emit dragStarted(getItem()->getCellSlots());

                Qt::DropAction result = drag->exec(Qt::MoveAction);
                emit dragEnded();
            }
        }
    }

    return false;
}

void InventoryCell::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList formats = event->mimeData()->formats();
    if(formats.contains("Item")) {
        //Если ячейка заблокирована вручную, то на неё нельзя перетащить итем
        if((isLocked && isManualLock))
            return;
        /*Разрешение на сброс в любом случае вызывается, для того чтобы потом мог вызываться dragLeaveEvent.
         *Это необходимо для того чтобы отслеживать покидание наведения перетаскиваемым итемом. В данном
         *случае невозможно использовать эвенты HoverLeave и MouseLeave так как они никогда не вызываются
         *при зажатой кнопке мыши, а перетаскивание как раз проводится зажатием кнопки мыши.*/
        event->acceptProposedAction();

        const ItemMimeData *itemData = qobject_cast<const ItemMimeData*>(event->mimeData());

        bool slotsMatch = false;
        Item* bufItem = new Item(itemData->getItem());

        //Если в векторе доступных слотов перетаскиваемого итема есть слот этой ячейки, то сброс разрешается
        QVector<Item::Slots> itemSlots = bufItem->getCellSlots();
        QVectorIterator<Item::Slots> iterator(itemSlots);
        while (iterator.hasNext()){
            if(iterator.next() == acceptedSlot){
                return;
            }
        }

        //Если слоты не совпадают, и ячейка не является ячейкой в инвентаре, то ячейке назначется стиль, говорящий о невозможности сбросить сюда итем
        if(acceptedSlot != Item::Slots::INVENTORY)
            setBlockedStyle(true);
    }
}

void InventoryCell::dropEvent(QDropEvent *event)
{
    //Если каким-то образом у ячейки в которую производится сброс был задан стиль, говорящий о том, что сброс невозможен, то он отключается
    setBlockedStyle(false);
    const ItemMimeData *itemData = qobject_cast<const ItemMimeData*>(event->mimeData());

    /*Если ячейку блокирует другой итем и этот итем не тот же, что и помещаемый итем из itemData, а также если сбрасывемый
     *итем не равен тому итему что уже лежит в ячейке, итем из текущей ячейки сбрасывается. Первое необходимо для пого, чтобы
     *можно было перекладывать итем, занимающий несколько ячеек, между своими доступными слотами, а второе возможно, если
     *Draug&Drop из ячейки начался, но вместо перемещения в другую ячейку итем кладут в ту же, из которой началось перетаскивание*/
    if(isLocked && !isManualLock && cellWithLockingItem!=nullptr && cellWithLockingItem!=itemData->getItemCell() && itemData->getItemCell()!=this)
        emit moveCell(cellWithLockingItem);

    //Итем сначала записывается в отдельную переменную из MimeData
    Item* bufItem = new Item(itemData->getItem());

    bool slotsMatch = false;
    //Производится проверка соответствия возможных слотов перетаскивемого итема и слота текущей ячейки
    QVector<Item::Slots> itemSlots = bufItem->getCellSlots();
    QVectorIterator<Item::Slots> iterator(itemSlots);
    while (iterator.hasNext()){
        if(iterator.next() == acceptedSlot){
            event->acceptProposedAction();
            slotsMatch = true;
            break;
        }
    }

    //Если соответствий найдено не было, и текущая ячейка - не ячейка в инвенторе, то перетаскивание отменяется
    if(!slotsMatch && acceptedSlot != Item::Slots::INVENTORY)
        return;

    InventoryCell* itemCell = const_cast<InventoryCell*>(itemData->getItemCell());
    //Если ячейка из itemData не nullptr, производится свап ячеек
    if(itemCell){
        swapItems(itemCell);
        event->acceptProposedAction();
    }
}

void InventoryCell::dragLeaveEvent(QDragLeaveEvent *event)
{
    //Если перетаскиваемый объект больше не наведён на ячейку, то стиль, говорящий о том, что сброс в данную ячейку невозможен, гасится
    if(isBlocked)
        setBlockedStyle(false);
}

/*Стиль неактивной (заблокированной) ячейки. Если ячейка блокируется, в метод передаётся та ячейка, которая
 *спровоцировала блокировку. Также есть ручная блокировка, которая может быть только также вручную и снята*/
void InventoryCell::setLockedStyle(bool isLocked, InventoryCell *cellWithLockingItem, bool isManualLock)
{
    this->isLocked = isLocked;
    this->isManualLock = isManualLock;

    //Если блокировка назначена вручную, то ей нельзя задать спровоцировавшую блокировку ячейку
    if(!this->isManualLock)
        this->cellWithLockingItem = cellWithLockingItem;
    else
        this->cellWithLockingItem = nullptr;

    if(!isLocked){
        cellWithLockingItem = nullptr;
        this->isManualLock = false;
        setAutoStyle();
        return;
    }

    //Есля в блокируемой ячейке что-то есть, оно сбрасывается
    if(isLocked && !ui->item->itemIsEmpty){
        emit moveCell(this);
    }

    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Задний фон и центральный элемент не участвуют в этом стиле, так что их следует скрыть
    ui->inventoryCellBG->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    ui->SubstrateDolls->setVisible(false);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::lockedBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonLockedStyle());
    ui->Locked->setStyleSheet(IC_stylemaster::lockedStyle());
    ui->CentralElement->setVisible(CentralElementIsVisible);
    ui->Locked->setVisible(true);
    ui->item->setUpdatesEnabled(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 56);
}

//Стиль ячейки с заглушенным предметом
void InventoryCell::setDisabledStyle()
{
    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Лейбл заблокированной ячейки и центральный элемент не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::disabledNotEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::disabledNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonDisabledNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);
    ui->CentralElement->setVisible(CentralElementIsVisible);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(false);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

//Стиль ячейки, в которую нельзя поместить выбранный итем
void InventoryCell::setBlockedStyle(bool isBlocked)
{
    this->isBlocked = isBlocked;
    ui->Blocked->setVisible(isBlocked);
    if(isBlocked)
        ui->Blocked->setStyleSheet(IC_stylemaster::blockedStyle());

    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
    ui->item->setUpdatesEnabled(true);
}

//Стиль ячейки, в которую возможно поместить перетаскиваемый итем
void InventoryCell::setAvailableStyle(bool isAvailable)
{
    this->isAvailable = isAvailable;
    ui->SubstrateDolls->setVisible(isAvailable);
    if(isAvailable){
        //В зависимости от уже применённых стилей находится необходимая гифка
        if(isLocked)
            inventoryCellNew.setFileName(":/Equipment/GIF/LockedAvailableInventoryCell.gif");
        else if(getItem()->itemIsEmpty)
            inventoryCellNew.setFileName(":/Equipment/GIF/EmptyAvailableInventoryCell.gif");
        else if(getItem()->isDisabled && getItem()->getIsBroken())
            inventoryCellNew.setFileName(":/Equipment/GIF/DisabledBrokenAvailableInventoryCell.gif");
        else if(getItem()->isDisabled)
            inventoryCellNew.setFileName(":/Equipment/GIF/DisabledAvailableInventoryCell.gif");
        else if(getItem()->getIsBroken())
            inventoryCellNew.setFileName(":/Equipment/GIF/BrokenAvailableInventoryCell.gif");
        else
            inventoryCellNew.setFileName(":/Equipment/GIF/AvailableInventoryCell.gif");

        inventoryCellNew.stop();
        //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
        ui->Locked->setVisible(false);
        ui->CentralElement->setVisible(false);
        //Включается отображение анимации ячейки с новым предметом. Только в данном случае туда передаётся гифка доступной ячейки
        ui->inventoryCellNew->setVisible(true);
        inventoryCellNew.setScaledSize(QSize(68,68));
        ui->inventoryCellNew->setMovie(&inventoryCellNew);
        inventoryCellNew.start();
        if(!getItem()->itemIsEmpty){
            /*Чтобы анимация не перерисовывала виджет итема с кучей эффектов, был создан лейбл оптимизации,
             *который запечатлевает Pixmap итема. Виджету итема обновляться запрещается, а вместо него
             *перисовываться будет один только Pixmap, что существенно улучшает производительность*/
            ui->ItemPixmapGrab->setPixmap(ui->item->grab());
            ui->ItemPixmapGrab->setVisible(true);

            //Запрет обновления виджета итема для оптимизации отображения вместе с анимацией
            ui->item->setUpdatesEnabled(false);
        }
    }else
        setAutoStyle();

}

//Метод задающий значения переменным col и row. Он не изменит позицию и требуется только для инициализации
void InventoryCell::setCellPosition(int col, int row)
{
    this->col = col;
    this->row = row;
}

//Стиль ячейки со сломанным пребметом
void InventoryCell::setBrokenStyle()
{
    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Задний фон и лейбл центрального элемента не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::notEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::brokenNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(true);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

//Стиль ячейки с заглушенным сломанным пребметом
void InventoryCell::setDisabledBrokenStyle()
{
    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Лейбл заблокированной ячейки и центральный элемент не участвуют в этом стиле, так что их следует скрыть
    ui->Locked->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::disabledNotEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::disabledBrokenNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonDisabledNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);
    ui->CentralElement->setVisible(CentralElementIsVisible);
    ui->SubstrateDolls->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(true);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

int InventoryCell::getRow() const
{
    return row;
}

int InventoryCell::getCol() const
{
    return col;
}

bool InventoryCell::getIsAvailable() const
{
    return isAvailable;
}

InventoryCell *InventoryCell::getCellWithLockingItem() const
{
    return cellWithLockingItem;
}

bool InventoryCell::getIsManualLock() const
{
    return isManualLock;
}

bool InventoryCell::getIsBlocked() const
{
    return isBlocked;
}

/*Метод меняющий местами итемы между ячейками. Следует помнить, что для правильного порядка
 *вызова сигналов данный метод следует вызывать у целевой ячейки, а передовать перемещаемую*/
void InventoryCell::swapItems(InventoryCell *cell, bool playSound)
{
    if(cell){
        /*Сначала, если целевая ячейка не является ячейкой в инвентаре и не блокирована итемом из передаваемой
         *ячейки, также как и сама не является этой самой передаваемой ячейкой, то для перемещаемой вещи сбрасывются
         *все конфликтующие вещи. Последние 2 пункта необходимы, чтобы итем не мог сбросить сам себя*/
        if(acceptedSlot!=Item::INVENTORY && cellWithLockingItem!=cell && cell!=this)
            emit checkLockedCells (cell->getItem()->getOccupiedCellSlots());

        /*Если хотябы одна из ячеек не является ячейкой в инвентаре, то для обоих вещей
         *разблокируются все заблкированые ячейки из списка занимаемых ими слотов*/
        if(acceptedSlot!=Item::INVENTORY || cell->acceptedSlot!=Item::INVENTORY){
            emit unlockOccupiedCells(cell);
            emit unlockOccupiedCells(this);
        }

        //Если каким-то образом у ячейки в которую производится сброс был задан стиль, говорящий о том, что сброс невозможен, то он отключается
        setBlockedStyle(false);

        //Итем из передаваемой ячейки записывается в буфер
        Item* bufItem = new Item(cell->getItem());

        //Затем в передаваемую ячейку переносится итем из целевой ячейки
        cell->setItem(new Item(ui->item));
        //Потом идёт перенос буферизированного итема в целевую ячейку
        setItem(bufItem);

        if(playSound && bufItem->SoundDrop!="")
            Global::mediaplayer.playSound(QUrl::fromLocalFile(bufItem->SoundDrop), MediaPlayer::SoundsGroup::DRAG_AND_DROP);

        emit itemIsDropped(col, row);

        //Если целевая ячейка не является ячейкой в инвентаре, то в экиперовке блокируются занимаемые итемом в ней слоты
        if(acceptedSlot!=Item::INVENTORY)
            emit lockOccupiedCells(this, acceptedSlot);
    }
}

bool InventoryCell::getIsLocked() const
{
    return isLocked;
}
