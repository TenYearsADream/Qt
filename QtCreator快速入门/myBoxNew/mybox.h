/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/

#ifndef MYBOX_H
#define MYBOX_H

#include <QtGui/QWidget>
#include "gamearea.h"
#include <QMovie>
#include <QStringList>
#include <QKeyEvent>
namespace Ui
{
    class MyBox;
}

class MyBox : public QWidget
{
    Q_OBJECT

public:
    MyBox(QWidget *parent = 0);
    ~MyBox();
    void initAll();
    void initMainWindow();
    void initTheGame();
    void initMainMenu();
    void initMoveSound();
    void set_visible(bool);
    void gameOver();
    void do_Score(int num);
    void do_Score_Sound(int num);
    void paintEvent(QPaintEvent *);
    void changeGameArea();
    void theEndGrade();

    void theEndGrade_init();
    void theEndGrade_rotate();
    void theEndGrade_start();

    void setSoundFile(QString fileName);

private:
    Ui::MyBox *ui;
    GameArea *gameArea;
    QTimer *boxMove_timer;
    QTimer *gameAreaRotate_timer;
    QTimer *mask_timer;
    QTimer *gameAreaFrame_lineWidth_timer;
    QTimer *second_timer;
    int moveSpeed;
    int colorChangeSpeed;

    int alpha;
    int score;
    int grade;
    QPixmap pix_backGround;
    QPixmap pix_mask;
    QPixmap pix_information;
    QMovie *movie;

    QStringList soundList;

    int rotateAngle;
    int maskMax;
    int maskMin;

    bool is_in_endGrade;
    bool isFirstOut_endGrade;
    bool isEndGrade_start;
    bool isEnterEndGrade;
    int gameFrame_lineWidth;
    int the_second;
    int lastSecond;

    bool isFirst2;
    bool isFirst3;
    bool isFirst4;
    bool isFirst5;
    bool isFirst6;

    bool is_in_game;
    void keyPressEvent(QKeyEvent *kk);

    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;

    MyBoxAudio audio;

private slots:
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_downKeyRadioButton_clicked();
    void on_backOptionBtn_clicked();
    void on_setOptionBtn_clicked();
    void on_gameGridRadioButton_clicked();
    void on_gameExitBtn_clicked();
    void on_gameStartBtn_clicked();
    void on_backBtn_clicked();
    void on_pauseBtn_clicked();
    void on_reStartBtn_clicked();
    void boxMove_timer_UpDate();
    void gameAreaRotate_timer_UpDate();
    void mask_timer_UpDate();
    void gameAreaFrame_lineWidth_timer_UpDate();
    void second_timer_UpDate();
    void loopMusic();
};

#endif // MYBOX_H
