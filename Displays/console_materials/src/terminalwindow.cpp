#include "../headers/terminalwindow.h"
#include "ui_terminalwindow.h"
#include <QGraphicsEffect>
#include <QScrollBar>
#include <QtCore/QDebug>

TerminalWindow::TerminalWindow(QWidget *parent)
    : QPlainTextEdit(parent)
    , localEchoEnabled(true),
    ui(new Ui::TerminalWindow)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(6);
    shadow->setColor(QColor(0,0,0,200));
    shadow->setOffset(0);
    this->setGraphicsEffect(shadow);
    //
   // QPalette pal = this->palette();
    //pal.setColor(this->backgroundRole(), QColor(255,255,255));
    //this->setPalette(pal);
    this->setAutoFillBackground(true);

    document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);

    //QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    //ui->windowLabel->setFont(QFont("Roboto",11));

}

TerminalWindow::~TerminalWindow()
{
    delete ui;
}




void TerminalWindow::putData(const QByteArray &data)
{
    insertPlainText(QString(data));

    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void TerminalWindow::setLocalEchoEnabled(bool set)
{
    localEchoEnabled = set;
}

void TerminalWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Enter:
        break;
    default:
        if (localEchoEnabled)
            QPlainTextEdit::keyPressEvent(e);
        //emit getData(e->text().toLocal8Bit());
    }
}

void TerminalWindow::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    setFocus();
}

void TerminalWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
}

void TerminalWindow::contextMenuEvent(QContextMenuEvent *e)
{
    Q_UNUSED(e)
}
