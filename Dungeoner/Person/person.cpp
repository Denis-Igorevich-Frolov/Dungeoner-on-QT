#include "person.h"

#include <QDate>
#include <qfile.h>

void Person::addBonusToStat(Bonus *bonus)
{
    switch (bonus->statName) {
    case Bonus::STRENGTH:
        StrengthBonuses.append(bonus);
        Strength.addBonus(bonus);
        emit StrengthBonusesChanged();
        break;
    case Bonus::AGILITY:
        AgilityBonuses.append(bonus);
        Agility.addBonus(bonus);
        emit AgilityBonusesChanged();
        break;
    case Bonus::INTELLIGENCE:
        IntelligenceBonuses.append(bonus);
        Intelligence.addBonus(bonus);
        emit IntelligenceBonusesChanged();
        break;
    case Bonus::MAGIC:
        MagicBonuses.append(bonus);
        Magic.addBonus(bonus);
        emit MagicBonusesChanged();
        break;
    case Bonus::BODYTYPE:
        BodyTypeBonuses.append(bonus);
        BodyType.addBonus(bonus);
        emit BodyTypeBonusesChanged();
        break;
    case Bonus::WILL:
        WillBonuses.append(bonus);
        Will.addBonus(bonus);
        emit WillBonusesChanged();
        break;
    case Bonus::MAGIC_DAMAGE:
        MagicDamageBonuses.append(bonus);
        MagicDamage.addBonus(bonus);
        break;
    case Bonus::RESIST_PHYSICAL_DAMAGE:
        ResistPhysicalDamageBonuses.append(bonus);
        ResistPhysicalDamage.addBonus(bonus);
        break;
    case Bonus::RESIST_MAGIC_DAMAGE:
        ResistMagicDamageBonuses.append(bonus);
        ResistMagicDamage.addBonus(bonus);
        break;
    case Bonus::RESIST_PHYSICAL_EFFECTS:
        ResistPhysicalEffectsBonuses.append(bonus);
        ResistPhysicalEffects.addBonus(bonus);
        break;
    case Bonus::RESIST_MAGIC_EFFECTS:
        ResistMagicEffectsBonuses.append(bonus);
        ResistMagicEffects.addBonus(bonus);
        break;
    case Bonus::STRENGTHENING_PHYSICAL_EFFECTS:
        StrengtheningPhysicalEffectsBonuses.append(bonus);
        StrengtheningPhysicalEffects.addBonus(bonus);
        break;
    case Bonus::STRENGTHENING_MAGICAL_EFFECTS:
        StrengtheningMagicalEffectsBonuses.append(bonus);
        StrengtheningMagicalEffects.addBonus(bonus);
        break;
    case Bonus::MELEE_ACCURACY:
        MeleeAccuracyBonuses.append(bonus);
        MeleeAccuracy.addBonus(bonus);
        break;
    case Bonus::RANGED_ACCURACY:
        RangedAccuracyBonuses.append(bonus);
        RangedAccuracy.addBonus(bonus);
        break;
    case Bonus::MAGIC_ACCURACY:
        MagicAccuracyBonuses.append(bonus);
        MagicAccuracy.addBonus(bonus);
        break;
    case Bonus::EVASION:
        EvasionBonuses.append(bonus);
        Evasion.addBonus(bonus);
        break;
    case Bonus::STEALTH:
        StealthBonuses.append(bonus);
        Stealth.addBonus(bonus);
        break;
    case Bonus::ATTENTIVENESS:
        AttentivenessBonuses.append(bonus);
        Attentiveness.addBonus(bonus);
        break;
    case Bonus::LOAD_CAPACITY:
        LoadCapacityBonuses.append(bonus);
        LoadCapacity.addBonus(bonus);
        break;
    case Bonus::INITIATIVE:
        InitiativeBonuses.append(bonus);
        Initiative.addBonus(bonus);
        break;
    case Bonus::MAGIC_CAST_CHANCE:
        MagicCastChanceBonuses.append(bonus);
        MagicCastChance.addBonus(bonus);
        break;
    case Bonus::CHANCE_OF_USING_COMBAT_TECHNIQUE:
        ChanceOfUsingCombatTechniqueBonuses.append(bonus);
        ChanceOfUsingCombatTechnique.addBonus(bonus);
        break;
    case Bonus::MOVE_RANGE:
        MoveRangeBonuses.append(bonus);
        MoveRange.addBonus(bonus);
        break;
    case Bonus::HEALTH:
        HealthBonuses.append(bonus);
        Health.addBonus(bonus);
        break;
    case Bonus::ENDURANCE:
        EnduranceBonuses.append(bonus);
        Endurance.addBonus(bonus);
        break;
    case Bonus::MANA:
        ManaBonuses.append(bonus);
        Mana.addBonus(bonus);
        break;
    }
}

