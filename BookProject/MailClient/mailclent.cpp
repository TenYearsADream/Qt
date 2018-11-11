#include <QtWidgets>

#include "mailclent.h"

MailClent::MailClent(QWidget* parent) : QMainWindow(parent)
{
    QIcon foldersIcon(style()->standardPixmap(QStyle::SP_DirClosedIcon));
    QIcon trashIcon(style()->standardPixmap(QStyle::SP_FileIcon));

    QStringList foldersLabels;
    foldersLabels << tr("Folders");

    foldersTreeWidget = new QTreeWidget;
    foldersTreeWidget->setHeaderLabels(foldersLabels);
    addFolder(foldersIcon, tr("Inbox"));
    addFolder(foldersIcon, tr("Outbox"));
    addFolder(foldersIcon, tr("Sent"));
    addFolder(trashIcon, tr("Trash"));

    QStringList messageLabels;
    messageLabels << tr("Subject") << tr("Sender") << tr("Date");

    messagesTreeWidget = new QTreeWidget;
    messagesTreeWidget->setHeaderLabels(messageLabels);
    addMessage(tr("Happy New Year"), tr("xiaohaijin@outlook.com"), tr("2018/11/13"));
    addMessage(tr("I am XiaohaiJin"), tr("jinxiaohai@sinap.ac.cn"), tr("2018/11/11"));
    messagesTreeWidget->resizeColumnToContents(0);
    messagesTreeWidget->resizeColumnToContents(1);

    textEdit = new QTextEdit;
    textEdit->setReadOnly(true);
    textEdit->setHtml("<table bolder=0>"
                      "<tr><td align=right><b>Subject:</b>"
                      "<td><p>Happy New Year!"
                      "<tr><td align=right><b>Date:</b>"
                      "<td><p>Sun, 31 Dec 2006"
                      "<tr><td align=right><b>From:</b>"
                      "<td><p>Grace K. &lt;grace@software-inc.com&gt;"
                      "<tr><td align=right><b>To:</b>"
                      "<td>all@software-inc.com"
                      "</table>"
                      "<br>I want to seize this occasion to thank "
                      "everybody for the year that has gone, and want "
                      "to wish you the best for next year. It has been "
                      "a pleasure to work with you all on the Hawk "
                      "project, and I'm sure we'll get concrete "
                      "results shortly."
                      "<br><br>Happy New Year!"
                      "<br>--Grace");

    menuBar()->addMenu(tr("&File"));
    menuBar()->addMenu(tr("&Edit;"));
    menuBar()->addMenu(tr("&View"));
    menuBar()->addMenu(tr("F&older"));
    menuBar()->addMenu(tr("&Message"));
    menuBar()->addMenu(tr("&Settings"));
    menuBar()->addMenu(tr("&Help"));
    statusBar()->showMessage(tr("No new message on server"));

    rightSplitter = new QSplitter(Qt::Vertical);
    rightSplitter->addWidget(messagesTreeWidget);
    rightSplitter->addWidget(textEdit);
    rightSplitter->setStretchFactor(1, 1);

    mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->addWidget(foldersTreeWidget);
    mainSplitter->addWidget(rightSplitter);
    mainSplitter->setStretchFactor(1, 1);
    setCentralWidget(mainSplitter);

    setWindowTitle(tr("Mail Client"));
    readSettings();
}

MailClent::~MailClent()
{
}

void MailClent::closeEvent(QCloseEvent* event)
{
    writeSettings();
    event->accept();
}

void MailClent::addFolder(const QIcon& icon, const QString& name)
{
    QTreeWidgetItem* root;
    if (foldersTreeWidget->topLevelItemCount() == 0) {
        root = new QTreeWidgetItem(foldersTreeWidget);
        root->setText(0, tr("Mail"));
        foldersTreeWidget->setItemExpanded(root, true);
    } else {
        root = foldersTreeWidget->topLevelItem(0);
    }

    QTreeWidgetItem* newItem = new QTreeWidgetItem(root);
    newItem->setText(0, name);
    newItem->setIcon(0, icon);

    if (!foldersTreeWidget->currentItem()) {
        foldersTreeWidget->setCurrentItem(newItem);
    }
}

void MailClent::addMessage(const QString& subject, const QString& from, const QString& date)
{
    QTreeWidgetItem* newItem = new QTreeWidgetItem(messagesTreeWidget);
    newItem->setText(0, subject);
    newItem->setText(1, from);
    newItem->setText(2, date);

    if (!messagesTreeWidget->currentItem()) {
        messagesTreeWidget->setCurrentItem(newItem);
    }
}

void MailClent::readSettings()
{
    QSettings settings("Software Inc.", "Mail Client");

    settings.beginGroup("mainWindow");
    restoreGeometry(settings.value("geometry").toByteArray());
    mainSplitter->restoreState(settings.value("mainSplitter").toByteArray());
    rightSplitter->restoreState(settings.value("rightSplitter").toByteArray());
    settings.endGroup();
}

void MailClent::writeSettings()
{
    QSettings settings("Software Inc.", "Mail Client");

    settings.beginGroup("mainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("mainSplitter", mainSplitter->saveState());
    settings.setValue("rightSplitter", rightSplitter->saveState());
    settings.endGroup();
}
