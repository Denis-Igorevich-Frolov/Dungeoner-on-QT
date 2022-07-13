#include "primaryskillsignature.h"
#include "ui_primaryskillsignature.h"
#include "stylemaster.h"
#include <QMouseEvent>

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
    ui->ButtonText->setStyleSheet(StyleMaster::TextFontStyle(25));
}

PrimarySkillSignature::~PrimarySkillSignature()
{
    delete ui;
}

void PrimarySkillSignature::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
        case Qt::LeftButton:
        {
            break;
        }
        case Qt::RightButton:
        {
            qDebug() << "Right Mouse button pressed";
            break;
        }
        case Qt::MiddleButton:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
void PrimarySkillSignature::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button()) {
        case Qt::LeftButton:
        {
            break;
        }
        case Qt::RightButton:
        {
            qDebug() << "Right Mouse button unpressed";
            break;
        }
        case Qt::MiddleButton:
        {
            break;
        }
        default:
        {
            break;
        }
    }

}
