/*************************************************************
 *Мастер стилей для LabelWithTooltip. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 *************************************************************/

#include "LWT_stylemaster.h"

QString LWT_StyleMaster::TextFontStyle(int sizePX)
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
