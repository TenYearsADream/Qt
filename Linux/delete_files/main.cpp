#include "deletefile.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  DeleteFile w;
  w.show();

  return a.exec();
}
