/********************************************************************************
** Form generated from reading UI file 'QtGis.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGIS_H
#define UI_QTGIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGisClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGisClass)
    {
        if (QtGisClass->objectName().isEmpty())
            QtGisClass->setObjectName(QString::fromUtf8("QtGisClass"));
        QtGisClass->resize(600, 400);
        menuBar = new QMenuBar(QtGisClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtGisClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGisClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGisClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGisClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtGisClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGisClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGisClass->setStatusBar(statusBar);

        retranslateUi(QtGisClass);

        QMetaObject::connectSlotsByName(QtGisClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGisClass)
    {
        QtGisClass->setWindowTitle(QCoreApplication::translate("QtGisClass", "QtGis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGisClass: public Ui_QtGisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGIS_H
