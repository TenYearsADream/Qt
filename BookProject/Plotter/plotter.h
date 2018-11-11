#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QPixmap>
#include <QVector>
#include <QMap>

class QToolButton;
class PlotSettings;

class Plotter : public QWidget {
    Q_OBJECT

public:
    Plotter(QWidget* parent = 0);
    ~Plotter();

    void setPlotSettings(const PlotSettings& setting);
    void setCurveData(int id, const QVector<QPointF>& data);
    void clearCurve(int id);
    virtual QSize minimumSizeHint() const override;
    virtual QSize sizeHint() const override;

public
slots:
    void zoomIn();
    void zoomOut();

protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void resizeEvent(QResizeEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void wheelEvent(QWheelEvent* event) override;

private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter* painter);
    void drawCurves(QPainter* painter);

    enum {
        Margin = 50
    };

    QToolButton* zoomInButton;
    QToolButton* zoomOutButton;
    QMap<int, QVector<QPointF> > curveMap;
    QVector<PlotSettings> zoomStack;
    int curZoom;
    bool rubberBandIsShown;
    QRect rubberBandRect;
    QPixmap pixmap;
};

#endif // PLOTTER_H
