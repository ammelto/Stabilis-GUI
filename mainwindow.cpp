#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sidemenu.h"
#include "./Displays/homedisplay.h"
#include "./Displays/docsdisplay.h"
#include "./Displays/configdisplay.h"
#include "./Displays/consoledisplay.h"
#include "./Displays/infodisplay.h"
#include "./Displays/windowdisplay.h"
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

    QGraphicsDropShadowEffect* elevatedShadow = new QGraphicsDropShadowEffect();
    elevatedShadow->setBlurRadius(10);
    elevatedShadow->setColor(QColor(0,0,0,200));
    elevatedShadow->setOffset(0);
    ui->displayArea->setGraphicsEffect(shadow);
    //
    QPalette pal = ui->displayArea->palette();
    pal.setColor(ui->displayArea->backgroundRole(), QColor(250,250,250));
    ui->displayArea->setPalette(pal);
    ui->displayArea->setAutoFillBackground(true);
    ui->displayArea->installEventFilter(this);

    QGraphicsDropShadowEffect* titleShadow = new QGraphicsDropShadowEffect();
    titleShadow->setBlurRadius(16);
    titleShadow->setColor(QColor(0,0,0,200));
    titleShadow->setOffset(0);
    titleShadow->setXOffset(2);
    ui->titleBar->setGraphicsEffect(titleShadow);

    ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->scrollAreaWidgetContents->resize(ui->scrollArea->size().width() ,ui->scrollArea->size().height());
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->adjustSize();

    homeDisplay = new homedisplay(ui->displayArea);
    docsDisplay = new docsdisplay(ui->displayArea);
    infoDisplay = new infodisplay(ui->displayArea);
    configDisplay = new configdisplay(ui->displayArea);
    windowDisplay = new windowdisplay(ui->displayArea);
    consoleDisplay = new consoledisplay(ui->displayArea);
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
    resetDisplay();
    switch(display){
    case home:
        homeDisplay->show();
        break;
    case docs:
        docsDisplay->show();
        break;
    case info:
        infoDisplay->show();
        break;
    case config:
        configDisplay->show();
        break;
    case window:
        windowDisplay->show();
        break;
    case console:
        consoleDisplay->show();
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
