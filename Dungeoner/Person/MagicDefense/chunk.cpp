/*************************************************************************************
 *Данный класс скорее даже и не класс, а структура, хранящая максимальное и текущее
 *значение фрагмента прогрессбара магической защиты. Вынесен всё же именно в класс
 *для реализации геттеров и сеттеров с ограничителями вне класса прогрессбара
 *магической защиты, чтобы не засорять его.
 *************************************************************************************/

#include "chunk.h"

Chunk::Chunk(int maxValue, int value)
{
    if(maxValue<1)
        maxValue = 1;
    setMaxValue(maxValue);
    calculateFinalMaxValue();

    setValue(value);
}

int Chunk::getMaxValue() const
{
    return maxValue;
}

void Chunk::setMaxValue(int newMaxValue)
{
    /*Ограничение стата для уменьшения шанса возможных переполнений. Значение
     *сравнительно небольшое так как подразумевается, что подобных фрагментов
     *в прогрессбаре магической защиты будет много.*/
    if(newMaxValue>10000)
        newMaxValue = 10000;
    /*Максимальное значение фрагмента прогрессбара магической защиты не может быть меньше 1 -
     *фрагмент 0/0 - это фактическое отсутствие фрагмента, что не делает смысла*/
    else if(newMaxValue<1)
        newMaxValue = 1;

    maxValue = newMaxValue;
    //После изменения чанка требуется пересчёт его финального максимального значения
    calculateFinalMaxValue();
}

int Chunk::getValue() const
{
    return value;
}

void Chunk::setValue(int newValue)
{
    /*Значение фрагмента прогрессбара магической защиты
     *лежит в диапазоне от 0 до максимального значения*/
    if(newValue>finalMaxValue)
        newValue = finalMaxValue;
    else if(newValue<0)
        newValue = 0;

    value = newValue;
}

void Chunk::addBonus(MagicDefenseBonus *bonus)
{
    bonuses.append(bonus);
    //После изменения чанка требуется пересчёт его финального максимального значения
    calculateFinalMaxValue();
}

int Chunk::getFinalMaxValue() const
{
    return finalMaxValue;
}

QVector<MagicDefenseBonus *> Chunk::getBonuses() const
{
    return bonuses;
}

//Очистка чанка от всех бонусов. Используется для переинициализации магической защиты
void Chunk::clearBonuses()
{
    bonuses.clear();
    //После изменения чанка требуется пересчёт его финального максимального значения
    calculateFinalMaxValue();
}

//Вычисление финального максимального значения чанка с учётом всех бонусов
void Chunk::calculateFinalMaxValue()
{
    finalMaxValue = maxValue;

    for(MagicDefenseBonus* bonus : bonuses){
        if(bonus != nullptr){
            if (bonus->isPercentage)
                finalMaxValue += ((double)maxValue/100)*bonus->getValue();
            else
                finalMaxValue += bonus->getValue();
        }
    }

    /*Ограничение стата для уменьшения шанса возможных переполнений. Значение
     *сравнительно небольшое так как подразумевается, что подобных фрагментов
     *в прогрессбаре магической защиты будет много.*/
    if(finalMaxValue>10000)
        finalMaxValue = 10000;
    /*Максимальное значение фрагмента прогрессбара магической защиты не может быть меньше 1 -
     *фрагмент 0/0 - это фактическое отсутствие фрагмента, что не делает смысла*/
    else if(finalMaxValue<1)
        finalMaxValue = 1;
}
