#ifndef STAT_H
#define STAT_H

#include "Person/Stat/bonus.h"

#include <QVector>

class Stat
{
public:
    Stat(int maximum);
    ~Stat();

    int getValue() const;
    void setValue(int newValue);
    void addBonus(Bonus* bonus);

    int getFinalValue() const;

    int getProgressBarCurrentValue() const;
    void setProgressBarCurrentValue(int newProgressBarCurrentValue);

private:
    int value = 0;
    int finalValue = 0;
    int progressBarCurrentValue = 0;

    int maximum = 0;

    QVector<Bonus*> bonuses;

    void calculateFinalValue();
};

#endif // STAT_H
