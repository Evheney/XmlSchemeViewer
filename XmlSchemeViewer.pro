#-------------------------------------------------
#
# Project created by QtCreator 2019-06-20T10:31:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MySchemeViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        aboutwnd.cpp \
        board.cpp \
        boardarray.cpp \
        boardgroup.cpp \
        component.cpp \
        componentdata.cpp \
        epmxrayinfo.cpp \
        footprints.cpp \
        graphicsview.cpp \
        main.cpp \
        mainwindow.cpp \
        parser.cpp \
        pd.cpp \
        rect.cpp \
        scene.cpp \
        scheme.cpp \
        settings.cpp \
        shape.cpp \
        shapecircle.cpp \
        shapepoly.cpp \
        shaperect.cpp \
        xmlboardreader.cpp

HEADERS += \
        aboutwnd.h \
        board.h \
        boardarray.h \
        boardgroup.h \
        component.h \
        componentdata.h \
        epmxrayinfo.h \
        footprints.h \
        graphicsview.h \
        mainwindow.h \
        parser.h \
        pd.h \
        rect.h \
        resources.rc \
        scene.h \
        scheme.h \
        settings.h \
        shape.h \
        shapecircle.h \
        shapepoly.h \
        shaperect.h \
        version.h \
        xmlboardreader.h

FORMS += \
        aboutwnd.ui \
        mainwindow.ui \
        settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

# assign application icon
win32:RC_FILE = resources.rc
#win32:RC_ICONS += Iconsmind-Outline-Chip.ico

