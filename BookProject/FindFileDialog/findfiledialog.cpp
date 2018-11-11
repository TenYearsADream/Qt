#include <QGridLayout>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

#include "findfiledialog.h"

FindFileDialog::FindFileDialog(QWidget* parent) : QDialog(parent)
{
    namedLabel = new QLabel(tr("&Named:"));
    namedLineEdit = new QLineEdit;
    namedLabel->setBuddy(namedLineEdit);

    lookInLabel = new QLabel(tr("&Look in:"));
    lookInLineEdit = new QLineEdit;
    lookInLabel->setBuddy(lookInLineEdit);

    subfoldersCheckBox = new QCheckBox(tr("Include subfolders"));

    QStringList labels;
    labels << tr("Name") << tr("In Folder") << tr("Size") << tr("Modified");

    tableWidget = new QTableWidget;
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels(labels);

    messageLabel = new QLabel(tr("0 files found"));
    messageLabel->setFrameShape(QLabel::Panel);
    messageLabel->setFrameShadow(QLabel::Sunken);

    findPushButton = new QPushButton(tr("&Find"));
    stopPushButton = new QPushButton(tr("Stop"));
    closePushButton = new QPushButton(tr("Close"));
    helpPushButton = new QPushButton(tr("Help"));

    connect(closePushButton, &QPushButton::clicked, this, &FindFileDialog::close);

    QGridLayout* leftLayout = new QGridLayout;
    leftLayout->addWidget(namedLabel, 0, 0);
    leftLayout->addWidget(namedLineEdit, 0, 1);
    leftLayout->addWidget(lookInLabel, 1, 0);
    leftLayout->addWidget(lookInLineEdit, 1, 1);
    leftLayout->addWidget(subfoldersCheckBox, 2, 0, 1, 2);
    leftLayout->addWidget(tableWidget, 3, 0, 1, 2);
    leftLayout->addWidget(messageLabel, 4, 0, 1, 2);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findPushButton);
    rightLayout->addWidget(stopPushButton);
    rightLayout->addWidget(closePushButton);
    rightLayout->addStretch();
    rightLayout->addWidget(helpPushButton);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find Files or Folders"));
}

FindFileDialog::~FindFileDialog()
{
}
