/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/

//该类实现对游戏的控制和产生各种效果

#include "mybox.h"
#include "ui_mybox.h"
#include <QSound>
#include <QTimer>
#include <QPainter>
#include <QMessageBox>
#include <QFile>


MyBox::MyBox(QWidget *parent)
    : QWidget(parent), ui(new Ui::MyBox)
{
    ui->setupUi(this);
    this->mediaObject = new Phonon::MediaObject(this);
    this->audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    Phonon::createPath(mediaObject,audioOutput);
    connect(mediaObject,SIGNAL(aboutToFinish()),this,SLOT(loopMusic()));
    this->initAll();
}

MyBox::~MyBox()
{
    delete ui;
}

void MyBox::initAll()
{
    this->boxMove_timer = new QTimer(this);
    connect(boxMove_timer,SIGNAL(timeout()),this,SLOT(boxMove_timer_UpDate()));

    this->gameAreaRotate_timer = new QTimer(this);
    connect(gameAreaRotate_timer,SIGNAL(timeout()),this,SLOT(gameAreaRotate_timer_UpDate()));
    this->rotateAngle = 0;

    this->mask_timer = new QTimer(this);
    connect(mask_timer,SIGNAL(timeout()),this,SLOT(mask_timer_UpDate()));

    this->gameAreaFrame_lineWidth_timer = new QTimer(this);
    connect(gameAreaFrame_lineWidth_timer,SIGNAL(timeout()),this,SLOT(gameAreaFrame_lineWidth_timer_UpDate()));

    this->second_timer = new QTimer(this);
    connect(second_timer,SIGNAL(timeout()),this,SLOT(second_timer_UpDate()));
    this->the_second = 0;
    this->lastSecond = 600;

    this->gameArea = new GameArea(this->ui->gameFrame);
    this->pix_backGround = QPixmap(800,500);
    this->pix_mask = QPixmap(800,500);
    this->pix_information =QPixmap(800,500);

    this->ui->maskWidget->setVisible(false);

    this->initMainWindow();
    this->initMainMenu();
}

void MyBox::initMainWindow()
{
    this->setMaximumSize(800,500);
    this->setMinimumSize(800,500);
    this->ui->gameFrame->resize(400,430);
    this->ui->gameFrame->move(100,60);
    this->ui->gameFrame->setFrameShape(QFrame::Panel);
    this->ui->gameFrame->setFrameShadow(QFrame::Sunken);
    this->gameFrame_lineWidth = 30;

    this->ui->MainMenuWidget->resize(500,500);
    this->ui->MainMenuWidget->move(150,0);
    this->ui->optionFrame->resize(500,500);
    this->ui->optionFrame->move(150,0);
    this->ui->gradeWidget->resize(580,50);
    this->ui->gradeWidget->move(10,5);

    this->gameArea->init_Game();   
    this->initMoveSound();

    this->ui->optionFrame->setVisible(false);

    this->ui->gameGridRadioButton->setChecked(true);
    this->ui->downKeyRadioButton->setChecked(true);

    this->moveSpeed = 500;
    this->colorChangeSpeed =80;


    this->maskMax = 255;
    this->maskMin =0;

    this->is_in_endGrade = false;
    this->isFirstOut_endGrade = false;
    this->isEndGrade_start = false;
    this->isEnterEndGrade = false;

    this->alpha = 255;

    movie = new QMovie(":/new/prefix1/images/fire.gif");
    this->ui->gradeLabel_1->setMovie(movie);
    this->ui->gradeLabel_2->setMovie(movie);
    this->ui->gradeLabel_3->setMovie(movie);
    this->ui->gradeLabel_4->setMovie(movie);
    this->ui->gradeLabel_5->setMovie(movie);
    movie->start();
    this->gameArea->setRotate(false);
    this->gameAreaRotate_timer->stop();


    this->soundList << "sound/00.wav"<< "sound/01.wav" <<"sound/02.wav" <<"sound/03.wav" <<"sound/04.wav" <<"sound/05.wav" <<"sound/06.wav";

    this->gameArea->setRotate(false);
    this->gameAreaRotate_timer->stop();
}

