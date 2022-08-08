/*Окно персонажа, содержащее всю информацию о нём*/

#include "characterwindow.h"
#include "qevent.h"
#include "ui_characterwindow.h"
#include ".\CustomWidgets\PrimarySkillSignature\primaryskillsignature.h"
#include "stylemaster.h"

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

    connect(ui->PhysicalDamage, &SecondarySkill::ShowTooltip,
            this, &CharacterWindow::ShowTooltip, Qt::QueuedConnection);
    connect(ui->PhysicalDamage, &SecondarySkill::RemoveTooltip,
            this, &CharacterWindow::RemoveTooltip, Qt::QueuedConnection);

    connect(ui->StrengthPrimarySkillSignature->getlabelWithTooltip(), &LabelWithTooltip::ShowTooltip,
            this, &CharacterWindow::ShowTooltip);
    connect(ui->StrengthPrimarySkillSignature->getlabelWithTooltip(), &LabelWithTooltip::RemoveTooltip,
            this, &CharacterWindow::RemoveTooltip);

    ui->widget->setMaxValue(100);
    ui->widget->setColor(QColor(255,0,0));
}

CharacterWindow::~CharacterWindow()
{
    delete ui;
}

/*Установка текста для подписи первичного навыка в соответствии с его динамическим свойством
 *Text путём перебора всех дочерних элементов контейнера PrimarySkillSignatures*/
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
            sb->setStyleSheet(StyleMaster::SpinBoxStyle(sb->property("fontSize").toInt()));
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

    ui->verticalScrollBar->setStyleSheet(StyleMaster::VerticalScrollBarStyle());

//    ui->widget->Redraw();
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
                "CharacterWindow выдал исключение в методе setStyles.\n"
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
        ++i;
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
    /*Звук проигрывается при любом взаимодействии со скроллбаром, кроме
     *тех случаев, когда на его ползунок нажимают. Соответственно звучать
     *будут только нажатия на стрелки прибавки и убавки и на нажатия в
     *тело скроллбара.*/
    if(!ui->verticalScrollBar->isSliderDown())
        Global::mediaplaer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);
}

/*Связывание области прокрутки со скроллбаром. Используется не встроенный в
 *область прокрутки скроллбар, а отдельный, другой для удобства позиционирования
 *и более простого и понятного доступа до его слотов.*/
void CharacterWindow::on_verticalScrollBar_valueChanged(int value)
{
    ui->ScrollAreaSecondarySkills->verticalScrollBar()->setValue(value);
}

void CharacterWindow::ShowTooltip()
{
    qDebug() <<QTime::currentTime()<< "show";
}

void CharacterWindow::RemoveTooltip()
{
    qDebug() <<QTime::currentTime()<< "leave";
}

void CharacterWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setValue(value);
}

