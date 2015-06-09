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

    qDebug() << QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-BoldItalic.ttf");
    qDebug() << QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-Thin.ttf");
    qDebug() << QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/Roboto-Regular.ttf");
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
    //
    ui->docs->installEventFilter(this);
    ui->docsLabel->setPixmap(QPixmap(":/icons/Resources/Icons/file94.png"));
    ui->docsLabelText->setFont(font);
    //
    ui->window->installEventFilter(this);
    ui->windowLabel->setPixmap(QPixmap(":/icons/Resources/Icons/website7.png"));
    ui->windowLabelText->setFont(font);
    //
    ui->info->installEventFilter(this);
    ui->infoLabel->setPixmap(QPixmap(":/icons/Resources/Icons/info21.png"));
    ui->infoLabelText->setFont(font);


    enabledShadow = new QGraphicsDropShadowEffect();
    enabledShadow->setBlurRadius(10);
    enabledShadow->setColor(QColor(0,0,0,200));
    enabledShadow->setOffset(1);
    //
    homeShadow = new QGraphicsDropShadowEffect();
    homeShadow->setBlurRadius(6);
    homeShadow->setColor(QColor(0,0,0,200));
    homeShadow->setOffset(1);
    ui->home->setGraphicsEffect(homeShadow);
    //
    consoleShadow = new QGraphicsDropShadowEffect();
    consoleShadow->setBlurRadius(6);
    consoleShadow->setColor(QColor(0,0,0,200));
    consoleShadow->setOffset(1);
    ui->console->setGraphicsEffect(consoleShadow);
    //
    configShadow = new QGraphicsDropShadowEffect();
    configShadow->setBlurRadius(6);
    configShadow->setColor(QColor(0,0,0,200));
    configShadow->setOffset(1);
    ui->config->setGraphicsEffect(configShadow);
    //
    windowShadow = new QGraphicsDropShadowEffect();
    windowShadow->setBlurRadius(6);
    windowShadow->setColor(QColor(0,0,0,200));
    windowShadow->setOffset(1);
    ui->window->setGraphicsEffect(windowShadow);
    //
    infoShadow = new QGraphicsDropShadowEffect();
    infoShadow->setBlurRadius(6);
    infoShadow->setColor(QColor(0,0,0,200));
    infoShadow->setOffset(1);
    ui->info->setGraphicsEffect(infoShadow);
    //
    docsShadow = new QGraphicsDropShadowEffect();
    docsShadow->setBlurRadius(6);
    docsShadow->setColor(QColor(0,0,0,200));
    docsShadow->setOffset(1);
    ui->docs->setGraphicsEffect(docsShadow);

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
            setDisplay(home);
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
            setDisplay(console);
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
            setDisplay(config);
            resetButtons();
            break;
        default:
            break;
        }
    }else if(obj == ui->docs){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->docs->palette();
            pal.setColor(ui->console->backgroundRole(), QColor(148,180,255));
            ui->docs->setPalette(pal);
            ui->docs->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != docs){
                pal = ui->docs->palette();
                pal.setColor(ui->docs->backgroundRole(), QColor(108,147,233));
                ui->docs->setPalette(pal);
                ui->docs->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = docs;
            setDisplay(docs);
            resetButtons();
            break;
        default:
            break;
        }
    }else if(obj == ui->window){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->window->palette();
            pal.setColor(ui->window->backgroundRole(), QColor(148,180,255));
            ui->window->setPalette(pal);
            ui->window->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != console){
                pal = ui->window->palette();
                pal.setColor(ui->window->backgroundRole(), QColor(108,147,233));
                ui->window->setPalette(pal);
                ui->window->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = window;
            setDisplay(window);
            resetButtons();
            break;
        default:
            break;
        }
    }else if(obj == ui->info){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->info->palette();
            pal.setColor(ui->info->backgroundRole(), QColor(148,180,255));
            ui->info->setPalette(pal);
            ui->info->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != console){
                pal = ui->info->palette();
                pal.setColor(ui->info->backgroundRole(), QColor(108,147,233));
                ui->info->setPalette(pal);
                ui->info->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = info;
            setDisplay(info);
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
        ui->home->setGeometry(8,0,94,32);
        ui->homeLabelText->setFont(QFont("Roboto",13));
        ui->homeLabelText->setGeometry(24,7,70,20);
        ui->homeLabel->setGeometry(5,6,16,20);
        break;
    case console:
        pal = ui->console->palette();
        pal.setColor(ui->console->backgroundRole(), QColor(148,180,255));
        ui->console->setPalette(pal);
        ui->console->setAutoFillBackground(true);
        ui->console->setGeometry(8,72,94,32);
        ui->consoleLabelText->setFont(QFont("Roboto",13));
        ui->consoleLabelText->setGeometry(24,7,70,20);
        ui->consoleLabel->setGeometry(5,6,16,20);
        break;
    case config:
        pal = ui->config->palette();
        pal.setColor(ui->config->backgroundRole(), QColor(148,180,255));
        ui->config->setPalette(pal);
        ui->config->setAutoFillBackground(true);
        ui->config->setGeometry(8,108,94,32);
        ui->configLabelText->setFont(QFont("Roboto",13));
        ui->configLabelText->setGeometry(24,7,70,20);
        ui->configLabel->setGeometry(5,6,16,20);
        break;
    case window:
        pal = ui->window->palette();
        pal.setColor(ui->window->backgroundRole(), QColor(148,180,255));
        ui->window->setPalette(pal);
        ui->window->setAutoFillBackground(true);
        ui->window->setGeometry(8,144,94,32);
        ui->windowLabelText->setFont(QFont("Roboto",13));
        ui->windowLabelText->setGeometry(24,7,70,20);
        ui->windowLabel->setGeometry(5,6,16,20);
        break;
    case info:
        pal = ui->info->palette();
        pal.setColor(ui->info->backgroundRole(), QColor(148,180,255));
        ui->info->setPalette(pal);
        ui->info->setAutoFillBackground(true);
        ui->info->setGeometry(8,180,94,32);
        ui->infoLabelText->setFont(QFont("Roboto",13));
        ui->infoLabelText->setGeometry(24,7,70,20);
        ui->infoLabel->setGeometry(5,6,16,20);
        break;
    case docs:
        pal = ui->docs->palette();
        pal.setColor(ui->docs->backgroundRole(), QColor(148,180,255));
        ui->docs->setPalette(pal);
        ui->docs->setAutoFillBackground(true);
        ui->docs->setGeometry(8,36,94,32);
        ui->docsLabelText->setFont(QFont("Roboto",13));
        ui->docsLabelText->setGeometry(24,7,70,20);
        ui->docsLabel->setGeometry(5,6,16,20);
        break;
    }


    return QObject::eventFilter(obj, event);
}

