/********************************************************************************
 *Данный класс является классом вещи. Здесь хранятся все её характеристики
 *и имеются все необходимые методы визуализации предметов в инвентаре.
 ********************************************************************************/

#include "I_stylemaster.h"
#include "item.h"
#include "qpainter.h"
#include "ui_item.h"

#include <qdir.h>

Item::Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->pushButton->installEventFilter(this);

    ui->Quantity->setFont(QFont("TextFont"));
    ui->Quantity->setStyleSheet(I_stylemaster::TextFontStyle(17));
    border->setOutlineThickness(2);
    ui->Quantity->setMargin(2);
    ui->Quantity->setGraphicsEffect(border);
}

Item::~Item()
{
    delete shadow;
    delete border;
    delete ui;
}

Item::Item(QString folderName, QVector<ItemType> itemTypes, QString itemName, int quantity, double weight, double volume,
           int price, int maxDurability, int currentDurability, QVector<Slots> cellSlots,
           QVector<Slots> occupiedCellSlots, QVector<Bonus *> bonuses, QVector<MagicDefenseBonus *> magicDefenseBonuses,
           int minDamage, int maxDamage, bool isPressable, bool isDisabled, bool isNew, int currentStyle) :
    ui(new Ui::Item)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->pushButton->installEventFilter(this);

    this->folderName = folderName;

    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName))
        dir.mkpath("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName);

    if(QFile("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName+"/image.png").exists())
         this->image = QImage("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName+"/image.png");
    else{
        this->image = QImage(":/Inventory/Textures PNG/Unknown-Item.png");
        this->hoverColor = QColor(255, 255, 255, 30);
        this->pressedColor = QColor(0, 0, 0, 50);
    }

    ui->Image->setPixmap(QPixmap::fromImage(this->image,Qt::AutoColor));

    this->itemTypes = itemTypes;
    setItemName(itemName);
    setQuantity(quantity);
    setWeight(weight);
    setVolume(volume);
    setPrice(price);
    setMaxDurability(maxDurability);
    setCurrentDurability(currentDurability);
    setCellSlots(cellSlots, occupiedCellSlots);
    this->bonuses = bonuses;
    this->magicDefenseBonuses = magicDefenseBonuses;
    setDamage(minDamage, maxDamage);
    this->isPressable = isPressable;
    setDisabledSyle(isDisabled);
    this->isNew = isNew;
    setCurrentStyle(currentStyle);

    setStyleButtonsStyle();

    ui->Quantity->setFont(QFont("TextFont"));
    ui->Quantity->setStyleSheet(I_stylemaster::TextFontStyle(17));
    border->setOutlineThickness(2);
    ui->Quantity->setMargin(2);
    ui->Quantity->setGraphicsEffect(border);

    if(this->quantity > 1)
        ui->Quantity->setText(QString::number(this->quantity));
}

void Item::setShadow(bool hasShadow, int shadowBlurRadius, int shadowXOffset, int shadowYOffset, QColor color)
{
    if(hasShadow){
        this->shadowBlurRadius = shadowBlurRadius;
        this->shadowXOffset = shadowXOffset;
        this->shadowYOffset = shadowYOffset;

        shadow->setColor(Qt::black);
        shadow->setBlurRadius(this->shadowBlurRadius);
        shadow->setOffset(this->shadowXOffset, this->shadowYOffset);

        ui->Image->setGraphicsEffect(shadow);
    }else
        ui->Image->setGraphicsEffect(NULL);
}

void Item::setStyleButtonsStyle()
{
    //Если у предмета несколько стилей, то включаются кнопки смены стилей
    if(styles.size()>1){
        /*Жёстко задаётся размер области кнопок стилей, чтобы как можно меньше перекрывать этим блоком виджет итема.
         *
         *2 - это нижний отступ, который учтён в размере, отдаваемом на каждую ячейку, но у последней кнопки нижний отступ не нужен.*/
        ui->StyleButtonsWrapper->setFixedHeight(14*styles.size()-2);
        //Получают стили и видимость столько кнопок, сколько стилей есть у вещи
        for(int i = 0; i < ui->StyleButtonsWrapper->children().size()-1; i++){
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setStyleSheet(I_stylemaster::StyleButtonStile());
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setFont(QFont("TextFont"));
        }
        for(int i = 4; i>styles.size()-1; i--)
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setVisible(false);
        //По умолчанию область кнопок стилей полупрозрачная
        opacity->setOpacity(0.3);
        ui->StyleButtonsWrapper->setGraphicsEffect(opacity);
        ui->StyleButtonsWrapper->installEventFilter(this);
    }else
        ui->StyleButtonsWrapper->setVisible(false);
}

int Item::getId() const
{
    return id;
}

//Установка/отключение стиля заглушенного итема
void Item::setDisabledSyle(bool isDisabled)
{
    if(id!=-1){
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

        if(isDisabled){
            //Если вещь сломана, то устанавливается стиль заглушенной сломанной вещи
            if(itemCondition == BROKEN)
                //В таком случае накладываемый цвет представляет из себя средний цвет между сломанным и заглушенным
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                       (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
            //Иначе просто заглушенной вещи
            else
                painter.fillRect(pixmap.rect(), disabledColor);

            ui->Image->setPixmap(pixmap);
            this->isDisabled = true;
        //Если стиль выключается, то просто все воздействия наложения заглушенного цвета снимаются
        }else{
            if(itemCondition == BROKEN){
                painter.fillRect(pixmap.rect(), brokenColor);
                ui->Image->setPixmap(pixmap);
            }else
                ui->Image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
            this->isDisabled = false;
        }
    }
}

//Установка/отключение стиля сломанного итема
void Item::setBrokenSyle(bool isBroken)
{
    if(id!=-1){
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

        if(isBroken){
            //Если вещь заглушена, то устанавливается стиль заглушенной сломанной вещи
            if(isDisabled)
                //В таком случае накладываемый цвет представляет из себя средний цвет между сломанным и заглушенным
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                       (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
            //Иначе просто сломанной вещи
            else
                painter.fillRect(pixmap.rect(), brokenColor);

            ui->Image->setPixmap(pixmap);
        //Если стиль выключается, то просто все воздействия наложения сломанного цвета снимаются
        }else{
            if(isDisabled){
                painter.fillRect(pixmap.rect(), disabledColor);
                ui->Image->setPixmap(pixmap);
            }else
                ui->Image->setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
        }
    }
}

bool Item::getIsBroken()
{
    if(itemCondition == BROKEN)
        return true;
    else
        return false;
}

bool Item::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->pushButton){
        if(isPressable){
            //Наложение на итем цета наведения
            if(event->type() == QEvent::HoverEnter){
                QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
                QPainter painter(&pixmap);
                painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
                //Если вещь сломана и заглушена, то находится средний цвет между заглушенным, сломанным и наведённым цветами
                if(isDisabled && (itemCondition == BROKEN))
                    painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red() + hoverColor.red())/3,
                                                           (disabledColor.green() + brokenColor.green() + hoverColor.green())/3,
                                                           (disabledColor.blue() + brokenColor.blue() + hoverColor.blue())/3,
                                                           (disabledColor.alpha() + brokenColor.alpha() + hoverColor.alpha())/3));
                //Если вещь заглушена, то находится средний цвет между заглушенным и наведённым цветами
                else if(isDisabled)
                    painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + hoverColor.red())/2, (disabledColor.green() + hoverColor.green())/2,
                                                           (disabledColor.blue() + hoverColor.blue())/2, (disabledColor.alpha() + hoverColor.alpha())/2));
                //Если вещь сломана, то находится средний цвет между ломанным и наведённым цветами
                else if(itemCondition == BROKEN)
                    painter.fillRect(pixmap.rect(), QColor((brokenColor.red() + hoverColor.red())/2, (brokenColor.green() + hoverColor.green())/2,
                                                           (brokenColor.blue() + hoverColor.blue())/2, (brokenColor.alpha() + hoverColor.alpha())/2));
                else
                    painter.fillRect(pixmap.rect(), hoverColor);

                ui->Image->setPixmap(pixmap);

                isHovered = true;
            }
            //Возвращение исходных цветов
            else if(event->type() == QEvent::HoverLeave){
                QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
                QPainter painter(&pixmap);
                painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
                //Если вещь сломана и заглушена, то находится средний цвет между заглушенным и сломанным цветами
                if(isDisabled && (itemCondition == BROKEN)){
                    painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                           (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
                    ui->Image->setPixmap(pixmap);
                }else if(isDisabled){
                    painter.fillRect(pixmap.rect(), disabledColor);
                    ui->Image->setPixmap(pixmap);
                }else if(itemCondition == BROKEN){
                    painter.fillRect(pixmap.rect(), brokenColor);
                    ui->Image->setPixmap(pixmap);
                }
                else
                    ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));

                isHovered = false;
            }
        }
    }
    if(object == ui->StyleButtonsWrapper){
        //При наведении, область кнопок стилей итема становится полностью непрозрачной
        if(event->type() == QEvent::Enter){
            opacity->setOpacity(1);
        }
        else if(event->type() == QEvent::Leave){
            opacity->setOpacity(0.3);
        }
    }

    return false;
}

