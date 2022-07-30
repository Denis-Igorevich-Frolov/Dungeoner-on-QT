#ifndef PROGRESSBAR_1_H
#define PROGRESSBAR_1_H

#include <QWidget>

namespace Ui {
class ProgressBar_1;
}

class ProgressBar_1 : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar_1(QWidget *parent = nullptr);
    ~ProgressBar_1();

    int getMinValue() const;
    void setMinValue(int newMinValue);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    int getValue() const;
    void setValue(int newValue);

    void setColor(const QColor &newColor);

private:
//    QColor color = QColor(255, 0, 0);
    QColor color = QColor(0 , 0, 0, 0);
    int minValue = 0;
    int maxValue = 0;
    int value = 0;
    double stepSize = 0;

    void recalculationChunkWidth();
    void redrawChunk();

    void resizeEvent(QResizeEvent* event);

    Ui::ProgressBar_1 *ui;
};

#endif // PROGRESSBAR_1_H
