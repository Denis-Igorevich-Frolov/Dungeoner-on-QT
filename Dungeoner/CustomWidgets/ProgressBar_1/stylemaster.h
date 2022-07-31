#ifndef STYLEMASTER_H
#define STYLEMASTER_H

/*Мастер стилей для ProgressBar_1. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include <QString>

class StyleMaster
{
public:
    static QString BordersStyle();
    static QString ShadowStyle();
    static QString TipsStyle();
};

#endif // STYLEMASTER_H
