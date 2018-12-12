#include "TabletApplication.h"
#include "TabletCanvas.h"

bool TabletApplication::event(QEvent *event) {
  if (event->type() == QEvent::TabletEnterProximity || event->type() == QEvent::TabletEnterProximity) {
    m_canvas->setTabletDevice(static_cast<QTabletEvent *>(event));
    return true;
  }

  return QApplication::event(event);
}

void TabletApplication::setCanvas(TabletCanvas *canvas) {
  m_canvas = canvas;
}
