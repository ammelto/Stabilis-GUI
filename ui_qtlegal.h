/********************************************************************************
** Form generated from reading UI file 'qtlegal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLEGAL_H
#define UI_QTLEGAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtLegal
{
public:
    QLabel *legalLabel;
    QLabel *qtLogo;

    void setupUi(QWidget *qtLegal)
    {
        if (qtLegal->objectName().isEmpty())
            qtLegal->setObjectName(QStringLiteral("qtLegal"));
        qtLegal->resize(704, 150);
        legalLabel = new QLabel(qtLegal);
        legalLabel->setObjectName(QStringLiteral("legalLabel"));
        legalLabel->setGeometry(QRect(200, 20, 484, 110));
        legalLabel->setWordWrap(true);
        qtLogo = new QLabel(qtLegal);
        qtLogo->setObjectName(QStringLiteral("qtLogo"));
        qtLogo->setGeometry(QRect(20, 10, 150, 120));

        retranslateUi(qtLegal);

        QMetaObject::connectSlotsByName(qtLegal);
    } // setupUi

    void retranslateUi(QWidget *qtLegal)
    {
        qtLegal->setWindowTitle(QApplication::translate("qtLegal", "Form", 0));
        legalLabel->setText(QApplication::translate("qtLegal", "<html><head/><body><p><span style=\" font-size:9pt;\">Vivamus sem risus, bibendum eget posuere et, scelerisque vitae mauris. Integer metus tortor, feugiat sed laoreet laoreet, venenatis a ipsum. Curabitur sed arcu sollicitudin, imperdiet nibh vel, mollis erat. Donec aliquet tortor eget consequat egestas. In fermentum fermentum accumsan. Vivamus varius elit tortor, non dapibus lectus semper quis. Aliquam lacus risus, commodo et malesuada eu, venenatis eget erat. Sed vel tincidunt massa. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut ullamcorper lectus quis mollis porttitor. Nunc et quam vitae ex luctus euismod. </span></p></body></html>", 0));
        qtLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class qtLegal: public Ui_qtLegal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLEGAL_H
