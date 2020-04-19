#ifndef COMPONENTDATA_H
#define COMPONENTDATA_H

#include <QList>
#include <QString>
#include <QStringList>

class ComponentData
{
public:
    ComponentData();

    double getRealX() const;
    double getRealY() const;
    double getRot() const;
    QString getRealName() const;
    QString getPartName() const;
    int getBoardNumber() const;
    QString getBlockName() const;

    void setRealX(double value);
    void setRealY(double value);
    void setRot(double value);
    void setRealName(const QString &value);
    void setPartName(const QString &value);
    void setBoardNumber(int value);
    void setBlockName(const QString &value);

private:
    double realX;
    double realY;
    double rot;

    QString realName;
    QString partName;

    int boardNumber=0;
    QString blockName;
};

#endif // COMPONENTDATA_H
