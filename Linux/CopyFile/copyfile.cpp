#include <iostream>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QRegExp>
#include <QStringList>

#include "copyfile.h"

#define K 1024
#define M 1024 * 1024
#define G 1024 * 1024 * 1024
#define T 1024 * 1024 * 1024 * 1024

CopyFile::CopyFile() : thresholdSize("1M") {
}

CopyFile::CopyFile(const QString &size) {
  thresholdSize = size;
}

QString CopyFile::getThresholdSize() const {
  return thresholdSize;
}

void CopyFile::setThresholdSize(const QString &value) {
  thresholdSize = value;
}

void CopyFile::copyFile(const QString &sourcePath, const QString &destinationPath) const {
  QDir sourceDir(sourcePath);
  if (!sourceDir.exists()) {
    qDebug() << "source dir is not exist.";
    return;
  }

  QDir destinationDir(destinationPath);
  if (!destinationDir.exists()) {
    qDebug() << "source dir is not exist.";
    return;
  }
  if (!destinationDir.isEmpty()) {
    qDebug() << "\033[32m" << destinationPath << " is not empty."
             << "\033[0m";
    return;
  }

  foreach (QFileInfo fileInfo, sourceDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs)) {
    if (fileInfo.isSymLink()) {
      continue;
    }

    if (fileInfo.isFile() && fileInfo.size() < intSize) {
      QFile tempFile(sourcePath + "/" + fileInfo.fileName());
      tempFile.copy(destinationPath + "/" + fileInfo.fileName());
    }

    if (fileInfo.isDir()) {
      destinationDir.mkdir(fileInfo.fileName());
      copyFile(sourcePath + "/" + fileInfo.fileName(), destinationPath + "/" + fileInfo.fileName());
    }
  }
}

void CopyFile::run(const QString &sourcePath, const QString &destinationPath) {
  getSize();
  copyFile(sourcePath, destinationPath);
}

void CopyFile::getSize() {
  QStringList numberList;
  QRegExp rxNumber("(\\d+)");
  int posNumber = 0;
  while ((posNumber = rxNumber.indexIn(thresholdSize, posNumber)) != -1) {
    numberList << rxNumber.cap(1);
    posNumber += rxNumber.matchedLength();
  }
  // qDebug() << numberList;

  QStringList letterList;
  QRegExp rxLetter("(\\D)");
  int posLetter = 0;
  while ((posLetter = rxLetter.indexIn(thresholdSize, posLetter)) != -1) {
    letterList << rxLetter.cap(1);
    posLetter += rxLetter.matchedLength();
  }
  // qDebug() << letterList;

  if (numberList.size() != letterList.size()) {
    qDebug() << "The format of size is error, please check it.";
  }

  for (int i = 0; i != letterList.size(); ++i) {
    if (letterList.at(i) == "T") {
      intSize += numberList.at(i).toInt() * T;
    } else if (letterList.at(i) == "G") {
      intSize += numberList.at(i).toInt() * G;
    } else if (letterList.at(i) == "M") {
      intSize += numberList.at(i).toInt() * M;
    } else if (letterList.at(i) == "K") {
      intSize += numberList.at(i).toInt() * K;
    } else if (letterList.at(i) == "B") {
      intSize += numberList.at(i).toInt() * 1;
    } else {
      /// nothing
    }
  }
  // qDebug() << intSize;
}
