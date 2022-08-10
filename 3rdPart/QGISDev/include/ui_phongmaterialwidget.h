/********************************************************************************
** Form generated from reading UI file 'phongmaterialwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONGMATERIALWIDGET_H
#define UI_PHONGMATERIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "qgscolorbutton.h"
#include "qgsdoublespinbox.h"
#include "qgspropertyoverridebutton.h"

QT_BEGIN_NAMESPACE

class Ui_PhongMaterialWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lblShininess;
    QgsColorButton *btnSpecular;
    QgsColorButton *btnDiffuse;
    QLabel *lblSpecular;
    QLabel *lblDiffuse;
    QgsDoubleSpinBox *spinShininess;
    QLabel *lblAmbient;
    QgsColorButton *btnAmbient;
    QgsPropertyOverrideButton *mDiffuseDataDefinedButton;
    QgsPropertyOverrideButton *mAmbientDataDefinedButton;
    QgsPropertyOverrideButton *mSpecularDataDefinedButton;

    void setupUi(QWidget *PhongMaterialWidget)
    {
        if (PhongMaterialWidget->objectName().isEmpty())
            PhongMaterialWidget->setObjectName(QString::fromUtf8("PhongMaterialWidget"));
        PhongMaterialWidget->resize(394, 186);
        PhongMaterialWidget->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(PhongMaterialWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblShininess = new QLabel(PhongMaterialWidget);
        lblShininess->setObjectName(QString::fromUtf8("lblShininess"));

        gridLayout->addWidget(lblShininess, 3, 0, 1, 1);

        btnSpecular = new QgsColorButton(PhongMaterialWidget);
        btnSpecular->setObjectName(QString::fromUtf8("btnSpecular"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSpecular->sizePolicy().hasHeightForWidth());
        btnSpecular->setSizePolicy(sizePolicy);
        btnSpecular->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnSpecular, 2, 1, 1, 1);

        btnDiffuse = new QgsColorButton(PhongMaterialWidget);
        btnDiffuse->setObjectName(QString::fromUtf8("btnDiffuse"));
        sizePolicy.setHeightForWidth(btnDiffuse->sizePolicy().hasHeightForWidth());
        btnDiffuse->setSizePolicy(sizePolicy);
        btnDiffuse->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnDiffuse, 0, 1, 1, 1);

        lblSpecular = new QLabel(PhongMaterialWidget);
        lblSpecular->setObjectName(QString::fromUtf8("lblSpecular"));

        gridLayout->addWidget(lblSpecular, 2, 0, 1, 1);

        lblDiffuse = new QLabel(PhongMaterialWidget);
        lblDiffuse->setObjectName(QString::fromUtf8("lblDiffuse"));

        gridLayout->addWidget(lblDiffuse, 0, 0, 1, 1);

        spinShininess = new QgsDoubleSpinBox(PhongMaterialWidget);
        spinShininess->setObjectName(QString::fromUtf8("spinShininess"));
        spinShininess->setMaximum(1000.000000000000000);

        gridLayout->addWidget(spinShininess, 3, 1, 1, 1);

        lblAmbient = new QLabel(PhongMaterialWidget);
        lblAmbient->setObjectName(QString::fromUtf8("lblAmbient"));

        gridLayout->addWidget(lblAmbient, 1, 0, 1, 1);

        btnAmbient = new QgsColorButton(PhongMaterialWidget);
        btnAmbient->setObjectName(QString::fromUtf8("btnAmbient"));
        sizePolicy.setHeightForWidth(btnAmbient->sizePolicy().hasHeightForWidth());
        btnAmbient->setSizePolicy(sizePolicy);
        btnAmbient->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnAmbient, 1, 1, 1, 1);

        mDiffuseDataDefinedButton = new QgsPropertyOverrideButton(PhongMaterialWidget);
        mDiffuseDataDefinedButton->setObjectName(QString::fromUtf8("mDiffuseDataDefinedButton"));

        gridLayout->addWidget(mDiffuseDataDefinedButton, 0, 2, 1, 1);

        mAmbientDataDefinedButton = new QgsPropertyOverrideButton(PhongMaterialWidget);
        mAmbientDataDefinedButton->setObjectName(QString::fromUtf8("mAmbientDataDefinedButton"));

        gridLayout->addWidget(mAmbientDataDefinedButton, 1, 2, 1, 1);

        mSpecularDataDefinedButton = new QgsPropertyOverrideButton(PhongMaterialWidget);
        mSpecularDataDefinedButton->setObjectName(QString::fromUtf8("mSpecularDataDefinedButton"));

        gridLayout->addWidget(mSpecularDataDefinedButton, 2, 2, 1, 1);

        QWidget::setTabOrder(btnDiffuse, mDiffuseDataDefinedButton);
        QWidget::setTabOrder(mDiffuseDataDefinedButton, btnAmbient);
        QWidget::setTabOrder(btnAmbient, mAmbientDataDefinedButton);
        QWidget::setTabOrder(mAmbientDataDefinedButton, btnSpecular);
        QWidget::setTabOrder(btnSpecular, mSpecularDataDefinedButton);
        QWidget::setTabOrder(mSpecularDataDefinedButton, spinShininess);

        retranslateUi(PhongMaterialWidget);

        QMetaObject::connectSlotsByName(PhongMaterialWidget);
    } // setupUi

    void retranslateUi(QWidget *PhongMaterialWidget)
    {
#if QT_CONFIG(tooltip)
        lblShininess->setToolTip(QCoreApplication::translate("PhongMaterialWidget", "How shiny smooth surfaces are.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblShininess->setText(QCoreApplication::translate("PhongMaterialWidget", "Shininess", nullptr));
#if QT_CONFIG(tooltip)
        lblSpecular->setToolTip(QCoreApplication::translate("PhongMaterialWidget", "Color of light reflecting from smooth surfaces.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblSpecular->setText(QCoreApplication::translate("PhongMaterialWidget", "Specular", nullptr));
#if QT_CONFIG(tooltip)
        lblDiffuse->setToolTip(QCoreApplication::translate("PhongMaterialWidget", "Color of light reflected from rough surfaces.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblDiffuse->setText(QCoreApplication::translate("PhongMaterialWidget", "Diffuse", nullptr));
#if QT_CONFIG(tooltip)
        lblAmbient->setToolTip(QCoreApplication::translate("PhongMaterialWidget", "Color of light that is scattered around the entire scene.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblAmbient->setText(QCoreApplication::translate("PhongMaterialWidget", "Ambient", nullptr));
        mDiffuseDataDefinedButton->setText(QCoreApplication::translate("PhongMaterialWidget", "...", nullptr));
        mAmbientDataDefinedButton->setText(QCoreApplication::translate("PhongMaterialWidget", "...", nullptr));
        mSpecularDataDefinedButton->setText(QCoreApplication::translate("PhongMaterialWidget", "...", nullptr));
        (void)PhongMaterialWidget;
    } // retranslateUi

};

namespace Ui {
    class PhongMaterialWidget: public Ui_PhongMaterialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONGMATERIALWIDGET_H
