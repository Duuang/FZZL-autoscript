/********************************************************************************
** Form generated from reading UI file 'FZZLautoscript.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FZZLAUTOSCRIPT_H
#define UI_FZZLAUTOSCRIPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FZZLautosciptClass
{
public:
    QWidget *centralWidget;
    QPushButton *startbutton;
    QPushButton *stopbutton;
    QTextEdit *stageinput;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FZZLautosciptClass)
    {
        if (FZZLautosciptClass->objectName().isEmpty())
            FZZLautosciptClass->setObjectName(QStringLiteral("FZZLautosciptClass"));
        FZZLautosciptClass->resize(600, 400);
        centralWidget = new QWidget(FZZLautosciptClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startbutton = new QPushButton(centralWidget);
        startbutton->setObjectName(QStringLiteral("startbutton"));
        startbutton->setGeometry(QRect(110, 170, 112, 34));
        stopbutton = new QPushButton(centralWidget);
        stopbutton->setObjectName(QStringLiteral("stopbutton"));
        stopbutton->setGeometry(QRect(300, 170, 112, 34));
        stageinput = new QTextEdit(centralWidget);
        stageinput->setObjectName(QStringLiteral("stageinput"));
        stageinput->setGeometry(QRect(130, 80, 271, 41));
        FZZLautosciptClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FZZLautosciptClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 30));
        FZZLautosciptClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FZZLautosciptClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FZZLautosciptClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FZZLautosciptClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FZZLautosciptClass->setStatusBar(statusBar);

        retranslateUi(FZZLautosciptClass);

        QMetaObject::connectSlotsByName(FZZLautosciptClass);
    } // setupUi

    void retranslateUi(QMainWindow *FZZLautosciptClass)
    {
        FZZLautosciptClass->setWindowTitle(QApplication::translate("FZZLautosciptClass", "FZZLautoscipt", Q_NULLPTR));
        startbutton->setText(QApplication::translate("FZZLautosciptClass", "Start", Q_NULLPTR));
        stopbutton->setText(QApplication::translate("FZZLautosciptClass", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FZZLautosciptClass: public Ui_FZZLautosciptClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FZZLAUTOSCRIPT_H
