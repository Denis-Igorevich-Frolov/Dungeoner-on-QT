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
    void init();

    bool isManualStatReplacement = false;

signals:
    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();
    void recalculateStats();

private slots:
    void onStatChanged(bool bonusChanged);

    void on_Value_valueChanged(int arg1);

private:
    Ui::PrimarySkill *ui;

    bool eventFilter(QObject *object, QEvent *event) override;
};

#endif // PRIMARYSKILL_H