void MyBox::initMainMenu()  //初始化主菜单，每次返回主菜单时都要调用该函数
{
    this->is_in_game = false;
    this->setSoundFile(soundList.at(0));

    this->pix_backGround.load(":/new/prefix1/images/00.jpg");
    this->set_visible(false);

    this->ui->MainMenuWidget->setVisible(true);
    this->is_in_endGrade = false;
    this->isEndGrade_start = false;

    this->update();
}

void MyBox::initTheGame() //第一次进行游戏时进行初始化，每次重新开始游戏，都要调用该函数
{
    this->is_in_game = true;

    this->ui->gameFrame->resize(400,430);
    this->ui->gameFrame->move(100,60);
    this->gameArea->setGameAreaPix(10,10);
    this->gameArea->setGameAreaPixOrigin(0,0);

    this->moveSpeed = 500;
    this->set_visible(true);
    this->score = 0;

    this->ui->scoreLabel->setText(tr("你的得分是：%1").arg(score));


    this->ui->gradeLabel_1->setVisible(true);
    this->ui->gradeLabel_2->setVisible(false);
    this->ui->gradeLabel_3->setVisible(false);
    this->ui->gradeLabel_4->setVisible(false);
    this->ui->gradeLabel_5->setVisible(false);
    QPalette palette;
    palette.setColor(QPalette::Foreground,QColor(255,255,255,100));
    this->ui->gradeLabel_11->setPalette(palette);
    this->ui->gradeLabel_21->setPalette(palette);
    this->ui->gradeLabel_31->setPalette(palette);
    this->ui->gradeLabel_41->setPalette(palette);
    this->ui->gradeLabel_51->setPalette(palette);


    this->gameArea->setDrawNextItem(true);
    this->gameArea->setDrawGrid(true);
    this->movie->start();

    this->gameArea->setRotate(false);
    this->gameAreaRotate_timer->stop();

    this->is_in_endGrade = false;
    this->isFirstOut_endGrade = false;
    this->isEndGrade_start = false;
    this->isEnterEndGrade = false;
    this->maskMax = 255;
    this->maskMin =-500;

    this->isFirst2 = true; //等级改变时，标记是不是第一次更改游戏环境
    this->isFirst3 = true;
    this->isFirst4 = true;
    this->isFirst5 = true;
    this->isFirst6 = true;

    this->grade = 1;
    this->changeGameArea();
}

void MyBox::initMoveSound() //初始化方块移动的声音
{
    this->gameArea->setPlaySound_moveLeft("sound/moveLeft.wav",true);
    this->gameArea->setPlaySound_moveRight("sound/moveLeft.wav",true);
    this->gameArea->setPlaySound_moveDown("sound/moveDown.wav",true);
    this->gameArea->setPlaySound_itemChange("sound/changeItem.wav",true);
    this->audio = MyBoxAudio("sound/good.wav");
}

