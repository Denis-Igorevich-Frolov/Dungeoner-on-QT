#ifndef STYLEMASTER_H
#define STYLEMASTER_H

#include <QString>


class StyleMaster
{
public:
    static QString CenterTextureStyle();
    static QString topTextureStyle();
    static QString bottomTextureStyle();
    static QString RightTextureStyle();
    static QString LeftTextureStyle();
    static QString TextFontStyle(int size);
};

#endif // STYLEMASTER_H
