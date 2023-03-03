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

    setDropdownButtonVisible(false);

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
    ui->item->setId(item->getId());
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
    //id -1 только у пустого неинициализированного предмета
    if(ui->item->getId() == -1)
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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(IC_stylemaster::centralElementStyle());
    ui->CentralElement->setVisible(true);

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

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(true);
    //Запрет обновления виджета итема для оптимизации отображения вместе с анимацией
    ui->item->setUpdatesEnabled(false);
}

void InventoryCell::setCentralElementStyle(bool isVisible)
{
    ui->CentralElement->setVisible(isVisible);
}

void InventoryCell::setDropdownButtonVisible(bool isVisible)
{
    ui->DropdownButton->setVisible(isVisible);
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

                //Установка позиции перетаскиваемого объекта по центру от курсора
                drag->setHotSpot(QPoint(ui->item->width()/2, ui->item->height()/2));
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

                Qt::DropAction result = drag->exec(Qt::MoveAction);
            }
        }
    }

    return false;
}

void InventoryCell::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList formats = event->mimeData()->formats();
    if(formats.contains("Item")) {
        event->acceptProposedAction();
    }
}

void InventoryCell::dropEvent(QDropEvent *event)
{
    const ItemMimeData *itemData = qobject_cast<const ItemMimeData*>(event->mimeData());
    //Итем сначала записывается в отдельную переменную из MimeData
    Item* newItem = new Item(itemData->getItem());
    newItem->setId(itemData->getItem()->getId());

    InventoryCell* itemCell = const_cast<InventoryCell*>(itemData->getItemCell());
    if(itemCell){
        if(newItem->SoundDrop!="")
            Global::mediaplayer.playSound(QUrl::fromLocalFile(newItem->SoundDrop), MediaPlayer::SoundsGroup::DRAG_AND_DROP);
        //Затем текущий итем помещается в ячейку из которой началось перетаскивание
        itemCell->setItem(new Item(ui->item));
        /*Так как setItem не передаёт id итема, вызов setAutoStyle внутри него не сработал
         *должным образом. Следует вручную перенести id и вызвать setAutoStyle снова*/
        itemCell->getItem()->setId(ui->item->getId());
        itemCell->setAutoStyle();
        /*Перенос буферизированного итема в текущую ячейку. id ему уже задан
         *заранее, так что setAutoStyle внутри setItem сработает как надо*/
        setItem(newItem);

        event->acceptProposedAction();
    }
}

//Стиль неактивной (заблокированной) ячейки
void InventoryCell::setLockedStyle()
{
    //Выключается отображение анимации ячейки с новым предметом, на случай если такая анимация была включена
    ui->inventoryCellNew->setVisible(false);
    inventoryCellNew.stop();
    //Задний фон и центральный элемент не участвуют в этом стиле, так что их следует скрыть
    ui->inventoryCellBG->setVisible(false);
    ui->CentralElement->setVisible(false);
    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::lockedBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonLockedStyle());
    ui->Locked->setStyleSheet(IC_stylemaster::lockedStyle());
    ui->CentralElement->setVisible(true);
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
    ui->CentralElement->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(false);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

//Стиль ячейки, в которую нельзя поместить выбранный итем
void InventoryCell::setBlockedStyle(bool isBlocked)
{
    ui->Blocked->setVisible(isBlocked);
    if(isBlocked)
        ui->Blocked->setStyleSheet(IC_stylemaster::blockedStyle());

    //Скрывается лейбл оптимизации анимаций заднего фона
    ui->ItemPixmapGrab->setVisible(false);
    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
    ui->item->setUpdatesEnabled(true);
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
    ui->CentralElement->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(true);
    ui->item->setUpdatesEnabled(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}
