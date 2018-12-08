#ifndef COPYFILE_H
#define COPYFILE_H

#include <QString>

class CopyFile {
 public:
  CopyFile();
  CopyFile(const QString &size);

  QString getThresholdSize() const;
  void setThresholdSize(const QString &value);

  void copyFile(const QString &sourcePath, const QString &destinationPath) const;
  void run(const QString &sourcePath, const QString &destinationPath);

 private:
  void getSize();
  QString thresholdSize = "1M";
  int intSize = 0;
};

#endif  // COPYFILE_H
