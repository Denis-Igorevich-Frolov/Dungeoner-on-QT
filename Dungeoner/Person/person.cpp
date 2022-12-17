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
        emit StrengthChanged();
        break;
    case Bonus::AGILITY:
        Agility.addBonus(bonus);
        emit AgilityChanged();
        break;
    case Bonus::INTELLIGENCE:
        Intelligence.addBonus(bonus);
        emit IntelligenceChanged();
        break;
    case Bonus::MAGIC:
        Magic.addBonus(bonus);
        emit MagicChanged();
        break;
    case Bonus::BODYTYPE:
        BodyType.addBonus(bonus);
        emit BodyTypeChanged();
        break;
    case Bonus::WILL:
        Will.addBonus(bonus);
        emit WillChanged();
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
        emit StrengthChanged();
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::AGILITY:
        successful = Agility.removeBonus(bonus);
        emit AgilityChanged();
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::INTELLIGENCE:
        successful = Intelligence.removeBonus(bonus);
        emit IntelligenceChanged();
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::MAGIC:
        successful = Magic.removeBonus(bonus);
        emit MagicChanged();
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::BODYTYPE:
        successful = BodyType.removeBonus(bonus);
        emit BodyTypeChanged();
        if (!successful)
            fullReinitialization();
        return successful;
    case Bonus::WILL:
        successful = Will.removeBonus(bonus);
        emit WillChanged();
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
    int magicDamage =
    floor(1.5 * Magic.getFinalValue()) + floor(1.5 * Intelligence.getFinalValue()) + floor(0.5 * Will.getFinalValue());
    MagicDamage.setValue(magicDamage);

    int resistPhysicalDamage = floor(1.5 * Will.getFinalValue()) + floor(0.5 * Magic.getFinalValue()) + BodyType.getFinalValue();
    ResistPhysicalDamage.setValue(resistPhysicalDamage);

    int resistMagicDamage = floor(1.5 * Will.getFinalValue()) + floor(0.5 * BodyType.getFinalValue()) + Magic.getFinalValue();
    ResistMagicDamage.setValue(resistMagicDamage);

    int resistPhysicalEffects = floor(0.1 * Will.getFinalValue()) + 10;
    ResistPhysicalEffects.setValue(resistPhysicalEffects);

    int resistMagicEffects = floor(0.1 * Will.getFinalValue()) + floor(0.1 * Magic.getFinalValue()) + 5;
    ResistMagicEffects.setValue(resistMagicEffects);

    int strengtheningPhysicalEffects = floor(0.1 * Strength.getFinalValue());
    StrengtheningPhysicalEffects.setValue(strengtheningPhysicalEffects);

    int strengtheningMagicalEffects = floor(0.1 * Intelligence.getFinalValue());
    StrengtheningMagicalEffects.setValue(strengtheningMagicalEffects);

    int meleeAccuracy = floor(0.1 * Agility.getFinalValue()) + 20;
    MeleeAccuracy.setValue(meleeAccuracy);

    int rangedAccuracy = floor(0.1 * Agility.getFinalValue()) + 15;
    RangedAccuracy.setValue(rangedAccuracy);

    int magicAccuracy = floor(0.1 * Intelligence.getFinalValue()) + 15;
    MagicAccuracy.setValue(magicAccuracy);

    int evasion = floor(0.5 * Agility.getFinalValue()) + floor(0.1 * BodyType.getFinalValue());
    Evasion.setValue(evasion);

    int stealth = Intelligence.getFinalValue() + Agility.getFinalValue();
    Stealth.setValue(stealth);

    int attentiveness = Intelligence.getFinalValue() + Agility.getFinalValue() + Will.getFinalValue();
    Attentiveness.setValue(attentiveness);

    int loadCapacity = floor(0.5 * Strength.getFinalValue()) + floor(0.5 * BodyType.getFinalValue());
    LoadCapacity.setValue(loadCapacity);

    int initiative = floor(5 * Agility.getFinalValue()) + Intelligence.getFinalValue() + Will.getFinalValue();
    Initiative.setValue(initiative);

    int magicCastChance = floor(0.3 * Intelligence.getFinalValue()) + floor(0.2 * Magic.getFinalValue());
    MagicCastChance.setValue(magicCastChance);

    int chanceOfUsingCombatTechnique = floor(0.2 * Agility.getFinalValue()) + 20;
    ChanceOfUsingCombatTechnique.setValue(chanceOfUsingCombatTechnique);

    int moveRange = floor(0.75 * Agility.getFinalValue()) + floor(0.5 * Strength.getFinalValue()) + BodyType.getFinalValue();
    MoveRange.setValue(moveRange);

    int health = Strength.getFinalValue() * 2 + BodyType.getFinalValue() * 10 + Will.getFinalValue() * 5 + Magic.getFinalValue();
    Health.setValue(health);

    int endurance = Agility.getFinalValue() * 10 + BodyType.getFinalValue();
    Endurance.setValue(endurance);

    int mana = Magic.getFinalValue() * 10 + Intelligence.getFinalValue() * 2 + Will.getFinalValue();
    Mana.setValue(mana);

    recalculateMagicDefense();
}

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

    bool successSaveStrength = saveStrength(true, false, true, false);
    bool successSaveAgility = saveAgility(true, false, true, false);
    bool successSaveIntelligence = saveIntelligence(true, false, true, false);
    bool successSaveMagic = saveMagic(true, false, true, false);
    bool successSaveBodyType = saveBodyType(true, false, true, false);
    bool successSaveWill = saveWill(true, false, true, false);

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

