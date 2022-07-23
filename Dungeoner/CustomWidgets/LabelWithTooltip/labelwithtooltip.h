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

signals:
    void ShowTooltip();
    void RemoveTooltip();

private:
    QGraphicsDropShadowEffect* shadow;
    Ui::LabelWithTooltip *ui;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Крайне важно помнить, что у любого фиджета,
     *который хочет показывать подсказку, все дочерние элементы интерфейса
     *обязательно должны быть disabled. Сделать это можно в редакторе форм
     *сняв у них галочку enabled. Иначе некоторые эвенты будут "застревать"
     *в дочерних элементах виджета и не передаться родительскому*/
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    /*Это проверка, вызываемая при почти каждом выше переопределённом эвенте.
     *Сиграл ShowTooltip будет вызван только при условии, что курсор наведён
     *на виджет и правая кнопка мыши зажата, иначе будет попытка вызова RemoveTooltip*/
    void CheckingDisplayOfTooltip();

    bool rightMousePressed = false;
    bool isHovered = false;

    /*TooltipHasBeenCalled участвует в проверке того, что RemoveTooltip был вызван
     *только один раз, только при условии, что ShowTooltip ранее уже был вызван*/
    bool TooltipHasBeenCalled = false;
};

#endif // LABELWITHTOOLTIP_H
