/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/

#ifndef STARTDLG_H
#define STARTDLG_H

#include <QtGui/QDialog>
#include <QKeyEvent>

namespace Ui {
    class StartDlg;
}

class StartDlg : public QDialog {
    Q_OBJECT
public:
    StartDlg(QWidget *parent = 0);
    ~StartDlg();
      void paintEvent(QPaintEvent *);

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *);

private:
    Ui::StartDlg *m_ui;

private slots:
    void on_pushButton_clicked();
    void yafeiExit();
};

#endif // STARTDLG_H
