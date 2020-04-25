#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"
#include "scheme.h"
#include "xmlboardreader.h"

#include <QDebug>
#include <QFile>
#include <QMessageBox>

#include <QFileDialog>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_view(nullptr)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);
//    m_scene->addLine(-400,0,400,0, QPen(Qt::blue));
//    m_scene->addLine(0,-400,0,400, QPen(Qt::blue));
//    m_scene->setSceneRect(-800,-400,1600,800);


    m_view = new GraphicsView(this);
    m_view->setScene(m_scene);

    m_view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_view ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->viewLayout->addWidget(m_view);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionZoom_In_triggered()
{
    m_view->zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    m_view->zoomOut();
}

void MainWindow::on_actionFit_to_content_triggered()
{
    m_view->zoomFit();
}

void MainWindow::on_actionExport_triggered()
{
    // TODO: move to Scene RenderPng()
    QRectF rect(m_scene->itemsBoundingRect());
    QRect myRect = rect.toRect();

    qreal sx = 1; //m_view->transform().m11();
    qreal sy = -1; //m_view->transform().m22();
    qDebug() << "SX : " << sx;
    qDebug() << "SY : " << sy;
    myRect.setSize(QSize(myRect.width()*sx, myRect.height()*abs(sy)));

    //qDebug() << "RenderPng myRect: " << myRect;

    QPixmap pixmap = QPixmap(myRect.size());
    QString filename = QFileDialog::getSaveFileName(
                nullptr, tr("Save As Image"), "Image", tr("PNG Image (*.png)"));
                //"PNG Images (*.png);;BMP images (*.bmp);;JPG images (*.jpg)");

    if( !filename.isEmpty() )
    {
        QPainter painter( &pixmap );
        painter.setBrush(QBrush(QColor(Qt::white)));
        painter.drawRect(myRect);
        painter.setTransform(QTransform().scale(sx, sy));
        painter.translate(0, -rect.height());
        painter.setRenderHint(QPainter::Antialiasing);
        m_scene->render( &painter, pixmap.rect(), myRect, Qt::KeepAspectRatio );
        painter.end();

        pixmap.save(filename,"PNG");

//            QFileInfo fileInfo(filename);
//            QString ext = fileInfo.completeSuffix();

//            if (ext.toLower() == "bmp")
//                pixmap.save(filename,"BMP");
//            else if (ext.toLower() == "png")
//                pixmap.save(filename,"PNG");
//            else
//                pixmap.save(filename,"JPG");
    }
}

void MainWindow::addScheme(const Scheme &scheme)
{
    const double SCALE = 10;
    const double sceneOffsX = 20;
    const double sceneOffsY = 20;

    Board * board = scheme.getBoard();

    m_scene->setSceneRect(-sceneOffsX,-sceneOffsY,
                          board->boardWidth()*SCALE + sceneOffsX,
                          board->boardHeight()*SCALE + sceneOffsY);
    m_scene->addRect(0,0,board->boardWidth()*SCALE,board->boardHeight()*SCALE);


    drawBoardArrays(scheme);

    const int size = scheme.getComponentSize();
    for (int index=0; index < size; ++index) {
        Component* component = scheme.getComponent(index);
        drawComponent(*component);
    }
}

void MainWindow::drawComponent(const Component& component)
{
    QPointF pt = component.getPoint();
    QSizeF sz = component.getSize();

    QGraphicsRectItem *rectItem = m_scene->addRect(
                pt.x(),pt.y(),sz.width(),sz.height(),
                QPen(Qt::NoPen),QBrush(QColor(0, 0, 255, 32), Qt::SolidPattern));

    //int ee = QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable;
    //qDebug() << ee;
    rectItem->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
    rectItem->setFocus();

    const int circleCount = component.getNumCircles();
    for (int index=0; index<circleCount; ++index) {
        QRectF r = component.getCircle(index);
        r.adjust(pt.x(),pt.y(), pt.x(),pt.y());

        QGraphicsEllipseItem * ellipseItem = m_scene->addEllipse(r);
        ellipseItem->setParentItem(rectItem);
    }

    // TODO: rotate only if necessary
    if (!qFuzzyIsNull(component.rotateAngle())) {
        QPointF ptOrg = QPointF(pt.x()+sz.width()/2, pt.y()+sz.height()/2);
        rectItem->setTransformOriginPoint(ptOrg);
        rectItem->setRotation(component.rotateAngle());
    }
}

void MainWindow::drawBoardArrays(const Scheme &scheme)
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


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Open ePMXray file"), "", tr("XML file (*.xml)"));

    m_scene->clear();

    //QString fileName("testnk.xml");
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file " << fileName << ". Error:" << file.errorString();

        QString messageText = QString("Cannot read the file %1.").arg(fileName);
        QString errorText = QString("<b>Error:</b> %2").arg(file.errorString());

        QMessageBox msgBox;
        msgBox.setWindowTitle(QApplication::applicationName());
        msgBox.setText(messageText);
        msgBox.setInformativeText(errorText);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }

    Scheme scheme;
    XmlBoardReader parser(&scheme);
    parser.read(&file);
    //parser.print();

    addScheme(scheme);
}