//Добавление бонуса на магическую защиту
void Person::addBonusToStat(MagicDefenseBonus *bonus)
{
    magicDefenseBonuses.append(bonus);
    magicDefense.addBonus(bonus);
}

bool Person::removeBonusFromStat(Bonus *bonus)
{
    //Переменная, говорящая о том было ли успешным удаление бонуса
    bool successful;
    switch (bonus->statName) {
    case Bonus::STRENGTH:
        successful = bonusRemoval(StrengthBonuses, bonus);
        Strength.reinitializationOfBonuses(StrengthBonuses);
        emit StrengthBonusesChanged();
        return successful;
    case Bonus::AGILITY:
        successful = bonusRemoval(AgilityBonuses, bonus);
        Agility.reinitializationOfBonuses(AgilityBonuses);
        emit AgilityBonusesChanged();
        return successful;
    case Bonus::INTELLIGENCE:
        successful = bonusRemoval(IntelligenceBonuses, bonus);
        Intelligence.reinitializationOfBonuses(IntelligenceBonuses);
        emit IntelligenceBonusesChanged();
        return successful;
    case Bonus::MAGIC:
        successful = bonusRemoval(MagicBonuses, bonus);
        Magic.reinitializationOfBonuses(MagicBonuses);
        emit MagicBonusesChanged();
        return successful;
    case Bonus::BODYTYPE:
        successful = bonusRemoval(BodyTypeBonuses, bonus);
        BodyType.reinitializationOfBonuses(BodyTypeBonuses);
        emit BodyTypeBonusesChanged();
        return successful;
    case Bonus::WILL:
        successful = bonusRemoval(WillBonuses, bonus);
        Will.reinitializationOfBonuses(WillBonuses);
        emit WillBonusesChanged();
        return successful;
    case Bonus::MAGIC_DAMAGE:
        successful = bonusRemoval(MagicDamageBonuses, bonus);
        MagicDamage.reinitializationOfBonuses(MagicDamageBonuses);
        return successful;
    case Bonus::RESIST_PHYSICAL_DAMAGE:
        successful = bonusRemoval(ResistPhysicalDamageBonuses, bonus);
        ResistPhysicalDamage.reinitializationOfBonuses(ResistPhysicalDamageBonuses);
        return successful;
    case Bonus::RESIST_MAGIC_DAMAGE:
        successful = bonusRemoval(ResistMagicDamageBonuses, bonus);
        ResistMagicDamage.reinitializationOfBonuses(ResistMagicDamageBonuses);
        return successful;
    case Bonus::RESIST_PHYSICAL_EFFECTS:
        successful = bonusRemoval(ResistPhysicalEffectsBonuses, bonus);
        ResistPhysicalEffects.reinitializationOfBonuses(ResistPhysicalEffectsBonuses);
        return successful;
    case Bonus::RESIST_MAGIC_EFFECTS:
        successful = bonusRemoval(ResistMagicEffectsBonuses, bonus);
        ResistMagicEffects.reinitializationOfBonuses(ResistMagicEffectsBonuses);
        return successful;
    case Bonus::STRENGTHENING_PHYSICAL_EFFECTS:
        successful = bonusRemoval(StrengtheningPhysicalEffectsBonuses, bonus);
        StrengtheningPhysicalEffects.reinitializationOfBonuses(StrengtheningPhysicalEffectsBonuses);
        return successful;
    case Bonus::STRENGTHENING_MAGICAL_EFFECTS:
        successful = bonusRemoval(StrengtheningMagicalEffectsBonuses, bonus);
        StrengtheningMagicalEffects.reinitializationOfBonuses(StrengtheningMagicalEffectsBonuses);
        return successful;
    case Bonus::MELEE_ACCURACY:
        successful = bonusRemoval(MeleeAccuracyBonuses, bonus);
        MeleeAccuracy.reinitializationOfBonuses(MeleeAccuracyBonuses);
        return successful;
    case Bonus::RANGED_ACCURACY:
        successful = bonusRemoval(RangedAccuracyBonuses, bonus);
        RangedAccuracy.reinitializationOfBonuses(RangedAccuracyBonuses);
        return successful;
    case Bonus::MAGIC_ACCURACY:
        successful = bonusRemoval(MagicAccuracyBonuses, bonus);
        MagicAccuracy.reinitializationOfBonuses(MagicAccuracyBonuses);
        return successful;
    case Bonus::EVASION:
        successful = bonusRemoval(EvasionBonuses, bonus);
        Evasion.reinitializationOfBonuses(EvasionBonuses);
        return successful;
    case Bonus::STEALTH:
        successful = bonusRemoval(StealthBonuses, bonus);
        Stealth.reinitializationOfBonuses(StealthBonuses);
        return successful;
    case Bonus::ATTENTIVENESS:
        successful = bonusRemoval(AttentivenessBonuses, bonus);
        Attentiveness.reinitializationOfBonuses(AttentivenessBonuses);
        return successful;
    case Bonus::LOAD_CAPACITY:
        successful = bonusRemoval(LoadCapacityBonuses, bonus);
        LoadCapacity.reinitializationOfBonuses(LoadCapacityBonuses);
        return successful;
    case Bonus::INITIATIVE:
        successful = bonusRemoval(InitiativeBonuses, bonus);
        Initiative.reinitializationOfBonuses(InitiativeBonuses);
        return successful;
    case Bonus::MAGIC_CAST_CHANCE:
        successful = bonusRemoval(MagicCastChanceBonuses, bonus);
        MagicCastChance.reinitializationOfBonuses(MagicCastChanceBonuses);
        return successful;
    case Bonus::CHANCE_OF_USING_COMBAT_TECHNIQUE:
        successful = bonusRemoval(ChanceOfUsingCombatTechniqueBonuses, bonus);
        ChanceOfUsingCombatTechnique.reinitializationOfBonuses(ChanceOfUsingCombatTechniqueBonuses);
        return successful;
    case Bonus::MOVE_RANGE:
        successful = bonusRemoval(MoveRangeBonuses, bonus);
        MoveRange.reinitializationOfBonuses(MoveRangeBonuses);
        return successful;
    case Bonus::HEALTH:
        successful = bonusRemoval(HealthBonuses, bonus);
        Health.reinitializationOfBonuses(HealthBonuses);
        return successful;
    case Bonus::ENDURANCE:
        successful = bonusRemoval(EnduranceBonuses, bonus);
        Endurance.reinitializationOfBonuses(EnduranceBonuses);
        return successful;
    case Bonus::MANA:
        successful = bonusRemoval(ManaBonuses, bonus);
        Mana.reinitializationOfBonuses(ManaBonuses);
        return successful;
    default:
        return false;
    }
}

