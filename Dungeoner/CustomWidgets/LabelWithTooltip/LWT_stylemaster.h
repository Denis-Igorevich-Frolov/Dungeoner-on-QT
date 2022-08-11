/*************************************************************
 *Мастер стилей для LabelWithTooltip. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 *************************************************************/

#ifndef LWT_STYLEMASTER_H
#define LWT_STYLEMASTER_H

#include <QString>

class LWT_StyleMaster
{
public:
    static QString TextFontStyle(int size, QString fontName);
};

#endif // LWT_STYLEMASTER_H
