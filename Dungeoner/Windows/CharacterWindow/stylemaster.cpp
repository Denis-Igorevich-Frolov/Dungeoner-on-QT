/*Мастер стилей для CharacterWindow. Хранит Qss инструкции,
 *которые затем будут применены к элементам виджета*/

#include "stylemaster.h"

QString StyleMaster::SpinBoxStyle(int sizePX)
{
    QString style =
    "QSpinBox::up-button{"
    "     width: 0px;"
    "    height: 0px;"
    "}"
    ""
    "QSpinBox::down-button{"
    "     width: 0px;"
    "    height: 0px;"
    "}"
    ""
    "QSpinBox{"
    "   border: none;"
    "   background: #130a0f;"
    "   font: %1px 'Old English Text MT';"
    "   color: #bdc440;"
    "}";
    return style.arg(sizePX);
}

QString StyleMaster::VerticalScrollBarStyle()
{
    /*У QScrollBar background-color задан как rgba(0, 0, 0, 0) не просто так. Если этого
     *не сделать, то тело скроллбара юудет иметь цвет виджета по умолчанию, то есть серый.
     *background: none эту проблему не решает из-за каких-то вложенностей и не уноследования
     *этого свойства под капотом виджеа скроллбара.
     *
     *Без margin сверху и снизу (в данном случае 26 пикселей) у QScrollBar, стрелки, при
     *увеличении своей высоты, будут налазить на тело скроллбара. И как раз высота в margin
     *не просто так равна 26 пикселям, когда как у самих стрелок она равна 33 пикселям.
     *Сделано это для того, чтобы текстура кнопки чуть-чуть налезла на тело скроллбара,
     *и этот нахлёст, в свою очередь, просто часть дизайна.*/
    return
    "QScrollBar:vertical {"
    "    margin: 26px 0px 26px 0px;"
    "    background-color: rgba(0, 0, 0, 0);"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Body.png);"
    "    background-position: center;"
    "    background-repeat: repeat-y;"
    "    border:none;"
    "    width: 24px;"
    "}"
    ""
    "QScrollBar::handle:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Button.png);"
    "    background-position: center;"
    "    background-repeat: no-repeat;"
    "    min-height: 49px;"
    "    max-height: 49px;"
    "}"
    ""
    "QScrollBar::handle::hover:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Button-Hovered.png);"
    "}"
    ""
    "QScrollBar::handle::pressed:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Button-Pressed.png);"
    "}"
    ""
    "QScrollBar::add-page:vertical {"
    "    background-color: none;"
    "}"
    ""
    "QScrollBar::sub-page:vertical {"
    "    background-color: none;"
    "}"
    ""
    "QScrollBar::sub-line:vertical, QScrollBar::add-line:vertical  {"
    "    subcontrol-origin: margin;"
    "    border: none;"
    "    height: 33px;"
    "}"
    ""
    "QScrollBar::up-arrow:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-T.png);"
    "    height:33px;"
    "}"
    ""
    "QScrollBar::up-arrow::hover:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-Hovered-T.png);"
    "}"
    ""
    "QScrollBar::up-arrow::pressed:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-Pressed-T.png);"
    "}"
    ""
    "QScrollBar::down-arrow:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-B.png);"
    "    height:33px;"
    "}"
    ""
    "QScrollBar::down-arrow::hover:vertical { "
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-Hovered-B.png);"
    "}"
    ""
    "QScrollBar::down-arrow::pressed:vertical {"
    "    background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-Pressed-B.png);"
    "}";
}
