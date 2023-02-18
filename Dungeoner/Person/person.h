/********************************************************************************************************************
 *Данный класс является классом вычисления, хранения, управления, сохранения и загрузки всех данных о персонаже.
 ********************************************************************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include "Person/MagicDefense/magicdefensebonus.h"
#include "Person/SecondaryStat/secondarystat.h"
#include "Person/Stat/stat.h"

#include <Global/global.h>

#include <qspinbox.h>

class Person : public QObject
{
    Q_OBJECT
public:
    Person();
    ~Person();

    bool addBonusToStat(Bonus* bonus);
    //Добавление бонуса на магическую защиту
    void addBonusToStat(MagicDefenseBonus* bonus);

    bool removeBonusFromStat(Bonus* bonus);
    //Удаление бонуса с магической защиты
    bool removeBonusFromStat(MagicDefenseBonus* bonus);

    //Перерасчёт вторичных навыков
    void recalculateStats();

    QString getPersonName() const;
    void setPersonName(const QString &newPersonName);

    StatsStruct* getStats();

signals:
    //Запрос на полную переинициализацию виджетов статов
    void FullReinitializationRequest();
public slots:
    /*Слот полной переинициализации. Каждый раз когда операции с бонусами проваливаются
     *запрашивается их полная переинциализация для избежания последующих проблем.*/
    void fullReinitialization();

    bool saveAllStats(bool createBackup);
    bool loadAllStats();

private:
    //Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
    void createBackup();

    QString personName = "new hero";

    QVector<Stat *> primaryStatsVector;
    QVector<RecalculatebleStat *> secondaryStatsVector;
    QVector<Stat*> allStats;
    StatsStruct* stats;
};

#endif // PERSON_H
