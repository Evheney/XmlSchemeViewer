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

QString EpmXrayInfo::formatVer() const
{
    return m_formatVer;
}

void EpmXrayInfo::setFormatVer(const QString &formatVer)
{
    m_formatVer = formatVer;
}

QString EpmXrayInfo::formatName() const
{
    return m_formatName;
}

void EpmXrayInfo::setFormatName(const QString &formatName)
{
    m_formatName = formatName;
}

QString EpmXrayInfo::programVer() const
{
    return m_programVer;
}

void EpmXrayInfo::setProgramVer(const QString &programVer)
{
    m_programVer = programVer;
}

QString EpmXrayInfo::programName() const
{
    return m_programName;
}

void EpmXrayInfo::setProgramName(const QString &programName)
{
    m_programName = programName;
}

QString EpmXrayInfo::programDate() const
{
    return m_programDate;
}

void EpmXrayInfo::setProgramDate(const QString &programDate)
{
    m_programDate = programDate;
}

QString EpmXrayInfo::unitName() const
{
    return m_unitName;
}

void EpmXrayInfo::setUnitName(const QString &unitName)
{
    m_unitName = unitName;
}

QString EpmXrayInfo::unitCoord() const
{
    return m_unitCoord;
}

void EpmXrayInfo::setUnitCoord(const QString &unitCoord)
{
    m_unitCoord = unitCoord;
}

QString EpmXrayInfo::unitDecpt() const
{
    return m_unitDecpt;
}

void EpmXrayInfo::setUnitDecpt(const QString &unitDecpt)
{
    m_unitDecpt = unitDecpt;
}

double EpmXrayInfo::boardWidth() const
{
    return m_boardWidth;
}

void EpmXrayInfo::setBoardWidth(double boardWidth)
{
    m_boardWidth = boardWidth;
}

double EpmXrayInfo::boardHeight() const
{
    return m_boardHeight;
}

void EpmXrayInfo::setBoardHeight(double boardHeight)
{
    m_boardHeight = boardHeight;
}
