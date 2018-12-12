#include <cmath>
//#include "math.h"

#include <QApplication>
#include <QPainter>
#include <QPen>
#include <QTabletEvent>
#include <QtMath>

#include "TabletCanvas.h"

TabletCanvas::TabletCanvas(QWidget *parent)
    : QWidget(parent),
      m_alphaChannelValuator(TangentialPressureValuator),
      m_colorSaturationValuator(NoValuator),
      m_lineWidthValuator(PressureValuator),
      m_color(Qt::red),
      m_brush(m_color),
      m_pen(m_brush, 1.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin),
      m_deviceDown(false) {
  resize(500, 500);
  setAutoFillBackground(true);
  setAttribute(Qt::WA_TabletTracking);
}

bool TabletCanvas::saveImage(const QString &file) {
  return m_pixmap.save(file);
}

bool TabletCanvas::loadImage(const QString &file) {
  bool success = m_pixmap.load(file);

  if (success) {
    update();
    return true;
  }

  return false;
}

void TabletCanvas::setAlphaChannelValuator(Valuator type) {
  m_alphaChannelValuator = type;
}

void TabletCanvas::setColorSaturationValuator(Valuator type) {
  m_colorSaturationValuator = type;
}

void TabletCanvas::setLineWidthType(Valuator type) {
  m_lineWidthValuator = type;
}

void TabletCanvas::setColor(const QColor &color) {
  if (color.isValid()) {
    m_color = color;
  }
}

QColor TabletCanvas::color() const {
  return m_color;
}

void TabletCanvas::setTabletDevice(QTabletEvent *event) {
  updateCursor(event);
}

int TabletCanvas::maximum(int a, int b) {
  return a < b ? b : a;
}

void TabletCanvas::tabletEvent(QTabletEvent *event) {
  switch (event->type()) {
    case QEvent::TabletPress:
      if (!m_deviceDown) {
        m_deviceDown = true;
        lastPoint.pos = event->posF();
        lastPoint.pressure = event->pressure();
        lastPoint.roration = event->rotation();
      }
      break;

    case QEvent::TabletMove:
#ifndef Q_OS_IOS
      if (event->device() == QTabletEvent::RotationStylus) {
        updateCursor(event);
      }
#endif
      if (m_deviceDown) {
        updateBrush(event);
        QPainter painter(&m_pixmap);
        paintPixmap(painter, event);
        lastPoint.pos = event->posF();
        lastPoint.pressure = event->pressure();
        lastPoint.roration = event->rotation();
      }
      break;

    case QEvent::TabletRelease:
      if (m_deviceDown && event->buttons() == Qt::NoButton) {
        m_deviceDown = false;
      }
      break;

    default:
      break;
  }

  event->accept();
  update();
}

void TabletCanvas::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);

  if (m_pixmap.isNull()) {
    initPixmap();
  }
  QPainter painter(this);
  painter.drawPixmap(0, 0, m_pixmap);
}

void TabletCanvas::resizeEvent(QResizeEvent *event) {
  Q_UNUSED(event);

  initPixmap();
}

void TabletCanvas::initPixmap() {
  qreal dpr = devicePixelRatioF();
  QPixmap newPixmap = QPixmap(static_cast<int>(width() * dpr), static_cast<int>(height() * dpr));
  newPixmap.setDevicePixelRatio(dpr);
  newPixmap.fill(Qt::white);
  QPainter painter(&newPixmap);

  if (!m_pixmap.isNull()) {
    painter.drawPixmap(0, 0, m_pixmap);
  }
  painter.end();
  m_pixmap = newPixmap;
}

void TabletCanvas::paintPixmap(QPainter &painter, QTabletEvent *event) {
  painter.setRenderHint(QPainter::Antialiasing);

  switch (event->device()) {
    case QTabletEvent::Airbrush: {
      painter.setPen(Qt::NoPen);
      QRadialGradient grad(lastPoint.pos, m_pen.widthF() * 10.0);
      QColor color = m_brush.color();
      color.setAlphaF(color.alphaF() * 0.25);
      grad.setColorAt(0, m_brush.color());
      grad.setColorAt(0.5, Qt::transparent);
      painter.setBrush(grad);
      qreal radius = grad.radius();
      painter.drawEllipse(event->posF(), radius, radius);
    } break;

    case QTabletEvent::RotationStylus: {
      m_brush.setStyle(Qt::SolidPattern);
      painter.setPen(Qt::NoPen);
      painter.setBrush(m_brush);

      QPolygonF poly;
      qreal halfWidth = pressureToWidth(lastPoint.pressure);
      QPointF brushAjust(sin(qDegreesToRadians(-lastPoint.roration)) * halfWidth, cos(qDegreesToRadians(-lastPoint.roration)) * halfWidth);
      poly << lastPoint.pos + brushAjust;
      poly << lastPoint.pos - brushAjust;
      halfWidth = m_pen.widthF();

      brushAjust = QPointF(sin(qDegreesToRadians(-event->rotation())) * halfWidth, cos(qDegreesToRadians(-event->rotation())) * halfWidth);
      poly << event->posF() - brushAjust;
      poly << event->posF() + brushAjust;
      painter.drawConvexPolygon(poly);
    } break;

    case QTabletEvent::Puck:
    case QTabletEvent::FourDMouse: {
      const QString error(tr("This input device is not supported by the example."));
#if QT_CONFIG(statustip)
      QStatusTipEvent status(error);
      QApplication::sendEvent(this, &status);
#else
      qWarning() << error;
#endif
    } break;

    case QTabletEvent::Stylus: {
      painter.setPen(m_pen);
      painter.drawLine(lastPoint.pos, event->posF());
    } break;

    default: {
      const QString error(tr("Unknown tablet device - treating as stylus"));
#if QT_CONFIG(statustip)
      QStatusTipEvent status(error);
      QApplication::sendEvent(this, &status);
#else
      qWarning() << error;
#endif
    }
  }
}

