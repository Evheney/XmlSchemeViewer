#include <QDebug>

#include "board.h"

Board::~Board()
{
    qDebug() << "Board Destructor";

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

    qDebug() << "End Board Destructor";
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
    qDebug() << "Print board infos";
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


    qDebug() << "\nBoard createComponent " << index;

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
    cc->setNumber(0);

    if (ba) {
        cc->setBoardArray(*ba);
    }
    // TODO: Use componentData->realX() and componentData->realY()
    //cc->setPoint((0*index)*SCALE,(0*index)*SCALE);

    cc->setPoint( x*SCALE, y*SCALE);
    cc->setSize(fpt->bodyWidth()*SCALE, fpt->bodyHeight()*SCALE);
    cc->setRotateAngle(cdata->getRot());

    qreal radius = 1.;
    Pin * pin0 = fpt->getPins().at(0);
    if (pin0) {
        int pd = pin0->pinpd();
        for (Pd * item : m_pdList) {
            if (item->m_num == pd) {
                radius = item->m_shapeDia/2.;
                break;
            }
        }
    }
    for(Pin* pin : fpt->getPins()) {
        cc->addPin(pin->pinx()*SCALE, pin->piny()*SCALE, radius*SCALE);
    }

    // footprint
        // pins
    // pd

    return cc;
}

Footprint *Board::getFootprint(const QString &partName)
{
    for (Footprint * fpt : m_footprintsList) {
        if (fpt->footName() == partName)
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

double Board::boardWidth() const
{
    return m_info.boardWidth();
}

double Board::boardHeight() const
{
    return m_info.boardHeight();
}
