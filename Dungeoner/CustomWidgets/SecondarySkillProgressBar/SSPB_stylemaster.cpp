/****************************************************************
 *Мастер стилей для SecondarySkillProgressBar. Хранит Qss,
 *инструкции которые затем будут применены к элементам виджета
 ****************************************************************/

#include "SSPB_stylemaster.h"

QString SSPB_StyleMaster::TextFontStyle(int sizePX)
{
    //Вместо %1 будет вставлен размер шрифта
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px;"
    "   color: #bdc440;"
    "}";

    return style.arg(sizePX);
}

QString SSPB_StyleMaster::TipLeftStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Decorative-Elements/Textures PNG/Tip-L-1.png);"
    "}";
}

QString SSPB_StyleMaster::TipRightStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Decorative-Elements/Textures PNG/Tip-R-1.png);"
    "}";
}

QString SSPB_StyleMaster::BorderStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background: #bec24d;"
    "}";
}
