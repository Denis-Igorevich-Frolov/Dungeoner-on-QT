/**************************************************************************
 *Данный класс создан для хранения статических глобальных переменных,
 *например экземпляр медиаплеера или разные энумы.
 **************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include "MediaPlayer/mediaplayer.h"

#include <QFont>

class Global
{
public:
    static MediaPlayer mediaplayer;

    enum PhysicalDamageScaling{
        STRENGTH,
        AGILITY,
        MAGIC
    };

    /*Массив нажатых клавиш, среди которых только Ctrl, Shift и Alt, они будут считаться
     *в виджетах модификаторами нажатия. Вектор статический и неконстантный, чтобы любой
     *виджет мог легко его получить и редактировать. Данный вектор общий для всего приложения,
     *а располагается он именно в глобальном классе для гарантии того, что при первом нажатии,
     *когда ещё никакой элемент интерфейса не в фокусе, вектор уже мог быть проинициализирован
     *зажатой клавишей. Возможность редактирования вектора в любом классе разрешена для того,
     *чтобы при дополнительном нажатии или отжатии клавиши, когда в фокусе уже другой элемент,
     *не тот из которого было вызвано предыдущее нажатие, он всё-равно обновлял бы этот вектор
     *как и должен. По этой причине любой виджет или окно, которые используют эти модификаторы
     *нажатия должны иметь переопределения виртуальных функций keyPressEvent и keyReleaseEvent.*/
    static QVector<int> pressedKeys;

    static QString DungeonName;
    static int numberOfBackups;

    Global();
};

#endif // GLOBAL_H
