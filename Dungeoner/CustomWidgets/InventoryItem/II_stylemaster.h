#ifndef II_STYLEMASTER_H
#define II_STYLEMASTER_H

#include <QString>

class II_stylemaster
{
public:
    static QString emptyBorderStyle();
    static QString notEmptyBorderStyle();
    static QString disabledNotEmptyBorderStyle();
    static QString notEmptyBGStyle();
    static QString disabledNotEmptyBGStyle();
    static QString centralElementStyle();
    static QString lockedStyle();
    static QString dropdownButtonEmptyStyle();
    static QString dropdownButtonNotEmptyStyle();
    static QString dropdownButtonDisabledNotEmptyStyle();
};

#endif // II_STYLEMASTER_H
