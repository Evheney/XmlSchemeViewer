#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

    Q_PROPERTY(double scale READ getScale WRITE setScale)

public:
    explicit GraphicsView(QWidget *parent = nullptr);

    void zoom100();
    void zoomFit();
    void zoomToSelected();
    void zoomIn();
    void zoomOut();

    double scaleFactor();
    void setScale(double s);
    double getScale();

    static void setSmoothZoom(bool value);

    static bool getSmoothZoom();

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;

    template <class T>
    void anim(QObject* target, const QByteArray& propertyName, T begin, T end);

    static GraphicsView* self;
    static bool smoothZoom;

    static double SX;   // initial hozirontal scale (1.0: normal)
    static double SY;   // initial vertical scale (-1.0: flipped)

};

#endif // VIEW_H
