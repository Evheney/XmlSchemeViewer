#include "xmlboardreader.h"

#include "board.h"
#include "boardarray.h"
#include "componentdata.h"

const QString k_group = "group";
const QString k_boardarray = "boardarray";

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
            info.setFormatVer(reader.attributes().value("ver").toString());
            info.setFormatName(reader.attributes().value("name").toString());
            //scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "program") {
            info.setProgramVer(reader.attributes().value("ver").toString());
            info.setProgramName(reader.attributes().value("name").toString());
            info.setProgramDate(reader.attributes().value("date").toString());
            //scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "unit") {
            info.setUnitName(reader.attributes().value("name").toString());
            info.setUnitCoord(reader.attributes().value("coord").toString());
            info.setUnitDecpt(reader.attributes().value("decpt").toString());
            scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "board") {
            //info.setBoardName(reader.attributes().value("name").toString());
            info.setBoardWidth(reader.attributes().value("w").toDouble());
            info.setBoardHeight(reader.attributes().value("h").toDouble());
            scheme->addEpmXrayInfo(info);
            reader.skipCurrentElement();
        }
        else if(reader.name() == "boardarrays") {
            readBoardArrays();
        }
        else if(reader.name() == "pds"){
            readPds();
        }
        else if(reader.name() == "footprints"){
            readFootprints();
        }
        else if(reader.name() == "components"){
            readComponentsData();
        }
        else
            reader.skipCurrentElement();

    }

}

void XmlBoardReader::readBoardArrays()
{
    while (reader.readNextStartElement()){
        qDebug() << reader.name();
        if (reader.name() == k_group){

            while (reader.readNextStartElement()){
                qDebug() << reader.name();
                if (reader.name() == k_boardarray){
                    int num = reader.attributes().value("num").toInt();
                    QString name = reader.attributes().value("name").toString();
                    double x = reader.attributes().value("x").toDouble();
                    double y = reader.attributes().value("y").toDouble();
                    double rot = reader.attributes().value("rot").toDouble();
                    BoardArray *ba = new BoardArray(num, name, x,y,rot);
                    scheme->addBoardArray(ba);
                    reader.skipCurrentElement();
                }
                else
                    reader.skipCurrentElement();
            }
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

            elem2->setFootName (
                    reader.attributes().value("name").toString());
            elem2->setFooth (
                    reader.attributes().value("bodyheight").toDouble());
            elem2->setFootw (
                    reader.attributes().value("bodywidth").toDouble());

            while (reader.readNextStartElement()){
                if (reader.name() == "pin") {
                    Pin *pin = new Pin;
                    pin->setPinName (
                            reader.attributes().value("name").toString());
                    pin->setPiny (
                            reader.attributes().value("y").toDouble());
                    pin->setPinx (
                            reader.attributes().value("x").toDouble());
                    pin->setPinrot (
                            reader.attributes().value("rot").toDouble());
                    pin->setPinpd (
                            reader.attributes().value("pd").toInt());

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

void XmlBoardReader::readComponentsData()
{
    while (reader.readNextStartElement()){
        qDebug() << reader.name();
        if (reader.name() == k_group){

            while (reader.readNextStartElement()){
                qDebug() << reader.name();
                if (reader.name() == k_boardarray){
                    int boardNum = reader.attributes().value("num").toInt();
                    QString blockName = reader.attributes().value("block_name").toString();

                    while (reader.readNextStartElement()){
                        qDebug() << reader.name();
                        if (reader.name() == "component"){
                            ComponentData * cdata = new ComponentData;
                            cdata->setRealName(reader.attributes().value("name").toString());
                            cdata->setPartName(reader.attributes().value("part").toString());
                            cdata->setRealX(reader.attributes().value("x").toDouble());
                            cdata->setRealY(reader.attributes().value("y").toDouble());
                            cdata->setRot(reader.attributes().value("rot").toDouble());
                            cdata->setBoardNumber(boardNum);
                            cdata->setBlockName(blockName);

                            scheme->addComponentElem(cdata);
                            reader.skipCurrentElement();
                        }
                        else
                            reader.skipCurrentElement();
                    }
                }
                else
                    reader.skipCurrentElement();
            }
        }
        else
            reader.skipCurrentElement();
    }
}
