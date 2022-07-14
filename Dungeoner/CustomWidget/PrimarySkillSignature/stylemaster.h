#ifndef STYLEMASTER_H
#define STYLEMASTER_H

/*
 *Мастер стилей для PrimarySkillSignature. Устанавливает
 *QSS стили для всех эллементов.
 */

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
