/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
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
