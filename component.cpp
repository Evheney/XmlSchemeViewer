#include "component.h"
#include <QDebug>

Component::Component()
    : number(0)
    , point(QPointF(0,0))
    , size(QSizeF(0,0))
    , rotAngle(0.)
{

}

Component::~Component()
{
    qDebug() << "Component destructor";
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

int Component::getNumCircles() const {
    return circles.size();
}

void Component::setRealName(const QString &value)
{
    realName = value;
}

void Component::setPartName(const QString &value)
{
    partName = value;
}

void Component::setRotateAngle(double value)
{
    rotAngle = value;
}

double Component::rotateAngle() const
{
    return rotAngle;
}

QString Component::getRealName() const
{
    return realName;
}

QString Component::getPartName() const
{
    return partName;
}

BoardArray Component::getBoardArray() const
{
    return boardArray;
}

void Component::setBoardArray(const BoardArray &value)
{
    boardArray = value;
}

void Component::setNumber(int n) {
    number = n;
}

void Component::setPoint(qreal x, qreal y) {
    point.setX(x);
    point.setY(y);
}

void Component::setSize(qreal sx, qreal sy) {
    size.setWidth(sx);
    size.setHeight(sy);
    calcOffset();
}
