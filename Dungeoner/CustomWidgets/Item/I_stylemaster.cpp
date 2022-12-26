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

QString I_stylemaster::StyleButtonStile()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   font: bold 7px;"
    "   color: #492c03;"
    "   background-image: url(:/Inventory/Textures PNG/Item-Style-Button.png);"
    "}"
    ""
    "QPushButton::hover{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Item-Style-Button-Hovered.png);"
    "}"
    ""
    "QPushButton::pressed{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Item-Style-Button-Pressed.png);"
    "}";
}
