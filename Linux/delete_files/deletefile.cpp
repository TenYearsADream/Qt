#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QTextEdit>

#include "deletefile.h"

DeleteFile::DeleteFile(QWidget *parent) : QWidget(parent) {
  directoryLabel = new QLabel(tr("Directory:"));
  directoryLineEidt = new QLineEdit;
  directoryLineEidt->setText(QDir::currentPath());
  directoryLabel->setBuddy(directoryLineEidt);

  fileSizeLabel = new QLabel(tr("File Size:"));
  fileSizeLineEdit = new QLineEdit;
  fileSizeLineEdit->setText(QString::number(0));
  fileSizeLabel->setBuddy(fileSizeLineEdit);

  extensionLabel = new QLabel(tr("Extension:"));
  extensionLineEdit = new QLineEdit;
  extensionLabel->setBuddy(extensionLineEdit);

  QGridLayout *topLayout = new QGridLayout;
  topLayout->addWidget(directoryLabel, 0, 0);
  topLayout->addWidget(directoryLineEidt, 0, 1);
  topLayout->addWidget(fileSizeLabel, 1, 0);
  topLayout->addWidget(fileSizeLineEdit, 1, 1);
  topLayout->addWidget(extensionLabel, 2, 0);
  topLayout->addWidget(extensionLineEdit, 2, 1);

  contentTextEdit = new QTextEdit;
  QHBoxLayout *middleLayout = new QHBoxLayout;
  middleLayout->addWidget(contentTextEdit);

  quitPushButton = new QPushButton(tr("Quit"));
  okPushButton = new QPushButton(tr("Ok"));
  connect(quitPushButton, SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(okPushButton, SIGNAL(clicked()), this, SLOT(deleteFile()));

  QHBoxLayout *bottomLayout = new QHBoxLayout;
  bottomLayout->addStretch();
  bottomLayout->addWidget(quitPushButton);
  bottomLayout->addWidget(okPushButton);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(topLayout);
  mainLayout->addLayout(middleLayout);
  mainLayout->addLayout(bottomLayout);

  setLayout(mainLayout);
  resize(800, 360);
  setWindowTitle(tr("delete files accroding to the size and extension."));
}

DeleteFile::~DeleteFile() {}

void DeleteFile::deleteFile() {
  QDir dirName(directoryLineEidt->text());
  bool ok;
  qint32 fileSize = fileSizeLineEdit->text().toInt(&ok, 10);
  QString extension = extensionLineEdit->text();
  contentTextEdit->clear();

  foreach(QFileInfo fileInfo, dirName.entryInfoList(QDir::Files)) {
    if (fileInfo.fileName().endsWith(extension) && fileInfo.size() < fileSize) {
      QFile tempFile(directoryLineEidt->text() + "/" + fileInfo.fileName());
      bool removeOk = tempFile.remove();
      if (removeOk) {
        contentTextEdit->append(fileInfo.fileName() + QString("... was deleted"));
      } else {
        contentTextEdit->append(fileInfo.fileName() + QString("... deleted fail."));
      }
    }
  }
  contentTextEdit->append("DELETE DONE");
}
