#include "musiclist.h"
#include "ui_musiclist.h"
#include <QSettings>
#include <QCloseEvent>

musicList::musicList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicList)
{
    ui->setupUi(this);
    listReadSettings();
    ui->tableWidget->setAcceptDrops(true);
    this->setWindowFlags(Qt::Tool  );
}

musicList::~musicList()
{
    delete ui;
}

void musicList::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void musicList::closeEvent(QCloseEvent *e)
{
    emit listClose();
    listWriteSettings();
    e->accept();
}

void musicList::listReadSettings()//读取播放列表的位置,大小信息
{
    QSettings settings("yafeilinux", "Phonon LIST");
    QPoint pos = settings.value("pos", QPoint(this->x(),this->y()+150)).toPoint();
    QSize size = settings.value("size", QSize(300,320)).toSize();
    move(pos);
    resize(size);
}

void musicList::listWriteSettings()//记录播放列表的位置,大小信息
{
    QSettings settings("yafeilinux","Phonon LIST");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void musicList::moveEvent(QMoveEvent *e)
{
    if(qAbs((this->y()- this->parentWidget()->y() - this->parentWidget()->frameGeometry().height())) < 20)
    {
        this->move(this->x(),this->parentWidget()->y() + this->parentWidget()->frameGeometry().height());
    }
    if(qAbs(this->x()+this->frameGeometry().width() - this->parentWidget()->x()) < 20)
    {
        this->move(this->parentWidget()->x()-this->frameGeometry().width(),this->y());
    }
    if(qAbs(this->x()-this->parentWidget()->frameGeometry().width()-this->parentWidget()->x()) < 20)
    {
        this->move(this->parentWidget()->x()+this->parentWidget()->frameGeometry().width(),this->y());
    }
    QWidget::moveEvent(e);
}
