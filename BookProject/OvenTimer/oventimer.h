#ifndef OVERTIMER_H
#define OVERTIMER_H

#include <QWidget>
#include <QDateTime>

class OvenTimer : public QWidget {
    Q_OBJECT

public:
    OvenTimer(QWidget* parent = 0);
    ~OvenTimer();

    void setDuration(int secs);
    int duration() const;
    void draw(QPainter* painter);

signals:
    void timeout();

protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;

private:
    QDateTime finishTime;
    QTimer* updateTimer;
    QTimer* finishTimer;
};

#endif // OVERTIMER_H
