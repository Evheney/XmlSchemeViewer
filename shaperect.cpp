#include "shaperect.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>

ShapeRect::ShapeRect(double x, double y,double w, double h,double r)
    :rectX(x),rectY(y), rectW(w), rectH(h), rot(r)
{

}

void ShapeRect::setRectW(double value)
{
    rectW = value;
}

void ShapeRect::setRectH(double value)
{
    rectH = value;
}

void ShapeRect::setRectX(double value)
{
    rectX = value;
}

void ShapeRect::setRectY(double value)
{
    rectY = value;
}

void ShapeRect::setRot(double value)
{
    rot = value;
}

QAbstractGraphicsShapeItem *ShapeRect::getItem(QGraphicsScene *s, const QPointF& pt)
{
    QRectF r = getRect();
    r.adjust(pt.x(),pt.y(), pt.x(),pt.y());

    QGraphicsRectItem * rectItem = s->addRect(r);

    // Rotate only if necessary
    if (!qFuzzyIsNull(rot)) {
        QPointF ptOrg = QPointF(r.center().x(), r.center().y());
        rectItem->setTransformOriginPoint(ptOrg);
        rectItem->setRotation(rot);
    }


    return rectItem;
}
