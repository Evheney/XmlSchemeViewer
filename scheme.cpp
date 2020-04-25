#include "scheme.h"
#include "componentdata.h"

Scheme::Scheme()
{
    board = new Board;
}

Scheme::~Scheme()
{
    qDebug() << "Scheme Destructor";

    delete board;

    for(Component * item: components) {
        delete item;
    }
    qDebug() << "End Scheme Destructor";
}

void Scheme::addComponent(Component *c)
{
    components.append(c);
}

Component *Scheme::getComponent(int index) const
{
    return components.at(index);
}

Board *Scheme::getBoard() const
{
    return board;
}

BoardArray *Scheme::getBoardArray(int index) const
{
    return board->getBoardArray(index);
}

void Scheme::addEpmXrayInfo(const EpmXrayInfo &info)
{
    board->addEpmXrayInfo(info);
}

void Scheme::addBoardGroup(BoardGroup *gr)
{
    board->addBoardGroup(gr);
}

void Scheme::addBoardArray(BoardArray *ba)
{
    board->addBoardArray(ba);
}

void Scheme::addPdElem(Pd *elem)
{
    board ->addPdElem(elem);
}

void Scheme::addFootprintElem(Footprint *elem2)
{
    board->addFootprintElem(elem2);
}

void Scheme::addComponentElem(ComponentData *cdata)
{
    board->addComponentData(cdata);
}

//void Scheme::addBoardName(BoardArray *board_info)
//{
//    board->addBoardName(board_info);
//}

void Scheme::print()
{
    board->print();
}

void Scheme::createComponets()
{
    qDebug() << "Scheme :: createComponetents";

/*    for (int i=0; i<4; ++i) {
        Component* cc = board->createComponent(i);
        if(cc != nullptr)
            addComponent(cc);
    }
*/

    int index=0;
    while(true){
        Component* cc = board->createComponent(index);
        if(cc == nullptr)
            break;

        addComponent(cc);
        ++index;
    }
}