/*Метод непосредственно удаляющий бонусы, в отличии от
 *removeBonusFromStat, который лишь направляет данные сюда*/
bool Person::bonusRemoval(QVector<Bonus*>& bonuses, Bonus *bonus)
{
    QMutableVectorIterator<Bonus*> iterator(bonuses);
    iterator.toBack();
    Bonus* MD;
    //Итератор идёт с конца, чтобы найти ближайшее к краю совпадение
    while(iterator.hasPrevious()){
        MD = iterator.previous();
        if(*MD==*bonus){
            delete MD;
            iterator.remove();
            return true;
        }
    }
    /*Если ничего найдено небыло, то выводится предупреждение. Вызывающему классу следует
     *запросить полный пересчёт всех бонусов и провести полную переинициализацию.*/

    //Вывод предупреждения в консоль и файл
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    QString error =
    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
    "\nПРЕДУПРЕЖДЕНИЕ: не найден Bonus\n"
    "Person выдал предупреждение в методе bonusRemoval.\n"
    "При попытке удалить Bonus, он не был обнаружен.\n\n";
    qDebug()<<error;

    QFile errorFile("error log.txt");
    if (!errorFile.open(QIODevice::Append))
    {
        qDebug() << "Ошибка при открытии файла логов";
    }else{
        errorFile.open(QIODevice::Append  | QIODevice::Text);
        QTextStream writeStream(&errorFile);
        writeStream<<error;
        errorFile.close();
    }
    return false;
}

