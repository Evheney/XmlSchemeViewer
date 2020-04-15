#include <QDebug>
#include "footprints.h"

Footprint::Footprint()
{

}

void Footprint::addPin(Pin *pin)
{
    pins.append(pin);
}

void Footprint::print() const
{
    qDebug() << "Footprint name is:" << m_footName << "bodyheight:" << m_footh << "bodywidth:" <<m_footw;

    //qDebug() << "Pin name is:" << m_pinName << "pin size:" << m_pinpd << "pin X:" <<m_pinx <<"pin Y:"<< m_piny;
}