//Эффекты при прожатии итема
void Item::on_pushButton_clicked()
{
    if(isPressable){
        qDebug()<<"Делаю штуку";
    }
}

void Item::on_pushButton_pressed()
{
    if(isPressable){
        //Наложение на итем цвета нажатия
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

        //Если вещь сломана и заглушена, то находится средний цвет между заглушенным, сломанным и нажатым цветами
        if(isDisabled && (itemCondition == BROKEN))
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red() + pressedColor.red())/3,
                                                   (disabledColor.green() + brokenColor.green() + pressedColor.green())/3,
                                                   (disabledColor.blue() + brokenColor.blue() + pressedColor.blue())/3,
                                                   (disabledColor.alpha() + brokenColor.alpha() + pressedColor.alpha())/3));
        //Если вещь заглушена, то находится средний цвет между заглушенным и нажатым цветами
        else if(isDisabled)
            painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + pressedColor.red())/2, (disabledColor.green() + pressedColor.green())/2,
                                                   (disabledColor.blue() + pressedColor.blue())/2, (disabledColor.alpha() + pressedColor.alpha())/2));
        //Если вещь сломана, то находится средний цвет между ломанным и нажатым цветами
        else if(itemCondition == BROKEN)
            painter.fillRect(pixmap.rect(), QColor((brokenColor.red() + pressedColor.red())/2, (brokenColor.green() + pressedColor.green())/2,
                                                   (brokenColor.blue() + pressedColor.blue())/2, (brokenColor.alpha() + pressedColor.alpha())/2));
        else
            painter.fillRect(pixmap.rect(), pressedColor);

        ui->Image->setPixmap(pixmap);
    }
}


