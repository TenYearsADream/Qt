#include <QApplication>

#include "convertdialog.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  ConvertDialog convertDialog;
  convertDialog.show();

  return app.exec();
}
