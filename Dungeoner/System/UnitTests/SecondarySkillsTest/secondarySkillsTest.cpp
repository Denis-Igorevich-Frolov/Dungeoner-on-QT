/***************************************************************************************
 *Данный класс является модулем юнит-тестов для тестирования вторичных навыков со
 *стороны их алгоритмического функционала (не GUI!). Тестирование проводится при
 *помощи макроса QFETCH и таблицы с окончанием _data для него у каждого метода.
 ***************************************************************************************/

#include "secondarySkillsTest.h"
#include <QTest>

SecondarySkillsTest::SecondarySkillsTest(QObject *parent)
    : QObject{parent}
{
}

void SecondarySkillsTest::recalculateMagicDamage()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->MagicDamage->recalculate(), result);
}

/*Тесты для проверки вычисления статов. Каждый выполняется в 4 прогона:
 *с минимальными значениями, максимальными и двумя произвольными.*/

/*Не смотря на то, что все значения первичных статов в каждом методе одинаковы, нет
 *смысла их выносить в отдельные переменные так как код от этого станет только
 *менее читабильным и будет сложнее увидеть откуда берётся результат.*/

void SecondarySkillsTest::recalculateMagicDamage_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 3499995;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 148;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 120;
}

void SecondarySkillsTest::recalculateResistPhysicalDamage()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->ResistPhysicalDamage->recalculate(), result);
}

void SecondarySkillsTest::recalculateResistPhysicalDamage_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 2999996;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 176;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 54;
}

void SecondarySkillsTest::recalculateResistMagicDamage()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->ResistMagicDamage->recalculate(), result);
}

void SecondarySkillsTest::recalculateResistMagicDamage_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 2999996;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 170;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 60;
}

void SecondarySkillsTest::recalculateResistPhysicalEffects()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->ResistPhysicalEffects->recalculate(), result);
}

void SecondarySkillsTest::recalculateResistPhysicalEffects_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 10;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 100009;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 16;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 11;
}

void SecondarySkillsTest::recalculateResistMagicEffects()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->ResistMagicEffects->recalculate(), result);
}

void SecondarySkillsTest::recalculateResistMagicEffects_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 5;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 200003;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 15;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 9;
}

void SecondarySkillsTest::recalculateStrengtheningPhysicalEffects()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->StrengtheningPhysicalEffects->recalculate(), result);
}

void SecondarySkillsTest::recalculateStrengtheningPhysicalEffects_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 99999;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 1;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 6;
}

void SecondarySkillsTest::recalculateStrengtheningMagicalEffects()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->StrengtheningMagicalEffects->recalculate(), result);
}

void SecondarySkillsTest::recalculateStrengtheningMagicalEffects_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 99999;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 3;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 4;
}

void SecondarySkillsTest::recalculateMeleeAccuracy()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->MeleeAccuracy->recalculate(), result);
}

void SecondarySkillsTest::recalculateMeleeAccuracy_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 20;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 100019;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 22;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 25;
}

void SecondarySkillsTest::recalculateRangedAccuracy()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->RangedAccuracy->recalculate(), result);
}

void SecondarySkillsTest::recalculateRangedAccuracy_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 15;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 100014;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 17;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 20;
}

void SecondarySkillsTest::recalculateMagicAccuracy()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->MagicAccuracy->recalculate(), result);
}

void SecondarySkillsTest::recalculateMagicAccuracy_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 15;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 100014;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 18;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 19;
}

void SecondarySkillsTest::recalculateEvasion()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Evasion->recalculate(), result);
}

void SecondarySkillsTest::recalculateEvasion_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 599998;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 16;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 29;
}

void SecondarySkillsTest::recalculateStealth()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Stealth->recalculate(), result);
}

void SecondarySkillsTest::recalculateStealth_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 1999998;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 55;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 99;
}

void SecondarySkillsTest::recalculateAttentiveness()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Attentiveness->recalculate(), result);
}

void SecondarySkillsTest::recalculateAttentiveness_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 2999997;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 121;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 110;
}

void SecondarySkillsTest::recalculateLoadCapacity()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->LoadCapacity->recalculate(), result);
}

void SecondarySkillsTest::recalculateLoadCapacity_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 999998;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 32;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 44;
}

void SecondarySkillsTest::recalculateInitiative()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Initiative->recalculate(), result);
}

void SecondarySkillsTest::recalculateInitiative_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 6999993;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 209;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 330;
}

void SecondarySkillsTest::recalculateMagicCastChance()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->MagicCastChance->recalculate(), result);
}

