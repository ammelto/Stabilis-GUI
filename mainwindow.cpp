#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sidemenu.h"
#include "titlebar.h"
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QColor>
#include <QFontDatabase>
#include <QPixmap>
#include <QtEvents>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsView>
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
    ui->displayArea->setGraphicsEffect(elevatedShadow);
    ui->displayArea->setGeometry(118,48,700,570);
    //
    QPalette pal = ui->displayArea->palette();
    pal.setColor(ui->displayArea->backgroundRole(), QColor(255,255,255));
    ui->displayArea->setPalette(pal);
    ui->displayArea->setAutoFillBackground(true);


    connect(ui->titleBar,SIGNAL(stateChange(int)),this,SLOT(setState(int)));
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }if(event->button() == Qt::RightButton){

    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(event->pos().y() < 48 && event->buttons() == Qt::LeftButton){
        move(event->globalPos() - dragPosition);
        event->accept();
    }
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

}

MainWindow::~MainWindow()
{
    delete ui;
}
