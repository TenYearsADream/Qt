/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/



#ifndef MYBOXAREA_H
#define MYBOXAREA_H

#include <QFrame>
#include <QtGui>
#include "myboxitem.h"
#include "myboxaudio.h"
class MyBoxArea : public QFrame
{
Q_OBJECT
public:
    MyBoxArea(QWidget *parent = 0);
    void initMyBoxArea();   //初始化方块游戏区域
    void clearMap(BoxItemShape *map);   //清空方块数组

    void gameStart();  //游戏开始
    bool itemRotate();  //方块旋转
    void clearFullRow();  //进行消行
    void clearRowAnimation(int i); //消行动画
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void itemToMap();   //将当前方块项添加到方块数组中
    void mapToMap(BoxItemShape *curMap,BoxItemShape *targetMap);
    //将两个方块数组进行相互拷贝
    bool tryMove(unsigned char key);  //尝试移动
    bool isMoveEnd();  //是否已经无法移动
private:
    void drawColorBox(QPainter &painter,int x,int y,BoxItemShape shape);
    //绘制整个游戏区域的方块
    void drawBoxMap(QPainter &painter);
    void drawNextItem(QPainter &painter);
private:
    BoxItemShape *boxMap;   //定义一个指向方块形状类型的数组的数组指针
    BoxItemShape *copyBoxMap;    //数组指针的备份
    int boxMapRow;   //整个方块游戏区域的行数
    int boxMapCol;   //整个方块游戏区域的列数
    MyBoxItem curItem;   //方块项对象，用于产生当前的方块
    MyBoxItem nextItem;
    int curX;     //当前方块在游戏区域的横坐标
    int curY;     //当前方块在游戏区域的纵坐标
    int step;     //方块移动一步的大小，也就是方块的边长

    bool isGameOver;
    //标志游戏是否已经结束，在初始化中将它置false和isMoveEnd()函数中将它置true，
    //在boxMoveOneStepDown()函数中用到了它

    MyBoxAudio leftAndRightAudio;
    MyBoxAudio upAudio;
    MyBoxAudio downAudio;

signals:
    void moveEnd(); //该信号在boxMoveOneStepDown()函数中发射，默认与newItem()关联
    void gameOver(); //该信号在boxMoveOneStepDown()函数中发射
    void fullRowNumChange(int); //该信号在clearFullRow()函数中发射，可用来记录分数
public slots:
    void newItem();  //新的方块
    void boxMoveOneStepDown();  //方块下移一步，与定时器配合使用
};

#endif // MYBOXAREA_H
