#ifndef SCHEME_H
#define SCHEME_H

#include "board.h"
#include "boardarray.h"
#include "boardgroup.h"
#include "component.h"
#include "componentdata.h"

#include <QList>

class Scheme
{
public:
    Scheme();
    ~Scheme();

    void addComponent(Component* c);
    Component* getComponent(int index) const;
    int getComponentSize() const { return components.size(); }


    Board* getBoard() const;
    BoardArray* getBoardArray(int index) const;

    void addEpmXrayInfo(const EpmXrayInfo& info);
    void addBoardGroup(BoardGroup* gr);
    void addBoardArray(BoardArray* ba);
    void addPdElem(Pd* elem);
    void addFootprintElem(Footprint * elem2);
    void addComponentElem(ComponentData*cdata);

    //void addBoardName(BoardArray* board_info);
    void print();
    void createComponets();

protected:
    QList<Component*> components;
    Board *board;
    //ComponentData* componentdata;
};

#endif // SCHEME_H
