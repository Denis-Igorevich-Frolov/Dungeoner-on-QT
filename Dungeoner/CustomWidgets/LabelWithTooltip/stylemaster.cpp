/*Мастер стилей для LabelWithTooltip. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include "stylemaster.h"

QString StyleMaster::TextFontStyle(int sizePX)
{
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px 'Algerian';"
    "   color: #bdc440;"
    "}";

    return style.arg(sizePX);
}
