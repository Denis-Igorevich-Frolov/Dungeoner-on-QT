/***********************************************************
 *Мастер стилей для SecondarySkill. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#ifndef SS_STYLEMASTER_H
#define SS_STYLEMASTER_H

#include <QString>

class SS_StyleMaster
{
public:
    static QString SecondarySkillInscriptionStyle(int size);
    static QString SecondarySkillValueStyle();
    static QString TooltipTextStyle(int sizePX, QString color);
    static QString SeparatorStyle();
};

#endif // SS_STYLEMASTER_H
