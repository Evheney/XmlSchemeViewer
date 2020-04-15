#include "scheme.h"

Scheme::Scheme()
{
    board=new Board;
}

Scheme::~Scheme()
{
     delete board ;
}

void Scheme::addComponent(Component *c)
{
    components.append(c);
}

Component *Scheme::getComponent(int index) const
{
    return components.at(index);
}

void Scheme::addEpmXrayInfo(const EpmXrayInfo &info)
{
    board->addEpmXrayInfo(info);
}

void Scheme::addPdElem(Pd *elem)
{
    board ->addPdElem(elem);
}

void Scheme::addFootprintElem(Footprint *elem2)
{
    board->addFootprintElem(elem2);
}

void Scheme::addBoardName(Board_info *board_info)
{
    board->addBoardName(board_info);
}

void Scheme::print()
{
    board->print();
}

void Scheme::createComponets()
{
    qDebug() << "Schem :: createComponetent";

    Component* cc = board->createComponent(0);
    if(cc != nullptr)
        addComponent(cc);

    /*
    int index=0;
    while(true){
        Component* cc = board->createComponent(index);
        if(cc == nullptr)
            break;

        addComponent(cc);
        ++index;
    }*/
}
