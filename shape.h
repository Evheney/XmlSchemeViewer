#ifndef SHAPE_H
#define SHAPE_H

#include <QRect>


class QAbstractGraphicsShapeItem;
class QGraphicsScene;

class Shape
{
public:
    Shape();
    virtual ~Shape() {}

    virtual QAbstractGraphicsShapeItem* getItem(QGraphicsScene *s, const QPointF& pt)=0;

    void setRect(QRectF r) { m_rect = r; }
    QRectF getRect() { return m_rect; }

private:
    QRectF m_rect;
};

#endif // SHAPE_H
