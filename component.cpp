#include "component.h"

Component::Component()
    : number(0)
    , point(QPointF(0,0))
    , size(QSizeF(0,0))
{

}

void Component::addPin(qreal x, qreal y, qreal radius)
{
    QRectF r = QRectF(QPointF(x,y), QSizeF(radius*2, radius*2));
    circles.append(r);
}

QPointF Component::getPoint() const
{
    return point;
}

QSizeF Component::getSize() const
{
    return size;
}

QRectF Component::getCircle(int index) const
{
    return circles.at(index);
}
