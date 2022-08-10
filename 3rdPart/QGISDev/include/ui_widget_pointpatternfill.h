/********************************************************************************
** Form generated from reading UI file 'widget_pointpatternfill.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_POINTPATTERNFILL_H
#define UI_WIDGET_POINTPATTERNFILL_H

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

class Ui_WidgetPointPatternFill
{
public:
    QGridLayout *gridLayout;
    QLabel *mHorizontalDistanceLabel;
    QLabel *mHorizontalDisplacementLabel;
    QLabel *mOffsetLabel;
    QLabel *mHorizontalOffsetLabel;
    QHBoxLayout *horizontalLayout_6;
    QgsDoubleSpinBox *mHorizontalOffsetSpinBox;
    QgsUnitSelectionWidget *mHorizontalOffsetUnitWidget;
    QgsPropertyOverrideButton *mHorizontalOffsetDDBtn;
    QLabel *mVerticalOffsetLabel;
    QHBoxLayout *horizontalLayout_7;
    QgsDoubleSpinBox *mVerticalOffsetSpinBox;
    QgsUnitSelectionWidget *mVerticalOffsetUnitWidget;
    QgsPropertyOverrideButton *mVerticalOffsetDDBtn;
    QLabel *mHorizontalDistanceLabel1;
    QLabel *mHorizontalDisplacementLabel1;
    QHBoxLayout *horizontalLayout_2;
    QgsDoubleSpinBox *mVerticalDistanceSpinBox;
    QgsUnitSelectionWidget *mVerticalDistanceUnitWidget;
    QgsPropertyOverrideButton *mVerticalDistanceDDBtn;
    QLabel *mVerticalDisplacementLabel;
    QHBoxLayout *horizontalLayout_5;
    QgsDoubleSpinBox *mVerticalDisplacementSpinBox;
    QgsUnitSelectionWidget *mVerticalDisplacementUnitWidget;
    QgsPropertyOverrideButton *mHorizontalDistanceDDBtn;
    QLabel *mVerticalDistanceLabel;
    QHBoxLayout *horizontalLayout_4;
    QgsDoubleSpinBox *mHorizontalDisplacementSpinBox;
    QgsUnitSelectionWidget *mHorizontalDisplacementUnitWidget;
    QgsPropertyOverrideButton *mHorizontalDisplacementDDBtn;
    QHBoxLayout *horizontalLayout;
    QgsDoubleSpinBox *mHorizontalDistanceSpinBox;
    QgsUnitSelectionWidget *mHorizontalDistanceUnitWidget;
    QgsPropertyOverrideButton *mVerticalDisplacementDDBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetPointPatternFill)
    {
        if (WidgetPointPatternFill->objectName().isEmpty())
            WidgetPointPatternFill->setObjectName(QString::fromUtf8("WidgetPointPatternFill"));
        WidgetPointPatternFill->resize(401, 206);
        WidgetPointPatternFill->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(WidgetPointPatternFill);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mHorizontalDistanceLabel = new QLabel(WidgetPointPatternFill);
        mHorizontalDistanceLabel->setObjectName(QString::fromUtf8("mHorizontalDistanceLabel"));

        gridLayout->addWidget(mHorizontalDistanceLabel, 0, 0, 1, 3);

        mHorizontalDisplacementLabel = new QLabel(WidgetPointPatternFill);
        mHorizontalDisplacementLabel->setObjectName(QString::fromUtf8("mHorizontalDisplacementLabel"));

        gridLayout->addWidget(mHorizontalDisplacementLabel, 3, 0, 1, 3);

        mOffsetLabel = new QLabel(WidgetPointPatternFill);
        mOffsetLabel->setObjectName(QString::fromUtf8("mOffsetLabel"));

        gridLayout->addWidget(mOffsetLabel, 6, 0, 1, 3);

        mHorizontalOffsetLabel = new QLabel(WidgetPointPatternFill);
        mHorizontalOffsetLabel->setObjectName(QString::fromUtf8("mHorizontalOffsetLabel"));

        gridLayout->addWidget(mHorizontalOffsetLabel, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        mHorizontalOffsetSpinBox = new QgsDoubleSpinBox(WidgetPointPatternFill);
        mHorizontalOffsetSpinBox->setObjectName(QString::fromUtf8("mHorizontalOffsetSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mHorizontalOffsetSpinBox->sizePolicy().hasHeightForWidth());
        mHorizontalOffsetSpinBox->setSizePolicy(sizePolicy);
        mHorizontalOffsetSpinBox->setDecimals(6);
        mHorizontalOffsetSpinBox->setMinimum(-99999999.989999994635582);
        mHorizontalOffsetSpinBox->setMaximum(99999999.989999994635582);
        mHorizontalOffsetSpinBox->setSingleStep(0.200000000000000);
        mHorizontalOffsetSpinBox->setClearValue(0.000000000000000);
        mHorizontalOffsetSpinBox->setProperty("showClearButton", QVariant(true));

        horizontalLayout_6->addWidget(mHorizontalOffsetSpinBox);

        mHorizontalOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetPointPatternFill);
        mHorizontalOffsetUnitWidget->setObjectName(QString::fromUtf8("mHorizontalOffsetUnitWidget"));
        mHorizontalOffsetUnitWidget->setMinimumSize(QSize(0, 0));
        mHorizontalOffsetUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_6->addWidget(mHorizontalOffsetUnitWidget);


        gridLayout->addLayout(horizontalLayout_6, 7, 1, 1, 1);

        mHorizontalOffsetDDBtn = new QgsPropertyOverrideButton(WidgetPointPatternFill);
        mHorizontalOffsetDDBtn->setObjectName(QString::fromUtf8("mHorizontalOffsetDDBtn"));

        gridLayout->addWidget(mHorizontalOffsetDDBtn, 7, 2, 1, 1);

        mVerticalOffsetLabel = new QLabel(WidgetPointPatternFill);
        mVerticalOffsetLabel->setObjectName(QString::fromUtf8("mVerticalOffsetLabel"));

        gridLayout->addWidget(mVerticalOffsetLabel, 8, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        mVerticalOffsetSpinBox = new QgsDoubleSpinBox(WidgetPointPatternFill);
        mVerticalOffsetSpinBox->setObjectName(QString::fromUtf8("mVerticalOffsetSpinBox"));
        sizePolicy.setHeightForWidth(mVerticalOffsetSpinBox->sizePolicy().hasHeightForWidth());
        mVerticalOffsetSpinBox->setSizePolicy(sizePolicy);
        mVerticalOffsetSpinBox->setDecimals(6);
        mVerticalOffsetSpinBox->setMinimum(-99999999.989999994635582);
        mVerticalOffsetSpinBox->setMaximum(99999999.989999994635582);
        mVerticalOffsetSpinBox->setSingleStep(0.200000000000000);
        mVerticalOffsetSpinBox->setClearValue(0.000000000000000);
        mVerticalOffsetSpinBox->setProperty("showClearButton", QVariant(true));

        horizontalLayout_7->addWidget(mVerticalOffsetSpinBox);

        mVerticalOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetPointPatternFill);
        mVerticalOffsetUnitWidget->setObjectName(QString::fromUtf8("mVerticalOffsetUnitWidget"));
        mVerticalOffsetUnitWidget->setMinimumSize(QSize(0, 0));
        mVerticalOffsetUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_7->addWidget(mVerticalOffsetUnitWidget);


        gridLayout->addLayout(horizontalLayout_7, 8, 1, 1, 1);

        mVerticalOffsetDDBtn = new QgsPropertyOverrideButton(WidgetPointPatternFill);
        mVerticalOffsetDDBtn->setObjectName(QString::fromUtf8("mVerticalOffsetDDBtn"));

        gridLayout->addWidget(mVerticalOffsetDDBtn, 8, 2, 1, 1);

        mHorizontalDistanceLabel1 = new QLabel(WidgetPointPatternFill);
        mHorizontalDistanceLabel1->setObjectName(QString::fromUtf8("mHorizontalDistanceLabel1"));

        gridLayout->addWidget(mHorizontalDistanceLabel1, 1, 0, 1, 1);

        mHorizontalDisplacementLabel1 = new QLabel(WidgetPointPatternFill);
        mHorizontalDisplacementLabel1->setObjectName(QString::fromUtf8("mHorizontalDisplacementLabel1"));

        gridLayout->addWidget(mHorizontalDisplacementLabel1, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mVerticalDistanceSpinBox = new QgsDoubleSpinBox(WidgetPointPatternFill);
        mVerticalDistanceSpinBox->setObjectName(QString::fromUtf8("mVerticalDistanceSpinBox"));
        sizePolicy.setHeightForWidth(mVerticalDistanceSpinBox->sizePolicy().hasHeightForWidth());
        mVerticalDistanceSpinBox->setSizePolicy(sizePolicy);
        mVerticalDistanceSpinBox->setDecimals(6);
        mVerticalDistanceSpinBox->setMaximum(999999999.990000009536743);
        mVerticalDistanceSpinBox->setSingleStep(0.200000000000000);
        mVerticalDistanceSpinBox->setProperty("showClearButton", QVariant(false));

        horizontalLayout_2->addWidget(mVerticalDistanceSpinBox);

        mVerticalDistanceUnitWidget = new QgsUnitSelectionWidget(WidgetPointPatternFill);
        mVerticalDistanceUnitWidget->setObjectName(QString::fromUtf8("mVerticalDistanceUnitWidget"));
        mVerticalDistanceUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(mVerticalDistanceUnitWidget);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        mVerticalDistanceDDBtn = new QgsPropertyOverrideButton(WidgetPointPatternFill);
        mVerticalDistanceDDBtn->setObjectName(QString::fromUtf8("mVerticalDistanceDDBtn"));

        gridLayout->addWidget(mVerticalDistanceDDBtn, 2, 2, 1, 1);

        mVerticalDisplacementLabel = new QLabel(WidgetPointPatternFill);
        mVerticalDisplacementLabel->setObjectName(QString::fromUtf8("mVerticalDisplacementLabel"));

        gridLayout->addWidget(mVerticalDisplacementLabel, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        mVerticalDisplacementSpinBox = new QgsDoubleSpinBox(WidgetPointPatternFill);
        mVerticalDisplacementSpinBox->setObjectName(QString::fromUtf8("mVerticalDisplacementSpinBox"));
        sizePolicy.setHeightForWidth(mVerticalDisplacementSpinBox->sizePolicy().hasHeightForWidth());
        mVerticalDisplacementSpinBox->setSizePolicy(sizePolicy);
        mVerticalDisplacementSpinBox->setDecimals(6);
        mVerticalDisplacementSpinBox->setMaximum(99999999.989999994635582);
        mVerticalDisplacementSpinBox->setSingleStep(0.200000000000000);
        mVerticalDisplacementSpinBox->setProperty("showClearButton", QVariant(true));

        horizontalLayout_5->addWidget(mVerticalDisplacementSpinBox);

        mVerticalDisplacementUnitWidget = new QgsUnitSelectionWidget(WidgetPointPatternFill);
        mVerticalDisplacementUnitWidget->setObjectName(QString::fromUtf8("mVerticalDisplacementUnitWidget"));
        mVerticalDisplacementUnitWidget->setMinimumSize(QSize(0, 0));
        mVerticalDisplacementUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_5->addWidget(mVerticalDisplacementUnitWidget);


        gridLayout->addLayout(horizontalLayout_5, 5, 1, 1, 1);

        mHorizontalDistanceDDBtn = new QgsPropertyOverrideButton(WidgetPointPatternFill);
        mHorizontalDistanceDDBtn->setObjectName(QString::fromUtf8("mHorizontalDistanceDDBtn"));

        gridLayout->addWidget(mHorizontalDistanceDDBtn, 1, 2, 1, 1);

        mVerticalDistanceLabel = new QLabel(WidgetPointPatternFill);
        mVerticalDistanceLabel->setObjectName(QString::fromUtf8("mVerticalDistanceLabel"));

        gridLayout->addWidget(mVerticalDistanceLabel, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mHorizontalDisplacementSpinBox = new QgsDoubleSpinBox(WidgetPointPatternFill);
        mHorizontalDisplacementSpinBox->setObjectName(QString::fromUtf8("mHorizontalDisplacementSpinBox"));
        sizePolicy.setHeightForWidth(mHorizontalDisplacementSpinBox->sizePolicy().hasHeightForWidth());
        mHorizontalDisplacementSpinBox->setSizePolicy(sizePolicy);
        mHorizontalDisplacementSpinBox->setDecimals(6);
        mHorizontalDisplacementSpinBox->setMaximum(99999999.989999994635582);
        mHorizontalDisplacementSpinBox->setSingleStep(0.200000000000000);
        mHorizontalDisplacementSpinBox->setProperty("showClearButton", QVariant(true));

        horizontalLayout_4->addWidget(mHorizontalDisplacementSpinBox);

        mHorizontalDisplacementUnitWidget = new QgsUnitSelectionWidget(WidgetPointPatternFill);
        mHorizontalDisplacementUnitWidget->setObjectName(QString::fromUtf8("mHorizontalDisplacementUnitWidget"));
        mHorizontalDisplacementUnitWidget->setMinimumSize(QSize(0, 0));
        mHorizontalDisplacementUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_4->addWidget(mHorizontalDisplacementUnitWidget);


        gridLayout->addLayout(horizontalLayout_4, 4, 1, 1, 1);

        mHorizontalDisplacementDDBtn = new QgsPropertyOverrideButton(WidgetPointPatternFill);
        mHorizontalDisplacementDDBtn->setObjectName(QString::fromUtf8("mHorizontalDisplacementDDBtn"));

        gridLayout->addWidget(mHorizontalDisplacementDDBtn, 4, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mHorizontalDistanceSpinBox = new QgsDoubleSpinBox(WidgetPointPatternFill);
        mHorizontalDistanceSpinBox->setObjectName(QString::fromUtf8("mHorizontalDistanceSpinBox"));
        sizePolicy.setHeightForWidth(mHorizontalDistanceSpinBox->sizePolicy().hasHeightForWidth());
        mHorizontalDistanceSpinBox->setSizePolicy(sizePolicy);
        mHorizontalDistanceSpinBox->setDecimals(6);
        mHorizontalDistanceSpinBox->setMaximum(99999999.989999994635582);
        mHorizontalDistanceSpinBox->setSingleStep(0.200000000000000);
        mHorizontalDistanceSpinBox->setProperty("showClearButton", QVariant(false));

        horizontalLayout->addWidget(mHorizontalDistanceSpinBox);

        mHorizontalDistanceUnitWidget = new QgsUnitSelectionWidget(WidgetPointPatternFill);
        mHorizontalDistanceUnitWidget->setObjectName(QString::fromUtf8("mHorizontalDistanceUnitWidget"));
        mHorizontalDistanceUnitWidget->setMinimumSize(QSize(0, 0));
        mHorizontalDistanceUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(mHorizontalDistanceUnitWidget);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        mVerticalDisplacementDDBtn = new QgsPropertyOverrideButton(WidgetPointPatternFill);
        mVerticalDisplacementDDBtn->setObjectName(QString::fromUtf8("mVerticalDisplacementDDBtn"));

        gridLayout->addWidget(mVerticalDisplacementDDBtn, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 3);

        gridLayout->setColumnStretch(1, 1);
        QWidget::setTabOrder(mHorizontalDistanceSpinBox, mHorizontalDistanceUnitWidget);
        QWidget::setTabOrder(mHorizontalDistanceUnitWidget, mHorizontalDistanceDDBtn);
        QWidget::setTabOrder(mHorizontalDistanceDDBtn, mVerticalDistanceSpinBox);
        QWidget::setTabOrder(mVerticalDistanceSpinBox, mVerticalDistanceUnitWidget);
        QWidget::setTabOrder(mVerticalDistanceUnitWidget, mVerticalDistanceDDBtn);
        QWidget::setTabOrder(mVerticalDistanceDDBtn, mHorizontalDisplacementSpinBox);
        QWidget::setTabOrder(mHorizontalDisplacementSpinBox, mHorizontalDisplacementUnitWidget);
        QWidget::setTabOrder(mHorizontalDisplacementUnitWidget, mHorizontalDisplacementDDBtn);
        QWidget::setTabOrder(mHorizontalDisplacementDDBtn, mVerticalDisplacementSpinBox);
        QWidget::setTabOrder(mVerticalDisplacementSpinBox, mVerticalDisplacementUnitWidget);
        QWidget::setTabOrder(mVerticalDisplacementUnitWidget, mVerticalDisplacementDDBtn);
        QWidget::setTabOrder(mVerticalDisplacementDDBtn, mHorizontalOffsetSpinBox);
        QWidget::setTabOrder(mHorizontalOffsetSpinBox, mHorizontalOffsetUnitWidget);
        QWidget::setTabOrder(mHorizontalOffsetUnitWidget, mHorizontalOffsetDDBtn);
        QWidget::setTabOrder(mHorizontalOffsetDDBtn, mVerticalOffsetSpinBox);
        QWidget::setTabOrder(mVerticalOffsetSpinBox, mVerticalOffsetUnitWidget);
        QWidget::setTabOrder(mVerticalOffsetUnitWidget, mVerticalOffsetDDBtn);

        retranslateUi(WidgetPointPatternFill);

        QMetaObject::connectSlotsByName(WidgetPointPatternFill);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointPatternFill)
    {
        mHorizontalDistanceLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Distance", nullptr));
        mHorizontalDisplacementLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Displacement", nullptr));
        mOffsetLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Offset", nullptr));
        mHorizontalOffsetLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Horizontal", nullptr));
        mHorizontalOffsetDDBtn->setText(QCoreApplication::translate("WidgetPointPatternFill", "\342\200\246", nullptr));
        mVerticalOffsetLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Vertical", nullptr));
        mVerticalOffsetDDBtn->setText(QCoreApplication::translate("WidgetPointPatternFill", "\342\200\246", nullptr));
        mHorizontalDistanceLabel1->setText(QCoreApplication::translate("WidgetPointPatternFill", "Horizontal", nullptr));
        mHorizontalDisplacementLabel1->setText(QCoreApplication::translate("WidgetPointPatternFill", "Horizontal", nullptr));
        mVerticalDistanceDDBtn->setText(QCoreApplication::translate("WidgetPointPatternFill", "\342\200\246", nullptr));
        mVerticalDisplacementLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Vertical", nullptr));
        mHorizontalDistanceDDBtn->setText(QCoreApplication::translate("WidgetPointPatternFill", "\342\200\246", nullptr));
        mVerticalDistanceLabel->setText(QCoreApplication::translate("WidgetPointPatternFill", "Vertical", nullptr));
        mHorizontalDisplacementDDBtn->setText(QCoreApplication::translate("WidgetPointPatternFill", "\342\200\246", nullptr));
        mVerticalDisplacementDDBtn->setText(QCoreApplication::translate("WidgetPointPatternFill", "\342\200\246", nullptr));
        (void)WidgetPointPatternFill;
    } // retranslateUi

};

namespace Ui {
    class WidgetPointPatternFill: public Ui_WidgetPointPatternFill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_POINTPATTERNFILL_H
