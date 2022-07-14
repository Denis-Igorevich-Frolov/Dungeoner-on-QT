#ifndef LABELWITHTOOLTIP_H
#define LABELWITHTOOLTIP_H

/*
 *Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки. Подсказка выводится
 *при нажатии правой кнопкой мыши. При наводке курсора на виджет, его значёк
 *меняется на курсор со знаком вопроса.
 */

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

private:
    Ui::LabelWithTooltip *ui;

protected:
//Функции эвентов нажатия и отжатия кнопок мыши
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};

#endif // LABELWITHTOOLTIP_H
