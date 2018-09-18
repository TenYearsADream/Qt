/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
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

    backgroundMusic = new Phonon::MediaObject(this);  //��������
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

void Widget::on_gameStartBtn_clicked() //��Ϸ��ʼ
{
    gameTimer->stop();
    score = 0;
    ui->lcdNumber->display(score);
    boxArea->setFocus();
    boxArea->gameStart();
    gameTimer->start(500);
    backgroundMusic->play();  //���ű�������
}

void Widget::on_gamePauseBtn_clicked(bool checked) //��Ϸ��ͣ
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

void Widget::on_exitBtn_clicked()   //�˳���Ϸ
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



void Widget::on_boxAudioVolumeSlider_valueChanged(int value)  //��Ч����
{
    qreal volume = value / 100.0;
    MyBoxAudio audio;
    audio.setVolume(volume);
    boxArea->setFocus();
}

void Widget::on_backgroundAudioVolumeSlider_2_valueChanged(int value) //��������
{
    qreal volume = value / 100.0;
    backgroundMusicAudioOutput->setVolume(volume);
    boxArea->setFocus();
}

void Widget::replayBackGroundMusic()
{
    backgroundMusic->enqueue(backgroundMusic->currentSource());  //���²��ŵ�ǰ����
}
