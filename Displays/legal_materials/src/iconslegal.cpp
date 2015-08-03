#include "../headers/iconslegal.h"
#include "ui_iconslegal.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>

iconsLegal::iconsLegal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iconsLegal)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(6);
    shadow->setColor(QColor(0,0,0,200));
    shadow->setOffset(0);
    this->setGraphicsEffect(shadow);
    //
    QPalette pal = this->palette();
    pal.setColor(this->backgroundRole(), QColor(255,255,255));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    ui->legalLabel->setFont(QFont("Roboto",9));

    QPixmap iLogo = QPixmap(":/logo/Resources/logos/icon_logo.png");
    ui->iconLogo->setPixmap(iLogo);
}

iconsLegal::~iconsLegal()
{
    delete ui;
}
