#ifndef EPMXRAYINFO_H
#define EPMXRAYINFO_H

#include "QString"

class EpmXrayInfo
{
public:
    EpmXrayInfo();

    void print() const;

    QString m_formatVer;
    QString m_formatName;

    QString m_programVer;
    QString m_programName;
    QString m_programDate;

    QString m_unitName;
    QString m_unitCoord;
    QString m_unitDecpt;
};

#endif // EPMXRAYINFO_H
