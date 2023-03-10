/***************************************************************************************************************
 *Данный класс является виджетом первичного навыка. Он обединяет в себе PrimarySkillSignature и его Spinbox
 ***************************************************************************************************************/

#ifndef PRIMARYSKILL_H
#define PRIMARYSKILL_H

#include "CustomWidgets/PrimarySkillSignature/primaryskillsignature.h"
#include "Person/Stat/stat.h"
#include "qlabel.h"
#include "qspinbox.h"
#include <QWidget>

namespace Ui {
class PrimarySkill;
}

class PrimarySkill : public QWidget
{
    Q_OBJECT

public:
    explicit PrimarySkill(QWidget *parent = nullptr);
    ~PrimarySkill();

    void setStat(Stat *newStat);
    void setValue(int val);
    QSpinBox* getValueSpinBox();
    PrimarySkillSignature* getPrimarySkillSignature();
    //Инициализация виджета значениями из Stat, который по историческим причинам расположен в PrimarySkillSignature
    void init();

    bool isManualStatReplacement = false;

signals:
    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();
    //Сигнал говорящий о том, что требуется пересчёт вторичных навыков
    void recalculateStats();

private slots:
    void onStatChanged(bool bonusChanged);

    void on_Value_valueChanged(int arg1);

private:
    Ui::PrimarySkill *ui;

    bool eventFilter(QObject *object, QEvent *event) override;
};

#endif // PRIMARYSKILL_H
