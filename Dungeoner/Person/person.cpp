/********************************************************************************************************************
 *Данный класс является классом вычисления, хранения, управления, сохранения и загрузки всех данных о персонаже.
 ********************************************************************************************************************/

#include "person.h"
#include "QtSql/qsqldatabase.h"

#include <QDate>
#include <QDir>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

void Person::addBonusToStat(Bonus *bonus)
{
    switch (bonus->statName) {
    case Bonus::STRENGTH:
        Strength.addBonus(bonus);
        break;
    case Bonus::AGILITY:
        Agility.addBonus(bonus);
        break;
    case Bonus::INTELLIGENCE:
        Intelligence.addBonus(bonus);
        break;
    case Bonus::MAGIC:
        Magic.addBonus(bonus);
        break;
    case Bonus::BODYTYPE:
        BodyType.addBonus(bonus);
        break;
    case Bonus::WILL:
        Will.addBonus(bonus);
        break;
    case Bonus::MAGIC_DAMAGE:
        MagicDamage.addBonus(bonus);
        break;
    case Bonus::RESIST_PHYSICAL_DAMAGE:
        ResistPhysicalDamage.addBonus(bonus);
        break;
    case Bonus::RESIST_MAGIC_DAMAGE:
        ResistMagicDamage.addBonus(bonus);
        break;
    case Bonus::RESIST_PHYSICAL_EFFECTS:
        ResistPhysicalEffects.addBonus(bonus);
        break;
    case Bonus::RESIST_MAGIC_EFFECTS:
        ResistMagicEffects.addBonus(bonus);
        break;
    case Bonus::STRENGTHENING_PHYSICAL_EFFECTS:
        StrengtheningPhysicalEffects.addBonus(bonus);
        break;
    case Bonus::STRENGTHENING_MAGICAL_EFFECTS:
        StrengtheningMagicalEffects.addBonus(bonus);
        break;
    case Bonus::MELEE_ACCURACY:
        MeleeAccuracy.addBonus(bonus);
        break;
    case Bonus::RANGED_ACCURACY:
        RangedAccuracy.addBonus(bonus);
        break;
    case Bonus::MAGIC_ACCURACY:
        MagicAccuracy.addBonus(bonus);
        break;
    case Bonus::EVASION:
        Evasion.addBonus(bonus);
        break;
    case Bonus::STEALTH:
        Stealth.addBonus(bonus);
        break;
    case Bonus::ATTENTIVENESS:
        Attentiveness.addBonus(bonus);
        break;
    case Bonus::LOAD_CAPACITY:
        LoadCapacity.addBonus(bonus);
        break;
    case Bonus::INITIATIVE:
        Initiative.addBonus(bonus);
        break;
    case Bonus::MAGIC_CAST_CHANCE:
        MagicCastChance.addBonus(bonus);
        break;
    case Bonus::CHANCE_OF_USING_COMBAT_TECHNIQUE:
        ChanceOfUsingCombatTechnique.addBonus(bonus);
        break;
    case Bonus::MOVE_RANGE:
        MoveRange.addBonus(bonus);
        break;
    case Bonus::HEALTH:
        Health.addBonus(bonus);
        break;
    case Bonus::ENDURANCE:
        Endurance.addBonus(bonus);
        break;
    case Bonus::MANA:
        Mana.addBonus(bonus);
        break;
    }
}

//Добавление бонуса на магическую защиту
void Person::addBonusToStat(MagicDefenseBonus *bonus)
{
    magicDefense.addBonus(bonus);
}

bool Person::removeBonusFromStat(Bonus *bonus)
{
    //Переменная, говорящая о том было ли успешным удаление бонуса
    bool successful;
    switch (bonus->statName) {
    case Bonus::STRENGTH:
        successful = Strength.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::AGILITY:
        successful = Agility.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::INTELLIGENCE:
        successful = Intelligence.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MAGIC:
        successful = Magic.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::BODYTYPE:
        successful = BodyType.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::WILL:
        successful = Will.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MAGIC_DAMAGE:
        successful =  MagicDamage.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::RESIST_PHYSICAL_DAMAGE:
        successful =  ResistPhysicalDamage.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::RESIST_MAGIC_DAMAGE:
        successful =  ResistMagicDamage.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::RESIST_PHYSICAL_EFFECTS:
        successful =  ResistPhysicalEffects.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::RESIST_MAGIC_EFFECTS:
        successful =  ResistMagicEffects.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::STRENGTHENING_PHYSICAL_EFFECTS:
        successful =  StrengtheningPhysicalEffects.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::STRENGTHENING_MAGICAL_EFFECTS:
        successful =  StrengtheningMagicalEffects.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MELEE_ACCURACY:
        successful =  MeleeAccuracy.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::RANGED_ACCURACY:
        successful =  RangedAccuracy.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MAGIC_ACCURACY:
        successful =  MagicAccuracy.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::EVASION:
        successful =  Evasion.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::STEALTH:
        successful =  Stealth.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::ATTENTIVENESS:
        successful =  Attentiveness.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::LOAD_CAPACITY:
        successful =  LoadCapacity.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::INITIATIVE:
        successful =  Initiative.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MAGIC_CAST_CHANCE:
        successful =  MagicCastChance.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::CHANCE_OF_USING_COMBAT_TECHNIQUE:
        successful =  ChanceOfUsingCombatTechnique.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MOVE_RANGE:
        successful =  MoveRange.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::HEALTH:
        successful =  Health.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::ENDURANCE:
        successful =  Endurance.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MANA:
        successful =  Mana.removeBonus(bonus);
        if (!successful)
            fullReinitialization();
        return successful;
    default:
        return false;
    }
}

//Удаление бонуса с магической защиты
bool Person::removeBonusFromStat(MagicDefenseBonus *bonus)
{
    //Переменная, говорящая о том было ли успешным удаление бонуса
    bool successful = magicDefense.removeBonus(bonus);

    if (!successful)
        fullReinitialization();
    return successful;
}

