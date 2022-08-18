/******************************************************************************************************
 *Данный класс создан для хранения статических глобальных переменных, например экземпляр медиаплеера
 ******************************************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include "MediaPlayer/mediaplayer.h"

class Global
{
public:
    static MediaPlayer mediaplayer;

    enum PhysicalDamageScaling{
        STRENGTH,
        AGILITY,
        MAGIC
    };

    Global();
};

#endif // GLOBAL_H
