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

//    double pinrot() const;
//    void setPinrot(double pinrot);

//    qreal X() const;
//    void setX(const qreal &x);

//    qreal Y() const;
//    void setY(const qreal &y);

//    qreal W() const;
//    void setW(const qreal &w);

//    qreal H() const;
//    void setH(const qreal &h);

private:
    QRectF m_rect;
    qreal m_pinrot;

//    qreal m_x;
//    qreal m_y;
//    qreal m_w;
//    qreal m_h;
};

#endif // SHAPE_H