void Item::on_pushButton_released()
{
    if(isPressable){
        //Возвращение исходных цветов
        QPixmap pixmap(QPixmap::fromImage(image, Qt::AutoColor));
        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);

        //Если на итем всё ещё наведена мышь, то ей возвращаются цвета наведения
        if(isHovered){
            //Если вещь сломана и заглушена, то находится средний цвет между заглушенным, сломанным и наведённым цветами
            if(isDisabled && (itemCondition == BROKEN))
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red() + hoverColor.red())/3,
                                                       (disabledColor.green() + brokenColor.green() + hoverColor.green())/3,
                                                       (disabledColor.blue() + brokenColor.blue() + hoverColor.blue())/3,
                                                       (disabledColor.alpha() + brokenColor.alpha() + hoverColor.alpha())/3));
            //Если вещь заглушена, то находится средний цвет между заглушенным и наведённым цветами
            else if(isDisabled)
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + hoverColor.red())/2, (disabledColor.green() + hoverColor.green())/2,
                                                       (disabledColor.blue() + hoverColor.blue())/2, (disabledColor.alpha() + hoverColor.alpha())/2));
            //Если вещь сломана, то находится средний цвет между ломанным и наведённым цветами
            else if(itemCondition == BROKEN)
                painter.fillRect(pixmap.rect(), QColor((brokenColor.red() + hoverColor.red())/2, (brokenColor.green() + hoverColor.green())/2,
                                                       (brokenColor.blue() + hoverColor.blue())/2, (brokenColor.alpha() + hoverColor.alpha())/2));
            else
                painter.fillRect(pixmap.rect(), hoverColor);

            ui->Image->setPixmap(pixmap);
        //Иначе возвращаются обычные цвета
        }else
            //Если вещь сломана и заглушена, то находится средний цвет между заглушенным и сломанным цветами
            if(isDisabled && (itemCondition == BROKEN)){
                painter.fillRect(pixmap.rect(), QColor((disabledColor.red() + brokenColor.red())/2, (disabledColor.green() + brokenColor.green())/2,
                                                       (disabledColor.blue() + brokenColor.blue())/2, (disabledColor.alpha() + brokenColor.alpha())/2));
                ui->Image->setPixmap(pixmap);
            }else if(isDisabled){
                painter.fillRect(pixmap.rect(), disabledColor);

                ui->Image->setPixmap(pixmap);
            }else if(itemCondition == BROKEN){
                painter.fillRect(pixmap.rect(), brokenColor);

                ui->Image->setPixmap(pixmap);
            }
            else
                ui->Image->setPixmap(QPixmap::fromImage(image, Qt::AutoColor));
    }
}

