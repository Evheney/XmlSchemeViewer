#ifndef PARSER_H
#define PARSER_H

#include "scheme.h"
#include <QIODevice>

class Parser
{
public:
    Parser(Scheme *sch);
    virtual ~Parser();
    virtual void print();

    virtual bool read(QIODevice *device);

protected:
    Scheme *scheme;
};

#endif // PARSER_H
