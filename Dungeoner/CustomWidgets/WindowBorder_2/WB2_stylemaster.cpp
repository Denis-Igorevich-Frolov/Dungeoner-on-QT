/***********************************************************
 *Мастер стилей для WindowBorder_2. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#include "WB2_stylemaster.h"

QString WB2_Stylemaster::BottomLeftCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-1-B-L.png);"
    "}";
}

QString WB2_Stylemaster::TopLeftCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-1-T-L.png);"
    "}";
}

QString WB2_Stylemaster::BottomRightCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-1-B-R.png);"
    "}";
}

QString WB2_Stylemaster::TopRightCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-1-T-R.png);"
    "}";
}

QString WB2_Stylemaster::BottomBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #bec340;"
    "}";
}

QString WB2_Stylemaster::TopBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #bec340;"
    "}";
}

QString WB2_Stylemaster::LeftBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #bec340;"
    "}";
}

QString WB2_Stylemaster::RightBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #bec340;"
    "}";
}
