/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
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
