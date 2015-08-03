#include "../headers/qtlegal.h"
#include "ui_qtlegal.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QPixmap>

qtLegal::qtLegal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qtLegal)
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

    QPixmap qtLogo = QPixmap(":/logo/Resources/logos/Qt_Logo.png");
    ui->qtLogo->setPixmap(qtLogo);
}

qtLegal::~qtLegal()
{
    delete ui;
}