QVector<Item::Slots> Item::getOccupiedCellSlots() const
{
    return occupiedCellSlots;
}

void Item::setId(int newId)
{
    id = newId;
}

int Item::getCurrentStyle() const
{
    return currentStyle;
}

void Item::setCurrentStyle(int newCurrentStyle)
{
    if(newCurrentStyle < 0)
        newCurrentStyle = 0;
    if(newCurrentStyle > styles.size()-1)
        newCurrentStyle = styles.size()-1;

    currentStyle = newCurrentStyle;
}

void Item::init(QPixmap pixMap)
{
    this->image = QImage("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName+"/image.png");
    ui->Image->setPixmap(QPixmap::fromImage(this->image,Qt::AutoColor));
}

QVector<Item::Slots> Item::getCellSlots() const
{
    return cellSlots;
}

//Объединить с занимаемыми!!!!
void Item::setCellSlots(QVector<Slots> newCellSlots, QVector<Slots> newOccupiedCellSlots)
{
    occupiedCellSlots.clear();

    cellSlots = newCellSlots;
    occupiedCellSlots.append(cellSlots);

    occupiedCellSlots.append(newOccupiedCellSlots);
}

int Item::getMaxDamage() const
{
    return maxDamage;
}

int Item::getMinDamage() const
{
    return minDamage;
}

void Item::setDamage(int newMinDamage, int newMaxDamage)
{
    if(newMaxDamage > 999999999)
        newMaxDamage = 999999999;

    if(newMinDamage > newMaxDamage)
        newMinDamage = newMaxDamage;
    if(newMinDamage < 0)
        newMinDamage = 0;

    minDamage = newMinDamage;
    maxDamage = newMaxDamage;
}

int Item::getCurrentDurability() const
{
    return currentDurability;
}

void Item::setCurrentDurability(int newCurrentDurability)
{
    if(newCurrentDurability > maxDurability)
        newCurrentDurability = maxDurability;
    if(newCurrentDurability < -1)
        newCurrentDurability = -1;

    currentDurability = newCurrentDurability;

    if(currentDurability == -1)
        itemCondition = CRASHPROOF;
    else if(currentDurability == maxDurability)
        itemCondition = IDEAL;
    else if(currentDurability == 0)
        itemCondition = BROKEN;
    else
        itemCondition = DAMAGED;
}

int Item::getMaxDurability() const
{
    return maxDurability;
}

void Item::setMaxDurability(int newMaxDurability)
{
    if(newMaxDurability == 0)
        newMaxDurability = 1;

    if(newMaxDurability > 999999999)
        newMaxDurability = 999999999;
    if(newMaxDurability < -1)
        newMaxDurability = -1;

    maxDurability = newMaxDurability;

    if(maxDurability < currentDurability)
        currentDurability = maxDurability;

    if(currentDurability == -1)
        itemCondition = CRASHPROOF;
    else if(currentDurability == maxDurability)
        itemCondition = IDEAL;
    else if(currentDurability == 0)
        itemCondition = BROKEN;
    else
        itemCondition = DAMAGED;
}

QString Item::getItemName() const
{
    return itemName;
}

void Item::setItemName(const QString &newItemName)
{
    if(newItemName == "")
        return;

    itemName = newItemName;
}

int Item::getPrice() const
{
    return price;
}

void Item::setPrice(int newPrice)
{
    if(newPrice > 999999999)
        newPrice = 999999999;
    if(newPrice < 0)
        newPrice = 0;

    price = newPrice;
}

double Item::getVolume() const
{
    return volume;
}

void Item::setVolume(double newVolume)
{
    if(newVolume > 9999)
        newVolume = 9999;
    if(newVolume < 0)
        newVolume = 0;

    volume = newVolume;
}

double Item::getWeight() const
{
    return weight;
}

void Item::setWeight(double newWeight)
{
    if(newWeight > 9999)
        newWeight = 9999;
    if(newWeight < 0)
        newWeight = 0;

    weight = newWeight;
}

int Item::getQuantity() const
{
    return quantity;
}

void Item::setQuantity(int newQuantity)
{
    if(newQuantity < 1)
        newQuantity = 1;
    else if(newQuantity>999)
        newQuantity = 999;

    quantity = newQuantity;

    if(this->quantity > 1)
        ui->Quantity->setText(QString::number(this->quantity));
}
