#include "sidemenu.h"
#include "ui_sidemenu.h"
#include <QGraphicsEffect>
#include <QFontDatabase>
#include <QResource>
#include <QDebug>
#include <QGridLayout>
#include <QEvent>

sidemenu::sidemenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sidemenu)
{
    ui->setupUi(this);
    QResource::registerResource(":/Resources.qrc");

    QFontDatabase fontDB;
    qDebug() << QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-BoldItalic.ttf");
    qDebug() << fontDB.addApplicationFont(":/fonts/Resources/fonts/Roboto-Thin.ttf");
    qDebug() << fontDB.addApplicationFont(":/fonts/Resources/fonts/Roboto-Regular.ttf");
    QFont font = QFont("Roboto",12);
    font.setStyleName("Thin");
    //
    pal = this->palette();
    pal.setColor(this->backgroundRole(), QColor(70,98,158));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    ui->home->installEventFilter(this);
    ui->homeLabel->setPixmap(QPixmap(":/icons/Resources/Icons/home63.png"));
    ui->homeLabelText->setFont(font);
    //
    ui->console->installEventFilter(this);
    ui->consoleLabel->setPixmap(QPixmap(":/icons/Resources/Icons/web-programming.png"));
    ui->consoleLabelText->setFont(font);
    //
    ui->config->installEventFilter(this);
    ui->configLabel->setPixmap(QPixmap(":/icons/Resources/Icons/settings13.png"));
    ui->configLabelText->setFont(font);


    enabledShadow = new QGraphicsDropShadowEffect();
    enabledShadow->setBlurRadius(10);
    enabledShadow->setColor(QColor(0,0,0,200));
    enabledShadow->setOffset(1);

    homeShadow = new QGraphicsDropShadowEffect();
    homeShadow->setBlurRadius(6);
    homeShadow->setColor(QColor(0,0,0,200));
    homeShadow->setOffset(1);
    ui->home->setGraphicsEffect(homeShadow);

    consoleShadow = new QGraphicsDropShadowEffect();
    consoleShadow->setBlurRadius(6);
    consoleShadow->setColor(QColor(0,0,0,200));
    consoleShadow->setOffset(1);
    ui->console->setGraphicsEffect(consoleShadow);

    configShadow = new QGraphicsDropShadowEffect();
    configShadow->setBlurRadius(6);
    configShadow->setColor(QColor(0,0,0,200));
    configShadow->setOffset(1);
    ui->config->setGraphicsEffect(configShadow);

    resetButtons();
}

bool sidemenu::eventFilter(QObject *obj, QEvent *event){
    if(obj == ui->home){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->home->palette();
            pal.setColor(ui->home->backgroundRole(), QColor(148,180,255));
            ui->home->setPalette(pal);
            ui->home->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != home){
                pal = ui->home->palette();
                pal.setColor(ui->home->backgroundRole(), QColor(108,147,233));
                ui->home->setPalette(pal);
                ui->home->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = home;
            resetButtons();
            break;
        default:
            break;
        }
    }else if(obj == ui->console){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->console->palette();
            pal.setColor(ui->console->backgroundRole(), QColor(148,180,255));
            ui->console->setPalette(pal);
            ui->console->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != console){
                pal = ui->console->palette();
                pal.setColor(ui->console->backgroundRole(), QColor(108,147,233));
                ui->console->setPalette(pal);
                ui->console->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = console;
            resetButtons();
            break;
        default:
            break;
        }
    }else if(obj == ui->config){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->config->palette();
            pal.setColor(ui->config->backgroundRole(), QColor(148,180,255));
            ui->config->setPalette(pal);
            ui->config->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != config){
                pal = ui->config->palette();
                pal.setColor(ui->config->backgroundRole(), QColor(108,147,233));
                ui->config->setPalette(pal);
                ui->config->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = config;
            resetButtons();
            break;
        default:
            break;
        }
    }

    switch(currentDisplay){
    case home:
        pal = ui->home->palette();
        pal.setColor(ui->home->backgroundRole(), QColor(148,180,255));
        ui->home->setPalette(pal);
        ui->home->setAutoFillBackground(true);
        ui->home->setGeometry(0,0,100,30);
        break;
    case console:
        pal = ui->console->palette();
        pal.setColor(ui->console->backgroundRole(), QColor(148,180,255));
        ui->console->setPalette(pal);
        ui->console->setAutoFillBackground(true);
        ui->console->setGeometry(0,72,100,30);
        break;
    case config:
        pal = ui->config->palette();
        pal.setColor(ui->config->backgroundRole(), QColor(148,180,255));
        ui->config->setPalette(pal);
        ui->config->setAutoFillBackground(true);
        ui->config->setGeometry(0,36,100,30);
        break;
    }


    return QObject::eventFilter(obj, event);
}

void sidemenu::resetButtons(){

    ui->home->setGeometry(6,0,88,30);
    ui->config->setGeometry(6,36,88,30);
    ui->console->setGeometry(6,72,88,30);

    //if(ui->home->graphicsEffect() != homeShadow) ui->home->setGraphicsEffect(homeShadow);
    pal = ui->home->palette();
    pal.setColor(ui->home->backgroundRole(), QColor(108,147,233));
    ui->home->setPalette(pal);
    ui->home->setAutoFillBackground(true);

    //if(ui->console->graphicsEffect() != consoleShadow) ui->console->setGraphicsEffect(consoleShadow);
    pal = ui->console->palette();
    pal.setColor(ui->console->backgroundRole(), QColor(108,147,233));
    ui->console->setPalette(pal);
    ui->console->setAutoFillBackground(true);

    //if(ui->config->graphicsEffect() != configShadow) ui->home->setGraphicsEffect(configShadow);
    pal = ui->config->palette();
    pal.setColor(ui->config->backgroundRole(), QColor(108,147,233));
    ui->config->setPalette(pal);
    ui->config->setAutoFillBackground(true);
}

sidemenu::~sidemenu()
{
    delete ui;
}
