/**************************************************************************
 *Данный класс является бонусом для всех статов кроме магической защиты.
 *Он хранит значение бонуса и информацию о том процентный ли бонус.
 *Также в классе реализованы операторы сравнения. Не смотря на название
 *может быть и отрицательным, а не только положительным.
 **************************************************************************/

#include "bonus.h"

Bonus::Bonus(QString statName, int value, bool isPercentage, QString bonusName, int durationDays, int durationHours, int durationMinutes, int durationSeconds)
{
    this->statName = statName;
    if(isPercentage && value > 9999)
        value = 9999;
    setValue(value);
    this->isPercentage = isPercentage;
    this->bonusName = bonusName;

    this->durationDays = durationDays;
    this->durationHours = durationHours;
    this->durationMinutes = durationMinutes;
    this->durationSeconds = durationSeconds;

    if(!isPercentage)
        finalValue = value;
}

Bonus::Bonus()
{
    value = 0;
    isPercentage = false;
}

int Bonus::getValue() const
{
    return value;
}

void Bonus::setValue(int newValue)
{
    value = newValue;

    if(value > 9999999)
        value = 9999999;
    else if(value < -9999999)
        value = -9999999;
    if(!isPercentage)
        finalValue = value;
}

int Bonus::getFinalValue() const
{
    return finalValue;
}

void Bonus::setFinalValue(int newFinalValue)
{
    finalValue = newFinalValue;
}

int Bonus::getDurationDays() const
{
    return durationDays;
}

void Bonus::setDurationDays(int newDurationDays)
{
    durationDays = newDurationDays;
}

int Bonus::getDurationHours() const
{
    return durationHours;
}

void Bonus::setDurationHours(int newDurationHours)
{
    durationHours = newDurationHours;
}

int Bonus::getDurationMinutes() const
{
    return durationMinutes;
}

void Bonus::setDurationMinutes(int newDurationMinutes)
{
    durationMinutes = newDurationMinutes;
}

int Bonus::getDurationSeconds() const
{
    return durationSeconds;
}

void Bonus::setDurationSeconds(int newDurationSeconds)
{
    durationSeconds = newDurationSeconds;
}

bool operator ==(const Bonus& bonus1, const Bonus& bonus2)
{
    return (bonus1.value==bonus2.value)&&(bonus1.isPercentage==bonus2.isPercentage);
}

bool operator !=(const Bonus& bonus1, const Bonus& bonus2)
{
    return !((bonus1.value==bonus2.value)||(bonus1.isPercentage==bonus2.isPercentage));
}

//Операторы отношения сделаны для сортировки подсказок, которая производится по степени воздействия. Следовательно сравнение производится по модулю
bool Bonus::operator <(const Bonus& bonus2)
{
    /*Если один из бонусов процентный, а второй нет, то у процентного берётся finalValue,
     *а у другого value, при этом если эти значения равны большим посчитается процентный*/
    if(isPercentage && !bonus2.isPercentage)
        if(std::abs(finalValue) == std::abs(bonus2.getValue()))
            return false;
        else
            return std::abs(finalValue) < std::abs(bonus2.getValue());
    else if(!isPercentage && bonus2.isPercentage)
        if(std::abs(value) == std::abs(bonus2.getFinalValue()))
            return true;
        else
            return std::abs(value) < std::abs(bonus2.getFinalValue());
    else if(isPercentage && bonus2.isPercentage){
        if(finalValue == bonus2.finalValue)
            /*Если оба бонуса процентные и имеют одинаковое finalValue, но разный value, это значит, что
             *они имеют разный процент, но эта разница достаточно незначительная, чтобы выдавать одинаковый
             *finalValue. В таком случае большим считается тот бонус, чей процент выше*/
            return std::abs(value) < std::abs(bonus2.getValue());
        else
            return std::abs(finalValue) < std::abs(bonus2.getFinalValue());
    }else
        return std::abs(value) < std::abs(bonus2.getValue());
}
bool Bonus::operator >(const Bonus& bonus2)
{
    /*Если один из бонусов процентный, а второй нет, то у процентного берётся finalValue,
     *а у другого value, при этом если эти значения равны большим посчитается процентный*/
    if(isPercentage && !bonus2.isPercentage)
        if(std::abs(finalValue) == std::abs(bonus2.getValue()))
            return true;
        else
            return std::abs(finalValue) > std::abs(bonus2.getValue());
    else if(!isPercentage && bonus2.isPercentage)
        if(std::abs(value) == std::abs(bonus2.getFinalValue()))
            return false;
        else
            return std::abs(value) > std::abs(bonus2.getFinalValue());
    else if(isPercentage && bonus2.isPercentage){
        if(finalValue == bonus2.finalValue)
            /*Если оба бонуса процентные и имеют одинаковое finalValue, но разный value, это значит, что
             *они имеют разный процент, но эта разница достаточно незначительная, чтобы выдавать одинаковый
             *finalValue. В таком случае большим считается тот бонус, чей процент выше*/
            return std::abs(value) > std::abs(bonus2.getValue());
        else
            return std::abs(finalValue) > std::abs(bonus2.getFinalValue());
    }else
        return std::abs(value) > std::abs(bonus2.getValue());
}
