/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
**********************************************************/

#include "startdlg.h"
#include "ui_startdlg.h"
#include <QPainter>
#include <QMovie>
#include <QTimer>
QMovie *movie;
QMovie *movie1;
StartDlg::StartDlg(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::StartDlg)
{
   m_ui->setupUi(this);

   movie1 = new QMovie(":/new/prefix1/images/yafeilinuxMovie.gif");
   this->m_ui->yafeilinux->resize(800,150);
   this->m_ui->yafeilinux->move(0,125);
   this->m_ui->yafeilinux->setMovie(movie1);
   this->m_ui->frame_2->resize(800,500);
   this->m_ui->frame_2->move(0,0);
   this->m_ui->frame_2->setVisible(true);
   movie1->start();
   QTimer::singleShot(27000,this,SLOT(yafeiExit()));
    movie = new QMovie(":/new/prefix1/images/jiantou.gif");
   this->m_ui->jiantou->setMovie(movie);

}

StartDlg::~StartDlg()
{
    delete m_ui;
    delete movie;
    delete movie1;
}

void StartDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

  void StartDlg::paintEvent(QPaintEvent *)
  {
    QPixmap pix(800,500);
    QPainter painter(this);
    pix.load(":/new/prefix1/images/start.jpg");
    painter.drawPixmap(0,0,800,500,pix);
  }

  void StartDlg::yafeiExit()
  {
    this->m_ui->frame_2->setVisible(false);
    movie->start();
  }


void StartDlg::on_pushButton_clicked()
{
    accept();
}

void StartDlg::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        this->close();
        accept();
    }
}
