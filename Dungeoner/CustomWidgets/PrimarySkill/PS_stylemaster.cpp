/************************************************************
 *Мастер стилей для PrimarySkill. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ************************************************************/

#include "PS_stylemaster.h"

QString PS_StyleMaster::SpinBoxStyle(int sizePX)
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
