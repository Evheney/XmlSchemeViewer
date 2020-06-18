#include "shapecircle.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>

ShapeCircle::ShapeCircle(double X,double Y,double dia)
    :  circleX(X), circleY(Y), circleDia(dia)
{

}

//void ShapeCircle::setCircleDia(double value)
//{
//    circleDia = value;
//}

//void ShapeCircle::setCircleY(double value)
//{
//    circleY = value;
//}

//void ShapeCircle::setCircleX(double value)
//{
//    circleX = value;
//}

QAbstractGraphicsShapeItem *ShapeCircle::getItem(QGraphicsScene *s, const QPointF& pt)
{
    QRectF r = getRect();
    r.adjust(pt.x(),pt.y(), pt.x(),pt.y());

    QGraphicsEllipseItem * ellipseItem = s->addEllipse(r);
    return ellipseItem;
}
