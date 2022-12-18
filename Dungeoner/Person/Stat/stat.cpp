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
    emit bonusesChanged();
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
            emit bonusesChanged();
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
