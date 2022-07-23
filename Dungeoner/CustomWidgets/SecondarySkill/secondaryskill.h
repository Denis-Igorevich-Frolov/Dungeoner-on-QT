#ifndef SECONDARYSKILL_H
#define SECONDARYSKILL_H

/*Данный класс представляет собой панельку вторичного навыка. Вынесен
 *в отдельный класс просто для выведения подсказки и гарантии того,
 *что все QGraphicsDropShadowEffect точно будут удалены в деструкторе.*/

#include <QGraphicsDropShadowEffect>
#include <QWidget>

namespace Ui {
class SecondarySkill;
}

class SecondarySkill : public QWidget
{
    Q_OBJECT

public:
    explicit SecondarySkill(QWidget *parent = nullptr);
    ~SecondarySkill();

    long getValue() const;
    /*Сеттер на переменную Value. Также устанавливает число в
     *лейбл Value и меняет его межстрочный интервал*/
    void setValue(long newValue);
    void setInscription(QString inscription);
    void setFontSize(int size);

signals:
    //сигнал отображения подсказки будет сдвигать её, если она уже существует
    void ShowTooltip();
    void RemoveTooltip();

private:
    //Эффекты тени для текста
    QGraphicsDropShadowEffect* shadow1;
    QGraphicsDropShadowEffect* shadow2;

    /*Значение стата имеет ограничение в 9999999, превышать которое не стоит
     *из-за возрастающего риска переполнения при взаимодействии с ним*/
    long value = 0;
    QString SValue;

    Ui::SecondarySkill *ui;

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

#endif // SECONDARYSKILL_H
