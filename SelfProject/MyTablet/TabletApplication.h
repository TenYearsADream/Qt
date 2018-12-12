#ifndef TABLETAPPLICATION_H
#define TABLETAPPLICATION_H

#include <QApplication>

class TabletCanvas;

class TabletApplication : public QApplication {
  Q_OBJECT

 public:
  TabletApplication(int &argc, char **argv) : QApplication(argc, argv) {
  }

  bool event(QEvent *event) override;
  void setCanvas(TabletCanvas *canvas);

 private:
  TabletCanvas *m_canvas;
};

#endif  // TABLETAPPLICATION_H
