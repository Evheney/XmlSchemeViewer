#ifndef EPMXRAYINFO_H
#define EPMXRAYINFO_H

#include "QString"

class EpmXrayInfo
{
public:
    EpmXrayInfo();

    void print() const;
    QString formatVer() const;
    void setFormatVer(const QString &formatVer);

    QString formatName() const;
    void setFormatName(const QString &formatName);

    QString programVer() const;
    void setProgramVer(const QString &programVer);

    QString programName() const;
    void setProgramName(const QString &programName);

    QString programDate() const;
    void setProgramDate(const QString &programDate);

    QString unitName() const;
    void setUnitName(const QString &unitName);

    QString unitCoord() const;
    void setUnitCoord(const QString &unitCoord);

    QString unitDecpt() const;
    void setUnitDecpt(const QString &unitDecpt);


    double boardWidth() const;
    void setBoardWidth(double boardWidth);

    double boardHeight() const;
    void setBoardHeight(double boardHeight);

private:
    QString m_formatVer;
    QString m_formatName;

    QString m_programVer;
    QString m_programName;
    QString m_programDate;

    QString m_unitName;
    QString m_unitCoord;
    QString m_unitDecpt;

    double m_boardWidth;
    double m_boardHeight;
};

#endif // EPMXRAYINFO_H
