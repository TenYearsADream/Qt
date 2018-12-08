#include <QtCore>

#include "copyfile.h"

int main(int argc, char **argv) {
  if (argc != 4) {
    qDebug() << argv[0] << " ThresholdSize "
             << " source "
             << " destination";
    return 0;
  }

  CopyFile test(argv[1]);
  test.run(argv[2], argv[3]);

  return 0;
}
