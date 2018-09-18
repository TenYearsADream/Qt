/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/


#include "myboxarea.h"

MyBoxArea::MyBoxArea(QWidget *parent) :
    QFrame(parent)
{
    resize(300,400);
    leftAndRightAudio = MyBoxAudio("moveLeft.wav");
    upAudio = MyBoxAudio("changeItem.wav");
    downAudio = MyBoxAudio("moveDown.wav");
    initMyBoxArea();
    connect(this,SIGNAL(moveEnd()),this,SLOT(newItem()));
}

void MyBoxArea::initMyBoxArea() //初始化
{       
    isGameOver = false;

    boxMapRow = 20;
    boxMapCol = 10;

    curX = 50;
    curY = 0;
    step = 20;

    boxMap = new BoxItemShape[boxMapRow * boxMapCol];
    copyBoxMap = new BoxItemShape[boxMapRow * boxMapCol];

    clearMap(boxMap);
    clearMap(copyBoxMap);

    curItem.setBoxItem(NoShape);
    nextItem.setBoxItem(NoShape);

    update();
}
void MyBoxArea::clearMap(BoxItemShape *map)
{
    for(int i=0; i<boxMapRow*boxMapCol; i++)
       *(map+i) = NoShape;
}

void MyBoxArea::gameStart()
{
    initMyBoxArea();
    curItem.setRandomBoxItem();
    nextItem.setRandomBoxItem();
    itemToMap();
}


void MyBoxArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    drawBoxMap(painter);
    drawNextItem(painter);

    QFrame::paintEvent(event);  //没有这句，就不能改变游戏区域的外框
}

void MyBoxArea::drawBoxMap(QPainter &painter)
{
    QPixmap pix(200,400);
    pix.fill(Qt::white);
    painter.drawPixmap(0,0,200,400,pix);
    for(int row=0; row<boxMapRow;row++)  //绘制所有方块
    {
        for(int col=0; col<boxMapCol; col++)
        {
            if(boxMap[row*boxMapCol+col] != NoShape)
            {
                BoxItemShape shape = boxMap[row*boxMapCol+col];
                drawColorBox(painter,col,row,shape); //col对应x，row对应y
            }
        }
    }
}

void MyBoxArea::drawNextItem(QPainter &painter)
{
    QPixmap nextItemPix(80,80);  //绘制下一个方块图形
    nextItemPix.fill(Qt::white);
    QPainter pp(&nextItemPix);

    BoxItemShape shape = nextItem.getBoxItemShape();

    for(int row = 0; row < 4;row++)
        for(int col = 0; col<4; col++)
        {
            if(nextItem.getBoxItemValue(row,col))
                drawColorBox(pp,col,row,shape);
        }
    painter.drawPixmap(220,20,80,80,nextItemPix);
}

void MyBoxArea::drawColorBox(QPainter &painter,int x,int y,BoxItemShape shape)
        //根据不同的方块填充不同的颜色
{
    static const QRgb colorTable[8] = {
        0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
        0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00
    };

    QColor color = colorTable[int(shape)];
    painter.setBrush(color);
    painter.setPen(color.light());
    painter.drawRect(x*step,y*step,step,step);
}

void MyBoxArea::mapToMap(BoxItemShape *curMap,BoxItemShape *targetMap)
{
    for(int row=0; row<boxMapRow; row++)
        for(int col=0; col<boxMapCol; col++)
            *(targetMap+row*boxMapCol+col) = *(curMap+row*boxMapCol+col);
}

void MyBoxArea::itemToMap()
{
    mapToMap(copyBoxMap,boxMap);  //使用备份数组的数据，这样实现方块的移动

    int curRow = curY / step;  //注意，坐标(x,y)中x对应列，y对应行
    int curCol = curX / step;

    BoxItemShape shape = curItem.getBoxItemShape();
    //得到当前方块项的形状

    for(int row=0; row<4; row++)
    {
        for(int col=0; col<4; col++)
        {
            if(curItem.getBoxItemValue(row,col))
                *(boxMap+(curRow+row)*boxMapCol+curCol+col) = shape;
        }
    }
    update();
}

