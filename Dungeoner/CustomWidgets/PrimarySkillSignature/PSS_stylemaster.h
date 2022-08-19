/******************************************************************
 *Мастер стилей для PrimarySkillSignature. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ******************************************************************/

#ifndef PSS_STYLEMASTER_H
#define PSS_STYLEMASTER_H

#include <QString>

class PSS_StyleMaster
{
public:
    static QString CenterTextureStyle();
    static QString topTextureStyle();
    static QString bottomTextureStyle();
    static QString RightTextureStyle();
    static QString LeftTextureStyle();
    static QString TooltipTextStyle(int sizePX);
};

#endif // PSS_STYLEMASTER_H
