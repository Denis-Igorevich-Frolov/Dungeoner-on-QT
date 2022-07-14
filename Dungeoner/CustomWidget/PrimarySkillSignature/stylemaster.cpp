/*
 *Мастер стилей для PrimarySkillSignature. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 */

#include "stylemaster.h"

QString StyleMaster::CenterTextureStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-1-BG.png);"
    "}";
}

QString StyleMaster::topTextureStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-1-T.png);"
    "   border: none;"
    "}"
    ""
    "QPushButton::hover{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-Hovered-1-T.png);"
    "   border: none;"
    "}"
    ""
    "QPushButton::pressed{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-Pressed-1-T.png);"
    "   border: none;"
    "}";
}

QString StyleMaster::bottomTextureStyle()
{
    return
    "QPushButton{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-1-B.png);"
    "   border: none;"
    "}"
    ""
    "QPushButton::hover{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-Hovered-1-B.png);"
    "   border: none;"
    "}"
    ""
    "QPushButton::pressed{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-Pressed-1-B.png);"
    "   border: none;"
    "}";
}

QString StyleMaster::RightTextureStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-1-R.png);"
    "}";
}

QString StyleMaster::LeftTextureStyle()
{
    return
    "QLabel{"
    "   background: none;"
    "   background-image: url(:/Text-Block-1/Textures PNG/Text-Block-1-L.png);"
    "}";
}
