#include "outlineeffect.h"
#include "qbitmap.h"
#include "qpainter.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

OutlineEffect::OutlineEffect(QGraphicsEffect *parent)
    : QGraphicsEffect{parent}
{

}

void OutlineEffect::draw(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPixmap map = sourcePixmap();
    QImage tmp = map.toImage();

    for(int y = 0; y < tmp.height(); y++)
      for(int x= 0; x < tmp.width(); x++){
        color.setAlpha(tmp.pixelColor(x,y).alpha());
        tmp.setPixelColor(x,y,color);
      }

    map = QPixmap::fromImage(tmp);

    painter->drawPixmap(0, 1, map);
    painter->drawPixmap(1, 0, map);
    painter->drawPixmap(1, 1, map);
    painter->drawPixmap(0, -1, map);
    painter->drawPixmap(-1, 0, map);
    painter->drawPixmap(-1, -1, map);

    drawSource(painter);
    painter->end();
}

const QColor &OutlineEffect::getColor() const
{
    return color;
}

void OutlineEffect::setColor(const QColor &newColor)
{
    color = newColor;
}
