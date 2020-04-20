#if 0
#ifndef WIDGET_H
#define WIDGET_H

#include "scheme.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public:
    void addScheme(const Scheme& scheme);
    void drawComponent (const Component& component);
    void drawBoardArrays(const Scheme& scheme);

private:
    Ui::Widget *ui;
    QGraphicsScene* m_scene;
    QGraphicsView * m_view;
};

#endif // WIDGET_H
#endif
