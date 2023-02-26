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
    setUpdatesEnabled(active);
    if(active)
        ui->FPSLabel->setStyleSheet("color: black;");
    else
        ui->FPSLabel->setStyleSheet("color: gray;");
}

void FPS_Counter::paintEvent(QPaintEvent *event)
{
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    times.push_back(currentTime);

    while (times[0] < currentTime - 1000) {
        times.pop_front();
    }

    int currentCount = times.length();
    currentFPS = (currentCount + cacheCount) / 2;

    cacheCount = currentCount;
    ui->FPSLabel->setText("FPS "+QString::number(currentFPS));

    update();
}
