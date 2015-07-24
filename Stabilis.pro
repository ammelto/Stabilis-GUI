#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T21:26:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stabilis
TEMPLATE = app

#LIBS += -L"$$_PRO_FILE_PWD_/Libs/libssh-0.7.1/lib/" -lssh

CONFIG += console

SOURCES += main.cpp\
        mainwindow.cpp \
        sidemenu.cpp \
        titlebar.cpp \
        Displays\config_materials\src\configcontrollersettings.cpp\
        Displays\config_materials\src\configgeneralsettings.cpp\
        Displays\config_materials\src\confignetworksettings.cpp\
        Displays\config_materials\src\configvehiclesettings.cpp\
        Displays\config_materials\src\configcreator.cpp\
        Displays\src\homedisplay.cpp \
        Displays\src\configdisplay.cpp \
        Displays\src\consoledisplay.cpp \
        Displays\src\docsdisplay.cpp \
        Displays\src\windowdisplay.cpp \
        Displays\src\infodisplay.cpp \
        slider.cpp \
        genericbutton.cpp \
        inputfield.cpp \
        Displays\config_materials\src\airplanetemplate.cpp \
        Displays\config_materials\src\loadvehicledialog.cpp \
        Displays\config_materials\src\newvehicledialog.cpp \
        Displays/console_materials/src/terminalwindow.cpp \
        Displays/docs_materials/src/docsnavmenu.cpp \
        Displays/docs_materials/src/docscontentwindow.cpp


HEADERS  += mainwindow.h \
        sidemenu.h \
        titlebar.h \
        Displays\config_materials\headers\configcontrollersettings.h\
        Displays\config_materials\headers\configgeneralsettings.h\
        Displays\config_materials\headers\confignetworksettings.h\
        Displays\config_materials\headers\configvehiclesettings.h\
        Displays\config_materials\headers\configcreator.h\
        Displays\headers\homedisplay.h \
        Displays\headers\configdisplay.h \
        Displays\headers\consoledisplay.h \
        Displays\headers\docsdisplay.h \
        Displays\headers\windowdisplay.h \
        Displays\headers\infodisplay.h \
        slider.h \
        genericbutton.h \
        inputfield.h \
        Displays/config_materials/headers/airplanetemplate.h \
        Displays/config_materials/headers/loadvehicledialog.h \
        Displays/config_materials/headers/newvehicledialog.h \
        Displays/console_materials/headers/terminalwindow.h \
        Displays/docs_materials/headers/docsnavmenu.h \
        Displays/docs_materials/headers/docscontentwindow.h

FORMS    += UI\mainwindow.ui \
        UI\sidemenu.ui \
        UI\titlebar.ui \
        UI\homedisplay.ui \
        UI\configdisplay.ui \
        UI\consoledisplay.ui \
        UI\docsdisplay.ui \
        UI\windowdisplay.ui \
        UI\infodisplay.ui \
        slider.ui \
        Displays\config_materials\UI\configcontrollersettings.ui\
        Displays\config_materials\UI\configgeneralsettings.ui\
        Displays\config_materials\UI\confignetworksettings.ui\
        Displays\config_materials\UI\configvehiclesettings.ui\
        genericbutton.ui \
        inputfield.ui \
        Displays/config_materials/UI/airplanetemplate.ui \
        Displays/config_materials/UI/loadvehicledialog.ui \
        Displays/config_materials/UI/newvehicledialog.ui \
        Displays/console_materials/UI/terminalwindow.ui \
        Displays/docs_materials/UI/docsnavmenu.ui \
        Displays/docs_materials/UI/docscontentwindow.ui

RESOURCES += \
    Resources.qrc

