#ifndef FOOTPRINTS_H
#define FOOTPRINTS_H

#include <QString>
#include <QList>

class Pin {
public:

    QString pinName() const;
    void setPinName(const QString &pinName);

    double piny() const;
    void setPiny(double piny);

    double pinx() const;
    void setPinx(double pinx);

    double pinrot() const;
    void setPinrot(double pinrot);

    int pinpd() const;
    void setPinpd(int pinpd);

private:
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

    QString footName() const;
    void setFootName(const QString &footName);

    double bodyHeight() const;
    void setBodyHeight(double bodyHeight);

    double bodyWidth() const;
    void setBodyWidth(double bodyWidth);

    void addPin(Pin* pin);
    void print() const;

    QList<Pin *> getPins() const;
    int getPinCount() const;
    Pin * getPin(int index);

private:
   // double SCALE;
    QString m_footName;
    double m_bodyHeight;
    double m_bodyWidth;

    QList<Pin*> pins;
};

#endif // FOOTPRINTS_H
