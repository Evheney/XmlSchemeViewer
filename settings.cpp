#include "settings.h"
#include "ui_settings.h"
#include <QColorDialog>
#include <QSettings>
#include <QDebug>

QColor Settings::backgroundColor = "#FFFFFF";//QColor(Qt::white);
QColor Settings::boardColor = "#400076";
QColor Settings::componentColor = "#A0ABFF";//QColor(0, 0, 255, 32);
bool Settings::smoothZoom  = true;

const QString Settings::backgroundColorStr = "backgroundColor";
const QString Settings::boardColorStr = "boardColor";
const QString Settings::componentColorStr = "componentColor";


void Settings::setComponentColor(const QColor &value)
{
    componentColor = value;
}

void Settings::setBoardColor(const QColor &value)
{
    boardColor = value;
}

void Settings::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}

void Settings::setSmoothZoom(bool value)
{
    smoothZoom = value;
}

QColor Settings::getBackgroundColor()
{
    return backgroundColor;
}

QColor Settings::getBoardColor()
{
    return boardColor;
}

QColor Settings::getComponentColor()
{
    return componentColor;
}

bool Settings::getSmoothZoom()
{
    return smoothZoom;
}

void Settings::save()
{
    QColor boardColors = getBoardColor();
    QColor componentColors = getComponentColor();
    QColor backgroundColors = getBackgroundColor();

//    QSettings settings("XMLReader", "Colors");
    QSettings settings("XmlSchemeViewer.ini",
                         QSettings::IniFormat);

    settings.beginGroup("Colors");
    settings.setValue(boardColorStr, getBoardColor().rgba());
    settings.setValue(componentColorStr, getComponentColor().rgba());
    settings.setValue(backgroundColorStr, getBackgroundColor().rgba());
    settings.endGroup();
    qDebug() << "Save " << boardColorStr << boardColors
             << componentColorStr << componentColors
             << backgroundColorStr << backgroundColors;
}

void Settings::load()
{
    //QSettings settings("XMLReader", "Colors");
    QSettings settings("XmlSchemeViewer.ini",
                         QSettings::IniFormat);


    settings.beginGroup("Colors");
    if(settings.contains(boardColorStr)){
        QColor color;
        color.setRgba(settings.value(boardColorStr).toUInt());
        setBoardColor(color);
        qDebug() << "Set " << boardColorStr << color;
    }
    if(settings.contains(componentColorStr)){
        QColor color;
        color.setRgba(settings.value(componentColorStr).toUInt());
        setComponentColor(color);
        qDebug() << "Set " << componentColorStr << color;
    }
    if(settings.contains(backgroundColorStr)){
        QColor color;
        color.setRgba(settings.value(backgroundColorStr).toUInt());
        setBackgroundColor(color);
        qDebug() << "Set " << backgroundColorStr << color;
    }
    settings.endGroup();

}

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    ui->smoothZoomCheck->setCheckState(Settings::getSmoothZoom() == true
                                      ? Qt::Checked : Qt::Unchecked);
    backgroundColor = Settings::getBackgroundColor();
    boardColor = Settings::getBoardColor();
    componentColor = Settings::getComponentColor();
    smoothZoom = Settings::getSmoothZoom();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::on_backgroundColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(backgroundColor);

    if (color.isValid()) {
        backgroundColor = color;
    }
}

void SettingsDialog::on_boardColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(boardColor);

    if (color.isValid()) {
        boardColor = color;
    }
}

void SettingsDialog::on_componentColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(componentColor);

    if (color.isValid()) {
        componentColor = color;
    }
}

void SettingsDialog::on_smoothZoomCheck_stateChanged(int arg1)
{
    smoothZoom=arg1 != Qt::Unchecked;
}

void SettingsDialog::on_saveButton_clicked()
{
    Settings::save();
}

void SettingsDialog::on_loadButton_clicked()
{
    Settings::load();
}

bool SettingsDialog::getSmoothZoom() const
{
    return smoothZoom;
}

QColor SettingsDialog::getComponentColor() const
{
    return componentColor;
}

QColor SettingsDialog::getBoardColor() const
{
    return boardColor;
}

QColor SettingsDialog::getBackgroundColor() const
{
    return backgroundColor;
}

