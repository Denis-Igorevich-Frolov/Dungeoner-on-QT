/****************************************************************
 *Мастер стилей для MagicDefenseProgressBar. Хранит Qss,
 *инструкции которые затем будут применены к элементам виджета
 ****************************************************************/

#ifndef MDP_STYLEMASTER_H
#define MDP_STYLEMASTER_H

#include <QString>

class MDP_StyleMaster
{
public:
    static QString TextFontStyle(int sizePX, QString fontName);
};

#endif // MDP_STYLEMASTER_H