void MyBox::paintEvent(QPaintEvent *) //窗口重绘事件，完成界面的显示
{
    QPainter painter(this);
    this->ui->gameFrame->setLineWidth(this->gameFrame_lineWidth);

    painter.drawPixmap(0,0,800,500,this->pix_backGround);
    //这个必须写在前面,不然出不来效果
    if(this->is_in_endGrade)  //最后一关的显示
    {
        this->pix_mask.fill(QColor(255,255,255,this->maskMax));
        painter.drawPixmap(0,0,800,500,this->pix_mask);

        QFont font;
        font.setPointSize(30);

        painter.setFont(font);

        painter.drawText(40,120,tr("你的得分是："));
        painter.drawText(40,240,tr("剩余秒数："));
        painter.drawText(130,40,tr("你的目标分数是300分"));


        painter.drawText(40,160,tr("%1").arg(score));
        font.setPointSize(50);
        painter.drawText(40,290,tr("%1").arg(lastSecond));

        QRadialGradient radialGradient(750,250,50,750,250);
        radialGradient.setColorAt(0,QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%255));
        radialGradient.setColorAt(0.5,QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%255));
        radialGradient.setColorAt(1,QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%255));
        painter.setPen(QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%255));
        painter.setBrush(radialGradient);
        painter.drawEllipse(700,200,100,100);

        this->gameArea->setBoxBrushColor(QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%255));
        this->gameArea->setBoxPenColor(QColor(255,255,255,100));
        this->gameArea->draw_gameArea();

    }
    else if(this->is_in_game&&this->grade<=5) //前五关的显示
    {
        this->pix_mask.fill(QColor(255,255,255,0));
        painter.drawPixmap(0,0,800,500,this->pix_mask);

        QLinearGradient linearGradient(0,60,100,440);
        linearGradient.setColorAt(0,QColor(255,255,255,100));
        linearGradient.setColorAt(0.5,QColor(255,255,255,qrand()%255));
        linearGradient.setColorAt(1,QColor(255,255,255,100));
        painter.setBrush(linearGradient);
        painter.drawRect(0,60,100,440);
        QFont font;
        font.setPointSize(50);

        painter.setFont(font);

        painter.drawText(10,150,tr("第"));
        painter.drawText(30,250,tr("%1").arg(grade));
        painter.drawText(10,350,tr("幕"));

    }
    else  //显示主菜单时的显示
    {
        this->pix_mask.fill(QColor(255,255,255,0));
        painter.drawPixmap(0,0,800,500,this->pix_mask);
    }


    if(this->isFirstOut_endGrade)  //第一次从第五关退出时显示
    {
        if(this->the_second<8)
        {
           if(this->maskMin<0)    //遮罩从无到有
           {
               this->ui->maskWidget->resize(800,500);
               this->ui->maskWidget->move(0,maskMin);

           }
           else //在白色遮罩上显示汉字
           {
               this->ui->maskWidget->setVisible(false);
                this->ui->gameFrame->setVisible(false);
                this->ui->backBtn->setVisible(false);
                this->ui->reStartBtn->setVisible(false);
                this->ui->pauseBtn->setVisible(false);
                this->ui->scoreLabel->setVisible(false);
                this->gameArea->setDrawNextItem(false);
                this->gameArea->setDrawGrid(false);
                this->ui->gradeWidget->setVisible(false);

               this->pix_information.fill(QColor(255,255,255,255));
               painter.drawPixmap(0,0,800,500,this->pix_information);

               QFont font;
               font.setPointSize(20);

               painter.setFont(font);
               painter.drawText(100,200,tr("这不是幻觉，这就是现实，而且你必须接受挑战"));
               painter.drawText(100,300,tr("你是传说中的无畏者吗？真正的战斗即将开始．．．．．．"));
               this->maskMax = 255;
           }
        }
        else if(this->the_second == 8) //开始进入最后一关
        {
            this->second_timer->stop();
            this->pix_backGround.fill(Qt::black);
            this->pix_information.fill(QColor(255,255,255,this->maskMax));
            painter.drawPixmap(0,0,800,500,this->pix_information);

           QFont font;
           font.setPointSize(20);

           painter.setFont(font);
           painter.drawText(100,200,tr("这不是幻觉，这就是现实，而且你必须接受挑战"));
           painter.drawText(100,300,tr("你是传说中的无畏者吗？真正的战斗即将开始．．．．．．"));
            if(this->maskMax == 10)
            {
                this->setSoundFile(soundList.at(6));

                this->gameAreaFrame_lineWidth_timer->start(100);
                this->gameFrame_lineWidth = 80;
                this->gameArea->setVisible(false);
            }
            else if(this->maskMax <10)
            {
                this->mask_timer->stop();

                this->ui->gameFrame->setVisible(true);
                if(gameFrame_lineWidth <= 0)
                {
                    this->gameArea->setVisible(true);
                    this->gameAreaFrame_lineWidth_timer->stop();

                    this->gameArea->setFocus();
                    this->the_second = 0; //秒计时重新数设为0
                    this->isFirstOut_endGrade = false;
                    this->maskMin = 0;

                    this->changeGameArea();    //进入第6关
                }
            }

        }

    }
    else
    {
        this->pix_information.fill(QColor(0,0,0,0));
        painter.drawPixmap(0,0,800,500,this->pix_information);
    }
}

