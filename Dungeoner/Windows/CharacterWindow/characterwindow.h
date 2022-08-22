/***************************************************
 *Окно персонажа, содержащее всю информацию о нём
 ***************************************************/

#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

#include <QLabel>
#include <QWidget>
#include "Global/global.h"

namespace Ui {
class CharacterWindow;
}

class CharacterWindow : public QWidget
{
    Q_OBJECT

public:
    CharacterWindow(QWidget *parent = nullptr);
    ~CharacterWindow();

    /*Массив нажатых клавиш, среди которых только Ctrl, Shift и Alt, они будут считаться
     *в виджетах модификаторами нажатия. Вектор статический и неконстантный, чтобы любой
     *виджет мог легко его получить и редактировать. Данный вектор общий для всего на
     *экране, что требует модификаторов нажатия, а располагается он именно в классе экрана
     *для гарантии того, что при первом нажатии, когда ещё никакой элемент интерфейса не
     *в фокусе, вектор уже мог быть проинициализирован зажатой клавишей. Возможность
     *редактирования вектора вне класса экрана разрешена для того, чтобы при дополнительном
     *нажатии или отжатии клавиши, когда в фокусе уже не экран, а виджет, вектор всё-равно
     *обновлялся как и должен. По этой причине любой виджет, который использует эти
     *модификаторы нажатия должен иметь точно такие же переопределения виртуальных функций
     *keyPressEvent и keyReleaseEvent, как и в этом классе.*/
    static QVector<int> pressedKeys;

private slots:
    void ScrollAreaSecondarySkillsScrolled(int value);

    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();

    void on_verticalScrollBar_actionTriggered(int action);
    void on_verticalScrollBar_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_StrengthValue_valueChanged(int arg1);

    void on_AgilityValue_valueChanged(int arg1);

    void on_IntelligenceValue_valueChanged(int arg1);

    void on_MagicValue_valueChanged(int arg1);

    void on_BodyTypeValue_valueChanged(int arg1);

    void on_WillValue_valueChanged(int arg1);

    void on_pushButton_4_clicked();

private:
    Ui::CharacterWindow *ui;

    /*Установка текста для подписи первичного навыка в соответствии с его динамическим свойством
     *Text путём перебора всех дочерних элементов контейнера PrimarySkillSignatures*/
    void setTextPrimarySkillSignature();
    //Установка стилей всех объектов. Подробности в комментариях cpp файла
    void setStyles ();
    /*В данном методе связываются подписи с их значениями в QSpinBox путём передачи
     *указателя на QSpinBox в переменную SpinBoxValue класса PrimarySkillSignature.
     *Делается это для работы кнопок больше и меньше.*/
    void associatingLabelsWithValues();

    /*Данный метод связывает все слоты показа и сокрытия подсказки у всех
     *необходимых элементов со слотами показа и сокрытия подсказки окна*/
    void linkingTooltipSlots();

    void recalculateStats();

    void tooltipInitialization();

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

    virtual void leaveEvent(QEvent *event)override;

    //Эти переменные пока отладочные, их следует в последствии перенести в класс персонажа
    Global::PhysicalDamageScaling physicalDamageScaling = Global::STRENGTH;
};

#endif // CHARACTERWINDOW_H
