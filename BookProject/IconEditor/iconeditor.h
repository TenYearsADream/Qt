#ifndef ICONEDITOR_H
#define ICONEDITOR_H

#include <QWidget>
#include <QColor>
#include <QImage>

class IconEditor : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
    Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage)
    Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor)

public:
    IconEditor(QWidget* parent = 0);
    ~IconEditor();

    QColor penColor() const;
    void setPenColor(const QColor& newColor);
    QImage iconImage() const;
    void setIconImage(const QImage& newImage);
    int zoomFactor() const;
    void setZoomFactor(int newZoom);
    virtual QSize sizeHint() const override;

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;

private:
    void setImagePixel(const QPoint& pos, bool opaque);
    QRect pixelRect(int i, int j) const;

    QColor curColor;
    QImage image;
    int zoom;
};

#endif // ICONEDITOR_H