void MyBox::set_visible(bool Bool)  //对一些部件进行是否可见设置
{
    this->ui->gameFrame->setVisible(Bool);
    this->ui->backBtn->setVisible(Bool);
    this->ui->pauseBtn->setVisible(Bool);
    this->ui->reStartBtn->setVisible(Bool);
    this->ui->scoreLabel->setVisible(Bool);
    this->ui->gradeWidget->setVisible(Bool);
}

void MyBox::on_reStartBtn_clicked()
        //重新开始
{
    this->initTheGame();
    gameArea->init_Game();
    gameArea->gameStart();
    this->boxMove_timer->start(this->moveSpeed);

    gameArea->setFocus();
}

void MyBox::on_pauseBtn_clicked()
        //暂停
{
    if(this->ui->pauseBtn->isChecked())//第一次按下暂停键
    {
        this->ui->pauseBtn->setText(tr("取消暂停"));
        this->boxMove_timer->stop();
    }
    else    //再次按下暂停键
    {
        this->ui->pauseBtn->setText(tr("暂停"));
        this->boxMove_timer->start(this->moveSpeed);
        gameArea->setFocus();
    }
}

void MyBox::on_backBtn_clicked()
        //返回主菜单
{
    this->ui->pauseBtn->setChecked(true);
    this->on_pauseBtn_clicked();
    this->ui->backBtn->setChecked(true);
    this->ui->gameStartBtn->setText(tr("继续游戏"));
    this->ui->gameStartBtn->setChecked(true);
    this->initMainMenu();
}

void MyBox::on_gameStartBtn_clicked()//一担按下按钮，isChecked()将会改变，然后执行下面代码
        //开始游戏
{
    if(ui->gameStartBtn->isChecked()==false)
    {
        this->is_in_game = true;
        this->ui->gameStartBtn->setText(tr("开始游戏"));

        ui->backBtn->setChecked(false);
        ui->gameStartBtn->setChecked(false);
        this->ui->MainMenuWidget->setVisible(false);
        this->set_visible(true);
        this->changeGameArea();
    }
    else{

        this->initTheGame();
        this->ui->MainMenuWidget->setVisible(false);
        this->gameArea->gameStart();
        this->boxMove_timer->start(this->moveSpeed);


        this->gameArea->setFocus();   //让游戏区域获得焦点，这样才能响应键盘
    }
    this->ui->gameStartBtn->setChecked(false);
}

void MyBox::on_gameExitBtn_clicked()
        //退出游戏
{
    qApp->quit();
}

void MyBox::boxMove_timer_UpDate()
        //方块下移定时器溢出处理
{
   this->gameArea->moveOneStep();
   if(this->gameArea->isMoveEnd())
   {
       if(this->gameArea->isGame_Over())
       {
           this->gameOver();
       }
       else
       {
           this->gameArea->nextItem();

           this->do_Score(this->gameArea->getFullRowNum());
           //要在游戏再次更新之前进行，因为gameStart()会把getFullRowNum()返回值置0
           this->boxMove_timer->start(moveSpeed); //等级改变可能改变了速度，这时要重新设置速度

           this->gameArea->gameStart();
       }
   }
   else
   {
       this->gameArea->currentItem_to_currentMap();
       this->gameArea->draw_gameArea();
       this->update();
   }
}

void MyBox::gameOver()  //游戏结束处理
{
    this->boxMove_timer->stop();
    this->second_timer->stop();
    if(this->isEndGrade_start&&this->grade==5)  //第6关的入口
    {
        this->gameArea->clearFocus();
        this->clearFocus();
        this->isFirstOut_endGrade = true;
        this->isEndGrade_start = false;


        this->grade = 6;
        this->score = 0;
        this->the_second = 0;
        this->second_timer->start(1000);
        this->maskMin = -500;
        this->ui->maskWidget->setVisible(true);
        this->mask_timer->start(1);

        this->pix_backGround.fill(Qt::white);//背景设置
        this->update();//执行显示信息界面

    }
    else
    {
        QMessageBox *box;
        box=new QMessageBox(QMessageBox::Warning,tr("游戏结束"),tr("游戏已经结束，要重新挑战吗？"),
                            QMessageBox::Yes|QMessageBox::No);
        if(box->exec()==QMessageBox::Yes)
        {
            this->initTheGame();
            this->gameArea->init_Game();
            this->gameArea->setFocus();
            this->gameArea->gameStart();
            this->boxMove_timer->start(this->moveSpeed);
        }
        else
        {
            this->gameArea->init_Game();
            this->initMainMenu();   //在initTheGame()之后
        }
    }
}

