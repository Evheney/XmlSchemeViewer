#include <QDebug>
#include "boardgroup.h"

BoardGroup::BoardGroup(int grn, double w, double h, double x, double y)
 : grName(grn), grw(w), grh(h), grx(x), gry(y)
{
}

BoardGroup::~BoardGroup()
{
    qDebug() << "BoardGroup destructor";
}

double BoardGroup::getGrw() const
{
    return grw;
}

double BoardGroup::getGrh() const
{
    return grh;
}

double BoardGroup::getGrx() const
{
    return grx;
}

double BoardGroup::getGry() const
{
    return gry;
}

int BoardGroup::getGrName() const
{
    return grName;
}
