#include "inputfield.h"
#include "ui_inputfield.h"
#include <QDebug>

inputField::inputField(QWidget *parent, QRect r, QString s, QString d) :
    QWidget(parent),
    ui(new Ui::inputField)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this);

    location = r;
    setLocation(r);

    hint = s;
    ui->lineEdit->setPlaceholderText(hint);

    QString color;
    color.append("QWidget{ background: #9E9E9E; }");
    ui->selectionBar->setStyleSheet(color);

    if(d != ""){
        ui->lineEdit->setText(d);
    }
}

void inputField::setLocation(QRect r){
    this->setGeometry(0,0,r.width(),r.height());
    ui->lineEdit->setGeometry(0,0,r.width(),r.height()-2);
    ui->selectionBar->setGeometry(2,r.height()-1,r.width()-2,1);
}

void inputField::setTheme(QColor s){
    secondary = s;
}

bool inputField::eventFilter(QObject *obj, QEvent *event){
    if(QApplication::focusWidget() == ui->lineEdit && event->type() == QEvent::FocusIn){
        ui->selectionBar->setStyleSheet("QWidget{ background: " + secondary.name() + "; }");
        ui->selectionBar->setGeometry(2,location.height()-2,location.width(),2);
    }else if(event->type() == QEvent::FocusOut){
        ui->selectionBar->setStyleSheet("QWidget{ background: #9E9E9E; }");
        ui->selectionBar->setGeometry(2,location.height()-1,location.width()-2,1);
        ui->lineEdit->setCursorPosition(2);
    }

    return QObject::eventFilter(obj, event);
}

inputField::~inputField()
{
    delete ui;
}
