/**************************************************************************
 *Данный класс является бонусом для всех статов кроме магической защиты.
 *Он хранит значение бонуса и информацию о том процентный ли бонус.
 *Также в классе реализованы операторы сравнения. Не смотря на название
 *может быть и отрицательным, а не только положительным.
 **************************************************************************/

#include "bonus.h"

Bonus::Bonus(StatName statName, int value, bool isPercentage, QString bonusName)
{
    this->statName = statName;
    if(isPercentage && value > 9999)
        value = 9999;
    setValue(value);
    this->isPercentage = isPercentage;
    this->bonusName = bonusName;

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

bool operator ==(const Bonus& bonus1, const Bonus& bonus2)
{
    return (bonus1.value==bonus2.value)&&(bonus1.isPercentage==bonus2.isPercentage);
}

bool operator !=(const Bonus& bonus1, const Bonus& bonus2)
{
    return !((bonus1.value==bonus2.value)&&(bonus1.isPercentage==bonus2.isPercentage));
}

//Операторы отношения сделаны для сортировки подсказок, которая производится по степени воздействия. Следовательно сравнение производится по модулю
bool Bonus::operator <(const Bonus& bonus2)
{
    //Если один из бонусов процентный, а второй нет, то у процентного берётся finalValue, а у другого value
    if(isPercentage && !bonus2.isPercentage)
        return std::abs(finalValue) < std::abs(bonus2.getValue());
    else if(!isPercentage && bonus2.isPercentage)
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
    //Если один из бонусов процентный, а второй нет, то у процентного берётся finalValue, а у другого value
    if(isPercentage && !bonus2.isPercentage)
        return std::abs(finalValue) > std::abs(bonus2.getValue());
    else if(!isPercentage && bonus2.isPercentage)
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
