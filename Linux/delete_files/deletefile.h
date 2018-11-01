#ifndef DELETEFILE_H
#define DELETEFILE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class DeleteFile : public QWidget {
  Q_OBJECT

 public:
  DeleteFile(QWidget *parent = 0);
  ~DeleteFile();

 public
slots:
  void deleteFile();

 private:
  QLabel *directoryLabel;
  QLineEdit *directoryLineEidt;
  QLabel *fileSizeLabel;
  QLineEdit *fileSizeLineEdit;
  QLabel *extensionLabel;
  QLineEdit *extensionLineEdit;

  QTextEdit *contentTextEdit;

  QPushButton *quitPushButton;
  QPushButton *okPushButton;
};

#endif  // DELETEFILE_H
