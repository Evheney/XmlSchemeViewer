#ifndef SCHEME_H
#define SCHEME_H

#include "board.h"
#include "component.h"
#include <QList>

class Scheme
{
public:
    Scheme();
    ~Scheme();

    void addComponent(Component* c);
    Component* getComponent(int index) const;
    int getComponentSize() const { return components.size(); }

    void addEpmXrayInfo(const EpmXrayInfo& info);
    void addPdElem(Pd* elem);
    void addFootprintElem(Footprint * elem2);

    void addBoardName(Board_info* board_info);
    void print();
    void createComponets();

protected:
    QList<Component*> components;
    Board *board;
};

#endif // SCHEME_H
