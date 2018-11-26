#include "mylayoutdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MyLayoutDialog w;
  w.show();

  return a.exec();
}
