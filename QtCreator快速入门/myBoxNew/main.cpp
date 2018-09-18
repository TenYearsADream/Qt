/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
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
        w.move((width-800)/2,(height-500)/2);   //窗口移动到桌面中间
        w.setWindowIcon(QIcon("laola.ico"));
        w.show();
        return a.exec();
    }
    else return 0;

}
