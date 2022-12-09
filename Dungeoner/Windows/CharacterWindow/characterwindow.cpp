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
    connect(&person, &Person::StrengthBonusesChanged, this, &CharacterWindow::onStrengthBonusesChanged);
    connect(&person, &Person::AgilityBonusesChanged, this, &CharacterWindow::onAgilityBonusesChanged);
    connect(&person, &Person::IntelligenceBonusesChanged, this, &CharacterWindow::onIntelligenceBonusesChanged);
    connect(&person, &Person::MagicBonusesChanged, this, &CharacterWindow::onMagicBonusesChanged);
    connect(&person, &Person::BodyTypeBonusesChanged, this, &CharacterWindow::onBodyTypeBonusesChanged);
    connect(&person, &Person::WillBonusesChanged, this, &CharacterWindow::onWillBonusesChanged);

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

            //Временная заглушка для прогрессбара магической защиты
//            magicDefenseProgressBar->getProgressBar()->setBonusChunks(QVector<Chunk*>{new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100)});
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
    ui->StrengthPrimarySkillSignature->setStat(person.getStrength());
    ui->AgilityPrimarySkillSignature->setStat(person.getAgility());
    ui->IntelligencePrimarySkillSignature->setStat(person.getIntelligence());
    ui->MagicPrimarySkillSignature->setStat(person.getMagic());
    ui->BodyTypePrimarySkillSignature->setStat(person.getBodyType());
    ui->WillPrimarySkillSignature->setStat(person.getWill());

    ui->MagicDamage->setStat(person.getMagicDamage());
    ui->ResistPhysicalDamage->setStat(person.getResistPhysicalDamage());
    ui->ResistMagicDamage->setStat(person.getResistMagicDamage());
    ui->ResistPhysicalEffects->setStat(person.getResistPhysicalEffects());
    ui->ResistMagicEffects->setStat(person.getResistMagicEffects());
    ui->StrengtheningPhysicalEffects->setStat(person.getStrengtheningPhysicalEffects());
    ui->StrengtheningMagicalEffects->setStat(person.getStrengtheningMagicalEffects());
    ui->MeleeAccuracy->setStat(person.getMeleeAccuracy());
    ui->RangedAccuracy->setStat(person.getRangedAccuracy());
    ui->MagicAccuracy->setStat(person.getMagicAccuracy());
    ui->Evasion->setStat(person.getEvasion());
    ui->Stealth->setStat(person.getStealth());
    ui->Attentiveness->setStat(person.getAttentiveness());
    ui->LoadCapacity->setStat(person.getLoadCapacity());
    ui->Initiative->setStat(person.getInitiative());
    ui->MagicCastChance->setStat(person.getMagicCastChance());
    ui->ChanceOfUsingCombatTechnique->setStat(person.getChanceOfUsingCombatTechnique());
    ui->MoveRange->setStat(person.getMoveRange());

    ui->Health->getProgressBar()->setStat(person.getHealth());
    ui->Endurance->getProgressBar()->setStat(person.getEndurance());
    ui->Mana->getProgressBar()->setStat(person.getMana());

//    ui->MagicDefense->getProgressBar()->setStat(magicDefense->getChunks(), magicDefense->getTotalValue(),
//                                                  magicDefense->getAmountOfNativeChunks(), magicDefense->getAmountOfBonusChunks(), magicDefense->getValue());
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
    ui->StrengthValue->setValue(person.getStrength()->getFinalValue());

    ui->AgilityValue->setValue(person.getAgility()->getFinalValue());

    ui->IntelligenceValue->setValue(person.getIntelligence()->getFinalValue());

    ui->MagicValue->setValue(person.getMagic()->getFinalValue());

    ui->BodyTypeValue->setValue(person.getBodyType()->getFinalValue());

    ui->WillValue->setValue(person.getWill()->getFinalValue());
}

//Инициализация элементов интерфеса связанных со статами значениями из Person
void CharacterWindow::initSecondaryStatsWidgets()
{
    ui->MagicDamage->setValue(person.getMagicDamage()->getFinalValue());
    ui->ResistPhysicalDamage->setValue(person.getResistPhysicalDamage()->getFinalValue());
    ui->ResistMagicDamage->setValue(person.getResistMagicDamage()->getFinalValue());
    ui->ResistPhysicalEffects->setValue(person.getResistPhysicalEffects()->getFinalValue());
    ui->ResistMagicEffects->setValue(person.getResistMagicEffects()->getFinalValue());
    ui->StrengtheningPhysicalEffects->setValue(person.getStrengtheningPhysicalEffects()->getFinalValue());
    ui->StrengtheningMagicalEffects->setValue(person.getStrengtheningMagicalEffects()->getFinalValue());
    ui->MeleeAccuracy->setValue(person.getMeleeAccuracy()->getFinalValue());
    ui->RangedAccuracy->setValue(person.getRangedAccuracy()->getFinalValue());
    ui->MagicAccuracy->setValue(person.getMagicAccuracy()->getFinalValue());
    ui->Evasion->setValue(person.getEvasion()->getFinalValue());
    ui->Stealth->setValue(person.getStealth()->getFinalValue());
    ui->Attentiveness->setValue(person.getAttentiveness()->getFinalValue());
    ui->LoadCapacity->setValue(person.getLoadCapacity()->getFinalValue());
    ui->Initiative->setValue(person.getInitiative()->getFinalValue());
    ui->MagicCastChance->setValue(person.getMagicCastChance()->getFinalValue());
    ui->ChanceOfUsingCombatTechnique->setValue(person.getChanceOfUsingCombatTechnique()->getFinalValue());
    ui->MoveRange->setValue(person.getMoveRange()->getFinalValue());

    ui->Health->getProgressBar()->setMaxValue(person.getHealth()->getFinalValue());
    healthSetValue(person.getHealth()->getProgressBarCurrentValue());
    ui->Endurance->getProgressBar()->setMaxValue(person.getEndurance()->getFinalValue());
    enduranceSetValue(person.getEndurance()->getProgressBarCurrentValue());
    ui->Mana->getProgressBar()->setMaxValue(person.getMana()->getFinalValue());
    manaSetValue(person.getMana()->getProgressBarCurrentValue());

    MagicDefense* magicDefense = person.getMagicDefense();
    ui->MagicDefense->getProgressBar()->setChunks(magicDefense->getChunks(), magicDefense->getTotalValue(),
                                                  magicDefense->getAmountOfNativeChunks(), magicDefense->getAmountOfBonusChunks(), magicDefense->getValue());
}

