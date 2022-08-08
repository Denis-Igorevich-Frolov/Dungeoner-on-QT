#ifndef OUTLINEEFFECT_H
#define OUTLINEEFFECT_H

#include <QGraphicsEffect>

class OutlineEffect : public QGraphicsEffect
{
public:
    explicit OutlineEffect(QGraphicsEffect *parent = nullptr);

    void draw(QPainter *painter)override;

    const QColor &getColor() const;
    void setColor(const QColor &newColor);

private:
    QColor color = Qt::black;
};

#endif // OUTLINEEFFECT_H
