#include <iostream>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include "generateprojectfile.h"

GenerateProjectFile::GenerateProjectFile(const QString &path) {
  QDir dir(path);

  foreach (QFileInfo eachFileInformation, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)) {
    if (eachFileInformation.suffix() == 'h' || eachFileInformation.suffix() == "hpp") {
      headers.append(eachFileInformation.fileName());
    }
    if (eachFileInformation.suffix() == "cpp" || eachFileInformation.suffix() == "cxx" ||
        eachFileInformation.suffix() == "C" || eachFileInformation.suffix() == "cc") {
      sources.append(eachFileInformation.fileName());
    }
  }
}

void GenerateProjectFile::run() const {
  QString baseName = QFileInfo(QDir::currentPath()).baseName();
  QFile file(baseName + ".pro");
  if (!file.open(QIODevice::WriteOnly)) {
    std::cout << "open project file error!!!!" << std::endl;
  }

  QTextStream output(&file);
  output << "HEADERS  += " << "    \\" << '\n';
  foreach (auto head, headers) { output << "          " << head << "    \\" << '\n'; }

  output << "\n\n\n";

  output << "SOURCES  += " << "    \\" << '\n';
  foreach (auto source, sources) { output << "          " << source << "    \\" << '\n'; }
}
