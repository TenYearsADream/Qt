/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
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
    void initMyBoxArea();   //��ʼ��������Ϸ����
    void clearMap(BoxItemShape *map);   //��շ�������

    void gameStart();  //��Ϸ��ʼ
    bool itemRotate();  //������ת
    void clearFullRow();  //��������
    void clearRowAnimation(int i); //���ж���
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void itemToMap();   //����ǰ��������ӵ�����������
    void mapToMap(BoxItemShape *curMap,BoxItemShape *targetMap);
    //������������������໥����
    bool tryMove(unsigned char key);  //�����ƶ�
    bool isMoveEnd();  //�Ƿ��Ѿ��޷��ƶ�
private:
    void drawColorBox(QPainter &painter,int x,int y,BoxItemShape shape);
    //����������Ϸ����ķ���
    void drawBoxMap(QPainter &painter);
    void drawNextItem(QPainter &painter);
private:
    BoxItemShape *boxMap;   //����һ��ָ�򷽿���״���͵����������ָ��
    BoxItemShape *copyBoxMap;    //����ָ��ı���
    int boxMapRow;   //����������Ϸ���������
    int boxMapCol;   //����������Ϸ���������
    MyBoxItem curItem;   //������������ڲ�����ǰ�ķ���
    MyBoxItem nextItem;
    int curX;     //��ǰ��������Ϸ����ĺ�����
    int curY;     //��ǰ��������Ϸ�����������
    int step;     //�����ƶ�һ���Ĵ�С��Ҳ���Ƿ���ı߳�

    bool isGameOver;
    //��־��Ϸ�Ƿ��Ѿ��������ڳ�ʼ���н�����false��isMoveEnd()�����н�����true��
    //��boxMoveOneStepDown()�������õ�����

    MyBoxAudio leftAndRightAudio;
    MyBoxAudio upAudio;
    MyBoxAudio downAudio;

signals:
    void moveEnd(); //���ź���boxMoveOneStepDown()�����з��䣬Ĭ����newItem()����
    void gameOver(); //���ź���boxMoveOneStepDown()�����з���
    void fullRowNumChange(int); //���ź���clearFullRow()�����з��䣬��������¼����
public slots:
    void newItem();  //�µķ���
    void boxMoveOneStepDown();  //��������һ�����붨ʱ�����ʹ��
};

#endif // MYBOXAREA_H
