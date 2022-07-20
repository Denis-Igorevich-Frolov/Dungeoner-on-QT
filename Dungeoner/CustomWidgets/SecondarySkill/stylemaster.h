#ifndef STYLEMASTER_H
#define STYLEMASTER_H

/*Мастер стилей для SecondarySkill. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include <QString>

class StyleMaster
{
public:
    static QString SecondarySkillInscriptionStyle(int size);
    static QString SecondarySkillValueStyle();
};

#endif // STYLEMASTER_H