void MyBox::do_Score(int num)  //对游戏分数的处理
{
    switch(num)
    {
        case 1:
        {
            score+=10;
            break;
        }
        case 2:
        {
            score+=30;
            break;
        }
        case 3:
        {
            score+=50;
            break;
        }
        case 4:
        {
            score+=70;
            break;
        }
    }

    this->ui->scoreLabel->setText(tr("你的得分是：%1").arg(score));
    do_Score_Sound(num);

    if(this->is_in_endGrade&&(this->isFirstOut_endGrade == false))
    {
        if(score >=200)
        {
            this->gameAreaRotate_timer->stop();
            this->gameAreaRotate_timer->start(150);
            this->gameArea->setGameAreaColor(QColor(0,0,0,0));
        }
        if(score >= 300)    //游戏在这里结束
        {
            this->boxMove_timer->stop();
            this->second_timer->stop();
            this->clearFocus();
            QMessageBox *box;
            box=new QMessageBox(QMessageBox::Information,tr("恭喜"),
                                tr("恭喜您通关成功，您可以到我的博客索要游戏的全部源码！"),
                            QMessageBox::Yes);
            if(box->exec()==QMessageBox::Yes)
            {
                this->gameArea->init_Game();
                this->initMainMenu();   //在initTheGame()之后
            }
        }
    }
    else
    {
        if(score<300)  //一级
        {
            this->gameArea->setBoxBrushColor(QColor(255,255,255,150));
            this->gameArea->setBoxPenColor(QColor(qrand()%255,qrand()%255,qrand()%255,255));
        }

        else if(score>=300&&score<600)  //二级
        {
            grade = 2;

            this->gameArea->setBoxBrushColor(QColor(17,142,255,150));
            this->gameArea->setBoxPenColor(QColor(0,0,0,qrand()%255));

            if(this->isFirst2)
            {

                this->gameArea->init_Game();
                this->gameArea->setbox(10,0);
                this->gameArea->setbox(10,1);
                this->gameArea->setbox(10,2);
                this->gameArea->setbox(10,7);
                this->gameArea->setbox(10,8);
                this->gameArea->setbox(10,9);
                this->changeGameArea();
                this->isFirst2 = false;
            }

        }

        else if(score>=600&&score<800)  //三级
        {
            grade = 3;

            this->gameArea->setBoxBrushColor(QColor(95,255,62,135));
            this->gameArea->setBoxPenColor(QColor(255,255,255,qrand()%255));
            if(this->isFirst3)
            {
                this->changeGameArea();
                this->isFirst3 = false;
            }
        }

        else if(score>=800&&score<1000)  //四级
        {
            grade = 4;
            this->gameArea->setGameAreaColor(QColor(255,255,255,80));
            this->gameArea->setBoxBrushColor(QColor(222,190,65,qrand()%255));
            this->gameArea->setBoxPenColor(QColor(0,0,0,100));

            if(this->isFirst4)
            {
                this->changeGameArea();
                this->isFirst4 = false;
            }
        }

        else if(score>=1000&&score<1100)  //五级
        {
            grade = 5;
            this->gameArea->setGameAreaColor(QColor(255,255,255,60));
            this->gameArea->setBoxBrushColor(QColor(255,255,255,qrand()%255));
            this->gameArea->setBoxPenColor(QColor(255,0,0,255));
            if(this->isFirst5)
            {
                this->changeGameArea();
                this->isFirst5 = false;
            }

        }
        else if(score>=1100)  //终级
        {
            isEndGrade_start = true;
            if(this->isFirst6)
            {
                this->changeGameArea();
                this->isFirst6 = false;
            }
        }
    }

}


void MyBox::do_Score_Sound(int num)  //游戏消行时的声音
{
    if(num > 0) audio.play();
}

