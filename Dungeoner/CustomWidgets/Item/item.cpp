/********************************************************************************
 *Данный класс является классом вещи. Здесь хранятся все её характеристики
 *и имеются все необходимые методы визуализации предметов в инвентаре.
 ********************************************************************************/

#include "I_stylemaster.h"
#include "item.h"
#include "qpainter.h"
#include "ui_item.h"

Item::Item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->pushButton->installEventFilter(this);

    //Установка всех стилей
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

//Конструктор, применяемый для создания независимого клона или полностью настроенного экземпляра Item
Item::Item(QString folderName, QVector<ItemType> itemTypes, QString itemName, int quantity, double weight, double volume,
           int price, int maxDurability, int currentDurability, QVector<Slots> cellSlots, QVector<Slots> occupiedCellSlots,
           QVector<Bonus*> bonuses, QVector<MagicDefenseBonus *> magicDefenseBonuses, int minDamage, int maxDamage,
           bool isPressable, int maxCharges, int currentCharges, bool isDisabled, bool isNew, int currentStyle,
           bool itemIsEmpty, QVector<Item *> styles, QString SoundDrag, QString SoundDrop, QString SoundPress, QString SoundPressWithOutOfCharge) :
    ui(new Ui::Item)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->pushButton->installEventFilter(this);

    this->itemIsEmpty = itemIsEmpty;
    //Если итем пуст, то и его id всегда будет равен -1
    if(itemIsEmpty)
        setId(-1);

    this->folderName = folderName;

    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName))
        dir.mkpath("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName);


    if(QFile("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName+"/image.png").exists())
         this->image = QImage("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName+"/image.png");
    //Если итем пуст, то ему вообще никакой картинки не нужно
    else if(id!=-1){
        //Если картинку итема загрузить не удалось, то ей присваивается картинка по умолчанию и стили для неё
        this->image = QImage(":/Inventory/Textures PNG/Unknown-Item.png");
        this->hoverColor = QColor(255, 255, 255, 30);
        this->pressedColor = QColor(0, 0, 0, 50);
    }

    ui->Image->setPixmap(QPixmap::fromImage(this->image,Qt::AutoColor));

    //Если итем пуст, то у него не может быть стилей
    if(itemIsEmpty){
        styles.clear();
        styles.append(this);
    }else if(styles.size()>0)
        this->styles = styles;
    else{
        dir.cd("Game Saves/" + Global::DungeonName + "/Items/"+ this->folderName);
        loadStyles(dir);
    }

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
    setMaxCharges(maxCharges);
    setCurrentCharges(currentCharges);
    setDisabledSyle(isDisabled);
    this->isNew = isNew;

    this->SoundDrag = SoundDrag;
    this->SoundDrop = SoundDrop;
    this->SoundPress = SoundPress;
    this->SoundPressWithOutOfCharge = SoundPressWithOutOfCharge;

    setStyleButtonsStyle();

    ui->Quantity->setFont(QFont("TextFont"));
    ui->Quantity->setStyleSheet(I_stylemaster::TextFontStyle(17));

    border->setOutlineThickness(2);
    ui->Quantity->setMargin(2);
    ui->Quantity->setGraphicsEffect(border);

    if(this->quantity > 1)
        ui->Quantity->setText(QString::number(this->quantity));
    else
        ui->Quantity->setText("");

    setCurrentStyle(currentStyle);
}

//Конструктор независимого клона итема по константной ссылке. Пока используется только в Drag&Drop
Item::Item(const Item *item):
    Item(item->folderName, item->itemTypes, item->itemName, item->quantity, item->weight, item->volume,
         item->price, item->maxDurability, item->currentDurability, item->cellSlots, item->occupiedCellSlots,
         item->bonuses, item->magicDefenseBonuses, item->minDamage, item->maxDamage, item->isPressable,
         item->maxCharges, item->currentCharges, item->isDisabled, item->isNew, item->currentStyle,
         item->itemIsEmpty, item->styles, item->SoundDrag, item->SoundDrop, item->SoundPress, item->SoundPressWithOutOfCharge)
{}

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
    }else{
        this->shadowBlurRadius = 0;
        this->shadowXOffset = 0;
        this->shadowYOffset = 0;

        shadow->setBlurRadius(this->shadowBlurRadius);
        shadow->setOffset(this->shadowXOffset, this->shadowYOffset);

        ui->Image->setGraphicsEffect(shadow);
    }
}

//Установка стиля для кнопки, переключающей стили предмета
void Item::setStyleButtonsStyle()
{
    //Если у предмета несколько стилей, то включаются кнопки смены стилей
    if(styles.size()>1){
        ui->StyleButtonsWrapper->setVisible(true);
        /*Жёстко задаётся размер области кнопок стилей, чтобы как можно меньше перекрывать этим блоком виджет итема.
         *
         *2 - это нижний отступ, который учтён в размере, отдаваемом на каждую ячейку, но у последней кнопки нижний отступ не нужен.*/
        ui->StyleButtonsWrapper->setFixedHeight(14*styles.size()-2);
        //Получают стили и видимость столько кнопок, сколько стилей есть у вещи
        for(int i = 0; i < ui->StyleButtonsWrapper->children().size()-1; i++){
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

//Проверка сломана ли вещь
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
    //!!!Пока класс эффекта прожатия вещи не реализован

    if(isPressable){
        //Если итем сломан, его нельзя продать
        if(itemCondition == BROKEN){
            if(SoundPressWithOutOfCharge!="")
                Global::mediaplayer.playSound(QUrl::fromLocalFile(SoundPressWithOutOfCharge), MediaPlayer::SoundsGroup::SOUNDS);
            return;
        }

        //Если у итема неограниченое количество зарядов, то просто выполняется эффект нажатия
        if(maxCharges == -1){
            if(SoundPress!="")
                Global::mediaplayer.playSound(QUrl::fromLocalFile(SoundPress), MediaPlayer::SoundsGroup::SOUNDS);
            qDebug()<<"Делаю штуку";
        //Иначе он выполняется только если эти заряды остались
        }else if(currentCharges != 0){
            if(maxCharges != -1){
                if(SoundPress!="")
                    Global::mediaplayer.playSound(QUrl::fromLocalFile(SoundPress), MediaPlayer::SoundsGroup::SOUNDS);
                qDebug()<<"Делаю штуку, заряды: " << currentCharges-1<<"/"<<maxCharges;
                setCurrentCharges(currentCharges-1);
            }
        }else{
            if(SoundPressWithOutOfCharge!="")
                Global::mediaplayer.playSound(QUrl::fromLocalFile(SoundPressWithOutOfCharge), MediaPlayer::SoundsGroup::SOUNDS);
            qDebug()<<"Заряды кончились";
            return;
        }
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

//Класс для оптимизации полностью скрывающий итем и его стили. Вызывается только когда итема и так не должно быть видно
void Item::hidenEffects(bool hiden)
{
    if(hiden){
        border->setEnabled(false);
        opacity->setEnabled(false);
        shadow->setEnabled(false);
        setVisible(false);
    }else{
        border->setEnabled(true);
        opacity->setEnabled(true);
        shadow->setEnabled(true);
        setVisible(true);
    }
}

//Загрузка всех стилей из папки Styles в папке итема
bool Item::loadStyles(QDir dir)
{
    if (dir.cd("Styles")) {
        QStringList folders = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
        if(folders.size() == 0)
            return false;
        else foreach (QString folder, folders) {
            //!!!! Когда будет реализована БД итема, здесь должна происходить загрузка
            Item* itemStyle = new Item(folderName+"/Styles/"+folder, QVector<Item::ItemType>(Item::ONE_HANDED_SWORD), "Меч");
            styles.append(itemStyle);
        }
        return true;
    }else
    return false;
}

void Item::setId(int newId)
{
    id = newId;
}

int Item::getCurrentStyle() const
{
    return currentStyle;
}

//Метод устанавливающий текущий стиль итемов на основе вектора styles
void Item::setCurrentStyle(int newCurrentStyle)
{
    if(newCurrentStyle < 0)
        newCurrentStyle = 0;
    if(newCurrentStyle > styles.size()-1)
        newCurrentStyle = styles.size()-1;

    currentStyle = newCurrentStyle;

    setChosenStyleButtonStyle();

    Item* currentItem = styles.at(currentStyle);

    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Game Saves/" + Global::DungeonName + "/Items/"+ currentItem->folderName))
        dir.mkpath("Game Saves/" + Global::DungeonName + "/Items/"+ currentItem->folderName);

    if(QFile("Game Saves/" + Global::DungeonName + "/Items/"+ currentItem->folderName+"/image.png").exists())
         this->image = QImage("Game Saves/" + Global::DungeonName + "/Items/"+ currentItem->folderName+"/image.png");
    //Если итем пуст, то ему вообще никакой картинки не нужно
    else if(id!=-1){
        //Если картинку итема загрузить не удалось, то ей присваивается картинка по умолчанию и стили для неё
        this->image = QImage(":/Inventory/Textures PNG/Unknown-Item.png");
        this->hoverColor = QColor(255, 255, 255, 30);
        this->pressedColor = QColor(0, 0, 0, 50);
    }

    ui->Image->setPixmap(QPixmap::fromImage(currentItem->image,Qt::AutoColor));

    this->itemTypes = currentItem->itemTypes;
    setItemName(currentItem->itemName);
    setWeight(currentItem->weight);
    setVolume(currentItem->volume);
    setCellSlots(currentItem->cellSlots, currentItem->occupiedCellSlots);
    this->bonuses = currentItem->bonuses;
    setDamage(currentItem->minDamage, currentItem->maxDamage);
    this->isPressable = currentItem->isPressable;
    setDisabledSyle(currentItem->isDisabled);

    setChosenStyleButtonStyle();
    setDisabledSyle(isDisabled);
    setBrokenSyle(getIsBroken());
}

QVector<Item::Slots> Item::getCellSlots() const
{
    return cellSlots;
}

/*Установка векторов ячеек доступных для этой вещи и её занимаемых слотов. В занимаемых
 *слотах нужно указывать ячейки только если предмет всегда занимает их несколько*/
void Item::setCellSlots(QVector<Slots> newCellSlots, QVector<Slots> newOccupiedCellSlots)
{
    occupiedCellSlots = newOccupiedCellSlots;
    cellSlots = newCellSlots;
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
    //Текущая прочность -1 может быть только если и максимальная также равна -1
    if(maxDurability > -1 && currentDurability < 0)
        currentDurability = 0;
    else if(newCurrentDurability < -1)
        newCurrentDurability = -1;


    currentDurability = newCurrentDurability;

    //Прочность -1 означает, что предмет неразрушим
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

    if(currentDurability > maxDurability)
        currentDurability = maxDurability;

    maxDurability = newMaxDurability;

    if(maxDurability < currentDurability)
        currentDurability = maxDurability;

    //Прочность -1 означает, что предмет неразрушим
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

//Передаваемое имя не может быть пустым. При попытке передачии "" в функцию не произойдёт ничего
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
    else
        ui->Quantity->setText("");
}

/*Метод устанавливающий стиль кнопок стилей итема в соответствии с текущим стилем. Так гасятся
 *все кнопки кроме той, которая соответствует текущему стилю, она же в свою очередь зажигается*/
void Item::setChosenStyleButtonStyle()
{
    for(int i = 0; i<styles.size(); i++){
        if(i == currentStyle)
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setStyleSheet(I_stylemaster::StyleChosenButtonStile());
        else
            ui->StyleButtonsWrapper->layout()->itemAt(i)->widget()->setStyleSheet(I_stylemaster::StyleButtonStile());
    }
}

int Item::getCurrentCharges() const
{
    return currentCharges;
}

void Item::setCurrentCharges(int newCurrentCharges)
{
    if(newCurrentCharges < 0)
        newCurrentCharges = 0;
    else if(newCurrentCharges > maxCharges)
        newCurrentCharges = maxCharges;

    currentCharges = newCurrentCharges;
}

int Item::getMaxCharges()
{
    return maxCharges;
}

void Item::setMaxCharges(int newMaxCharges)
{
    if(newMaxCharges < -1)
        newMaxCharges = -1;
    //Если количество текущих зарядов больше максимального, то они усекаются до максимального
    if(currentCharges > newMaxCharges)
        currentCharges = newMaxCharges;
    //Если таким образом у предмета стало неограниченное количество зарядов, то текущее количество всё-равно остаётся нулевым
    if(currentCharges == -1)
        currentCharges = 0;

    maxCharges = newMaxCharges;
}

void Item::on_StyleButton_1_clicked()
{
    setCurrentStyle(0);
}


void Item::on_StyleButton_2_clicked()
{
    setCurrentStyle(1);
}


void Item::on_StyleButton_3_clicked()
{
    setCurrentStyle(2);
}


void Item::on_StyleButton_4_clicked()
{
    setCurrentStyle(3);
}


void Item::on_StyleButton_5_clicked()
{
    setCurrentStyle(4);
}

QWidget *Item::getStyleButtonsWrapper()
{
    return ui->StyleButtonsWrapper;
}

QPushButton *Item::getItemButton()
{
    return ui->pushButton;
}
