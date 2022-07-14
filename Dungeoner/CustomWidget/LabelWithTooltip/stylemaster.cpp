/*
 *Мастер стилей для LabelWithTooltip. Устанавливает
 *QSS стили для всех эллементов.
 */

#include "stylemaster.h"

QString StyleMaster::TextFontStyle(int sizePX)
{
    QString style =
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   font: %1px 'Algerian';"
    "   color: #bdc440"
    "}";

    return style.arg(sizePX);
}
