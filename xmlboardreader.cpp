#include "xmlboardreader.h"

#include "board.h"
#include "board_info.h"

XmlBoardReader::XmlBoardReader(Scheme* board)
    : Parser(board)
{
}

bool XmlBoardReader::read(QIODevice *device)
{
    reader.setDevice(device);

    if (reader.readNextStartElement()) {
        if (reader.name() == "ePM-Xray") {
            readEpmXrayInfo();

            createComponents();
        //readBoard();
        }
        else {
            reader.raiseError(QObject::tr("Not a Scheme file"));
        }
    }


    return !reader.error();
}

QString XmlBoardReader::errorString() const
{
    return QObject::tr("%1\nLine %2, column %3")
            .arg(reader.errorString())
            .arg(reader.lineNumber())
            .arg(reader.columnNumber());
}

void XmlBoardReader::createComponents()
{
    qDebug() << "XmlBoardReader createComponetent";
    scheme->createComponets();
}

void XmlBoardReader::readEpmXrayInfo()
{
    EpmXrayInfo info;

    while(reader.readNextStartElement()){
        if(reader.name() == "format") {
            info.m_formatVer =
                    reader.attributes().value("ver").toString();
            info.m_formatName =
                    reader.attributes().value("name").toString();
            //scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "program") {
            info.m_programVer =
                    reader.attributes().value("ver").toString();
            info.m_programName =
                    reader.attributes().value("name").toString();
            info.m_programDate =
                    reader.attributes().value("date").toString();
            //scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "unit") {
            info.m_unitName =
                    reader.attributes().value("name").toString();
            info.m_unitCoord =
                    reader.attributes().value("coord").toString();
            info.m_unitDecpt =
                    reader.attributes().value("decpt").toString();
            scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "pds"){
            readPds();
        }
        else if(reader.name() == "footprints"){
            readFootprints();
        }
        else
            reader.skipCurrentElement();

    }

}

void XmlBoardReader::readPds(){
    while(reader.readNextStartElement()){
        if(reader.name() == "pd"){
            Pd * elem = new Pd;

            // Read NUM
            elem->m_num = reader.attributes().value("num").toInt();

            while (reader.readNextStartElement()) {
                if (reader.name() == "roi") {

                    // Read h and w
                    elem->m_roiH =
                            reader.attributes().value("h").toDouble();
                    elem->m_roiW =
                            reader.attributes().value("w").toDouble();
                    elem->m_roiRot =
                            reader.attributes().value("rot").toDouble();
                    elem->m_roiperi =
                            reader.attributes().value("perimeter").toDouble();
                    elem->m_roiarea =
                            reader.attributes().value("area").toDouble();
                    reader.skipCurrentElement();
                }
                else if (reader.name() == "shape") {
                    elem->m_shapetype =
                            reader.attributes().value("type").toString();
                    elem->m_shapeperi =
                            reader.attributes().value("perimeter").toDouble();
                    elem->m_shapearea =
                            reader.attributes().value("area").toDouble();
                    elem->m_shapeDia =
                            reader.attributes().value("dia").toDouble();
                    reader.skipCurrentElement();
                }
                else
                    reader.skipCurrentElement();
            }

            scheme->addPdElem(elem);
        }
        else
            reader.skipCurrentElement();
    }
}

void XmlBoardReader::readFootprints(){
    while (reader.readNextStartElement()){
        if (reader.name() == "footprint") {
            Footprint * elem2 = new Footprint;

            elem2->m_footName =
                    reader.attributes().value("name").toString();
            elem2->m_footh =
                    reader.attributes().value("bodyheight").toDouble();
            elem2->m_footw =
                    reader.attributes().value("bodywidth").toDouble();

            while (reader.readNextStartElement()){
                if (reader.name() == "pin") {
                    Pin *pin = new Pin;
                    pin->m_pinName =
                            reader.attributes().value("name").toString();
                    pin->m_piny =
                            reader.attributes().value("y").toDouble();
                    pin->m_pinx =
                            reader.attributes().value("x").toDouble();
                    pin->m_pinrot =
                            reader.attributes().value("rot").toDouble();
                    pin->m_pinpd =
                            reader.attributes().value("pd").toInt();

                    elem2->addPin(pin);
                    reader.skipCurrentElement();
                }
                else
                    reader.skipCurrentElement();
            }
            scheme->addFootprintElem(elem2);
        }
        else
            reader.skipCurrentElement();
    }
}


