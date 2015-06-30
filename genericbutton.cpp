#include "genericbutton.h"
#include "ui_genericbutton.h"
#include <QFontDatabase>
#include <QGraphicsDropShadowEffect>
#include <QDebug>

//Originally planned on having a dropshadow effect for this
//unfortunately, adding a dropshadow effect caused the entire button to vanish
//A possible cause might be that there are too many parents for this widget that also have drop shadows.
//Creating more than one drop shadow, especially within nested children, tend to have adverse effects.
//At the same time, multiple drop shadows are required in order to render them correctly
genericButton::genericButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::genericButton)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    ui->label->setFont(QFont("Roboto",11));

    this->setLocation(parent->geometry());
    this->installEventFilter(this);

}

void genericButton::setButtonText(QString s){
    ui->label->setText(s);
    ui->label->setAlignment(Qt::AlignCenter);
}

void genericButton::setTheme(QColor p, QColor s, QColor f){
    primary = p;
    secondary = s;
    font = f;

    QPalette pal = ui->label->palette();
    pal.setColor(ui->label->foregroundRole(), font);
    ui->label->setPalette(pal);
    ui->label->setAutoFillBackground(true);

    //Originally intended to use QPalette with the background color as well
    //Buttons would not render when using QPallete for some reason
    //Work around is hard coding the style sheet and parsing the color as strings
    QString color;
    color.append("QLabel{ background: " + primary.name() + "; }");
    this->setStyleSheet(color);
}

void genericButton::setLocation(QRect r){
    this->setGeometry(0,0,r.width(),r.height());
    ui->label->setGeometry(0,0,r.width(),r.height());
    ui->label->setAlignment(Qt::AlignCenter);
}

bool genericButton::eventFilter(QObject *obj, QEvent *event){
    QString color;
    switch(event->type()){
    case (QEvent::Enter):
        color.append("QLabel{ background: " + secondary.name() + "; }");
        this->setStyleSheet(color);
        break;
    case (QEvent::Leave):
        color.append("QLabel{ background: " + primary.name() + "; }");
        this->setStyleSheet(color);
        break;
    case (QEvent::MouseButtonPress):
        this->pressed();
        break;
    default:
        break;
    }
    return QObject::eventFilter(obj, event);
}

genericButton::~genericButton()
{
    delete ui;
}
