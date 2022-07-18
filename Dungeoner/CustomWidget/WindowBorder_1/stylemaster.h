#ifndef STYLEMASTER_H
#define STYLEMASTER_H

#include <QWidget>

class stylemaster
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

#endif // STYLEMASTER_H
