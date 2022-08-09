/***************************************************
 *Окно персонажа, содержащее всю информацию о нём
 ***************************************************/

#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

#include <QWidget>

namespace Ui {
class CharacterWindow;
}

class CharacterWindow : public QWidget
{
    Q_OBJECT

public:
    CharacterWindow(QWidget *parent = nullptr);
    ~CharacterWindow();

private slots:
    void ScrollAreaSecondarySkillsScrolled(int value);

    void ShowTooltip();
    void RemoveTooltip();

    void on_verticalScrollBar_actionTriggered(int action);
    void on_verticalScrollBar_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::CharacterWindow *ui;

    /*Установка текста для подписи первичного навыка в соответствии с его динамическим свойством
     *Text путём перебора всех дочерних элементов контейнера PrimarySkillSignatures*/
    void setTextPrimarySkillSignature ();
    //Установка стилей всех объектов. Подробности в комментариях cpp файла
    void setStyles ();
    /*В данном методе связываются подписи с их значениями в QSpinBox путём передачи
     *указателя на QSpinBox в переменную SpinBoxValue класса PrimarySkillSignature.
     *Делается это для работы кнопок больше и меньше.*/
    void associatingLabelsWithValues();

    void linkingTooltipSlots();
};

#endif // CHARACTERWINDOW_H
