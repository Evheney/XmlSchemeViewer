#include <QDebug>
#include "footprints.h"

Footprint::Footprint()
   // :SCALE(10)
{

}

QList<Pin *> Footprint::getPins() const
{
    return pins;
}

int Footprint::getPinCount() const
{
    return  pins.size();
}

Pin *Footprint::getPin(int index)
{
    return pins.at(index);
}

double Footprint::bodyWidth() const
{
    return m_bodyWidth;
}

void Footprint::setBodyWidth(double footw)
{
    m_bodyWidth = footw;
}

double Footprint::bodyHeight() const
{
    return m_bodyHeight;
}

void Footprint::setBodyHeight(double footh)
{
    m_bodyHeight = footh;
}

QString Footprint::footName() const
{
    return m_footName;
}

void Footprint::setFootName(const QString &footName)
{
    m_footName = footName;
}

void Footprint::addPin(Pin *pin)
{
    pins.append(pin);
}

void Footprint::print() const
{
    qDebug() << "Footprint name is:" << m_footName << "bodyheight:" << m_bodyHeight << "bodywidth:" <<m_bodyWidth;

    //qDebug() << "Pin name is:" << m_pinName << "pin size:" << m_pinpd << "pin X:" <<m_pinx <<"pin Y:"<< m_piny;
}

QString Pin::pinName() const
{
    return m_pinName;
}

void Pin::setPinName(const QString &pinName)
{
    m_pinName = pinName;
}

double Pin::piny() const
{
    return m_piny;
}

void Pin::setPiny(double piny)
{
    m_piny = piny;
}

double Pin::pinx() const
{
    return m_pinx;
}

void Pin::setPinx(double pinx)
{
    m_pinx = pinx;
}

double Pin::pinrot() const
{
    return m_pinrot;
}

void Pin::setPinrot(double pinrot)
{
    m_pinrot = pinrot;
}

int Pin::pinpd() const
{
    return m_pinpd;
}

void Pin::setPinpd(int pinpd)
{
    m_pinpd = pinpd;
}
