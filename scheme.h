#ifndef SCHEME_H
#define SCHEME_H

#include "component.h"
#include <QList>

class Scheme
{
public:
    Scheme();

    void addComponent(Component* c);
    Component* getComponent(int index) const;
    int getComponentSize() const { return components.size(); }

protected:
    QList<Component*> components;
};

#endif // SCHEME_H
