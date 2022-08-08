/*************************************************************************************
 *Данный класс является наследником QGraphicsEffect и накладывает эффект обводки.
 *Применим ко всему, что имеет метод setGraphicsEffect.
 *
 *Стоит помнить, что этот графический эффект не изменит размер виджета и обводка
 *может не умещаться в отведённый виджету размер. Для того чтобы всё влезло,
 *виджету, которому передаётся эффект, стоит сделать margin равный толщине обводки.
 *************************************************************************************/

#ifndef OUTLINEEFFECT_H
#define OUTLINEEFFECT_H

#include <QGraphicsEffect>

class OutlineEffect : public QGraphicsEffect
{
public:
    explicit OutlineEffect(QGraphicsEffect *parent = nullptr);

    //Переопределение родительской виртуальной функции отрисовки
    void draw(QPainter *painter)override;

    const QColor &getColor() const;
    void setColor(const QColor &newColor);

    int getOutlineThickness() const;
    void setOutlineThickness(int newOutlineThickness);

private:
    QColor color = Qt::black;
    int outlineThickness = 0;
};

#endif // OUTLINEEFFECT_H
