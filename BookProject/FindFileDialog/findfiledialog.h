#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;
QT_END_NAMESPACE

class FindFileDialog : public QDialog {
    Q_OBJECT

public:
    FindFileDialog(QWidget* parent = 0);
    ~FindFileDialog();

private:
    QLabel* namedLabel;
    QLineEdit* namedLineEdit;
    QLabel* lookInLabel;
    QLineEdit* lookInLineEdit;

    QCheckBox* subfoldersCheckBox;
    QTableWidget* tableWidget;
    QLabel* messageLabel;

    QPushButton* findPushButton;
    QPushButton* stopPushButton;
    QPushButton* closePushButton;
    QPushButton* helpPushButton;
};

#endif // FINDFILEDIALOG_H
