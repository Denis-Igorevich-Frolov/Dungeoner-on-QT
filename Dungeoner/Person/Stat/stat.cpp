#include "stat.h"

int Stat::getValue() const
{
    return value;
}

void Stat::setValue(int newValue)
{
    value = newValue;

    if(value > maximum)
        value = maximum;
    else if(value<0)
        value = 0;

    calculateFinalValue();
}

void Stat::addBonus(Bonus *bonus)
{
    bonuses.append(bonus);
    calculateFinalValue();
}

int Stat::getFinalValue() const
{
    return finalValue;
}

int Stat::getProgressBarCurrentValue() const
{
    return progressBarCurrentValue;
}

void Stat::setProgressBarCurrentValue(int newProgressBarCurrentValue)
{
    progressBarCurrentValue = newProgressBarCurrentValue;
}

void Stat::calculateFinalValue()
{
    finalValue = value;

    for(Bonus* bonus : bonuses){
        if(bonus != nullptr){
            if (bonus->isPercentage)
                finalValue += ((double)value/100)*bonus->getValue();
            else
                finalValue += bonus->getValue();
        }
    }

    if(finalValue > maximum)
        finalValue = maximum;
    else if(finalValue<0)
        finalValue = 0;
}

Stat::Stat(int maximum) : maximum(maximum)
{}

Stat::~Stat()
{
    for(Bonus* bonus : bonuses)
        delete bonus;
}