void sidemenu::resetButtons(){

    //HOME BUTTON DEFAULT
    pal = ui->home->palette();
    pal.setColor(ui->home->backgroundRole(), QColor(108,147,233));
    ui->home->setPalette(pal);
    ui->home->setAutoFillBackground(true);
    ui->homeLabelText->setFont(QFont("Roboto",12));
    ui->homeLabelText->setGeometry(24,7,70,20);
    ui->homeLabel->setGeometry(5,5,16,20);
    ui->home->setGeometry(11,1,88,30);

    //CONFIG BUTTON DEFAULT
    pal = ui->config->palette();
    pal.setColor(ui->config->backgroundRole(), QColor(108,147,233));
    ui->config->setPalette(pal);
    ui->config->setAutoFillBackground(true);
    ui->configLabelText->setFont(QFont("Roboto",12));
    ui->configLabelText->setGeometry(24,7,70,20);
    ui->configLabel->setGeometry(5,5,16,20);
    ui->config->setGeometry(11,109,88,30);

    //CONSOLE BUTTON DEFAULT
    pal = ui->console->palette();
    pal.setColor(ui->console->backgroundRole(), QColor(108,147,233));
    ui->console->setPalette(pal);
    ui->console->setAutoFillBackground(true);
    ui->consoleLabelText->setFont(QFont("Roboto",12));
    ui->consoleLabelText->setGeometry(24,7,70,20);
    ui->consoleLabel->setGeometry(5,5,16,20);
    ui->console->setGeometry(11,73,88,30);

    //DOCS BUTTON DEFAULT
    pal = ui->docs->palette();
    pal.setColor(ui->docs->backgroundRole(), QColor(108,147,233));
    ui->docs->setPalette(pal);
    ui->docs->setAutoFillBackground(true);
    ui->docsLabelText->setFont(QFont("Roboto",12));
    ui->docsLabelText->setGeometry(24,7,70,20);
    ui->docsLabel->setGeometry(5,5,16,20);
    ui->docs->setGeometry(11,37,88,30);

    //WINDOW BUTTON DEFAULT
    pal = ui->window->palette();
    pal.setColor(ui->window->backgroundRole(), QColor(108,147,233));
    ui->window->setPalette(pal);
    ui->window->setAutoFillBackground(true);
    ui->windowLabelText->setFont(QFont("Roboto",12));
    ui->windowLabelText->setGeometry(24,7,70,20);
    ui->windowLabel->setGeometry(5,5,16,20);
    ui->window->setGeometry(11,145,88,30);

    //INFO BUTTON DEFAULT
    pal = ui->info->palette();
    pal.setColor(ui->info->backgroundRole(), QColor(108,147,233));
    ui->info->setPalette(pal);
    ui->info->setAutoFillBackground(true);
    ui->infoLabelText->setFont(QFont("Roboto",12));
    ui->infoLabelText->setGeometry(24,7,70,20);
    ui->infoLabel->setGeometry(5,5,16,20);
    ui->info->setGeometry(11,181,88,30);




}

sidemenu::~sidemenu()
{
    delete ui;
}
