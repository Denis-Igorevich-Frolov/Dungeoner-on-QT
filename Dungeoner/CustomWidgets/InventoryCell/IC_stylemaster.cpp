#include "IC_stylemaster.h"

QString IC_stylemaster::emptyBorderStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-BG.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::notEmptyBorderStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::disabledNotEmptyBorderStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Disabled-Inventory-Item-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::notEmptyBGStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Not-Empty-BG.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::disabledNotEmptyBGStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Disabled-Inventory-Item-Not-Empty-BG.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::centralElementStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Central-Element.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::lockedStyle()
{
    return
    "QLabel{"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Item-Locked.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::dropdownButtonEmptyStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Text-Block-2/Textures PNG/DecorativeElement-2-D.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}"
    ""
    "QPushButton::hover{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Empty-Hovered.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}"
    ""
    "QPushButton::pressed{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Empty-Pressed.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::dropdownButtonNotEmptyStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}"
    ""
    "QPushButton::hover{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Not-Empty-Hovered.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}"
    ""
    "QPushButton::pressed{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Not-Empty-Pressed.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}

QString IC_stylemaster::dropdownButtonDisabledNotEmptyStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Disabled-Not-Empty.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}"
    ""
    "QPushButton::hover{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Disabled-Not-Empty-Hovered.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}"
    ""
    "QPushButton::pressed{"
    "   background: none;"
    "   border: none;"
    "   background-image: url(:/Inventory/Textures PNG/Inventory-Dropdown-Button-Disabled-Not-Empty-Pressed.png);"
    "   background-repeat: no-repiat;"
    "   background-position: center center;"
    "}";
}
