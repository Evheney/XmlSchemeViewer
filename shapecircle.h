#ifndef SHAPECIRCLE_H
#define SHAPECIRCLE_H

#include "shape.h"

class ShapeCircle : public Shape
{
public:
    ShapeCircle(double X,double Y,double dia);

    void setCircleX(double value);
    void setCircleY(double value);
    void setCircleDia(double value);

private:
    double circleX;
    double circleY;
    double circleDia;

    // Shape interface
public:
    QAbstractGraphicsShapeItem *getItem(QGraphicsScene *scene, const QPointF& pt) override;
};

#endif // SHAPECIRCLE_H
