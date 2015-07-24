#include "../headers/docsnavmenu.h"
#include "ui_docsnavmenu.h"
#include <QGraphicsEffect>

DocsNavMenu::DocsNavMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocsNavMenu)
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
}

DocsNavMenu::~DocsNavMenu()
{
    delete ui;
}
