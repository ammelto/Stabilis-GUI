#include "sidemenu.h"
#include "ui_sidemenu.h"
#include <QGraphicsEffect>
#include <QFontDatabase>
#include <QResource>
#include <QDebug>
#include <QGridLayout>
#include <QEvent>
#include <QPixmap>
#include <QPainter>

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

    homeIconSource = QPixmap(":/icons/Resources/Icons/home63.png");
    ui->home->installEventFilter(this);
    ui->homeLabelText->setFont(font);
    //
    consoleIconSource = QPixmap(":/icons/Resources/Icons/web-programming.png");
    ui->console->installEventFilter(this);
    ui->consoleLabelText->setFont(font);
    //
    configIconSource = QPixmap(":/icons/Resources/Icons/settings13.png");
    ui->config->installEventFilter(this);
    ui->configLabelText->setFont(font);
    //
    docsIconSource = QPixmap(":/icons/Resources/Icons/file94.png");
    ui->docs->installEventFilter(this);
    ui->docsLabelText->setFont(font);
    //
    windowIconSource = QPixmap(":/icons/Resources/Icons/website7.png");
    ui->window->installEventFilter(this);
    ui->windowLabelText->setFont(font);
    //
    infoIconSource = QPixmap(":/icons/Resources/Icons/info21.png");
    ui->info->installEventFilter(this);
    ui->infoLabelText->setFont(font);

}

void sidemenu::setTheme(QColor p, QColor s, QColor font){
    primaryColor = p;
    secondaryColor = s;
    fontColor = font;
    repaint();
    repaintIcons();
}

bool sidemenu::eventFilter(QObject *obj, QEvent *event){
    if(obj == ui->home){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->home->palette();
            pal.setColor(ui->home->backgroundRole(), secondaryColor);
            ui->home->setPalette(pal);
            ui->home->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            pal = ui->home->palette();
            pal.setColor(ui->home->backgroundRole(), primaryColor);
            ui->home->setPalette(pal);
            ui->home->setAutoFillBackground(true);
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = home;
            setDisplay(home);
            repaint();
            break;
        default:
            break;
        }
    }else if(obj == ui->console){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->console->palette();
            pal.setColor(ui->console->backgroundRole(), secondaryColor);
            ui->console->setPalette(pal);
            ui->console->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            pal = ui->console->palette();
            pal.setColor(ui->console->backgroundRole(), primaryColor);
            ui->console->setPalette(pal);
            ui->console->setAutoFillBackground(true);
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = console;
            setDisplay(console);
            repaint();
            break;
        default:
            break;
        }
    }else if(obj == ui->config){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->config->palette();
            pal.setColor(ui->config->backgroundRole(), secondaryColor);
            ui->config->setPalette(pal);
            ui->config->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            pal = ui->config->palette();
            pal.setColor(ui->config->backgroundRole(), primaryColor);
            ui->config->setPalette(pal);
            ui->config->setAutoFillBackground(true);
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = config;
            setDisplay(config);
            repaint();
            break;
        default:
            break;
        }
    }else if(obj == ui->docs){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->docs->palette();
            pal.setColor(ui->console->backgroundRole(), secondaryColor);
            ui->docs->setPalette(pal);
            ui->docs->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            pal = ui->docs->palette();
            pal.setColor(ui->docs->backgroundRole(), primaryColor);
            ui->docs->setPalette(pal);
            ui->docs->setAutoFillBackground(true);
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = docs;
            setDisplay(docs);
            repaint();
            break;
        default:
            break;
        }
    }else if(obj == ui->window){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->window->palette();
            pal.setColor(ui->window->backgroundRole(), secondaryColor);
            ui->window->setPalette(pal);
            ui->window->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            pal = ui->window->palette();
            pal.setColor(ui->window->backgroundRole(), primaryColor);
            ui->window->setPalette(pal);
            ui->window->setAutoFillBackground(true);
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = window;
            setDisplay(window);
            repaint();
            break;
        default:
            break;
        }
    }else if(obj == ui->info){
        switch(event->type()){
        case (QEvent::Enter):
            pal = ui->info->palette();
            pal.setColor(ui->info->backgroundRole(), secondaryColor);
            ui->info->setPalette(pal);
            ui->info->setAutoFillBackground(true);
            break;
        case (QEvent::Leave):
            if(currentDisplay != console){
                pal = ui->info->palette();
                pal.setColor(ui->info->backgroundRole(), primaryColor);
                ui->info->setPalette(pal);
                ui->info->setAutoFillBackground(true);
            }
            break;
        case (QEvent::MouseButtonPress):
            currentDisplay = info;
            setDisplay(info);
            repaint();
            break;
        default:
            break;
        }
    }
    return QObject::eventFilter(obj, event);
}

