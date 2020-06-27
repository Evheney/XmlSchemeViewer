#include "shapepoly.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsScene>

ShapePoly::ShapePoly(qreal x,qreal y,const QVector<QPointF> &listPts)
{
    for(auto& item: listPts) {
        m_listPts.append(QPointF(item.x()+x, item.y()+y));
    }
}



QAbstractGraphicsShapeItem *ShapePoly::getItem(QGraphicsScene *s, const QPointF &pt)
{
//    QRectF r = getRect();
//    r.adjust(pt.x(),pt.y(), pt.x(),pt.y());

    QPolygonF poly; // = m_listPts;
    for(auto& item: m_listPts) {
        poly.append(QPointF(item.x()+pt.x(), item.y()+pt.y()));
    }
    QGraphicsPolygonItem * Item = s->addPolygon(poly/*m_listPts*/);
    //Item ->moveBy(pt.x(),pt.y());
    return Item;

}

