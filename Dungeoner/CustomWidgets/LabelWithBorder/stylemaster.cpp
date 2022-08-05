#include "stylemaster.h"

QString  StyleMaster::TextFontStyle(int sizePX, QString fontName)
{
    //Вместо %1 будет вставлен размер шрифта, а вместо %2 имя шрифта
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px '%2';"
    "}";

    return style.arg(sizePX).arg(fontName);
}
