#include <QApplication>
#include <QLabel>
#include <QDialog>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QDialog w;
  w.resize(400, 300);

  QLabel label(&w);
  label.move(120, 120);
  label.setText(QObject::tr("Hello World! Hello Qt"));
  w.show();

  return app.exec();
}
