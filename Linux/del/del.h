#ifndef DEL_H
#define DEL_H

#include <QObject>

class Del : public QObject {
    Q_OBJECT

public:
    explicit Del(QObject* parent = nullptr);
    Del(const qint32 fileSize, const QString& extension, QObject* parent = nullptr);

    void run();
    void unlink();

signals:

public
slots:

private:
    QString path;
    QString extension;
    qint32 fileSize;
};

#endif // DEL_H
