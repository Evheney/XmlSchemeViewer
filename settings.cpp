#include "settings.h"
#include "ui_settings.h"
#include <QColorDialog>
#include <QSettings>
#include <QDebug>

QColor Settings::backgroundColor = "#FFFFFF";//QColor(Qt::white);
QColor Settings::boardColor = "#400076";
QColor Settings::componentColor = "#A0ABFF";//QColor(0, 0, 255, 32);

bool Settings::smoothZoom  = true;
bool Settings::displayTopSide=true;
bool Settings::displayBottomSide=true;

const QString Settings::backgroundColorStr = "BackgroundColor";
const QString Settings::boardColorStr = "BoardColor";
const QString Settings::componentColorStr = "ComponentColor";
const QString Settings::displayTopSideStr="DisplayTopSide";
const QString Settings::displayBottomSideStr="DisplayBottomSide";
const QString Settings::smoothZoomStr="SmoothZoom";



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
void SettingsDialog::on_bottomSide_stateChanged(int arg1)
{
    displayBottomSide=arg1 != Qt::Unchecked;
}

void SettingsDialog::on_topSide_stateChanged(int arg1)
{
    displayTopSide=arg1 == Qt::Checked;
}

void Settings::save()
{
    QColor boardColors = getBoardColor();
    QColor componentColors = getComponentColor();
    QColor backgroundColors = getBackgroundColor();

    QSettings settings(QApplication::applicationName()+".ini", //"XmlSchemeViewer.ini",
                       QSettings::IniFormat);

    settings.beginGroup("Colors");
    settings.setValue(boardColorStr, getBoardColor().name(QColor::HexArgb));
    settings.setValue(componentColorStr, getComponentColor().name(QColor::HexArgb));
    settings.setValue(backgroundColorStr, getBackgroundColor().name(QColor::HexArgb));
    settings.endGroup();
    settings.beginGroup("Display");
    settings.setValue(displayTopSideStr,getDisplayTopSide());
    settings.setValue(displayBottomSideStr,getDisplayBottomSide());
    settings.setValue(smoothZoomStr,getSmoothZoom());
    settings.endGroup();
    qDebug() << "Save " << boardColorStr << boardColors
             << componentColorStr << componentColors
             << backgroundColorStr << backgroundColors;
}


void Settings::load()
{
    QSettings settings(QApplication::applicationName()+".ini", //"XmlSchemeViewer.ini",
                       QSettings::IniFormat);
    //    QSettings settings("XmlSchemeViewer.ini",
    //                         QSettings::IniFormat);

    settings.beginGroup("Colors");
    if(settings.contains(boardColorStr)){
        QColor color = getBoardColor();
        color.setNamedColor(settings.value(boardColorStr,color.name(QColor::HexArgb)).toString());
        setBoardColor(color);
        qDebug() << "Set " << boardColorStr << color;
    }
    if(settings.contains(componentColorStr)){
        QColor color = getComponentColor();
        color.setNamedColor(settings.value(componentColorStr,color.name(QColor::HexArgb)).toString());
        setComponentColor(color);
        qDebug() << "Set " << componentColorStr << color;
    }
    if(settings.contains(backgroundColorStr)){
        QColor color = getBackgroundColor();
        color.setNamedColor(settings.value(backgroundColorStr,color.name(QColor::HexArgb)).toString());
        setBackgroundColor(color);
        qDebug() << "Set " << backgroundColorStr << color;
    }
    settings.endGroup();

    settings.beginGroup("Display");
    if(settings.contains(displayTopSideStr)){
        bool topSide = settings.value(displayTopSideStr,getDisplayTopSide()).toBool();
        setDisplayTopSide(topSide);
    }
    if(settings.contains(displayBottomSideStr)){
        bool bottomSide = settings.value(displayBottomSideStr,getDisplayBottomSide()).toBool();
        setDisplayBottomSide(bottomSide);
    }
    if(settings.contains(smoothZoomStr)){
        bool zoom = settings.value(smoothZoomStr,getSmoothZoom()).toBool();
        setSmoothZoom(zoom);
    }

    settings.endGroup();

}
bool Settings::getDisplayTopSide()
{
    return displayTopSide;
}

void Settings::setDisplayTopSide(bool value)
{
    displayTopSide = value;
}

bool Settings::getDisplayBottomSide()
{
    return displayBottomSide;
}

void Settings::setDisplayBottomSide(bool value)
{
    displayBottomSide = value;
}

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    ui->smoothZoomCheck->setCheckState(Settings::getSmoothZoom() == true
                                       ? Qt::Checked : Qt::Unchecked);
    ui->topSide->setCheckState(Settings::getDisplayTopSide()==true?
                                   Qt::Checked : Qt::Unchecked);
    ui->bottomSide->setCheckState(Settings::getDisplayBottomSide()==true?
                                   Qt::Checked : Qt::Unchecked);
    backgroundColor = Settings::getBackgroundColor();
    boardColor = Settings::getBoardColor();
    componentColor = Settings::getComponentColor();
    smoothZoom = Settings::getSmoothZoom();
    displayTopSide=Settings::getDisplayTopSide();
    displayBottomSide= Settings::getDisplayBottomSide();
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

void SettingsDialog::setDisplayBottomSide(bool value)
{
    displayBottomSide = value;
}

bool SettingsDialog::getDisplayBottomSide() const
{
    return displayBottomSide;
}

void SettingsDialog::setDisplayTopSide(bool value)
{
    displayTopSide = value;
}

bool SettingsDialog::getDisplayTopSide() const
{
    return displayTopSide;
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


void SettingsDialog::on_buttonBox_accepted()
{
    Settings::setBoardColor(getBoardColor());
    Settings::setComponentColor(getComponentColor());
    Settings::setBackgroundColor(getBackgroundColor());
    Settings::setSmoothZoom(getSmoothZoom());
    Settings::setDisplayTopSide(getDisplayTopSide());
    Settings::setDisplayBottomSide(getDisplayBottomSide());


    Settings::save();
}
