#ifndef STYLEMASTER_H
#define STYLEMASTER_H

/*Мастер стилей для LabelWithTooltip. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include <QString>

class StyleMaster
{
public:
    static QString TextFontStyle(int size, QString fontName);
};

#endif // STYLEMASTER_H
