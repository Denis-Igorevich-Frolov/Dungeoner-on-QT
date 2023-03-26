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

void WeaponGripButton::on_GripButton_toggled(bool checked)
{
    ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
    if(checked){
        if(emit checkFreeHands()){
            if(isRightClick)
                emit takeTwoHandedGripLeftHandItem();
            else
                emit takeTwoHandedGripRightHandItem();
        }else{
            Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Error.mp3"), MediaPlayer::SoundsGroup::SOUNDS);
            ui->GripButton->toggle();
        }
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
