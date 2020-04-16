#include "widget.h"
#include "ui_widget.h"
#include "view.h"
#include "scene.h"
#include "rect.h"
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);

    //m_scene->setBackgroundBrush(QBrush(QColor(Qt::yellow)));
    m_scene->setSceneRect(-400,-400,800,800);
    m_scene->addLine(0,-400,0,400);
    m_scene->addLine(-400,0,400,0);

    QGraphicsView * view = new QGraphicsView(this);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->scale(2,2);

    view->setScene(m_scene);

    ui->verticalLayout->addWidget(view);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addScheme(const Scheme &scheme)
{
    const int size = scheme.getComponentSize();
    for (int index=0; index < size; ++index) {
        Component* component = scheme.getComponent(index);
        drawComponent(*component);
    }
}

void Widget::drawComponent(const Component& component)
{
    QPointF pt = component.getPoint();
    QSizeF sz = component.getSize();

    QGraphicsRectItem *rectItem = m_scene->addRect(
                pt.x(),pt.y(),sz.width(),sz.height(),
                QPen(Qt::NoPen),QBrush(QColor(0, 0, 255, 32), Qt::SolidPattern));

    int ee = QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable;
    qDebug() << ee;
    rectItem->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    rectItem->setFocus();

    const int circleCount = component.getNumCircles();
    for (int index=0; index<circleCount; ++index) {
        QRectF r = component.getCircle(index);
        QGraphicsEllipseItem * ellipseItem = m_scene->addEllipse(r);
        ellipseItem->setParentItem(rectItem);
    }
}

