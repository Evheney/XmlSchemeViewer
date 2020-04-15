#ifndef PD_H
#define PD_H

#include "QString"

class Pd
{
public:

    Pd();

    int m_num;
    double m_roiH;
    double m_roiW;
    double m_roiRot;
    double m_roiperi;
    double m_roiarea;

    QString m_shapetype;
    double m_shapeperi;
    double m_shapearea;
    double m_shapeDia;

    void print() const;

};

#endif // PD_H
