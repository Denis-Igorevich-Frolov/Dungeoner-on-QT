/***************************************************
 *Окно персонажа, содержащее всю информацию о нём
 ***************************************************/

#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

#include <QLabel>
#include <QWidget>
#include "Person/person.h"

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
    void InventoryScrollAreaScrolled(int value);

    void onStrengthChanged();
    void onAgilityChanged();
    void onIntelligenceChanged();
    void onMagicChanged();
    void onBodyTypeChanged();
    void onWillChanged();

    //Метод обновляющий отображение всех статов, инициализируя виджеты данными из класса Person
    void refreshDisplayStats();

    //Добавление новой линии пустых ячеек в инвентарь
    void addRowOfCellsToInventory();
    //Удаление последней линии ячеек в инвентаре
    void removeRowOfCellsFromInventory();

    void on_verticalScrollBar_actionTriggered(int action);
    void on_verticalScrollBar_valueChanged(int value);

    void on_StrengthValue_valueChanged(int arg1);

    void on_AgilityValue_valueChanged(int arg1);

    void on_IntelligenceValue_valueChanged(int arg1);

    void on_MagicValue_valueChanged(int arg1);

    void on_BodyTypeValue_valueChanged(int arg1);

    void on_WillValue_valueChanged(int arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_SaveButton_clicked();

    void on_LoadButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_InventoryScrollBar_valueChanged(int value);
    void on_InventoryScrollBar_actionTriggered(int action);

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

    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();

    void associatingLabelsWithStat();

    /*Данный метод связывает все слоты показа и сокрытия подсказки у всех
     *необходимых элементов со слотами показа и сокрытия подсказки окна*/
    void linkingTooltipSlots();

    //В методе происходит полный перерасчёт всех вторичных навыков
    void recalculateStats();

    void initPrimaryStatsWidgets();

    //Инициализация элементов интерфеса связанных со статами значениями из Person
    void initSecondaryStatsWidgets();

    void healthSetValue(int value);
    void enduranceSetValue(int value);
    void manaSetValue(int value);

    //Заполнение контентом подсказок элементов на основе их динамических свойств
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

    virtual bool eventFilter(QObject* object, QEvent* event) override;

    Person person;
    bool isManualStatReplacement = false;
};

#endif // CHARACTERWINDOW_H
