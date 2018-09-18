#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->closeMyComBtn->setEnabled(false);   //开始“关闭串口”按钮不可用
    ui->sendMsgBtn->setEnabled(false);     //开始“发送数据”按钮不可用
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readMyCom()//读串口函数
{
    QByteArray temp = myCom->readAll();
    //读取串口缓冲区的所有数据给临时变量temp
    ui->textBrowser->insertPlainText(temp);
    //将串口的数据显示在窗口的文本浏览器中
}

void MainWindow::on_openMyComBtn_clicked()
{
    QString portName = ui->portNameComboBox->currentText(); //获取串口名
    myCom = new Win_QextSerialPort(portName,QextSerialBase::EventDriven);
    //定义串口对象，并传递参数，在构造函数里对其进行初始化
    myCom ->open(QIODevice::ReadWrite); //打开串口

    if(ui->baudRateComboBox->currentText()==tr("9600"))     //根据组合框内容对串口进行设置
        myCom->setBaudRate(BAUD9600);
    else if(ui->baudRateComboBox->currentText()==tr("115200"))
        myCom->setBaudRate(BAUD115200);

    if(ui->dataBitsComboBox->currentText()==tr("8"))
         myCom->setDataBits(DATA_8);
    else if(ui->dataBitsComboBox->currentText()==tr("7"))
        myCom->setDataBits(DATA_7);

    if(ui->parityComboBox->currentText()==tr("无"))
        myCom->setParity(PAR_NONE);
    else if(ui->parityComboBox->currentText()==tr("奇"))
        myCom->setParity(PAR_ODD);
    else if(ui->parityComboBox->currentText()==tr("偶"))
        myCom->setParity(PAR_EVEN);

    if(ui->stopBitsComboBox->currentText()==tr("1"))
        myCom->setStopBits(STOP_1);
    else if(ui->stopBitsComboBox->currentText()==tr("2"))
        myCom->setStopBits(STOP_2);

    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(500);

    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作

    ui->openMyComBtn->setEnabled(false);       //打开串口后“打开串口”按钮不可用
    ui->closeMyComBtn->setEnabled(true);     //打开串口后“关闭串口”按钮可用
    ui->sendMsgBtn->setEnabled(true);     //打开串口后“发送数据”按钮可用
    ui->baudRateComboBox->setEnabled(false);  //设置各个组合框不可用
    ui->dataBitsComboBox->setEnabled(false);
    ui->parityComboBox->setEnabled(false);
    ui->stopBitsComboBox->setEnabled(false);
    ui->portNameComboBox->setEnabled(false);
}

void MainWindow::on_closeMyComBtn_clicked()
{
    myCom->close();
    ui->openMyComBtn->setEnabled(true);       //关闭串口后“打开串口”按钮可用
    ui->closeMyComBtn->setEnabled(false);     //关闭串口后“关闭串口”按钮不可用
    ui->sendMsgBtn->setEnabled(false);        //关闭串口后“发送数据”按钮不可用

    ui->baudRateComboBox->setEnabled(true);     //设置各个组合框可用
    ui->dataBitsComboBox->setEnabled(true);
    ui->parityComboBox->setEnabled(true);
    ui->stopBitsComboBox->setEnabled(true);
    ui->portNameComboBox->setEnabled(true);
}

void MainWindow::on_sendMsgBtn_clicked()
{
    myCom->write(ui->sendMsgLineEdit->text().toAscii());  //以ASCII码形式将数据写入串口
}
