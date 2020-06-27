#ifndef PD_H
#define PD_H

#include "QString"
#include <QList>
#include <QPointF>
#include <QVector>

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
    double m_shapeW;
    double m_shapeH;

    void print() const;

    QVector<QPointF> points() const;
    void addPoint(qreal xpos,qreal ypos);

private:

    QVector<QPointF> m_points;

};

#endif // PD_H
