/********************************************************************************
** Form generated from reading UI file 'sidemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEMENU_H
#define UI_SIDEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sidemenu
{
public:
    QWidget *home;
    QLabel *homeLabel;
    QLabel *homeLabelText;
    QWidget *homeSelect;
    QWidget *config;
    QLabel *configLabel;
    QLabel *configLabelText;
    QWidget *configSelect;
    QWidget *console;
    QLabel *consoleLabel;
    QLabel *consoleLabelText;
    QWidget *consoleSelect;
    QWidget *docs;
    QLabel *docsLabel;
    QLabel *docsLabelText;
    QWidget *docsSelect;
    QWidget *window;
    QLabel *windowLabel;
    QLabel *windowLabelText;
    QWidget *windowSelect;
    QWidget *info;
    QLabel *infoLabel;
    QLabel *infoLabelText;
    QWidget *infoSelect;

    void setupUi(QWidget *sidemenu)
    {
        if (sidemenu->objectName().isEmpty())
            sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->resize(800, 30);
        home = new QWidget(sidemenu);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(0, 0, 100, 30));
        homeLabel = new QLabel(home);
        homeLabel->setObjectName(QStringLiteral("homeLabel"));
        homeLabel->setGeometry(QRect(5, 5, 16, 20));
        homeLabelText = new QLabel(home);
        homeLabelText->setObjectName(QStringLiteral("homeLabelText"));
        homeLabelText->setGeometry(QRect(27, 6, 61, 20));
        homeLabelText->setStyleSheet(QStringLiteral(""));
        homeSelect = new QWidget(home);
        homeSelect->setObjectName(QStringLiteral("homeSelect"));
        homeSelect->setGeometry(QRect(0, 29, 100, 1));
        config = new QWidget(sidemenu);
        config->setObjectName(QStringLiteral("config"));
        config->setGeometry(QRect(300, 0, 100, 30));
        configLabel = new QLabel(config);
        configLabel->setObjectName(QStringLiteral("configLabel"));
        configLabel->setGeometry(QRect(5, 5, 16, 20));
        configLabelText = new QLabel(config);
        configLabelText->setObjectName(QStringLiteral("configLabelText"));
        configLabelText->setGeometry(QRect(27, 6, 61, 20));
        configSelect = new QWidget(config);
        configSelect->setObjectName(QStringLiteral("configSelect"));
        configSelect->setGeometry(QRect(0, 29, 100, 1));
        console = new QWidget(sidemenu);
        console->setObjectName(QStringLiteral("console"));
        console->setGeometry(QRect(100, 0, 100, 30));
        consoleLabel = new QLabel(console);
        consoleLabel->setObjectName(QStringLiteral("consoleLabel"));
        consoleLabel->setGeometry(QRect(5, 5, 16, 20));
        consoleLabelText = new QLabel(console);
        consoleLabelText->setObjectName(QStringLiteral("consoleLabelText"));
        consoleLabelText->setGeometry(QRect(27, 6, 61, 20));
        consoleSelect = new QWidget(console);
        consoleSelect->setObjectName(QStringLiteral("consoleSelect"));
        consoleSelect->setGeometry(QRect(0, 29, 100, 1));
        docs = new QWidget(sidemenu);
        docs->setObjectName(QStringLiteral("docs"));
        docs->setGeometry(QRect(200, 0, 100, 30));
        docsLabel = new QLabel(docs);
        docsLabel->setObjectName(QStringLiteral("docsLabel"));
        docsLabel->setGeometry(QRect(5, 5, 16, 20));
        docsLabelText = new QLabel(docs);
        docsLabelText->setObjectName(QStringLiteral("docsLabelText"));
        docsLabelText->setGeometry(QRect(27, 6, 61, 20));
        docsSelect = new QWidget(docs);
        docsSelect->setObjectName(QStringLiteral("docsSelect"));
        docsSelect->setGeometry(QRect(0, 29, 100, 1));
        window = new QWidget(sidemenu);
        window->setObjectName(QStringLiteral("window"));
        window->setGeometry(QRect(400, 0, 100, 30));
        windowLabel = new QLabel(window);
        windowLabel->setObjectName(QStringLiteral("windowLabel"));
        windowLabel->setGeometry(QRect(5, 5, 16, 20));
        windowLabelText = new QLabel(window);
        windowLabelText->setObjectName(QStringLiteral("windowLabelText"));
        windowLabelText->setGeometry(QRect(27, 6, 61, 20));
        windowSelect = new QWidget(window);
        windowSelect->setObjectName(QStringLiteral("windowSelect"));
        windowSelect->setGeometry(QRect(0, 29, 100, 1));
        info = new QWidget(sidemenu);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(700, 0, 100, 30));
        infoLabel = new QLabel(info);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(5, 5, 16, 20));
        infoLabelText = new QLabel(info);
        infoLabelText->setObjectName(QStringLiteral("infoLabelText"));
        infoLabelText->setGeometry(QRect(27, 6, 61, 20));
        infoSelect = new QWidget(info);
        infoSelect->setObjectName(QStringLiteral("infoSelect"));
        infoSelect->setGeometry(QRect(0, 29, 100, 1));
        config->raise();
        home->raise();
        console->raise();
        docs->raise();
        window->raise();
        info->raise();

        retranslateUi(sidemenu);

        QMetaObject::connectSlotsByName(sidemenu);
    } // setupUi

    void retranslateUi(QWidget *sidemenu)
    {
        sidemenu->setWindowTitle(QApplication::translate("sidemenu", "Form", 0));
        homeLabel->setText(QApplication::translate("sidemenu", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        homeLabelText->setText(QApplication::translate("sidemenu", "<html><head/><body><p><span style=\" color:#ffffff;\">Home</span></p></body></html>", 0));
        configLabel->setText(QString());
        configLabelText->setText(QApplication::translate("sidemenu", "<html><head/><body><p><span style=\" color:#ffffff;\">Config</span></p></body></html>", 0));
        consoleLabel->setText(QApplication::translate("sidemenu", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        consoleLabelText->setText(QApplication::translate("sidemenu", "<html><head/><body><p><span style=\" color:#ffffff;\">Console</span></p></body></html>", 0));
        docsLabel->setText(QApplication::translate("sidemenu", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        docsLabelText->setText(QApplication::translate("sidemenu", "<html><head/><body><p><span style=\" color:#ffffff;\">Docs</span></p></body></html>", 0));
        windowLabel->setText(QApplication::translate("sidemenu", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        windowLabelText->setText(QApplication::translate("sidemenu", "<html><head/><body><p><span style=\" color:#ffffff;\">Window</span></p></body></html>", 0));
        infoLabel->setText(QApplication::translate("sidemenu", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        infoLabelText->setText(QApplication::translate("sidemenu", "<html><head/><body><p><span style=\" color:#ffffff;\">Info</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class sidemenu: public Ui_sidemenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEMENU_H
