/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/


#include "myboxitem.h"
#include <QtCore>
//以下是7个方块图形的数组,还包括一个空方块
static const unsigned char BoxItem[8][4*4]=
        //这是一个二维数组，8表示一共8种方块，与前面的枚举变量一一对应
        //4*4表示一个方块项在一个四乘四的区域里
{
    {0,0,0,0,
     0,0,0,0,
     0,0,0,0,
     0,0,0,0},  //NoShape

    {0,1,1,0,
     0,1,1,0,
     0,0,0,0,
     0,0,0,0},  //OShape

    {0,0,0,1,
     0,0,0,1,
     0,0,0,1,
     0,0,0,1},  //IShape

    {0,0,1,0,
     0,1,1,0,
     0,1,0,0,
     0,0,0,0},  //ZShape

    {0,1,0,0,
     0,1,1,0,
     0,0,1,0,
     0,0,0,0},  //SShape

    {0,0,1,0,
     0,0,1,0,
     0,1,1,0,
     0,0,0,0},  //JShape

    {0,1,0,0,
     0,1,0,0,
     0,1,1,0,
     0,0,0,0},  //LShape

    {0,1,1,1,
     0,0,1,0,
     0,0,0,0,
     0,0,0,0}  //TShape
};


MyBoxItem::MyBoxItem()
{
    setBoxItem(NoShape);   //设置当前方块项为空方块

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //设置随机数的初始值
}


void MyBoxItem::setRandomBoxItem() //一个随机的方块项
{
    setBoxItem(BoxItemShape(qrand()%7+1));
}

void MyBoxItem::setBoxItem(BoxItemShape shape)  //设置方块项
{
    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 4; j++)
            *(boxItem+i*4+j) = BoxItem[shape][i*4+j];
    }
    boxItemShape = shape;
}

int MyBoxItem::getBoxItemPos(unsigned char end)
{
    int k = 0;
    switch(end)
    {
        case 'd' :   //返回从上面数图形一共占几行
        {
            for(int row=3;row>=0;row--)
                for(int col=0;col<4;col++)
                {
                    if(boxItem[row*4+col] | k)
                        return row;
                }
            return 0;
        }
        case 'r' :  //返回从左边数图形在第几列结束
        {
            for(int col=3;col>=0;col--)
                for(int row=0;row<4;row++)
                {
                    if(boxItem[row*4+col] | k)
                        return col;
                }
            return 0;
        }
        case 'l' :  //返回从左边数图形从第几列开始
        {
            for(int col=0;col<4;col++)
                for(int row=0;row<4;row++)
                {
                    if(boxItem[row*4+col] | k)
                        return col;
                }
            return 0;
        }
        default: return 0;
    }
}

void MyBoxItem::boxItemRotate()   //方块旋转
{
   unsigned char *tempItem = new unsigned char[4*4];
   for(int i=0;i<4;i++)
       for(int j=0;j<4;j++)
       {
           *(tempItem+(3-j)*4+i) = boxItem[i*4+j]; //将图形逆时针旋转90度,先放到临时数组中
       }

   for(int i=0;i<4;i++)
       for(int j=0;j<4;j++)
        {
           boxItem[i*4+j] = *(tempItem+i*4+j); //再将转换好的数组复制到以前的数组
        }
}


