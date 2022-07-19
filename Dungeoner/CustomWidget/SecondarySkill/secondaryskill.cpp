#include "secondaryskill.h"
#include "ui_secondaryskill.h"
#include "stylemaster.h"

SecondarySkill::SecondarySkill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondarySkill)
{
    ui->setupUi(this);

    shadow1 = new QGraphicsDropShadowEffect(this);
    shadow1->setOffset(1, 1);
    shadow1->setColor(QColor(32, 29, 16));

    ui->Inscription->setStyleSheet(StyleMaster::SecondarySkillInscriptionStyle(12));
    ui->Inscription->setGraphicsEffect(shadow1);

    shadow2 = new QGraphicsDropShadowEffect(this);
    shadow2->setOffset(1, 1);
    shadow2->setColor(QColor(32, 29, 16));

    ui->Value->setStyleSheet(StyleMaster::SecondarySkillValueStyle());
    ui->Value->setGraphicsEffect(shadow2);

    setValue(0);
}

SecondarySkill::~SecondarySkill()
{
    delete ui;
    delete shadow1;
    delete shadow2;
}

long SecondarySkill::getValue() const
{
    return value;
}

void SecondarySkill::setValue(long newValue)
{
    SValue = "<p style=\"line-height:%1%;\">%2</p>";

    if(newValue>9999999)
        newValue = 9999999;
    value = newValue;

    QString sValue;
    QString finalValue;
    sValue.setNum(value);
    if(sValue.size()!=0){
        int j = 0;
        for(int i = sValue.size(); i>0; --i){
            finalValue.prepend(sValue[i-1]);
            ++j;
            if(sValue.size()!=3 && j==3){
                j = 0;
                finalValue.prepend(' ');
            }
        }
    }
    SValue = SValue.arg(70).arg(finalValue);
    ui->Value->setText(SValue);
}

void SecondarySkill::setInscription(QString inscription)
{
    ui->Inscription->setText(inscription);
}

void SecondarySkill::setFontSize(int size)
{
    ui->Inscription->setStyleSheet(StyleMaster::SecondarySkillInscriptionStyle(size));
}
