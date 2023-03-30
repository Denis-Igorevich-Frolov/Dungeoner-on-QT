#include "OB_stylemaster.h"

QString OB_Stylemaster::setRegularStyle()
{
    return
    "#Background{"
    "   background: qlineargradient(spread:pad, x1:0.499764, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 9));"
    "}"
    ""
    "#DecorativeElement{"
    "   border-image: url(:/OpenworkButton/Textures PNG/DecorativeButtonElement.png)  0 0 0 0 stretch stretch;"
    "}";
}
