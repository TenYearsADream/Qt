#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include "citymodel.h"

/*!
 * \brief CityModel::CityModel initial the base class.
 * \param parent
 */
CityModel::CityModel(QObject *parent) : QAbstractTableModel(parent) {}

void CityModel::setCities(const QStringList &cityNames) {
  this->cities = cityNames;
  distance.resize(cityNames.size() * (cityNames.size() - 1) / 2);
  distance.fill(0);
  endResetModel();
}

int CityModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return this->cities.count();
}

int CityModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return this->cities.count();
}

QVariant CityModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  if (role == Qt::TextAlignmentRole) {
    return int(Qt::AlignRight | Qt::AlignVCenter);
  } else if (role == Qt::DisplayRole) {
    if (index.row() == index.column()) {
      return 0;
    }

    int offset = offsetOf(index.row(), index.column());
    return distance[offset];
  }
  return QVariant();
}

bool CityModel::setData(const QModelIndex &index, const QVariant &value,
                        int role) {
  if (index.isValid() && index.row() != index.column() &&
      role == Qt::EditRole) {
    int offset = offsetOf(index.row(), index.column());
    distance[offset] = value.toInt();

    QModelIndex transposedIndex = createIndex(index.column(), index.row());
    emit dataChanged(index, index);
    emit dataChanged(transposedIndex, transposedIndex);
    return true;
  }
  return false;
}

QVariant CityModel::headerData(int section, Qt::Orientation orientation,
                               int role) const {
  Q_UNUSED(orientation);
  if (role == Qt::DisplayRole) {
    return cities[section];
  }
  return QVariant();
}

Qt::ItemFlags CityModel::flags(const QModelIndex &index) const {
  Qt::ItemFlags flags = QAbstractItemModel::flags(index);
  if (index.row() != index.column()) {
    flags |= Qt::ItemIsEditable;
  }
  return flags;
}

/*!
 * \brief CityModel::offsetOf calculate the index of each item
 * \param row the number of row
 * \param column the number of column
 * \return the index
 */
int CityModel::offsetOf(int row, int column) const {
  if (row < column) {
    qSwap(row, column);
  }

  return (row * (row - 1) / 2) + column;
}
