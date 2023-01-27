/**********************************************************************
 *Данный класс является структурой для всех статов кроме магической
 *защиты с реализацией геттеров и сеттеров с ограничителями.
 **********************************************************************/

#include "stat.h"

#include <QDate>
#include <qfile.h>

int Stat::getValue() const
{
    return value;
}

void Stat::setValue(int newValue)
{
    value = newValue;

    if(value > maximum)
        value = maximum;
    else if(value<0)
        value = 0;

    //Если текущее значение прогрессбара превышает максимальное значение, то оно усекается
    if(progressBarCurrentValue>value)
        progressBarCurrentValue = value;

    calculateFinalValue();
}

void Stat::addBonus(Bonus *bonus)
{
    bonuses.append(bonus);
    //Сортировка по степени воздействия
    std::sort(bonuses.begin(), bonuses.end(), [](Bonus* a, Bonus* b) {
        return *a > *b;
    });
    calculateFinalValue();
    emit statChanged();
}

/*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
 *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
 *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
 *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
bool Stat::removeBonus(Bonus *bonus)
{
    QMutableVectorIterator<Bonus*> iterator(bonuses);
    iterator.toBack();
    Bonus* MD;
    while(iterator.hasPrevious()){
        MD = iterator.previous();
        if(*MD==*bonus){
            delete MD;
            iterator.remove();

            calculateFinalValue();
            emit statChanged();
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
    "MagicDefense выдал предупреждение в методе removeBonus.\n"
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

int Stat::getFinalValue() const
{
    return finalValue;
}

int Stat::getProgressBarCurrentValue() const
{
    return progressBarCurrentValue;
}

//Задание текущего значения прогрессбара, при этом просто value, в таком случае, является максимальным значением
void Stat::setProgressBarCurrentValue(int newProgressBarCurrentValue)
{
    progressBarCurrentValue = newProgressBarCurrentValue;
}

QVector<Bonus *> Stat::getBonuses()
{
    return bonuses;
}

/*Очистка вектора бонусов. Метод не обновляет отображение бонусов в виджетах. Память указателей на
 *бонусы не высвобождается, так как это должно происходить только в классе предмета или эффекта*/
void Stat::removeAllBonuses()
{
    bonuses.clear();
}

//Вычисление финального максимального значения стата с учётом всех бонусов
void Stat::calculateFinalValue()
{
    finalValue = value;

    for(Bonus* bonus : bonuses){
        if(bonus != nullptr){
            if (bonus->isPercentage){
                int bonusFinalValue = ((double)value/100)*bonus->getValue();
                finalValue += bonusFinalValue;
                bonus->setFinalValue(bonusFinalValue);
            }else
                finalValue += bonus->getValue();
        }
    }

    if(finalValue > maximum)
        finalValue = maximum;
    else if(finalValue<0)
        finalValue = 0;

    //Сортировка бонусов по степени воздействия
    std::sort(bonuses.begin(), bonuses.end(), [](Bonus* a, Bonus* b) {
        return *a > *b;
    });
}

/*Разные группы статов имеют разные максимальные значения. Так для первичных навыков -
 *это 999999,а для вторичных - 9999999. Чтобы корректно работали ограничители на
 *сеттерах это максимальное значение задаётся при инициализации*/
Stat::Stat(int maximum) : maximum(maximum)
{}

Stat::~Stat()
{
    for(Bonus* bonus : bonuses)
        delete bonus;
}

//Так как класс Stat унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
Stat& Stat::operator= (const Stat &stat)
{
    value = stat.value;
    finalValue = stat.finalValue;
    progressBarCurrentValue = stat.progressBarCurrentValue;
    maximum = stat.maximum;
    bonuses = stat.bonuses;

    return *this;
}

int Stat::getMaximum() const
{
    return maximum;
}


RecalculatebleStat::RecalculatebleStat(int maximum, QVector<Stat *> primaryStats) : Stat(maximum)
{
    if(primaryStats.size()>=numberOfPrimaryStat){
        Strength = primaryStats.at(0);
        Agility = primaryStats.at(1);
        Intelligence = primaryStats.at(2);
        Magic = primaryStats.at(3);
        BodyType = primaryStats.at(4);
        Will = primaryStats.at(5);
    }else{
        //Вывод ошибки в консоль и файл
        QDate cd = QDate::currentDate();
        QTime ct = QTime::currentTime();

        QString error =
        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
        "\nОШИБКА: неправильное количество первичных навыков\n"
        "RecalculatebleStat выдал предупреждение в методе RecalculatebleStat.\n"
        "В конструктор было передано менее " + QString::number(numberOfPrimaryStat) + " стандартных primaryStats.\n"
        "Если вы хотите добавить новые первичные навыки, то просто добавьте\n"
        "их в конец primaryStats вектора, не трогая оригинальные.\n\n";
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
        std::exit(EXIT_FAILURE);
    }
}

int RecalculatebleStat::recalculate()
{
    return 0;
}

