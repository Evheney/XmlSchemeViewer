#ifndef SHAPEPOLY_H
#define SHAPEPOLY_H

#include "shape.h"

#include <QList>

class shapepoly : public Shape
{
public:
    shapepoly();

private:
    double polyX; // offset ??
    double polyY;

    QList<QPointF> listPts;
};

#endif // SHAPEPOLY_H
