#include "stylemaster.h"

QString StyleMaster::SpinBoxStyle(int sizePX)
{
    QString style =
    "QSpinBox::up-button{"
    "     width: 0px;"
    "    height: 0px;"
    "}"
    ""
    "QSpinBox::down-button{"
    "     width: 0px;"
    "    height: 0px;"
    "}"
    ""
    "QSpinBox{"
    "   border: none;"
    "   background: #130a0f;"
    "   font: %1px 'Old English Text MT';"
    "   color: #bdc440;"
    "}";
    return style.arg(sizePX);
}
