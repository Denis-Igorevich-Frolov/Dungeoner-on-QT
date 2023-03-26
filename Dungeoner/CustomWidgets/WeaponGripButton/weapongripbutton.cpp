#include "weapongripbutton.h"
#include "ui_weapongripbutton.h"
#include "CustomWidgets/WeaponGripButton/WGB_stylemaster.h"

WeaponGripButton::WeaponGripButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeaponGripButton)
{
    ui->setupUi(this);

    ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
}

WeaponGripButton::~WeaponGripButton()
{
    delete ui;
}

void WeaponGripButton::on_GripButton_toggled(bool checked)
{
    ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
    if(checked){
        if(isRightClick)
            emit takeTwoHandedGripLeftHandItem();
        else
            emit takeTwoHandedGripRightHandItem();
    }else{
        emit useOneHandedGrip();
    }
    isRightClick = false;
}

void WeaponGripButton::mousePressEvent(QMouseEvent *event)
{
    if(QApplication::mouseButtons() & QFlags<Qt::MouseButton>(Qt::LeftButton)){
        isRightClick = false;
    }else if(QApplication::mouseButtons() & QFlags<Qt::MouseButton>(Qt::RightButton)){
        ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonPressedStyle());
        isRightClick = true;
    }
}

void WeaponGripButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(isRightClick)
        ui->GripButton->toggle();
}