void MyBox::changeGameArea()   //对不同级别显示不同的界面
{
    QPalette palette;
    palette.setColor(QPalette::Foreground,QColor(255,255,255,255));

    switch(grade)
    {
        case 1 :
        {
            this->setSoundFile(soundList.at(1));

            this->moveSpeed = 500;
            this->gameFrame_lineWidth = 3;
            this->pix_backGround.load(":/new/prefix1/images/01.jpg");

            this->ui->gradeLabel_1->setVisible(true);
            this->ui->gradeLabel_11->setPalette(palette);
            this->gameArea->setGameAreaColor(QColor(0,0,0,80));
            this->gameArea->set_draw_box_picture(true);
            this->gameArea->setBoxPicture(":/new/prefix1/images/box.gif");
            this->gameArea->setBoxBrushColor(QColor(255,255,255,150));
            this->gameArea->setBoxPenColor(QColor(qrand()%255,qrand()%255,qrand()%255,255));

            break;
        }
         case 2 :
        {
            this->setSoundFile(soundList.at(2));


            this->moveSpeed = 400;
            this->gameFrame_lineWidth = 6;
            this->pix_backGround.load(":/new/prefix1/images/02.jpg");

            this->ui->gradeLabel_2->setVisible(true);
            this->ui->gradeLabel_21->setPalette(palette);
            this->gameArea->setGameAreaColor(QColor(255,255,255,100));

            break;
        }
         case 3 :
        {
            this->setSoundFile(soundList.at(3));

            this->moveSpeed = 300;
            this->gameFrame_lineWidth = 9;
            this->pix_backGround.load(":/new/prefix1/images/03.jpg");

            this->ui->gradeLabel_3->setVisible(true);
            this->ui->gradeLabel_31->setPalette(palette);
            this->gameArea->setGameAreaColor(QColor(255,255,255,100));

            break;
        }
         case 4 :
        {
            this->setSoundFile(soundList.at(4));

            this->gameArea->init_Game();
            this->gameArea->setbox(19,5);
            this->gameArea->setbox(18,6);
            this->gameArea->setbox(17,7);
            this->gameArea->setbox(16,5);
            this->gameArea->setbox(15,4);
            this->gameArea->setbox(14,3);

            this->moveSpeed = 250;
            this->gameFrame_lineWidth = 12;
            this->pix_backGround.load(":/new/prefix1/images/04.jpg");

            this->ui->gradeLabel_4->setVisible(true);
            this->ui->gradeLabel_41->setPalette(palette);

            this->gameArea->setDrawGrid(false);
            this->ui->backBtn->setVisible(false);

            break;
        }
         case 5 :
        { 
            this->setSoundFile(soundList.at(5));

            this->gameArea->setDrawNextItem(false);
            this->gameArea->setDrawGrid(false);
            this->ui->backBtn->setVisible(false);

            if(this->isEndGrade_start)
            {
                this->ui->gradeLabel_5->setVisible(true);
                this->ui->gradeLabel_51->setPalette(palette);


                if(this->isEnterEndGrade==false)  //标志第一次显示
                {
                    this->boxMove_timer->stop();
                    this->isEnterEndGrade = true;
                    QMessageBox *box;
                    box=new QMessageBox(QMessageBox::Warning,tr("游戏提示"),
           tr("无畏者之火虽然已经点亮，但你有能力保护它吗？下面的挑战已经不能用困难二字来形容，为了不打击你强大的自尊心，你在这里可以选择退出。要继续挑战吗？"),
                                QMessageBox::Yes|QMessageBox::No);
                    if(box->exec()==QMessageBox::Yes)
                    {
                        this->moveSpeed = 80;
                        this->boxMove_timer->start(moveSpeed);
                        this->pix_backGround.fill(Qt::white);
                        this->theEndGrade_init();
                        this->gameArea->setRotate(true);
                        this->gameArea->setRotateAngle(180);
                        this->gameArea->draw_gameArea();
                    }
                    else
                    {
                        this->gameArea->init_Game();
                        this->initMainMenu();   //在initTheGame()之后
                    }
                }

            }
            else
            {
                this->moveSpeed = 200;
                this->gameFrame_lineWidth = 15;
                this->pix_backGround.load(":/new/prefix1/images/05.jpg");
            }
            break;
        }
        case 6:
        {
            this->setSoundFile(soundList.at(6));

            this->moveSpeed = 250;
            this->theEndGrade_start();
            this->boxMove_timer->start(moveSpeed);
            this->is_in_endGrade = true;

            this->theEndGrade();

            break;
        }
    }
 this->update();
}