//Перерасчёт вторичных навыков
void Person::recalculateStats()
{
    recalculateMagicDamage();
    recalculateResistPhysicalDamage();
    recalculateResistMagicDamage();
    recalculateResistPhysicalEffects();
    recalculateResistMagicEffects();
    recalculateStrengtheningPhysicalEffects();
    recalculateStrengtheningMagicalEffects();
    recalculateMeleeAccuracy();
    recalculateRangedAccuracy();
    recalculateMagicAccuracy();
    recalculateEvasion();
    recalculateStealth();
    recalculateAttentiveness();
    recalculateLoadCapacity();
    recalculateInitiative();
    recalculateMagicCastChance();
    recalculateChanceOfUsingCombatTechnique();
    recalculateMoveRange();
    recalculateHealth();
    recalculateEndurance();
    recalculateMana();
    recalculateMagicDefense();
}

int Person::recalculateMagicDamage()
{
    int magicDamage =
    floor(1.5 * Magic.getFinalValue()) + floor(1.5 * Intelligence.getFinalValue()) + floor(0.5 * Will.getFinalValue());
    MagicDamage.setValue(magicDamage);

    return MagicDamage.getFinalValue();
}

int Person::recalculateResistPhysicalDamage()
{
    int resistPhysicalDamage = floor(1.5 * Will.getFinalValue()) + floor(0.5 * Magic.getFinalValue()) + BodyType.getFinalValue();
    ResistPhysicalDamage.setValue(resistPhysicalDamage);

    return ResistPhysicalDamage.getFinalValue();
}

int Person::recalculateResistMagicDamage()
{
    int resistMagicDamage = floor(1.5 * Will.getFinalValue()) + floor(0.5 * BodyType.getFinalValue()) + Magic.getFinalValue();
    ResistMagicDamage.setValue(resistMagicDamage);

    return ResistMagicDamage.getFinalValue();
}

int Person::recalculateResistPhysicalEffects()
{
    int resistPhysicalEffects = floor(0.1 * Will.getFinalValue()) + 10;
    ResistPhysicalEffects.setValue(resistPhysicalEffects);

    return ResistPhysicalEffects.getFinalValue();
}

int Person::recalculateResistMagicEffects()
{
    int resistMagicEffects = floor(0.1 * Will.getFinalValue()) + floor(0.1 * Magic.getFinalValue()) + 5;
    ResistMagicEffects.setValue(resistMagicEffects);

    return ResistMagicEffects.getFinalValue();
}

int Person::recalculateStrengtheningPhysicalEffects()
{
    int strengtheningPhysicalEffects = floor(0.1 * Strength.getFinalValue());
    StrengtheningPhysicalEffects.setValue(strengtheningPhysicalEffects);

    return StrengtheningPhysicalEffects.getFinalValue();
}

int Person::recalculateStrengtheningMagicalEffects()
{
    int strengtheningMagicalEffects = floor(0.1 * Intelligence.getFinalValue());
    StrengtheningMagicalEffects.setValue(strengtheningMagicalEffects);

    return StrengtheningMagicalEffects.getFinalValue();
}

int Person::recalculateMeleeAccuracy()
{
    int meleeAccuracy = floor(0.1 * Agility.getFinalValue()) + 20;
    MeleeAccuracy.setValue(meleeAccuracy);

    return MeleeAccuracy.getFinalValue();
}

int Person::recalculateRangedAccuracy()
{
    int rangedAccuracy = floor(0.1 * Agility.getFinalValue()) + 15;
    RangedAccuracy.setValue(rangedAccuracy);

    return RangedAccuracy.getFinalValue();
}

int Person::recalculateMagicAccuracy()
{
    int magicAccuracy = floor(0.1 * Intelligence.getFinalValue()) + 15;
    MagicAccuracy.setValue(magicAccuracy);

    return MagicAccuracy.getFinalValue();
}

int Person::recalculateEvasion()
{
    int evasion = floor(0.5 * Agility.getFinalValue()) + floor(0.1 * BodyType.getFinalValue());
    Evasion.setValue(evasion);

    return Evasion.getFinalValue();
}

int Person::recalculateStealth()
{
    int stealth = Intelligence.getFinalValue() + Agility.getFinalValue();
    Stealth.setValue(stealth);

    return Stealth.getFinalValue();
}

int Person::recalculateAttentiveness()
{
    int attentiveness = Intelligence.getFinalValue() + Agility.getFinalValue() + Will.getFinalValue();
    Attentiveness.setValue(attentiveness);

    return Attentiveness.getFinalValue();
}

int Person::recalculateLoadCapacity()
{
    int loadCapacity = floor(0.5 * Strength.getFinalValue()) + floor(0.5 * BodyType.getFinalValue());
    LoadCapacity.setValue(loadCapacity);

    return LoadCapacity.getFinalValue();
}

int Person::recalculateInitiative()
{
    int initiative = floor(5 * Agility.getFinalValue()) + Intelligence.getFinalValue() + Will.getFinalValue();
    Initiative.setValue(initiative);

    return Initiative.getFinalValue();
}

int Person::recalculateMagicCastChance()
{
    int magicCastChance = floor(0.3 * Intelligence.getFinalValue()) + floor(0.2 * Magic.getFinalValue());
    MagicCastChance.setValue(magicCastChance);

    return MagicCastChance.getFinalValue();
}

int Person::recalculateChanceOfUsingCombatTechnique()
{
    int chanceOfUsingCombatTechnique = floor(0.2 * Agility.getFinalValue()) + 20;
    ChanceOfUsingCombatTechnique.setValue(chanceOfUsingCombatTechnique);

    return ChanceOfUsingCombatTechnique.getFinalValue();
}

int Person::recalculateMoveRange()
{
    int moveRange = floor(0.75 * Agility.getFinalValue()) + floor(0.5 * Strength.getFinalValue()) + BodyType.getFinalValue();
    MoveRange.setValue(moveRange);

    return MoveRange.getFinalValue();
}

int Person::recalculateHealth()
{
    int health = Strength.getFinalValue() * 2 + BodyType.getFinalValue() * 10 + Will.getFinalValue() * 5 + Magic.getFinalValue();
    Health.setValue(health);

    return Health.getFinalValue();
}

int Person::recalculateEndurance()
{
    int endurance = Agility.getFinalValue() * 10 + BodyType.getFinalValue();
    Endurance.setValue(endurance);

    return Endurance.getFinalValue();
}

int Person::recalculateMana()
{
    int mana = Magic.getFinalValue() * 10 + Intelligence.getFinalValue() * 2 + Will.getFinalValue();
    Mana.setValue(mana);

    return Mana.getFinalValue();
}

