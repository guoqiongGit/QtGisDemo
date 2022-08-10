/********************************************************************************
** Form generated from reading UI file 'qgsdashspacewidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSDASHSPACEWIDGETBASE_H
#define UI_QGSDASHSPACEWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include "qgspanelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsDashSpaceWidgetBase
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *mAddButton;
    QPushButton *mRemoveButton;
    QSpacerItem *verticalSpacer;
    QTreeWidget *mDashSpaceTreeWidget;

    void setupUi(QgsPanelWidget *QgsDashSpaceWidgetBase)
    {
        if (QgsDashSpaceWidgetBase->objectName().isEmpty())
            QgsDashSpaceWidgetBase->setObjectName(QString::fromUtf8("QgsDashSpaceWidgetBase"));
        QgsDashSpaceWidgetBase->resize(194, 277);
        gridLayout = new QGridLayout(QgsDashSpaceWidgetBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mAddButton = new QPushButton(QgsDashSpaceWidgetBase);
        mAddButton->setObjectName(QString::fromUtf8("mAddButton"));

        verticalLayout->addWidget(mAddButton);

        mRemoveButton = new QPushButton(QgsDashSpaceWidgetBase);
        mRemoveButton->setObjectName(QString::fromUtf8("mRemoveButton"));

        verticalLayout->addWidget(mRemoveButton);

        verticalSpacer = new QSpacerItem(20, 245, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        mDashSpaceTreeWidget = new QTreeWidget(QgsDashSpaceWidgetBase);
        mDashSpaceTreeWidget->setObjectName(QString::fromUtf8("mDashSpaceTreeWidget"));
        mDashSpaceTreeWidget->setColumnCount(2);

        gridLayout->addWidget(mDashSpaceTreeWidget, 0, 0, 1, 1);


        retranslateUi(QgsDashSpaceWidgetBase);

        QMetaObject::connectSlotsByName(QgsDashSpaceWidgetBase);
    } // setupUi

    void retranslateUi(QgsPanelWidget *QgsDashSpaceWidgetBase)
    {
        QgsDashSpaceWidgetBase->setWindowTitle(QCoreApplication::translate("QgsDashSpaceWidgetBase", "Dash Space Pattern", nullptr));
        mAddButton->setText(QString());
        mRemoveButton->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = mDashSpaceTreeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("QgsDashSpaceWidgetBase", "Space", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("QgsDashSpaceWidgetBase", "Dash", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsDashSpaceWidgetBase: public Ui_QgsDashSpaceWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSDASHSPACEWIDGETBASE_H
