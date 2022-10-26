/**********************************************************
 *Мастер стилей для ProgressBar_1. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 **********************************************************/

#ifndef PB1_STYLEMASTER_H
#define PB1_STYLEMASTER_H

#include <QString>

class PB1_StyleMaster
{
public:
    static QString BordersStyle();
    static QString ShadowStyle();
    static QString TipsStyle();
    static QString TooltipTextStyle(int sizePX, QString color);
    static QString SeparatorStyle();
};

#endif // PB1_STYLEMASTER_H
