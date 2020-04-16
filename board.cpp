#include <QDebug>

#include "board.h"

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

void Board::addBoardName(Board_info *board_info)
{
    m_BoardInfoList.append(board_info);
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
    qDebug() << "Board createComponent " << index;

    if (index < 0 || index >= m_footprintsList.size())
        return nullptr;

    // TODO: Create getFootprint(realname) and use it instead of m_footprintsList.at(index)
    Footprint * fpt = m_footprintsList.at(index);
    if (!fpt)
        return nullptr;

    const double SCALE = 10;//20;


    Component * cc = new Component();

    cc->setNumber(0);

    // TODO: Use componentData->realX() and componentData->realY()
    cc->setPoint((0*index)*SCALE,(0*index)*SCALE);
    cc->setSize(fpt->m_footw*SCALE, fpt->m_footh*SCALE);

    qreal radius = 1.;
    Pin * pin0 = fpt->pins.at(0);
    if (pin0) {
        int pd = pin0->m_pinpd;
        for (Pd * item : m_pdList) {
            if (item->m_num == pd) {
                radius = item->m_shapeDia/2.;
                break;
            }
        }
    }
    for(Pin* pin : fpt->pins) {
        cc->addPin(pin->m_pinx*SCALE, pin->m_piny*SCALE, radius*SCALE);
    }

    // footprint
        // pins
    // pd

    return cc;
}
