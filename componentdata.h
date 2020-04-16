#ifndef COMPONENTDATA_H
#define COMPONENTDATA_H

#include <QList>
#include <QString>
#include <QStringList>

class ComponentData
{
public:
    ComponentData();

    // TODO: Refactoring: use getters/setters
    double realX;
    double realY;
    QString realname;
    QString partname;
    // TODO: Add blockName
};

#endif // COMPONENTDATA_H