//Перерасчёт количества родных чанков магической защиты
void Person::recalculateMagicDefense()
{
    int numberOfChunks = 0;
    //Требование для появления нового чанка магической защиты
    int requirementOfChunk = 5;
    int will = Will.getFinalValue();
    /*Общая сумма требований воли до получения ещё одного чанка. Служит для передачи
     *подсказке информации о том сколько ещё нужно воли до появления нового чанка*/
    int amountOfRequirements = requirementOfChunk;

    //Если воли достаточно для получения хотябы одного чанка
    if(will>=requirementOfChunk){
        /*Вычисляется сколько остаётся воли после заполнения первого чанка.
         *Единица 1 раз вычитается из требований чтобы последующий цикл каждый
         *раз толкался на одну дополнительную итерацию, заполняя количество
         *чанков, и главное, заполняя требования для получения следующего чанка.*/
        will-=requirementOfChunk-1;
        while(true){
            numberOfChunks++;
            //Требования экспоненциально растут
            requirementOfChunk*=1.2;
            /*Вычисляется общая сумма требований, а из-за толкания на дополнительную
             *итерацию эти требования всегда для уже последующего чанка, а не текущего*/
            amountOfRequirements+=requirementOfChunk;
            //Вычисляется сколько остаётся воли после заполнения нового чанка
            will-=requirementOfChunk;
            /*Меньше или равным нулю воля может оказаться только если
             *требования на появления ещё одного чанка не соблюдены*/
            if(will<=0){
                break;
            }
        }
    }

    //Прогрессбару магической защиты передаётся значение недостающей воли до появления ещё одного чанка
    willUntilNextChunk = amountOfRequirements - Will.getFinalValue();

    //Генерируется новый вектор чанков исходя из новых статов
    QVector<Chunk*> chunks;
    for(int i = 0; i<numberOfChunks; i++){
        int chunkValue = floor(Magic.getFinalValue() * 0.7 + BodyType.getFinalValue() * 0.3);
        chunks.append(new Chunk(chunkValue, 0));
    }

    magicDefense.setNativeChunks(chunks);
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

/*Слот полной переинициализации. Каждый раз когда операции с бонусами проваливаются
 *запрашивается их полная переинциализация для избежания последующих проблем.*/
void Person::fullReinitialization()
{
    qDebug()<<"!!!Полная переинициализация всех бонусов!!!";

    //!!!Здесь должны быть запросы на пересчёты инвенторя и активных эффектов!!!

    recalculateStats();

    emit FullReinitializationRequest();
}

bool Person::saveAllStats(bool createBackup)
{
    if(createBackup){
        this->createBackup();
    }

    bool successSaveStrength = saveStrength(true, true, false);
    bool successSaveAgility = saveAgility(true, true, false);
    bool successSaveIntelligence = saveIntelligence(true, true, false);
    bool successSaveMagic = saveMagic(true, true, false);
    bool successSaveBodyType = saveBodyType(true, true, false);
    bool successSaveWill = saveWill(true, true, false);

    bool successSaveMagicDamage = saveMagicDamage(false);
    bool successSaveResistPhysicalDamage = saveResistPhysicalDamage(false);
    bool successSaveResistMagicDamage = saveResistMagicDamage(false);
    bool successSaveResistPhysicalEffects = saveResistPhysicalEffects(false);
    bool successSaveResistMagicEffects = saveResistMagicEffects(false);
    bool successSaveStrengtheningPhysicalEffects = saveStrengtheningPhysicalEffects(false);
    bool successSaveStrengtheningMagicalEffects = saveStrengtheningMagicalEffects(false);
    bool successSaveMeleeAccuracy = saveMeleeAccuracy(false);
    bool successSaveRangedAccuracy = saveRangedAccuracy(false);
    bool successSaveMagicAccuracy = saveMagicAccuracy(false);
    bool successSaveEvasion = saveEvasion(false);
    bool successSaveStealth = saveStealth(false);
    bool successSaveAttentiveness = saveAttentiveness(false);
    bool successSaveLoadCapacity = saveLoadCapacity(false);
    bool successSaveInitiative = saveInitiative(false);
    bool successSaveMagicCastChance = saveMagicCastChance(false);
    bool successSaveChanceOfUsingCombatTechnique = saveChanceOfUsingCombatTechnique(false);
    bool successSaveMoveRange = saveMoveRange(false);
    bool successSaveHealth = saveHealth(false);
    bool successSaveEndurance = saveEndurance(false);
    bool successSaveMana = saveMana(false);
    bool succesSaveMagicDefense = saveMagicDefense(false);

    return successSaveStrength && successSaveAgility && successSaveIntelligence &&
            successSaveMagic && successSaveMagic && successSaveBodyType &&
            successSaveWill && successSaveMagicDamage && successSaveResistPhysicalDamage &&
            successSaveResistMagicDamage && successSaveResistPhysicalEffects &&
            successSaveResistMagicEffects && successSaveStrengtheningPhysicalEffects &&
            successSaveStrengtheningMagicalEffects && successSaveMeleeAccuracy &&
            successSaveRangedAccuracy && successSaveMagicAccuracy && successSaveEvasion &&
            successSaveStealth && successSaveAttentiveness && successSaveLoadCapacity &&
            successSaveInitiative && successSaveMagicCastChance && successSaveChanceOfUsingCombatTechnique &&
            successSaveMoveRange && successSaveHealth && successSaveEndurance && successSaveMana && succesSaveMagicDefense;
}

bool Person::loadAllStats()
{
    bool successLoadStrength = loadStrength(true, true, false);
    bool successLoadAgility = loadAgility(true, true, false);
    bool successLoadIntelligence = loadIntelligence(true, true, false);
    bool successLoadMagic = loadMagic(true, true, false);
    bool successLoadBodyType = loadBodyType(true, true, false);
    bool successLoadWill = loadWill(true, true, false);

    bool successLoadMagicDamage = loadMagicDamage();
    bool successLoadResistPhysicalDamage = loadResistPhysicalDamage();
    bool successLoadResistMagicDamage = loadResistMagicDamage();
    bool successLoadResistPhysicalEffects = loadResistPhysicalEffects();
    bool successLoadResistMagicEffects = loadResistMagicEffects();
    bool successLoadStrengtheningPhysicalEffects = loadStrengtheningPhysicalEffects();
    bool successLoadStrengtheningMagicalEffects = loadStrengtheningMagicalEffects();
    bool successLoadMeleeAccuracy = loadMeleeAccuracy();
    bool successLoadRangedAccuracy = loadRangedAccuracy();
    bool successLoadMagicAccuracy = loadMagicAccuracy();
    bool successLoadEvasion = loadEvasion();
    bool successLoadStealth = loadStealth();
    bool successLoadAttentiveness = loadAttentiveness();
    bool successLoadLoadCapacity = loadLoadCapacity();
    bool successLoadInitiative = loadInitiative();
    bool successLoadMagicCastChance = loadMagicCastChance();
    bool successLoadChanceOfUsingCombatTechnique = loadChanceOfUsingCombatTechnique();
    bool successLoadMoveRange = loadMoveRange();
    bool successLoadHealth = loadHealth();
    bool successLoadEndurance = loadEndurance();
    bool successLoadMana = loadMana();
    bool successLoadMagicDefense = loadMagicDefense();

    recalculateStats();
    emit FullReinitializationRequest();

    return successLoadStrength && successLoadAgility && successLoadIntelligence &&
            successLoadMagic && successLoadMagic && successLoadBodyType &&
            successLoadWill && successLoadMagicDamage && successLoadResistPhysicalDamage &&
            successLoadResistMagicDamage && successLoadResistPhysicalEffects &&
            successLoadResistMagicEffects && successLoadStrengtheningPhysicalEffects &&
            successLoadStrengtheningMagicalEffects && successLoadMeleeAccuracy &&
            successLoadRangedAccuracy && successLoadMagicAccuracy && successLoadEvasion &&
            successLoadStealth && successLoadAttentiveness && successLoadLoadCapacity &&
            successLoadInitiative && successLoadMagicCastChance && successLoadChanceOfUsingCombatTechnique &&
            successLoadMoveRange && successLoadHealth && successLoadEndurance && successLoadMana && successLoadMagicDefense;
}

/*Ниже идут методы сохранения и загрузки ко всем статам. Почти все из них вызывают универсальные методы
 *сохранения и загрузки, и только магическая защита имеет свои уникальные функции. У первичных навыков
 *можно выбрать сохранять/загружать ли значения и бонусы, а также у загрузки - посылать ли сигнал,
 *говорящий о том, что стат был изменён. У всех методов сохранения есть возможность выбрать сгенерирует
 *ли запрос бекап. У всех вторичных навыков не сохраняется значение, ведь оно просто генерируется заного
 *при любом обновлении первичных, и смысла хранить его нет. У них сохраняются только бонусы, а у навыков
 *имеющих прогресбар, сохраняется текущее значение прогресбара.*/
bool Person::saveStrength(bool saveValues, bool saveBonuses, bool createBackup)
{
    return saveStat("Strength", Strength.getValue(), Strength.getMaximum(), 0, Strength.getBonuses(), saveValues, false, saveBonuses, createBackup);
}
bool Person::loadStrength(bool loadValues, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Strength", Bonus::STRENGTH, Strength, loadValues, false, loadBonuses);
//    if(emittedChanged)
//        emit StrengthChanged();
    return success;
}

bool Person::saveAgility(bool saveValues, bool saveBonuses, bool createBackup)
{
    return saveStat("Agility", Agility.getValue(), Agility.getMaximum(), 0, Agility.getBonuses(), saveValues, false, saveBonuses, createBackup);
}
bool Person::loadAgility(bool loadValues, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Agility", Bonus::AGILITY, Agility, loadValues, false, loadBonuses);
//    if(emittedChanged)
//        emit AgilityChanged();
    return success;
}

bool Person::saveIntelligence(bool saveValues, bool saveBonuses, bool createBackup)
{
    return saveStat("Intelligence", Intelligence.getValue(), Intelligence.getMaximum(), 0, Intelligence.getBonuses(), saveValues, false, saveBonuses, createBackup);
}
bool Person::loadIntelligence(bool loadValues, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Intelligence", Bonus::INTELLIGENCE, Intelligence, loadValues, false, loadBonuses);
//    if(emittedChanged)
//        emit IntelligenceChanged();
    return success;
}

bool Person::saveMagic(bool saveValues, bool saveBonuses, bool createBackup)
{
    return saveStat("Magic", Magic.getValue(), Magic.getMaximum(), 0, Magic.getBonuses(), saveValues, false, saveBonuses, createBackup);
}
bool Person::loadMagic(bool loadValues, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Magic", Bonus::MAGIC, Magic, loadValues, false, loadBonuses);
//    if(emittedChanged)
//        emit MagicChanged();
    return success;
}

bool Person::saveBodyType(bool saveValues, bool saveBonuses, bool createBackup)
{
    return saveStat("BodyType", BodyType.getValue(), BodyType.getMaximum(), 0, BodyType.getBonuses(), saveValues, false, saveBonuses, createBackup);
}
bool Person::loadBodyType(bool loadValues, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("BodyType", Bonus::BODYTYPE, BodyType, loadValues, false, loadBonuses);
//    if(emittedChanged)
//        emit BodyTypeChanged();
    return success;
}

bool Person::saveWill(bool saveValues, bool saveBonuses, bool createBackup)
{
    return saveStat("Will", Will.getValue(), Will.getMaximum(), 0, Will.getBonuses(), saveValues, false, saveBonuses, createBackup);
}
bool Person::loadWill(bool loadValues, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Will", Bonus::WILL, Will, loadValues, false, loadBonuses);
//    if(emittedChanged)
//        emit WillChanged();
    return success;
}

bool Person::saveMagicDamage(bool createBackup)
{
    return saveStat("MagicDamage", MagicDamage.getValue(), MagicDamage.getMaximum(), 0, MagicDamage.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMagicDamage()
{
    return loadStat("MagicDamage", Bonus::MAGIC_DAMAGE, MagicDamage, false, false, true);
}

bool Person::saveResistPhysicalDamage(bool createBackup)
{
    return saveStat("ResistPhysicalDamage", ResistPhysicalDamage.getValue(), ResistPhysicalDamage.getMaximum(),
                    0, ResistPhysicalDamage.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistPhysicalDamage()
{
    return loadStat("ResistPhysicalDamage", Bonus::RESIST_PHYSICAL_DAMAGE, ResistPhysicalDamage, false, false, true);
}

bool Person::saveResistMagicDamage(bool createBackup)
{
    return saveStat("ResistMagicDamage", ResistMagicDamage.getValue(), ResistMagicDamage.getMaximum(),
                    0, ResistMagicDamage.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistMagicDamage()
{
    return loadStat("ResistMagicDamage", Bonus::RESIST_MAGIC_DAMAGE, ResistMagicDamage, false, false, true);
}

bool Person::saveResistPhysicalEffects(bool createBackup)
{
    return saveStat("ResistPhysicalEffects", ResistPhysicalEffects.getValue(), ResistPhysicalEffects.getMaximum(),
                    0, ResistPhysicalEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistPhysicalEffects()
{
    return loadStat("ResistPhysicalEffects", Bonus::RESIST_PHYSICAL_EFFECTS, ResistPhysicalEffects, false, false, true);
}

bool Person::saveResistMagicEffects(bool createBackup)
{
    return saveStat("ResistMagicEffects", ResistMagicEffects.getValue(), ResistMagicEffects.getMaximum(), 0, ResistMagicEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistMagicEffects()
{
    return loadStat("ResistMagicEffects", Bonus::RESIST_MAGIC_EFFECTS, ResistMagicEffects, false, false, true);
}

bool Person::saveStrengtheningPhysicalEffects(bool createBackup)
{
    return saveStat("StrengtheningPhysicalEffects", StrengtheningPhysicalEffects.getValue(), StrengtheningPhysicalEffects.getMaximum(),
                    0, StrengtheningPhysicalEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadStrengtheningPhysicalEffects()
{
    return loadStat("StrengtheningPhysicalEffects", Bonus::STRENGTHENING_PHYSICAL_EFFECTS, StrengtheningPhysicalEffects, false, false, true);
}

bool Person::saveStrengtheningMagicalEffects(bool createBackup)
{
    return saveStat("StrengtheningMagicalEffects", StrengtheningMagicalEffects.getValue(), StrengtheningMagicalEffects.getMaximum(),
                    0, StrengtheningMagicalEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadStrengtheningMagicalEffects()
{
    return loadStat("StrengtheningMagicalEffects", Bonus::STRENGTHENING_MAGICAL_EFFECTS, StrengtheningMagicalEffects, false, false, true);
}

bool Person::saveMeleeAccuracy(bool createBackup)
{
    return saveStat("MeleeAccuracy", MeleeAccuracy.getValue(), MeleeAccuracy.getMaximum(), 0, MeleeAccuracy.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMeleeAccuracy()
{
    return loadStat("MeleeAccuracy", Bonus::MELEE_ACCURACY, MeleeAccuracy, false, false, true);
}

bool Person::saveRangedAccuracy(bool createBackup)
{
    return saveStat("RangedAccuracy", RangedAccuracy.getValue(), RangedAccuracy.getMaximum(),
                    0, RangedAccuracy.getBonuses(), false, false, true, createBackup);
}
bool Person::loadRangedAccuracy()
{
    return loadStat("RangedAccuracy", Bonus::RANGED_ACCURACY, RangedAccuracy, false, false, true);
}

bool Person::saveMagicAccuracy(bool createBackup)
{
    return saveStat("MagicAccuracy", MagicAccuracy.getValue(), MagicAccuracy.getMaximum(),
                    0, MagicAccuracy.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMagicAccuracy()
{
    return loadStat("MagicAccuracy", Bonus::MAGIC_ACCURACY, MagicAccuracy, false, false, true);
}

bool Person::saveEvasion(bool createBackup)
{
    return saveStat("Evasion", Evasion.getValue(), Evasion.getMaximum(),
                    0, Evasion.getBonuses(), false, false, true, createBackup);
}
bool Person::loadEvasion()
{
    return loadStat("Evasion", Bonus::EVASION, Evasion, false, false, true);
}

bool Person::saveStealth(bool createBackup)
{
    return saveStat("Stealth", Stealth.getValue(), Stealth.getMaximum(),
                    0, Stealth.getBonuses(), false, false, true, createBackup);
}
bool Person::loadStealth()
{
    return loadStat("Stealth", Bonus::STEALTH, Stealth, false, false, true);
}

bool Person::saveAttentiveness(bool createBackup)
{
    return saveStat("Attentiveness", Attentiveness.getValue(), Attentiveness.getMaximum(),
                    0, Attentiveness.getBonuses(), false, false, true, createBackup);
}
bool Person::loadAttentiveness()
{
    return loadStat("Attentiveness", Bonus::ATTENTIVENESS, Attentiveness, false, false, true);
}

bool Person::saveLoadCapacity(bool createBackup)
{
    return saveStat("LoadCapacity", LoadCapacity.getValue(), LoadCapacity.getMaximum(),
                    0, LoadCapacity.getBonuses(), false, false, true, createBackup);
}
bool Person::loadLoadCapacity()
{
    return loadStat("LoadCapacity", Bonus::LOAD_CAPACITY, LoadCapacity, false, false, true);
}

bool Person::saveInitiative(bool createBackup)
{
    return saveStat("Initiative", Initiative.getValue(), Initiative.getMaximum(),
                    0, Initiative.getBonuses(), false, false, true, createBackup);
}
bool Person::loadInitiative()
{
    return loadStat("Initiative", Bonus::INITIATIVE, Initiative, false, false, true);
}

bool Person::saveMagicCastChance(bool createBackup)
{
    return saveStat("MagicCastChance", MagicCastChance.getValue(), MagicCastChance.getMaximum(),
                    0, MagicCastChance.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMagicCastChance()
{
    return loadStat("MagicCastChance", Bonus::MAGIC_CAST_CHANCE, MagicCastChance, false, false, true);
}

bool Person::saveChanceOfUsingCombatTechnique(bool createBackup)
{
    return saveStat("ChanceOfUsingCombatTechnique", ChanceOfUsingCombatTechnique.getValue(), ChanceOfUsingCombatTechnique.getMaximum(),
                    0, ChanceOfUsingCombatTechnique.getBonuses(), false, false, true, createBackup);
}
bool Person::loadChanceOfUsingCombatTechnique()
{
    return loadStat("ChanceOfUsingCombatTechnique", Bonus::CHANCE_OF_USING_COMBAT_TECHNIQUE, ChanceOfUsingCombatTechnique, false, false, true);
}

bool Person::saveMoveRange(bool createBackup)
{
    return saveStat("MoveRange", MoveRange.getValue(), MoveRange.getMaximum(), 0, MoveRange.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMoveRange()
{
    return loadStat("MoveRange", Bonus::MOVE_RANGE, MoveRange, false, false, true);
}

bool Person::saveHealth(bool createBackup)
{
    return saveStat("Health", Health.getValue(), Health.getMaximum(), Health.getProgressBarCurrentValue(), Health.getBonuses(), false, true, true, createBackup);
}
bool Person::loadHealth()
{
    return loadStat("Health", Bonus::HEALTH, Health, false, true, true);
}

bool Person::saveEndurance(bool createBackup)
{
    return saveStat("Endurance", Endurance.getValue(), Endurance.getMaximum(), Endurance.getProgressBarCurrentValue(), Endurance.getBonuses(), false, true, true, createBackup);
}
bool Person::loadEndurance()
{
    return loadStat("Endurance", Bonus::ENDURANCE, Endurance, false, true, true);
}

bool Person::saveMana(bool createBackup)
{
    return saveStat("Mana", Mana.getValue(), Mana.getMaximum(), Mana.getProgressBarCurrentValue(), Mana.getBonuses(), false, true, true, createBackup);
}
bool Person::loadMana()
{
    return loadStat("Mana", Bonus::MANA, Mana, false, true, true);
}

bool Person::saveMagicDefense(bool createBackup)
{
    //Сначала сохраняется текущее значение прогрессбара для магической защиты
    bool succesSaveValue = saveStat("MagicDefense", 0, 0, magicDefense.getValue(), QVector<Bonus*>{}, false, true, false, false);
    //Скобки нужны чтобы к моменту закрытия базы данных QSqlDatabase database вышел из своей зоны видимости и удалился
    {
        //Создаётся директория, если её небыло
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName))
            dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName);

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(createBackup)
            this->createBackup();

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Ошибка открытия файла\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite не удалось открыть.\n\n";
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

        /*Создаётся таблица бонусов магической защиты. У каждого такого бонуса в отличии от обычного бонуса
         *стата есть уникальный id, так как у магической защиты один бонус может вносить более одного изменения,
         *а именно добавлять неопределённое количество новых бонусных чанков, и надо точно знать какой бонус
         *добавил какие чанки.*/
        QSqlQuery query(database);
        if(!query.exec("CREATE TABLE IF NOT EXISTS MagicDefenseBonuses("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "value INTEGER NOT NULL DEFAULT 0, "
                       "static_position INTEGER NOT NULL DEFAULT 0, "
                       "dynamic_position INTEGER NOT NULL DEFAULT 0, "
                       "is_percentage INTEGER NOT NULL DEFAULT 0, "
                       "is_dynamic INTEGER NOT NULL DEFAULT 0, "
                       "is_bonus_chunk INTEGER NOT NULL DEFAULT 0, "
                       "bonus_name TEXT NOT NULL, "
                       "duration_days INTEGER NOT NULL DEFAULT 0, "
                       "duration_hours INTEGER NOT NULL DEFAULT 0, "
                       "duration_minutes INTEGER NOT NULL DEFAULT 0, "
                       "duration_seconds INTEGER NOT NULL DEFAULT 0, "
                       "CONSTRAINT static_position_chek CHECK (static_position >= 0), "
                       "CONSTRAINT dynamic_position_chek CHECK (dynamic_position >= 0 AND dynamic_position <= 3), "
                       "CONSTRAINT is_percentage_bool_chek CHECK (is_percentage >= 0 AND is_percentage <= 1), "
                       "CONSTRAINT is_dynamic_bool_chek CHECK (is_dynamic >= 0 AND is_dynamic <= 1), "
                       "CONSTRAINT is_bonus_chunk_bool_chek CHECK (is_bonus_chunk >= 0 AND is_bonus_chunk <= 1), "
                       "CONSTRAINT stat_name_chek CHECK (bonus_name != ''), "
                       "CONSTRAINT duration_days_chek CHECK (duration_days >= -1), "
                       "CONSTRAINT duration_hours_chek CHECK (duration_hours >= -1), "
                       "CONSTRAINT duration_minutes_chek CHECK (duration_minutes >= -1), "
                       "CONSTRAINT duration_seconds_chek CHECK (duration_seconds >= -1));"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось создать таблицу\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        //Сброс автоинкремента id бонусов магической защиты. Всё-равно они сейчас будут полностью перезаписаны, и нет смысла копиться этому инкременту
        if(!query.exec("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'MagicDefenseBonuses';")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось обновить данные в таблице\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Не удалось обновить данные в таблице базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        //Полная очистка всех бонусов магической защиты. В старых значениях уже нет нужды, сейчас они заменятся атуальными
        if(!query.exec("DELETE FROM MagicDefenseBonuses;")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось удалить данные из таблицы\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Не удалось удалить данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        //Создание таблицы бонусных чанков. Каждый чанк этой таблицы знает, путём передачи id, какой бонус породил его
        if(!query.exec("CREATE TABLE IF NOT EXISTS MagicDefenseBonusChunks("
                       "bonus_id INTEGER NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0);"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось создать таблицу\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        //Полная очистка всех бонусных чанков магической защиты. В старых значениях уже нет нужды, сейчас они заменятся атуальными
        if(!query.exec("DELETE FROM MagicDefenseBonusChunks;")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось удалить данные из таблицы\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Не удалось удалить данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        for(MagicDefenseBonus* bonus : magicDefense.getBonuses()){
            if(!query.exec("INSERT INTO MagicDefenseBonuses (value, static_position, dynamic_position, is_percentage, is_dynamic, is_bonus_chunk, bonus_name, "
                           "duration_days, duration_hours, duration_minutes, duration_seconds) VALUES (" + QString::number(bonus->getValue()) + ", " +
                           QString::number(bonus->staticPosition) + ", " + QString::number(bonus->dynamicPosition) + ", " + QString::number(bonus->isPercentage) +
                           ", " + QString::number(bonus->isDynamic) + ", " + QString::number(bonus->isBonusChunk) + ", '" + bonus->bonusName + "', " +
                           QString::number(bonus->getDurationDays()) + ", " + QString::number(bonus->getDurationHours()) + ", " + QString::number(bonus->getDurationMinutes())
                           + ", " + QString::number(bonus->getDurationSeconds()) + ");")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось записать данные в таблицу\n"
                        "Person выдал ошибку в методе saveMagicDefense.\n"
                        "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }            

            if(bonus->isBonusChunk){
                for(int i : bonus->getBonusChunksMaxVales()){
                    //Считывание id текущего бонуса
                    if( !query.exec("SELECT seq FROM sqlite_sequence WHERE name IS 'MagicDefenseBonuses';")) {
                        //Вывод предупреждения в консоль и файл
                        QDate cd = QDate::currentDate();
                        QTime ct = QTime::currentTime();

                        QString error =
                                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                                "\nОШИБКА: Не удалось считать данные из таблицы\n"
                                "Person выдал ошибку в методе loadStat.\n"
                                "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                        database.close();
                        return false;
                    }

                    query.first();
                    int id = query.value(0).toInt();

                    //Если бонус на чанки, то значения всех новых чанков забиваются в таблицу бонусных чанков с указанием id бонуса породившего их
                    if(!query.exec("INSERT INTO MagicDefenseBonusChunks (bonus_id, value) VALUES (" +  QString::number(id) + ", " + QString::number(i) + ");")){
                        //Вывод предупреждения в консоль и файл
                        QDate cd = QDate::currentDate();
                        QTime ct = QTime::currentTime();

                        QString error =
                                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                                "\nОШИБКА: Не удалось записать данные в таблицу\n"
                                "Person выдал ошибку в методе saveMagicDefense.\n"
                                "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                        database.close();
                        return false;
                    }
                }
            }
        }
        database.close();
    }
    QSqlDatabase::removeDatabase("save");

    return succesSaveValue;
}
bool Person::loadMagicDefense()
{
    //Скобки нужны чтобы к моменту закрытия базы данных QSqlDatabase database вышел из своей зоны видимости и удалился
    {
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadMagicDefense.\n"
            "Директории Game Saves/"+Global::DungeonName+"/Heroes/"+personName + " не существует.\n\n";
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

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadMagicDefense.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite не удалось открыть.\n\n";
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

        QSqlQuery query(database);
        if( !query.exec( "SELECT * FROM MagicDefenseBonuses;")) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось считать данные из таблицы\n"
                    "Person выдал ошибку в методе loadMagicDefense.\n"
                    "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        //Удаление всех бонусов магической защиты, так как они сейчас будут переинициализированы данными из БД
        magicDefense.removeAllBonuses();
        while (query.next()){
            //Проверка является ли бонус бонусом на чанки
            if(query.value(6).toBool()){
                QSqlQuery chunksQuery(database);
                //Поиск всех бонусных чанков, созданых бонусом с текущим id
                if( !chunksQuery.exec( "SELECT value FROM MagicDefenseBonusChunks WHERE bonus_id IS " + query.value(0).toString() + ";")) {
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nОШИБКА: Не удалось считать данные из таблицы\n"
                            "Person выдал ошибку в методе loadMagicDefense.\n"
                            "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                    database.close();
                    return false;
                }

                //Создание и передача бонуса на чанки
                QVector<int> bonusChunksMaxVales;
                while(chunksQuery.next()){
                    bonusChunksMaxVales.append(chunksQuery.value(0).toInt());
                }
                magicDefense.addBonus(new MagicDefenseBonus(bonusChunksMaxVales, query.value(7).toString(), query.value(8).toInt(),
                                                            query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));

            //Проверка является ли бонус динамическим
            }else if(query.value(5).toBool())
                magicDefense.addBonus(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition(query.value(3).toInt()),
                                                            query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString(),
                                                            query.value(8).toInt(), query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));
            //Иначе он статический
            else
                magicDefense.addBonus(new MagicDefenseBonus(query.value(2).toInt(), query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString(),
                                                            query.value(8).toInt(), query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));
        }

        //Считывание из БД текущего значения прогрессбара магической защиты
        if( !query.exec( "SELECT progress_bar_current_value FROM Stats WHERE stat_name IS 'MagicDefense';")) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось считать данные из таблицы\n"
                    "Person выдал ошибку в методе loadStat.\n"
                    "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }


        //Пересчёт вектора чанков магической защиты
        recalculateMagicDefense();
        //Обнуление текущего значения прогрессбара, так как ему будет передано значение из БД
        magicDefense.subtractValue(magicDefense.getValue());

        query.first();
        //Передача текущего значения прогрессбара
        magicDefense.addValue(query.value(0).toInt());

        database.close();
    }

    QSqlDatabase::removeDatabase("save");
    return true;
}

/*Универсальный метод сохранения стата. В нём представлены все возможные поля статов. Если у
 *стата, который необходимо сохранить некоторых полей нет, то в них передаётся просто 0 и
 *указывается false в переменных, говорящих что сохранять. В поле statName следует передать
 *имя стата так, как его переменная названа в этом классе.*/
bool Person::saveStat(QString statName, int value, int maximum, int progressBarCurrentValue, QVector<Bonus *> bonuses,
                      bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    {
        //Создаётся директория, если её небыло
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName))
            dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName);

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(createBackup)
            this->createBackup();

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе saveStat.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite не удалось открыть.\n\n";
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

        //Создание таблицы стата
        QSqlQuery query(database);
        if(!query.exec("CREATE TABLE IF NOT EXISTS Stats("
                       "stat_name TEXT NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0,"
                       "maximum INTEGER NOT NULL DEFAULT 0,"
                       "progress_bar_current_value INTEGER NOT NULL DEFAULT 0, "
                       "CONSTRAINT value_chek CHECK ((value >= 0) AND (value <= maximum)), "
                       "CONSTRAINT progress_bar_current_value_chek CHECK ((value >= -value) AND (value <= value)), "
                       "CONSTRAINT stat PRIMARY KEY (stat_name), "
                       "CONSTRAINT stat_name_chek CHECK (stat_name !=''));"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось создать таблицу\n"
            "Person выдал ошибку в методе saveStat.\n"
            "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        //Создание таблицы бонусов стата
        if(!query.exec("CREATE TABLE IF NOT EXISTS Bonuses("
                       "stat_name TEXT NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0, "
                       "is_percentage INTEGER NOT NULL DEFAULT 0, "
                       "bonus_name TEXT NOT NULL,"
                       "duration_days INTEGER NOT NULL DEFAULT 0, "
                       "duration_hours INTEGER NOT NULL DEFAULT 0, "
                       "duration_minutes INTEGER NOT NULL DEFAULT 0, "
                       "duration_seconds INTEGER NOT NULL DEFAULT 0, "
                       "CONSTRAINT bool_chek CHECK (is_percentage >= 0 AND is_percentage <= 1), "
                       "CONSTRAINT stat_name_chek CHECK (stat_name != ''), "
                       "CONSTRAINT bonus_name_chek CHECK (bonus_name != ''), "
                       "CONSTRAINT duration_days_chek CHECK (duration_days >= -1), "
                       "CONSTRAINT duration_hours_chek CHECK (duration_hours >= -1), "
                       "CONSTRAINT duration_minutes_chek CHECK (duration_minutes >= -1), "
                       "CONSTRAINT duration_seconds_chek CHECK (duration_seconds >= -1));"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось создать таблицу\n"
            "Person выдал ошибку в методе saveStat.\n"
            "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            database.close();
            return false;
        }

        if(saveValues){
            if(!query.exec("REPLACE INTO Stats (stat_name, value, maximum) VALUES ('" + statName + "', "
                           + QString::number(value) + ", " +  QString::number(maximum) +");")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось записать данные в таблицу\n"
                        "Person выдал ошибку в методе saveStat.\n"
                        "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }
        }else if(saveProgressBarCurrentValue)
            if(!query.exec("REPLACE INTO Stats (stat_name, progress_bar_current_value) VALUES ('" + statName + "', " + QString::number(progressBarCurrentValue) + ");")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось записать данные в таблицу\n"
                        "Person выдал ошибку в методе saveStat.\n"
                        "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }

        if(saveBonuses){
            if(!query.exec("DELETE FROM Bonuses WHERE stat_name = '" + statName + "';")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось удалить данные из таблицы\n"
                        "Person выдал ошибку в методе saveStat.\n"
                        "Не удалось удалить данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }

            for(Bonus* bonus : bonuses){
                if(!query.exec("INSERT INTO Bonuses (stat_name, value, is_percentage, bonus_name, duration_days, "
                               "duration_hours, duration_minutes, duration_seconds) VALUES ('" + statName + "', " +
                               QString::number(bonus->getValue())+ ", " + QString::number(bonus->isPercentage) +
                               ", '" + bonus->bonusName + "', " + QString::number(bonus->getDurationDays()) + ", " +
                               QString::number(bonus->getDurationHours()) + ", " + QString::number(bonus->getDurationMinutes())
                               + ", " + QString::number(bonus->getDurationSeconds()) + ");")){

                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nОШИБКА: Не удалось записать данные в таблицу\n"
                            "Person выдал ошибку в методе saveStat.\n"
                            "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                    database.close();
                    return false;
                }
            }
        }

        database.close();
    }
    QSqlDatabase::removeDatabase("save");

    return true;
}

/*Универсальный метод загрузки стата. В нём представлены все возможные варианты того, что у
 *стата можно загрузить. Если у стата, который необходимо загрузить некоторых полей нет, то
 *указвается false в переменных, говорящих что загружать. В поле statName следует передать
 *имя стата так, как его переменная названа в этом классе. В перемннею statIndex следует
 *передать соответствующее стату значение enum'а StatName из Bonus*/
bool Person::loadStat(QString statName, Bonus::StatName statIndex, Stat &stat, bool loadValue, bool loadProgressBarCurrentValue, bool loadBonuses)
{
    {
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadStat.\n"
            "Директории Game Saves/"+Global::DungeonName+"/Heroes/"+personName + " не существует.\n\n";
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

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadStat.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite не удалось открыть.\n\n";
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

        QSqlQuery query(database);
        if(loadValue){
            if( !query.exec( "SELECT value FROM Stats WHERE stat_name IS '" + statName + "';")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "Person выдал ошибку в методе loadStat.\n"
                        "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }

            query.first();
            stat.setValue(query.value(0).toInt());

            query.clear();
        }

        if(loadProgressBarCurrentValue){
            if( !query.exec( "SELECT progress_bar_current_value FROM Stats WHERE stat_name IS '" + statName + "';")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "Person выдал ошибку в методе loadStat.\n"
                        "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }

            query.first();
            stat.setProgressBarCurrentValue(query.value(0).toInt());

            query.clear();
        }

        if(loadBonuses){
            if( !query.exec( "SELECT * FROM Bonuses WHERE stat_name = '" + statName + "';")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "Person выдал ошибку в методе loadStat.\n"
                        "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

                database.close();
                return false;
            }

            stat.removeAllBonuses();
            while (query.next())
                stat.addBonus(new Bonus(statIndex, query.value(1).toInt(), query.value(2).toBool(), query.value(3).toString(),
                                        query.value(4).toInt(), query.value(5).toInt(), query.value(6).toInt(), query.value(7).toInt()));
        }

        database.close();
    }

    QSqlDatabase::removeDatabase("save");
    return true;
}

//Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
void Person::createBackup()
{
    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups"))
        dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups");
    dir = QDir("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups");

    //Из директории берутся файлы и сортируются по дате изменения
    QStringList files = dir.entryList(QDir::Files, QDir::Time);

    //В папке может храниться только такое число бекапов, какое узазано в Global::numberOfBackups. Новые бекапы вытесняют старые.
    for (int i = Global::numberOfBackups - 1; i < files.size(); i++)
    {
        dir.remove(files.at(i));
    }

    QDateTime dt = QDateTime::currentDateTime();

    //Создаётся новый бекап с указанием даты и времени создания
    QFile::copy("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite",
                "Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups/save "
                + dt.toString("dd-MM-yyyy hh.mm.ss") + ".sqlite");
}

QString Person::getPersonName() const
{
    return personName;
}

void Person::setPersonName(const QString &newPersonName)
{
    personName = newPersonName;
}
