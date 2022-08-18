/****************************************************************
 *Мастер стилей для MagicDefenseProgressBar. Хранит Qss,
 *инструкции которые затем будут применены к элементам виджета
 ****************************************************************/

#include "MDP_stylemaster.h"

QString MDP_StyleMaster::TextFontStyle(int sizePX)
{
    //Вместо %1 будет вставлен размер шрифта, а вместо %2 имя шрифта
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px;"
    "   color: #bdc440;"
    "}";

    return style.arg(sizePX);
}
