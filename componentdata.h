#ifndef COMPONENTDATA_H
#define COMPONENTDATA_H

#include <QList>
#include <QString>
#include <QStringList>

class ComponentData
{
public:
    ComponentData();
    ~ComponentData();

    double getCenterX() const;
    double getCenterY() const;
    double getRot() const;
    QString getRealName() const;
    QString getPartName() const;
    int getBoardNumber() const;
    QString getBlockName() const;

    void setCenterX(double value);
    void setCenterY(double value);
    void setRot(double value);
    void setRealName(const QString &value);
    void setPartName(const QString &value);
    void setBoardNumber(int value);
    void setBlockName(const QString &value);

private:
    double centerX;
    double centerY;
    double rot;

    QString realName;
    QString partName;

    int boardNumber=0;
    QString blockName;
};

#endif // COMPONENTDATA_H
