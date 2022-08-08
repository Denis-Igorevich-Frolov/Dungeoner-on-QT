/***********************************************************
 *Мастер стилей для WindowBorder_1. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#include "stylemaster.h"

QString stylemaster::BottomLeftCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-7-B-L.png);"
    "}";
}

QString stylemaster::TopLeftCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-7-T-L.png);"
    "}";
}

QString stylemaster::BottomRightCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-7-B-R.png);"
    "}";
}

QString stylemaster::TopRightCornerStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Angle-7-T-R.png);"
    "}";
}

QString stylemaster::BottomBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #271a12;"
    "   border-bottom: 1px solid #6d4b31;"
    "   border-top: 1px solid #483221;"
    "}";
}

QString stylemaster::TopBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #271a12;"
    "   border-top: 1px solid #6d4b31;"
    "   border-bottom: 1px solid #483221;"
    "}";
}

QString stylemaster::LeftBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #271a12;"
    "   border-left: 1px solid #6d4b31;"
    "   border-right: 1px solid #483221;"
    "}";
}

QString stylemaster::RightBorderStyle()
{
    return
    "QLabel{"
    "   background-color: #271a12;"
    "   border-right: 1px solid #6d4b31;"
    "   border-left: 1px solid #483221;"
    "}";
}
