#ifndef TABLETCANVAS_H
#define TABLETCANVAS_H

#include <QBrush>
#include <QColor>
#include <QPen>
#include <QPixmap>
#include <QPoint>
#include <QTabletEvent>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QString;
QT_END_NAMESPACE

class TabletCanvas : public QWidget {
  Q_OBJECT

 public:
  enum Valuator { PressureValuator = 0, TangentialPressureValuator = 1, TiltValuator = 2, VTiltValuator = 3, HTiltValuator = 4, NoValuator = 5 };
  Q_ENUM(Valuator)

 public:
  explicit TabletCanvas(QWidget *parent = nullptr);

  bool saveImage(const QString &file);
  bool loadImage(const QString &file);
  void setAlphaChannelValuator(Valuator type);
  void setColorSaturationValuator(Valuator type);
  void setLineWidthType(Valuator type);
  void setColor(const QColor &color);
  QColor color() const;
  void setTabletDevice(QTabletEvent *event);
  int maximum(int a, int b);

 protected:
  void tabletEvent(QTabletEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

 signals:

 public slots:

 private:
  void initPixmap();
  void paintPixmap(QPainter &painter, QTabletEvent *event);
  Qt::BrushStyle brushPattern(qreal value);
  qreal pressureToWidth(qreal pressure);
  void updateBrush(const QTabletEvent *event);
  void updateCursor(const QTabletEvent *event);

  Valuator m_alphaChannelValuator;
  Valuator m_colorSaturationValuator;
  Valuator m_lineWidthValuator;
  QColor m_color;
  QPixmap m_pixmap;
  QBrush m_brush;
  QPen m_pen;
  bool m_deviceDown;

  struct Point {
    QPointF pos;
    qreal pressure;
    qreal roration;
  } lastPoint;
};

#endif  // TABLETCANVAS_H
