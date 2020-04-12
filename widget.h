#ifndef WIDGET_H
#define WIDGET_H

#include "scheme.h"
#include <QGraphicsScene>
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

private:
    Ui::Widget *ui;
    QGraphicsScene* m_scene;
};

#endif // WIDGET_H
