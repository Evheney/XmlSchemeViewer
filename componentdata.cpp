#include <QDebug>
#include "componentdata.h"
#include <math.h>

ComponentData::ComponentData()
    : centerX(0.)
    , centerY(0.)
    , boardNumber(0)
{
}

ComponentData::~ComponentData()
{
    qDebug() << "ComponentData destructor";
}

double ComponentData::getCenterX() const
{
    //const double theta = rot*M_PI/180.;
    //return cos(theta)*realX - sin(theta)*realY + realX;
    return centerX;
}

void ComponentData::setCenterX(double value)
{
    centerX = value;
}

double ComponentData::getCenterY() const
{
    //const double theta = rot*M_PI/180.;
    //return sin(theta)*realX + cos(theta)*realY + realY;
    return centerY;
}

void ComponentData::setCenterY(double value)
{
    centerY = value;
}

QString ComponentData::getRealName() const
{
    return realName;
}

void ComponentData::setRealName(const QString &value)
{
    realName = value;
}

QString ComponentData::getPartName() const
{
    return partName;
}

void ComponentData::setPartName(const QString &value)
{
    partName = value;
}

int ComponentData::getBoardNumber() const
{
    return boardNumber;
}

void ComponentData::setBoardNumber(int value)
{
    boardNumber = value;
}

QString ComponentData::getBlockName() const
{
    return blockName;
}

void ComponentData::setBlockName(const QString &value)
{
    blockName = value;
}

QString ComponentData::getSi() const
{
    return si;
}

void ComponentData::setSi(const QString &value)
{
    si = value;
}

double ComponentData::getRot() const
{
    return rot;
}

void ComponentData::setRot(double value)
{
    rot = value;
}

