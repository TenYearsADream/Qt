#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>

class CityModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  CityModel(QObject *parent = nullptr);

  void setCities(const QStringList &cityNames);
  virtual int rowCount(const QModelIndex &parent) const override;
  virtual int columnCount(const QModelIndex &parent) const override;
  virtual QVariant data(const QModelIndex &index, int role) const override;
  virtual bool setData(const QModelIndex &index, const QVariant &value,
                       int role) override;
  virtual QVariant headerData(int section, Qt::Orientation orientation,
                              int role) const override;
  virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

 private:
  int offsetOf(int row, int column) const;

 private:
  QStringList cities;
  QVector<int> distance;
};

#endif  // CITYMODEL_H
