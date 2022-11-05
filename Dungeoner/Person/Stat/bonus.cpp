#include "bonus.h"

Bonus::Bonus(int value, bool isPercentage)
{
    this->value = value;
    this->isPercentage = isPercentage;
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
}

bool Bonus::operator ==(Bonus *bonus2)
{
    return (this->value==bonus2->value)&&(this->isPercentage==bonus2->isPercentage);
}

bool Bonus::operator !=(Bonus *bonus2)
{
    return !((this->value==bonus2->value)&&(this->isPercentage==bonus2->isPercentage));
}
