#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "posix_qextserialport.h"
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
    Posix_QextSerialPort *myCom;
    QTimer *readTimer;

private slots:
    void on_pushButton_clicked(); //"��������"��ť�ۺ���
    void readMyCom();  //��ȡ����
};

#endif // WIDGET_H
