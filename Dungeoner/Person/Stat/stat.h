/**********************************************************************
 *Данный класс является структурой для всех статов кроме магической
 *защиты с реализацией геттеров и сеттеров с ограничителями.
 **********************************************************************/

#ifndef STAT_H
#define STAT_H

#include "Person/Stat/bonus.h"
#include "qobject.h"

#include <QVector>

class Stat: public QObject
{
    Q_OBJECT
public:
    /*Разные группы статов имеют разные максимальные значения. Так для первичных навыков -
     *это 999999,а для вторичных - 9999999. Чтобы корректно работали ограничители на
     *сеттерах это максимальное значение задаётся при инициализации*/
    Stat(int maximum);
    ~Stat();

    int getValue() const;
    void setValue(int newValue);

    void addBonus(Bonus* bonus);

    /*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
     *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
     *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
     *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
    bool removeBonus(Bonus* bonus);

    int getFinalValue() const;

    int getProgressBarCurrentValue() const;
    //Задание текущего значения прогрессбара, при этом просто value, в таком случае, является максимальным значением
    void setProgressBarCurrentValue(int newProgressBarCurrentValue);

    QVector<Bonus *> getBonuses();

    void removeAllBonuses();

    //Так как класс Stat унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
    Stat& operator= (const Stat &stat);
    int getMaximum() const;

signals:
    void bonusesChanged();
private:
    int value = 0;
    //Значение с учётом всех бонусов
    int finalValue = 0;
    //Текущее значение прогрессбара. Используется только в статах с прогрессбаром.
    int progressBarCurrentValue = 0;

    //Максимальное значение стата
    int maximum = 0;

    QVector<Bonus*> bonuses;

    //Вычисление финального максимального значения стата с учётом всех бонусов
    void calculateFinalValue();
};

#endif // STAT_H
