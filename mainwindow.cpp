#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sidemenu.h"
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

    QPalette pal = ui->titleBar->palette();
    pal.setColor(ui->titleBar->backgroundRole(), QColor(70,98,158));
    ui->titleBar->setPalette(pal);
    ui->titleBar->setAutoFillBackground(true);
    //
    pal = ui->displayArea->palette();
    pal.setColor(ui->displayArea->backgroundRole(), QColor(255,255,255));
    ui->displayArea->setPalette(pal);
    ui->displayArea->setAutoFillBackground(true);


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

    addFonts();
    createTitleBar();


}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(event->pos().y() < 48 && event->buttons() == Qt::LeftButton){
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void MainWindow::createTitleBar(){
    ui->title->setStyleSheet("QLabel { color : white; }");
    QFont font("Roboto",14);

    QPalette pal = ui->closeButton->palette();
    pal.setColor(ui->closeButton->backgroundRole(), QColor(192, 57, 43));
    ui->closeButton->setPalette(pal);
    ui->closeButton->setAutoFillBackground(true);
    ui->closeLabel->setStyleSheet("QLabel { color : white; }");
    //
    ui->maximizeLabel->setStyleSheet("QLabel { color : white; }");
    //
    ui->minimizeLabel->setStyleSheet("QLabel { color : white; }");
}

void MainWindow::addFonts(){

    QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-Medium.ttf");
    ui->title->setFont(QFont("Roboto",18));

    QFont boldRoboto = QFont("Roboto",14);
    boldRoboto.setBold(true);
    ui->closeLabel->setFont(boldRoboto);
    boldRoboto.setPixelSize(18);
    ui->maximizeLabel->setFont(boldRoboto);
    ui->minimizeLabel->setFont(boldRoboto);

}

MainWindow::~MainWindow()
{
    delete ui;
}
