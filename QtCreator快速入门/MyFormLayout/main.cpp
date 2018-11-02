#include "myformlayout.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MyFormLayout w;
  w.show();

  return a.exec();
}
