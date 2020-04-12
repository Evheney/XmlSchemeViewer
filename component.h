#ifndef COMPONENT_H
#define COMPONENT_H

#include <QRectF>
#include <QList>

class Component
{
public:
    Component();

    void setNumber(int n) {
        number = n;
    }
    void setPoint(qreal x, qreal y) {
        point.setX(x);
        point.setY(y);
    }
    void setSize(qreal sx, qreal sy) {
        size.setWidth(sx);
        size.setHeight(sy);
    }
    void addPin(qreal x, qreal y, qreal radius);

    QPointF getPoint() const;
    QSizeF getSize() const;
    QRectF getCircle(int index) const;
    int getNumCircles() const {
        return circles.size();
    }

protected:
    int number;
    QPointF point;
    QSizeF size;
    //QRectF rect;
    QList<QRectF> circles;
};

#endif // COMPONENT_H
