/************************************************************
 *Мастер стилей для InventoryCell. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ************************************************************/

#ifndef IC_STYLEMASTER_H
#define IC_STYLEMASTER_H

#include <QString>

class IC_stylemaster
{
public:
    static QString emptyBorderStyle();
    static QString notEmptyBorderStyle();
    static QString disabledNotEmptyBorderStyle();
    static QString lockedBorderStyle();
    static QString notEmptyBGStyle();
    static QString disabledNotEmptyBGStyle();
    static QString brokenNotEmptyBGStyle();
    static QString disabledBrokenNotEmptyBGStyle();
    static QString centralElementStyle();
    static QString lockedStyle();
    static QString blockedStyle();
    static QString dropdownButtonEmptyStyle();
    static QString dropdownButtonNotEmptyStyle();
    static QString dropdownButtonDisabledNotEmptyStyle();
    static QString dropdownButtonLockedStyle();
};

#endif // IC_STYLEMASTER_H
