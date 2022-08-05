#ifndef LABELWITHTOOLTIP_H
#define LABELWITHTOOLTIP_H

/*Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки.
 *
 *Суть вынесения этого одного лейбла в отдельный класс в том, чтобы подсказка
 *выводилась только у этой части, а у всего родительского виджета*/

#include "System/TooltipDisplayEvents/tooltipdisplayevents.h"
#include "../LabelWithBorder/labelwithborder.h"

#include <QGraphicsDropShadowEffect>
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

    void setFontStyle(QColor textColor, QColor borderColor, int borderThickness, LabelWithBorder::FontType fontType);

signals:
    void ShowTooltip();
    void RemoveTooltip();

private:
//    QGraphicsDropShadowEffect* shadow;
    Ui::LabelWithTooltip *ui;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    TooltipDisplayEvents tooltipDisplayEvents;
};

#endif // LABELWITHTOOLTIP_H
