/********************************************************************************
** Form generated from reading UI file 'widget_linepatternfill.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LINEPATTERNFILL_H
#define UI_WIDGET_LINEPATTERNFILL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qgsdoublespinbox.h"
#include "qgspropertyoverridebutton.h"
#include "qgsunitselectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetLinePatternFill
{
public:
    QGridLayout *gridLayout;
    QLabel *mRotationLabel;
    QgsPropertyOverrideButton *mAngleDDBtn;
    QLabel *mDistanceLabel;
    QHBoxLayout *horizontalLayout;
    QgsDoubleSpinBox *mDistanceSpinBox;
    QgsUnitSelectionWidget *mDistanceUnitWidget;
    QLabel *mOffsetLabel;
    QHBoxLayout *horizontalLayout_4;
    QgsDoubleSpinBox *mOffsetSpinBox;
    QgsUnitSelectionWidget *mOffsetUnitWidget;
    QgsPropertyOverrideButton *mDistanceDDBtn;
    QgsDoubleSpinBox *mAngleSpinBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetLinePatternFill)
    {
        if (WidgetLinePatternFill->objectName().isEmpty())
            WidgetLinePatternFill->setObjectName(QString::fromUtf8("WidgetLinePatternFill"));
        WidgetLinePatternFill->resize(327, 161);
        WidgetLinePatternFill->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(WidgetLinePatternFill);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mRotationLabel = new QLabel(WidgetLinePatternFill);
        mRotationLabel->setObjectName(QString::fromUtf8("mRotationLabel"));

        gridLayout->addWidget(mRotationLabel, 0, 0, 1, 1);

        mAngleDDBtn = new QgsPropertyOverrideButton(WidgetLinePatternFill);
        mAngleDDBtn->setObjectName(QString::fromUtf8("mAngleDDBtn"));

        gridLayout->addWidget(mAngleDDBtn, 0, 3, 1, 1);

        mDistanceLabel = new QLabel(WidgetLinePatternFill);
        mDistanceLabel->setObjectName(QString::fromUtf8("mDistanceLabel"));

        gridLayout->addWidget(mDistanceLabel, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mDistanceSpinBox = new QgsDoubleSpinBox(WidgetLinePatternFill);
        mDistanceSpinBox->setObjectName(QString::fromUtf8("mDistanceSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mDistanceSpinBox->sizePolicy().hasHeightForWidth());
        mDistanceSpinBox->setSizePolicy(sizePolicy);
        mDistanceSpinBox->setDecimals(6);
        mDistanceSpinBox->setMaximum(999999999.000000000000000);
        mDistanceSpinBox->setSingleStep(0.200000000000000);
        mDistanceSpinBox->setProperty("showClearButton", QVariant(false));

        horizontalLayout->addWidget(mDistanceSpinBox);

        mDistanceUnitWidget = new QgsUnitSelectionWidget(WidgetLinePatternFill);
        mDistanceUnitWidget->setObjectName(QString::fromUtf8("mDistanceUnitWidget"));
        mDistanceUnitWidget->setMinimumSize(QSize(0, 0));
        mDistanceUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(mDistanceUnitWidget);


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 1);

        mOffsetLabel = new QLabel(WidgetLinePatternFill);
        mOffsetLabel->setObjectName(QString::fromUtf8("mOffsetLabel"));

        gridLayout->addWidget(mOffsetLabel, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mOffsetSpinBox = new QgsDoubleSpinBox(WidgetLinePatternFill);
        mOffsetSpinBox->setObjectName(QString::fromUtf8("mOffsetSpinBox"));
        sizePolicy.setHeightForWidth(mOffsetSpinBox->sizePolicy().hasHeightForWidth());
        mOffsetSpinBox->setSizePolicy(sizePolicy);
        mOffsetSpinBox->setDecimals(6);
        mOffsetSpinBox->setMinimum(-999999999.000000000000000);
        mOffsetSpinBox->setMaximum(999999999.000000000000000);
        mOffsetSpinBox->setSingleStep(0.200000000000000);
        mOffsetSpinBox->setProperty("showClearButton", QVariant(true));

        horizontalLayout_4->addWidget(mOffsetSpinBox);

        mOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetLinePatternFill);
        mOffsetUnitWidget->setObjectName(QString::fromUtf8("mOffsetUnitWidget"));
        mOffsetUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_4->addWidget(mOffsetUnitWidget);


        gridLayout->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        mDistanceDDBtn = new QgsPropertyOverrideButton(WidgetLinePatternFill);
        mDistanceDDBtn->setObjectName(QString::fromUtf8("mDistanceDDBtn"));

        gridLayout->addWidget(mDistanceDDBtn, 1, 3, 1, 1);

        mAngleSpinBox = new QgsDoubleSpinBox(WidgetLinePatternFill);
        mAngleSpinBox->setObjectName(QString::fromUtf8("mAngleSpinBox"));
        mAngleSpinBox->setWrapping(true);
        mAngleSpinBox->setMinimum(-360.000000000000000);
        mAngleSpinBox->setMaximum(360.000000000000000);
        mAngleSpinBox->setSingleStep(0.500000000000000);
        mAngleSpinBox->setProperty("showClearButton", QVariant(true));

        gridLayout->addWidget(mAngleSpinBox, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        QWidget::setTabOrder(mAngleSpinBox, mAngleDDBtn);
        QWidget::setTabOrder(mAngleDDBtn, mDistanceSpinBox);
        QWidget::setTabOrder(mDistanceSpinBox, mDistanceUnitWidget);
        QWidget::setTabOrder(mDistanceUnitWidget, mDistanceDDBtn);
        QWidget::setTabOrder(mDistanceDDBtn, mOffsetSpinBox);
        QWidget::setTabOrder(mOffsetSpinBox, mOffsetUnitWidget);

        retranslateUi(WidgetLinePatternFill);

        QMetaObject::connectSlotsByName(WidgetLinePatternFill);
    } // setupUi

    void retranslateUi(QWidget *WidgetLinePatternFill)
    {
        mRotationLabel->setText(QCoreApplication::translate("WidgetLinePatternFill", "Rotation", nullptr));
        mAngleDDBtn->setText(QCoreApplication::translate("WidgetLinePatternFill", "\342\200\246", nullptr));
        mDistanceLabel->setText(QCoreApplication::translate("WidgetLinePatternFill", "Spacing", nullptr));
        mOffsetLabel->setText(QCoreApplication::translate("WidgetLinePatternFill", "Offset", nullptr));
        mDistanceDDBtn->setText(QCoreApplication::translate("WidgetLinePatternFill", "\342\200\246", nullptr));
        mAngleSpinBox->setSuffix(QCoreApplication::translate("WidgetLinePatternFill", " \302\260", nullptr));
        (void)WidgetLinePatternFill;
    } // retranslateUi

};

namespace Ui {
    class WidgetLinePatternFill: public Ui_WidgetLinePatternFill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LINEPATTERNFILL_H
