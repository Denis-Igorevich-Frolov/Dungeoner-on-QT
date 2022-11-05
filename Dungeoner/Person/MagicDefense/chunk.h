/*************************************************************************************
 *Данный класс скорее даже и не класс, а структура, хранящая максимальное и текущее
 *значение фрагмента прогрессбара магической защиты. Вынесен всё же именно в класс
 *для реализации геттеров и сеттеров с ограничителями вне класса прогрессбара
 *магической защиты, чтобы не засорять его.
 *************************************************************************************/

#ifndef CHUNK_H
#define CHUNK_H

#include "magicdefensebonus.h"

#include <QVector>


class Chunk
{
public:
    Chunk(int maxValue, int value);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    int getValue() const;
    void setValue(int newValue);
    void addBonus(MagicDefenseBonus* bonus);
    QVector<MagicDefenseBonus *> getBonuses() const;
    void clearBonuses();

    int getFinalMaxValue() const;

private:
    int maxValue = 1;
    int finalMaxValue = 1;
    int value = 0;

    QVector<MagicDefenseBonus*> bonuses;

    void calculateFinalMaxValue();
};

#endif // CHUNK_H
