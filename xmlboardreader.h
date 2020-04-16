#ifndef XMLBOARDREADER_H
#define XMLBOARDREADER_H

#include "parser.h"
#include <QIODevice>
#include <QXmlStreamReader>
//#include "board.h"
class Scheme;
//#include "board_info.h"


class XmlBoardReader : public Parser
{
public:

    XmlBoardReader(Scheme* board);

    bool read(QIODevice *device) override;
    QString errorString() const;

protected:
    void createComponents();

private:
    QXmlStreamReader reader;

    void readEpmXrayInfo();
    void readPds();
    void readFootprints();
    void readComponentsData();

    void readBoard();
    void readBoard_info();
    void readBoard_name(Scheme *board);
    void readBoard_arrays(Scheme *board);
    void readBoard_pin_name(Scheme *board);
};

#endif // XMLBOARDREADER_H
