/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *mainWidget;
    QWidget *titleBar;
    QWidget *menu;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFrame *displayArea;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(832, 732);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        titleBar = new QWidget(mainWidget);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        titleBar->setGeometry(QRect(18, 18, 800, 50));
        menu = new QWidget(titleBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(0, 20, 800, 30));
        scrollArea = new QScrollArea(mainWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(18, 68, 800, 634));
        scrollArea->setStyleSheet(QLatin1String("QScrollBar:vertical {               \n"
"    border: 0px;\n"
"    background: #EEEEEE;\n"
"    width: 4px; \n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	background: #BDBDBD;\n"
"	border-radius: 2px;\n"
"	min-height: 0px;\n"
"	margin: 3px 0px 3px 0px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical{\n"
"	background: #EEEEEE;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical{\n"
"	background: #EEEEEE;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 632));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        displayArea = new QFrame(scrollAreaWidgetContents);
        displayArea->setObjectName(QStringLiteral("displayArea"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayArea->sizePolicy().hasHeightForWidth());
        displayArea->setSizePolicy(sizePolicy);
        displayArea->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(displayArea);

        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea->raise();
        titleBar->raise();

        verticalLayout_2->addWidget(mainWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
