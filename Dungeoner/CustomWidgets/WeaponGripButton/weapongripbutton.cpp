#include "weapongripbutton.h"
#include "qevent.h"
#include "ui_weapongripbutton.h"
#include "CustomWidgets/WeaponGripButton/WGB_stylemaster.h"
#include "Global/global.h"

WeaponGripButton::WeaponGripButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeaponGripButton)
{
    ui->setupUi(this);
    ui->GifLabel->setVisible(false);

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

void WeaponGripButton::setTwoHandedGrip(bool isRightClick)
{
    if(!ui->GripButton->isChecked()){
        this->isRightClick = isRightClick;
        ui->GripButton->toggle();
    }
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

void WeaponGripButton::setForbiddenTwoHandedGripStyle()
{
    ui->GripButton->setVisible(false);
    ui->GifLabel->setVisible(true);

    Forbidden.stop();
    Forbidden.setFileName(":/Equipment/GIF/Forbidden-Two-Handed-Grip.gif");
    Forbidden.setScaledSize(QSize(65,77));
    ui->GifLabel->setMovie(&Forbidden);
    Forbidden.start();
}

void WeaponGripButton::setForbiddenOneHandedGripStyle()
{
    ui->GripButton->setVisible(false);
    ui->GifLabel->setVisible(true);

    Forbidden.stop();
    Forbidden.setFileName(":/Equipment/GIF/Forbidden-One-Handed-Grip.gif");
    Forbidden.setScaledSize(QSize(65,77));
    ui->GifLabel->setMovie(&Forbidden);
    Forbidden.start();
}

void WeaponGripButton::setNormalStyle()
{
    Forbidden.stop();

    ui->GripButton->setVisible(true);
    ui->GifLabel->setVisible(false);
}

void WeaponGripButton::on_GripButton_toggled(bool checked)
{
    ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
    if(styleSettingMode){
        styleSettingMode = false;
    }else{
        if(checked){
            if(emit checkFreeHands(!isRightClick)){
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
    if(isRightClick && cursorWithinWidget)
        ui->GripButton->toggle();
    isRightClick = false;
    cursorWithinWidget = true;
    ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
}

void WeaponGripButton::mouseMoveEvent(QMouseEvent *event)
{
    if(isRightClick){
        if(event->pos().x()<0 || event->pos().y()<0 || event->pos().x()>ui->GripButton->size().width() || event->pos().y()>ui->GripButton->size().height()){
            cursorWithinWidget = false;
            ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonStyle());
        }else{
            cursorWithinWidget = true;
            if(getIsTwoHandedGrip())
                ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonTwoHandedPressedStyle());
            else
                ui->GripButton->setStyleSheet(WGB_stylemaster::GripButtonOneHandedPressedStyle());
        }
    }
}
