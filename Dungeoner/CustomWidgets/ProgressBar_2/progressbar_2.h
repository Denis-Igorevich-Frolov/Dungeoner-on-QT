/************************************************************************************************************
 *Данный класс является прогрессбаром разделённым на ячейки. Он предназначен пока что только для
 *магической защиты. Общее значение складывается из векторов фрагментов прогрессбара (Сhunk).
 *Максимальное количество родных чанков 50, но бонусные чанки могут расширить предел до 60. Всё,
 *что не влезло в эти пределы усекается.
 *
 *Важно то, что частично заполненным может быть только один чанк, если такой чанк не первый, то
 *все чанки до него должны быть полностью заполненными, а все чанки после - полностью пустыми.
 *По этому, хоть вектор chunks и имеет сеттер, он предназначен только для первичной инициализации,
 *все же последующие вычисления производятся при помощи методов addValue, subtractValue, HealOneChunk,
 *spendLastChunk и т.д.
 *
 *addBonusChunk добавляет незаполненные ячейки в конец прогрессбара. Медод добавит незаполненную
 *ячейку даже если передать заполненную. Бонусные чанки добавляются всегда в конец, всегда уже
 *после родных чанков. При удалении бонусных чанков итератор делает обход с конца вектора. То
 *есть если имеются 2 одинаковых бонусных чанка, вне зовисимости от причины вызываемого удаления,
 *будет удалён последний подходящий.
 *
 *Надпись прогрессбара выводит информацию в формате
 *Текущий чанк / Всего чанков(текущее значение чанка / Максимальное значение чанка)
 ************************************************************************************************************/

#ifndef PROGRESSBAR_2_H
#define PROGRESSBAR_2_H

#include "Person/MagicDefense/chunk.h"

#include <QHBoxLayout>
#include <QWidget>

#include <CustomWidgets/LabelWithTooltip/labelwithtooltip.h>

#include <Person/MagicDefense/magicdefense.h>

namespace Ui {
class ProgressBar_2;
}


class ProgressBar_2 : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar_2(QWidget *parent = nullptr);
    ~ProgressBar_2();

    void setColor(const QColor &newColor);

    const QVector<Chunk*> &getChunks() const;
    //Метод задаёт родные чанки (nativeChunks)
    void setChunks(const QVector<Chunk*> &newChunks, int totalValue, int amountOfNativeChunks, int amountOfBonusChunks, int value);

    LabelWithTooltip* getLabelWithTooltip();

    void setTooltipContent(QString fullName, QString numberOfChunksFormula, QString chunkValueFormula, QString description);

    /*Метод возвращает индекс текущего активного чанка. Текущим чанком
     *считается последний чанк, имеющий ненулевое значение.*/
    int getCurrentChunkIndex();

    /*Метод устанавливает общее значение всему прогрессбару, последовательно заполняя все чанки пока
     *не кончится переданное значение. Используется для первичной инициализации и сохранения значения
     *при перерасчёте векторов прогрессбара из переменной value, чтобы оно не сбрасывалось при любом
     *изменении.*/
    void setValue(int value);

    //Максимальное значение всего прогрессбара
    int totalValue = 0;
    //Текущее общее заполненное значение всех чанков прогрессбара
    int value = 0;
    //Значение воли которого недостаёт до получения ещё одного фрагмента магической защиты
    int willUntilNextChunk = 0;

    void setStat(MagicDefense *newStat);

private slots:
    void statChanged();

private:
    //Энум знака числа. Используется для подсказки бонусов
    enum NumberSign{
        PLUS,
        MINUS,
        ZERO
    };
    NumberSign numberSign = ZERO;

    bool bonusesLableIsAppend = false;

    MagicDefense* stat = nullptr;

    int amountOfNativeChunks = 0;
    int amountOfBonusChunks = 0;

    //Цвет, в который будет окрашенна заполненная область прогрессбара
    QColor color = QColor(0 , 0, 0, 0);
    /*Общий вектор чанков. Его первая часть состоит из родных чанков
     *(nativeChunks), а вторая - из бонусных (bonusChunks)*/
    QVector<Chunk*> chunks;
    //Вектор родных чанков, которые будут расположены в начале - перед бонусными
    QVector<Chunk*> nativeChunks;
    //Вектор бонусных чанков, который хранит все бонусы
    QVector<Chunk*> bonusChunks;
    //Вектор бонусных чанков, которые влезли в предел и будут добавлены в конец прогрессбара
    QVector<Chunk*> finalBonusChunks;

    //Метод задаёт текущее значение в подсказве в формате Текущее_Значение (Исходное_Значение+Бонус)
    void setTextValue();

    /*Размер в пикселях, которому эквивалентен сдвиг
     *заполняемой области при изменении значения на 1*/
    double stepSize = 0;

    //Пересчёт размера заполненной области и позиций разделителей
    void recalculationChunkWidth();
    //Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
    void redrawChunk();
    //Генерация лейбла с информацией по всем бонусам для его дальнейшего добавления в tooltipContent
    void CreatingBonusTooltip();

    /*Переопределённая виртуальная функция класса QWidget. Во время этого эвента
     *происходит подгонка всех обёрток(wrapper) под размер виджета.*/
    void resizeEvent(QResizeEvent* event) override;

    QVector<QLabel*> tooltipContent;
    QVector<QLabel*> AltTooltipContent;
    QLabel* valueLabel = new QLabel;
    QLabel* generalValueLabel = new QLabel;
    QLabel* chunkNumber = new QLabel;
    QLabel* newChunkRequirementsLabel = new QLabel;
    QLabel* detailedInformationLabel = new QLabel;
    QLabel* bonusesLabel = new QLabel;
    QGridLayout* bonusesLayout = new QGridLayout;

    Ui::ProgressBar_2 *ui;
};

#endif // PROGRESSBAR_2_H
