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

    static QColor getComponentColor();
    static QColor getBoardColor();
    static QColor getBackgroundColor();
    static bool getSmoothZoom();

    static void save();
    static void load();

private:
    static QColor backgroundColor;
    static QColor boardColor;
    static QColor componentColor;
    static bool smoothZoom;

    static const QString backgroundColorStr;
    static const QString boardColorStr;
    static const QString componentColorStr;
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

private slots:
    void on_backgroundColorButton_clicked();

    void on_boardColorButton_clicked();

    void on_componentColorButton_clicked();

    void on_smoothZoomCheck_stateChanged(int arg1);

    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::Settings *ui;
    QColor backgroundColor;
    QColor boardColor;
    QColor componentColor;
    bool smoothZoom;
};

#endif // SETTINGS_H
