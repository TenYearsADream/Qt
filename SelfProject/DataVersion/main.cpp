#include <iostream>

#include <QCoreApplication>
#include <QDataStream>
#include <QFile>
#include <QtGlobal>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QFile file("test.dat");

  QDataStream out(&file);
  out << quint16(0xA0B0C0D0) << quint16(out.version());

  quint16 magic;
  quint16 streamVersion;

  QDataStream in(&file);
  in >> magic >> streamVersion;

  if (magic != quint16(0xA0B0C0D0)) {
    std::cerr << "File is not recognized by this applicatione" << std::endl;
  } else if (streamVersion > in.version()) {
    std::cerr << "File is from a more recent version of the application" << std::endl;
    return false;
  }

  in.setVersion(streamVersion);
  return a.exec();
}
