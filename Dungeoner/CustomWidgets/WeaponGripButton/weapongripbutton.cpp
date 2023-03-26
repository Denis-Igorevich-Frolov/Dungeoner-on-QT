#include "weapongripbutton.h"
#include "ui_weapongripbutton.h"
#include "CustomWidgets/WeaponGripButton/WGB_stylemaster.h"
#include "Global/global.h"

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

void WeaponGripButton::toggle()
{
    ui->GripButton->toggle();
}

void WeaponGripButton::setTwoHandedGrip()
{
    if(!ui->GripButton->isChecked())
        ui->GripButton->toggle();
}

void WeaponGripButton::setOneHandedGrip()
{
    if(ui->GripButton->isChecked())
        ui->GripButton->toggle();
}

bool WeaponGripButton::getIsTwoHandedGrip()
{
    return ui->GripButton->isChecked();
}

void WeaponGripButton::on_GripButton_toggled(bool checked)
{
    ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
    if(styleSettingMode){
        styleSettingMode = false;
    }else{
        if(checked){
            if(emit checkFreeHands()){
                if(isRightClick)
                    emit takeTwoHandedGripLeftHandItem();
                else
                    emit takeTwoHandedGripRightHandItem();
            }else{
                Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Error.mp3"), MediaPlayer::SoundsGroup::SOUNDS);
                styleSettingMode = true;
                ui->GripButton->toggle();
            }
        }else{
            if(emit checkBusyHands())
                emit useOneHandedGrip();
            else{
                Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Error.mp3"), MediaPlayer::SoundsGroup::SOUNDS);
                styleSettingMode = true;
                ui->GripButton->toggle();
            }
        }
    }
    isRightClick = false;
}

void WeaponGripButton::mousePressEvent(QMouseEvent *event)
{
    if(QApplication::mouseButtons() & QFlags<Qt::MouseButton>(Qt::LeftButton)){
        isRightClick = false;
    }else if(QApplication::mouseButtons() & QFlags<Qt::MouseButton>(Qt::RightButton)){
        if(getIsTwoHandedGrip())
            ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonTwoHandedPressedStyle());
        else
            ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonOneHandedPressedStyle());
        isRightClick = true;
    }
}

void WeaponGripButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(isRightClick)
        ui->GripButton->toggle();
}
