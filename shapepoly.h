#ifndef SHAPEPOLY_H
#define SHAPEPOLY_H

#include "shape.h"

#include <QList>
#include <QVector>

class ShapePoly : public Shape
{
public:
    ShapePoly(qreal x,qreal y,const QVector<QPointF> &listPts);


private:
    double polyX; // offset ??
    double polyY;

    QVector<QPointF> m_listPts;

    // Shape interface
public:
    QAbstractGraphicsShapeItem *getItem(QGraphicsScene *s, const QPointF &pt) override;
};

#endif // SHAPEPOLY_H