void MyBoxArea::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left :   //向左的按键，改变的是X坐标的值
        {
            curX -= step;
            if(!tryMove('l')) curX += step;
  //先进行移动，然后尝试移动是否成功，如果不成功，那么就还原坐标
            else leftAndRightAudio.play();
            break;
        }
        case Qt::Key_Right :
        {
            curX += step;
            if(!tryMove('r')) curX -= step;
            else leftAndRightAudio.play();
            break;
        }
        case Qt::Key_Up :
        {
            if(itemRotate()) upAudio.play();
            break;
        }
        case Qt::Key_Down :    //向下的按键，改变的是Y坐标的值
        {
            curY += step;
            if(!tryMove('d')) curY -= step;
            break;
        }
        case Qt::Key_Space :  //向下一次移动到底
        {
            while(tryMove('d')) curY += step;

            curY -= step;
            downAudio.play();

            break;
        }
        default:
        QFrame::keyPressEvent(event);
    }
    itemToMap();
}

bool MyBoxArea::isMoveEnd() //是否跟已有的图形重合
{
    int x = curX / step;
    int y = curY / step;
    int boxItemDown = curItem.getBoxItemPos('d');

    for(int i=boxItemDown;i>=0;i--)
    {
        for(int j=3;j>=0;j--)
        {
           if(*(copyBoxMap+(y+i)*boxMapCol+x+j) && curItem.getBoxItemValue(i,j))
            {
               if(curY <= step) isGameOver = true;
                   //标记游戏已经结束，这时在newItem()函数中不再出新的方块
               return true;
            }
        }
    }
    return false;
}

bool MyBoxArea::tryMove(unsigned char key)  //尝试移动
{
    int x = curX / step;
    int y = curY / step;
    switch(key)
    {
        case 'l' :
        {
            int boxItemLeft = curItem.getBoxItemPos(key);
            if(x+boxItemLeft < 0 || isMoveEnd()) return false;
            return true;
        }
        case 'r' :
        {
            int boxItemRight = curItem.getBoxItemPos(key);
            if(x+boxItemRight >= boxMapCol || isMoveEnd()) return false;
            return true;
        }
        case 'd' :
        {
            int boxItemDown = curItem.getBoxItemPos(key);
            if(y+boxItemDown >= boxMapRow || isMoveEnd()) return false;
            return true;
        }
 ///////////关于if语句中是否有‘=’号，因为x，y坐标都是从0，0开始的，所以左边是<0,没有等号。而右边和下面
 ///////////坐标是从0算的，而行数我们是从1算的，比方说，坐标算出来是y，其实是第y+1行，坐标比行数少一，
 ///////////所以有等号。
        default: return false;
    }
}

void MyBoxArea::newItem()  //出现新的方块项
{
    mapToMap(boxMap,copyBoxMap); //将现在的所有方块区域进行备份
    clearFullRow();  //消除已满的行

    curItem = nextItem;
    nextItem.setRandomBoxItem();

    curX = 50;
    curY = 0;
    itemToMap();
}

bool MyBoxArea::itemRotate() //方块旋转
{
    curItem.boxItemRotate();
    if(!tryMove('l') || !tryMove('r') || !tryMove('d') || isMoveEnd()) //如果旋转后出现问题
    {
        curItem.setBoxItem(curItem.getBoxItemShape());  //取消旋转
        return false;
    }
    itemToMap();
    return true;
}

void MyBoxArea::clearFullRow() //清除已满的行
{
    int fullRowNum = 0;
    int temp = 1;
    for(int i=boxMapRow-1;i>0;i--) //从下向上扫描游戏区域
    {
        for(int j=0;j<boxMapCol;j++)
        {
            temp = *(copyBoxMap+i*boxMapCol+j) && temp;
        }
        if(temp) //如果这一行全为1，说明已满，则清除
        {
            fullRowNum++;
            clearRowAnimation(i); //消行时的动画
            for(int row = i;row>0;row--)   //让已满的行及其上面的各行均等于其上一行
            for(int col = 0;col<boxMapCol;col++)
            {
                *(copyBoxMap+row*boxMapCol+col)=*(copyBoxMap+(row-1)*boxMapCol+col);
            }
            i=i+1; //重新开始扫描整张图
        }
        temp =1;
    }
    if(fullRowNum) emit fullRowNumChange(fullRowNum);
}

void MyBoxArea::clearRowAnimation(int i) //消行时的动画
{
    //这里执行消行的动画
}

void MyBoxArea::boxMoveOneStepDown()   //方块下移一步，这个是槽函数，可与定时器配合使用
/****************
为了简单，我们只是在这里发射方块已经无法移动的信号，而在键盘事件里，如果方块不能再移动，我们只是不让它移动
但不发射信号。
***********************/
{
    curY += step;
    if(!tryMove('d'))
    {
        //isGameOver标志在isMoveEnd()函数中
        if(!isGameOver) emit moveEnd(); //如果移动到底，发射信号
        else emit gameOver();  //如果游戏结束，发射信号
    }
    else itemToMap();
}
