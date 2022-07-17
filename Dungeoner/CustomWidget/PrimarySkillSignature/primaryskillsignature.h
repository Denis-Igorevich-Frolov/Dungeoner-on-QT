#ifndef PRIMARYSKILLSIGNATURE_H
#define PRIMARYSKILLSIGNATURE_H

/*Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.*/

//#include "MediaPlayer/mediaplayer.h"
#include "dungeoner.h"
#include "Global/global.h"

#include <QWidget>
#include <QSpinBox>

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

//    MediaPlayer mediaPlayer;

    //Устанавливает текст для LabelWithTooltip
    void setText(QString text);

private slots:
    /*Метод реализации нажатия кнопки прибавки стата. Он обрабатывает нажатия с учётом модификаторов:
     *Ctrl: +10, Shift: +100, Alt: +1000. Обычное нажатие: +1. Модификатором считается последняя нажатая клавиша.*/
    void on_ButtonTop_released();
    /*Метод реализации нажатия кнопки вычета стата. Он обрабатывает нажатия с учётом модификаторов:
     *Ctrl: -10, Shift: -100, Alt: -1000. Обычное нажатие: -1. Модификатором считается последняя нажатая клавиша.*/
    void on_ButtonBottom_released();

private:
    Ui::PrimarySkillSignature *ui;

    //Массив нажатых клавиш, среди которых только Ctrl, Shift и Alt
    QVector<int> pressedKeys;


    /*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
     *Считаются только Ctrl,Shift и Alt*/
    virtual void keyPressEvent(QKeyEvent *event);
    /*Эвент отжатия клавиши, который находит и удаляет код клавиши из вектора pressedKeys.
     *Сделано это для того, чтобы обрабатывать случай, когда зажато несколько модификаторов
     *одновременно. Они не будут последовательно обработаны, считаться будет только последний,
     *но если просто сбрасывать int переменную, то может возникать случай, когда второй
     *модификатор будет зажат до отжатия предыдущего, а затем первый будет отжат, и управление
     *как бы "заест", модификатор придётся жать вновь. Для избежания этого и создан этот вектор.*/
    virtual void keyReleaseEvent(QKeyEvent *event);
};

#endif // PRIMARYSKILLSIGNATURE_H
