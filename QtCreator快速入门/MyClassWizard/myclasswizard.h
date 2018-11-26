#ifndef MYCLASSWIZARD_H
#define MYCLASSWIZARD_H

#include <QWizard>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
QT_END_NAMESPACE

class MyClassWizard : public QWizard {
  Q_OBJECT

 public:
  MyClassWizard(QWidget *parent = nullptr);

  virtual void accept() override;
};

class IntroPage : public QWizardPage {
  Q_OBJECT

 public:
  IntroPage(QWidget *parent = nullptr);

 private:
  QLabel *label;
};

class ClassInforPage : public QWizardPage {
  Q_OBJECT
 public:
  ClassInforPage(QWidget *parent = nullptr);

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

class CodeStylePage : public QWizardPage {
  Q_OBJECT

 public:
  CodeStylePage(QWidget *parent = nullptr);

 protected:
  virtual void initializePage() override;

 private:
  QCheckBox *commentCheckBox;
  QCheckBox *protectCheckBox;
  QCheckBox *includeBaseCheckBox;
  QLabel *macroNameLabel;
  QLabel *baseIncludeLabel;
  QLineEdit *macroNameLineEdit;
  QLineEdit *baseIncludeLineEdit;
};

class OutputFilesPage : public QWizardPage {
  Q_OBJECT

 public:
  OutputFilesPage(QWidget *parent = nullptr);

 protected:
  virtual void initializePage() override;

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
  ConclusionPage(QWidget *parent = nullptr);

 protected:
  virtual void initializePage() override;

 private:
  QLabel *label;
};

#endif  // MYCLASSWIZARD_H
