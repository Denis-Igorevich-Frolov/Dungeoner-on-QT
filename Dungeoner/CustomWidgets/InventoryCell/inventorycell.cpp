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

    if(ui->item->getId()==-1)
        setEmptyStyle();
    else
        setNoEmptyStyle();
    setDropdownButtonVisible(false);
}

InventoryCell::~InventoryCell()
{
    delete ui;
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
void InventoryCell::setLockedNewStyle()
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

void InventoryCell::setCentralElementStyle(bool isVisible)
{
    ui->CentralElement->setVisible(isVisible);
}

void InventoryCell::setDropdownButtonVisible(bool isVisible)
{
    ui->DropdownButton->setVisible(isVisible);
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

void InventoryCell::setLockedBrokenStyle()
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
