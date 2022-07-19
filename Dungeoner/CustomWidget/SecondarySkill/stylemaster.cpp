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
    return
    "QLabel{"
    "   background: none;"
    "   font-family: 'Old English Text MT';"
    "   color: #bdc440;"
    "   margin-bottom: 10px;"
    "}";
}
