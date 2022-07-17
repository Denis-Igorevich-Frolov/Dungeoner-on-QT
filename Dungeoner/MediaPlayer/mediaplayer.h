#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

/*Данный класс является медиаплеером*/

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

    /*Проигрывание медиафайла. В него передаётся ссылка на ресурс и энум
     *группы медиафайла для контроля громкости разных груп.*/
    void playSound(QUrl url, enum SoundsGroup);

    double getOverallVolume() const;
    void setOverallVolume(double newOverallVolume);

    double getSoundsVolume() const;
    void setSoundsVolume(double newSoundsVolume);

    double getMusicsVolume() const;
    void setMusicsVolume(double newMusicsVolume);

    QMediaPlayer *getPlayer() const;
    void setPlayer(QMediaPlayer *newPlayer);

    QAudioOutput *getAudioOutput() const;
    void setAudioOutput(QAudioOutput *newAudioOutput);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    double overallVolume;
    double soundsVolume;
    double musicsVolume;

};

#endif // MEDIAPLAYER_H
