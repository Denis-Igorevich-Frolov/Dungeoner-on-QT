/*
 *Окно персонажа, содержащее всю информацию о нём
 */

#include "characterwindow.h"
#include "ui_characterwindow.h"
#include ".\CustomWidget\PrimarySkillSignature\primaryskillsignature.h"

#include <QGridLayout>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTime>

CharacterWindow::CharacterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWindow)
{
    ui->setupUi(this);
    //Убирание рамки окна
    this->setWindowFlags(Qt::FramelessWindowHint);

    setTextPrimarySkillSignature();
}

CharacterWindow::~CharacterWindow()
{
    delete ui;
}

void CharacterWindow::setTextPrimarySkillSignature()
{
    /*Установка текста для подписи первичного навыка в соответствии с его динамическим свойством
     *Text путём перебора всех дочерних элементов контейнера PrimarySkillSignatures
     */

    for(auto* autoPSS : ui->PrimarySkillSignatures->children()){
        if(dynamic_cast <PrimarySkillSignature*> (autoPSS)){
            PrimarySkillSignature* pss = qobject_cast <PrimarySkillSignature*> (autoPSS);
            pss->setText(pss->property("Text").toString());
        }else{
            //Вывод логов ошибки в кончоль и файл
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
