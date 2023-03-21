/**************************************
 *Данный класс является медиаплеером
 **************************************/

#include "mediaplayer.h"

MediaPlayer::MediaPlayer()
{
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
}

MediaPlayer::~MediaPlayer()
{
    delete player;
    delete audioOutput;
}

/*Проигрывание медиафайла. В него передаётся ссылка на ресурс и энум
 *группы медиафайла для регулировки громкости разных груп.*/
void MediaPlayer::playSound(QUrl url, SoundsGroup group)
{
    double volume = 0;

    if(group == SoundsGroup::SOUNDS){
        volume = soundsVolume * overallVolume;
    } else if(group == SoundsGroup::MUSICS){
        volume = musicsVolume * overallVolume;
    } else if(group == SoundsGroup::DRAG_AND_DROP){
        if(playDragAndDropSound)
            volume = soundsVolume * overallVolume * 0.1;
        else volume = 0;
    }

    /*Если громкость равна нулю, то и смысла дальше что-то делать нет. R тому же в Qt
     *воспроизведение звука с нулевой громкостью сопровождается едва слышимыми щелчками*/
    if(volume == 0)
        return;

    audioOutput->setVolume(volume);
    player->setAudioOutput(audioOutput);
    player->setSource(url);
    player->play();
}

QMediaPlayer *MediaPlayer::getPlayer() const
{
    return player;
}

void MediaPlayer::setPlayer(QMediaPlayer *newPlayer)
{
    player = newPlayer;
}

QAudioOutput *MediaPlayer::getAudioOutput() const
{
    return audioOutput;
}

void MediaPlayer::setAudioOutput(QAudioOutput *newAudioOutput)
{
    audioOutput = newAudioOutput;
}

double MediaPlayer::getOverallVolume() const
{
    return overallVolume;
}

void MediaPlayer::setOverallVolume(double newOverallVolume)
{
    overallVolume = newOverallVolume;
}

double MediaPlayer::getSoundsVolume() const
{
    return soundsVolume;
}

void MediaPlayer::setSoundsVolume(double newSoundsVolume)
{
    soundsVolume = newSoundsVolume;
}

double MediaPlayer::getMusicsVolume() const
{
    return musicsVolume;
}

void MediaPlayer::setMusicsVolume(double newMusicsVolume)
{
    musicsVolume = newMusicsVolume;
}

