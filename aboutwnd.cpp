#include "aboutwnd.h"
#include "ui_aboutwnd.h"
#include "version.h"

AboutWnd::AboutWnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWnd)
{
    ui->setupUi(this);
    ui->version->setText(QString("Version ") + VER_PRODUCTVERSION_STR);
    ui->buildDate->setText(QString("Build ") + __DATE__);
}

AboutWnd::~AboutWnd()
{
    delete ui;
}
