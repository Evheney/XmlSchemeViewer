#include <QDebug>
#include "epmxrayinfo.h"

EpmXrayInfo::EpmXrayInfo()
{

}

void EpmXrayInfo::print() const
{
    qDebug() << "Format ver:" << m_formatVer << "name:" << m_formatName;
    qDebug() << "Program ver:" << m_programVer << "name:" << m_programName << "date:" << m_programDate;
    qDebug() << "Unit name:" << m_unitName << "coord" << m_unitCoord << "decpt" << m_unitDecpt;
}
