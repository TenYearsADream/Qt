#include <QLineEdit>
#include <QSplitter>
#include <QLabel>

#include "myaction.h"

MyAction::MyAction(QWidget* parent) : QWidgetAction(parent)
{
    /*! create a QLineEdit object */
    lineEdit = new QLineEdit;
    /*! connecting these two signals */
    connect(lineEdit, &QLineEdit::returnPressed, this, &MyAction::sendText);
}

QWidget* MyAction::createWidget(QWidget* parent)
{
    if (parent->inherits("QMenu") || parent->inherits("QToolBar")) {
        QSplitter* splitter = new QSplitter(parent);
        QLabel* label = new QLabel;
        label->setText(tr("insert texts"));
        splitter->addWidget(label);
        splitter->addWidget(lineEdit);
        return splitter;
    }
    return 0;
}

void MyAction::sendText()
{
    emit getText(lineEdit->text());
    lineEdit->clear();
}
