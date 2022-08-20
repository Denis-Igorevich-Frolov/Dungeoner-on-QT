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

QVector<int> CharacterWindow::pressedKeys;

CharacterWindow::CharacterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWindow)
{
    ui->setupUi(this);
    //Убирание рамки окна
    this->setWindowFlags(Qt::FramelessWindowHint);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    setTextPrimarySkillSignature();
    setStyles();
    associatingLabelsWithValues();

    /*Связывание слота ScrollAreaSecondarySkillsScrolled с сигналом valueChanged у вертикального скроллбара в области
     *прокрутки ScrollAreaSecondarySkills. Делается это потому, что у убласти прокрутки мне нужен сигнал изменения
     *положения прокрутки. Внезапно вдруг такого не имеется. Но имеется сигнал valueChanged у скроллбара внутри
     *области прокрутки, что собственно и есть то, что мне и нужно. Для этого я и связываю его сигнал с моим слотом*/
    connect(ui->ScrollAreaSecondarySkills->verticalScrollBar(), &QAbstractSlider::valueChanged,
            this, &CharacterWindow::ScrollAreaSecondarySkillsScrolled);

    /*Отключение у теней скроллбара вторичных навыков возможности принимать фокус
     *и ивенты мыши, чтобы они не перекравали непосредственно вторичные навыки*/
    ui->SecondarySkillsShadowTop->setFocusPolicy(Qt::NoFocus);
    ui->SecondarySkillsShadowTop->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->SecondarySkillsShadowBottom->setFocusPolicy(Qt::NoFocus);
    ui->SecondarySkillsShadowBottom->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->tooltip->setFocusPolicy(Qt::NoFocus);
    ui->tooltip->setAttribute(Qt::WA_TransparentForMouseEvents);
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

            magicDefenseProgressBar->getProgressBar()->setChunks(QVector<Chunk*>{
            new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100),new Chunk(100,100)});
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
                pss->SpinBoxValue = qobject_cast <QSpinBox*> (ui->PrimarySkillValues->children().at(i));
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

void CharacterWindow::recalculateStats()
{
    long physicalDamage = 0;
    if(physicalDamageScaling == Global::STRENGTH)
        physicalDamage = floor(2.5 * ui->StrengthValue->value()) + ui->AgilityValue->value();
    else if (physicalDamageScaling == Global::AGILITY)
        physicalDamage = floor(2.5 * ui->AgilityValue->value()) + ui->StrengthValue->value();
    else if (physicalDamageScaling == Global::MAGIC)
        physicalDamage = floor(1.5 * ui->MagicValue->value()) + ui->IntelligenceValue->value() + ui->AgilityValue->value();
    ui->PhysicalDamage->setValue(physicalDamage);

    long magicDamage =
    floor(1.5 * ui->MagicValue->value()) + floor(1.5 * ui->IntelligenceValue->value()) + floor(0.5 * ui->WillValue->value());
    ui->MagicDamage->setValue(magicDamage);

    long resistPhysicalDamage = floor(1.5 * ui->WillValue->value()) + floor(0.5 * ui->MagicValue->value()) + ui->BodyTypeValue->value();
    ui->ResistPhysicalDamage->setValue(resistPhysicalDamage);

    long resistMagicDamage = floor(1.5 * ui->WillValue->value()) + floor(0.5 * ui->BodyTypeValue->value()) + ui->MagicValue->value();
    ui->ResistMagicDamage->setValue(resistMagicDamage);

    long resistPhysicalEffects = floor(0.1 * ui->WillValue->value()) + 10;
    ui->ResistPhysicalEffects->setValue(resistPhysicalEffects);

    long resistMagicEffects = floor(0.1 * ui->WillValue->value()) + floor(0.1 * ui->MagicValue->value()) + 5;
    ui->ResistMagicEffects->setValue(resistMagicEffects);

    long strengtheningPhysicalEffects = floor(0.1 * ui->StrengthValue->value());
    ui->StrengtheningPhysicalEffects->setValue(strengtheningPhysicalEffects);

    long strengtheningMagicalEffects = floor(0.1 * ui->IntelligenceValue->value());
    ui->StrengtheningMagicalEffects->setValue(strengtheningMagicalEffects);

    long meleeAccuracy = floor(0.1 * ui->AgilityValue->value()) + 20;
    ui->MeleeAccuracy->setValue(meleeAccuracy);

    long rangedAccuracy = floor(0.1 * ui->AgilityValue->value()) + 15;
    ui->RangedAccuracy->setValue(rangedAccuracy);

    long magicAccuracy = floor(0.1 * ui->IntelligenceValue->value()) + 15;
    ui->MagicAccuracy->setValue(magicAccuracy);

    long evasion = floor(0.5 * ui->AgilityValue->value()) + floor(0.1 * ui->BodyTypeValue->value());
    ui->Evasion->setValue(evasion);

    long stealth = ui->IntelligenceValue->value() + ui->AgilityValue->value();
    ui->Stealth->setValue(stealth);

    long attentiveness = ui->IntelligenceValue->value() + ui->AgilityValue->value() + ui->WillValue->value();
    ui->Attentiveness->setValue(attentiveness);

    long loadCapacity = floor(0.5 * ui->StrengthValue->value()) + floor(0.5 * ui->BodyTypeValue->value());
    ui->LoadCapacity->setValue(loadCapacity);

    long initiative = floor(0.5 * ui->AgilityValue->value()) + ui->IntelligenceValue->value() + ui->WillValue->value();
    ui->Initiative->setValue(initiative);

    long magicCastChance = floor(0.3 * ui->IntelligenceValue->value()) + floor(0.2 * ui->MagicValue->value());
    ui->MagicCastChance->setValue(magicCastChance);

    long chanceOfUsingCombatTechnique = floor(0.2 * ui->AgilityValue->value()) + 20;
    ui->ChanceOfUsingCombatTechnique->setValue(chanceOfUsingCombatTechnique);

    long moveRange = floor(0.75 * ui->AgilityValue->value()) + floor(0.5 * ui->StrengthValue->value()) + ui->BodyTypeValue->value();
    ui->MoveRange->setValue(moveRange);

    long health = ui->StrengthValue->value() * 2 + ui->BodyTypeValue->value() * 10 + ui->WillValue->value() * 5 + ui->MagicValue->value();
    ui->Health->getProgressBar()->setMaxValue(health);

    long endurance = ui->AgilityValue->value() * 10 + ui->BodyTypeValue->value();
    ui->Endurance->getProgressBar()->setMaxValue(endurance);

    long mana = ui->MagicValue->value() * 10 + ui->IntelligenceValue->value() * 2 + ui->WillValue->value();
    ui->Mana->getProgressBar()->setMaxValue(mana);
}

