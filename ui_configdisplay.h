/********************************************************************************
** Form generated from reading UI file 'configdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDISPLAY_H
#define UI_CONFIGDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configdisplay
{
public:
    QWidget *generalSettings;
    QWidget *networkSettings;
    QWidget *vehicleSettings;
    QWidget *controllerSettings;

    void setupUi(QWidget *configdisplay)
    {
        if (configdisplay->objectName().isEmpty())
            configdisplay->setObjectName(QStringLiteral("configdisplay"));
        configdisplay->resize(800, 900);
        generalSettings = new QWidget(configdisplay);
        generalSettings->setObjectName(QStringLiteral("generalSettings"));
        generalSettings->setGeometry(QRect(48, 28, 355, 220));
        networkSettings = new QWidget(configdisplay);
        networkSettings->setObjectName(QStringLiteral("networkSettings"));
        networkSettings->setGeometry(QRect(48, 262, 355, 294));
        vehicleSettings = new QWidget(configdisplay);
        vehicleSettings->setObjectName(QStringLiteral("vehicleSettings"));
        vehicleSettings->setGeometry(QRect(414, 28, 338, 528));
        controllerSettings = new QWidget(configdisplay);
        controllerSettings->setObjectName(QStringLiteral("controllerSettings"));
        controllerSettings->setGeometry(QRect(48, 570, 704, 300));

        retranslateUi(configdisplay);

        QMetaObject::connectSlotsByName(configdisplay);
    } // setupUi

    void retranslateUi(QWidget *configdisplay)
    {
        configdisplay->setWindowTitle(QApplication::translate("configdisplay", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class configdisplay: public Ui_configdisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDISPLAY_H
