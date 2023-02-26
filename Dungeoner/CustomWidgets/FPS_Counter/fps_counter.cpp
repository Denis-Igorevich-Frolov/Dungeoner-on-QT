#include "fps_counter.h"
#include "qdatetime.h"
#include "ui_fps_counter.h"

FPS_Counter::FPS_Counter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FPS_Counter)
{
    ui->setupUi(this);
}

FPS_Counter::~FPS_Counter()
{
    delete ui;
}

void FPS_Counter::setActive(bool active)
{
    this->active = active;
    if(active)
        ui->FPSLabel->setStyleSheet("background: white;"
                                    "color: black;");
    else
        ui->FPSLabel->setStyleSheet("background: white;"
                                    "color: grey;");
}

void FPS_Counter::paintEvent(QPaintEvent *event)
{
    if(active){
        qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
        times.push_back(currentTime);

        while (times[0] < currentTime - 1000) {
            times.pop_front();
        }

        int currentCount = times.length();
        currentFPS = (currentCount + cacheCount) / 2;

        cacheCount = currentCount;
        ui->FPSLabel->setText(" FPS "+QString::number(currentFPS));

        update();
    }
}
