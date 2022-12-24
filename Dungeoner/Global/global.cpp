/**************************************************************************
 *Данный класс создан для хранения статических глобальных переменных,
 *например экземпляр медиаплеера или разные энумы.
 **************************************************************************/

#include "global.h"

MediaPlayer Global::mediaplayer;
QVector<int> Global::pressedKeys;
QString Global::DungeonName = "New Dungeon";
int Global::numberOfBackups;

Global::Global()
{

}
