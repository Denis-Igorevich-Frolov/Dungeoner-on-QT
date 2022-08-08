/***********************************************************
 *Мастер стилей для SecondarySkill. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#include "stylemaster.h"

QString StyleMaster::SecondarySkillInscriptionStyle(int size)
{
    QString style =
    "QLabel{"
    "   background: none;"
    "   font-family: 'Algerian';"
    "   font-size: %1px;"
    "   color: #bdc440;"
    "}";
    return style.arg(size);
}

QString StyleMaster::SecondarySkillValueStyle()
{
    /*Этот margin-bottom тут для компинсации размера при изменения межстрочного интервала.
     *Подробнее в методе SecondarySkill::setValue*/
    return
    "QLabel{"
    "   background: none;"
    "   font-family: 'Old English Text MT';"
    "   color: #bdc440;"
    "   margin-bottom: 10px;"
    "}";
}
