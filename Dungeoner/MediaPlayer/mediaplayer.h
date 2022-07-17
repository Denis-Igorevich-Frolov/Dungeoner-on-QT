#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>

class MediaPlayer
{
public:
    MediaPlayer();
    ~MediaPlayer();

    enum SoundsGroup{
        SOUNDS,
        MUSICS
    };

    void playSound(QUrl url, enum SoundsGroup);


    int getOverallVolume() const;
    void setOverallVolume(int newOverallVolume);

    int getSoundsVolume() const;
    void setSoundsVolume(int newSoundsVolume);

    int getMusicsVolume() const;
    void setMusicsVolume(int newMusicsVolume);

    QMediaPlayer *getPlayer() const;
    void setPlayer(QMediaPlayer *newPlayer);

    QAudioOutput *getAudioOutput() const;
    void setAudioOutput(QAudioOutput *newAudioOutput);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    int overallVolume;
    int soundsVolume;
    int musicsVolume;

};

#endif // MEDIAPLAYER_H
