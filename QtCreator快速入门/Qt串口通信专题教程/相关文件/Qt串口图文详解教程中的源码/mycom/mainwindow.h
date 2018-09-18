#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "win_qextserialport.h"//加入头文件
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Win_QextSerialPort *myCom; //声明对象

private slots:
        void on_sendMsgBtn_clicked();
        void on_closeMyComBtn_clicked();
        void on_openMyComBtn_clicked();
        void readMyCom();      //声明读串口槽函数

};

#endif // MAINWINDOW_H