/*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
 *Считаются только Ctrl,Shift и Alt*/
void CharacterWindow::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    if(key==16777249||key==16777248||key==16777251)
        pressedKeys.append(key);
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
    QMutableVectorIterator<int> keyIterator(pressedKeys);

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

    /*377 - это максимальный сдвиг области прокрутки относительно стартовой позии с
     *учётом запаса в 7 пикселей.*/
    if(value < 377)
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
    ui->ScrollAreaSecondarySkills->verticalScrollBar()->setValue(value);

    /*!!!Передача во все SecondarySkill размера смещения их ScrollArea для последующей обработки
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
    qDebug() <<QTime::currentTime()<< "show";
    if(!ui->tooltip->isVisible())
        ui->tooltip->setContent(TooltipContent);
    ui->tooltip->setVisible(true);
    ui->tooltip->move(QWidget::mapFromGlobal(QCursor::pos()-QPoint(15, 15)));
}

void CharacterWindow::RemoveTooltip()
{
    qDebug() <<QTime::currentTime()<< "leave";
    ui->tooltip->setVisible(false);
}


void CharacterWindow::on_pushButton_clicked()
{
    physicalDamageScaling = Global::STRENGTH;
    recalculateStats();
}


void CharacterWindow::on_pushButton_2_clicked()
{
    physicalDamageScaling = Global::AGILITY;
    recalculateStats();
}


void CharacterWindow::on_pushButton_3_clicked()
{
    physicalDamageScaling = Global::MAGIC;
    recalculateStats();
}


void CharacterWindow::on_StrengthValue_valueChanged(int arg1)
{
    recalculateStats();
}


void CharacterWindow::on_AgilityValue_valueChanged(int arg1)
{
    recalculateStats();
}


void CharacterWindow::on_IntelligenceValue_valueChanged(int arg1)
{
    recalculateStats();
}


void CharacterWindow::on_MagicValue_valueChanged(int arg1)
{
    recalculateStats();
}


void CharacterWindow::on_BodyTypeValue_valueChanged(int arg1)
{
    recalculateStats();
}


void CharacterWindow::on_WillValue_valueChanged(int arg1)
{
    recalculateStats();
}


void CharacterWindow::on_pushButton_4_clicked()
{
    ui->Health->getProgressBar()->setValue(ui->Health->getProgressBar()->getMaxValue());
    ui->Endurance->getProgressBar()->setValue(ui->Endurance->getProgressBar()->getMaxValue());
    ui->Mana->getProgressBar()->setValue(ui->Mana->getProgressBar()->getMaxValue());
}

