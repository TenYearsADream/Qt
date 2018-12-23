#ifndef EXTENSIONDIALOG_H
#define EXTENSIONDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class ExtensionDialog : public QDialog {
  Q_OBJECT

 public:
  ExtensionDialog(QWidget *parent = nullptr);
  ~ExtensionDialog();

 private:
  QLabel *label;
  QLineEdit *lineEdit;
  QCheckBox *caseCheckBox;
  QCheckBox *fromStartChechBox;
  QCheckBox *wholeWordsCheckBox;
  QCheckBox *searchSelectCheckBox;
  QCheckBox *backwardCheckBox;
  QDialogButtonBox *buttonBox;
  QPushButton *findButton;
  QPushButton *moreButton;
  QWidget *extension;
};

#endif  // EXTENSIONDIALOG_H
