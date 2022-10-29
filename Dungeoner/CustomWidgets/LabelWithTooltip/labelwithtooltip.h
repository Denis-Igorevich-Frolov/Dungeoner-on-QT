/******************************************************************************
 *Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки.
 *
 *Суть вынесения этого одного лейбла в отдельный класс в том, чтобы подсказка
 *выводилась только у этой части, а у всего родительского виджета
 ******************************************************************************/

#ifndef LABELWITHTOOLTIP_H
#define LABELWITHTOOLTIP_H

#include "System/TooltipDisplayEvents/tooltipdisplayevents.h"
#include "System/OutlineEffect/outlineeffect.h"

#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QWidget>

namespace Ui {
class LabelWithTooltip;
}

class LabelWithTooltip : public QWidget
{
    Q_OBJECT

public:
    explicit LabelWithTooltip(QWidget *parent = nullptr);
    ~LabelWithTooltip();

    //Устанавливает текст для ButtonText
    void setText(QString text);

    QString getText();

    /*От этого энума будет зависить шрифт, сама же
     *замена шрита происходит в сетере fontType*/
    enum FontType{
        TEXT,
        NUMBERS
    };

    FontType getFontType() const;
    void setFontType(FontType newFontType);
    void setOutlineThickness(int thickness);

    void setTooltipContent(QVector<QLabel*> &newTooltipContent);

    //Установка контента для подсказок вызываемых с зажатым модификатором

    void setAltTooltipContent(QVector<QLabel*> &newTooltipContent);
    void setCtrlTooltipContent(QVector<QLabel*> &newTooltipContent);
    void setShiftTooltipContent(QVector<QLabel*> &newTooltipContent);

signals:
    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();

private:
    Ui::LabelWithTooltip *ui;

    OutlineEffect* border;
    TooltipDisplayEvents tooltipDisplayEvents;

    QVector<QLabel*> tooltipContent;

    //Контент подсказок с зажатыми модификаторами

    QVector<QLabel*> AltTooltipContent;
    QVector<QLabel*> CtrlTooltipContent;
    QVector<QLabel*> ShiftTooltipContent;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

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

    //Автоматически инициализируем экземпляр энума значением по умолчанию
    FontType fontType = FontType::TEXT;
};

#endif // LABELWITHTOOLTIP_H
