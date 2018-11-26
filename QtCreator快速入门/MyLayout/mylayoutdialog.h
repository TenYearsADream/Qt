#ifndef MYLAYOUTDIALOG_H
#define MYLAYOUTDIALOG_H

#include <QDialog>

namespace Ui {
class MyLayoutDialog;
}

class MyLayoutDialog : public QDialog {
  Q_OBJECT

 public:
  explicit MyLayoutDialog(QWidget *parent = 0);
  ~MyLayoutDialog();

 protected:
  void changeEvent(QEvent *e);

 private:
  Ui::MyLayoutDialog *ui;
};

#endif  // MYLAYOUTDIALOG_H
