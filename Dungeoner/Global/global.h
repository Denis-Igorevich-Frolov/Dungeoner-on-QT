#ifndef GLOBAL_H
#define GLOBAL_H

/*Данный класс создан для хранения статических глобальных переменных, например экземпляр медиаплеера*/

#include "MediaPlayer/mediaplayer.h"

class Global
{
public:
    static MediaPlayer mediaplaer;

    Global();
};

#endif // GLOBAL_H
