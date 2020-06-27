#ifndef ABOUTWND_H
#define ABOUTWND_H

#include <QDialog>

namespace Ui {
class AboutWnd;
}

class AboutWnd : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWnd(QWidget *parent = nullptr);
    ~AboutWnd();

private:
    Ui::AboutWnd *ui;
};

#endif // ABOUTWND_H
