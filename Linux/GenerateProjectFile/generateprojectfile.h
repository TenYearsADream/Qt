#ifndef GENERATEPROJECTFILE_H
#define GENERATEPROJECTFILE_H

#include <QObject>

class GenerateProjectFile {
 public:
  GenerateProjectFile(const QString &path);
  void run() const;

 private:
  QStringList headers;
  QStringList sources;
};

#endif  // GENERATEPROJECTFILE_H
