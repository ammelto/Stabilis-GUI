#include "titlebar.h"
#include "ui_titlebar.h"
#include "mainwindow.h"
#include <QtGui>
#include <QtCore>
#include <QColor>
#include <QFontDatabase>
#include <QtEvents>
#include <QDebug>
#include <QWidget>
#include <QPalette>

titlebar::titlebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::titlebar)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(this->backgroundRole(), QColor(70,98,158));
    this->setPalette(pal);
    this->setAutoFillBackground(true);
    //
    ui->closeButton->installEventFilter(this);
    ui->maximizeButton->installEventFilter(this);
    ui->minimizeButton->installEventFilter(this);

    QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-Medium.ttf");
    ui->title->setFont(QFont("Roboto",18));

    QFont boldRoboto = QFont("Roboto",14);
    boldRoboto.setBold(true);
    ui->closeLabel->setFont(boldRoboto);
    boldRoboto.setPixelSize(18);
    ui->maximizeLabel->setFont(boldRoboto);
    ui->minimizeLabel->setFont(boldRoboto);

    this->setStyleSheet("QLabel { color : white; }");

    pal = ui->closeButton->palette();
    pal.setColor(ui->closeButton->backgroundRole(), QColor(192, 57, 43));
    ui->closeButton->setPalette(pal);
    ui->closeButton->setAutoFillBackground(true);
    ui->closeLabel->setStyleSheet("QLabel { color : white; }");
    //
    pal = ui->maximizeButton->palette();
    pal.setColor(ui->maximizeButton->backgroundRole(), QColor(70,98,158));
    ui->maximizeButton->setPalette(pal);
    ui->maximizeButton->setAutoFillBackground(true);
    ui->maximizeLabel->setStyleSheet("QLabel { color : white; }");
    //
    pal = ui->minimizeButton->palette();
    pal.setColor(ui->minimizeButton->backgroundRole(), QColor(70,98,158));
    ui->minimizeButton->setPalette(pal);
    ui->minimizeButton->setAutoFillBackground(true);
    ui->minimizeLabel->setStyleSheet("QLabel { color : white; }");

}

bool titlebar::eventFilter(QObject *obj, QEvent *event){

    QPalette pal;

    if(obj == ui->closeButton){
        pal = ui->closeButton->palette();

        if(event->type() == QEvent::Enter){
            pal.setColor(ui->closeButton->backgroundRole(), QColor(231, 76, 60));
        }else if(event->type() == QEvent::Leave){
            pal.setColor(ui->closeButton->backgroundRole(), QColor(192, 57, 43));
        }else if(event->type() == QEvent::MouseButtonPress){
            stateChange(close);
        }
        ui->closeButton->setPalette(pal);
        ui->closeButton->setAutoFillBackground(true);
    }

    if(obj == ui->minimizeButton){
        pal = ui->minimizeButton->palette();

        if(event->type() == QEvent::Enter){
            pal.setColor(ui->minimizeButton->backgroundRole(), QColor(108,147,233));
        }else if(event->type() == QEvent::Leave){
            pal.setColor(ui->minimizeButton->backgroundRole(), QColor(70,98,158));
        }else if(event->type() == QEvent::MouseButtonPress){
        stateChange(minimize);
        }
        ui->minimizeButton->setPalette(pal);
        ui->minimizeButton->setAutoFillBackground(true);
    }

    if(obj == ui->maximizeButton){
        pal = ui->maximizeButton->palette();

        if(event->type() == QEvent::Enter){
            pal.setColor(ui->maximizeButton->backgroundRole(), QColor(108,147,233));
        }else if(event->type() == QEvent::Leave){
            pal.setColor(ui->maximizeButton->backgroundRole(), QColor(70,98,158));
        }else if(event->type() == QEvent::MouseButtonPress){
            stateChange(maximize);
        }
        ui->maximizeButton->setPalette(pal);
        ui->maximizeButton->setAutoFillBackground(true);
    }


    return QObject::eventFilter(obj, event);
}

titlebar::~titlebar()
{
    delete ui;
}
