#include "II_stylemaster.h"

QString II_stylemaster::emptyBorderStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-BG.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::notEmptyBorderStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::disabledNotEmptyBorderStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Disabled-Inventory-Item-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::notEmptyBGStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Not-Empty-BG.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::disabledNotEmptyBGStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Disabled-Inventory-Item-Not-Empty-BG.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::centralElementStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Central-Element.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::lockedStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Locked.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::dropdownButtonEmptyStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Text-Block-2/Textures PNG/DecorativeElement-2-D.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::dropdownButtonNotEmptyStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString II_stylemaster::dropdownButtonDisabledNotEmptyStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Disabled-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}
