#include "boardarray.h"

BoardArray::BoardArray()
    : num(0), name(""), x(0), y(0), rotate(0), grName(0)
{
}

BoardArray::BoardArray(int n, QString nm, double xx, double yy, double rot, int grN)
    : num(n), name(nm), x(xx), y(yy), rotate(rot), grName(grN)
{

}

int BoardArray::getNum() const
{
    return num;
}

//void BoardArray::setNum(int value)
//{
//    num = value;
//}

QString BoardArray::getName() const
{
    return name;
}

//void BoardArray::setName(const QString &value)
//{
//    name = value;
//}

double BoardArray::getX() const
{
    return x;
}

//void BoardArray::setX(double value)
//{
//    x = value;
//}

double BoardArray::getY() const
{
    return y;
}

//void BoardArray::setY(double value)
//{
//    y = value;
//}

double BoardArray::getRotate() const
{
    return rotate;
}

int BoardArray::getGrName() const
{
    return grName;
}

//void BoardArray::setRotate(double value)
//{
//    rotate = value;
//}
