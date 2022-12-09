#ifndef PRIMARYSKILLSIGNATURE_H
#define PRIMARYSKILLSIGNATURE_H

/***********************************************************
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 ***********************************************************/

#include "Global/global.h"
#include "CustomWidgets/LabelWithTooltip/labelwithtooltip.h"
#include "Person/Stat/stat.h"

#include <QWidget>
#include <QSpinBox>
#include <QTimer>
#include <qgridlayout.h>

namespace Ui {
class PrimarySkillSignature;
}

class PrimarySkillSignature : public QWidget
{
    Q_OBJECT

public:
    explicit PrimarySkillSignature(QWidget *parent = nullptr);
    ~PrimarySkillSignature();

    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    //Устанавливает текст для LabelWithTooltip
    void setText(QString text);

    LabelWithTooltip* getlabelWithTooltip();

    //Установка контента подсказки по нажатию на правую нопку мыши по подписи
    void setTooltipContent(QString fullName, QString description);

    QSpinBox *getSpinBoxValue() const;
    /*Метод связвания QSpinBox (значение стата) с PrimarySkillSignature (подпись).
     *Само связываниепроизводится непосредственно в классе окна.*/
    void setSpinBoxValue(QSpinBox *newSpinBoxValue);

    Stat *getStat() const;
    void setStat(Stat *newStat);

signals:
    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();

private slots:
    /*Метод реализации нажатия кнопки прибавки стата. Он обрабатывает нажатия с учётом модификаторов:
     *Alt: +5, Ctrl: +10, Shift: +100. Обычное нажатие: +1. Модификатором считается последняя нажатая клавиша.*/
    void on_ButtonTop_released();
    /*Метод реализации нажатия кнопки вычета стата. Он обрабатывает нажатия с учётом модификаторов:
     *Alt: -5, Ctrl: -10, Shift: -100. Обычное нажатие: -1. Модификатором считается последняя нажатая клавиша.*/
    void on_ButtonBottom_released();
    void clickModifierTooltipTimerAlarm();
    void valueChanged(int value);
    void bonusesChanged();

private:
    Ui::PrimarySkillSignature *ui;

    //Энум знака числа. Используется для подсказки бонусов
    enum NumberSign{
        PLUS,
        MINUS,
        ZERO
    };
    NumberSign numberSign = ZERO;

    /*Указатель на QSpinBox со значением стата, относящимся к этой подписи. Само связывание
     *PrimarySkillSignature и QSpinBox производится непосредственно в классе окна.*/
    QSpinBox *SpinBoxValue;
    Stat* stat;
    bool bonusesLableIsAppend = false;

    //Таймер до вывода подсказки по модификаторам нажатия при наведении курсора на кнопку прибавки или убавки стата
    QTimer* clickModifierTooltipTimer = new QTimer;
    bool isShowTooltip = false;
    //Подсказка при наведении на кнопку прибавки или убавки
    QVector<QLabel*> buttonTooltipContent;
    //Подсказка при нажатии правой кнопки по подписи стата
    QVector<QLabel*> tooltipContent;
    QLabel* buttonTooltipContentLabel = new QLabel;
    QLabel* valueLabel;
    QLabel* bonusesLabel = new QLabel;
    QGridLayout* bonusesLayout = new QGridLayout;

    //Генерация лейбла с информацией по всем бонусам для его дальнейшего добавления в tooltipContent
    void CreatingBonusTooltip();

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
