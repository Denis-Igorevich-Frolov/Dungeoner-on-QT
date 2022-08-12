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
#include <QGraphicsDropShadowEffect>
#include <QScrollBar>

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

    linkingTooltipSlots();

    /*Передача во все SecondarySkill высоты их ScrollArea для последующей обработки
     *выведения подсказки при усечении SecondarySkill внутри ScrollArea. Само собой
     *программа не подразумевает последующиее изменение размера SecondarySkills,
     *если же такая потребность возникнет, то этот кусок кода надо переместить в
     *метод resize.
     *
     *При переборе всех дочерних эллементов контейнера SecondarySkills важно, чтобы
     *все эти эллементы были типа SecondarySkill. Если это не так, то эллемент будет
     *проигнорирован и выведена ошибка.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                ss->setScrollAreaHeight(ui->ScrollAreaSecondarySkills->height());
            }else{
                //Вывод логов ошибки в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: неверный тип данных\n"
                        "CharacterWindow выдал исключение в методе CharacterWindow.\n"
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

    ui->widget->setMaxValue(100);
    ui->widget->setValue(100);
    ui->widget->setColor(QColor("#9e17cf"));
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
 *проигнорирован и выведена ошибка.*/
void CharacterWindow::setTextPrimarySkillSignature()
{
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            /*Метод устанавливает текст для подписи PrimarySkillSignature, при этом сам
             *текст извлекается из динамического свойства виджета Text.*/
            pss->setText(pss->property("Text").toString());
        }else{
            //Вывод логов ошибки в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: неверный тип данных\n"
            "CharacterWindow выдал исключение в методе setTextPrimarySkillSignature.\n"
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
    /*Перебор всех дочерних эллементов контейнера PrimarySkillValues. Здесь важно,
     *чтобы все эти эллементы были типа QSpinBox. Если это не так, то эллемент будет
     *проигнорирован и выведена ошибка.*/
    for(auto* autoSB : ui->PrimarySkillValues->children()){
        if(dynamic_cast <QSpinBox*> (autoSB)){
            QSpinBox* sb = qobject_cast <QSpinBox*> (autoSB);
            /*Метод устанавливает стиль для SpinBox, при этом размер
             *шрифта извлекается из динамического свойства виджета fontSize.*/
            sb->setStyleSheet(CW_StyleMaster::SpinBoxStyle(sb->property("fontSize").toInt()));
        }else{
            //Вывод логов ошибки в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: неверный тип данных\n"
            "CharacterWindow выдал исключение в методе setStyles.\n"
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
     *не так, то эллемент будет проигнорирован и выведена ошибка.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                /*Установка надписи на вторичном навыке и указание размера его шрифта
                 *при помощи динамических свойств.*/
                ss->setInscription(ss->property("Inscription").toString());
                ss->setFontSize(ss->property("FontSize").toInt());
            }else{
                //Вывод логов ошибки в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: неверный тип данных\n"
                        "CharacterWindow выдал исключение в методе setStyles.\n"
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

    /*Изначально область прокрутки вторичных навыков находится в максимально верхней позиции.
     *А, по задумке, когда прокрутка доходит до того или иного конца, то соответствующая
     *тень пропадает. Соответственно, если область прокрутки сразу в максимально верхней
     *позиции, то и верхняя тень со старта должна быть убрана.*/
    ui->SecondarySkillsShadowTop->hide();

    ui->verticalScrollBar->setStyleSheet(CW_StyleMaster::VerticalScrollBarStyle());

    for(auto* autoFrame : ui->ProgressBars->children()){
        if(dynamic_cast <SecondarySkillProgressBar*> (autoFrame)){
            SecondarySkillProgressBar* secondarySkillProgressBar = qobject_cast <SecondarySkillProgressBar*> (autoFrame);
            secondarySkillProgressBar->setColor(secondarySkillProgressBar->property("Color").toString());
            secondarySkillProgressBar->setName(secondarySkillProgressBar->property("Name").toString());

            secondarySkillProgressBar->setMaxValue(100);
            secondarySkillProgressBar->setValue(100);
        }else if(!dynamic_cast <QLayout*> (autoFrame)){
            //Вывод логов ошибки в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: неверный тип данных\n"
            "CharacterWindow выдал исключение в методе setStyles.\n"
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
     *проигнорирован и выведена ошибка.*/
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            if(dynamic_cast <QSpinBox*> (ui->PrimarySkillValues->children().at(i))){
                /*SpinBoxValue - это указатель в классе PrimarySkillSignature. Здесь
                 *происходит передача в него соответствующего указателя на QSpinBox*/
                pss->SpinBoxValue = qobject_cast <QSpinBox*> (ui->PrimarySkillValues->children().at(i));
            }else{
                //Вывод логов ошибки в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                "\nОШИБКА: неверный тип данных\n"
                "CharacterWindow выдал исключение в методе associatingLabelsWithValues.\n"
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
            //Вывод логов ошибки в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: неверный тип данных\n"
            "CharacterWindow выдал исключение в методе associatingLabelsWithValues.\n"
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
     *эллемент будет проигнорирован и выведена ошибка.*/
    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            connect(pss->getlabelWithTooltip(), &LabelWithTooltip::ShowTooltip,
                    this, &CharacterWindow::ShowTooltip);
            connect(pss->getlabelWithTooltip(), &LabelWithTooltip::RemoveTooltip,
                    this, &CharacterWindow::RemoveTooltip);
        }else{
            //Вывод логов ошибки в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: неверный тип данных\n"
            "CharacterWindow выдал исключение в методе linkingTooltipSlots.\n"
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
     *эллемент будет проигнорирован и выведена ошибка.*/
    QGridLayout *secondarySkillsGrid = qobject_cast <QGridLayout*> (ui->SecondarySkills->layout());
    for(int row = 0; row < secondarySkillsGrid->rowCount(); row++)
    {
        for (int column = 0; column < secondarySkillsGrid->columnCount(); column++)
        {
            if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                connect(ss, &SecondarySkill::ShowTooltip,
                        this, &CharacterWindow::ShowTooltip, Qt::QueuedConnection);
                connect(ss, &SecondarySkill::RemoveTooltip,
                        this, &CharacterWindow::RemoveTooltip, Qt::QueuedConnection);
            }else{
                //Вывод логов ошибки в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: неверный тип данных\n"
                        "CharacterWindow выдал исключение в методе linkingTooltipSlots.\n"
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
        Global::mediaplaer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);
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
            if(dynamic_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget())){
                SecondarySkill* ss = qobject_cast <SecondarySkill*> (secondarySkillsGrid->itemAtPosition(row, column)->widget());
                ss->setScrollAreaOffset(value);
            }else{
                //Вывод логов ошибки в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: неверный тип данных\n"
                        "CharacterWindow выдал исключение в методе on_verticalScrollBar_valueChanged.\n"
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

void CharacterWindow::ShowTooltip()
{
    qDebug() <<QTime::currentTime()<< "show";
}

void CharacterWindow::RemoveTooltip()
{
    qDebug() <<QTime::currentTime()<< "leave";
}

