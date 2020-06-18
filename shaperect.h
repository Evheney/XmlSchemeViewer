#ifndef SHAPERECT_H
#define SHAPERECT_H

#include "shape.h"

class ShapeRect : public Shape
{
public:
    ShapeRect(double x,double y,double w,double h,double rot);
    void setRectW(double value);
    void setRectH(double value);
    void setRectX(double value);
    void setRectY(double value);
    void setRot(double value);

    QAbstractGraphicsShapeItem *getItem(QGraphicsScene *scene, const QPointF& pt) override;

private:
    double rectX;
    double rectY;
    double rectW;
    double rectH;
    double rot;
};

#endif // SHAPERECT_H