void CharacterWindow::healthSetValue(int value)
{
    person.getHealth()->setProgressBarCurrentValue(value);
    ui->Health->getProgressBar()->setValue(value);
}

void CharacterWindow::enduranceSetValue(int value)
{
    person.getEndurance()->setProgressBarCurrentValue(value);
    ui->Endurance->getProgressBar()->setValue(value);
}

void CharacterWindow::manaSetValue(int value)
{
    person.getMana()->setProgressBarCurrentValue(value);
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
            ui->StrengthValue->setValue(person.getStrength()->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->StrengthValue->setValue(person.getStrength()->getFinalValue());
        }
    }

    if(object == ui->AgilityValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->AgilityValue->setValue(person.getAgility()->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->AgilityValue->setValue(person.getAgility()->getFinalValue());
        }
    }

    if(object == ui->IntelligenceValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->IntelligenceValue->setValue(person.getIntelligence()->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->IntelligenceValue->setValue(person.getIntelligence()->getFinalValue());
        }
    }

    if(object == ui->MagicValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->MagicValue->setValue(person.getMagic()->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->MagicValue->setValue(person.getMagic()->getFinalValue());
        }
    }

    if(object == ui->BodyTypeValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->BodyTypeValue->setValue(person.getBodyType()->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->BodyTypeValue->setValue(person.getBodyType()->getFinalValue());
        }
    }

    if(object == ui->WillValue){
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->WillValue->setValue(person.getWill()->getValue());
        }
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->WillValue->setValue(person.getWill()->getFinalValue());
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

void CharacterWindow::onStrengthBonusesChanged()
{
    if(!isManualStatReplacement){
        ui->StrengthValue->setValue(person.getStrength()->getFinalValue());
    }
}

void CharacterWindow::onAgilityBonusesChanged()
{
    if(!isManualStatReplacement){
        ui->AgilityValue->setValue(person.getAgility()->getFinalValue());
    }
}

void CharacterWindow::onIntelligenceBonusesChanged()
{
    if(!isManualStatReplacement){
        ui->IntelligenceValue->setValue(person.getIntelligence()->getFinalValue());
    }
}

void CharacterWindow::onMagicBonusesChanged()
{
    if(!isManualStatReplacement){
        ui->MagicValue->setValue(person.getMagic()->getFinalValue());
    }
}

void CharacterWindow::onBodyTypeBonusesChanged()
{
    if(!isManualStatReplacement){
        ui->BodyTypeValue->setValue(person.getBodyType()->getFinalValue());
    }
}

void CharacterWindow::onWillBonusesChanged()
{
    if(!isManualStatReplacement){
        ui->WillValue->setValue(person.getWill()->getFinalValue());
    }
}

//Метод обновляющий отображение всех статов, инициализируя виджеты данными из класса Person
void CharacterWindow::refreshDisplayStats()
{
    //Задание значения воли, для подсказки, требуемой до получения нового чанка магической защиты
    ui->MagicDefense->getProgressBar()->willUntilNextChunk = person.willUntilNextChunk;
    //Инициализация получеными значениями
    initSecondaryStatsWidgets();
}

void CharacterWindow::on_StrengthValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getStrength()->setValue(arg1);
    }
    recalculateStats();
}


void CharacterWindow::on_AgilityValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getAgility()->setValue(arg1);
    }
    recalculateStats();
}


void CharacterWindow::on_IntelligenceValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getIntelligence()->setValue(arg1);
    }
    recalculateStats();
}


void CharacterWindow::on_MagicValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getMagic()->setValue(arg1);
    }
    recalculateStats();
}


void CharacterWindow::on_BodyTypeValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getBodyType()->setValue(arg1);
    }
    recalculateStats();
}


void CharacterWindow::on_WillValue_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        person.getWill()->setValue(arg1);
    }
    recalculateStats();
}


void CharacterWindow::on_pushButton_4_clicked()
{
    healthSetValue(person.getHealth()->getFinalValue());
    enduranceSetValue(person.getEndurance()->getFinalValue());
    manaSetValue(person.getMana()->getFinalValue());

    person.getMagicDefense()->HealAllChunk();
    ui->MagicDefense->getProgressBar()->setValue(person.getMagicDefense()->getValue());
}


void CharacterWindow::on_pushButton_clicked()
{
    person.addBonusToStat(new Bonus(Bonus::HEALTH, 10, false, "Проклятие чорота эля"));
    recalculateStats();
}


void CharacterWindow::on_pushButton_2_clicked()
{
    person.removeBonusFromStat(new Bonus(Bonus::HEALTH, 10, false, "Проклятие чорота эля"));
    recalculateStats();
}


void CharacterWindow::on_pushButton_3_clicked()
{
}

