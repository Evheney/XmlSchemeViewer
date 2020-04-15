#ifndef FOOTPRINTS_H
#define FOOTPRINTS_H

#include <QString>
#include <QList>

class Pin {
public:
    QString m_pinName;
    double m_piny;
    double m_pinx;
    double m_pinrot;
    int m_pinpd;
};
class Footprint
{
public:
    Footprint();

    QString m_footName;
    double m_footh;
    double m_footw;


    void addPin(Pin* pin);

//protected:
    QList<Pin*> pins;

    void print() const;
//private:
//    const double offsetx;
//    const double offsety;
};

#endif // FOOTPRINTS_H
