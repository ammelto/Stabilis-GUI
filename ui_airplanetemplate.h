/********************************************************************************
** Form generated from reading UI file 'airplanetemplate.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRPLANETEMPLATE_H
#define UI_AIRPLANETEMPLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_airplaneTemplate
{
public:
    QLabel *zPIDDetail;
    QLabel *referencesLabel;
    QLabel *yPIDDetail;
    QLabel *bankPitchPhiDetail;
    QLabel *bankPitchThetaDetail;
    QLabel *stallLabel;
    QLabel *kThrottleDetail;
    QLabel *innerLoopLabel;
    QLabel *bankPitchLimit;
    QLabel *referenceOneDetail;
    QLabel *hLongitudeDetail;
    QLabel *referenceTwoDetail;
    QLabel *referenceThreeDetail;
    QLabel *bankPitchThtrottleDetail;
    QLabel *xyLatitudeDetail;
    QLabel *outerLoopLabel;
    QLabel *xPIDDetail;
    QLabel *stallDetail;
    QWidget *pathValue;
    QWidget *orbitValue;
    QWidget *infValue;
    QWidget *throttleP;
    QWidget *throttleI;
    QWidget *throttleD;
    QWidget *longitudeD;
    QWidget *longitudeI;
    QWidget *longitudeP;
    QWidget *lattitudeD;
    QWidget *lattitudeP;
    QWidget *lattitudeI;
    QWidget *zI;
    QWidget *xP;
    QWidget *zP;
    QWidget *zD;
    QWidget *xD;
    QWidget *xI;
    QWidget *yI;
    QWidget *yP;
    QWidget *yD;
    QWidget *phiValue;
    QWidget *thetaValue;
    QWidget *throttleValue;
    QWidget *stallValue;

    void setupUi(QWidget *airplaneTemplate)
    {
        if (airplaneTemplate->objectName().isEmpty())
            airplaneTemplate->setObjectName(QStringLiteral("airplaneTemplate"));
        airplaneTemplate->resize(308, 468);
        zPIDDetail = new QLabel(airplaneTemplate);
        zPIDDetail->setObjectName(QStringLiteral("zPIDDetail"));
        zPIDDetail->setGeometry(QRect(1, 196, 200, 15));
        zPIDDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        referencesLabel = new QLabel(airplaneTemplate);
        referencesLabel->setObjectName(QStringLiteral("referencesLabel"));
        referencesLabel->setGeometry(QRect(1, 312, 251, 22));
        referencesLabel->setStyleSheet(QStringLiteral(""));
        yPIDDetail = new QLabel(airplaneTemplate);
        yPIDDetail->setObjectName(QStringLiteral("yPIDDetail"));
        yPIDDetail->setGeometry(QRect(1, 176, 200, 15));
        yPIDDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        bankPitchPhiDetail = new QLabel(airplaneTemplate);
        bankPitchPhiDetail->setObjectName(QStringLiteral("bankPitchPhiDetail"));
        bankPitchPhiDetail->setGeometry(QRect(1, 68, 200, 15));
        bankPitchPhiDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        bankPitchThetaDetail = new QLabel(airplaneTemplate);
        bankPitchThetaDetail->setObjectName(QStringLiteral("bankPitchThetaDetail"));
        bankPitchThetaDetail->setGeometry(QRect(1, 88, 200, 15));
        bankPitchThetaDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        stallLabel = new QLabel(airplaneTemplate);
        stallLabel->setObjectName(QStringLiteral("stallLabel"));
        stallLabel->setGeometry(QRect(0, 0, 251, 22));
        stallLabel->setStyleSheet(QStringLiteral(""));
        kThrottleDetail = new QLabel(airplaneTemplate);
        kThrottleDetail->setObjectName(QStringLiteral("kThrottleDetail"));
        kThrottleDetail->setGeometry(QRect(1, 284, 180, 15));
        kThrottleDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        innerLoopLabel = new QLabel(airplaneTemplate);
        innerLoopLabel->setObjectName(QStringLiteral("innerLoopLabel"));
        innerLoopLabel->setGeometry(QRect(1, 136, 251, 22));
        innerLoopLabel->setStyleSheet(QStringLiteral(""));
        bankPitchLimit = new QLabel(airplaneTemplate);
        bankPitchLimit->setObjectName(QStringLiteral("bankPitchLimit"));
        bankPitchLimit->setGeometry(QRect(1, 48, 251, 22));
        bankPitchLimit->setStyleSheet(QStringLiteral(""));
        referenceOneDetail = new QLabel(airplaneTemplate);
        referenceOneDetail->setObjectName(QStringLiteral("referenceOneDetail"));
        referenceOneDetail->setGeometry(QRect(1, 332, 200, 15));
        referenceOneDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        hLongitudeDetail = new QLabel(airplaneTemplate);
        hLongitudeDetail->setObjectName(QStringLiteral("hLongitudeDetail"));
        hLongitudeDetail->setGeometry(QRect(1, 264, 200, 15));
        hLongitudeDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        referenceTwoDetail = new QLabel(airplaneTemplate);
        referenceTwoDetail->setObjectName(QStringLiteral("referenceTwoDetail"));
        referenceTwoDetail->setGeometry(QRect(1, 352, 200, 15));
        referenceTwoDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        referenceThreeDetail = new QLabel(airplaneTemplate);
        referenceThreeDetail->setObjectName(QStringLiteral("referenceThreeDetail"));
        referenceThreeDetail->setGeometry(QRect(1, 372, 200, 15));
        referenceThreeDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        bankPitchThtrottleDetail = new QLabel(airplaneTemplate);
        bankPitchThtrottleDetail->setObjectName(QStringLiteral("bankPitchThtrottleDetail"));
        bankPitchThtrottleDetail->setGeometry(QRect(1, 108, 200, 15));
        bankPitchThtrottleDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        xyLatitudeDetail = new QLabel(airplaneTemplate);
        xyLatitudeDetail->setObjectName(QStringLiteral("xyLatitudeDetail"));
        xyLatitudeDetail->setGeometry(QRect(1, 244, 200, 15));
        xyLatitudeDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        outerLoopLabel = new QLabel(airplaneTemplate);
        outerLoopLabel->setObjectName(QStringLiteral("outerLoopLabel"));
        outerLoopLabel->setGeometry(QRect(1, 224, 251, 22));
        outerLoopLabel->setStyleSheet(QStringLiteral(""));
        xPIDDetail = new QLabel(airplaneTemplate);
        xPIDDetail->setObjectName(QStringLiteral("xPIDDetail"));
        xPIDDetail->setGeometry(QRect(1, 156, 200, 15));
        xPIDDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        stallDetail = new QLabel(airplaneTemplate);
        stallDetail->setObjectName(QStringLiteral("stallDetail"));
        stallDetail->setGeometry(QRect(0, 20, 200, 15));
        stallDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        pathValue = new QWidget(airplaneTemplate);
        pathValue->setObjectName(QStringLiteral("pathValue"));
        pathValue->setGeometry(QRect(200, 332, 108, 15));
        orbitValue = new QWidget(airplaneTemplate);
        orbitValue->setObjectName(QStringLiteral("orbitValue"));
        orbitValue->setGeometry(QRect(200, 372, 108, 15));
        infValue = new QWidget(airplaneTemplate);
        infValue->setObjectName(QStringLiteral("infValue"));
        infValue->setGeometry(QRect(200, 352, 108, 15));
        throttleP = new QWidget(airplaneTemplate);
        throttleP->setObjectName(QStringLiteral("throttleP"));
        throttleP->setGeometry(QRect(200, 284, 36, 15));
        throttleI = new QWidget(airplaneTemplate);
        throttleI->setObjectName(QStringLiteral("throttleI"));
        throttleI->setGeometry(QRect(234, 284, 36, 15));
        throttleD = new QWidget(airplaneTemplate);
        throttleD->setObjectName(QStringLiteral("throttleD"));
        throttleD->setGeometry(QRect(268, 284, 36, 15));
        longitudeD = new QWidget(airplaneTemplate);
        longitudeD->setObjectName(QStringLiteral("longitudeD"));
        longitudeD->setGeometry(QRect(268, 264, 36, 15));
        longitudeI = new QWidget(airplaneTemplate);
        longitudeI->setObjectName(QStringLiteral("longitudeI"));
        longitudeI->setGeometry(QRect(234, 264, 36, 15));
        longitudeP = new QWidget(airplaneTemplate);
        longitudeP->setObjectName(QStringLiteral("longitudeP"));
        longitudeP->setGeometry(QRect(200, 264, 36, 15));
        lattitudeD = new QWidget(airplaneTemplate);
        lattitudeD->setObjectName(QStringLiteral("lattitudeD"));
        lattitudeD->setGeometry(QRect(268, 244, 36, 15));
        lattitudeP = new QWidget(airplaneTemplate);
        lattitudeP->setObjectName(QStringLiteral("lattitudeP"));
        lattitudeP->setGeometry(QRect(200, 244, 36, 15));
        lattitudeI = new QWidget(airplaneTemplate);
        lattitudeI->setObjectName(QStringLiteral("lattitudeI"));
        lattitudeI->setGeometry(QRect(234, 244, 36, 15));
        zI = new QWidget(airplaneTemplate);
        zI->setObjectName(QStringLiteral("zI"));
        zI->setGeometry(QRect(234, 196, 36, 15));
        xP = new QWidget(airplaneTemplate);
        xP->setObjectName(QStringLiteral("xP"));
        xP->setGeometry(QRect(200, 160, 36, 15));
        zP = new QWidget(airplaneTemplate);
        zP->setObjectName(QStringLiteral("zP"));
        zP->setGeometry(QRect(200, 196, 36, 15));
        zD = new QWidget(airplaneTemplate);
        zD->setObjectName(QStringLiteral("zD"));
        zD->setGeometry(QRect(268, 196, 36, 15));
        xD = new QWidget(airplaneTemplate);
        xD->setObjectName(QStringLiteral("xD"));
        xD->setGeometry(QRect(268, 160, 36, 15));
        xI = new QWidget(airplaneTemplate);
        xI->setObjectName(QStringLiteral("xI"));
        xI->setGeometry(QRect(234, 160, 36, 15));
        yI = new QWidget(airplaneTemplate);
        yI->setObjectName(QStringLiteral("yI"));
        yI->setGeometry(QRect(234, 180, 36, 15));
        yP = new QWidget(airplaneTemplate);
        yP->setObjectName(QStringLiteral("yP"));
        yP->setGeometry(QRect(200, 180, 36, 15));
        yD = new QWidget(airplaneTemplate);
        yD->setObjectName(QStringLiteral("yD"));
        yD->setGeometry(QRect(268, 180, 36, 15));
        phiValue = new QWidget(airplaneTemplate);
        phiValue->setObjectName(QStringLiteral("phiValue"));
        phiValue->setGeometry(QRect(200, 68, 108, 15));
        thetaValue = new QWidget(airplaneTemplate);
        thetaValue->setObjectName(QStringLiteral("thetaValue"));
        thetaValue->setGeometry(QRect(200, 88, 108, 15));
        throttleValue = new QWidget(airplaneTemplate);
        throttleValue->setObjectName(QStringLiteral("throttleValue"));
        throttleValue->setGeometry(QRect(200, 108, 108, 15));
        stallValue = new QWidget(airplaneTemplate);
        stallValue->setObjectName(QStringLiteral("stallValue"));
        stallValue->setGeometry(QRect(200, 20, 108, 15));

        retranslateUi(airplaneTemplate);

        QMetaObject::connectSlotsByName(airplaneTemplate);
    } // setupUi

    void retranslateUi(QWidget *airplaneTemplate)
    {
        airplaneTemplate->setWindowTitle(QApplication::translate("airplaneTemplate", "Form", 0));
        zPIDDetail->setText(QApplication::translate("airplaneTemplate", "Z K(P,I,D)", 0));
        referencesLabel->setText(QApplication::translate("airplaneTemplate", "Vehicle references", 0));
        yPIDDetail->setText(QApplication::translate("airplaneTemplate", "Y K(P,I,D)", 0));
        bankPitchPhiDetail->setText(QApplication::translate("airplaneTemplate", "Phi limit", 0));
        bankPitchThetaDetail->setText(QApplication::translate("airplaneTemplate", "Theta limit", 0));
        stallLabel->setText(QApplication::translate("airplaneTemplate", "Airplane stall", 0));
        kThrottleDetail->setText(QApplication::translate("airplaneTemplate", "Throttle H(P,I,D)", 0));
        innerLoopLabel->setText(QApplication::translate("airplaneTemplate", "Inner loop alttitude gains", 0));
        bankPitchLimit->setText(QApplication::translate("airplaneTemplate", "Bank angle and pitch angle", 0));
        referenceOneDetail->setText(QApplication::translate("airplaneTemplate", "Path", 0));
        hLongitudeDetail->setText(QApplication::translate("airplaneTemplate", "Longitude H(P,I,D)", 0));
        referenceTwoDetail->setText(QApplication::translate("airplaneTemplate", "Inf", 0));
        referenceThreeDetail->setText(QApplication::translate("airplaneTemplate", "Orbit", 0));
        bankPitchThtrottleDetail->setText(QApplication::translate("airplaneTemplate", "Throttle limit", 0));
        xyLatitudeDetail->setText(QApplication::translate("airplaneTemplate", "Latitude XY(P,I,D)", 0));
        outerLoopLabel->setText(QApplication::translate("airplaneTemplate", "Outer loop gains", 0));
        xPIDDetail->setText(QApplication::translate("airplaneTemplate", "X K(P,I,D)", 0));
        stallDetail->setText(QApplication::translate("airplaneTemplate", "Stall value for simulation", 0));
    } // retranslateUi

};

namespace Ui {
    class airplaneTemplate: public Ui_airplaneTemplate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRPLANETEMPLATE_H
