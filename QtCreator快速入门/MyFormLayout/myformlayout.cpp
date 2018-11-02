#include "myformlayout.h"
#include "ui_myformlayout.h"

MyFormLayout::MyFormLayout(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MyFormLayout)
{
  ui->setupUi(this);
}

MyFormLayout::~MyFormLayout()
{
  delete ui;
}

void MyFormLayout::changeEvent(QEvent *e)
{
  QDialog::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
    }
}