qreal TabletCanvas::pressureToWidth(qreal pressure) {
  return pressure * 10 + 1;
}

void TabletCanvas::updateBrush(const QTabletEvent *event) {
  int hue = 0;
  int saturation = 0;
  int value = 0;
  int alpha = 0;

  m_color.getHsv(&hue, &saturation, &value, &alpha);

  int vValue = static_cast<int>((event->yTilt() + 60.0) / 120.0 * 255);
  int hValue = static_cast<int>((event->xTilt() + 60.0) / 120.0 * 255);

  switch (m_alphaChannelValuator) {
    case PressureValuator:
      m_color.setAlphaF(event->pressure());
      break;

    case TangentialPressureValuator:
      if (event->device() == QTabletEvent::Airbrush) {
        m_color.setAlphaF(qMax(0.01, (event->tangentialPressure() + 1.0) / 2.0));
      } else {
        m_color.setAlpha(255);
      }
      break;

    case TiltValuator:
      m_color.setAlpha(maximum(abs(vValue - 127), abs(hValue - 127)));
      break;

    default:
      m_color.setAlpha(255);
      break;
  }

  switch (m_lineWidthValuator) {
    case PressureValuator:
      m_pen.setWidthF(pressureToWidth(event->pressure()));
      break;

    case TiltValuator:
      m_pen.setWidthF(maximum(abs(vValue - 127), abs(hValue - 127)) / 12);
      break;

    default:
      m_pen.setWidthF(1);
      break;
  }

  switch (m_colorSaturationValuator) {
    case VTiltValuator:
      m_color.setHsv(hue, vValue, value, alpha);
      break;
    case HTiltValuator:
      m_color.setHsv(hue, hValue, value, alpha);
      break;
    case PressureValuator:
      m_color.setHsv(hue, int(event->pressure() * 255.0), value, alpha);
      break;
    default:;
  }

  if (event->pointerType() == QTabletEvent::Eraser) {
    m_brush.setColor(Qt::white);
    m_pen.setColor(Qt::white);
    m_pen.setWidthF(event->pressure() * 10 + 1);
  } else {
    m_brush.setColor(m_color);
    m_pen.setColor(m_color);
  }
}

void TabletCanvas::updateCursor(const QTabletEvent *event) {
  QCursor cursor;
  if (event->type() != QEvent::TabletLeaveProximity) {
    if (event->pointerType() == QTabletEvent::Eraser) {
      cursor = QCursor(QPixmap(":/images/cursor-eraser.png"), 3, 28);
    } else {
      switch (event->device()) {
        case QTabletEvent::Stylus:
          cursor = QCursor(QPixmap(":/images/cursor-pencil.png"), 0, 0);
          break;

        case QTabletEvent::Airbrush:
          cursor = QCursor(QPixmap(":/images/cursor-airbrush.png"), 3, 4);
          break;

        case QTabletEvent::RotationStylus: {
          QImage oriImg(QLatin1String(":/images/cursor-felt-marker.png"));
          QImage img(32, 32, QImage::Format_ARGB32);
          QColor solid = m_color;
          solid.setAlpha(255);
          img.fill(solid);
          QPainter painter(&img);
          QTransform transform = painter.transform();
          transform.translate(16, 16);
          transform.rotate(event->rotation());
          painter.setTransform(transform);
          painter.setCompositionMode(QPainter::CompositionMode_Destination);
          painter.drawImage(-24, -24, oriImg);
          painter.setCompositionMode(QPainter::CompositionMode_HardLight);
          painter.drawImage(-24, -24, oriImg);
          painter.end();
          cursor = QCursor(QPixmap::fromImage(img), 16, 16);
        } break;

        default:
          break;
      }
    }
  }

  setCursor(cursor);
}
