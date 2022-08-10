/**********************************************************
 *Мастер стилей для ProgressBar_1. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 **********************************************************/

#include "stylemaster.h"

QString StyleMaster::BordersStyle()
{
    return
    "QLabel#BorderBottom{"
    "   background-image: url(:/Text-Block-1/Textures PNG/Border-B-1.png);"
    "}"
    ""
    "QLabel#BorderTop{"
    "   background-image: url(:/Text-Block-1/Textures PNG/Border-T-1.png);"
    "}";
}

QString StyleMaster::ShadowStyle()
{
    return
    "QLabel#Shadow{"
    "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 100),"
    "               stop:0.5 rgba(116, 116, 116, 0), stop:1 rgba(0, 0, 0, 100));"
    "}";
}

QString StyleMaster::TipsStyle()
{
    return
    "QLabel#TipLeft{"
    "   background-image: url(:/Text-Block-1/Textures PNG/ProgressBarTip-L-1.png);"
    "   background-repeat: no-repeat;"
    "}"
    ""
    "QLabel#TipRight{"
    "   background-image: url(:/Text-Block-1/Textures PNG/ProgressBarTip-R-1.png);"
    "   background-repeat: no-repeat;"
    "}";
}