void sidemenu::repaintIcons(){
    QPixmap homeIcon = homeIconSource;
    QPainter homePainter(&homeIcon);
    homePainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    homePainter.fillRect(homeIcon.rect(),fontColor);
    homePainter.end();
    ui->homeLabel->setPixmap(homeIcon);

    QPixmap docsIcon = docsIconSource;
    QPainter docsPainter(&docsIcon);
    docsPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    docsPainter.fillRect(docsIcon.rect(),fontColor);
    docsPainter.end();
    ui->docsLabel->setPixmap(docsIcon);

    QPixmap consoleIcon = consoleIconSource;
    QPainter consolePainter(&consoleIcon);
    consolePainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    consolePainter.fillRect(consoleIcon.rect(),fontColor);
    consolePainter.end();
    ui->consoleLabel->setPixmap(consoleIcon);

    QPixmap configIcon = configIconSource;
    QPainter configPainter(&configIcon);
    configPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    configPainter.fillRect(configIcon.rect(),fontColor);
    configPainter.end();
    ui->configLabel->setPixmap(configIcon);

    QPixmap windowIcon = windowIconSource;
    QPainter windowPainter(&windowIcon);
    windowPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    windowPainter.fillRect(windowIcon.rect(),fontColor);
    windowPainter.end();
    ui->windowLabel->setPixmap(windowIcon);

    QPixmap infoIcon = infoIconSource;
    QPainter infoPainter(&infoIcon);
    infoPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    infoPainter.fillRect(infoIcon.rect(),fontColor);
    infoPainter.end();
    ui->infoLabel->setPixmap(infoIcon);

}

