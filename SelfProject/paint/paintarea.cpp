#include <QPainter>

#include "paintarea.h"

PaintArea::PaintArea(QWidget* parent) : QWidget(parent)
{
    image = QImage(400, 300, QImage::Format_RGB32);
    backColor = qRgb(255, 255, 255);
    image.fill(backColor);
}

void PaintArea::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawImage(0, 0, image);
}
