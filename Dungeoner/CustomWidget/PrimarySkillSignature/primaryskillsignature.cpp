/*
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 */

#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "stylemaster.h"
#include <QMouseEvent>

PrimarySkillSignature::PrimarySkillSignature(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimarySkillSignature)
{
    ui->setupUi(this);

    //Установка стилей для эллементов виджета
    ui->labelCenter->setStyleSheet(StyleMaster::CenterTextureStyle());
    ui->ButtonTop->setStyleSheet(StyleMaster::topTextureStyle());
    ui->ButtonBottom->setStyleSheet(StyleMaster::bottomTextureStyle());
    ui->labelRight->setStyleSheet(StyleMaster::RightTextureStyle());
    ui->labelLeft->setStyleSheet(StyleMaster::LeftTextureStyle());
}

PrimarySkillSignature::~PrimarySkillSignature()
{
    delete ui;
}
