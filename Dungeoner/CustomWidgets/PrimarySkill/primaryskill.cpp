/***************************************************************************************************************
 *Данный класс является виджетом первичного навыка. Он обединяет в себе PrimarySkillSignature и его Spinbox
 ***************************************************************************************************************/

#include "primaryskill.h"
#include "ui_primaryskill.h"
#include "PS_styleMaster.h"

PrimarySkill::PrimarySkill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimarySkill)
{
    ui->setupUi(this);

    //Установка стилей
    ui->Value->setStyleSheet(PS_StyleMaster::SpinBoxStyle(ui->Value->property("fontSize").toInt()));
    ui->Value->setFont(QFont("NumbersFont"));
    ui->primarySkillSignature->setSpinBoxValue(ui->Value);

    //Связывание слотов и сигналов вывода позсказки
    connect(ui->primarySkillSignature->getlabelWithTooltip(), &LabelWithTooltip::ShowTooltip, this, &PrimarySkill::ShowTooltip);
    connect(ui->primarySkillSignature->getlabelWithTooltip(), &LabelWithTooltip::RemoveTooltip, this, &PrimarySkill::RemoveTooltip);

    //Связывание слотов и сигналов вывода позсказки о модификаторах нажатия
    connect(ui->primarySkillSignature, &PrimarySkillSignature::ShowTooltip, this, &PrimarySkill::ShowTooltip);
    connect(ui->primarySkillSignature, &PrimarySkillSignature::RemoveTooltip, this, &PrimarySkill::RemoveTooltip);

    ui->Value->installEventFilter(this);
}

PrimarySkill::~PrimarySkill()
{
    delete ui;
}

void PrimarySkill::setStat(Stat *newStat)
{
    ui->primarySkillSignature->setStat(newStat);
    connect(newStat, &Stat::statChanged, this, &PrimarySkill::onStatChanged);
    setValue(newStat->getFinalValue());
}

void PrimarySkill::setValue(int val)
{
    ui->Value->setValue(val);
}

QSpinBox *PrimarySkill::getValueSpinBox()
{
    return ui->Value;
}

PrimarySkillSignature *PrimarySkill::getPrimarySkillSignature()
{
    return ui->primarySkillSignature;
}

//Инициализация виджета значениями из Stat, который по историческим причинам расположен в PrimarySkillSignature
void PrimarySkill::init()
{
    ui->Value->setValue(ui->primarySkillSignature->getStat()->getFinalValue());
}

void PrimarySkill::onStatChanged(bool bonusChanged)
{
    if(!isManualStatReplacement && bonusChanged){
        ui->Value->setValue(ui->primarySkillSignature->getStat()->getFinalValue());
    }
}

bool PrimarySkill::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->Value){
        /*Если Spinbox в фокусе, это значит что происходит ручное редактирование стата в нём и следует
         *вывести только родное значение, так как редактировать вручную можно только его*/
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->Value->setValue(ui->primarySkillSignature->getStat()->getValue());
            Global::pressedKeys.clear();
        }
        //Как только Spinbox покидает фокус, снова выводится финальное значение стата
        if(event->type() == QEvent::FocusOut){
            isManualStatReplacement = false;
            ui->Value->setValue(ui->primarySkillSignature->getStat()->getFinalValue());
        }
    }

    return false;
}

void PrimarySkill::on_Value_valueChanged(int arg1)
{
    if(isManualStatReplacement){
        ui->primarySkillSignature->getStat()->setValue(arg1);
    }
    emit recalculateStats();
}

