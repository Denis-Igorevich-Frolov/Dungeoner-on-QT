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
        MUSICS,
        DRAG_AND_DROP
    };

    /*Проигрывание медиафайла. В него передаётся ссылка на ресурс и энум
     *группы медиафайла для регулировки громкости разных групп.*/
    void playSound(QUrl url, SoundsGroup group);

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

    bool playDragAndDropSound = true;

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    //Общая громкость
    double overallVolume = 1;

    //Громкость разных групп
    double soundsVolume = 1;
    double musicsVolume = 1;
};

#endif // MEDIAPLAYER_H
