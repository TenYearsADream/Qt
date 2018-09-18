/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
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

void MyBoxArea::initMyBoxArea() //��ʼ��
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

    QFrame::paintEvent(event);  //û����䣬�Ͳ��ܸı���Ϸ��������
}

void MyBoxArea::drawBoxMap(QPainter &painter)
{
    QPixmap pix(200,400);
    pix.fill(Qt::white);
    painter.drawPixmap(0,0,200,400,pix);
    for(int row=0; row<boxMapRow;row++)  //�������з���
    {
        for(int col=0; col<boxMapCol; col++)
        {
            if(boxMap[row*boxMapCol+col] != NoShape)
            {
                BoxItemShape shape = boxMap[row*boxMapCol+col];
                drawColorBox(painter,col,row,shape); //col��Ӧx��row��Ӧy
            }
        }
    }
}

void MyBoxArea::drawNextItem(QPainter &painter)
{
    QPixmap nextItemPix(80,80);  //������һ������ͼ��
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
        //���ݲ�ͬ�ķ�����䲻ͬ����ɫ
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
    mapToMap(copyBoxMap,boxMap);  //ʹ�ñ�����������ݣ�����ʵ�ַ�����ƶ�

    int curRow = curY / step;  //ע�⣬����(x,y)��x��Ӧ�У�y��Ӧ��
    int curCol = curX / step;

    BoxItemShape shape = curItem.getBoxItemShape();
    //�õ���ǰ���������״

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
        case Qt::Key_Left :   //����İ������ı����X�����ֵ
        {
            curX -= step;
            if(!tryMove('l')) curX += step;
  //�Ƚ����ƶ���Ȼ�����ƶ��Ƿ�ɹ���������ɹ�����ô�ͻ�ԭ����
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
        case Qt::Key_Down :    //���µİ������ı����Y�����ֵ
        {
            curY += step;
            if(!tryMove('d')) curY -= step;
            break;
        }
        case Qt::Key_Space :  //����һ���ƶ�����
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

bool MyBoxArea::isMoveEnd() //�Ƿ�����е�ͼ���غ�
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
                   //�����Ϸ�Ѿ���������ʱ��newItem()�����в��ٳ��µķ���
               return true;
            }
        }
    }
    return false;
}

bool MyBoxArea::tryMove(unsigned char key)  //�����ƶ�
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
 ///////////����if������Ƿ��С�=���ţ���Ϊx��y���궼�Ǵ�0��0��ʼ�ģ����������<0,û�еȺš����ұߺ�����
 ///////////�����Ǵ�0��ģ������������Ǵ�1��ģ��ȷ�˵�������������y����ʵ�ǵ�y+1�У������������һ��
 ///////////�����еȺš�
        default: return false;
    }
}

void MyBoxArea::newItem()  //�����µķ�����
{
    mapToMap(boxMap,copyBoxMap); //�����ڵ����з���������б���
    clearFullRow();  //������������

    curItem = nextItem;
    nextItem.setRandomBoxItem();

    curX = 50;
    curY = 0;
    itemToMap();
}

bool MyBoxArea::itemRotate() //������ת
{
    curItem.boxItemRotate();
    if(!tryMove('l') || !tryMove('r') || !tryMove('d') || isMoveEnd()) //�����ת���������
    {
        curItem.setBoxItem(curItem.getBoxItemShape());  //ȡ����ת
        return false;
    }
    itemToMap();
    return true;
}

void MyBoxArea::clearFullRow() //�����������
{
    int fullRowNum = 0;
    int temp = 1;
    for(int i=boxMapRow-1;i>0;i--) //��������ɨ����Ϸ����
    {
        for(int j=0;j<boxMapCol;j++)
        {
            temp = *(copyBoxMap+i*boxMapCol+j) && temp;
        }
        if(temp) //�����һ��ȫΪ1��˵�������������
        {
            fullRowNum++;
            clearRowAnimation(i); //����ʱ�Ķ���
            for(int row = i;row>0;row--)   //���������м�������ĸ��о���������һ��
            for(int col = 0;col<boxMapCol;col++)
            {
                *(copyBoxMap+row*boxMapCol+col)=*(copyBoxMap+(row-1)*boxMapCol+col);
            }
            i=i+1; //���¿�ʼɨ������ͼ
        }
        temp =1;
    }
    if(fullRowNum) emit fullRowNumChange(fullRowNum);
}

void MyBoxArea::clearRowAnimation(int i) //����ʱ�Ķ���
{
    //����ִ�����еĶ���
}

void MyBoxArea::boxMoveOneStepDown()   //��������һ��������ǲۺ��������붨ʱ�����ʹ��
/****************
Ϊ�˼򵥣�����ֻ�������﷢�䷽���Ѿ��޷��ƶ����źţ����ڼ����¼��������鲻�����ƶ�������ֻ�ǲ������ƶ�
���������źš�
***********************/
{
    curY += step;
    if(!tryMove('d'))
    {
        //isGameOver��־��isMoveEnd()������
        if(!isGameOver) emit moveEnd(); //����ƶ����ף������ź�
        else emit gameOver();  //�����Ϸ�����������ź�
    }
    else itemToMap();
}
