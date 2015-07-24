#include "../headers/terminalwindow.h"
#include "ui_terminalwindow.h"
#include <QGraphicsEffect>
#include <QScrollBar>
#include <QTextBlock>
#include <QTextDocument>
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
    bool forwardEvent = true;
    const int curs_pos = this->textCursor().positionInBlock();

    switch (e->key()) {
        case Qt::Key_Return:
            sendCommand();
        break;
        case Qt::Key_Backspace:
            if(curs_pos <= cursor_stop_position)
                forwardEvent = false;
        break;
        case Qt::Key_Left:
            if(curs_pos <= cursor_stop_position)
                forwardEvent = false;
        break;
        //case Qt::Key_Right:
        case Qt::Key_Up:
            forwardEvent = false;
        break;
        case Qt::Key_Down:
        break;

        default:
        break;
    }
    if (localEchoEnabled && forwardEvent)
        QPlainTextEdit::keyPressEvent(e);
}

void TerminalWindow::sendCommand(){
    QString command;
    int err;
    command = this->document()->findBlockByLineNumber(this->document()->blockCount()-1).text();
    command = command.right(command.length()-cursor_stop_position+1);
    printf("trying send write command\n");
    err = writeCommand(command);
    //if not err
    prev_command_length = command.length();
}

void TerminalWindow::updateTerminal(char* text){

    QString string;
    string = string.fromUtf8(text);
    moveCursor(QTextCursor::End);
    insertPlainText(string);
    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
    moveCursor(QTextCursor::End);
    cursor_stop_position = this->textCursor().positionInBlock() - prev_command_length;
}


void TerminalWindow::writeOut(QString text){



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
