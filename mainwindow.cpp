#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sidemenu.h"
#include "./Displays/headers/homedisplay.h"
#include "./Displays/headers/docsdisplay.h"
#include "./Displays/headers/configdisplay.h"
#include "./Displays/headers/consoledisplay.h"
#include "./Displays/headers/infodisplay.h"
#include "./Displays/headers/windowdisplay.h"
#include "titlebar.h"
#include <QtGui>
#include <QtCore>
#include <QColor>
#include <QFontDatabase>
#include <QLayout>
#include <QPixmap>
#include <QtEvents>
#include <QDebug>
#include <QDesktopWidget>
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
    ui(new Ui::MainWindow)
{
    //Initializes the window
    ui->setupUi(this);
    this->setWindowTitle("Stabilis");
    setCentralWidget(ui->mainWidget);

    //Hides the main frame and replaces it with a drop shadow
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(25);
    shadow->setColor(QColor(0,0,0,200));
    shadow->setOffset(0);
    this->setGraphicsEffect(shadow);
    ui->scrollArea->setGraphicsEffect(shadow);

    //Creates a drop shadow around the title bar, offsets it so it only appears below
    QGraphicsDropShadowEffect* titleShadow = new QGraphicsDropShadowEffect();
    titleShadow->setBlurRadius(16);
    titleShadow->setColor(QColor(0,0,0,200));
    titleShadow->setOffset(0);
    titleShadow->setXOffset(2);
    ui->titleBar->setGraphicsEffect(titleShadow);

    //Initializes the scroll area
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);

    //Sets the background color of the scroll area to a material gray
    QPalette pal = ui->scrollArea->palette();
    pal.setColor(ui->scrollArea->backgroundRole(), QColor(250,250,250));
    ui->scrollArea->setPalette(pal);
    ui->scrollArea->setAutoFillBackground(true);
    ui->scrollArea->installEventFilter(this);

    //Creates multiple display objects with the main scroll area widget as the parent.
    //Hides and shows the current active display area
    //Think of the display area as the model, the displays as views, and the MainWindow.cpp as the control
    homeDisplay = new homedisplay(ui->scrollAreaWidgetContents);
    docsDisplay = new docsdisplay(ui->scrollAreaWidgetContents);
    infoDisplay = new infodisplay(ui->scrollAreaWidgetContents);
    configDisplay = new configdisplay(ui->scrollAreaWidgetContents);
    windowDisplay = new windowdisplay(ui->scrollAreaWidgetContents);
    consoleDisplay = new consoledisplay(ui->scrollAreaWidgetContents);
    sideMenu = new sidemenu(ui->menu);
    titleBar = new titlebar(ui->titleBar);

    //Resets the display area to ensure they are all hidden and no overlaps occur
    resetDisplay();
    homeDisplay->show();

    //Connects primary model - view signals.
    connect(titleBar,SIGNAL(stateChange(int)),this,SLOT(setState(int)));
    connect(sideMenu,SIGNAL(setDisplay(int)),this,SLOT(setDisplay(int)));
    connect(windowDisplay, SIGNAL(setTheme(QColor,QColor,QColor)),this,SLOT(setTheme(QColor,QColor,QColor)));

    //Loads the theme colors from the ini file.
    QSettings settings(":/files/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    this->setTheme(QColor(settings.value("primary").toString()), QColor(settings.value("secondary").toString()), QColor(settings.value("font").toString()));
    settings.endGroup();

}

//Since the window manager does not recognize the custom title bar
//window movement had to be reimplemented by the following two frunctions
//####
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if((event->pos().y() < 48) && event->buttons() == Qt::LeftButton && !isMax){
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
//####

void MainWindow::resetDisplay(){
    homeDisplay->hide();
    docsDisplay->hide();
    infoDisplay->hide();
    configDisplay->hide();
    windowDisplay->hide();
    consoleDisplay->hide();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    return QObject::eventFilter(obj, event);
}

//Sets the theme
//This is faster than reading from the ini file every time we want to reference the color theme
void MainWindow::setTheme(QColor p, QColor s, QColor f){
    sideMenu->setTheme(p,s,f);
    titleBar->setTheme(p,s,f);
    configDisplay->setTheme(p,s,f);
}

//Sets primary window states. The view in this case is controlled by menu bar signals.
//This is a slot
void MainWindow::setState(int state){
    QDesktopWidget desktop;
    switch(state){
    case close:
        QApplication::exit(0);
        break;
    case maximize:
        if(isMax == false){
            savedGeometry = this->geometry();
            this->setGeometry(-18,-18,832,desktop.height());
            ui->scrollArea->setGeometry(18,68,800,desktop.height()-98);
            //Avaliable geometry function has some inconsistencies on some linux distros.
#ifdef Q_OS_WIN
            this->setGeometry(-18,-18,832,desktop.availableGeometry().height()+18);
#else
            this->setGeometry(-18,-18,832,desktop.height());
#endif
            isMax = true;
            break;
        }else{
            this->setGeometry(savedGeometry);
            ui->scrollArea->setGeometry(18,68,800,634);
            isMax = false;
        }
        break;
    case minimize:
        this->setWindowState(Qt::WindowMinimized);
        this->showMinimized();
        this->lower();
        break;
    }

}

//Since the menu and display are seperate objects, the main window has to control them
//It implements the view in both the menu bar and display, then it updates the model with repaint
void MainWindow::setDisplay(int display){
    if (display == currentDisplay) return;
    resetDisplay();
    ui->scrollAreaWidgetContents->setMinimumHeight(530);
    switch(display){
    case home:
        homeDisplay->show();
        sideMenu->repaintButtons();
        sideMenu->moveBar(home);
        this->repaint();
        break;
    case docs:
        docsDisplay->show();
        sideMenu->repaintButtons();
        sideMenu->moveBar(docs);
        this->repaint();
        break;
    case info:
        infoDisplay->show();
        sideMenu->repaintButtons();
        sideMenu->moveBar(info);
        this->repaint();
        break;
    case config:
        //Prevents scrollbar from showing when it is not needed
        ui->scrollAreaWidgetContents->setMinimumHeight(900);
        configDisplay->show();
        sideMenu->repaintButtons();
        sideMenu->moveBar(config);
        this->repaint();
        break;
    case window:
        windowDisplay->show();
        sideMenu->repaintButtons();
        sideMenu->moveBar(window);
        this->repaint();
        break;
    case console:
        consoleDisplay->show();
        sideMenu->repaintButtons();
        sideMenu->moveBar(console);
        this->repaint();
        break;
    }
    currentDisplay = display;
}

MainWindow::~MainWindow()
{
    delete ui;
}
