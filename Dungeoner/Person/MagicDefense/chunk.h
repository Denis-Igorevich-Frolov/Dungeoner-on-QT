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

    //Очистка чанка от всех бонусов. Используется для переинициализации магической защиты
    void clearBonuses();

    int getFinalMaxValue() const;

    friend bool operator == (const Chunk& chunk1, const Chunk& chunk2);
    friend bool operator != (const Chunk& chunk1, const Chunk& chunk2);

private:
    int maxValue = 1;
    //Максимальное значение с учётом всех бонусов
    int finalMaxValue = 1;
    //Текущее значение
    int value = 0;

    QVector<MagicDefenseBonus*> bonuses;

    //Вычисление финального максимального значения чанка с учётом всех бонусов
    void calculateFinalMaxValue();
};

#endif // CHUNK_H
