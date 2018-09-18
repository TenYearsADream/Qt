#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "win_qextserialport.h"
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
private slots:
    void on_pushButton_clicked(); //"��������"��ť�ۺ���
    void readMyCom();  //��ȡ����
};

#endif // WIDGET_H
