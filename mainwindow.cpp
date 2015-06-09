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
    ui->displayArea->setGeometry(128,48,690,570);
    //
    QPalette pal = ui->displayArea->palette();
    pal.setColor(ui->displayArea->backgroundRole(), QColor(255,255,255));
    ui->displayArea->setPalette(pal);
    ui->displayArea->setAutoFillBackground(true);
    ui->displayArea->installEventFilter(this);

    homeDisplay = new homedisplay(ui->displayArea);
    docsDisplay = new docsdisplay(ui->displayArea);
    infoDisplay = new infodisplay(ui->displayArea);
    configDisplay = new configdisplay(ui->displayArea);
    windowDisplay = new windowdisplay(ui->displayArea);
    consoleDisplay = new consoledisplay(ui->displayArea);

    resetDisplay();
    homeDisplay->show();

    connect(ui->titleBar,SIGNAL(stateChange(int)),this,SLOT(setState(int)));
    connect(ui->sideMenu,SIGNAL(setDisplay(int)),this,SLOT(setDisplay(int)));

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
