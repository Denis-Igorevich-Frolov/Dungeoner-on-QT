#ifndef BONUS_H
#define BONUS_H

class Bonus
{
public:
    Bonus(int value, bool isPercentage);
    Bonus();
    int getValue() const;
    void setValue(int newValue);

    bool isPercentage = false;

    friend bool operator == (const Bonus& bonus1, const Bonus& bonus2);
    friend bool operator != (const Bonus& bonus1, const Bonus& bonus2);

private:
    int value = 0;
};

#endif // BONUS_H
