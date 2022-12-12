/*************************************************************************************
 *Данный класс является наследником QGraphicsEffect и накладывает эффект обводки.
 *Применим ко всему, что имеет метод setGraphicsEffect.
 *
 *Стоит помнить, что этот графический эффект не изменит размер виджета и обводка
 *может не умещаться в отведённый виджету размер. Для того чтобы всё влезло,
 *виджету, которому передаётся эффект, стоит сделать margin равный толщине обводки.
 *************************************************************************************/

#include "outlineeffect.h"
#include "qpainter.h"

OutlineEffect::OutlineEffect(QGraphicsEffect *parent)
    : QGraphicsEffect{parent}
{

}

//Переопределение родительской виртуальной функции отрисовки
void OutlineEffect::draw(QPainter *painter)
{
    //Так как работа идёт уже с QPixmap антиалайзинг должен быть обычным, а не TextAntialiasing
    painter->setRenderHint(QPainter::Antialiasing);

    //Если толщина обводки нулевая, то и смысла гонять эти циклы нет
    if(outlineThickness > 0){
        //Перекрашивание дубликата изображения в переданый цвет
        QPixmap outline = sourcePixmap();
        QPainter repaintingPainter(&outline);
        repaintingPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        repaintingPainter.fillRect(outline.rect(), color);
        repaintingPainter.end();

        /*После перекрашивания получается дубликат исходного изображения, залитый цветом обводки.
         *Теперь из него можно сделать непосредственно обводку. Масштабировать этот дубликат для
         *такой задачи абсолютно не вариант, так как при увеличении масштаба увеличатся и общие
         *пропорции текста включая расстояние можду буквами. А если это рассояние не совпадает с
         *интервалом исходного текста, то очень быстро такая обводка станет неотцентрированной для
         *каждой отдельно взятой буквы и в конечном итоге вообще съедет, и чем больше исходный
         *текст, тем сильнее будет эффект.
         *
         *Вместо этого следует поступить в стиле импровизированной CSS обводки, которая делается
         *множеством теней с разным смещением. Так как в Qt каждый новый QGraphicsEffect
         *перезаписывает предыдущий, сделать множество теней простыми методами не получится. Так
         *что окрашенный дубликат sourcePixmap() здесь выступает в роли такой "тени". Его следует
         *отрисовать в каждой позиции заданного смещения.*/
        for(int i = 0; i<=outlineThickness; i++){
            for(int j = 0; j<=outlineThickness; j++){
                if(i!=0||j!=0){
                    painter->drawPixmap(i, j, outline);
                    painter->drawPixmap(-i, j, outline);
                    painter->drawPixmap(i, -j, outline);
                    painter->drawPixmap(-i, -j, outline);
                }
            }
        }
    }

    //По окончинии отрисовки обводки отрисовываем исходное изображение
    drawSource(painter);
}

const QColor &OutlineEffect::getColor() const
{
    return color;
}

void OutlineEffect::setColor(const QColor &newColor)
{
    color = newColor;
}

int OutlineEffect::getOutlineThickness() const
{
    return outlineThickness;
}

void OutlineEffect::setOutlineThickness(int newOutlineThickness)
{
    outlineThickness = newOutlineThickness;
}
