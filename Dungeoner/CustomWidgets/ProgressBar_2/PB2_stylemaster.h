/**********************************************************
 *Мастер стилей для ProgressBar_2. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 **********************************************************/

#ifndef PB2_STYLEMASTER_H
#define PB2_STYLEMASTER_H

#include <QString>

class PB2_StyleMaster
{
public:
    static QString BordersStyle();
    static QString ShadowStyle();
    static QString TipsStyle();
    static QString SeparatorStyle();
};

#endif // PB2_STYLEMASTER_H
