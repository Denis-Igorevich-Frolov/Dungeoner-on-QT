#include "primaryskill.h"
#include "ui_primaryskill.h"
#include "PS_styleMaster.h"

PrimarySkill::PrimarySkill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimarySkill)
{
    ui->setupUi(this);

    ui->Value->setStyleSheet(PS_StyleMaster::SpinBoxStyle(ui->Value->property("fontSize").toInt()));
    ui->Value->setFont(QFont("NumbersFont"));
    ui->primarySkillSignature->setSpinBoxValue(ui->Value);

    connect(ui->primarySkillSignature->getlabelWithTooltip(), &LabelWithTooltip::ShowTooltip, this, &PrimarySkill::ShowTooltip);
    connect(ui->primarySkillSignature->getlabelWithTooltip(), &LabelWithTooltip::RemoveTooltip, this, &PrimarySkill::RemoveTooltip);

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
        if(event->type() == QEvent::FocusIn){
            isManualStatReplacement = true;
            ui->Value->setValue(ui->primarySkillSignature->getStat()->getValue());
        }
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

