#include "WGB_stylemaster.h"


QString WGB_stylemaster::GripButtonStyle()
{
    return("QPushButton{"
           "border: none;"
           "background:url(:/Character-Equipment/Textures PNG/One-Handed-Button.png);"
           "}"
           ""
           "QPushButton:hover{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/One-Handed-Button-Hovered.png);"
           "}"
           ""
           "QPushButton:pressed{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/One-Handed-Button-Pressed.png);"
           "}"
           ""
           "QPushButton:checked{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button.png);"
           "}"
           ""
           "QPushButton:checked:hover{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button-Hovered.png);"
           "}"
           ""
           "QPushButton:checked:pressed{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button-Pressed.png);"
           "}");
}

QString WGB_stylemaster::GripButtonPressedStyle()
{
    return("QPushButton{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/One-Handed-Button-Pressed.png);"
           "}"
           ""
           "QPushButton:pressed{"
           "    border: none;"
           "    background:url(:/Character-Equipment/Textures PNG/Two-Handed-Button-Pressed.png);"
           "}");
}
