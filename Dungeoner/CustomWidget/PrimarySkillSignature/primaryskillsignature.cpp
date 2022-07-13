#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "stylemaster.h"

PrimarySkillSignature::PrimarySkillSignature(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimarySkillSignature)
{
    ui->setupUi(this);

    ui->labelCenter->setStyleSheet(StyleMaster::CenterTextureStyle());
    ui->ButtonTop->setStyleSheet(StyleMaster::topTextureStyle());
    ui->ButtonBottom->setStyleSheet(StyleMaster::bottomTextureStyle());
    ui->labelRight->setStyleSheet(StyleMaster::RightTextureStyle());
    ui->labelLeft->setStyleSheet(StyleMaster::LeftTextureStyle());
    ui->labelText->setStyleSheet(StyleMaster::TextFontStyle(25));
}

PrimarySkillSignature::~PrimarySkillSignature()
{
    delete ui;
}
