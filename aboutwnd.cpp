#include "aboutwnd.h"
#include "ui_aboutwnd.h"

AboutWnd::AboutWnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWnd)
{
    ui->setupUi(this);
}

AboutWnd::~AboutWnd()
{
    delete ui;
}
