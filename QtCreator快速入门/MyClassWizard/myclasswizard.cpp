#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "myclasswizard.h"

MyClassWizard::MyClassWizard(QWidget *parent) : QWizard(parent) {}

void MyClassWizard::accept() {}

/*!
 * \brief IntroPage::IntroPage
 * \param parent
 */
IntroPage::IntroPage(QWidget *parent) : QWizardPage(parent) {
  setTitle(tr("Introduction"));
  setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark1.png"));

  label = new QLabel(
      tr("This wizard will generate a skeleton C++ class definition, including a few functions. You simply need to specify the class name and set a "
         "few options to produce a header file and animplementation file for your new C++ class."));
  label->setWordWrap(true);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  setLayout(layout);
}

ClassInforPage::ClassInforPage(QWidget *parent) : QWizardPage(parent) {
  setTitle(tr("Class Information"));
  setSubTitle(tr("Specify basic information about the class for which you want to generate skeleton source code files."));
  setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));

  classNameLabel = new QLabel(tr("&Class name:"));
  classNameLineEdit = new QLineEdit;
  classNameLabel->setBuddy(classNameLineEdit);

  baseClassLabel = new QLabel(tr("B&ase class:"));
  baseClassLineEdit = new QLineEdit;
  baseClassLabel->setBuddy(baseClassLineEdit);

}
