#include "component.h"
#include "shaperect.h"
#include "shapecircle.h"
#include "shapepoly.h"
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
    //qDebug() << "Component destructor";

    for(auto* item: shapes) {
        delete item;
    }
}

void Component::addPin(qreal x, qreal y, qreal dia)
{
    Shape* circle = new ShapeCircle(x,y,dia);
    circle->setRect(QRectF(QPointF(x+offsetx,y+offsety), QSizeF(dia, dia)));
    shapes.append(circle);

    //qDebug() <<"Add pin: Offset x"<<offsetx <<"offsety"<<offsety<<"Diameter"<<dia;
}
void Component::addRect(qreal x, qreal y, qreal w, qreal h, qreal rot)
{
    Shape* rect = new ShapeRect(x,y,w,h,rot);
    rect->setRect(QRectF(QPointF(x+offsetx,y+offsety), QSizeF(w, h)));
    shapes.append(rect);

    qDebug() <<"Add rect: Offset x"<<offsetx <<"offsety"<<offsety<<"width"<<w<<"height"<<h;
}
void Component::addPoly(qreal x, qreal y,const QVector<QPointF> &listPts)
{
    Shape*poly = new ShapePoly(x+offsetx,y+offsety,listPts);
    shapes.append(poly);

    qDebug() <<"Add poly: X"<< x <<"Y"<<y;
    //qDebug() <<"Add poly: Offset x"<<offsetx <<"offsety"<<offsety;
}
QPointF Component::getPoint() const
{
    return point;
}

QSizeF Component::getSize() const
{
    return size;
}

int Component::getNumShapes() const
{
    return shapes.size();
}

Shape *Component::getShape(int index) const
{
    return shapes.at(index);
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

void Component::setSide(const QString &value)
{
    side = value;
}

QString Component::getSide() const
{
    return side;
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
