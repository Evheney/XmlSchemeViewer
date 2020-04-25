#include "graphicsview.h"
//#include "widget.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QGuiApplication>
#include <QPropertyAnimation>
#include <QScreen>
#include <QTimer>

namespace  {
const double zoomFactor = 1.25;
const double MAX_SCALE = 100;
const double MIN_SCALE = 0.1;
};

bool GraphicsView::smoothZoom = false;
GraphicsView* GraphicsView::self = nullptr;
double GraphicsView::SX = 1.0;   // initial hozirontal scale (1.0: normal)
double GraphicsView::SY = -1.0;   // initial vertical scale (-1.0: flipped)

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setDragMode(RubberBandDrag);
    setRubberBandSelectionMode(Qt::IntersectsItemBoundingRect);

    //setStyleSheet("QGraphicsView { background: black }");

    //scale(1.0, 1.0); // general view coordinate: 0 at top-left
    scale(1.0, -1.0); //flip vertical: 0 at bottom-left, as in real world
    GraphicsView::SX = transform().m11();
    GraphicsView::SY = transform().m22();

    qDebug() << "Initial horizontal scale SX:" << GraphicsView::SX;
    qDebug() << "Initial vertical scale SY:" << GraphicsView::SY;

    self = this;
}


void GraphicsView::zoomFit()
{
    scene()->setSceneRect(scene()->itemsBoundingRect());
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}

void GraphicsView::zoomToSelected()
{
    if (self == nullptr)
        return;

    QRectF rect;
    for (const QGraphicsItem* item : self->scene()->selectedItems()) {
        const QRectF tmpRect(item->pos().isNull() ? item->boundingRect() : item->boundingRect().translated(item->pos()));
        rect = rect.isEmpty() ? tmpRect : rect.united(tmpRect);
    }
    if (rect.isEmpty())
        return;

    const double k = 5.0 / self->transform().m11();
    rect += QMarginsF(k, k, k, k);
    if (GraphicsView::smoothZoom) { // && /* DISABLES CODE */ (0)) {
        // Reset the view scale to 1:1.
        QRectF unity = self->matrix().mapRect(QRectF(0, 0, 1, 1));
        if (unity.isEmpty())
            return;
        self->scale(1 / unity.width(), 1 / unity.height());
        // Find the ideal x / y scaling ratio to fit \a rect in the view.
        int margin = 2;
        QRectF viewRect = self->viewport()->rect().adjusted(margin, margin, -margin, -margin);
        if (viewRect.isEmpty())
            return;
        QRectF sceneRect = self->matrix().mapRect(rect);
        if (sceneRect.isEmpty())
            return;
        qreal xratio = viewRect.width() / sceneRect.width();
        qreal yratio = viewRect.height() / sceneRect.height();

        // Respect the aspect ratio mode.
        //switch (self->aspectRatioMode) {
        //case Qt::KeepAspectRatio:
        //    xratio = yratio = qMin(xratio, yratio);
        //    break;
        //case Qt::KeepAspectRatioByExpanding:
            xratio = yratio = qMax(xratio, yratio);
        //    break;
        //case Qt::IgnoreAspectRatio:
        //    break;
        //}

        qDebug() << "Scene rect: " << sceneRect << ", rect: " << rect;

        // Scale and center on the center of \a rect.
        self->scale(xratio, yratio);
        self->centerOn(rect.center());
        self->anim(self, "sceneRect", sceneRect/*self->scene()->sceneRect()*/, rect);


        self->fitInView(rect, Qt::KeepAspectRatio);
        //self->updateRuler();
    } else {
        const double k = 10 * self->scaleFactor();
        self->fitInView(rect + QMarginsF(k, k, k, k), Qt::KeepAspectRatio);
        //self->updateRuler();
    }
}

void GraphicsView::zoom100()
{
    if (self == nullptr)
        return;
    double x = 1.0, y = 1.0;
    const double m11 = self->QGraphicsView::transform().m11(), m22 = self->QGraphicsView::transform().m22();
    if (/* DISABLES CODE */ (0)) {
        x = qAbs(1.0 / m11 / (25.4 / self->physicalDpiX()));
        y = qAbs(1.0 / m22 / (25.4 / self->physicalDpiY()));
    } else {
        const QSizeF size(QGuiApplication::screens()[0]->physicalSize()); //(GetEdid()); // size in mm
        const QRect scrGeometry(QGuiApplication::primaryScreen()->geometry()); // size in pix
        x = qAbs(1.0 / m11 / (size.height() / scrGeometry.height()));
        y = qAbs(1.0 / m22 / (size.width() / scrGeometry.width()));
    }

    if (GraphicsView::smoothZoom) {
        const double maxZoom = (std::max)(x,y);
        self->anim(self, "scale", getScale(), maxZoom);
    } else {
        self->scale(x, y);
        //self->updateRuler();
    }
}

void GraphicsView::zoomIn()
{
    if (self == nullptr)
        return;
    if (getScale() > MAX_SCALE)
        return;

    if (GraphicsView::smoothZoom) {
        self->anim(self, "scale", getScale(), getScale() * zoomFactor);
    } else {
        self->scale(zoomFactor, zoomFactor);
        //self->updateRuler();
    }
}

void GraphicsView::zoomOut()
{
    if (self == nullptr)
        return;
    if (getScale() < MIN_SCALE)
        return;

    if (GraphicsView::smoothZoom) {
        self->anim(self, "scale", getScale(), getScale() * (1.0 / zoomFactor));
    } else {
        self->scale(1.0 / zoomFactor, 1.0 / zoomFactor);
        //self->updateRuler();
    }
}

double GraphicsView::scaleFactor()
{
    return 1.0 / getScale();
}

void GraphicsView::setScale(double s)
{
    const auto trf = transform();
    setTransform({ s*GraphicsView::SX /*11*/, trf.m12(), trf.m13(),
                   trf.m21(), s*GraphicsView::SY /*22*/, trf.m23(),
                   trf.m31(), trf.m32(), trf.m33() });
}

double GraphicsView::getScale()
{
    if (self == nullptr)
        return 1.0;
    return transform().m11();
}


void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QGraphicsView::mousePressEvent(event);

    //Widget * w = dynamic_cast<Widget*>(parentWidget());
    //if (w) {
    //    w->updateUiBySelection(scene()->selectedItems());
    //}
}


class PropertyAnimation : public QPropertyAnimation {
public:
    PropertyAnimation(QObject* target, const QByteArray& propertyName, QObject* parent = nullptr)
        : QPropertyAnimation(target, propertyName, parent)
    {
    }
    ~PropertyAnimation() override
    {
        qDebug() << "~PropertyAnimation()";
    }
};
template <class T>
void GraphicsView::anim(QObject* target, const QByteArray& propertyName, T begin, T end)
{
    const int duration = 200;
    auto* animation = new PropertyAnimation(target, propertyName);
    //connect(animation, &QPropertyAnimation::finished, this, &GraphicsView::updateRuler);
    animation->setDuration(duration);

    qDebug() << "Animation zoom from " << begin << " to " << end;

    animation->setStartValue(begin);
    animation->setEndValue(end);
    animation->start();
    QTimer::singleShot(duration + 1, [animation] { delete animation; });
}
