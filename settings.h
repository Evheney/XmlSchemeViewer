#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings
{
public:
    static void setBackgroundColor(const QColor &value);
    static void setBoardColor(const QColor &value);
    static void setComponentColor(const QColor &value);
    static void setSmoothZoom(bool value);
    static void setDisplayTopSide(bool value);
    static void setDisplayBottomSide(bool value);


    static QColor getComponentColor();
    static QColor getBoardColor();
    static QColor getBackgroundColor();
    static bool getSmoothZoom();
    static void sideShow(bool value);
    static bool getDisplayTopSide();
    static bool getDisplayBottomSide();


    static void save();
    static void load();

private:
    static QColor backgroundColor;
    static QColor boardColor;
    static QColor componentColor;
    static bool smoothZoom;
    static bool displayTopSide;
    static bool displayBottomSide;

    static const QString backgroundColorStr;
    static const QString boardColorStr;
    static const QString componentColorStr;
    static const QString displayTopSideStr;
    static const QString displayBottomSideStr;
    static const QString smoothZoomStr;
};


class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog() override ;

    QColor getBackgroundColor() const;

    QColor getBoardColor() const;

    QColor getComponentColor() const;

    bool getSmoothZoom() const;

    bool getDisplayTopSide() const;

    void setDisplayTopSide(bool value);

    bool getDisplayBottomSide() const;

    void setDisplayBottomSide(bool value);

private slots:
    void on_backgroundColorButton_clicked();

    void on_boardColorButton_clicked();

    void on_componentColorButton_clicked();

    void on_smoothZoomCheck_stateChanged(int arg1);

    void on_bottomSide_stateChanged(int arg1);

    void on_topSide_stateChanged(int arg1);

    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Settings *ui;
    QColor backgroundColor;
    QColor boardColor;
    QColor componentColor;
    bool smoothZoom;
    bool displayTopSide;
    bool displayBottomSide;
};

#endif // SETTINGS_H
