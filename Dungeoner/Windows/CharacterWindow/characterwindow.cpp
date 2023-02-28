/***************************************************
 *Окно персонажа, содержащее всю информацию о нём
 ***************************************************/

#include "characterwindow.h"
#include "qevent.h"
#include "ui_characterwindow.h"
#include "CW_stylemaster.h"

#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QSpinBox>
#include <QScrollBar>
#include <QMutableVectorIterator>
#include <CustomWidgets/Item/item.h>

CharacterWindow::CharacterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWindow)
{
    ui->setupUi(this);
    //Убирание рамки окна
    this->setWindowFlags(Qt::FramelessWindowHint);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    ui->StrengthValue->installEventFilter(this);
    ui->AgilityValue->installEventFilter(this);
    ui->IntelligenceValue->installEventFilter(this);
    ui->MagicValue->installEventFilter(this);
    ui->BodyTypeValue->installEventFilter(this);
    ui->WillValue->installEventFilter(this);

    setTextPrimarySkillSignature();
    setStyles();

    initPrimaryStatsWidgets();

    associatingLabelsWithValues();
    associatingLabelsWithStat();

    //Связывание слотов изменения первичных навыков бонусами с сигналами сигнализирующими об этом
    connect(person.getStats()->primaryStats->Strength, &Stat::statChanged, this, &CharacterWindow::onStrengthChanged);
    connect(person.getStats()->primaryStats->Agility, &Stat::statChanged, this, &CharacterWindow::onAgilityChanged);
    connect(person.getStats()->primaryStats->Intelligence, &Stat::statChanged, this, &CharacterWindow::onIntelligenceChanged);
    connect(person.getStats()->primaryStats->Magic, &Stat::statChanged, this, &CharacterWindow::onMagicChanged);
    connect(person.getStats()->primaryStats->BodyType, &Stat::statChanged, this, &CharacterWindow::onBodyTypeChanged);
    connect(person.getStats()->primaryStats->Will, &Stat::statChanged, this, &CharacterWindow::onWillChanged);

    //Связывание слота полной переинициализации из класса person с обновлением отображения статов
    connect(&person, &Person::FullReinitializationRequest, this, &CharacterWindow::refreshDisplayStats);

    /*Связывание слота ScrollAreaSecondarySkillsScrolled с сигналом valueChanged у вертикального скроллбара в области
     *прокрутки ScrollAreaSecondarySkills. Делается это потому, что у убласти прокрутки мне нужен сигнал изменения
     *положения прокрутки. Внезапно вдруг такого не имеется. Но имеется сигнал valueChanged у скроллбара внутри
     *области прокрутки, что собственно и есть то, что мне и нужно. Для этого я и связываю его сигнал с моим слотом*/
    connect(ui->ScrollAreaSecondarySkills->verticalScrollBar(), &QAbstractSlider::valueChanged,
            this, &CharacterWindow::ScrollAreaSecondarySkillsScrolled);
    /*Связывание слота InventoryScrollAreaScrolled с сигналом valueChanged
     *у вертикального скроллбара в области прокрутки ScrollAreaSecondarySkills.*/
    connect(ui->InventoryScrollArea->verticalScrollBar(), &QScrollBar::valueChanged,
            this, &CharacterWindow::InventoryScrollAreaScrolled);
    /*По умолчанию скроллбар инвентаря имеет максимум в 0. Любое изменение количества
     *ячеек инвентаря переопределит это значение, когда то будет нужно.*/
    ui->InventoryScrollBar->setMaximum(0);

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


    //!!!
    for(int i = 0; i<4; i++)
        addRowOfCellsToInventory();

//    ui->SkillsWraper->setVisible(false);
//    ui->SecondarySkillsWraper->setVisible(false);
//    ui->ScrollAreaWraper->setVisible(false);
//    ui->ProgressBars->setVisible(false);
//    ui->InventoryWrapper->setVisible(false);
}

CharacterWindow::~CharacterWindow()
{
    delete ui;
}

