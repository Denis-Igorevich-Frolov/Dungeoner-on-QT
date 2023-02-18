/**********************************************************************
 *Данный класс является структурой для всех статов кроме магической
 *защиты с реализацией геттеров и сеттеров с ограничителями.
 **********************************************************************/

#ifndef STAT_H
#define STAT_H

#include "Person/Stat/bonus.h"
#include "qobject.h"

#include <QVector>

namespace Interface {
    class fastSaveble{
    public:
        virtual bool fastSave(){return false;}
    };
    class fastLoadble{
    public:
        virtual bool fastLoad(){return false;}
    };
}

class Stat: public QObject, Interface::fastSaveble, Interface::fastLoadble
{
    Q_OBJECT
public:
    /*Разные группы статов имеют разные максимальные значения. Так для первичных навыков -
     *это 999999,а для вторичных - 9999999. Чтобы корректно работали ограничители на
     *сеттерах это максимальное значение задаётся при инициализации*/
    Stat(int maximum, QString personName, QString statName);
    Stat(int maximum, QString personName, QString statName, QVector<Stat*>& stats);
    ~Stat();

    QString statName;

    int getValue() const;
    void setValue(int newValue);

    void addBonus(Bonus* bonus);

    /*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
     *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
     *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
     *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
    virtual bool removeBonus(Bonus* bonus);

    int getFinalValue() const;

    QVector<Bonus *> getBonuses();

    /*Очистка вектора бонусов. Метод не обновляет отображение бонусов в виджетах. Память указателей на
     *бонусы не высвобождается, так как это должно происходить только в классе предмета или эффекта*/
    void removeAllBonuses();

    bool saveStat(bool saveValue, bool saveBonuses, bool createBackup);
    // fastSaveble interface
    bool fastSave();

    bool loadStat(bool loadValue, bool loadBonuses);
    // fastLoadble interface
    bool fastLoad();

    //Так как класс Stat унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
    Stat& operator= (const Stat &stat);
    int getMaximum() const;

signals:
    void statChanged();

protected:
    //Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
    void createBackup();

    int value = 0;
    //Значение с учётом всех бонусов
    int finalValue = 0;
    //Максимальное значение стата
    int maximum = 0;

    QVector<Bonus*> bonuses;

    //Вычисление финального максимального значения стата с учётом всех бонусов
    void calculateFinalValue();
    QString personName;
};

#endif // STAT_H
