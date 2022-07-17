#include "mediaplayer.h"

MediaPlayer::MediaPlayer()
{
    overallVolume = 1;
    soundsVolume = 50;
    musicsVolume = 50;


    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
}

MediaPlayer::~MediaPlayer()
{
    delete player;
    delete audioOutput;
}

void MediaPlayer::playSound(QUrl url, enum SoundsGroup)
{
    int volume;
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

int MediaPlayer::getOverallVolume() const
{
    return overallVolume;
}

void MediaPlayer::setOverallVolume(int newOverallVolume)
{
    overallVolume = newOverallVolume;
}

int MediaPlayer::getSoundsVolume() const
{
    return soundsVolume;
}

void MediaPlayer::setSoundsVolume(int newSoundsVolume)
{
    soundsVolume = newSoundsVolume;
}

int MediaPlayer::getMusicsVolume() const
{
    return musicsVolume;
}

void MediaPlayer::setMusicsVolume(int newMusicsVolume)
{
    musicsVolume = newMusicsVolume;
}

