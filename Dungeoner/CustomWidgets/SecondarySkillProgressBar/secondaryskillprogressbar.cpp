#include "secondaryskillprogressbar.h"
#include "ui_secondaryskillprogressbar.h"
#include "SSPB_stylemaster.h"

SecondarySkillProgressBar::SecondarySkillProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondarySkillProgressBar)
{
    ui->setupUi(this);

    ui->Name->setStyleSheet(SSPB_StyleMaster::TextFontStyle(25, "Algerian"));

    outlineEffect = new OutlineEffect;
    outlineEffect->setOutlineThickness(1);
    ui->Name->setGraphicsEffect(outlineEffect);

    ui->Border->setStyleSheet(SSPB_StyleMaster::BorderStyle());
    ui->TipLeft->setStyleSheet(SSPB_StyleMaster::TipLeftStyle());
    ui->TipRight->setStyleSheet(SSPB_StyleMaster::TipRightStyle());
}

SecondarySkillProgressBar::~SecondarySkillProgressBar()
{
    delete outlineEffect;
    delete ui;
}

int SecondarySkillProgressBar::getMinValue() const
{
    return ui->progressBar->getMinValue();
}

void SecondarySkillProgressBar::setMinValue(int newMinValue)
{
    ui->progressBar->setMinValue(newMinValue);
}

int SecondarySkillProgressBar::getMaxValue() const
{
    return ui->progressBar->getMaxValue();
}

void SecondarySkillProgressBar::setMaxValue(int newMaxValue)
{
    ui->progressBar->setMaxValue(newMaxValue);
}

int SecondarySkillProgressBar::getValue() const
{
    return ui->progressBar->getValue();
}

void SecondarySkillProgressBar::setValue(int newValue)
{
    ui->progressBar->setValue(newValue);
}

void SecondarySkillProgressBar::setColor(QColor color)
{
    ui->progressBar->setColor(color);
}

void SecondarySkillProgressBar::setName(QString name)
{
    ui->Name->setText(name);
}
