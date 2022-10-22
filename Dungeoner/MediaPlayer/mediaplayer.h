/**************************************
 *Данный класс является медиаплеером
 **************************************/

#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>

class MediaPlayer
{
public:
    MediaPlayer();
    ~MediaPlayer();

    //Группы медиаконтента для индивидуальной регулировки громкости
    enum SoundsGroup{
        SOUNDS,
        MUSICS
    };

    /*Проигрывание медиафайла. В него передаётся ссылка на ресурс и энум
     *группы медиафайла для регулировки громкости разных групп.*/
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

    //Общая громкость
    double overallVolume;

    //Громкость разных групп
    double soundsVolume;
    double musicsVolume;

};

#endif // MEDIAPLAYER_H
