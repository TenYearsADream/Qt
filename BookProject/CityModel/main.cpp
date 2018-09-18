#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include "citymodel.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QStringList cities;
  cities << "KAIFENG"
         << "ZHENGZHOU"
         << "LUOYANG"
         << "SHANGQIU"
         << "ZHOUKOU"
         << "ANYANG"
         << "PUYANG";

  CityModel cityModel;
  cityModel.setCities(cities);

  QTableView tableView;
  tableView.setModel(&cityModel);
  tableView.setAlternatingRowColors(true);
  tableView.setWindowTitle(QObject::tr("Cities"));
  tableView.show();

  return app.exec();
}
