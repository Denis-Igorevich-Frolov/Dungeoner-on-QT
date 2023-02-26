#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <QWidget>

namespace Ui {
class FPS_Counter;
}

class FPS_Counter : public QWidget
{
    Q_OBJECT

public:
    explicit FPS_Counter(QWidget *parent = nullptr);
    ~FPS_Counter();

    void setActive(bool active);
    bool active = true;

private:
    Ui::FPS_Counter *ui;

        void paintEvent(QPaintEvent * event) override;

        int currentFPS;
        int cacheCount;
        QVector<qint64> times;
};

#endif // FPS_COUNTER_H
