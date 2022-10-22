/***********************************************************
 *Мастер стилей для SecondarySkill. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#include "SS_stylemaster.h"

QString SS_StyleMaster::SecondarySkillInscriptionStyle(int size)
{
    QString style =
    "QLabel{"
    "   background: none;"
    "   font-size: %1px;"
    "   color: #bdc440;"
    "}";
    return style.arg(size);
}

QString SS_StyleMaster::SecondarySkillValueStyle()
{
    /*Этот margin-bottom тут для компинсации размера при изменения межстрочного интервала.
     *Подробнее в методе SecondarySkill::setValue*/
    return
    "QLabel{"
    "   background: none;"
    "   font-size: 28px;"
    "   color: #bdc440;"
    "   margin-bottom: 10px;"
    "}";
}

QString SS_StyleMaster::TooltipTextStyle(int sizePX, QString color)
{
    //Вместо %1 будет вставлен размер шрифта, а вместо %2 - его цвет
    QString style =
    "QLabel{"
    "   background: none;"
    "   font: %1px;"
    "   color: #%2;"
    "}";

    return style.arg(sizePX).arg(color);
}

QString SS_StyleMaster::SeparatorStyle()
{
    return
    "background: url(:/Text-Block-1/Textures PNG/Separator-1.png);"
    "background-repeat: norepeat;"
    "background-position: center;";
}
