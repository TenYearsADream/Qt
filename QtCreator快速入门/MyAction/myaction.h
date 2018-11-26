#ifndef MYACTION_H
#define MYACTION_H

#include <QWidgetAction>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class MyAction : public QWidgetAction {
    Q_OBJECT

public:
    explicit MyAction(QWidget* parent = nullptr);

protected:
    virtual QWidget* createWidget(QWidget* parent) override;

signals:
    void getText(const QString& string);

private
slots:
    void sendText();

private:
    QLineEdit* lineEdit;
};

#endif // MYACTION_H
