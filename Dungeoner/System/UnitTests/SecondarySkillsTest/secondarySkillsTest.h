/***************************************************************************************
 *Данный класс является модулем юнит-тестов для тестирования вторичных навыков со
 *стороны их алгоритмического функционала (не GUI!). Тестирование проводится при
 *помощи макроса QFETCH и таблицы с окончанием _data для него у каждого метода.
 ***************************************************************************************/

#ifndef SECONDARYSKILLSTEST_H
#define SECONDARYSKILLSTEST_H

#include "Person/person.h"
#include <QObject>

class SecondarySkillsTest : public QObject
{
    Q_OBJECT
public:
    explicit SecondarySkillsTest(QObject *parent = nullptr);

private slots:
    /*Тесты для проверки вычисления статов. Каждый выполняется в 4 прогона:
     *с минимальными значениями, максимальными и двумя произвольными.*/

    void recalculateMagicDamage();
    void recalculateMagicDamage_data();

    void recalculateResistPhysicalDamage();
    void recalculateResistPhysicalDamage_data();

    void recalculateResistMagicDamage();
    void recalculateResistMagicDamage_data();

    void recalculateResistPhysicalEffects();
    void recalculateResistPhysicalEffects_data();

    void recalculateResistMagicEffects();
    void recalculateResistMagicEffects_data();

    void recalculateStrengtheningPhysicalEffects();
    void recalculateStrengtheningPhysicalEffects_data();

    void recalculateStrengtheningMagicalEffects();
    void recalculateStrengtheningMagicalEffects_data();

    void recalculateMeleeAccuracy();
    void recalculateMeleeAccuracy_data();

    void recalculateRangedAccuracy();
    void recalculateRangedAccuracy_data();

    void recalculateMagicAccuracy();
    void recalculateMagicAccuracy_data();

    void recalculateEvasion();
    void recalculateEvasion_data();

    void recalculateStealth();
    void recalculateStealth_data();

    void recalculateAttentiveness();
    void recalculateAttentiveness_data();

    void recalculateLoadCapacity();
    void recalculateLoadCapacity_data();

    void recalculateInitiative();
    void recalculateInitiative_data();

    void recalculateMagicCastChance();
    void recalculateMagicCastChance_data();

    void recalculateChanceOfUsingCombatTechnique();
    void recalculateChanceOfUsingCombatTechnique_data();

    void recalculateMoveRange();
    void recalculateMoveRange_data();

    void recalculateHealth();
    void recalculateHealth_data();

    void recalculateEndurance();
    void recalculateEndurance_data();

    void recalculateMana();
    void recalculateMana_data();

    void recalculateMagicDefense();
    void recalculateMagicDefense_data();

private:
    Person person = Person();
};

#endif // SECONDARYSKILLSTEST_H
