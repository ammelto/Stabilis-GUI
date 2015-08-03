/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_titlebar
{
public:
    QWidget *closeButton;
    QLabel *closeLabel;
    QWidget *minimizeButton;
    QLabel *minimizeLabel;
    QWidget *maximizeButton;
    QLabel *maximizeLabel;
    QLabel *title;

    void setupUi(QWidget *titlebar)
    {
        if (titlebar->objectName().isEmpty())
            titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->resize(800, 20);
        closeButton = new QWidget(titlebar);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(780, 0, 20, 20));
        closeLabel = new QLabel(closeButton);
        closeLabel->setObjectName(QStringLiteral("closeLabel"));
        closeLabel->setGeometry(QRect(0, 0, 20, 20));
        minimizeButton = new QWidget(titlebar);
        minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
        minimizeButton->setGeometry(QRect(740, 0, 20, 20));
        minimizeLabel = new QLabel(minimizeButton);
        minimizeLabel->setObjectName(QStringLiteral("minimizeLabel"));
        minimizeLabel->setGeometry(QRect(0, 0, 20, 20));
        maximizeButton = new QWidget(titlebar);
        maximizeButton->setObjectName(QStringLiteral("maximizeButton"));
        maximizeButton->setGeometry(QRect(760, 0, 20, 20));
        maximizeLabel = new QLabel(maximizeButton);
        maximizeLabel->setObjectName(QStringLiteral("maximizeLabel"));
        maximizeLabel->setGeometry(QRect(0, 0, 20, 20));
        title = new QLabel(titlebar);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(5, 2, 61, 20));
        QFont font;
        font.setFamily(QStringLiteral("Serif"));
        font.setPointSize(14);
        title->setFont(font);

        retranslateUi(titlebar);

        QMetaObject::connectSlotsByName(titlebar);
    } // setupUi

    void retranslateUi(QWidget *titlebar)
    {
        titlebar->setWindowTitle(QApplication::translate("titlebar", "Form", 0));
        closeLabel->setText(QApplication::translate("titlebar", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">x</span></p></body></html>", 0));
        minimizeLabel->setText(QApplication::translate("titlebar", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">-</span></p></body></html>", 0));
        maximizeLabel->setText(QApplication::translate("titlebar", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">+</span></p></body></html>", 0));
        title->setText(QApplication::translate("titlebar", "<html><head/><body><p><span style=\" font-size:12pt;\">Stabilis</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class titlebar: public Ui_titlebar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
