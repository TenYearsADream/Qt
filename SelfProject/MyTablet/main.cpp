#include <QApplication>

#include "MainWindow.h"
#include "TabletApplication.h"
#include "TabletCanvas.h"

int main(int argc, char *argv[]) {
  TabletApplication app(argc, argv);
  TabletCanvas *canvas = new TabletCanvas;
  app.setCanvas(canvas);

  MainWindow mainWindow(canvas);
  mainWindow.resize(500, 500);
  mainWindow.show();

  return app.exec();
}
