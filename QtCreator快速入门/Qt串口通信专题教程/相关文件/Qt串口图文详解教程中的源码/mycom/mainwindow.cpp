#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->closeMyComBtn->setEnabled(false);   //��ʼ���رմ��ڡ���ť������
    ui->sendMsgBtn->setEnabled(false);     //��ʼ���������ݡ���ť������
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readMyCom()//�����ں���
{
    QByteArray temp = myCom->readAll();
    //��ȡ���ڻ��������������ݸ���ʱ����temp
    ui->textBrowser->insertPlainText(temp);
    //�����ڵ�������ʾ�ڴ��ڵ��ı��������
}

void MainWindow::on_openMyComBtn_clicked()
{
    QString portName = ui->portNameComboBox->currentText(); //��ȡ������
    myCom = new Win_QextSerialPort(portName,QextSerialBase::EventDriven);
    //���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��
    myCom ->open(QIODevice::ReadWrite); //�򿪴���

    if(ui->baudRateComboBox->currentText()==tr("9600"))     //������Ͽ����ݶԴ��ڽ�������
        myCom->setBaudRate(BAUD9600);
    else if(ui->baudRateComboBox->currentText()==tr("115200"))
        myCom->setBaudRate(BAUD115200);

    if(ui->dataBitsComboBox->currentText()==tr("8"))
         myCom->setDataBits(DATA_8);
    else if(ui->dataBitsComboBox->currentText()==tr("7"))
        myCom->setDataBits(DATA_7);

    if(ui->parityComboBox->currentText()==tr("��"))
        myCom->setParity(PAR_NONE);
    else if(ui->parityComboBox->currentText()==tr("��"))
        myCom->setParity(PAR_ODD);
    else if(ui->parityComboBox->currentText()==tr("ż"))
        myCom->setParity(PAR_EVEN);

    if(ui->stopBitsComboBox->currentText()==tr("1"))
        myCom->setStopBits(STOP_1);
    else if(ui->stopBitsComboBox->currentText()==tr("2"))
        myCom->setStopBits(STOP_2);

    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(500);

    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���

    ui->openMyComBtn->setEnabled(false);       //�򿪴��ں󡰴򿪴��ڡ���ť������
    ui->closeMyComBtn->setEnabled(true);     //�򿪴��ں󡰹رմ��ڡ���ť����
    ui->sendMsgBtn->setEnabled(true);     //�򿪴��ں󡰷������ݡ���ť����
    ui->baudRateComboBox->setEnabled(false);  //���ø�����Ͽ򲻿���
    ui->dataBitsComboBox->setEnabled(false);
    ui->parityComboBox->setEnabled(false);
    ui->stopBitsComboBox->setEnabled(false);
    ui->portNameComboBox->setEnabled(false);
}

void MainWindow::on_closeMyComBtn_clicked()
{
    myCom->close();
    ui->openMyComBtn->setEnabled(true);       //�رմ��ں󡰴򿪴��ڡ���ť����
    ui->closeMyComBtn->setEnabled(false);     //�رմ��ں󡰹رմ��ڡ���ť������
    ui->sendMsgBtn->setEnabled(false);        //�رմ��ں󡰷������ݡ���ť������

    ui->baudRateComboBox->setEnabled(true);     //���ø�����Ͽ����
    ui->dataBitsComboBox->setEnabled(true);
    ui->parityComboBox->setEnabled(true);
    ui->stopBitsComboBox->setEnabled(true);
    ui->portNameComboBox->setEnabled(true);
}

void MainWindow::on_sendMsgBtn_clicked()
{
    myCom->write(ui->sendMsgLineEdit->text().toAscii());  //��ASCII����ʽ������д�봮��
}
