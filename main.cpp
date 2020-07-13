#include "mainwindow.h"
#include "parser.h"
#include "scheme.h"
#include "settings.h"
#include "xmlboardreader.h"

#include <QCommandLineParser>
#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include "version.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(VER_PRODUCTNAME_STR);
    a.setApplicationVersion(VER_PRODUCTVERSION_STR);

    Settings::load();

    MainWindow w;
    w.hide();

    QApplication::setApplicationName(VER_PRODUCTNAME_STR);
    QCoreApplication::setApplicationVersion(VER_PRODUCTVERSION_STR);

    // DECLARING parser and setting default options and positional arguments
    QCommandLineParser parser;
    parser.setApplicationDescription(QObject::tr("Viewer and convertor gerber xml files to image."));
    parser.addPositionalArgument("source.xml", QObject::tr("Input gerber file in xml format."));
    parser.addPositionalArgument("destination.ext",
                                 QObject::tr("Output image filename. Extension can be {bmp|png|jpg}."));
    parser.addHelpOption();
    parser.addVersionOption();

        // DECLARING options
        QCommandLineOption componentColorOption(
                    QStringList() << "c" << "component-color",
                    QCoreApplication::translate("main", "Specify components color (default is #ffa0abff)."),
                    QCoreApplication::translate("main", "#AARRGGBB"),
                    "#ffa0abff");
        parser.addOption(componentColorOption);
        QCommandLineOption boardColorOption(
                    QStringList() << "p" << "board-color",
                    QCoreApplication::translate("main", "Specify board color (default is #ff400076)."),
                    QCoreApplication::translate("main", "#AARRGGBB"),
                    "#ff400076");
        parser.addOption(boardColorOption);
        QCommandLineOption backgroundColorOption(
                    QStringList() << "w" << "background-color",
                QCoreApplication::translate("main", "Specify background color (default is #ffffffff)."),
                QCoreApplication::translate("main", "#AARRGGBB"),
                "#ffffffff");
    parser.addOption(backgroundColorOption);


    QCommandLineOption topOption(QStringList() << "t" << "display-top",
                                 QObject::tr("Display top layer."));
    parser.addOption(topOption);
    QCommandLineOption bottomOption(QStringList() << "b" << "display-bottom",
                                    QObject::tr("Display bottom layer."));
    Settings::setDisplayBottomSide(true);
    parser.addOption(bottomOption);


    // PARSING options
    parser.process(a);


    // CHECKING and USING options
    const QStringList args = parser.positionalArguments();
    for (auto& a: args)
        qDebug() << "Arg:" << a;

    bool topConf=parser.isSet(topOption);
    bool bottomConf = parser.isSet(bottomOption);
    qDebug() << "Display top:" << topConf;
    qDebug() << "Display bottom:" << bottomConf;

    QString componentColorConf = parser.value(componentColorOption);
    Settings::setComponentColor(componentColorConf);
    QString boardColorConf = parser.value(boardColorOption);
    Settings::setBoardColor(boardColorConf);
    QString backgroundColorConf = parser.value(backgroundColorOption);
    Settings::setBackgroundColor(backgroundColorConf);


    if ((topConf && bottomConf) == false) {
        Settings::setDisplayTopSide(true);
        Settings::setDisplayBottomSide(true);
    } else {
        Settings::setDisplayTopSide(topConf);
        Settings::setDisplayBottomSide(bottomConf);
    }


    if (args.size() == 1 ) {
        QString fileName = args.at(0);
        w.openScheme(fileName);
    } else if (args.size() == 2) {
        QString fromFileName = args.at(0);
        QString toFileName = args.at(1);
        if (w.openScheme(fromFileName)) {
            if (w.exportTo(toFileName)) {
                QApplication::quit();
                return 1;
            }
        }
    }
    w.show();
    return a.exec();
}
