/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
**********************************************************/


#include "myboxitem.h"
#include <QtCore>
//������7������ͼ�ε�����,������һ���շ���
static const unsigned char BoxItem[8][4*4]=
        //����һ����ά���飬8��ʾһ��8�ַ��飬��ǰ���ö�ٱ���һһ��Ӧ
        //4*4��ʾһ����������һ���ĳ��ĵ�������
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
    setBoxItem(NoShape);   //���õ�ǰ������Ϊ�շ���

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //����������ĳ�ʼֵ
}


void MyBoxItem::setRandomBoxItem() //һ������ķ�����
{
    setBoxItem(BoxItemShape(qrand()%7+1));
}

void MyBoxItem::setBoxItem(BoxItemShape shape)  //���÷�����
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
        case 'd' :   //���ش�������ͼ��һ��ռ����
        {
            for(int row=3;row>=0;row--)
                for(int col=0;col<4;col++)
                {
                    if(boxItem[row*4+col] | k)
                        return row;
                }
            return 0;
        }
        case 'r' :  //���ش������ͼ���ڵڼ��н���
        {
            for(int col=3;col>=0;col--)
                for(int row=0;row<4;row++)
                {
                    if(boxItem[row*4+col] | k)
                        return col;
                }
            return 0;
        }
        case 'l' :  //���ش������ͼ�δӵڼ��п�ʼ
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

void MyBoxItem::boxItemRotate()   //������ת
{
   unsigned char *tempItem = new unsigned char[4*4];
   for(int i=0;i<4;i++)
       for(int j=0;j<4;j++)
       {
           *(tempItem+(3-j)*4+i) = boxItem[i*4+j]; //��ͼ����ʱ����ת90��,�ȷŵ���ʱ������
       }

   for(int i=0;i<4;i++)
       for(int j=0;j<4;j++)
        {
           boxItem[i*4+j] = *(tempItem+i*4+j); //�ٽ�ת���õ����鸴�Ƶ���ǰ������
        }
}


