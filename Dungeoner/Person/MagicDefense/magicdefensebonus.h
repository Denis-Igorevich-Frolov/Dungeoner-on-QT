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

    MagicDefenseBonus(DynamicPosition dynamicPosition, int value, bool isPercentage);
    MagicDefenseBonus(int staticPosition, int value, bool isPercentage);
    MagicDefenseBonus(QVector<int> bonusChunksMaxVales);

    bool isDynamic = false;
    bool isPercentage = false;
    bool isBonusChunk = false;

    int getValue() const;
    void setValue(int newValue);

    DynamicPosition dynamicPosition;
    int staticPosition;

    QVector<int> getBonusChunksMaxVales() const;
    void setBonusChunksMaxVales(const QVector<int> &newBonusChunksMaxVales);

    friend bool operator == (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2);
    friend bool operator != (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2);

private:
    int value = 0;
    QVector<int> bonusChunksMaxVales;
};

#endif // MAGICDEFENSEBONUS_H
