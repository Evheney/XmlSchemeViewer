#include "component.h"
#include <QDebug>

Component::Component()
    : number(0)
    , point(QPointF(0,0))
    , size(QSizeF(0,0))
{

}

void Component::addPin(qreal x, qreal y, qreal radius)
{
    QRectF r = QRectF(QPointF(x+offsetx,y+offsety), QSizeF(radius*2, radius*2));
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

void Component::setRealName(const QString &value)
{
    realName = value;
}

void Component::setPartName(const QString &value)
{
    partName = value;
}
