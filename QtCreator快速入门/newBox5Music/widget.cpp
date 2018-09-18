/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/


#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(600,450);
    boxArea = new MyBoxArea(ui->frame);
    boxArea->move(30,5);

    boxArea->show();
    gameTimer = new QTimer;
    connect(gameTimer,SIGNAL(timeout()),boxArea,SLOT(boxMoveOneStepDown()));

    backgroundMusic = new Phonon::MediaObject(this);  //背景音乐
    backgroundMusicAudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    Phonon::createPath(backgroundMusic,backgroundMusicAudioOutput);
    backgroundMusic->setCurrentSource(Phonon::MediaSource("01.mp3"));
    connect(backgroundMusic,SIGNAL(aboutToFinish()),
            this,SLOT(replayBackGroundMusic()));

    clearRowAudio = MyBoxAudio("good.wav");

    connect(boxArea,SIGNAL(gameOver()),this,SLOT(theGameOver()));
    connect(boxArea,SIGNAL(fullRowNumChange(int)),this,SLOT(displayScore(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::on_gameStartBtn_clicked() //游戏开始
{
    gameTimer->stop();
    score = 0;
    ui->lcdNumber->display(score);
    boxArea->setFocus();
    boxArea->gameStart();
    gameTimer->start(500);
    backgroundMusic->play();  //播放背景音乐
}

void Widget::on_gamePauseBtn_clicked(bool checked) //游戏暂停
{
    if(checked)
    {
        gameTimer->stop();
        boxArea->clearFocus();
    }
    else
    {
        gameTimer->start(500);
        boxArea->setFocus();
    }
}

void Widget::on_exitBtn_clicked()   //退出游戏
{
    QWidget::close();
}

void Widget::theGameOver()
{
    on_gameStartBtn_clicked();
}

void Widget::displayScore(int num)
{

    clearRowAudio.play();
    score += num*100;
    ui->lcdNumber->display(score);
}



void Widget::on_boxAudioVolumeSlider_valueChanged(int value)  //音效音量
{
    qreal volume = value / 100.0;
    MyBoxAudio audio;
    audio.setVolume(volume);
    boxArea->setFocus();
}

void Widget::on_backgroundAudioVolumeSlider_2_valueChanged(int value) //音乐音量
{
    qreal volume = value / 100.0;
    backgroundMusicAudioOutput->setVolume(volume);
    boxArea->setFocus();
}

void Widget::replayBackGroundMusic()
{
    backgroundMusic->enqueue(backgroundMusic->currentSource());  //重新播放当前音乐
}
