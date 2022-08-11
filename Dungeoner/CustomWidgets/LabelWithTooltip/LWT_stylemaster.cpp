/*************************************************************
 *Мастер стилей для LabelWithTooltip. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 *************************************************************/

#include "LWT_stylemaster.h"

QString LWT_StyleMaster::TextFontStyle(int sizePX, QString fontName)
{
    //Вместо %1 будет вставлен размер шрифта, а вместо %2 имя шрифта
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px '%2';"
    "   color: #bdc440;"
    "}";

    return style.arg(sizePX).arg(fontName);
}