void sidemenu::repaint(){
/*
    pal = ui->LINE->palette();
    pal.setColor(this->backgroundRole(), QColor(0,0,0));
    ui->LINE->setPalette(pal);
    ui->LINE->setAutoFillBackground(true);

    pal = ui->LINETOP->palette();
    pal.setColor(this->backgroundRole(), QColor(0,0,0));
    ui->LINETOP->setPalette(pal);
    ui->LINETOP->setAutoFillBackground(true);
*/

    //BACKGROUND DEFAULT
    pal = this->palette();
    pal.setColor(this->backgroundRole(), primaryColor);
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    //HOME BUTTON DEFAULT
    pal = ui->homeSelect->palette();
    pal.setColor(ui->homeSelect->backgroundRole(), primaryColor);
    ui->homeSelect->setPalette(pal);
    ui->homeSelect->setAutoFillBackground(true);
    ui->homeLabelText->setFont(QFont("Roboto",12));
    ui->homeLabelText->setGeometry(38,6,42,20);
    ui->homeLabel->setGeometry(19,4,16,20);
    ui->home->setGeometry(0,0,100,30);

    //CONFIG BUTTON DEFAULT
    pal = ui->configSelect->palette();
    pal.setColor(ui->configSelect->backgroundRole(), primaryColor);
    ui->configSelect->setPalette(pal);
    ui->configSelect->setAutoFillBackground(true);
    ui->configLabelText->setFont(QFont("Roboto",12));
    ui->configLabelText->setGeometry(35,6,45,20);
    ui->configLabel->setGeometry(16,5,16,20);
    ui->config->setGeometry(200,0,100,30);

    //CONSOLE BUTTON DEFAULT
    pal = ui->consoleSelect->palette();
    pal.setColor(ui->consoleSelect->backgroundRole(), primaryColor);
    ui->consoleSelect->setPalette(pal);
    ui->consoleSelect->setAutoFillBackground(true);
    ui->consoleLabelText->setFont(QFont("Roboto",12));
    ui->consoleLabelText->setGeometry(31,6,58,20);
    ui->consoleLabel->setGeometry(12,5,16,20);
    ui->console->setGeometry(100,0,100,30);

    //DOCS BUTTON DEFAULT
    pal = ui->docsSelect->palette();
    pal.setColor(ui->docsSelect->backgroundRole(), primaryColor);
    ui->docsSelect->setPalette(pal);
    ui->docsSelect->setAutoFillBackground(true);
    ui->docsLabelText->setFont(QFont("Roboto",12));
    ui->docsLabelText->setGeometry(40,6,36,20);
    ui->docsLabel->setGeometry(21,5,16,20);
    ui->docs->setGeometry(300,0,100,30);

    //WINDOW BUTTON DEFAULT
    pal = ui->windowSelect->palette();
    pal.setColor(ui->windowSelect->backgroundRole(), primaryColor);
    ui->windowSelect->setPalette(pal);
    ui->windowSelect->setAutoFillBackground(true);
    ui->windowLabelText->setFont(QFont("Roboto",12));
    ui->windowLabelText->setGeometry(0,0,0,0);
    ui->windowLabel->setGeometry(7,0,30,30);
    ui->window->setGeometry(740,0,30,30);

    //INFO BUTTON DEFAULT
    pal = ui->infoSelect->palette();
    pal.setColor(ui->infoSelect->backgroundRole(), primaryColor);
    ui->infoSelect->setPalette(pal);
    ui->infoSelect->setAutoFillBackground(true);
    ui->infoLabelText->setFont(QFont("Roboto",12));
    ui->infoLabelText->setGeometry(0,0,0,0);
    ui->infoLabel->setGeometry(7,0,30,30);
    ui->info->setGeometry(770,0,30,30);


    switch(currentDisplay){
    case home:
        pal = ui->homeSelect->palette();
        pal.setColor(ui->homeSelect->backgroundRole(), fontColor);
        ui->homeSelect->setPalette(pal);
        ui->homeSelect->setAutoFillBackground(true);
        break;
    case console:
        pal = ui->consoleSelect->palette();
        pal.setColor(ui->consoleSelect->backgroundRole(), fontColor);
        ui->consoleSelect->setPalette(pal);
        ui->consoleSelect->setAutoFillBackground(true);
        break;
    case config:
        pal = ui->configSelect->palette();
        pal.setColor(ui->configSelect->backgroundRole(), fontColor);
        ui->configSelect->setPalette(pal);
        ui->configSelect->setAutoFillBackground(true);
        break;
    case window:
        pal = ui->windowSelect->palette();
        pal.setColor(ui->windowSelect->backgroundRole(), fontColor);
        ui->windowSelect->setPalette(pal);
        ui->windowSelect->setAutoFillBackground(true);
        break;
    case info:
        pal = ui->infoSelect->palette();
        pal.setColor(ui->infoSelect->backgroundRole(), fontColor);
        ui->infoSelect->setPalette(pal);
        ui->infoSelect->setAutoFillBackground(true);
        break;
    case docs:
        pal = ui->docsSelect->palette();
        pal.setColor(ui->docsSelect->backgroundRole(), fontColor);
        ui->docsSelect->setPalette(pal);
        ui->docsSelect->setAutoFillBackground(true);
        break;
    }

}

sidemenu::~sidemenu()
{
    delete ui;
}
