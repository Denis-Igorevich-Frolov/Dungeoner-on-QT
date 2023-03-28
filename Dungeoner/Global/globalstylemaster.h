#ifndef GLOBALSTYLEMASTER_H
#define GLOBALSTYLEMASTER_H

#include <QString>



class GlobalStyleMaster
{
public:
    static QString VerticalScrollBarStyle();
    static QString TooltipTextStyle(int sizePX, QString color);
};

#endif // GLOBALSTYLEMASTER_H
