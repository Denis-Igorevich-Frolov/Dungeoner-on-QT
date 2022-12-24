#include "I_stylemaster.h"

QString I_stylemaster::TextFontStyle(int size)
{
    //Вместо %1 будет вставлен размер шрифта
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px;"
    "   color: #bdc440;"
    "}";

    return style.arg(size);
}