bool Person::loadALLStats()
{
    bool successLoadStrength = loadStrength(true, false, true, false);
    bool successLoadAgility = loadAgility(true, false, true, false);
    bool successLoadIntelligence = loadIntelligence(true, false, true, false);
    bool successLoadMagic = loadMagic(true, false, true, false);
    bool successLoadBodyType = loadBodyType(true, false, true, false);
    bool successLoadWill = loadWill(true, false, true, false);

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

bool Person::saveStrength(bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    return saveStat("Strength", Strength.getValue(), Strength.getMaximum(), 0, Strength.getBonuses(), saveValues, saveProgressBarCurrentValue, saveBonuses, createBackup);
}
bool Person::loadStrength(bool loadValues, bool loadProgressBarCurrentValue, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Strength", Bonus::STRENGTH, Strength, loadValues, loadProgressBarCurrentValue, loadBonuses);
    if(emittedChanged)
        emit StrengthChanged();
    return success;
}

bool Person::saveAgility(bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    return saveStat("Agility", Agility.getValue(), Agility.getMaximum(), 0, Agility.getBonuses(), saveValues, saveProgressBarCurrentValue, saveBonuses, createBackup);
}
bool Person::loadAgility(bool loadValues, bool loadProgressBarCurrentValue, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Agility", Bonus::AGILITY, Agility, loadValues, loadProgressBarCurrentValue, loadBonuses);
    if(emittedChanged)
        emit AgilityChanged();
    return success;
}

bool Person::saveIntelligence(bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    return saveStat("Intelligence", Intelligence.getValue(), Intelligence.getMaximum(), 0, Intelligence.getBonuses(), saveValues, saveProgressBarCurrentValue, saveBonuses, createBackup);
}
bool Person::loadIntelligence(bool loadValues, bool loadProgressBarCurrentValue, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Intelligence", Bonus::INTELLIGENCE, Intelligence, loadValues, loadProgressBarCurrentValue, loadBonuses);
    if(emittedChanged)
        emit IntelligenceChanged();
    return success;
}

bool Person::saveMagic(bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    return saveStat("Magic", Magic.getValue(), Magic.getMaximum(), 0, Magic.getBonuses(), saveValues, saveProgressBarCurrentValue, saveBonuses, createBackup);
}
bool Person::loadMagic(bool loadValues, bool loadProgressBarCurrentValue, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Magic", Bonus::MAGIC, Magic, loadValues, loadProgressBarCurrentValue, loadBonuses);
    if(emittedChanged)
        emit MagicChanged();
    return success;
}

bool Person::saveBodyType(bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    return saveStat("BodyType", BodyType.getValue(), BodyType.getMaximum(), 0, BodyType.getBonuses(), saveValues, saveProgressBarCurrentValue, saveBonuses, createBackup);
}
bool Person::loadBodyType(bool loadValues, bool loadProgressBarCurrentValue, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("BodyType", Bonus::BODYTYPE, BodyType, loadValues, loadProgressBarCurrentValue, loadBonuses);
    if(emittedChanged)
        emit BodyTypeChanged();
    return success;
}

bool Person::saveWill(bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    return saveStat("Will", Will.getValue(), Will.getMaximum(), 0, Will.getBonuses(), saveValues, saveProgressBarCurrentValue, saveBonuses, createBackup);
}
bool Person::loadWill(bool loadValues, bool loadProgressBarCurrentValue, bool loadBonuses, bool emittedChanged)
{
    bool success = loadStat("Will", Bonus::WILL, Will, loadValues, loadProgressBarCurrentValue, loadBonuses);
    if(emittedChanged)
        emit WillChanged();
    return success;
}

bool Person::saveMagicDamage(bool createBackup)
{
    return saveStat("MagicDamage", MagicDamage.getValue(), MagicDamage.getMaximum(), 0, MagicDamage.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMagicDamage()
{
    bool success = loadStat("MagicDamage", Bonus::MAGIC_DAMAGE, MagicDamage, false, false, true);
    return success;
}

bool Person::saveResistPhysicalDamage(bool createBackup)
{
    return saveStat("ResistPhysicalDamage", ResistPhysicalDamage.getValue(), ResistPhysicalDamage.getMaximum(),
                    0, ResistPhysicalDamage.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistPhysicalDamage()
{
    bool success = loadStat("ResistPhysicalDamage", Bonus::RESIST_PHYSICAL_DAMAGE, ResistPhysicalDamage, false, false, true);
    return success;
}

bool Person::saveResistMagicDamage(bool createBackup)
{
    return saveStat("ResistMagicDamage", ResistMagicDamage.getValue(), ResistMagicDamage.getMaximum(),
                    0, ResistMagicDamage.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistMagicDamage()
{
    bool success = loadStat("ResistMagicDamage", Bonus::RESIST_MAGIC_DAMAGE, ResistMagicDamage, false, false, true);
    return success;
}

bool Person::saveResistPhysicalEffects(bool createBackup)
{
    return saveStat("ResistPhysicalEffects", ResistPhysicalEffects.getValue(), ResistPhysicalEffects.getMaximum(),
                    0, ResistPhysicalEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistPhysicalEffects()
{
    bool success = loadStat("ResistPhysicalEffects", Bonus::RESIST_PHYSICAL_EFFECTS, ResistPhysicalEffects, false, false, true);
    return success;
}

bool Person::saveResistMagicEffects(bool createBackup)
{
    return saveStat("ResistMagicEffects", ResistMagicEffects.getValue(), ResistMagicEffects.getMaximum(), 0, ResistMagicEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadResistMagicEffects()
{
    bool success = loadStat("ResistMagicEffects", Bonus::RESIST_MAGIC_EFFECTS, ResistMagicEffects, false, false, true);
    return success;
}

bool Person::saveStrengtheningPhysicalEffects(bool createBackup)
{
    return saveStat("StrengtheningPhysicalEffects", StrengtheningPhysicalEffects.getValue(), StrengtheningPhysicalEffects.getMaximum(),
                    0, StrengtheningPhysicalEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadStrengtheningPhysicalEffects()
{
    bool success = loadStat("StrengtheningPhysicalEffects", Bonus::STRENGTHENING_PHYSICAL_EFFECTS, StrengtheningPhysicalEffects, false, false, true);
    return success;
}

bool Person::saveStrengtheningMagicalEffects(bool createBackup)
{
    return saveStat("StrengtheningMagicalEffects", StrengtheningMagicalEffects.getValue(), StrengtheningMagicalEffects.getMaximum(),
                    0, StrengtheningMagicalEffects.getBonuses(), false, false, true, createBackup);
}
bool Person::loadStrengtheningMagicalEffects()
{
    bool success = loadStat("StrengtheningMagicalEffects", Bonus::STRENGTHENING_MAGICAL_EFFECTS, StrengtheningMagicalEffects, false, false, true);
    return success;
}

bool Person::saveMeleeAccuracy(bool createBackup)
{
    return saveStat("MeleeAccuracy", MeleeAccuracy.getValue(), MeleeAccuracy.getMaximum(), 0, MeleeAccuracy.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMeleeAccuracy()
{
    bool success = loadStat("MeleeAccuracy", Bonus::MELEE_ACCURACY, MeleeAccuracy, false, false, true);
    return success;
}

bool Person::saveRangedAccuracy(bool createBackup)
{
    return saveStat("RangedAccuracy", RangedAccuracy.getValue(), RangedAccuracy.getMaximum(),
                    0, RangedAccuracy.getBonuses(), false, false, true, createBackup);
}
bool Person::loadRangedAccuracy()
{
    bool success = loadStat("RangedAccuracy", Bonus::RANGED_ACCURACY, RangedAccuracy, false, false, true);
    return success;
}

bool Person::saveMagicAccuracy(bool createBackup)
{
    return saveStat("MagicAccuracy", MagicAccuracy.getValue(), MagicAccuracy.getMaximum(),
                    0, MagicAccuracy.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMagicAccuracy()
{
    bool success = loadStat("MagicAccuracy", Bonus::MAGIC_ACCURACY, MagicAccuracy, false, false, true);
    return success;
}

bool Person::saveEvasion(bool createBackup)
{
    return saveStat("Evasion", Evasion.getValue(), Evasion.getMaximum(),
                    0, Evasion.getBonuses(), false, false, true, createBackup);
}
bool Person::loadEvasion()
{
    bool success = loadStat("Evasion", Bonus::EVASION, Evasion, false, false, true);
    return success;
}

bool Person::saveStealth(bool createBackup)
{
    return saveStat("Stealth", Stealth.getValue(), Stealth.getMaximum(),
                    0, Stealth.getBonuses(), false, false, true, createBackup);
}
bool Person::loadStealth()
{
    bool success = loadStat("Stealth", Bonus::STEALTH, Stealth, false, false, true);
    return success;
}

bool Person::saveAttentiveness(bool createBackup)
{
    return saveStat("Attentiveness", Attentiveness.getValue(), Attentiveness.getMaximum(),
                    0, Attentiveness.getBonuses(), false, false, true, createBackup);
}
bool Person::loadAttentiveness()
{
    bool success = loadStat("Attentiveness", Bonus::ATTENTIVENESS, Attentiveness, false, false, true);
    return success;
}

bool Person::saveLoadCapacity(bool createBackup)
{
    return saveStat("LoadCapacity", LoadCapacity.getValue(), LoadCapacity.getMaximum(),
                    0, LoadCapacity.getBonuses(), false, false, true, createBackup);
}
bool Person::loadLoadCapacity()
{
    bool success = loadStat("LoadCapacity", Bonus::LOAD_CAPACITY, LoadCapacity, false, false, true);
    return success;
}

bool Person::saveInitiative(bool createBackup)
{
    return saveStat("Initiative", Initiative.getValue(), Initiative.getMaximum(),
                    0, Initiative.getBonuses(), false, false, true, createBackup);
}
bool Person::loadInitiative()
{
    bool success = loadStat("Initiative", Bonus::INITIATIVE, Initiative, false, false, true);
    return success;
}

bool Person::saveMagicCastChance(bool createBackup)
{
    return saveStat("MagicCastChance", MagicCastChance.getValue(), MagicCastChance.getMaximum(),
                    0, MagicCastChance.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMagicCastChance()
{
    bool success = loadStat("MagicCastChance", Bonus::MAGIC_CAST_CHANCE, MagicCastChance, false, false, true);
    return success;
}

bool Person::saveChanceOfUsingCombatTechnique(bool createBackup)
{
    return saveStat("ChanceOfUsingCombatTechnique", ChanceOfUsingCombatTechnique.getValue(), ChanceOfUsingCombatTechnique.getMaximum(),
                    0, ChanceOfUsingCombatTechnique.getBonuses(), false, false, true, createBackup);
}
bool Person::loadChanceOfUsingCombatTechnique()
{
    bool success = loadStat("ChanceOfUsingCombatTechnique", Bonus::CHANCE_OF_USING_COMBAT_TECHNIQUE, ChanceOfUsingCombatTechnique, false, false, true);
    return success;
}

bool Person::saveMoveRange(bool createBackup)
{
    return saveStat("MoveRange", MoveRange.getValue(), MoveRange.getMaximum(), 0, MoveRange.getBonuses(), false, false, true, createBackup);
}
bool Person::loadMoveRange()
{
    bool success = loadStat("MoveRange", Bonus::MOVE_RANGE, MoveRange, false, false, true);
    return success;
}

bool Person::saveHealth(bool createBackup)
{
    return saveStat("Health", Health.getValue(), Health.getMaximum(), Health.getProgressBarCurrentValue(), Health.getBonuses(), false, true, true, createBackup);
}
bool Person::loadHealth()
{
    bool success = loadStat("Health", Bonus::HEALTH, Health, false, true, true);
    return success;
}

bool Person::saveEndurance(bool createBackup)
{
    return saveStat("Endurance", Endurance.getValue(), Endurance.getMaximum(), Endurance.getProgressBarCurrentValue(), Endurance.getBonuses(), false, true, true, createBackup);
}
bool Person::loadEndurance()
{
    bool success = loadStat("Endurance", Bonus::ENDURANCE, Endurance, false, true, true);
    return success;
}

bool Person::saveMana(bool createBackup)
{
    return saveStat("Mana", Mana.getValue(), Mana.getMaximum(), Mana.getProgressBarCurrentValue(), Mana.getBonuses(), false, true, true, createBackup);
}
bool Person::loadMana()
{
    bool success = loadStat("Mana", Bonus::MANA, Mana, false, true, true);
    return success;
}

bool Person::saveMagicDefense(bool createBackup)
{
    bool succesSaveValue = saveStat("MagicDefense", 0, 0, magicDefense.getValue(), QVector<Bonus*>{}, false, true, false, false);
    {
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
                       "CONSTRAINT static_position_chek CHECK (static_position >= 0), "
                       "CONSTRAINT dynamic_position_chek CHECK (dynamic_position >= 0 AND dynamic_position <= 3), "
                       "CONSTRAINT is_percentage_bool_chek CHECK (is_percentage >= 0 AND is_percentage <= 1), "
                       "CONSTRAINT is_dynamic_bool_chek CHECK (is_dynamic >= 0 AND is_dynamic <= 1), "
                       "CONSTRAINT is_bonus_chunk_bool_chek CHECK (is_bonus_chunk >= 0 AND is_bonus_chunk <= 1), "
                       "CONSTRAINT stat_name_chek CHECK (bonus_name != ''));"
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
            if(!query.exec("INSERT INTO MagicDefenseBonuses (value, static_position, dynamic_position, is_percentage, is_dynamic, is_bonus_chunk, bonus_name) VALUES (" +
                           QString::number(bonus->getValue()) + ", " + QString::number(bonus->staticPosition) + ", " + QString::number(bonus->dynamicPosition) + ", " +
                           QString::number(bonus->isPercentage) + ", " + QString::number(bonus->isDynamic) + ", " + QString::number(bonus->isBonusChunk) + ", '" +
                           bonus->bonusName + "');")){

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

        magicDefense.removeAllBonuses();
        while (query.next()){
            if(query.value(6).toBool()){
                QSqlQuery chunksQuery(database);
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

                QVector<int> bonusChunksMaxVales;
                while(chunksQuery.next()){
                    bonusChunksMaxVales.append(chunksQuery.value(0).toInt());
                }
                magicDefense.addBonus(new MagicDefenseBonus(bonusChunksMaxVales, query.value(7).toString()));

            }else if(query.value(5).toBool())
                magicDefense.addBonus(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition(query.value(3).toInt()),
                                                            query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString()));
            else
                magicDefense.addBonus(new MagicDefenseBonus(query.value(2).toInt(), query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString()));
        }

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


        recalculateMagicDefense();
        magicDefense.subtractValue(magicDefense.getValue());

        query.first();
        magicDefense.addValue(query.value(0).toInt());

        database.close();
    }

    QSqlDatabase::removeDatabase("save");
    return true;
}

bool Person::saveStat(QString statName, int value, int maximum, int progressBarCurrentValue, QVector<Bonus *> bonuses,
                      bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup)
{
    {
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

        if(!query.exec("CREATE TABLE IF NOT EXISTS Bonuses("
                       "stat_name TEXT NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0, "
                       "is_percentage INTEGER NOT NULL DEFAULT 0, "
                       "bonus_name TEXT NOT NULL, "
                       "CONSTRAINT bool_chek CHECK (is_percentage >= 0 AND is_percentage <= 1), "
                       "CONSTRAINT stat_name_chek CHECK (stat_name != ''), "
                       "CONSTRAINT bonus_name_chek CHECK (bonus_name != ''));"
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
                if(!query.exec("INSERT INTO Bonuses (stat_name, value, is_percentage, bonus_name) VALUES ('" + statName + "', " +
                               QString::number(bonus->getValue())+ ", " + QString::number(bonus->isPercentage) + ", '" + bonus->bonusName + "');")){

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
                stat.addBonus(new Bonus(statIndex, query.value(1).toInt(), query.value(2).toBool(), query.value(3).toString()));
        }

        database.close();
    }

    QSqlDatabase::removeDatabase("save");
    return true;
}

void Person::createBackup()
{
    QDir dir;
    if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups"))
        dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups");
    dir = QDir("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups");

    QStringList files = dir.entryList(QDir::Files, QDir::Time);

    for (int i = Global::numberOfBackups - 1; i < files.size(); i++)
    {
        dir.remove(files.at(i));
    }

    QDateTime dt = QDateTime::currentDateTime();

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
