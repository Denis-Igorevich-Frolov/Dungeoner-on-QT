#ifndef PROGRESSBAR_2_H
#define PROGRESSBAR_2_H

#include <QWidget>

namespace Ui {
class ProgressBar_2;
}

class ProgressBar_2 : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar_2(QWidget *parent = nullptr);
    ~ProgressBar_2();

    int getMinValue() const;
    void setMinValue(int newMinValue);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    int getValue() const;
    void setValue(int newValue);

    void setColor(const QColor &newColor);

private:
    //Цвет, в который будет окрашенна заполненная область прогрессбара
    QColor color = QColor(0 , 0, 0, 0);
    int minValue = 0;
    int maxValue = 0;
    int value = 0;
    /*Размер в пикселях, которому эквивалентен сдвиг
     *заполняемой области при изменении значения на 1*/
    double stepSize = 0;

    //Пересчёт размера заполненной области
    void recalculationChunkWidth();
    //Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
    void redrawChunk();

    /*Переопределённая виртуальная функция класса QWidget. Во время этого эвента
     *происходит подгонка всех обёрток(wrapper) под размер виджета.*/
    void resizeEvent(QResizeEvent* event) override;

    Ui::ProgressBar_2 *ui;
};

#endif // PROGRESSBAR_2_H
