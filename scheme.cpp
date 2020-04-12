#include "scheme.h"

Scheme::Scheme()
{

}

void Scheme::addComponent(Component *c)
{
    components.append(c);
}

Component *Scheme::getComponent(int index) const
{
    return components.at(index);
}
