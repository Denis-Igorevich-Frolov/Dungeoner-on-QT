/**********************************************************
 *Мастер стилей для ProgressBar_2. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 **********************************************************/

#include "PB2_stylemaster.h"

QString PB2_StyleMaster::BordersStyle()
{
    return
    "QLabel#BorderBottom{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Border-B-1.png);"
    "}"
    ""
    "QLabel#BorderTop{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Border-T-1.png);"
    "}";
}

QString PB2_StyleMaster::ShadowStyle()
{
    return
    "QLabel#Shadow{"
    "   background: none;"
    "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 100),"
    "               stop:0.5 rgba(116, 116, 116, 0), stop:1 rgba(0, 0, 0, 100));"
    "}";
}

QString PB2_StyleMaster::TipsStyle()
{
    return
    "QLabel#TipLeft{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/ProgressBarTip-L-1.png);"
    "   background-repeat: no-repeat;"
    "}"
    ""
    "QLabel#TipRight{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/ProgressBarTip-R-1.png);"
    "   background-repeat: no-repeat;"
    "}";
}

QString PB2_StyleMaster::ProgressBarSeparatorStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/ProgressBarSeparator.png);"
    "}";
}

QString PB2_StyleMaster::TooltipTextStyle(int sizePX, QString color)
{
    //Вместо %1 будет вставлен размер шрифта, а вместо %2 - его цвет
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px;"
    "   color: #%2;"
    "}";

    return style.arg(sizePX).arg(color);
}

QString PB2_StyleMaster::SeparatorStyle()
{
    return
    "background: url(:/Text-Block-1/Textures PNG/Separator-1.png);"
    "background-repeat: norepeat;"
    "background-position: center;";
}
