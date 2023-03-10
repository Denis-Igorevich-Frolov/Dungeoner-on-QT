/***************************************************
 *Окно персонажа, содержащее всю информацию о нём
 ***************************************************/

#include "characterwindow.h"
#include "qevent.h"
#include "ui_characterwindow.h"

#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QSpinBox>
#include <QScrollBar>
#include <QMutableVectorIterator>
#include <QEasingCurve>
#include <CustomWidgets/Item/item.h>
#include <Global/GlobalStyleMaster.h>

CharacterWindow::CharacterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWindow)
{
    ui->setupUi(this);
    //Убирание рамки окна
    this->setWindowFlags(Qt::FramelessWindowHint);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->Inventory->setPos(ui->Inventory->pos());
    setTextPrimarySkills();
    setStyles();

    associatingLabelsWithStat();

    connect(ui->Inventory, &CharacterWindowInventory::RemoveTooltip, this, &CharacterWindow::RemoveTooltip);

    //Связывание слота полной переинициализации из класса person с обновлением отображения статов
    connect(&person, &Person::FullReinitializationRequest, this, &CharacterWindow::refreshDisplayStats);

    /*Связывание слота ScrollAreaSecondarySkillsScrolled с сигналом valueChanged у вертикального скроллбара в области
     *прокрутки ScrollAreaSecondarySkills. Делается это потому, что у убласти прокрутки мне нужен сигнал изменения
     *положения прокрутки. Внезапно вдруг такого не имеется. Но имеется сигнал valueChanged у скроллбара внутри
     *области прокрутки, что собственно и есть то, что мне и нужно. Для этого я и связываю его сигнал с моим слотом*/
    connect(ui->ScrollAreaSecondarySkills->verticalScrollBar(), &QAbstractSlider::valueChanged,
            this, &CharacterWindow::ScrollAreaSecondarySkillsScrolled);

    /*Отключение у теней скроллбара вторичных навыков возможности принимать фокус
     *и ивенты мыши, чтобы они не перекрывали непосредственно вторичные навыки*/
    ui->SecondarySkillsShadowTop->setFocusPolicy(Qt::NoFocus);
    ui->SecondarySkillsShadowTop->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->SecondarySkillsShadowBottom->setFocusPolicy(Qt::NoFocus);
    ui->SecondarySkillsShadowBottom->setAttribute(Qt::WA_TransparentForMouseEvents);

    /*Подсказка не должна принимать фокус и ивенты мыши, чтобы не перехватывать
     *их с виджетов с которых она сама и вызывается.*/
    ui->tooltip->setFocusPolicy(Qt::NoFocus);
    ui->tooltip->setAttribute(Qt::WA_TransparentForMouseEvents);
    //Подсказка по умолчанию скрыта
    ui->tooltip->setVisible(false);

    linkingTooltipSlots();

    /*Передача во все SecondarySkill высоты их ScrollArea для последующей обработки
     *выведения подсказки при усечении SecondarySkill внутри ScrollArea. Само собой
     *программа не подразумевает последующиее изменение размера SecondarySkills,
     *если же такая потребность возникнет, то этот кусок кода надо переместить в
     *метод resize.
     *
     *При переборе всех дочерних эллементов контейнера SecondarySkills важно, чтобы
     *все эти эллементы были типа SecondarySkill. Если это не так, то эллемент будет
     *проигнорирован и выведено предупреждение.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(secondarySkillsGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                    SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                    ss->setScrollAreaHeight(ui->ScrollAreaSecondarySkills->height());
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе CharacterWindow.\n"
                            "Объект " + secondarySkillsGrid->itemAtPosition(row, column)->widget()->objectName() + " не является SecondarySkill.\n\n";
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
    }

    tooltipInitialization();
    recalculateStats();

    //!!!отладка
    //////////////////////////////////////////////
    Item* item = new Item("Test", QVector<Item::ItemType>(Item::ONE_HANDED_SWORD), "Меч");

    item->isPressable = true;
//    item->isDisabled = true;
    item->isNew = true;

    item->setQuantity(999);
    item->setMaxCharges(10);
    item->setCurrentCharges(10);
    item->setId(0);

    item->SoundDrag = "qrc:/Drag&Drop/Sounds/Drag&Drop/Sword_is_taken.mp3";
    item->SoundDrop = "qrc:/Drag&Drop/Sounds/Drag&Drop/Sword_is_dropped.mp3";
    item->SoundPress = "qrc:/Item is pressed/Sounds/Item is pressed/Sword_is_pressed.wav";

    InventoryCell* cell = ui->Inventory->getCell(0, 0);

    if(cell){
        cell->setItem(item);
    }

    Item* item2 = new Item("Test", QVector<Item::ItemType>(Item::ONE_HANDED_SWORD), "Меч");

    item2->isPressable = true;
//    item2->isDisabled = true;
    item2->isNew = true;

    item2->setMaxDurability(1);
    item2->setCurrentDurability(0);

    item2->setQuantity(999);
    item2->setMaxCharges(10);
    item2->setCurrentCharges(10);
    item2->setId(0);

    item2->SoundDrag = "qrc:/Drag&Drop/Sounds/Drag&Drop/Sword_is_taken.mp3";
    item2->SoundDrop = "qrc:/Drag&Drop/Sounds/Drag&Drop/Sword_is_dropped.mp3";
    item2->SoundPress = "qrc:/Item is pressed/Sounds/Item is pressed/Sword_is_pressed.wav";

    InventoryCell* cell2 = ui->Inventory->getCell(0, 2);

    if(cell2){
        cell2->setItem(item2);
    }
    /////////////////////////////////////////////
}

CharacterWindow::~CharacterWindow()
{
    delete ui;
}

/*Установка текста для подписи первичного навыка в соответствии с его динамическим
 * свойством Text путём перебора всех дочерних элементов контейнера PrimarySkills
 *
 *При переборе всех дочерних эллементов контейнера PrimarySkills важно, чтобы
 *все эти эллементы были типа PrimarySkill. Если это не так, то эллемент будет
 *проигнорирован и выведено предупреждение.*/
void CharacterWindow::setTextPrimarySkills()
{
    for(auto* autoPS : ui->PrimarySkills->children()){
        if(dynamic_cast <PrimarySkill*> (autoPS)){
            PrimarySkill* ps = qobject_cast <PrimarySkill*> (autoPS);
            /*Метод устанавливает текст для подписи PrimarySkillSignature, при этом сам
             *текст извлекается из динамического свойства виджета Text.*/
            ps->getPrimarySkillSignature()->setText(ps->property("Text").toString());
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setTextPrimarySkills.\n"
            "Объект " + autoPS->objectName() + " не является PrimarySkill.\n\n";
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

//Установка стилей всех объектов
void CharacterWindow::setStyles()
{
    ui->ScrollAreaSecondarySkills->verticalScrollBar()->setSingleStep(6);

    /*Перебор всех дочерних эллементов контейнера SecondarySkills. Перебор
     *производится при помощи QGridLayout, из-за того, что контейнер - сетка.
     *Здесь важно, чтобы все эти эллементы были типа SecondarySkill. Если это
     *не так, то эллемент будет проигнорирован и выведено предупреждение.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(secondarySkillsGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                    SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                    /*Установка надписи на вторичном навыке и указание размера его шрифта
                     *при помощи динамических свойств.*/
                    ss->setInscription(ss->property("Inscription").toString());
                    ss->setFontSize(ss->property("FontSize").toInt());
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе setStyles.\n"
                            "Объект " + secondarySkillsGrid->itemAtPosition(row, column)->widget()->objectName() + " не является SecondarySkill.\n\n";
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
    }

    /*Изначально область прокрутки вторичных навыков находится в максимально верхней позиции.
     *А, по задумке, когда прокрутка доходит до того или иного конца, то соответствующая
     *тень пропадает. Соответственно, если область прокрутки сразу в максимально верхней
     *позиции, то и верхняя тень со старта должна быть убрана.*/
    ui->SecondarySkillsShadowTop->hide();

    ui->verticalScrollBar->setStyleSheet(GlobalStyleMaster::VerticalScrollBarStyle());

    /*Перебор всех дочерних эллементов контейнера ProgressBars. Здесь важно, чтобы все эти
     *эллементы были либо типа SecondarySkillProgressBar, либо MagicDefenseProgressBar.
     *Если это не так, то эллемент будет проигнорирован и выведено предупреждение.*/
    for(auto* autoFrame : ui->ProgressBars->children()){
        if(dynamic_cast <SecondarySkillProgressBar*> (autoFrame)){
            SecondarySkillProgressBar* secondarySkillProgressBar = qobject_cast <SecondarySkillProgressBar*> (autoFrame);
            //Установка цвета прогрессбара при помощи динамического свойства Color
            secondarySkillProgressBar->getProgressBar()->setColor(secondarySkillProgressBar->property("Color").toString());
            //Установка имени прогрессбара при помощи динамического свойства Name
            secondarySkillProgressBar->setName(secondarySkillProgressBar->property("Name").toString());
        }else if(dynamic_cast <MagicDefenseProgressBar*> (autoFrame)){
            MagicDefenseProgressBar* magicDefenseProgressBar = qobject_cast <MagicDefenseProgressBar*> (autoFrame);
            //Установка цвета прогрессбара при помощи динамического свойства Color
            magicDefenseProgressBar->getProgressBar()->setColor(magicDefenseProgressBar->property("Color").toString());
            //Установка имени прогрессбара при помощи динамического свойства Name
            magicDefenseProgressBar->setName(magicDefenseProgressBar->property("Name").toString());
        }else if(!dynamic_cast <QLayout*> (autoFrame)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setStyles.\n"
            "Объект " + autoFrame->objectName() + " не является QFrame.\n\n";
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

void CharacterWindow::associatingLabelsWithStat()
{
    ui->PrimarySkillStrength->setStat(person.getStats()->primaryStats->Strength);
    ui->PrimarySkillAgility->setStat(person.getStats()->primaryStats->Agility);
    ui->PrimarySkillIntelligence->setStat(person.getStats()->primaryStats->Intelligence);
    ui->PrimarySkillMagic->setStat(person.getStats()->primaryStats->Magic);
    ui->PrimarySkillBodyType->setStat(person.getStats()->primaryStats->BodyType);
    ui->PrimarySkillWill->setStat(person.getStats()->primaryStats->Will);

    ui->MagicDamage->setStat(person.getStats()->secondaryStats->MagicDamage);
    ui->ResistPhysicalDamage->setStat(person.getStats()->secondaryStats->ResistPhysicalDamage);
    ui->ResistMagicDamage->setStat(person.getStats()->secondaryStats->ResistMagicDamage);
    ui->ResistPhysicalEffects->setStat(person.getStats()->secondaryStats->ResistPhysicalEffects);
    ui->ResistMagicEffects->setStat(person.getStats()->secondaryStats->ResistMagicEffects);
    ui->StrengtheningPhysicalEffects->setStat(person.getStats()->secondaryStats->StrengtheningPhysicalEffects);
    ui->StrengtheningMagicalEffects->setStat(person.getStats()->secondaryStats->StrengtheningMagicalEffects);
    ui->MeleeAccuracy->setStat(person.getStats()->secondaryStats->MeleeAccuracy);
    ui->RangedAccuracy->setStat(person.getStats()->secondaryStats->RangedAccuracy);
    ui->MagicAccuracy->setStat(person.getStats()->secondaryStats->MagicAccuracy);
    ui->Evasion->setStat(person.getStats()->secondaryStats->Evasion);
    ui->Stealth->setStat(person.getStats()->secondaryStats->Stealth);
    ui->Attentiveness->setStat(person.getStats()->secondaryStats->Attentiveness);
    ui->LoadCapacity->setStat(person.getStats()->secondaryStats->LoadCapacity);
    ui->Initiative->setStat(person.getStats()->secondaryStats->Initiative);
    ui->MagicCastChance->setStat(person.getStats()->secondaryStats->MagicCastChance);
    ui->ChanceOfUsingCombatTechnique->setStat(person.getStats()->secondaryStats->ChanceOfUsingCombatTechnique);
    ui->MoveRange->setStat(person.getStats()->secondaryStats->MoveRange);

    ui->Health->getProgressBar()->setStat(person.getStats()->secondaryStats->Health);
    ui->Endurance->getProgressBar()->setStat(person.getStats()->secondaryStats->Endurance);
    ui->Mana->getProgressBar()->setStat(person.getStats()->secondaryStats->Mana);

    ui->MagicDefense->getProgressBar()->setStat(person.getStats()->secondaryStats->magicDefense);
}

/*Данный метод связывает все слоты показа и сокрытия подсказки у всех
 *необходимых элементов со слотами показа и сокрытия подсказки окна*/
void CharacterWindow::linkingTooltipSlots()
{
    /*Перебор всех дочерних эллементов контейнера PrimarySkills. Здесь важно
     *чтобы все эти эллементы были типа PrimarySkill. Если это не так, то
     *эллемент будет проигнорирован и выведено предупреждение.*/
    for(auto* autoPS : ui->PrimarySkills->children()){
        if(dynamic_cast <PrimarySkill*> (autoPS)){
            PrimarySkill* ps = qobject_cast <PrimarySkill*> (autoPS);
            connect(ps, &PrimarySkill::ShowTooltip, this, &CharacterWindow::ShowTooltip);
            connect(ps, &PrimarySkill::RemoveTooltip, this, &CharacterWindow::RemoveTooltip);
            connect(ps, &PrimarySkill::recalculateStats, this, &CharacterWindow::recalculateStats);
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе linkingTooltipSlots.\n"
            "Объект " + autoPS->objectName() + " не является PrimarySkill.\n\n";
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

    /*Перебор всех дочерних эллементов контейнера SecondarySkills. Здесь важно
     *чтобы все эти эллементы были типа SecondarySkill. Если это не так, то
     *эллемент будет проигнорирован и выведено предупреждение.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(secondarySkillsGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                    SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                    connect(ss, &SecondarySkill::ShowTooltip, this, &CharacterWindow::ShowTooltip, Qt::QueuedConnection);
                    connect(ss, &SecondarySkill::RemoveTooltip, this, &CharacterWindow::RemoveTooltip, Qt::QueuedConnection);
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе linkingTooltipSlots.\n"
                            "Объект " + secondarySkillsGrid->itemAtPosition(row, column)->widget()->objectName() + " не является SecondarySkill.\n\n";
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
    }

    /*Перебор всех дочерних эллементов контейнера ProgressBars. Здесь важно, чтобы все эти
     *эллементы были либо типа SecondarySkillProgressBar, либо MagicDefenseProgressBar.
     *Если это не так, то эллемент будет проигнорирован и выведено предупреждение.*/
    for(auto* autoFrame : ui->ProgressBars->children()){
        if(dynamic_cast <SecondarySkillProgressBar*> (autoFrame)){
            SecondarySkillProgressBar* secondarySkillProgressBar = qobject_cast <SecondarySkillProgressBar*> (autoFrame);

            connect(secondarySkillProgressBar->getProgressBar()->getLabelWithTooltip(), &LabelWithTooltip::ShowTooltip,
                    this, &CharacterWindow::ShowTooltip, Qt::QueuedConnection);
            connect(secondarySkillProgressBar->getProgressBar()->getLabelWithTooltip(), &LabelWithTooltip::RemoveTooltip,
                    this, &CharacterWindow::RemoveTooltip, Qt::QueuedConnection);
        }else if(dynamic_cast <MagicDefenseProgressBar*> (autoFrame)){
            MagicDefenseProgressBar* magicDefenseProgressBar = qobject_cast <MagicDefenseProgressBar*> (autoFrame);

            connect(magicDefenseProgressBar->getProgressBar()->getLabelWithTooltip(), &LabelWithTooltip::ShowTooltip,
                    this, &CharacterWindow::ShowTooltip, Qt::QueuedConnection);
            connect(magicDefenseProgressBar->getProgressBar()->getLabelWithTooltip(), &LabelWithTooltip::RemoveTooltip,
                    this, &CharacterWindow::RemoveTooltip, Qt::QueuedConnection);
        }else if(!dynamic_cast <QLayout*> (autoFrame)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setStyles.\n"
            "Объект " + autoFrame->objectName() + " не является QFrame.\n\n";
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

//В методе происходит полный перерасчёт всех вторичных навыков
void CharacterWindow::recalculateStats()
{
    //Непосредственно перерасчёт делается в классе Person
    person.recalculateStats();
    //Обновление отображения статов
    refreshDisplayStats();
}

//Инициализация элементов интерфеса связанных со статами значениями из Person
void CharacterWindow::initSecondaryStatsWidgets()
{
    /*Перебор всех дочерних эллементов контейнера SecondarySkills. Здесь важно
     *чтобы все эти эллементы были типа SecondarySkill. Если это не так, то
     *эллемент будет проигнорирован и выведено предупреждение.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(secondarySkillsGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                    SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                    ss->init();
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе linkingTooltipSlots.\n"
                            "Объект " + secondarySkillsGrid->itemAtPosition(row, column)->widget()->objectName() + " не является SecondarySkill.\n\n";
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
    }

    /*Перебор всех дочерних эллементов контейнера ProgressBars. Здесь важно, чтобы все эти
     *эллементы были либо типа SecondarySkillProgressBar, либо MagicDefenseProgressBar.
     *Если это не так, то эллемент будет проигнорирован и выведено предупреждение.*/
    for(auto* autoFrame : ui->ProgressBars->children()){
        if(dynamic_cast <SecondarySkillProgressBar*> (autoFrame)){
            SecondarySkillProgressBar* secondarySkillProgressBar = qobject_cast <SecondarySkillProgressBar*> (autoFrame);
            ProgressBar_1* PB_1 = secondarySkillProgressBar->getProgressBar();
            PB_1->init();
        }else if(dynamic_cast <MagicDefenseProgressBar*> (autoFrame)){
            MagicDefenseProgressBar* magicDefenseProgressBar = qobject_cast <MagicDefenseProgressBar*> (autoFrame);
            ProgressBar_2* PB_2 = magicDefenseProgressBar->getProgressBar();
            PB_2->init();
        }else if(!dynamic_cast <QLayout*> (autoFrame)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setStyles.\n"
            "Объект " + autoFrame->objectName() + " не является QFrame.\n\n";
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

void CharacterWindow::healthSetValue(int value)
{
    person.getStats()->secondaryStats->Health->setProgressBarCurrentValue(value);
    ui->Health->getProgressBar()->setValue(value);
}

void CharacterWindow::enduranceSetValue(int value)
{
    person.getStats()->secondaryStats->Endurance->setProgressBarCurrentValue(value);
    ui->Endurance->getProgressBar()->setValue(value);
}

void CharacterWindow::manaSetValue(int value)
{
    person.getStats()->secondaryStats->Mana->setProgressBarCurrentValue(value);
    ui->Mana->getProgressBar()->setValue(value);
}


//Заполнение контентом подсказок элементов на основе их динамических свойств
void CharacterWindow::tooltipInitialization()
{
    /*Перебор всех дочерних эллементов контейнера PrimarySkills. Здесь важно
     *чтобы все эти эллементы были типа PrimarySkill. Если это не так, то эллемент будет
     *проигнорирован и выведено предупреждение.*/
    for(auto* autoPS : ui->PrimarySkills->children()){
        if(dynamic_cast <PrimarySkill*> (autoPS)){
            PrimarySkill* ps = qobject_cast <PrimarySkill*> (autoPS);
            ps->getPrimarySkillSignature()->setTooltipContent(ps->property("FullName").toString(), ps->property("Description").toString());
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе associatingLabelsWithValues.\n"
            "Объект " + autoPS->objectName() + " не является PrimarySkill.\n\n";
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

    /*Перебор всех дочерних эллементов контейнера SecondarySkills. Перебор
     *производится при помощи QGridLayout, из-за того, что контейнер - сетка.
     *Здесь важно, чтобы все эти эллементы были типа SecondarySkill. Если это
     *не так, то эллемент будет проигнорирован и выведено предупреждение.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(secondarySkillsGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                    SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                    ss->setTooltipContent(ss->property("FullName").toString(), ss->property("Formula").toString(), ss->property("Description").toString());
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе setStyles.\n"
                            "Объект " + secondarySkillsGrid->itemAtPosition(row, column)->widget()->objectName() + " не является SecondarySkill.\n\n";
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
    }

    /*Перебор всех дочерних эллементов контейнера ProgressBars. Здесь важно, чтобы все эти
     *эллементы были либо типа SecondarySkillProgressBar, либо MagicDefenseProgressBar.
     *Если это не так, то эллемент будет проигнорирован и выведено предупреждение.*/
    for(auto* autoFrame : ui->ProgressBars->children()){
        if(dynamic_cast <SecondarySkillProgressBar*> (autoFrame)){
            SecondarySkillProgressBar* secondarySkillProgressBar = qobject_cast <SecondarySkillProgressBar*> (autoFrame);
            ProgressBar_1* PB_1 = secondarySkillProgressBar->getProgressBar();
            PB_1->setTooltipContent(secondarySkillProgressBar->property("Name").toString(),
                                    secondarySkillProgressBar->property("Formula").toString(),
                                    secondarySkillProgressBar->property("FormulaFontSize").toInt(),
                                    secondarySkillProgressBar->property("Description").toString());
        }else if(dynamic_cast <MagicDefenseProgressBar*> (autoFrame)){
            MagicDefenseProgressBar* magicDefenseProgressBar = qobject_cast <MagicDefenseProgressBar*> (autoFrame);
            ProgressBar_2* PB_2 = magicDefenseProgressBar->getProgressBar();
            PB_2->setTooltipContent(magicDefenseProgressBar->property("Name").toString(),
                                    magicDefenseProgressBar->property("NumberOfChunksFormula").toString(),
                                    magicDefenseProgressBar->property("ChunkValueFormula").toString(),
                                    magicDefenseProgressBar->property("Description").toString());
        }else if(!dynamic_cast <QLayout*> (autoFrame)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setStyles.\n"
            "Объект " + autoFrame->objectName() + " не является QFrame.\n\n";
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

/*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
 *Считаются только Ctrl,Shift и Alt*/
void CharacterWindow::keyPressEvent(QKeyEvent *event)
{
    bool ValueInFocus = false;
    for(auto* autoPS : ui->PrimarySkills->children()){
        if(dynamic_cast <PrimarySkill*> (autoPS)){
            PrimarySkill* ps = qobject_cast <PrimarySkill*> (autoPS);
            if(ps->getPrimarySkillSignature()->hasFocus()){
                ValueInFocus = true;
                break;
            }
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе associatingLabelsWithValues.\n"
            "Объект " + autoPS->objectName() + " не является PrimarySkill.\n\n";
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

    if(!ValueInFocus){
        int key=event->key();
        if(key==16777249||key==16777248||key==16777251)
            Global::pressedKeys.append(key);
    }
}

/*Эвент отжатия клавиши, который находит и удаляет код клавиши из вектора pressedKeys.
 *Сделано это для того, чтобы обрабатывать случай, когда зажато несколько модификаторов
 *одновременно. Они не будут последовательно обработаны, считаться будет только последний,
 *но если просто сбрасывать int переменную, то может возникать случай, когда второй
 *модификатор будет зажат до отжатия предыдущего, а затем первый будет отжат, и управление
 *как бы "заест", модификатор придётся жать вновь. Для избежания этого и создан этот вектор.*/
void CharacterWindow::keyReleaseEvent(QKeyEvent *event)
{
    int key=event->key();
    QMutableVectorIterator<int> keyIterator(Global::pressedKeys);

    /*Так как вектор pressedKeys доступен многим виджетам одновременно, гипотетически
     *возможна ситуация когда фокус получат одновременно несколько виджетов, и они
     *начнут отправлять в вектор дубликаты ключей зажатых клавиш. Для просчёта
     *модификаторов это никакой проблемы не создаст, но возможна ситуация когда до
     *отжатия клавиши один или несколько таких виджетов, передавших ключи клавиш,
     *потеряют фокус, соответственно ключи переданные ими не удалятся из вектора.
     *И для избежания такой ситуации итератор проходит по всему вектору, удаляя из
     *него все вхождения переданного ключа, а не первое. Подразумевается что этот
     *метод будет вызван хотя бы 1 раз из любого виджета в фокусе.*/
    while(keyIterator.hasNext()) {
      int currentValue=keyIterator.next();

      if(currentValue==key)
        keyIterator.remove();
    }
}

void CharacterWindow::leaveEvent(QEvent *event)
{
    Global::pressedKeys.clear();
}

/*Слот изменения позиции скролла области прокрутки CharacterWindow.
 *Здесь, при прокрутке, во-первых проверяется на сколько близко текущее положение области прокрутки к краю.
 *Если оно менее чем на 7 пикселей приблизилось к краю, то соответствующая тень у виджета пропадает. 7
 *пикселей здесь как запас, равный вертикальному размеру тени. Этот запас создан для случаев, когда при
 *скролле, пользователь вроде бы и докрутил до конца, но не добрал всего пару пикселей до самого-самого края,
 *и тень не пропала, хотя визуально ей бы уже пора было пропасть.*/
void CharacterWindow::ScrollAreaSecondarySkillsScrolled(int value)
{
    if(value > 7)
        ui->SecondarySkillsShadowTop->show();
    else
        ui->SecondarySkillsShadowTop->hide();

    /*296 - это максимальный сдвиг области прокрутки относительно стартовой позии с
     *учётом запаса в 3 пикселей.*/
    if(value < 296)
        ui->SecondarySkillsShadowBottom->show();
    else
        ui->SecondarySkillsShadowBottom->hide();

    /*Связывание области прокрутки со скроллбаром. Используется не встроенный в
     *область прокрутки скроллбар, а отдельный, другой для удобства позиционирования
     *и более простого и понятного доступа до его слотов.*/
    ui->verticalScrollBar->setValue(value);
}

void CharacterWindow::on_verticalScrollBar_actionTriggered(int action)
{
    /*Звук проигрывается только при нажатии на стрелки прибавки и убавки.
     *Цифры в проверке - это id этих ивентов*/
    if(action==1||action==2)
        Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);
}

/*Связывание области прокрутки со скроллбаром. Используется не встроенный в
 *область прокрутки скроллбар, а отдельный, другой для удобства позиционирования
 *и более простого и понятного доступа до его слотов.*/
void CharacterWindow::on_verticalScrollBar_valueChanged(int value)
{
    //При скролле скроллбара подсказка пропадает так как всё-равно окошко стата уезжает
    RemoveTooltip();

    ui->ScrollAreaSecondarySkills->verticalScrollBar()->setValue(value);

    /*Передача во все SecondarySkill размера смещения их ScrollArea для последующей обработки
     *выведения подсказки при усечении SecondarySkill внутри ScrollArea.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(secondarySkillsGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                    SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                    ss->setScrollAreaOffset(value);
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе on_verticalScrollBar_valueChanged.\n"
                            "Объект " + secondarySkillsGrid->itemAtPosition(row, column)->widget()->objectName() + " не является SecondarySkill.\n\n";
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
    }
}

void CharacterWindow::ShowTooltip(QVector<QLabel*> TooltipContent)
{
    if(!ui->tooltip->isVisible())
        ui->tooltip->setContent(TooltipContent);
    ui->tooltip->setVisible(true);

    QPoint position = QCursor::pos()-QPoint(ui->tooltip->invisibleFrame.width()/2, ui->tooltip->invisibleFrame.height()/2);

    if(position.x() + ui->tooltip->width() - ui->tooltip->invisibleFrame.width()/2 > this->width())
        position.setX(this->width() - ui->tooltip->width() + ui->tooltip->invisibleFrame.width()/2);

    if(position.y() + ui->tooltip->height() - ui->tooltip->invisibleFrame.height()/2 > this->height())
        position.setY(this->height() - ui->tooltip->height() + ui->tooltip->invisibleFrame.height()/2);

    ui->tooltip->move(QWidget::mapFromGlobal(position));
}

void CharacterWindow::RemoveTooltip()
{
    ui->tooltip->setVisible(false);
}

//Метод обновляющий отображение всех статов, инициализируя виджеты данными из класса Person
void CharacterWindow::refreshDisplayStats()
{
    for(auto* autoPS : ui->PrimarySkills->children()){
        if(dynamic_cast <PrimarySkill*> (autoPS)){
            PrimarySkill* ps = qobject_cast <PrimarySkill*> (autoPS);

            if(!ps->isManualStatReplacement)
                ps->init();
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                    "CharacterWindow выдал предупреждение в методе setTextPrimarySkills.\n"
                    "Объект " + autoPS->objectName() + " не является PrimarySkill.\n\n";
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
    //Задание значения воли, для подсказки, требуемой до получения нового чанка магической защиты
    ui->MagicDefense->getProgressBar()->willUntilNextChunk = person.getStats()->secondaryStats->magicDefense->getWillUntilNextChunk();
    //Инициализация получеными значениями
    initSecondaryStatsWidgets();
}

void CharacterWindow::on_pushButton_4_clicked()
{
    healthSetValue(person.getStats()->secondaryStats->Health->getFinalValue());
    enduranceSetValue(person.getStats()->secondaryStats->Endurance->getFinalValue());
    manaSetValue(person.getStats()->secondaryStats->Mana->getFinalValue());

    person.getStats()->secondaryStats->magicDefense->HealAllChunk();
//    ui->MagicDefense->getProgressBar()->setValue(person.getStats()->secondaryStats->magicDefense->getValue());
}

void CharacterWindow::on_pushButton_clicked()
{
    person.addBonusToStat(new Bonus("Strength", 10, false, "Тест увеличения силы", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_2_clicked()
{
    person.removeBonusFromStat(new Bonus("Strength", 10, false, "Тест увеличения силы", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_3_clicked()
{
    person.addBonusToStat(new Bonus("Agility", 17, true, "Тест увеличения ловкости", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_5_clicked()
{
    person.removeBonusFromStat(new Bonus("Agility", 17, true, "Тест увеличения ловкости", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_6_clicked()
{
    person.addBonusToStat(new Bonus("Intelligence", -9, false, "Тест уменьшения интеллекта", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_9_clicked()
{
    person.removeBonusFromStat(new Bonus("Intelligence", -9, false, "Тест уменьшения интеллекта", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_10_clicked()
{
    person.addBonusToStat(new Bonus("Magic", -28, true, "Тест уменьшения магии", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_11_clicked()
{
    person.removeBonusFromStat(new Bonus("Magic", -28, true, "Тест уменьшения магии", 1, 1, 1, 1));
}

void CharacterWindow::on_pushButton_8_clicked()
{
    ui->Inventory->addRowOfCellsToInventory();
}

void CharacterWindow::on_pushButton_7_clicked()
{
    ui->Inventory->removeRowOfCellsFromInventory();
}

void CharacterWindow::on_pushButton_17_clicked()
{
    person.addBonusToStat(new Bonus("Health", 3, false, "Бонус 1", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", 8, false, "Бонус 2", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", 1, true, "Бонус 4", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", 23, false, "Бонус 5", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", -2, false, "Дебаф 1", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", -100, false, "Дебаф 2", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", 25, true, "Бонус 6", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", -19, true, "Дебаф 3", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", 249, false, "Бонус 7", 1, 1, 1, 1));
    person.addBonusToStat(new Bonus("Health", 47, true, "Бонус 8", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_13_clicked()
{
    person.removeBonusFromStat(new Bonus("Health", 3, false, "Бонус 1", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", 8, false, "Бонус 2", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", 1, true, "Бонус 4", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", 23, false, "Бонус 5", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", -2, false, "Дебаф 1", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", -100, false, "Дебаф 2", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", 25, true, "Бонус 6", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", -19, true, "Дебаф 3", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", 249, false, "Бонус 7", 1, 1, 1, 1));
    person.removeBonusFromStat(new Bonus("Health", 47, true, "Бонус 8", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_21_clicked()
{
    person.addBonusToStat(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition::CENTER, 10, false, "Бонус к центральной ячейке", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_18_clicked()
{
    person.addBonusToStat(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition::FIRST, 13, true, "Бонус к первой ячейке", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_20_clicked()
{
    person.addBonusToStat(new MagicDefenseBonus(3, 18, false, "Бонус к третей ячейке", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_16_clicked()
{
    person.addBonusToStat(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition::ALL, 1, true, "Бонус ко всем ячейкам", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_19_clicked()
{
    person.addBonusToStat(new MagicDefenseBonus(QVector<int>{134, 5, 9, 12}, "Бонусные ячейки 1", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_15_clicked()
{
    person.addBonusToStat(new MagicDefenseBonus(QVector<int>{3, 2, 1, 4}, "Бонусные ячейки 2", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_12_clicked()
{
    person.removeBonusFromStat(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition::ALL, 1, true, "Бонус ко всем ячейкам", 1, 1, 1, 1));
}


void CharacterWindow::on_pushButton_14_clicked()
{
    ui->FPSCounter->setActive(!ui->FPSCounter->active);
}

void CharacterWindow::on_SaveButton_clicked()
{
    person.saveAllStats(true);
}

void CharacterWindow::on_LoadButton_clicked()
{
    person.loadAllStats();
}
