#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include "graphicsview.h"
#include "scheme.h"
#include "boardgroup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool openScheme(const QString& fileName);
    bool addScheme(const Scheme& scheme);
    bool exportTo(const QString& filename);

    void populateTree(QTreeWidgetItem *root, const Component& component);
    void drawComponent (const Component& component);
    void drawBoardArrays(const Scheme& scheme);

private slots:
    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionFit_to_content_triggered();

    void on_actionExport_triggered();

    void on_actionOpen_triggered();

    void on_actionSettings_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    GraphicsView *m_view;
    Scheme *m_scheme;

};
#endif // MAINWINDOW_H
