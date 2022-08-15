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

ProgressBar_1* SecondarySkillProgressBar::getProgressBar()
{
    return ui->progressBar;
}

void SecondarySkillProgressBar::setName(QString name)
{
    ui->Name->setText(name);
}
