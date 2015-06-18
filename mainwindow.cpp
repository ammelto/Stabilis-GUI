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
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Stabilis");
    setCentralWidget(ui->mainWidget);

    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(25);
    shadow->setColor(QColor(0,0,0,200));
    shadow->setOffset(0);
    this->setGraphicsEffect(shadow);
    ui->scrollArea->setGraphicsEffect(shadow);

    QGraphicsDropShadowEffect* titleShadow = new QGraphicsDropShadowEffect();
    titleShadow->setBlurRadius(16);
    titleShadow->setColor(QColor(0,0,0,200));
    titleShadow->setOffset(0);
    titleShadow->setXOffset(2);
    ui->titleBar->setGraphicsEffect(titleShadow);

    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);


    QPalette pal = ui->scrollArea->palette();
    pal.setColor(ui->scrollArea->backgroundRole(), QColor(250,250,250));
    ui->scrollArea->setPalette(pal);
    ui->scrollArea->setAutoFillBackground(true);
    ui->scrollArea->installEventFilter(this);

    homeDisplay = new homedisplay(ui->scrollAreaWidgetContents);
    docsDisplay = new docsdisplay(ui->scrollAreaWidgetContents);
    infoDisplay = new infodisplay(ui->scrollAreaWidgetContents);
    configDisplay = new configdisplay(ui->scrollAreaWidgetContents);
    windowDisplay = new windowdisplay(ui->scrollAreaWidgetContents);
    consoleDisplay = new consoledisplay(ui->scrollAreaWidgetContents);
    sideMenu = new sidemenu(ui->menu);
    titleBar = new titlebar(ui->titleBar);

    resetDisplay();
    homeDisplay->show();

    this->setTheme(QColor(70,98,158), QColor(78,109,176), QColor(255,255,255));
    connect(titleBar,SIGNAL(stateChange(int)),this,SLOT(setState(int)));
    connect(sideMenu,SIGNAL(setDisplay(int)),this,SLOT(setDisplay(int)));
    connect(windowDisplay, SIGNAL(setTheme(QColor,QColor,QColor)),this,SLOT(setTheme(QColor,QColor,QColor)));

}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if((event->pos().y() < 48) && event->buttons() == Qt::LeftButton){
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

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

void MainWindow::setTheme(QColor p, QColor s, QColor f){
    sideMenu->setTheme(p,s,f);
    titleBar->setTheme(p,s,f);
    configDisplay->setTheme(p,s,f);
}

void MainWindow::setState(int state){
    switch(state){
    case close:
        QApplication::exit(0);
        break;
    case maximize:
        break;
    case minimize:
        this->setWindowState(Qt::WindowMinimized);
        this->showMinimized();
        this->lower();
        break;
    }

}

void MainWindow::setDisplay(int display){
    qDebug() << currentDisplay;
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
        //ui->scrollAreaWidgetContents->resize(configDisplay->sizeHint());
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
