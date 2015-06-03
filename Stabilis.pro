#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T21:26:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stabilis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sidemenu.cpp \
    sidebutton.cpp

HEADERS  += mainwindow.h \
    sidemenu.h \
    sidebutton.h

FORMS    += mainwindow.ui \
    sidemenu.ui \
    sidebutton.ui

RESOURCES += \
    Resources.qrc
