#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myCom = new Win_QextSerialPort("COM1",QextSerialBase::Polling);
    //���崮�ڶ���ָ���������Ͳ�ѯģʽ������ʹ��Polling

    myCom ->open(QIODevice::ReadWrite);
    //�Զ�д��ʽ�򿪴���

    myCom->setBaudRate(BAUD9600);
    //���������ã���������Ϊ9600

    myCom->setDataBits(DATA_8);
    //����λ���ã���������Ϊ8λ����λ

    myCom->setParity(PAR_NONE);
    //��żУ�����ã���������Ϊ��У��

    myCom->setStopBits(STOP_1);
    //ֹͣλ���ã���������Ϊ1λֹͣλ

    myCom->setFlowControl(FLOW_OFF);
    //�������������ã���������Ϊ������������

    myCom->setTimeout(10);
    //��ʱ���ã���������Ϊ��ʱ10ms

    readTimer = new QTimer(this);
    readTimer->start(100);
    //������ʱΪ100ms
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));
    //�źźͲۺ�����������ʱһ��ʱ�䣬���ж����ڲ���
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readMyCom() //��ȡ�������ݲ���ʾ����
{
    QByteArray temp = myCom->readAll();
    //��ȡ���ڻ��������������ݸ���ʱ����temp
    ui->textBrowser->insertPlainText(temp);
    //�����ڵ�������ʾ�ڴ��ڵ��ı��������
}

void Widget::on_pushButton_clicked()  //��������
{
    myCom->write(ui->lineEdit->text().toAscii());
    //��ASCII����ʽ������д�봮��
}
