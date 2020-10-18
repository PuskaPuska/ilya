/********************************************************************************
** Form generated from reading UI file 'gen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEN_H
#define UI_GEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GenClass)
    {
        if (GenClass->objectName().isEmpty())
            GenClass->setObjectName(QString::fromUtf8("GenClass"));
        GenClass->resize(600, 400);
        menuBar = new QMenuBar(GenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GenClass->setStatusBar(statusBar);

        retranslateUi(GenClass);

        QMetaObject::connectSlotsByName(GenClass);
    } // setupUi

    void retranslateUi(QMainWindow *GenClass)
    {
        GenClass->setWindowTitle(QApplication::translate("GenClass", "Gen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GenClass: public Ui_GenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEN_H
