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
    titlebar.cpp \
    Displays\homedisplay.cpp \
    Displays\configdisplay.cpp \
    Displays\consoledisplay.cpp \
    Displays\docsdisplay.cpp \
    Displays\windowdisplay.cpp \
    Displays\infodisplay.cpp

HEADERS  += mainwindow.h \
    sidemenu.h \
    titlebar.h \
    Displays\homedisplay.h \
    Displays\configdisplay.h \
    Displays\consoledisplay.h \
    Displays\docsdisplay.h \
    Displays\windowdisplay.h \
    Displays\infodisplay.h

FORMS    += UI\mainwindow.ui \
    UI\sidemenu.ui \
    UI\titlebar.ui \
    UI\homedisplay.ui \
    UI\configdisplay.ui \
    UI\consoledisplay.ui \
    UI\docsdisplay.ui \
    UI\windowdisplay.ui \
    UI\infodisplay.ui

RESOURCES += \
    Resources.qrc
