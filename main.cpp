#include "mainwindow.h"
#include "parser.h"
#include "scheme.h"
#include "settings.h"
#include "xmlboardreader.h"

#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QString fileName("testnk.xml");
//    QFile file(fileName);
//    if(!file.open(QFile::ReadOnly | QFile::Text)){
//        qDebug() << "Cannot read file " << fileName << ". Error:" << file.errorString();

//        QString messageText = QString("Cannot read the file %1.").arg(fileName);
//        QString errorText = QString("<b>Error:</b> %2").arg(file.errorString());

//        QMessageBox msgBox;
//        msgBox.setWindowTitle(a.applicationName());
//        msgBox.setText(messageText);
//        msgBox.setInformativeText(errorText);
//        msgBox.setStandardButtons(QMessageBox::Ok);
//        msgBox.exec();
//        return -1;
//    }

//    Scheme scheme;
//    XmlBoardReader parser(&scheme);
//    parser.read(&file);
//    parser.print();

    Settings::load();

    MainWindow w;
    w.show();
//    w.addScheme(scheme);

    return a.exec();
}
