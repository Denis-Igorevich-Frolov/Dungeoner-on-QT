#ifndef SECONDARYSKILLPROGRESSBAR_H
#define SECONDARYSKILLPROGRESSBAR_H

#include "System/OutlineEffect/outlineeffect.h"

#include <QWidget>

namespace Ui {
class SecondarySkillProgressBar;
}

class SecondarySkillProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit SecondarySkillProgressBar(QWidget *parent = nullptr);
    ~SecondarySkillProgressBar();

    int getMinValue() const;
    void setMinValue(int newMinValue);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    int getValue() const;
    void setValue(int newValue);

    void setColor(QColor color);
    void setName(QString name);

private:
    Ui::SecondarySkillProgressBar *ui;

    OutlineEffect* outlineEffect;
};

#endif // SECONDARYSKILLPROGRESSBAR_H
