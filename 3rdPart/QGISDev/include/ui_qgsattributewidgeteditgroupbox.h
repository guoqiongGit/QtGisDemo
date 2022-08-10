/********************************************************************************
** Form generated from reading UI file 'qgsattributewidgeteditgroupbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSATTRIBUTEWIDGETEDITGROUPBOX_H
#define UI_QGSATTRIBUTEWIDGETEDITGROUPBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include "qgscollapsiblegroupbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAttributeWidgetEditGroupBox
{
public:
    QGridLayout *gridLayout;
    QCheckBox *mShowLabelCheckBox;
    QgsCollapsibleGroupBox *mWidgetSpecificConfigGroupBox;

    void setupUi(QgsCollapsibleGroupBox *QgsAttributeWidgetEditGroupBox)
    {
        if (QgsAttributeWidgetEditGroupBox->objectName().isEmpty())
            QgsAttributeWidgetEditGroupBox->setObjectName(QString::fromUtf8("QgsAttributeWidgetEditGroupBox"));
        QgsAttributeWidgetEditGroupBox->resize(283, 278);
        gridLayout = new QGridLayout(QgsAttributeWidgetEditGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mShowLabelCheckBox = new QCheckBox(QgsAttributeWidgetEditGroupBox);
        mShowLabelCheckBox->setObjectName(QString::fromUtf8("mShowLabelCheckBox"));

        gridLayout->addWidget(mShowLabelCheckBox, 2, 0, 1, 1);

        mWidgetSpecificConfigGroupBox = new QgsCollapsibleGroupBox(QgsAttributeWidgetEditGroupBox);
        mWidgetSpecificConfigGroupBox->setObjectName(QString::fromUtf8("mWidgetSpecificConfigGroupBox"));

        gridLayout->addWidget(mWidgetSpecificConfigGroupBox, 3, 0, 1, 1);


        retranslateUi(QgsAttributeWidgetEditGroupBox);

        QMetaObject::connectSlotsByName(QgsAttributeWidgetEditGroupBox);
    } // setupUi

    void retranslateUi(QgsCollapsibleGroupBox *QgsAttributeWidgetEditGroupBox)
    {
        QgsAttributeWidgetEditGroupBox->setWindowTitle(QCoreApplication::translate("QgsAttributeWidgetEditGroupBox", "QgsCollapsibleGroupBox", nullptr));
        QgsAttributeWidgetEditGroupBox->setTitle(QCoreApplication::translate("QgsAttributeWidgetEditGroupBox", "Widget Display", nullptr));
        mShowLabelCheckBox->setText(QCoreApplication::translate("QgsAttributeWidgetEditGroupBox", "Show label", nullptr));
        mWidgetSpecificConfigGroupBox->setTitle(QCoreApplication::translate("QgsAttributeWidgetEditGroupBox", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsAttributeWidgetEditGroupBox: public Ui_QgsAttributeWidgetEditGroupBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSATTRIBUTEWIDGETEDITGROUPBOX_H
