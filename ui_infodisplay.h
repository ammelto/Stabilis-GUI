/********************************************************************************
** Form generated from reading UI file 'infodisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODISPLAY_H
#define UI_INFODISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infodisplay
{
public:
    QWidget *stabilisLegal;
    QWidget *qtLegal;
    QWidget *iconsLegal;

    void setupUi(QWidget *infodisplay)
    {
        if (infodisplay->objectName().isEmpty())
            infodisplay->setObjectName(QStringLiteral("infodisplay"));
        infodisplay->resize(800, 634);
        stabilisLegal = new QWidget(infodisplay);
        stabilisLegal->setObjectName(QStringLiteral("stabilisLegal"));
        stabilisLegal->setGeometry(QRect(48, 28, 704, 150));
        qtLegal = new QWidget(infodisplay);
        qtLegal->setObjectName(QStringLiteral("qtLegal"));
        qtLegal->setGeometry(QRect(48, 206, 704, 150));
        iconsLegal = new QWidget(infodisplay);
        iconsLegal->setObjectName(QStringLiteral("iconsLegal"));
        iconsLegal->setGeometry(QRect(48, 384, 704, 150));

        retranslateUi(infodisplay);

        QMetaObject::connectSlotsByName(infodisplay);
    } // setupUi

    void retranslateUi(QWidget *infodisplay)
    {
        infodisplay->setWindowTitle(QApplication::translate("infodisplay", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class infodisplay: public Ui_infodisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODISPLAY_H
