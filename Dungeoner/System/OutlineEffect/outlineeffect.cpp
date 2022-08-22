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
    //Так как работа идёт уже с QImage антиалайзинг должен быть обычным, а не TextAntialiasing
    painter->setRenderHint(QPainter::Antialiasing);

    //Если толщина обводки нулевая, то и смысла гонять эти цыклы нет
    if(outlineThickness > 0){
        /*Создание QImage на основе sourcePixmap необходимо для перекраски полученного изображения
         *в цвет обводки функцией setPixelColor. Тоже самое можно сделать и при помощи QPixmap с
         *QBitmap маской, что скорее всего будет более выгодно по затрачиваемым ресурсам, но
         *полученная обводка будет очень пиксельной. И так как это просто маска, антиалайзинг не
         *будет её сглаживать.*/
        QImage outline (sourcePixmap().toImage());

        //Перекраска всех пикселей QImage outline в цвет обводки
        for(int y = 0; y < outline.height(); y++)
            for(int x= 0; x < outline.width(); x++){
                /*Для сохранения прозрачности изображения цвету задаётся
                 *альфа перекрашиваемого пикселя*/
                color.setAlpha(outline.pixelColor(x,y).alpha());
                outline.setPixelColor(x, y, color);
            }

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
        for(int i = 0; i<outlineThickness; i++){
            for(int j = 0; j<=outlineThickness; j++){
                painter->drawImage(i, j, outline);

                if(i!=0&&j!=0){
                    painter->drawImage(-i, j, outline);
                    painter->drawImage(i, -j, outline);
                    painter->drawImage(-i, -j, outline);

                    painter->drawImage(j, i, outline);
                    painter->drawImage(-j, i, outline);
                    painter->drawImage(j, -i, outline);
                    painter->drawImage(-j, -i, outline);
                }

                if(i!=0){
                    painter->drawImage(i, i, outline);
                    painter->drawImage(-i, i, outline);
                    painter->drawImage(i, -i, outline);
                }

                if(i!=0){
                    painter->drawImage(j, j, outline);
                    painter->drawImage(-j, j, outline);
                    painter->drawImage(j, -j, outline);
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
