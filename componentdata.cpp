#include <QDebug>
#include "componentdata.h"
#include <math.h>

ComponentData::ComponentData()
    : realX(0.)
    , realY(0.)
    , boardNumber(0)
{
}

ComponentData::~ComponentData()
{
    qDebug() << "ComponentData destructor";
}

double ComponentData::getRealX() const
{
    //const double theta = rot*M_PI/180.;
    //return cos(theta)*realX - sin(theta)*realY + realX;
    return realX;
}

void ComponentData::setRealX(double value)
{
    realX = value;
}

double ComponentData::getRealY() const
{
    //const double theta = rot*M_PI/180.;
    //return sin(theta)*realX + cos(theta)*realY + realY;
    return realY;
}

void ComponentData::setRealY(double value)
{
    realY = value;
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

double ComponentData::getRot() const
{
    return rot;
}

void ComponentData::setRot(double value)
{
    rot = value;
}

