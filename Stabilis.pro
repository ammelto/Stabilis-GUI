#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T21:26:55
#
#-------------------------------------------------

QT       += core

QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stabilis
TEMPLATE = app

INCLUDEPATH +=C:\cygwin64\home\daslabasus1\libssh2-1.6.0\include
win32:CONFIG(release, debug|release):INCLUDEPATH +=C:\cygwin64\home\daslabasus1\libssh2-1.6.0\include
else:unix:INCLUDEPATH += /home/nolander/Desktop/libssh2-1.6.0/include

win32{
LIBS += -static -LC:/Users/daslabasus1/Nolan/libssh2_1.2.6/bin -lssh2
LIBS += -static -LC:/Qt/Tools/mingw492_32/i686-w64-mingw32/lib/ -lws2_32#must be static\
LIBS += -static -LC:/Qt/Tools/mingw492_32/i686-w64-mingw32/lib/ -lz #must be static
LIBS += -static -LC:/Qt/Tools/mingw492_32/i686-w64-mingw32/lib/ -lbcrypt #must be static
LIBS += -static -LC:/Qt/Tools/mingw492_32/i686-w64-mingw32/lib/ -lcrypt32 #must be static
}

unix{
#if we dont use the -L switch below it doesnt work because we then must declare -static,
#but that causes the maker to look for static Qt libs which do not exist
LIBS+= -L/home/nolander/Desktop/libssh2-1.6.0/bin -lssh2
}

CONFIG += console
#make sure paths have "/" and not "\" for linux compat
#SOURCES += /home/nolander/Desktop/libssh2-1.6.0/src/*

SOURCES += main.cpp\
mainwindow.cpp \
        sidemenu.cpp \
        titlebar.cpp \
        Displays/config_materials/src/configcontrollersettings.cpp\
        Displays/config_materials/src/configgeneralsettings.cpp\
        Displays/config_materials/src/confignetworksettings.cpp\
        Displays/config_materials/src/configvehiclesettings.cpp\
        Displays/config_materials/src/configcreator.cpp\
        Displays/src/homedisplay.cpp \
        Displays/src/configdisplay.cpp \
        Displays/src/consoledisplay.cpp \
        Displays/src/docsdisplay.cpp \
        Displays/src/windowdisplay.cpp \
        Displays/src/infodisplay.cpp \
        slider.cpp \
        genericbutton.cpp \
        inputfield.cpp \
        Displays/config_materials/src/airplanetemplate.cpp \
        Displays/config_materials/src/loadvehicledialog.cpp \
        Displays/config_materials/src/newvehicledialog.cpp \
console.cpp\

HEADERS  += mainwindow.h \
 sidemenu.h \
        titlebar.h \
        Displays/config_materials/headers/configcontrollersettings.h\
        Displays/config_materials/headers/configgeneralsettings.h\
        Displays/config_materials/headers/confignetworksettings.h\
        Displays/config_materials/headers/configvehiclesettings.h\
        Displays/config_materials/headers/configcreator.h\
        Displays/headers/homedisplay.h \
        Displays/headers/configdisplay.h \
        Displays/headers/consoledisplay.h \
        Displays/headers/docsdisplay.h \
        Displays/headers/windowdisplay.h \
        Displays/headers/infodisplay.h \
        slider.h \
        genericbutton.h \
        inputfield.h \
        Displays/config_materials/headers/airplanetemplate.h \
        Displays/config_materials/headers/loadvehicledialog.h \
        Displays/config_materials/headers/newvehicledialog.h \
console.h\

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




RESOURCES += \
    Resources.qrc

DISTFILES += \
    notes.txt

