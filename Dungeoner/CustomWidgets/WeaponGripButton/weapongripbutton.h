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

private slots:
    void on_GripButton_toggled(bool checked);

signals:
    void takeTwoHandedGripRightHandItem();
    void takeTwoHandedGripLeftHandItem();
    void useOneHandedGrip();

private:
    Ui::WeaponGripButton *ui;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    bool isRightClick = false;
};

#endif // WEAPONGRIPBUTTON_H