/*Установка текста для подписи первичного навыка в соответствии с его динамическим свойством
 *Text путём перебора всех дочерних элементов контейнера PrimarySkillSignatures.
 *
 *При переборе всех дочерних эллементов контейнера PrimarySkillSignatures важно, чтобы
 *все эти эллементы были типа PrimarySkillSignature. Если это не так, то эллемент будет
 *проигнорирован и выведено предупреждение.*/
void CharacterWindow::setTextPrimarySkillSignature()
{
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            /*Метод устанавливает текст для подписи PrimarySkillSignature, при этом сам
             *текст извлекается из динамического свойства виджета Text.*/
            pss->setText(pss->property("Text").toString());
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setTextPrimarySkillSignature.\n"
            "Объект " + autoPSS->objectName() + " не является PrimarySkillSignature.\n\n";
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

    ui->InventoryScrollArea->verticalScrollBar()->setSingleStep(10);
    ui->InventoryScrollBar->setStyleSheet(CW_StyleMaster::VerticalScrollBarStyle());

    /*Перебор всех дочерних эллементов контейнера PrimarySkillValues. Здесь важно,
     *чтобы все эти эллементы были типа QSpinBox. Если это не так, то эллемент будет
     *проигнорирован и выведено предупреждение.*/
    for(auto* autoSB : ui->PrimarySkillValues->children()){
        if(dynamic_cast <QSpinBox*> (autoSB)){
            QSpinBox* sb = qobject_cast <QSpinBox*> (autoSB);
            /*Метод устанавливает стиль для SpinBox, при этом размер
             *шрифта извлекается из динамического свойства виджета fontSize.*/
            sb->setStyleSheet(CW_StyleMaster::SpinBoxStyle(sb->property("fontSize").toInt()));
            sb->setFont(QFont("NumbersFont"));
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе setStyles.\n"
            "Объект " + autoSB->objectName() + " не является QSpinBox.\n\n";
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

    ui->verticalScrollBar->setStyleSheet(CW_StyleMaster::VerticalScrollBarStyle());

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

/*В данном методе связываются подписи с их значениями в QSpinBox путём передачи
 *указателя на QSpinBox в переменную SpinBoxValue класса PrimarySkillSignature.
 *Делается это для работы кнопок больше и меньше.*/
void CharacterWindow::associatingLabelsWithValues()
{
    int i = 0;
    /*Перебор всех дочерних эллементов контейнера PrimarySkillSignatures. Здесь важно
     *чтобы все эти эллементы были типа QSpinBox. Если это не так, то эллемент будет
     *проигнорирован и выведено предупреждение.*/
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            if(dynamic_cast <QSpinBox*> (ui->PrimarySkillValues->children().at(i))){
                /*SpinBoxValue - это указатель в классе PrimarySkillSignature. Здесь
                 *происходит передача в него соответствующего указателя на QSpinBox*/
                pss->setSpinBoxValue(qobject_cast <QSpinBox*> (ui->PrimarySkillValues->children().at(i)));
            }else{
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                "CharacterWindow выдал предупреждение в методе associatingLabelsWithValues.\n"
                "Объект " + ui->PrimarySkillValues->children().at(i)->objectName() + " не является QSpinBox.\n\n";
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
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе associatingLabelsWithValues.\n"
            "Объект " + autoPSS->objectName() + " не является PrimarySkillSignature.\n\n";
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
        ++i;
    }
}

void CharacterWindow::associatingLabelsWithStat()
{
    ui->StrengthPrimarySkillSignature->setStat(person.getStats()->primaryStats->Strength);
    ui->AgilityPrimarySkillSignature->setStat(person.getStats()->primaryStats->Agility);
    ui->IntelligencePrimarySkillSignature->setStat(person.getStats()->primaryStats->Intelligence);
    ui->MagicPrimarySkillSignature->setStat(person.getStats()->primaryStats->Magic);
    ui->BodyTypePrimarySkillSignature->setStat(person.getStats()->primaryStats->BodyType);
    ui->WillPrimarySkillSignature->setStat(person.getStats()->primaryStats->Will);

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
    /*Перебор всех дочерних эллементов контейнера PrimarySkillSignatures. Здесь важно
     *чтобы все эти эллементы были типа PrimarySkillSignature. Если это не так, то
     *эллемент будет проигнорирован и выведено предупреждение.*/
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            connect(pss->getlabelWithTooltip(), &LabelWithTooltip::ShowTooltip,
                    this, &CharacterWindow::ShowTooltip);
            connect(pss->getlabelWithTooltip(), &LabelWithTooltip::RemoveTooltip,
                    this, &CharacterWindow::RemoveTooltip);

            connect(pss, &PrimarySkillSignature::ShowTooltip,
                    this, &CharacterWindow::ShowTooltip);
            connect(pss, &PrimarySkillSignature::RemoveTooltip,
                    this, &CharacterWindow::RemoveTooltip);
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе linkingTooltipSlots.\n"
            "Объект " + autoPSS->objectName() + " не является PrimarySkillSignature.\n\n";
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
                    connect(ss, &SecondarySkill::ShowTooltip,
                            this, &CharacterWindow::ShowTooltip, Qt::QueuedConnection);
                    connect(ss, &SecondarySkill::RemoveTooltip,
                            this, &CharacterWindow::RemoveTooltip, Qt::QueuedConnection);
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

void CharacterWindow::initPrimaryStatsWidgets()
{
    ui->StrengthValue->setValue(person.getStats()->primaryStats->Strength->getFinalValue());

    ui->AgilityValue->setValue(person.getStats()->primaryStats->Agility->getFinalValue());

    ui->IntelligenceValue->setValue(person.getStats()->primaryStats->Intelligence->getFinalValue());

    ui->MagicValue->setValue(person.getStats()->primaryStats->Magic->getFinalValue());

    ui->BodyTypeValue->setValue(person.getStats()->primaryStats->BodyType->getFinalValue());

    ui->WillValue->setValue(person.getStats()->primaryStats->Will->getFinalValue());
}

//Инициализация элементов интерфеса связанных со статами значениями из Person
void CharacterWindow::initSecondaryStatsWidgets()
{
    ui->MagicDamage->setValue(person.getStats()->secondaryStats->MagicDamage->getFinalValue());
    ui->ResistPhysicalDamage->setValue(person.getStats()->secondaryStats->ResistPhysicalDamage->getFinalValue());
    ui->ResistMagicDamage->setValue(person.getStats()->secondaryStats->ResistMagicDamage->getFinalValue());
    ui->ResistPhysicalEffects->setValue(person.getStats()->secondaryStats->ResistPhysicalEffects->getFinalValue());
    ui->ResistMagicEffects->setValue(person.getStats()->secondaryStats->ResistMagicEffects->getFinalValue());
    ui->StrengtheningPhysicalEffects->setValue(person.getStats()->secondaryStats->StrengtheningPhysicalEffects->getFinalValue());
    ui->StrengtheningMagicalEffects->setValue(person.getStats()->secondaryStats->StrengtheningMagicalEffects->getFinalValue());
    ui->MeleeAccuracy->setValue(person.getStats()->secondaryStats->MeleeAccuracy->getFinalValue());
    ui->RangedAccuracy->setValue(person.getStats()->secondaryStats->RangedAccuracy->getFinalValue());
    ui->MagicAccuracy->setValue(person.getStats()->secondaryStats->MagicAccuracy->getFinalValue());
    ui->Evasion->setValue(person.getStats()->secondaryStats->Evasion->getFinalValue());
    ui->Stealth->setValue(person.getStats()->secondaryStats->Stealth->getFinalValue());
    ui->Attentiveness->setValue(person.getStats()->secondaryStats->Attentiveness->getFinalValue());
    ui->LoadCapacity->setValue(person.getStats()->secondaryStats->LoadCapacity->getFinalValue());
    ui->Initiative->setValue(person.getStats()->secondaryStats->Initiative->getFinalValue());
    ui->MagicCastChance->setValue(person.getStats()->secondaryStats->MagicCastChance->getFinalValue());
    ui->ChanceOfUsingCombatTechnique->setValue(person.getStats()->secondaryStats->ChanceOfUsingCombatTechnique->getFinalValue());
    ui->MoveRange->setValue(person.getStats()->secondaryStats->MoveRange->getFinalValue());

    ui->Health->getProgressBar()->setMaxValue(person.getStats()->secondaryStats->Health->getFinalValue());
    healthSetValue(person.getStats()->secondaryStats->Health->getProgressBarCurrentValue());
    ui->Endurance->getProgressBar()->setMaxValue(person.getStats()->secondaryStats->Endurance->getFinalValue());
    enduranceSetValue(person.getStats()->secondaryStats->Endurance->getProgressBarCurrentValue());
    ui->Mana->getProgressBar()->setMaxValue(person.getStats()->secondaryStats->Mana->getFinalValue());
    manaSetValue(person.getStats()->secondaryStats->Mana->getProgressBarCurrentValue());

    MagicDefense* magicDefense = person.getStats()->secondaryStats->magicDefense;
    ui->MagicDefense->getProgressBar()->setChunks(magicDefense->getChunks(), magicDefense->getTotalValue(),
                                                  magicDefense->getAmountOfNativeChunks(), magicDefense->getAmountOfBonusChunks(), magicDefense->getValue());
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
    int i = 0;
    /*Перебор всех дочерних эллементов контейнера PrimarySkillSignatures. Здесь важно
     *чтобы все эти эллементы были типа QSpinBox. Если это не так, то эллемент будет
     *проигнорирован и выведено предупреждение.*/
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            if(dynamic_cast <QSpinBox*> (ui->PrimarySkillValues->children().at(i))){
                pss->setTooltipContent(pss->property("FullName").toString(), pss->property("Description").toString());
            }else{
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                "CharacterWindow выдал предупреждение в методе associatingLabelsWithValues.\n"
                "Объект " + ui->PrimarySkillValues->children().at(i)->objectName() + " не является QSpinBox.\n\n";
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
        }else{
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
            "CharacterWindow выдал предупреждение в методе associatingLabelsWithValues.\n"
            "Объект " + autoPSS->objectName() + " не является PrimarySkillSignature.\n\n";
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
        ++i;
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
    if(!ui->StrengthValue->hasFocus()&&!ui->AgilityValue->hasFocus()&&!ui->IntelligenceValue->hasFocus()&&
            !ui->MagicValue->hasFocus()&&!ui->BodyTypeValue->hasFocus()&&!ui->WillValue->hasFocus()){
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

bool CharacterWindow::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->StrengthValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->StrengthValue->setValue(person.getStats()->primaryStats->Strength->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->StrengthValue->setValue(person.getStats()->primaryStats->Strength->getFinalValue());
        }
    }

    if(object == ui->AgilityValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->AgilityValue->setValue(person.getStats()->primaryStats->Agility->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->AgilityValue->setValue(person.getStats()->primaryStats->Agility->getFinalValue());
        }
    }

    if(object == ui->IntelligenceValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->IntelligenceValue->setValue(person.getStats()->primaryStats->Intelligence->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->IntelligenceValue->setValue(person.getStats()->primaryStats->Intelligence->getFinalValue());
        }
    }

    if(object == ui->MagicValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->MagicValue->setValue(person.getStats()->primaryStats->Magic->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->MagicValue->setValue(person.getStats()->primaryStats->Magic->getFinalValue());
        }
    }

    if(object == ui->BodyTypeValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->BodyTypeValue->setValue(person.getStats()->primaryStats->BodyType->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->BodyTypeValue->setValue(person.getStats()->primaryStats->BodyType->getFinalValue());
        }
    }

    if(object == ui->WillValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->WillValue->setValue(person.getStats()->primaryStats->Will->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->WillValue->setValue(person.getStats()->primaryStats->Will->getFinalValue());
        }
    }

    return false;
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

void CharacterWindow::InventoryScrollAreaScrolled(int value)
{
    ui->InventoryScrollBar->setValue(value);
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

void CharacterWindow::onStrengthChanged()
{
    if(!isManualStatReplacement){
        ui->StrengthValue->setValue(person.getStats()->primaryStats->Strength->getFinalValue());
    }
}

void CharacterWindow::onAgilityChanged()
{
    if(!isManualStatReplacement){
        ui->AgilityValue->setValue(person.getStats()->primaryStats->Agility->getFinalValue());
    }
}

void CharacterWindow::onIntelligenceChanged()
{
    if(!isManualStatReplacement){
        ui->IntelligenceValue->setValue(person.getStats()->primaryStats->Intelligence->getFinalValue());
    }
}

void CharacterWindow::onMagicChanged()
{
    if(!isManualStatReplacement){
        ui->MagicValue->setValue(person.getStats()->primaryStats->Magic->getFinalValue());
    }
}

void CharacterWindow::onBodyTypeChanged()
{
    if(!isManualStatReplacement){
        ui->BodyTypeValue->setValue(person.getStats()->primaryStats->BodyType->getFinalValue());
    }
}

void CharacterWindow::onWillChanged()
{
    if(!isManualStatReplacement){
        ui->WillValue->setValue(person.getStats()->primaryStats->Will->getFinalValue());
    }
}

//Метод обновляющий отображение всех статов, инициализируя виджеты данными из класса Person
void CharacterWindow::refreshDisplayStats()
{
    if(!isManualStatReplacement)
        initPrimaryStatsWidgets();
    //Задание значения воли, для подсказки, требуемой до получения нового чанка магической защиты
    ui->MagicDefense->getProgressBar()->willUntilNextChunk = person.getStats()->secondaryStats->magicDefense->getWillUntilNextChunk();
    //Инициализация получеными значениями
    initSecondaryStatsWidgets();
}

//Добавление новой линии пустых ячеек в инвентарь
void CharacterWindow::addRowOfCellsToInventory()
{
    /*В строке всегда 10 ячеек, так что вычислить количество строк легко. Преимущество такого способа перед
     *rowCount в том, что rowCount возвращет 1, даже если строк вообще нет, а тут результат однозначный.*/
    int row = ui->Inventory->count()/10;

    /*row показывает текущее количество строк. Учитывая, что одна сейчас прибавися, row 3 означает, что
     *в таблице будет 4 строки, а 4 строки - это тот размер таблицы, который прокрутки не требует.*/
    if(row>3){
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        ui->scrollAreaWidgetContents_2->setFixedHeight(308 + 70*(row-3) + 4*(row-4));
        //Установка максимума скроллбаров равного суммарной высоте с учётом отствупов всех строк после четвёртой.
        int maximum = 70*(row-3) + 4*(row-4);
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(maximum);
        ui->InventoryScrollBar->setMaximum(maximum);
    }else{
        //Иначе прокрутка не требуется, и максимум скроллбаров обнуляется
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(0);
        ui->InventoryScrollBar->setMaximum(0);
    }

    //Создание новой строки ячеек
    for(int i = 0; i<10; i++){
        InventoryCell* cell = new InventoryCell();
        cell->setFixedSize(68, 68);
        /*Учитывая что row всегда показывает текущее количество ячеек, то есть на
         *1 меньше, чем будет, то его можно вставлять как индекс с отсчётом от 0*/
        ui->Inventory->addWidget(cell, row, i, Qt::AlignTop);

        QRect rect = cell->geometry();
        rect.setY(5 + 74*row);
        cell->setGeometry(rect);

        //!!!отладка
        //////////////////////////////////////////////
        if(/*true*/((i == 0)||(i == 2)) && ui->Inventory->count()<10){
        Item* item = new Item("Test", QVector<Item::ItemType>(Item::ONE_HANDED_SWORD), "Меч");

        item->isPressable = true;
        item->isNew = true;
//        item->isDisabled = true;
        if(/*true*/i == 2 && ui->Inventory->count()<10){
                item->setMaxDurability(1);
                item->setCurrentDurability(0);
        }
        item->setQuantity(999);
        item->setId(0);

        cell->setItem(item);
        }
        /////////////////////////////////////////////

        cell->setScrollAreaHeight(ui->InventoryScrollArea->height());
        cell->setScrollAreaOffset(ui->InventoryScrollBar->value());

        cell->cellHidingCheck();
    }
}

//Удаление последней линии ячеек в инвентаре
void CharacterWindow::removeRowOfCellsFromInventory()
{
    /*В строке всегда 10 ячеек, так что вычислить количество строк легко. Преимущество такого способа перед
     *rowCount в том, что rowCount возвращет 1, даже если строк вообще нет, а тут результат однозначный.*/
    int row = ui->Inventory->count()/10;

    /*row показывает текущее количество строк. Учитывая, что одна сейчас удалится, row 5 означает, что в
     *таблице останется 4 строки, а 4 строки - это тот размер таблицы, который прокрутки не требует.*/
    if(row>5){
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        ui->scrollAreaWidgetContents_2->setFixedHeight(308 + 70*(row-5) + 4*(row-6));
        //Установка максимума скроллбаров равного суммарной высоте с учётом отствупов всех строк после четвёртой.
        int maximum = 70*(row-5) + 4*(row-6);
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(maximum);
        ui->InventoryScrollBar->setMaximum(maximum);
    }else{
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        ui->scrollAreaWidgetContents_2->setFixedHeight(304);
        //Иначе прокрутка не требуется, и максимум скроллбаров обнуляется
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(0);
        ui->InventoryScrollBar->setMaximum(0);
    }

    //В инвентаре не может быть менее 4 строк
    if(row<=4)
        return;

    //Удаление строки ячеек
    for(int i = 0; i<10; i++){
        //Учитывая что row всегда показывает текущее количество ячеек, то его надо привести к индексу с отсчётом от 0
        delete ui->Inventory->itemAtPosition(row-1, i)->widget();
        ui->Inventory->removeItem(ui->Inventory->itemAtPosition(row-1, i));
    }
}

void CharacterWindow::on_StrengthValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStats()->primaryStats->Strength->setValue(arg1);
    }
    recalculateStats();
}

void CharacterWindow::on_AgilityValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStats()->primaryStats->Agility->setValue(arg1);
    }
    recalculateStats();
}

void CharacterWindow::on_IntelligenceValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStats()->primaryStats->Intelligence->setValue(arg1);
    }
    recalculateStats();
}

void CharacterWindow::on_MagicValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStats()->primaryStats->Magic->setValue(arg1);
    }
    recalculateStats();
}

