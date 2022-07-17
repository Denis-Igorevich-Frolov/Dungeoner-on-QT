#ifndef STYLEMASTER_H
#define STYLEMASTER_H

/*Мастер стилей для CharacterWindow. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include <QString>

class StyleMaster
{
public:
    static QString SpinBoxStyle(int sizePX);
};

#endif // STYLEMASTER_H
