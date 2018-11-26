#ifndef CLASSWIZARD_H
#define CLASSWIZARD_H

#include <QWizard>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
QT_END_NAMESPACE

//! [0]
class ClassWizard : public QWizard {
  Q_OBJECT

 public:
  ClassWizard(QWidget *parent = 0);

  void accept() override;
};
//! [0]

//! [1]
class IntroPage : public QWizardPage {
  Q_OBJECT

 public:
  IntroPage(QWidget *parent = 0);

 private:
  QLabel *label;
};
//! [1]

//! [2]
class ClassInfoPage : public QWizardPage {
  Q_OBJECT

 public:
  ClassInfoPage(QWidget *parent = 0);

 private:
  QLabel *classNameLabel;
  QLabel *baseClassLabel;
  QLineEdit *classNameLineEdit;
  QLineEdit *baseClassLineEdit;
  QCheckBox *qobjectMacroCheckBox;
  QGroupBox *groupBox;
  QRadioButton *qobjectCtorRadioButton;
  QRadioButton *qwidgetCtorRadioButton;
  QRadioButton *defaultCtorRadioButton;
  QCheckBox *copyCtorCheckBox;
};
//! [2]

//! [3]
class CodeStylePage : public QWizardPage {
  Q_OBJECT

 public:
  CodeStylePage(QWidget *parent = 0);

 protected:
  void initializePage() override;

 private:
  QCheckBox *commentCheckBox;
  QCheckBox *protectCheckBox;
  QCheckBox *includeBaseCheckBox;
  QLabel *macroNameLabel;
  QLabel *baseIncludeLabel;
  QLineEdit *macroNameLineEdit;
  QLineEdit *baseIncludeLineEdit;
};
//! [3]

class OutputFilesPage : public QWizardPage {
  Q_OBJECT

 public:
  OutputFilesPage(QWidget *parent = 0);

 protected:
  void initializePage() override;

 private:
  QLabel *outputDirLabel;
  QLabel *headerLabel;
  QLabel *implementationLabel;
  QLineEdit *outputDirLineEdit;
  QLineEdit *headerLineEdit;
  QLineEdit *implementationLineEdit;
};

class ConclusionPage : public QWizardPage {
  Q_OBJECT

 public:
  ConclusionPage(QWidget *parent = 0);

 protected:
  void initializePage() override;

 private:
  QLabel *label;
};

#endif
