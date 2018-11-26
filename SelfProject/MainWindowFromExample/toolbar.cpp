#include <cstdlib>

#include <QRandomGenerator>
#include <QMainWindow>
#include <QMenu>
#include <QPainter>
#include <QPainterPath>
#include <QSpinBox>
#include <QLabel>
#include <QToolTip>

#include "toolbar.h"

static QPixmap genIcon(const QSize& iconSize, const QString&, const QColor& color)
{
    int w = iconSize.width();
    int h = iconSize.height();

    QImage image(w, h, QImage::Format_A2BGR30_Premultiplied);
    image.fill(0);

    QPainter painter(&image);
    extern void render_qt_text(QPainter*, int, int, const QColor&);
    render_qt_text(&painter, w, h, color);

    return QPixmap::fromImage(image, Qt::DiffuseDither | Qt::DiffuseAlphaDither);
}

ToolBar::ToolBar(const QString& title, QWidget* parent)
    : QToolBar(parent)
    , spinBox(nullptr)
    , spinBoxAction(nullptr)
{
}
