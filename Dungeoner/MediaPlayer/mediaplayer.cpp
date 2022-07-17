#include "mediaplayer.h"

/*Данный класс является медиаплеером*/

MediaPlayer::MediaPlayer()
{
    //Значения по умолчанию
    overallVolume = 1;
    soundsVolume = 1;
    musicsVolume = 1;


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
 *группы медиафайла для контроля громкости разных груп.*/
void MediaPlayer::playSound(QUrl url, enum SoundsGroup)
{
    double volume;
    if(SoundsGroup::SOUNDS){
        volume = soundsVolume * overallVolume;
    } else if(SoundsGroup::MUSICS){
        volume = musicsVolume * overallVolume;
    }
    audioOutput->setVolume(volume);
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

