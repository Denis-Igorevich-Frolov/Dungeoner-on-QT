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

    /*От этого энума будет зависить шрифт, сама же
     *замена шрита происходит в сетере fontType*/
    enum FontType{
        TEXT,
        NUMBERS
    };

    FontType getFontType() const;
    void setFontType(FontType newFontType);

signals:
    void ShowTooltip();
    void RemoveTooltip();

private:
    OutlineEffect* border;
    Ui::LabelWithTooltip *ui;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    TooltipDisplayEvents tooltipDisplayEvents;

    //Автоматически инициализируем экземпляр энума значением по умолчанию
    FontType fontType = FontType::TEXT;
};

#endif // LABELWITHTOOLTIP_H
