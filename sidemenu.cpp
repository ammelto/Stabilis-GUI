#include "sidemenu.h"
#include "ui_sidemenu.h"
#include "sidebutton.h"
#include <QGraphicsEffect>
#include <QFontDatabase>
#include <QResource>
#include <QDebug>
#include <QGridLayout>

sidemenu::sidemenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sidemenu)
{
    ui->setupUi(this);
    QResource::registerResource(":/Resources.qrc");

    QPalette pal = this->palette();
    pal.setColor(this->backgroundRole(), QColor(70,98,158));
    this->setPalette(pal);
    this->setAutoFillBackground(true);


    ui->homeLabel->setPixmap(QPixmap(":/icons/Resources/Icons/home63.png"));
    pal = ui->home->palette();
    pal.setColor(ui->home->backgroundRole(), QColor(108,147,233));
    ui->home->setPalette(pal);
    ui->home->setAutoFillBackground(true);
    //
    ui->configLabel->setPixmap(QPixmap(":/icons/Resources/Icons/settings13.png"));
    pal = ui->config->palette();
    pal.setColor(ui->config->backgroundRole(), QColor(108,147,233));
    ui->config->setPalette(pal);
    ui->config->setAutoFillBackground(true);


    QGraphicsDropShadowEffect* homeShadow = new QGraphicsDropShadowEffect();
    homeShadow->setBlurRadius(6);
    homeShadow->setColor(QColor(0,0,0,200));
    homeShadow->setOffset(1);
    ui->home->setGraphicsEffect(homeShadow);
    //
    QGraphicsDropShadowEffect* configShadow = new QGraphicsDropShadowEffect();
    configShadow->setBlurRadius(6);
    configShadow->setColor(QColor(0,0,0,200));
    configShadow->setOffset(1);
    ui->config->setGraphicsEffect(configShadow);


    QFontDatabase fontDB;
    qDebug() << QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-BoldItalic.ttf");
    qDebug() << fontDB.addApplicationFont(":/fonts/Resources/fonts/Roboto-Thin.ttf");
    qDebug() << fontDB.addApplicationFont(":/fonts/Resources/fonts/Roboto-Regular.ttf");
    QFont font = QFont("Roboto",13);
    //
    font.setStyleName("Thin");
    ui->configLabelText->setFont(font);
    ui->homeLabelText->setFont(font);
    foreach(QString s, fontDB.styles("Roboto")){
        qDebug() << s;
    }

    /*
    sidebutton *button = new sidebutton();
    QLayout *layout = new QVBoxLayout;
    button->setGeometry(6,72,88,30);
    button->move(6,72);
    button->setSizeIncrement(100,42);
    layout->addWidget(button);
    */
}

sidemenu::~sidemenu()
{
    delete ui;
}
