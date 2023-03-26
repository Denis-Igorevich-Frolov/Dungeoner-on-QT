#ifndef WEAPONGRIPBUTTON_H
#define WEAPONGRIPBUTTON_H

#include <QWidget>

namespace Ui {
class WeaponGripButton;
}

class WeaponGripButton : public QWidget
{
    Q_OBJECT

public:
    explicit WeaponGripButton(QWidget *parent = nullptr);
    ~WeaponGripButton();

    void toggle();
    void setTwoHandedGrip();
    void setOneHandedGrip();
    bool getIsTwoHandedGrip();

private slots:
    void on_GripButton_toggled(bool checked);

signals:
    void takeTwoHandedGripRightHandItem();
    void takeTwoHandedGripLeftHandItem();
    void useOneHandedGrip();
    bool checkFreeHands(bool isRightHand);
    bool checkBusyHands();

private:
    Ui::WeaponGripButton *ui;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    bool isRightClick = false;
    bool styleSettingMode = false;
};

#endif // WEAPONGRIPBUTTON_H
