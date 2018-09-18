#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myCom = new Win_QextSerialPort("COM1",QextSerialBase::EventDriven);
    //���崮�ڶ���ָ���������Ͳ�ѯģʽ������ʹ���¼�����EventDriven

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

    myCom->setTimeout(500);
    //��ʱ���ã���������Ϊ��ʱ500ms,�����Windows�º���������

    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readMyCom() //��ȡ�������ݲ���ʾ����
{
   // if(myCom->bytesAvailable() >=8 ) //����������ݴ��ڻ����8�ֽ��ٶ�ȡ
   // {
       // qDebug() << "read: "<<myCom->bytesAvailable()<<"bytes";
        //�������ÿ�λ�õ��ֽ���
        QByteArray temp = myCom->readAll();
        //��ȡ���ڻ��������������ݸ���ʱ����temp
        ui->textBrowser->insertPlainText(temp);
        //�����ڵ�������ʾ�ڴ��ڵ��ı��������
  // }
}

void Widget::on_pushButton_clicked()  //��������
{
    myCom->write(ui->lineEdit->text().toAscii());
    //��ASCII����ʽ������д�봮��
    //qDebug() << "write: "<<myCom->bytesToWrite()<<"bytes";
    //���Ҫ���͵��ֽ���
}
