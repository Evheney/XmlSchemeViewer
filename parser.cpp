#include "parser.h"

Parser::Parser(Scheme *sch)
    : scheme(sch)
{

}

bool Parser::read(QIODevice *device)
{
    Q_UNUSED(device)

    Component *c = new Component();

    c->setNumber(1);
    c->setPoint(10,10);
    c->setSize(200,100);
    for(int row=0; row < 4; ++row) {
        for(int col=0; col < 10; ++col)
            c->addPin( col*20 + 10, row*20 + 10, 10);
    }

    scheme->addComponent(c);
    return true;
}
