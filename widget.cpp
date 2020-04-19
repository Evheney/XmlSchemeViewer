#include "widget.h"
#include "ui_widget.h"
//#include "view.h"
//#include "scene.h"
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
    //m_scene->setSceneRect(0,0,1800,1800);
    //m_scene->addLine(0,-400,0,400);
    //m_scene->addLine(-400,0,400,0);

    m_view = new QGraphicsView(this);
    m_view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_view ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //m_view->scale(1,-1);

    m_view->setScene(m_scene);

    ui->verticalLayout->addWidget(m_view);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addScheme(const Scheme &scheme)
{
    const double SCALE = 10;
    const double sceneOffsX = 20;
    const double sceneOffsY = 20;

    Board * board = scheme.getBoard();

    m_scene->setSceneRect(-sceneOffsX,-sceneOffsY,
                          board->boardWidth()*SCALE + sceneOffsX,
                          board->boardHeight()*SCALE + sceneOffsY);
    m_scene->addRect(0,0,board->boardWidth()*SCALE,board->boardHeight()*SCALE);
    m_view->scale(1,-1);

    drawBoardArrays(scheme);

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

    int ee = QGraphicsItem::ItemIsFocusable /*| QGraphicsItem::ItemIsMovable*/ | QGraphicsItem::ItemIsSelectable;
    qDebug() << ee;
    rectItem->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    rectItem->setFocus();

    const int circleCount = component.getNumCircles();
    for (int index=0; index<circleCount; ++index) {
        QRectF r = component.getCircle(index);
        r.adjust(pt.x(),pt.y(), pt.x(),pt.y());
        //r.moveTo(pt);

        QGraphicsEllipseItem * ellipseItem = m_scene->addEllipse(r);
        ellipseItem->setParentItem(rectItem);
    }
}

void Widget::drawBoardArrays(const Scheme &scheme)
{
    // TODO: Declare SCALE in header file
    const double SCALE = 10.;

    int index=0;
    while(true){
        BoardArray* ba = scheme.getBoardArray(index);
        if(ba == nullptr) {
            break;
        }

        qreal x = (ba->getX() + 2.076)*SCALE;
        qreal y = (ba->getY() + 13.198)*SCALE;
        qreal w = 60.432*SCALE;
        qreal h = 84.651*SCALE;

        m_scene->addRect(x,y,w,h,QPen(Qt::NoPen),QBrush(QColor(40, 0, 76, 16), Qt::SolidPattern));
        ++index;
    }

//    const int size = scheme.getBoardArraySize();
//    for (int index=0; index < size; ++index) {
//        BoardArray* ba = scheme.getBoardArray(index);
//        //drawBoard(*ba);
//    }

}

