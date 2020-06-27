#ifndef COMPONENT_H
#define COMPONENT_H

#include <QRectF>
#include <QList>

#include "boardarray.h"
//#include "footprints.h"
#include "shape.h"

class Component
{
public:
    Component();
    ~Component();

    void addPin(qreal x, qreal y, qreal dia);
    void addRect(qreal x, qreal y, qreal w, qreal h, qreal rot);
    void addPoly(qreal x, qreal y, const QVector<QPointF> &listPts);
    //void setBoardArray()

    void setNumber(int n);
    void setPoint(qreal x, qreal y);
    void setSize(qreal sx, qreal sy);
    void setRealName(const QString &value);
    void setPartName(const QString &value);
    void setRotateAngle(double value);

    QPointF getPoint() const;
    QSizeF getSize() const;
    int getNumShapes() const;
    Shape* getShape(int index) const;
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
    QList<Shape*> shapes;
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
