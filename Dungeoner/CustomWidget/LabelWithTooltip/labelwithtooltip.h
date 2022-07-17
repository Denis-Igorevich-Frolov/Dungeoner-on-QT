#ifndef LABELWITHTOOLTIP_H
#define LABELWITHTOOLTIP_H

/*
 *Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки. Подсказка выводится
 *при нажатии правой кнопкой мыши. При наводке курсора на виджет, его значёк
 *меняется на курсор со знаком вопроса.
 *
 *Суть вынесения этой одной кнопки в отдельный класс в том, чтобы эвент
 *QMouseEvent обрабатывала только эта кнопка, а не весь родительский виджет,
 *а так как QMouseEvent - это эвент класса виджет, то самым простым и
 *понятным решением было просто вынести кнопку в отдельный виджет.*/

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

private:
    Ui::LabelWithTooltip *ui;

protected:
    /*Функция ивента нажатия клафиши мыши. Обрабатывает нажатие только
     *правой кнопки для вывода подсказки.*/
    virtual void mousePressEvent(QMouseEvent* event);
    /*Функция ивента отжатия клафиши мыши. Обрабатывает отжатие только
     * правой кнопки для сокрытия подсказки.*/
    virtual void mouseReleaseEvent(QMouseEvent* event);
};

#endif // LABELWITHTOOLTIP_H
