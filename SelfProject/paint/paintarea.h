#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class PaintArea : public QWidget {
    Q_OBJECT
public:
    explicit PaintArea(QWidget* parent = nullptr);

signals:

public
slots:

protected:
    void paintEvent(QPaintEvent* event);

private:
    QImage image;
    QRgb backColor;
};

#endif // PAINTAREA_H
