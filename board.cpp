#include <QDebug>

#include "board.h"

Board::~Board()
{
    //qDebug() << "Board Destructor";

    for (BoardGroup* item: m_boardGroupList)
        delete item;
    for (BoardArray* item: m_boardArrayList)
        delete item;
    for (Pd* item: m_pdList)
        delete item;
    for (Footprint* item : m_footprintsList)
        delete item;
    //for (BoardArray* item : m_BoardInfoList)
    //    delete item;
    for (ComponentData* item : m_componentDataList)
        delete item;

    // qDebug() << "End Board Destructor";
}

void Board::addEpmXrayInfo(const EpmXrayInfo &info)
{
    m_info = info;
}

void Board::addPdElem(Pd *elem)
{
    m_pdList.append(elem);
}

void Board::addFootprintElem(Footprint *elem2)
{
    m_footprintsList.append(elem2);
}

void Board::addComponentData(ComponentData *cdata)
{
    m_componentDataList.append(cdata);
}

void Board::addPart(QString partName, QString footprintName)
{
    m_partMap.insert(partName, footprintName);
}

//void Board::addBoardName(BoardArray *board_info)
//{
//    m_BoardInfoList.append(board_info);
//}

void Board::addBoardGroup(BoardGroup *gr)
{
    m_boardGroupList.append(gr);
}

void Board::addBoardArray(BoardArray *ba)
{
    m_boardArrayList.append(ba);
}

void Board::print() const
{
    // qDebug() << "Print board infos";
    m_info.print();

    for(Pd* elem: m_pdList) {
        elem->print();
    }
    for(Footprint* elem2: m_footprintsList) {
        elem2->print();
    }
}

/*
bool Board::getDataForComponent(int index, int& number, QPointF& point, QSizeF& size)
{
    qDebug() << "Get Data for " << index << " component";

    if (index >= 0 && index < m_pdList.size()) {
        number = index;
        point =
        return true;
    }

    return false;

    m_info.print();

    number = m_pd
    for(pd* elem: m_pdList) {
        elem->print();
    }
    for(footprints* elem2: m_footprintsList) {
        elem2->print();
}
}
*/

Component *Board::createComponent(int index)
{
    if (index >= m_componentDataList.size()) {
        return nullptr;
    }


    //  qDebug() << "\nBoard createComponent " << index;

    //if (index < 0 || index >= m_footprintsList.size())
    //    return nullptr;

    // Get componetData by index
    ComponentData * cdata = m_componentDataList.at(index);
    if (!cdata) {
        qDebug() << "ComponentData with index " << index << " does not exist";
        return nullptr;
    }

    QString partName = cdata->getPartName();

    // TODO: Create getFootprint(realname) and use it instead of m_footprintsList.at(index)
    Footprint * fpt = getFootprint(partName);
    if (!fpt) {
        qDebug() << "Cannot find footprint with name " << partName;
        return nullptr;
    }
    double x = cdata->getCenterX() - (fpt->bodyWidth() / 2);
    double y = cdata->getCenterY() - (fpt->bodyHeight() / 2);
    qDebug() << "Part : " << partName;
    qDebug() << "X : " << x;
    qDebug() << "Y : " << y;


    BoardArray * ba = getBoardArray(cdata->getBoardNumber()-1);
    if (!ba) {
        qDebug() << "Cannot find boardarray with num=" << cdata->getBoardNumber();
    }

    const double SCALE = 10;//20;


    Component * cc = new Component();
    cc->setPartName(cdata->getPartName());
    cc->setRealName(cdata->getRealName());
    cc->setSide(cdata->getSi());
    cc->setNumber(0);

    if (ba) {
        cc->setBoardArray(*ba);
    }
    // TODO: Use componentData->realX() and componentData->realY()
    //cc->setPoint((0*index)*SCALE,(0*index)*SCALE);

    cc->setPoint( x*SCALE, y*SCALE);
    cc->setSize(fpt->bodyWidth()*SCALE, fpt->bodyHeight()*SCALE);
    cc->setRotateAngle(cdata->getRot());

    /*
    qreal dia = 1.;
    qreal w=0.;
    qreal h=0.;
    Pin * pin0 = fpt->getPins().at(0);
    if (pin0) {
        int pd = pin0->pinpd();
        for (Pd * item : m_pdList) {
            if (item->m_num == pd && item->m_shapetype =="cir") {
               // radius = item->m_shapeDia/2.;
               // radius = item->m_roiH/2.;
                dia = item->m_shapeDia;
                for(Pin* pin : fpt->getPins()) {
                    cc->addPin(pin->pinx()*SCALE, pin->piny()*SCALE, dia*SCALE);

                }
              //  break;
            }
            else if(item->m_num == pd && (item->m_shapetype == "rc" || item->m_shapetype== "rec" ||item->m_shapetype=="ob")){
                w=item->m_shapeW;
                h=item->m_shapeH;
                for(Pin* pin : fpt->getPins()) {
                    cc->addRect(pin->pinx()*SCALE, pin->piny()*SCALE, w*SCALE, h*SCALE);

                }
               // break;

            }
        }
    }
*/
    for (auto pin: fpt->getPins()) {
        int pdNum = pin->pinpd();
        auto pdItem = getPd(pdNum);
        if (pdItem->m_shapetype == "cir") {
            cc->addPin(pin->pinx()*SCALE, pin->piny()*SCALE, pdItem->m_shapeDia*SCALE);
        }
        else if (pdItem->m_shapetype == "rc" || pdItem->m_shapetype== "rec" || pdItem->m_shapetype=="ob") {
            cc->addRect(pin->pinx()*SCALE, pin->piny()*SCALE,
                        pdItem->m_shapeW*SCALE, pdItem->m_shapeH*SCALE, pin->pinrot()+pdItem->m_roiRot);
        }
        else if (pdItem->m_shapetype == "poly"){
            QVector<QPointF> listPts;
            for(auto& item: pdItem->points()) {
                listPts.append(QPointF(item.x()*SCALE, item.y()*SCALE));
            }
            cc->addPoly(pin->pinx()*SCALE, pin->piny()*SCALE,listPts);
        }
        //else poly {}
    }



    // footprint
    // pins
    // pd

    return cc;
}

Footprint *Board::getFootprint(const QString &partName)
{
    QString footName = partName;
    if (m_partMap.contains(partName))
        footName = m_partMap.value(partName);

    for (Footprint * fpt : m_footprintsList) {
        if (fpt->footName() == footName)
            return fpt;
    }

    return nullptr;
}

BoardArray *Board::getBoardArray(int index) const
{
    if (index < m_boardArrayList.size()) {
        return m_boardArrayList.at(index);
    }

    return nullptr;
}

BoardGroup *Board::getBoardGroup(const int grName)
{
    for (BoardGroup * gr : m_boardGroupList) {
        if (gr->getGrName() == grName)
            return gr;
    }

    return nullptr;
}

Pd *Board::getPd(int pd) const
{
    for(Pd* pdElem : m_pdList) {
        if (pdElem->m_num == pd)
            return pdElem;
    }
    return nullptr;
}

double Board::boardWidth() const
{
    return m_info.boardWidth();
}

double Board::boardHeight() const
{
    return m_info.boardHeight();
}
