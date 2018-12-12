#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QColorDialog;
QT_END_NAMESPACE
class TabletCanvas;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(TabletCanvas *canvas);
  ~MainWindow();

 private slots:
  void setBurshColor();
  void setAlphaValuator(QAction *action);
  void setLineWidthValuator(QAction *action);
  void setSaturationValuator(QAction *action);
  void setEventCompression(bool comress);
  void save();
  void load();
  void about();

 private:
  void createMenus();

  TabletCanvas *m_canvas;
  QColorDialog *m_colorDialog;
};

#endif  // MAINWINDOW_H
