/************************************************************
 *Мастер стилей для Item. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ************************************************************/

#ifndef I_STYLEMASTER_H
#define I_STYLEMASTER_H

#include <QString>

class I_stylemaster
{
public:
    static QString TextFontStyle(int size);
    static QString StyleButtonStile();
    static QString StyleChosenButtonStile();
};

#endif // I_STYLEMASTER_H
