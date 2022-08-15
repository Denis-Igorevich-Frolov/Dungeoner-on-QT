#ifndef SSPB_STYLEMASTER_H
#define SSPB_STYLEMASTER_H

#include <QString>

class SSPB_StyleMaster
{
public:
    static QString TextFontStyle(int sizePX, QString fontName);
    static QString TipLeftStyle();
    static QString TipRightStyle();
    static QString BorderStyle();
};

#endif // SSPB_STYLEMASTER_H