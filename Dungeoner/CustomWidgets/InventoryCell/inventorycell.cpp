/********************************************************************************************
 *Данный класс является виджетом ячейки инвентаря, где хранятся любые итемы инвентаря.
 ********************************************************************************************/

#include "IC_stylemaster.h"

#include "inventorycell.h"
#include "ui_inventorycell.h"

InventoryCell::InventoryCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryCell)
{
    ui->setupUi(this);

    ui->item->installEventFilter(this);

    setDropdownButtonVisible(false);

    QSizePolicy sp_retain = sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    setSizePolicy(sp_retain);

    setAutoStyle();
    ui->item->setStyleButtonsStyle();
}

InventoryCell::~InventoryCell()
{
    delete ui;
}

void InventoryCell::setItem(Item *item)
{
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

    ui->item->setShadow(item->hasShadow, item->shadowBlurRadius, item->shadowXOffset, item->shadowYOffset);
    ui->item->setStyleButtonsStyle();

    setAutoStyle();
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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::emptyBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonEmptyStyle());
    ui->CentralElement->setStyleSheet(IC_stylemaster::centralElementStyle());
    ui->CentralElement->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);

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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::notEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::notEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);

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

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
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

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(false);
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

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(true);
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

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(true);
}

void InventoryCell::setCentralElementStyle(bool isVisible)
{
    ui->CentralElement->setVisible(isVisible);
}

void InventoryCell::setDropdownButtonVisible(bool isVisible)
{
    ui->DropdownButton->setVisible(isVisible);
}

void InventoryCell::setScrollAreaHeight(int newScrollAreaHeight)
{
    ScrollAreaHeight = newScrollAreaHeight;
}

bool InventoryCell::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->item){
        //При наведении новый стиль пропадает
        if(event->type() == QEvent::HoverEnter){
            if(ui->item->isNew){
                ui->item->isNew = false;
                setAutoStyle();
            }
        }
    }

    return false;
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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::lockedBorderStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonLockedStyle());
    ui->Locked->setStyleSheet(IC_stylemaster::lockedStyle());
    ui->CentralElement->setVisible(true);
    ui->Locked->setVisible(true);

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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::disabledNotEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::disabledNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonDisabledNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);
    ui->CentralElement->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(false);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

//Стиль ячейки, в которую нельзя поместить выбранный итем
void InventoryCell::setBlockedStyle(bool isBlocked)
{
    ui->Blocked->setVisible(isBlocked);
    if(isBlocked)
        ui->Blocked->setStyleSheet(IC_stylemaster::blockedStyle());

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(false);
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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::notEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::brokenNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);

    ui->item->setDisabledSyle(false);
    ui->item->setBrokenSyle(true);

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
    //Установка стилей
    ui->inventoryCellBorder->setStyleSheet(IC_stylemaster::disabledNotEmptyBorderStyle());
    ui->inventoryCellBG->setStyleSheet(IC_stylemaster::disabledBrokenNotEmptyBGStyle());
    ui->DropdownButton->setStyleSheet(IC_stylemaster::dropdownButtonDisabledNotEmptyStyle());
    ui->inventoryCellBG->setVisible(true);
    ui->CentralElement->setVisible(true);

    ui->item->setDisabledSyle(true);
    ui->item->setBrokenSyle(true);

    //Пустой стиль чуть-чуть меньше, чем не пустой, так что у них есть разница в высоте отображения кнопки
    ui->DropdownButton->move(3, 57);
}

//Если ячейка находится вне границ скроллбара, то для оптимизации она очищается от стилей и скрывается
void InventoryCell::cellHidingCheck()
{
    if(geometry().y() > ScrollAreaHeight+ScrollAreaOffset){
        setVisible(false);
        inventoryCellNew.stop();
        ui->item->hidenEffects(true);
    }else if(geometry().y()+72 < ScrollAreaOffset){
        setVisible(false);
        inventoryCellNew.stop();
        ui->item->hidenEffects(true);
    }else{
        setVisible(true);
        inventoryCellNew.start();
        ui->item->hidenEffects(false);
    }
}

void InventoryCell::setScrollAreaOffset(int newScrollAreaOffset)
{
    ScrollAreaOffset = newScrollAreaOffset;

    cellHidingCheck();
}
