/************************************************************
 *Мастер стилей для CharacterWindow. Хранит Qss инструкции,
 *которые затем будут применены к элементам окна
 ************************************************************/

#include "CW_stylemaster.h"

QString CW_StyleMaster::SpinBoxStyle(int sizePX)
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
    "   font-size: %1px;"
    "   color: #bdc440;"
    "}";
    return style.arg(sizePX);
}
