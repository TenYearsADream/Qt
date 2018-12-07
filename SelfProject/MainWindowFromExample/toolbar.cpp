#include <cstdlib>

#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QPainter>
#include <QPainterPath>
#include <QRandomGenerator>
#include <QSpinBox>
#include <QToolTip>

#include "toolbar.h"

static QPixmap genIcon(const QSize& iconSize, const QString&, const QColor& color) {
  int w = iconSize.width();
  int h = iconSize.height();

  QImage image(w, h, QImage::Format_A2BGR30_Premultiplied);
  image.fill(0);

  QPainter painter(&image);
  extern void render_qt_text(QPainter*, int, int, const QColor&);
  render_qt_text(&painter, w, h, color);

  return QPixmap::fromImage(image, Qt::DiffuseDither | Qt::DiffuseAlphaDither);
}

static QPixmap genIcon(const QSize& iconSize, int number, const QColor& color) {
  return genIcon(iconSize, QString::number(number), color);
}

ToolBar::ToolBar(const QString& title, QWidget* parent) : QToolBar(parent), spinBox(nullptr), spinBoxAction(nullptr) {
  setWindowTitle(title);
  setObjectName(title);

  setIconSize(QSize(32, 32));

  menu = new QMenu("One", this);
  menu->setIcon(genIcon(iconSize(), 1, Qt::black));
  menu->addAction(genIcon(iconSize(), "A", Qt::blue), "A");
  menu->addAction(genIcon(iconSize(), "B", Qt::blue), "B");
  menu->addAction(genIcon(iconSize(), "C", Qt::blue), "C");
  addAction(menu->menuAction());

  QAction* two = addAction(genIcon(iconSize(), 2, Qt::white), "Two");
  QFont boldFont;
  boldFont.setBold(true);
  two->setFont(boldFont);
}
