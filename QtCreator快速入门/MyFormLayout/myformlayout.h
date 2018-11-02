#ifndef MYFORMLAYOUT_H
#define MYFORMLAYOUT_H

#include <QDialog>

namespace Ui {
class MyFormLayout;
}

class MyFormLayout : public QDialog {
  Q_OBJECT

 public:
  explicit MyFormLayout(QWidget *parent = 0);
  ~MyFormLayout();

 protected:
  void changeEvent(QEvent *e);

 private:
  Ui::MyFormLayout *ui;
};

#endif  // MYFORMLAYOUT_H
