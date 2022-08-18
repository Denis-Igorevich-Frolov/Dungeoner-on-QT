/****************************************************************
 *Мастер стилей для SecondarySkillProgressBar. Хранит Qss,
 *инструкции которые затем будут применены к элементам виджета
 ****************************************************************/

#ifndef SSPB_STYLEMASTER_H
#define SSPB_STYLEMASTER_H

#include <QString>

class SSPB_StyleMaster
{
public:
    static QString TextFontStyle(int sizePX);
    static QString TipLeftStyle();
    static QString TipRightStyle();
    static QString BorderStyle();
};

#endif // SSPB_STYLEMASTER_H
