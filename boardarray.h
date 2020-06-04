#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <QString>
#include <QStringList>

class BoardArray
{
public:
    BoardArray();
    BoardArray(int num, QString name, double x, double y, double rotate, int grN);

    int getNum() const;
    QString getName() const;
    double getX() const;
    double getY() const;
    double getRotate() const;
    int getGrName() const;


//    void setNum(int value);
//    void setName(const QString &value);
//    void setX(double value);
//    void setY(double value);
//    void setRotate(double value);


private:
    int num;
    QString name;
    double x;
    double y;
    double rotate;
    int grName;
};

#endif // BOARD_INFO_H

