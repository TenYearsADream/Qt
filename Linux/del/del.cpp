#include <QDebug>
#include <QDir>
#include <QFileInfo>

#include "del.h"

Del::Del(QObject* parent) : QObject(parent)
{
}

Del::Del(const qint32 fileSize, const QString& extension, QObject* parent) : QObject(parent)
{
    this->fileSize = fileSize;
    this->path = QDir::currentPath();
    this->extension = extension;
}

void Del::run()
{
    unlink();
}

void Del::unlink()
{
    QDir dir(path);
    qint32 deleteFile = 0;
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
    {
        if (fileInfo.fileName().endsWith(extension) && fileInfo.size() < fileSize) {
            QFile tempFile(path + "/" + fileInfo.fileName());
            bool ok = tempFile.remove();
            if (ok) {
                qDebug() << "\E[0;32m" << path + "/" + fileInfo.fileName() + " was deleted ......"
                         << "\E[0;0m";
                ++deleteFile;
            } else {
                qDebug() << "\E[0;31m"
                         << "fail to delete " + path + "/" + fileInfo.fileName() << "\E[0;0m";
            }
        }
    }
    if (deleteFile <= 1) {
        qDebug() << "\E[0;31m"
                 << "A total of " << deleteFile << " file was deleted."
                 << "\E[0;0m";
    } else {
        qDebug() << "\E[0;31m"
                 << "A total of " << deleteFile << " files were deleted."
                 << "\E[0;0m";
    }
}
