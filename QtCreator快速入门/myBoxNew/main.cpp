/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
**********************************************************/
#include <QtGui/QApplication>
#include "mybox.h"
#include <QTextCodec>
#include <QSplashScreen>
#include "startdlg.h"
#include <QDesktopWidget>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/new/prefix1/images/yafeilinux.gif");
    QSplashScreen splash(pixmap);
    for(qint64 i=5555555*6;i>0;i--) splash.show();
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    StartDlg dlg;
    Qt::WindowFlags flags = Qt::FramelessWindowHint;
    dlg.setWindowFlags(flags);
    splash.finish(&dlg);
    if(dlg.exec()==QDialog::Accepted)
    {
        MyBox w;
        int width = QApplication::desktop()->width();
        int height = QApplication::desktop()->height();
        w.move((width-800)/2,(height-500)/2);   //�����ƶ��������м�
        w.setWindowIcon(QIcon("laola.ico"));
        w.show();
        return a.exec();
    }
    else return 0;

}
