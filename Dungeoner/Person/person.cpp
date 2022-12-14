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

bool Person::saveStrength()
{
    {
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName))
            dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName);

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "stats");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе saveStrength.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite не удалось открыть.\n\n";
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
            "Person выдал ошибку в методе saveStrength.\n"
            "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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
            "Person выдал ошибку в методе saveStrength.\n"
            "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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

        if(!query.exec("REPLACE INTO Stats (stat_name, value, maximum) VALUES ('Strength', "
                       + QString::number(Strength.getValue()) + ", " +  QString::number(Strength.getMaximum()) +");")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось записать данные в таблицу\n"
            "Person выдал ошибку в методе saveStrength.\n"
            "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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

        if(!query.exec("DELETE FROM Bonuses;")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось удалить данные из таблицы\n"
            "Person выдал ошибку в методе saveStrength.\n"
            "Не удалось удалить данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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

        for(Bonus* bonus : Strength.getBonuses()){
            if(!query.exec("INSERT INTO Bonuses (stat_name, value, is_percentage, bonus_name) VALUES ('Strength', " +
                           QString::number(bonus->getValue())+ ", " + QString::number(bonus->isPercentage) + ", '" + bonus->bonusName + "');")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                "\nОШИБКА: Не удалось записать данные в таблицу\n"
                "Person выдал ошибку в методе saveStrength.\n"
                "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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

        database.close();
    }
    QSqlDatabase::removeDatabase("stats");

    return true;
}

bool Person::loadStrength()
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
            "Person выдал ошибку в методе loadStrength.\n"
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

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "stats");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadStrength.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite не удалось открыть.\n\n";
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
        if( !query.exec( "SELECT value FROM Stats WHERE stat_name = 'Strength';"
                         )) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось считать данные из таблицы\n"
            "Person выдал ошибку в методе loadStrength.\n"
            "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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
        Strength.setValue(query.value(0).toInt());

        query.clear();
        if( !query.exec( "SELECT * FROM Bonuses WHERE stat_name = 'Strength';"
                         )) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось считать данные из таблицы\n"
            "Person выдал ошибку в методе loadStrength.\n"
            "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/stats.sqlite\n\n";
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

        Strength.removeAllBonuses();
        while (query.next())
            Strength.addBonus(new Bonus(Bonus::STRENGTH, query.value(1).toInt(), query.value(2).toBool(), query.value(3).toString()));

        emit StrengthChanged();
        database.close();
    }

    QSqlDatabase::removeDatabase("stats");
    return true;
}

QString Person::getPersonName() const
{
    return personName;
}

void Person::setPersonName(const QString &newPersonName)
{
    personName = newPersonName;
}
