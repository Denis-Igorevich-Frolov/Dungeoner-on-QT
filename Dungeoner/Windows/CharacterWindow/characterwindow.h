#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

/*Окно персонажа, содержащее всю информацию о нём*/

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
    void cho(int value);

private:
    Ui::CharacterWindow *ui;

    /*Установка текста для подписи первичного навыка в соответствии с его динамическим свойством
     *Text путём перебора всех дочерних элементов контейнера PrimarySkillSignatures*/
    void setTextPrimarySkillSignature ();
    //Установка стилей всех объектов. Подробности в комментариях cpp файла
    void setStyles ();
    void associatingLabelsWithValues();
};

#endif // CHARACTERWINDOW_H
