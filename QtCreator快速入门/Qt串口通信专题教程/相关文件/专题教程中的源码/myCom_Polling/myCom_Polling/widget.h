#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "win_qextserialport.h"
#include <QTimer>
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Win_QextSerialPort *myCom;
    QTimer *readTimer;

private slots:
    void on_pushButton_clicked(); //"发送数据"按钮槽函数
    void readMyCom();  //读取串口
};

#endif // WIDGET_H
