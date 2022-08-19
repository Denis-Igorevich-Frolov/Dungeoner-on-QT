#ifndef PRIMARYSKILLSIGNATURE_H
#define PRIMARYSKILLSIGNATURE_H

/***********************************************************
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 ***********************************************************/

#include "dungeoner.h"
#include "Global/global.h"
#include "CustomWidgets/LabelWithTooltip/labelwithtooltip.h"

#include <QWidget>
#include <QSpinBox>
#include <QTimer>

namespace Ui {
class PrimarySkillSignature;
}

class PrimarySkillSignature : public QWidget
{
    Q_OBJECT

public:
    explicit PrimarySkillSignature(QWidget *parent = nullptr);
    ~PrimarySkillSignature();

    /*Указатель на QSpinBox относящийся к этой подписи. Само связывание
     * PrimarySkillSignature и QSpinBox производится непосредственно в классе окна.*/
    QSpinBox *SpinBoxValue;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    //Устанавливает текст для LabelWithTooltip
    void setText(QString text);

    LabelWithTooltip* getlabelWithTooltip();

signals:
    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();

private slots:
    /*Метод реализации нажатия кнопки прибавки стата. Он обрабатывает нажатия с учётом модификаторов:
     *Ctrl: +10, Shift: +100, Alt: +1000. Обычное нажатие: +1. Модификатором считается последняя нажатая клавиша.*/
    void on_ButtonTop_released();
    /*Метод реализации нажатия кнопки вычета стата. Он обрабатывает нажатия с учётом модификаторов:
     *Ctrl: -10, Shift: -100, Alt: -1000. Обычное нажатие: -1. Модификатором считается последняя нажатая клавиша.*/
    void on_ButtonBottom_released();
    void slotTimerAlarm();

private:
    Ui::PrimarySkillSignature *ui;

    QTimer* timer = new QTimer;
    bool isShowTooltip = false;
    QVector<QLabel*> TooltipContent;
    QLabel* tooltipContentLabel = new QLabel;

    /*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
     *Считаются только Ctrl,Shift и Alt*/
    virtual void keyPressEvent(QKeyEvent *event) override;
    /*Эвент отжатия клавиши, который находит и удаляет код клавиши из вектора pressedKeys.
     *Сделано это для того, чтобы обрабатывать случай, когда зажато несколько модификаторов
     *одновременно. Они не будут последовательно обработаны, считаться будет только последний,
     *но если просто сбрасывать int переменную, то может возникать случай, когда второй
     *модификатор будет зажат до отжатия предыдущего, а затем первый будет отжат, и управление
     *как бы "заест", модификатор придётся жать вновь. Для избежания этого и создан этот вектор.*/
    virtual void keyReleaseEvent(QKeyEvent *event) override;

    virtual bool eventFilter(QObject* object, QEvent* event) override;
};

#endif // PRIMARYSKILLSIGNATURE_H
