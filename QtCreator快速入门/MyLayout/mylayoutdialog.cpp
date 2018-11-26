#include <QHBoxLayout>
#include <QVBoxLayout>

#include "mylayoutdialog.h"
#include "ui_mylayoutdialog.h"

MyLayoutDialog::MyLayoutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::MyLayoutDialog) {
  ui->setupUi(this);
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(ui->fontComboBox);
  mainLayout->addWidget(ui->textEdit);
  mainLayout->setSpacing(50);
  mainLayout->setContentsMargins(0, 0, 50, 100);

  this->setLayout(mainLayout);
}

MyLayoutDialog::~MyLayoutDialog() { delete ui; }

void MyLayoutDialog::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
  }
}
