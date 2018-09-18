/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/



#ifndef MYBOXITEM_H
#define MYBOXITEM_H

enum BoxItemShape { NoShape, OShape, IShape, ZShape, SShape, JShape,
                   LShape, TShape };  //枚举变量，包含7个方块形状的名字和一个空方块

class MyBoxItem
{
public:
    MyBoxItem();
    void setRandomBoxItem();   //获得一个随机的方块项
    void setBoxItem(BoxItemShape shape);   //指定当前方块为指定形状的方块
    BoxItemShape getBoxItemShape() {return boxItemShape;}

    int getBoxItemValue(int row,int col) {return boxItem[row*4+col];}
    int getBoxItemPos(unsigned char end);  //获得当前方块项在四乘四区域中的位置
    void boxItemRotate();  //方块旋转

private:
    unsigned char boxItem[4*4];
    //当前的方块项，不能用数组指针，因为不同的两个方块类的对象进行赋值时，指针会执行同一个地址
    BoxItemShape boxItemShape;  //当前方块项的形状
};

#endif // MYBOXITEM_H
