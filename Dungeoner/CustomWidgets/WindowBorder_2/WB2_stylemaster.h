/***********************************************************
 *Мастер стилей для WindowBorder_2. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#ifndef WB2_STYLEMASTER_H
#define WB2_STYLEMASTER_H

#include <QString>

class WB2_Stylemaster
{
public:
    static QString BottomLeftCornerStyle();
    static QString TopLeftCornerStyle();
    static QString BottomRightCornerStyle();
    static QString TopRightCornerStyle();

    static QString BottomBorderStyle();
    static QString TopBorderStyle();
    static QString LeftBorderStyle();
    static QString RightBorderStyle();
};

#endif // WB2_STYLEMASTER_H
