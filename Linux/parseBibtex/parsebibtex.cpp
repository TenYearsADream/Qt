#include <QtCore>

#include "parsebibtex.h"

ParseBibtex::ParseBibtex(QObject *parent) : QObject(parent) {
  dir = QDir::currentPath() + QString("/bibtex");
}

ParseBibtex::ParseBibtex(const QString &dirName, QObject *parent)
    : QObject(parent) {
  dir = dirName;
}

void ParseBibtex::parse() const {
  QFile outFile("BIBDATABASE.bib");
  if (!outFile.open(QFile::WriteOnly | QFile::Text)) {
    qDebug() << "Open BIBDATABASE.bib error.";
  }
  QTextStream outTextStream(&outFile);

  QDir containsBibTexDir(dir);
  for (auto eachBibTex :
       containsBibTexDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)) {

    if (eachBibTex.fileName().endsWith(".bibtex")) {
      QFile inFile(eachBibTex.absoluteFilePath());
      if (!inFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Open " << eachBibTex.absoluteFilePath() << " error.";
      }
      QTextStream inTextStream(&inFile);
      while (!inTextStream.atEnd()) {
        QString eachLine = inTextStream.readLine();
        if (eachLine.trimmed().startsWith("author")) {
          if (eachLine.contains(" and ")) {
            QStringList allAuthors = eachLine.split("and");
            if (allAuthors.size() > 3) {
              eachLine.clear();
              for (int i = 0; i != 4; ++i) {
                eachLine.append(allAuthors[i]);
                if (i != 3) {
                  eachLine.append("and");
                } else {
                  eachLine.append("and others},");
                }
              }
            }
          }
        }
        outTextStream << eachLine << "\n";
      }
      outTextStream << "\n\n";
    }
  }
}
