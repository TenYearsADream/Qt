#ifndef PARSEBIBTEX_H
#define PARSEBIBTEX_H

#include <QObject>

class ParseBibtex : public QObject {
  Q_OBJECT
 public:
  explicit ParseBibtex(QObject *parent = nullptr);
  ParseBibtex(const QString &dirName, QObject *parent = nullptr);

  void parse() const;

signals:

 public
slots:

 private:
  QString BibTex{};
  QString dir{};
};

#endif  // PARSEBIBTEX_H