void SecondarySkillsTest::recalculateMagicCastChance_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 499998;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 17;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 19;
}

void SecondarySkillsTest::recalculateChanceOfUsingCombatTechnique()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->ChanceOfUsingCombatTechnique->recalculate(), result);
}

void SecondarySkillsTest::recalculateChanceOfUsingCombatTechnique_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 20;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 200019;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 24;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 31;
}

void SecondarySkillsTest::recalculateMoveRange()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->MoveRange->recalculate(), result);
}

void SecondarySkillsTest::recalculateMoveRange_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 2249997;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 76;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 96;
}

void SecondarySkillsTest::recalculateHealth()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Health->recalculate(), result);
}

void SecondarySkillsTest::recalculateHealth_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 9999999;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 946;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 440;
}

void SecondarySkillsTest::recalculateEndurance()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Endurance->recalculate(), result);
}

void SecondarySkillsTest::recalculateEndurance_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 9999999;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 275;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 572;
}

void SecondarySkillsTest::recalculateMana()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(int, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    QCOMPARE(person.getStats()->secondaryStats->Mana->recalculate(), result);
}

void SecondarySkillsTest::recalculateMana_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<int>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< 0;

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< 9999999;

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< 572;

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< 429;
}

void SecondarySkillsTest::recalculateMagicDefense()
{
    QFETCH(int, strength);
    QFETCH(int, agility);
    QFETCH(int, intelligence);
    QFETCH(int, magic);
    QFETCH(int, bodyType);
    QFETCH(int, will);
    QFETCH(QVector<Chunk>, result);

    person.getStats()->primaryStats->Strength->setValue(strength);
    person.getStats()->primaryStats->Agility->setValue(agility);
    person.getStats()->primaryStats->Intelligence->setValue(intelligence);
    person.getStats()->primaryStats->Magic->setValue(magic);
    person.getStats()->primaryStats->BodyType->setValue(bodyType);
    person.getStats()->primaryStats->Will->setValue(will);

    person.recalculateMagicDefense();

    /*Так как изначальный вектор является вектором указателей, а мне требуется сравнивать именно значения,
     *здесь эти указатели разыменовываются и помещаются в новый вектор уже с типом данных просто Chunk.*/
    QVector<Chunk> actualChunks{};
    for(Chunk* c : person.getMagicDefense()->getChunks())
        actualChunks.append(*c);

    QCOMPARE(actualChunks, result);
}

void SecondarySkillsTest::recalculateMagicDefense_data()
{
    QTest::addColumn<int>("strength");
    QTest::addColumn<int>("agility");
    QTest::addColumn<int>("intelligence");
    QTest::addColumn<int>("magic");
    QTest::addColumn<int>("bodyType");
    QTest::addColumn<int>("will");
    QTest::addColumn<QVector<Chunk>>("result");

    QTest::newRow("recalculate_1")
            /*Сила:---------*/<< 0
            /*Ловкость:-----*/<< 0
            /*Интеллект:----*/<< 0
            /*Магия:--------*/<< 0
            /*Телосложение:-*/<< 0
            /*Воля:---------*/<< 0
            /*Резуьтат:-----*/<< QVector<Chunk>{};

    QTest::newRow("recalculate_2")
            /*Сила:---------*/<< 999999
            /*Ловкость:-----*/<< 999999
            /*Интеллект:----*/<< 999999
            /*Магия:--------*/<< 999999
            /*Телосложение:-*/<< 999999
            /*Воля:---------*/<< 999999
            /*Резуьтат:-----*/<< QVector<Chunk>{Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0),
                                                Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0), Chunk(10000, 0)};

    QTest::newRow("recalculate_3")
            /*Сила:---------*/<< 11
            /*Ловкость:-----*/<< 22
            /*Интеллект:----*/<< 33
            /*Магия:--------*/<< 44
            /*Телосложение:-*/<< 55
            /*Воля:---------*/<< 66
            /*Резуьтат:-----*/<< QVector<Chunk>{Chunk(47, 0), Chunk(47, 0), Chunk(47, 0), Chunk(47, 0),
                                                Chunk(47, 0), Chunk(47, 0), Chunk(47, 0)};

    QTest::newRow("recalculate_4")
            /*Сила:---------*/<< 66
            /*Ловкость:-----*/<< 55
            /*Интеллект:----*/<< 44
            /*Магия:--------*/<< 33
            /*Телосложение:-*/<< 22
            /*Воля:---------*/<< 11
            /*Резуьтат:-----*/<< QVector<Chunk>{Chunk(29, 0), Chunk(29, 0)};
}
