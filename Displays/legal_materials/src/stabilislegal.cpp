#include "../headers/stabilislegal.h"
#include "ui_stabilislegal.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>

stabilisLegal::stabilisLegal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stabilisLegal)
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
}

stabilisLegal::~stabilisLegal()
{
    delete ui;
}
