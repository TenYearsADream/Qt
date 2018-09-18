/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
**********************************************************/



#ifndef MYBOXITEM_H
#define MYBOXITEM_H

enum BoxItemShape { NoShape, OShape, IShape, ZShape, SShape, JShape,
                   LShape, TShape };  //ö�ٱ���������7��������״�����ֺ�һ���շ���

class MyBoxItem
{
public:
    MyBoxItem();
    void setRandomBoxItem();   //���һ������ķ�����
    void setBoxItem(BoxItemShape shape);   //ָ����ǰ����Ϊָ����״�ķ���
    BoxItemShape getBoxItemShape() {return boxItemShape;}

    int getBoxItemValue(int row,int col) {return boxItem[row*4+col];}
    int getBoxItemPos(unsigned char end);  //��õ�ǰ���������ĳ��������е�λ��
    void boxItemRotate();  //������ת

private:
    unsigned char boxItem[4*4];
    //��ǰ�ķ��������������ָ�룬��Ϊ��ͬ������������Ķ�����и�ֵʱ��ָ���ִ��ͬһ����ַ
    BoxItemShape boxItemShape;  //��ǰ���������״
};

#endif // MYBOXITEM_H