void MyBox::on_gameGridRadioButton_clicked()  //是否显示网格
{
    if(this->ui->gameGridRadioButton->isChecked())
    {
        this->gameArea->setDrawGrid(true);
    }
    else{
        this->gameArea->setDrawGrid(false);
    }
    this->gameArea->draw_gameArea();
}

void MyBox::on_setOptionBtn_clicked()   //选项设置按钮
{
    this->ui->optionFrame->setVisible(true);
    this->ui->MainMenuWidget->setVisible(false);
}

void MyBox::on_backOptionBtn_clicked()   //从选项设置返回主菜单按钮
{
    this->ui->optionFrame->setVisible(false);
    this->ui->MainMenuWidget->setVisible(true);
}

void MyBox::on_downKeyRadioButton_clicked()  //是否下移一步选择按钮
{
    if(this->ui->downKeyRadioButton->isChecked())
    {
        this->gameArea->setKey_Down_Move_oneStep(false);
    }
    else
    {
        this->gameArea->setKey_Down_Move_oneStep(true);//设置一次移动到底
    }
    this->gameArea->draw_gameArea();
}




/**********最后一关特效设置*******/
void MyBox::theEndGrade()
{
    this->theEndGrade_init();
    this->theEndGrade_rotate();
    this->gameArea->init_Game();
    this->lastSecond = 600;
    this->second_timer->start(1000);
    this->gameArea->draw_gameArea();
    this->update();
}
void MyBox::theEndGrade_init()  //设置部件的大小和位置
{

    this->ui->gameFrame->resize(430,430);
    this->ui->gameFrame->move(200,50);
    this->gameArea->setGameAreaPix(-100,-200);
    this->gameArea->setGameAreaPixOrigin(215,215);

}
void MyBox::theEndGrade_rotate()    //开启旋转
{
    this->gameArea->setRotate(true);
    this->gameAreaRotate_timer->start(300);
}

void MyBox::gameAreaRotate_timer_UpDate()  //旋转定时器
{
    this->rotateAngle++;
    if(this->rotateAngle==360)
        this->rotateAngle = 0;
    this->gameArea->setRotateAngle(this->rotateAngle);
    this->gameArea->draw_gameArea();
}

void MyBox::theEndGrade_start()  //最后一关开始
{
    this->mask_timer->start(10);

}
void MyBox::mask_timer_UpDate()  //遮罩窗体的定时器
{
    this->maskMax--;
    if(this->maskMax <0)
    {
        maskMax=255;
    }
    this->maskMin+=5;
    this->update();
}
void MyBox::gameAreaFrame_lineWidth_timer_UpDate()  //边框变化的定时器
{
    this->gameFrame_lineWidth--;
    this->update();

}

void MyBox::second_timer_UpDate()  //秒定时器
{
    this->the_second++;
    this->lastSecond--;
    if(this->is_in_endGrade&&this->lastSecond==0)
    {
        this->second_timer->stop();
        this->gameOver();  //在第6关，如果时间到了就结束游戏
    }
    this->update();
}

/**********最后一关特效设置*******/



void MyBox::keyPressEvent(QKeyEvent *kk)
{
    if(kk->key() == Qt::Key_End)
    {
        this->isEndGrade_start = true;
        this->grade=5;
    }
    else QWidget::keyPressEvent(kk);
}

void MyBox::setSoundFile(QString fileName)
{
    this->mediaObject->setCurrentSource(Phonon::MediaSource(fileName));
    this->mediaObject->play();
}

void MyBox::loopMusic()
{
    this->mediaObject->stop();
    this->mediaObject->play();
}

void MyBox::on_horizontalSlider_valueChanged(int value) //music
{
    qreal volume = value /100.0;
    this->audioOutput->setVolume(volume);
}

void MyBox::on_horizontalSlider_2_valueChanged(int value)
{
    qreal volume = value /100.0;
    this->audio.setVolume(volume);
}
