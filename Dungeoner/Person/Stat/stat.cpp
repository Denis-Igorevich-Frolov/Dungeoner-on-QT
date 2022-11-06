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

    calculateFinalValue();
}

void Stat::addBonus(Bonus *bonus)
{
    bonuses.append(bonus);
    calculateFinalValue();
}

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

void Stat::setProgressBarCurrentValue(int newProgressBarCurrentValue)
{
    progressBarCurrentValue = newProgressBarCurrentValue;
}

void Stat::calculateFinalValue()
{
    finalValue = value;

    for(Bonus* bonus : bonuses){
        if(bonus != nullptr){
            if (bonus->isPercentage)
                finalValue += ((double)value/100)*bonus->getValue();
            else
                finalValue += bonus->getValue();
        }
    }

    if(finalValue > maximum)
        finalValue = maximum;
    else if(finalValue<0)
        finalValue = 0;
}

Stat::Stat(int maximum) : maximum(maximum)
{}

Stat::~Stat()
{
    for(Bonus* bonus : bonuses)
        delete bonus;
}