//Удаление бонуса с магической защиты
bool Person::removeBonusFromStat(MagicDefenseBonus *bonus)
{
    QMutableVectorIterator<MagicDefenseBonus*> iterator(magicDefenseBonuses);
    iterator.toBack();
    MagicDefenseBonus* MD;
    //Итератор идёт с конца, чтобы найти ближайшее к краю совпадение
    while(iterator.hasPrevious()){
        MD = iterator.previous();
        if(*MD==*bonus){
            delete MD;
            iterator.remove();

            magicDefense.reinitializationOfBonuses(magicDefenseBonuses);

            return true;
        }
    }
    /*Если ничего найдено небыло, то выводится предупреждение. Вызывающему классу следует
     *запросить полный пересчёт всех векторов чанков и провести их полную переинициализацию.*/

    //Вывод предупреждения в консоль и файл
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    QString error =
    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
    "\nПРЕДУПРЕЖДЕНИЕ: не найден MagicDefenseBonus\n"
    "Person выдал предупреждение в методе removeBonusFromStat.\n"
    "При попытке удалить MagicDefenseBonus, он не был обнаружен.\n\n";
    qDebug()<<error;

    QFile errorFile("error log.txt");
    if (!errorFile.open(QIODevice::Append))
    {
        qDebug() << "Ошибка при открытии файла логов";
    }else{
        errorFile.open(QIODevice::Append  | QIODevice::Text);
        QTextStream writeStream(&errorFile);
        writeStream<<error;
        errorFile.close();
    }
    return false;
}

Stat* Person::getStrength()
{
    return &Strength;
}

void Person::setStrength(Stat &newStrength)
{
    Strength = newStrength;
}

Stat* Person::getAgility()
{
    return &Agility;
}

void Person::setAgility(Stat &newAgility)
{
    Agility = newAgility;
}

Stat* Person::getIntelligence()
{
    return &Intelligence;
}

void Person::setIntelligence(Stat &newIntelligence)
{
    Intelligence = newIntelligence;
}

Stat* Person::getMagic()
{
    return &Magic;
}

void Person::setMagic(Stat &newMagic)
{
    Magic = newMagic;
}

Stat* Person::getBodyType()
{
    return &BodyType;
}

void Person::setBodyType(Stat &newBodyType)
{
    BodyType = newBodyType;
}

Stat* Person::getWill()
{
    return &Will;
}

void Person::setWill(Stat &newWill)
{
    Will = newWill;
}

Stat* Person::getMagicDamage()
{
    return &MagicDamage;
}

void Person::setMagicDamage(Stat &newMagicDamage)
{
    MagicDamage = newMagicDamage;
}

Stat* Person::getResistPhysicalDamage()
{
    return &ResistPhysicalDamage;
}

void Person::setResistPhysicalDamage(Stat &newResistPhysicalDamage)
{
    ResistPhysicalDamage = newResistPhysicalDamage;
}

Stat* Person::getResistMagicDamage()
{
    return &ResistMagicDamage;
}

void Person::setResistMagicDamage(Stat &newResistMagicDamage)
{
    ResistMagicDamage = newResistMagicDamage;
}

