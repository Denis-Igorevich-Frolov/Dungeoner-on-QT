#include "chunk.h"

Chunk::Chunk()
{
}

Chunk::Chunk(int maxValue, int value)
{
    setMaxValue(maxValue);
    setValue(value);
}

int Chunk::getMaxValue() const
{
    return maxValue;
}

void Chunk::setMaxValue(int newMaxValue)
{
    if(newMaxValue>200000)
        newMaxValue = 200000;
    maxValue = newMaxValue;
}

int Chunk::getValue() const
{
    return value;
}

void Chunk::setValue(int newValue)
{
    if(newValue>maxValue)
        newValue = maxValue;
    value = newValue;
}
