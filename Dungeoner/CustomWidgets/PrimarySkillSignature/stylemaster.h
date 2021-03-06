#ifndef STYLEMASTER_H
#define STYLEMASTER_H

/*Мастер стилей для PrimarySkillSignature. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include <QString>

class StyleMaster
{
public:
    static QString CenterTextureStyle();
    static QString topTextureStyle();
    static QString bottomTextureStyle();
    static QString RightTextureStyle();
    static QString LeftTextureStyle();
};

#endif // STYLEMASTER_H
