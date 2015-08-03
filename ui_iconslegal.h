/********************************************************************************
** Form generated from reading UI file 'iconslegal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICONSLEGAL_H
#define UI_ICONSLEGAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iconsLegal
{
public:
    QLabel *legalLabel;
    QLabel *iconLogo;

    void setupUi(QWidget *iconsLegal)
    {
        if (iconsLegal->objectName().isEmpty())
            iconsLegal->setObjectName(QStringLiteral("iconsLegal"));
        iconsLegal->resize(704, 150);
        legalLabel = new QLabel(iconsLegal);
        legalLabel->setObjectName(QStringLiteral("legalLabel"));
        legalLabel->setGeometry(QRect(200, 20, 484, 110));
        iconLogo = new QLabel(iconsLegal);
        iconLogo->setObjectName(QStringLiteral("iconLogo"));
        iconLogo->setGeometry(QRect(20, 10, 150, 120));

        retranslateUi(iconsLegal);

        QMetaObject::connectSlotsByName(iconsLegal);
    } // setupUi

    void retranslateUi(QWidget *iconsLegal)
    {
        iconsLegal->setWindowTitle(QApplication::translate("iconsLegal", "Form", 0));
        legalLabel->setText(QApplication::translate("iconsLegal", "<div>Icons made by <a href=\"http://www.flaticon.com/authors/simpleicon\" title=\"SimpleIcon\">SimpleIcon</a> from <a href=\"http://www.flaticon.com\" title=\"Flaticon\">www.flaticon.com</a>             is licensed by <a href=\"http://creativecommons.org/licenses/by/3.0/\" title=\"Creative Commons BY 3.0\">CC BY 3.0</a></div>", 0));
        iconLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class iconsLegal: public Ui_iconsLegal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICONSLEGAL_H
