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
                InventoryCell* ic = qobject_cast <InventoryCell*> (autoCell);
                ic->setCentralElementStyle(false);
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
            InventoryCell* ic = qobject_cast <InventoryCell*> (autoCell);
            ic->setCentralElementStyle(false);
        }
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

