#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myCom = new Win_QextSerialPort("COM1",QextSerialBase::Polling);
    //定义串口对象，指定串口名和查询模式，这里使用Polling

    myCom ->open(QIODevice::ReadWrite);
    //以读写方式打开串口

    myCom->setBaudRate(BAUD9600);
    //波特率设置，我们设置为9600

    myCom->setDataBits(DATA_8);
    //数据位设置，我们设置为8位数据位

    myCom->setParity(PAR_NONE);
    //奇偶校验设置，我们设置为无校验

    myCom->setStopBits(STOP_1);
    //停止位设置，我们设置为1位停止位

    myCom->setFlowControl(FLOW_OFF);
    //数据流控制设置，我们设置为无数据流控制

    myCom->setTimeout(10);
    //延时设置，我们设置为延时10ms

    readTimer = new QTimer(this);
    readTimer->start(100);
    //设置延时为100ms
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));
    //信号和槽函数关联，延时一段时间，进行读串口操作
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readMyCom() //读取串口数据并显示出来
{
    QByteArray temp = myCom->readAll();
    //读取串口缓冲区的所有数据给临时变量temp
    ui->textBrowser->insertPlainText(temp);
    //将串口的数据显示在窗口的文本浏览器中
}

void Widget::on_pushButton_clicked()  //发送数据
{
    myCom->write(ui->lineEdit->text().toAscii());
    //以ASCII码形式将数据写入串口
}
