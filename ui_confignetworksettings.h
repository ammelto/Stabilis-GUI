/********************************************************************************
** Form generated from reading UI file 'confignetworksettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGNETWORKSETTINGS_H
#define UI_CONFIGNETWORKSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confignetworksettings
{
public:
    QLabel *windowLabel;
    QLabel *addressLabel;
    QLabel *addressDetail;
    QWidget *addressValue;
    QLabel *portDetail;
    QWidget *portValue;
    QWidget *connectButton;
    QLabel *userName;
    QLabel *userLabel;
    QLabel *userPassword;
    QWidget *userPasswordValue;
    QWidget *userNameValue;
    QLabel *connectionLabel;

    void setupUi(QWidget *confignetworksettings)
    {
        if (confignetworksettings->objectName().isEmpty())
            confignetworksettings->setObjectName(QStringLiteral("confignetworksettings"));
        confignetworksettings->resize(355, 294);
        windowLabel = new QLabel(confignetworksettings);
        windowLabel->setObjectName(QStringLiteral("windowLabel"));
        windowLabel->setGeometry(QRect(5, 5, 200, 20));
        windowLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #616161\n"
"}"));
        addressLabel = new QLabel(confignetworksettings);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));
        addressLabel->setGeometry(QRect(15, 30, 251, 22));
        addressLabel->setStyleSheet(QStringLiteral(""));
        addressDetail = new QLabel(confignetworksettings);
        addressDetail->setObjectName(QStringLiteral("addressDetail"));
        addressDetail->setGeometry(QRect(15, 50, 220, 15));
        addressDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        addressValue = new QWidget(confignetworksettings);
        addressValue->setObjectName(QStringLiteral("addressValue"));
        addressValue->setGeometry(QRect(235, 50, 105, 15));
        portDetail = new QLabel(confignetworksettings);
        portDetail->setObjectName(QStringLiteral("portDetail"));
        portDetail->setGeometry(QRect(15, 70, 220, 15));
        portDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        portValue = new QWidget(confignetworksettings);
        portValue->setObjectName(QStringLiteral("portValue"));
        portValue->setGeometry(QRect(235, 70, 105, 15));
        connectButton = new QWidget(confignetworksettings);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(0, 264, 355, 30));
        userName = new QLabel(confignetworksettings);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(15, 118, 220, 15));
        userName->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        userLabel = new QLabel(confignetworksettings);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(15, 98, 251, 22));
        userLabel->setStyleSheet(QStringLiteral(""));
        userPassword = new QLabel(confignetworksettings);
        userPassword->setObjectName(QStringLiteral("userPassword"));
        userPassword->setGeometry(QRect(15, 138, 220, 15));
        userPassword->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        userPasswordValue = new QWidget(confignetworksettings);
        userPasswordValue->setObjectName(QStringLiteral("userPasswordValue"));
        userPasswordValue->setGeometry(QRect(235, 138, 105, 15));
        userNameValue = new QWidget(confignetworksettings);
        userNameValue->setObjectName(QStringLiteral("userNameValue"));
        userNameValue->setGeometry(QRect(235, 118, 105, 15));
        connectionLabel = new QLabel(confignetworksettings);
        connectionLabel->setObjectName(QStringLiteral("connectionLabel"));
        connectionLabel->setGeometry(QRect(255, 5, 100, 20));
        connectionLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #616161\n"
"}"));

        retranslateUi(confignetworksettings);

        QMetaObject::connectSlotsByName(confignetworksettings);
    } // setupUi

    void retranslateUi(QWidget *confignetworksettings)
    {
        confignetworksettings->setWindowTitle(QApplication::translate("confignetworksettings", "Form", 0));
        windowLabel->setText(QApplication::translate("confignetworksettings", "Network", 0));
        addressLabel->setText(QApplication::translate("confignetworksettings", "Host name", 0));
        addressDetail->setText(QApplication::translate("confignetworksettings", "Destination address of Stabilis", 0));
        portDetail->setText(QApplication::translate("confignetworksettings", "Destination port", 0));
        userName->setText(QApplication::translate("confignetworksettings", "Username", 0));
        userLabel->setText(QApplication::translate("confignetworksettings", "Login", 0));
        userPassword->setText(QApplication::translate("confignetworksettings", "Password", 0));
        connectionLabel->setText(QApplication::translate("confignetworksettings", "Disconnected", 0));
    } // retranslateUi

};

namespace Ui {
    class confignetworksettings: public Ui_confignetworksettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGNETWORKSETTINGS_H