void CharacterWindow::on_BodyTypeValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStats()->primaryStats->BodyType->setValue(arg1);
    }
    recalculateStats();
}

void CharacterWindow::on_WillValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStats()->primaryStats->Will->setValue(arg1);
    }
    recalculateStats();
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
    addRowOfCellsToInventory();
}

void CharacterWindow::on_pushButton_7_clicked()
{
    removeRowOfCellsFromInventory();
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

void CharacterWindow::on_InventoryScrollBar_valueChanged(int value)
{
    //При скролле скроллбара подсказка пропадает так как всё-равно окошко стата уезжает
    RemoveTooltip();

    ui->InventoryScrollArea->verticalScrollBar()->setValue(value);

    /*Передача во все InventoryCell размера смещения их ScrollArea для последующей обработки выведения
     *подсказки при усечении InventoryCell внутри ScrollArea и для сокрытия неуместившихся ячеек.*/
    QGridLayout *inventoryGrid = qobject_cast <QGridLayout*> (ui->Inventory->layout());
    for(int row = 0; row < inventoryGrid->rowCount(); row++)
    {
        for (int column = 0; column < inventoryGrid->columnCount(); column++)
        {
            if(inventoryGrid->itemAtPosition(row, column)!=0){
                if(dynamic_cast <InventoryCell*> (inventoryGrid->itemAtPosition(row, column)->widget())){
                    InventoryCell* ic = qobject_cast <InventoryCell*> (inventoryGrid->itemAtPosition(row, column)->widget());
                    ic->setScrollAreaOffset(value);
                }else{
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nПРЕДУПРЕЖДЕНИЕ: неверный тип данных\n"
                            "CharacterWindow выдал предупреждение в методе on_InventoryScrollBar_valueChanged.\n"
                            "Объект " + inventoryGrid->itemAtPosition(row, column)->widget()->objectName() + " не является InventoryCell.\n\n";
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

void CharacterWindow::on_InventoryScrollBar_actionTriggered(int action)
{
    /*Звук проигрывается только при нажатии на стрелки прибавки и убавки.
     *Цифры в проверке - это id этих ивентов*/
    if(action==1||action==2)
        Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);
}
