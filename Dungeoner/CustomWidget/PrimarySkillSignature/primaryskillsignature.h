#ifndef PRIMARYSKILLSIGNATURE_H
#define PRIMARYSKILLSIGNATURE_H

/*Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.*/

#include "MediaPlayer/mediaplayer.h"
#include "dungeoner.h"

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

    //Устанавливает текст для LabelWithTooltip
    void setText(QString text);

private slots:
    /*Метод реализации нажатия кнопки прибавки стата. Он обрабатывает нажатия с учётом модификаторов:
     *Ctrl: +10, Ctrl+Shift: +100, Ctrl+Shift+Alt: +1000. Обычное нажатие: +1. Во вложенных циклах
     *поиска прибавка написана как +90 и +900 из-за того, что если код дошёл до этой позиции,
     *то соответственно все вышестоящие прибавки уже были произведены.*/
    void on_ButtonTop_released();
    /*Метод реализации нажатия кнопки убавления стата. Он обрабатывает нажатия с учётом модификаторов:
     *Ctrl: -10, Ctrl+Shift: -100, Ctrl+Shift+Alt: -1000. Обычное нажатие: -1. Во вложенных циклах
     *поиска убавление написано как -90 и -900 из-за того, что если код дошёл до этой позиции, то
     *соответственно все вышестоящие вычеты уже были произведены.*/
    void on_ButtonBottom_released();

private:
    Ui::PrimarySkillSignature *ui;

    //Массив нажатых клавиш, среди которых только Ctrl, Shift и Alt
    QVector<int> pressedKeys;


    /*Эвент нажатия клавиши, который записывает код клавиши в вектор pressedKeys.
     *Считаются только Ctrl,Shift и Alt*/
    virtual void keyPressEvent(QKeyEvent *event);
    //Эвент отжатия клавиши, который находит и удаляет код клавиши из вектора pressedKeys
    virtual void keyReleaseEvent(QKeyEvent *event);
};

#endif // PRIMARYSKILLSIGNATURE_H
