#ifndef CHARACTEREQUIPMENT_H
#define CHARACTEREQUIPMENT_H

#include <QWidget>

namespace Ui {
class CharacterEquipment;
}

class CharacterEquipment : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterEquipment(QWidget *parent = nullptr);
    ~CharacterEquipment();

private slots:
    void on_OverArmorButton_clicked();
    void on_ArmorButton_clicked();
    void on_UnderArmorButton_clicked();

private:
    Ui::CharacterEquipment *ui;

    void setCellsAcceptedSlots();
};

#endif // CHARACTEREQUIPMENT_H
