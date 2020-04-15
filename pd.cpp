#include <QDebug>
#include "pd.h"

Pd::Pd()
{

}

void Pd::print() const
{
    qDebug() << "Pd number is:" << m_num << "h:" << m_roiH << "w:" << m_roiW << "rot:" << m_roiRot << "perimetr:" << m_roiperi << "area:" << m_roiarea ;
    qDebug() << "Shape type is" << m_shapetype << "perimeter:" << m_shapeperi << "area:" << m_shapearea<< "dia:" << m_shapeDia ;
}
