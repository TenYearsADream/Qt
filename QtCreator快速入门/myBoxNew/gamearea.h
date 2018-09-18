/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/
#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QtGui/QFrame>
#include "myitem.h"
#include <QPainter>
#include <QColor>
#include "myboxaudio.h"

class GameArea : public QFrame {
    Q_OBJECT
public:
    GameArea(QWidget *parent = 0);
    ~GameArea();
public:
    void init_gameArea(int X,int Y,int frame_width,int frame_height,int width,int height,int boxStep,int start_x,int start_y);

    void init_Game();
    void gameStart();
    void init_Map(unsigned char *initMap,int row,int col);
    void draw_gameArea();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void draw_Grid();
    void currentItem_to_currentMap();
    void copy_Map(unsigned char *theMap,unsigned char *toMap,int row,int col);
    void draw_currentMap();
    void draw_nextItem();
    bool isMoveEnd();
    bool isMoveLeft();
    bool isMoveRight();
    bool isGame_Over();
    void nextItem();

    void do_itemChange();
    void clearRow();

    void moveOneStep();
    int getFullRowNum();

    void setKey_Down_Move_oneStep(bool Bool = false);

    void setGameAreaColor(QColor color=Qt::white);
    void setBoxBrushColor(QColor color=Qt::green);
    void setBoxPenColor(QColor color=Qt::black);
    void setDrawGrid(bool Bool = true);
    void setDrawNextItem(bool Bool =true);
    void setPlaySound_moveLeft(QString fileName,bool Bool=false);
    void setPlaySound_moveRight(QString fileName,bool Bool=false);
    void setPlaySound_moveDown(QString fileName,bool Bool=false);
    void setPlaySound_itemChange(QString fileName,bool Bool=false);
    void playSound(QString fileName);

    void setRotate(bool Bool=false);
    void setRotateAngle(int angle);
    void setGameAreaPixOrigin(int x,int y);
    void setGameAreaPix(int x,int y);

    void setBoxStep(int boxStep);
    void setbox(int row,int col);
    void set_draw_box_picture(bool Bool=false);
    void setBoxPicture(QString fileName);

private:
    int gameArea_width;
    int gameArea_height;
    int map_row;
    int map_col;
    int startX;
    int startY;
    int step;
    int init_startX;
    int init_startY;
    unsigned char *currentMap;
    unsigned char *copyMap;

    QPixmap *pix_gameArea;
    MyItem *myItem;
    unsigned char *currentItem;
    unsigned char *theNextItem;
    bool isFirstItem;
    bool isGameOver;
    int fullRowNum;
    QColor gameAreaColor;
    QColor boxPenColor;
    QColor boxBrushColor;

    bool isKey_Down_Move_OneStep;

    bool isDrawGrid;
    bool isDrawNextItem;
    bool isPlaySound_moveLeft;
    bool isPlaySound_moveRight;
    bool isPlaySound_moveDown;
    bool isPlaySound_itemChange;

    MyBoxAudio moveLeftAudio;
    MyBoxAudio moveRightAudio;
    MyBoxAudio moveDownAudio;
    MyBoxAudio itemChangeAudio;

    bool isRotate;
    int theAngle;
    int gameArea_X;
    int gameArea_Y;
    int pix_X;
    int pix_Y;

    bool is_draw_box_picture;
    QString boxPicture;
};

#endif // GAMEAREA_H
