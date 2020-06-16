#ifndef SHAPERECT_H
#define SHAPERECT_H

#include "shape.h"

class ShapeRect : public Shape
{

public:

private:
    double rectW;
    double rectH;
    double rectX;
    double rectY;

    // Shape interface
public:
    ShapeRect();
};

#endif // SHAPERECT_H
