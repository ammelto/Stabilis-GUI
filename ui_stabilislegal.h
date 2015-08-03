/********************************************************************************
** Form generated from reading UI file 'stabilislegal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STABILISLEGAL_H
#define UI_STABILISLEGAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stabilisLegal
{
public:
    QLabel *legalLabel;
    QLabel *stabilisLogo;

    void setupUi(QWidget *stabilisLegal)
    {
        if (stabilisLegal->objectName().isEmpty())
            stabilisLegal->setObjectName(QStringLiteral("stabilisLegal"));
        stabilisLegal->resize(704, 150);
        legalLabel = new QLabel(stabilisLegal);
        legalLabel->setObjectName(QStringLiteral("legalLabel"));
        legalLabel->setGeometry(QRect(200, 20, 484, 110));
        legalLabel->setWordWrap(true);
        stabilisLogo = new QLabel(stabilisLegal);
        stabilisLogo->setObjectName(QStringLiteral("stabilisLogo"));
        stabilisLogo->setGeometry(QRect(20, 10, 150, 120));

        retranslateUi(stabilisLegal);

        QMetaObject::connectSlotsByName(stabilisLegal);
    } // setupUi

    void retranslateUi(QWidget *stabilisLegal)
    {
        stabilisLegal->setWindowTitle(QApplication::translate("stabilisLegal", "Form", 0));
        legalLabel->setText(QApplication::translate("stabilisLegal", "<html><head/><body><p><span style=\" font-family:'Arial,Helvetica,sans'; font-size:9pt; color:#000000;\">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vehicula est a sem molestie, finibus tempor turpis sodales. Donec tempus, diam vel facilisis pretium, leo risus dignissim sapien, eget varius neque ex quis erat. Praesent vehicula commodo enim et varius. Phasellus ante elit, accumsan ut libero eu, tristique vestibulum diam. Vestibulum rutrum mollis ex, non dictum velit aliquet congue. Aliquam eget consequat odio, et bibendum mauris. Vivamus suscipit congue mauris egestas ullamcorper. Vestibulum sed metus porttitor, lobortis nulla eget, condimentum augue.</span></p></body></html>", 0));
        stabilisLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stabilisLegal: public Ui_stabilisLegal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STABILISLEGAL_H