MagicDamageStat::MagicDamageStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int MagicDamageStat::recalculate()
{
    setValue(floor(1.5 * Magic->getFinalValue()) + floor(1.5 * Intelligence->getFinalValue()) + floor(0.5 * Will->getFinalValue()));

    return finalValue;

}

ResistPhysicalDamageStat::ResistPhysicalDamageStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int ResistPhysicalDamageStat::recalculate()
{
    setValue(floor(1.5 * Will->getFinalValue()) + floor(0.5 * Magic->getFinalValue()) + BodyType->getFinalValue());

    return finalValue;
}

ResistMagicDamageStat::ResistMagicDamageStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int ResistMagicDamageStat::recalculate()
{
    setValue(floor(1.5 * Will->getFinalValue()) + floor(0.5 * BodyType->getFinalValue()) + Magic->getFinalValue());

    return finalValue;
}

ResistPhysicalEffectsStat::ResistPhysicalEffectsStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int ResistPhysicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * Will->getFinalValue()) + 10);

    return finalValue;
}

ResistMagicEffectsStat::ResistMagicEffectsStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int ResistMagicEffectsStat::recalculate()
{
    setValue(floor(0.1 * Will->getFinalValue()) + floor(0.1 * Magic->getFinalValue()) + 5);

    return finalValue;
}

StrengtheningPhysicalEffectsStat::StrengtheningPhysicalEffectsStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int StrengtheningPhysicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * Strength->getFinalValue()));

    return finalValue;
}

StrengtheningMagicalEffectsStat::StrengtheningMagicalEffectsStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int StrengtheningMagicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * Intelligence->getFinalValue()));

    return finalValue;
}

MeleeAccuracyStat::MeleeAccuracyStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int MeleeAccuracyStat::recalculate()
{
    setValue(floor(0.1 * Agility->getFinalValue()) + 20);

    return finalValue;
}

RangedAccuracyStat::RangedAccuracyStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int RangedAccuracyStat::recalculate()
{
    setValue(floor(0.1 * Agility->getFinalValue()) + 15);

    return finalValue;
}

MagicAccuracyStat::MagicAccuracyStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int MagicAccuracyStat::recalculate()
{
    setValue(floor(0.1 * Intelligence->getFinalValue()) + 15);

    return finalValue;
}

EvasionStat::EvasionStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int EvasionStat::recalculate()
{
    setValue(floor(0.5 * Agility->getFinalValue()) + floor(0.1 * BodyType->getFinalValue()));

    return finalValue;
}

StealthStat::StealthStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int StealthStat::recalculate()
{
    setValue(Intelligence->getFinalValue() + Agility->getFinalValue());

    return finalValue;
}

AttentivenessStat::AttentivenessStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int AttentivenessStat::recalculate()
{
    setValue(Intelligence->getFinalValue() + Agility->getFinalValue() + Will->getFinalValue());

    return finalValue;
}

LoadCapacityStat::LoadCapacityStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int LoadCapacityStat::recalculate()
{
    setValue(floor(0.5 * Strength->getFinalValue()) + floor(0.5 * BodyType->getFinalValue()));

    return finalValue;
}

InitiativeStat::InitiativeStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int InitiativeStat::recalculate()
{
    setValue(floor(5 * Agility->getFinalValue()) + Intelligence->getFinalValue() + Will->getFinalValue());

    return finalValue;
}

MagicCastChanceStat::MagicCastChanceStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int MagicCastChanceStat::recalculate()
{
    setValue(floor(0.3 * Intelligence->getFinalValue()) + floor(0.2 * Magic->getFinalValue()));

    return finalValue;
}

ChanceOfUsingCombatTechniqueStat::ChanceOfUsingCombatTechniqueStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int ChanceOfUsingCombatTechniqueStat::recalculate()
{
    setValue(floor(0.2 * Agility->getFinalValue()) + 20);

    return finalValue;
}

MoveRangeStat::MoveRangeStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int MoveRangeStat::recalculate()
{
    setValue(floor(0.75 * Agility->getFinalValue()) + floor(0.5 * Strength->getFinalValue()) + BodyType->getFinalValue());

    return finalValue;
}

HealthStat::HealthStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int HealthStat::recalculate()
{
    setValue(Strength->getFinalValue() * 2 + BodyType->getFinalValue() * 10 + Will->getFinalValue() * 5 + Magic->getFinalValue());

    return finalValue;
}

EnduranceStat::EnduranceStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int EnduranceStat::recalculate()
{
    setValue(Agility->getFinalValue() * 10 + BodyType->getFinalValue());

    return finalValue;
}

ManaStat::ManaStat(int maximum, QVector<Stat *> primaryStats):RecalculatebleStat(maximum, primaryStats)
{}
int ManaStat::recalculate()
{
    setValue(Magic->getFinalValue() * 10 + Intelligence->getFinalValue() * 2 + Will->getFinalValue());

    return finalValue;
}
