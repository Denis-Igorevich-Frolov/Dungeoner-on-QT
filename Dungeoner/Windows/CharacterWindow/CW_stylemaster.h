/************************************************************
 *Мастер стилей для CharacterWindow. Хранит Qss инструкции,
 *которые затем будут применены к элементам окна
 ************************************************************/

#ifndef CW_STYLEMASTER_H
#define CW_STYLEMASTER_H

#include <QString>

class CW_StyleMaster
{
public:
    static QString SpinBoxStyle(int sizePX);
};

#endif // CW_STYLEMASTER_H
