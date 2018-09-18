/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/



#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myboxarea.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;
    MyBoxArea *boxArea;
    QTimer *gameTimer;
    double score;
    Phonon::MediaObject *backgroundMusic;
    Phonon::AudioOutput *backgroundMusicAudioOutput;
    MyBoxAudio clearRowAudio;

private slots:

    void on_backgroundAudioVolumeSlider_2_valueChanged(int value);
    void on_boxAudioVolumeSlider_valueChanged(int value);
    void on_gamePauseBtn_clicked(bool checked);
    void on_exitBtn_clicked();
    void on_gameStartBtn_clicked();

    void theGameOver();
    void displayScore(int);
    void replayBackGroundMusic();
};

#endif // WIDGET_H