Stat* Person::getResistPhysicalEffects()
{
    return &ResistPhysicalEffects;
}

void Person::setResistPhysicalEffects(Stat &newResistPhysicalEffects)
{
    ResistPhysicalEffects = newResistPhysicalEffects;
}

Stat* Person::getResistMagicEffects()
{
    return &ResistMagicEffects;
}

void Person::setResistMagicEffects(Stat &newResistMagicEffects)
{
    ResistMagicEffects = newResistMagicEffects;
}

Stat* Person::getStrengtheningPhysicalEffects()
{
    return &StrengtheningPhysicalEffects;
}

void Person::setStrengtheningPhysicalEffects(Stat &newStrengtheningPhysicalEffects)
{
    StrengtheningPhysicalEffects = newStrengtheningPhysicalEffects;
}

Stat* Person::getStrengtheningMagicalEffects()
{
    return &StrengtheningMagicalEffects;
}

void Person::setStrengtheningMagicalEffects(Stat &newStrengtheningMagicalEffects)
{
    StrengtheningMagicalEffects = newStrengtheningMagicalEffects;
}

Stat* Person::getMeleeAccuracy()
{
    return &MeleeAccuracy;
}

void Person::setMeleeAccuracy(Stat &newMeleeAccuracy)
{
    MeleeAccuracy = newMeleeAccuracy;
}

Stat* Person::getRangedAccuracy()
{
    return &RangedAccuracy;
}

void Person::setRangedAccuracy(Stat &newRangedAccuracy)
{
    RangedAccuracy = newRangedAccuracy;
}

Stat* Person::getMagicAccuracy()
{
    return &MagicAccuracy;
}

void Person::setMagicAccuracy(Stat &newMagicAccuracy)
{
    MagicAccuracy = newMagicAccuracy;
}

Stat* Person::getEvasion()
{
    return &Evasion;
}

void Person::setEvasion(Stat &newEvasion)
{
    Evasion = newEvasion;
}

Stat* Person::getStealth()
{
    return &Stealth;
}

void Person::setStealth(Stat &newStealth)
{
    Stealth = newStealth;
}

Stat* Person::getAttentiveness()
{
    return &Attentiveness;
}

void Person::setAttentiveness(Stat &newAttentiveness)
{
    Attentiveness = newAttentiveness;
}

Stat* Person::getLoadCapacity()
{
    return &LoadCapacity;
}

void Person::setLoadCapacity(Stat &newLoadCapacity)
{
    LoadCapacity = newLoadCapacity;
}

Stat* Person::getInitiative()
{
    return &Initiative;
}

void Person::setInitiative(Stat &newInitiative)
{
    Initiative = newInitiative;
}

Stat* Person::getMagicCastChance()
{
    return &MagicCastChance;
}

void Person::setMagicCastChance(Stat &newMagicCastChance)
{
    MagicCastChance = newMagicCastChance;
}

Stat* Person::getChanceOfUsingCombatTechnique()
{
    return &ChanceOfUsingCombatTechnique;
}

void Person::setChanceOfUsingCombatTechnique(Stat &newChanceOfUsingCombatTechnique)
{
    ChanceOfUsingCombatTechnique = newChanceOfUsingCombatTechnique;
}

Stat* Person::getMoveRange()
{
    return &MoveRange;
}

void Person::setMoveRange(Stat &newMoveRange)
{
    MoveRange = newMoveRange;
}

Stat* Person::getHealth()
{
    return &Health;
}

void Person::setHealth(Stat &newHealth)
{
    Health = newHealth;
}

Stat* Person::getEndurance()
{
    return &Endurance;
}

void Person::setEndurance(Stat &newEndurance)
{
    Endurance = newEndurance;
}

Stat* Person::getMana()
{
    return &Mana;
}

void Person::setMana(Stat &newMana)
{
    Mana = newMana;
}

MagicDefense* Person::getMagicDefense()
{
    return &magicDefense;
}

void Person::setMagicDefense(MagicDefense &newMagicDefense)
{
    magicDefense = newMagicDefense;
}
