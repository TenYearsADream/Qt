#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "win_qextserialport.h"//����ͷ�ļ�
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
    Win_QextSerialPort *myCom; //��������

private slots:
        void on_sendMsgBtn_clicked();
        void on_closeMyComBtn_clicked();
        void on_openMyComBtn_clicked();
        void readMyCom();      //���������ڲۺ���

};

#endif // MAINWINDOW_H
