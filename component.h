#ifndef COMPONENT_H
#define COMPONENT_H

#include "boardarray.h"

#include <QRectF>
#include <QList>

class Component
{
public:
    Component();
    ~Component();

    void addPin(qreal x, qreal y, qreal radius);
    //void setBoardArray()

    void setNumber(int n);
    void setPoint(qreal x, qreal y);
    void setSize(qreal sx, qreal sy);
    void setRealName(const QString &value);
    void setPartName(const QString &value);
    void setRotateAngle(double value);

    QPointF getPoint() const;
    QSizeF getSize() const;
    QRectF getCircle(int index) const;
    int getNumCircles() const;
    double rotateAngle() const;

    QString getRealName() const;
    QString getPartName() const;

    BoardArray getBoardArray() const;
    void setBoardArray(const BoardArray &value);

protected:
    BoardArray boardArray;

    QString realName; // U1001
    QString partName; // ****-****-****-****

    int number;
    QPointF point;
    QSizeF size;
    //QRectF rect;
    QList<QRectF> circles;
    double rotAngle; // degree

    void calcOffset() {
        offsetx = size.width() / 2.;
        offsety = size.height() / 2.;
    }

private:
    double offsetx;
    double offsety;
};

#endif // COMPONENT_H
