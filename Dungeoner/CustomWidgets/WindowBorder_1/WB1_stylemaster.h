/***********************************************************
 *Мастер стилей для WindowBorder_1. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета
 ***********************************************************/

#ifndef WB1_STYLEMASTER_H
#define WB1_STYLEMASTER_H

#include <QWidget>

class WB1_Stylemaster
{
public:
  static QString BottomLeftCornerStyle();
  static QString TopLeftCornerStyle();
  static QString BottomRightCornerStyle();
  static QString TopRightCornerStyle();

  static QString BottomBorderStyle();
  static QString TopBorderStyle();
  static QString LeftBorderStyle();
  static QString RightBorderStyle();
};

#endif // WB1_STYLEMASTER_H
