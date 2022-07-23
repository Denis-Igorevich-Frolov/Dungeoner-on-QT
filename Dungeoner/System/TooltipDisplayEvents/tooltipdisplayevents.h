#ifndef TOOLTIPDISPLAYEVENTS_H
#define TOOLTIPDISPLAYEVENTS_H

/*Данный класс представляет собой алгоритм, посылающий сигналы для выведения и сокрытия подсказки.*/

#include <QWidget>

class TooltipDisplayEvents : public QWidget
{
    Q_OBJECT
public:
    explicit TooltipDisplayEvents(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event, int width, int height);
    /*Это проверка, вызываемая при почти каждом выше переопределённом эвенте.
     *Сиграл ShowTooltip будет вызван только при условии, что курсор наведён
     *на виджет и правая кнопка мыши зажата, иначе будет попытка вызова RemoveTooltip*/
    void CheckingDisplayOfTooltip();

signals:
    //сигнал отображения подсказки будет сдвигать её, если она уже существует
    void ShowTooltip();
    void RemoveTooltip();

private:
    bool rightMousePressed = false;
    bool isHovered = false;

    /*TooltipHasBeenCalled участвует в проверке того, что RemoveTooltip был вызван
     *только один раз, только при условии, что ShowTooltip ранее уже был вызван*/
    bool TooltipHasBeenCalled = false;
};

#endif // TOOLTIPDISPLAYEVENTS_H
