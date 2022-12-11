/***********************************************************************************
 *Данный класс является бонусом для магической защиты. Есть 3 типа бонусов:
 *
 *1)Бонус на динамической позиции. Есть 4 таких позиции: первый, последний,
 *центральный и все. Такой бонус прибавляет своё значение (процентное или
 *абсолютное) к указанному РОДНОМУ чанку магической защиты.
 *
 *2)Бонус на статической позиции. В него передаётся конкретный индекс
 *(начиная с 1) чанка магической защиты. Такой бонус прибавляет своё значение
 *(процентное или абсолютное) к указанному РОДНОМУ чанку магической защиты.
 *Если чанка с указанным индексом несуществует не происходит ничего.
 *
 *3)Бонус на чанки. В конструктор передаётся вектор максимальных значений новых
 *чанков. Такие чанки дабавляются после всех остальных, и на них нельзя повесить
 *другие бонусы.
 *
 *Также в классе реализованы операторы сравнения. Не смотря на название
 *может быть и отрицательным, а не только положительным.
 ***********************************************************************************/

#ifndef MAGICDEFENSEBONUS_H
#define MAGICDEFENSEBONUS_H

#include <QVector>


class MagicDefenseBonus
{
public:
    enum DynamicPosition{
        FIRST,
        LAST,
        CENTER,
        ALL
    };

    //Конструктор для бонуса на динамической позиции
    MagicDefenseBonus(DynamicPosition dynamicPosition, int value, bool isPercentage, QString bonusName);
    //Конструктор для бонуса на статической позиции
    MagicDefenseBonus(int staticPosition, int value, bool isPercentage, QString bonusName);
    //Конструктор для бонусных чанков
    MagicDefenseBonus(QVector<int> bonusChunksMaxVales, QString bonusName);

    bool isDynamic = false;
    bool isPercentage = false;
    bool isBonusChunk = false;

    int getValue() const;
    void setValue(int newValue);

    //Переменная показывающая на какой динамической позиции бонус, если бонус динамический
    DynamicPosition dynamicPosition;
    //Переменная показывающая на какой статической позиции бонус, если бонус статический
    int staticPosition;

    QVector<int> getBonusChunksMaxVales() const;
    void setBonusChunksMaxVales(const QVector<int> &newBonusChunksMaxVales);

    friend bool operator == (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2);
    friend bool operator != (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2);

    /*Операторы отношения сделаны для сортировки подсказок, которая производится по степени воздействия. Следовательно
     *сравнение производится по модулю. Бонус на новые чанки всегда считается большим чем любой другой.*/
    bool operator > (const MagicDefenseBonus& bonus2);
    bool operator < (const MagicDefenseBonus& bonus2);

    QString bonusName;

    int getFinalValue() const;
    void setFinalValue(int newFinalValue);

    int getNumberOfChunksChanged() const;
    void setNumberOfChunksChanged(int newNumberOfChunksChanged);

private:
    int numberOfChunksChanged = 1;
    //Финальное значеие с учётом процента. Хранится для подсказки
    int finalValue = 0;
    //Значение бонуса. Используется только для статических и динамических бонусов
    int value = 0;
    //Вектор максимальных значений бонусных чанков. Используется только для бонуса на чанки.
    QVector<int> bonusChunksMaxVales;
};

#endif // MAGICDEFENSEBONUS_H
