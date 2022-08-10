/********************************************************************************
** Form generated from reading UI file 'widget_markerline.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MARKERLINE_H
#define UI_WIDGET_MARKERLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qgsdoublespinbox.h"
#include "qgspropertyoverridebutton.h"
#include "qgsunitselectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetMarkerLine
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QRadioButton *radVertexLast;
    QRadioButton *radCurvePoint;
    QSpacerItem *horizontalSpacer_2;
    QgsPropertyOverrideButton *mIntervalDDBtn;
    QRadioButton *radVertexFirst;
    QRadioButton *radVertex;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radInterval;
    QgsDoubleSpinBox *spinInterval;
    QgsUnitSelectionWidget *mIntervalUnitWidget;
    QRadioButton *radCentralPoint;
    QRadioButton *radSegmentCentralPoint;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QgsPropertyOverrideButton *mPlacementDDBtn;
    QGridLayout *gridLayout;
    QgsDoubleSpinBox *mSpinOffsetAlongLine;
    QComboBox *mRingFilterComboBox;
    QgsPropertyOverrideButton *mLineOffsetDDBtn;
    QLabel *label_4;
    QgsUnitSelectionWidget *mOffsetAlongLineUnitWidget;
    QgsDoubleSpinBox *spinOffset;
    QgsUnitSelectionWidget *mOffsetUnitWidget;
    QgsUnitSelectionWidget *mAverageAngleUnit;
    QgsPropertyOverrideButton *mAverageAngleDDBtn;
    QgsPropertyOverrideButton *mOffsetAlongLineDDBtn;
    QgsDoubleSpinBox *mSpinAverageAngleLength;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QCheckBox *chkRotateMarker;
    QLabel *label_3;
    QLabel *mRingsLabel;

    void setupUi(QWidget *WidgetMarkerLine)
    {
        if (WidgetMarkerLine->objectName().isEmpty())
            WidgetMarkerLine->setObjectName(QString::fromUtf8("WidgetMarkerLine"));
        WidgetMarkerLine->resize(371, 348);
        WidgetMarkerLine->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout_2 = new QGridLayout(WidgetMarkerLine);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, -1, 1, 1);
        label_2 = new QLabel(WidgetMarkerLine);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, -1, 0);
        radVertexLast = new QRadioButton(WidgetMarkerLine);
        radVertexLast->setObjectName(QString::fromUtf8("radVertexLast"));

        gridLayout_3->addWidget(radVertexLast, 5, 1, 1, 1);

        radCurvePoint = new QRadioButton(WidgetMarkerLine);
        radCurvePoint->setObjectName(QString::fromUtf8("radCurvePoint"));

        gridLayout_3->addWidget(radCurvePoint, 9, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 6, 0, 1, 1);

        mIntervalDDBtn = new QgsPropertyOverrideButton(WidgetMarkerLine);
        mIntervalDDBtn->setObjectName(QString::fromUtf8("mIntervalDDBtn"));

        gridLayout_3->addWidget(mIntervalDDBtn, 3, 2, 1, 1);

        radVertexFirst = new QRadioButton(WidgetMarkerLine);
        radVertexFirst->setObjectName(QString::fromUtf8("radVertexFirst"));

        gridLayout_3->addWidget(radVertexFirst, 6, 1, 1, 1);

        radVertex = new QRadioButton(WidgetMarkerLine);
        radVertex->setObjectName(QString::fromUtf8("radVertex"));

        gridLayout_3->addWidget(radVertex, 4, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radInterval = new QRadioButton(WidgetMarkerLine);
        radInterval->setObjectName(QString::fromUtf8("radInterval"));
        radInterval->setChecked(true);

        horizontalLayout_4->addWidget(radInterval);

        spinInterval = new QgsDoubleSpinBox(WidgetMarkerLine);
        spinInterval->setObjectName(QString::fromUtf8("spinInterval"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinInterval->sizePolicy().hasHeightForWidth());
        spinInterval->setSizePolicy(sizePolicy);
        spinInterval->setDecimals(6);
        spinInterval->setMaximum(10000000.000000000000000);
        spinInterval->setSingleStep(0.200000000000000);
        spinInterval->setValue(1.000000000000000);
        spinInterval->setProperty("showClearButton", QVariant(false));

        horizontalLayout_4->addWidget(spinInterval);

        mIntervalUnitWidget = new QgsUnitSelectionWidget(WidgetMarkerLine);
        mIntervalUnitWidget->setObjectName(QString::fromUtf8("mIntervalUnitWidget"));
        mIntervalUnitWidget->setMinimumSize(QSize(0, 0));
        mIntervalUnitWidget->setFocusPolicy(Qt::TabFocus);

        horizontalLayout_4->addWidget(mIntervalUnitWidget);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        radCentralPoint = new QRadioButton(WidgetMarkerLine);
        radCentralPoint->setObjectName(QString::fromUtf8("radCentralPoint"));

        gridLayout_3->addWidget(radCentralPoint, 7, 1, 1, 1);

        radSegmentCentralPoint = new QRadioButton(WidgetMarkerLine);
        radSegmentCentralPoint->setObjectName(QString::fromUtf8("radSegmentCentralPoint"));

        gridLayout_3->addWidget(radSegmentCentralPoint, 8, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        mPlacementDDBtn = new QgsPropertyOverrideButton(WidgetMarkerLine);
        mPlacementDDBtn->setObjectName(QString::fromUtf8("mPlacementDDBtn"));

        gridLayout_2->addWidget(mPlacementDDBtn, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        mSpinOffsetAlongLine = new QgsDoubleSpinBox(WidgetMarkerLine);
        mSpinOffsetAlongLine->setObjectName(QString::fromUtf8("mSpinOffsetAlongLine"));
        sizePolicy.setHeightForWidth(mSpinOffsetAlongLine->sizePolicy().hasHeightForWidth());
        mSpinOffsetAlongLine->setSizePolicy(sizePolicy);
        mSpinOffsetAlongLine->setDecimals(6);
        mSpinOffsetAlongLine->setMaximum(10000000.000000000000000);
        mSpinOffsetAlongLine->setSingleStep(0.200000000000000);
        mSpinOffsetAlongLine->setValue(1.000000000000000);

        gridLayout->addWidget(mSpinOffsetAlongLine, 0, 2, 1, 1);

        mRingFilterComboBox = new QComboBox(WidgetMarkerLine);
        mRingFilterComboBox->setObjectName(QString::fromUtf8("mRingFilterComboBox"));

        gridLayout->addWidget(mRingFilterComboBox, 4, 2, 1, 3);

        mLineOffsetDDBtn = new QgsPropertyOverrideButton(WidgetMarkerLine);
        mLineOffsetDDBtn->setObjectName(QString::fromUtf8("mLineOffsetDDBtn"));

        gridLayout->addWidget(mLineOffsetDDBtn, 3, 4, 1, 1);

        label_4 = new QLabel(WidgetMarkerLine);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        mOffsetAlongLineUnitWidget = new QgsUnitSelectionWidget(WidgetMarkerLine);
        mOffsetAlongLineUnitWidget->setObjectName(QString::fromUtf8("mOffsetAlongLineUnitWidget"));
        mOffsetAlongLineUnitWidget->setMinimumSize(QSize(20, 0));
        mOffsetAlongLineUnitWidget->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mOffsetAlongLineUnitWidget, 0, 3, 1, 1);

        spinOffset = new QgsDoubleSpinBox(WidgetMarkerLine);
        spinOffset->setObjectName(QString::fromUtf8("spinOffset"));
        sizePolicy.setHeightForWidth(spinOffset->sizePolicy().hasHeightForWidth());
        spinOffset->setSizePolicy(sizePolicy);
        spinOffset->setDecimals(6);
        spinOffset->setMinimum(-999999999.000000000000000);
        spinOffset->setMaximum(999999999.000000000000000);
        spinOffset->setSingleStep(0.200000000000000);

        gridLayout->addWidget(spinOffset, 3, 2, 1, 1);

        mOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetMarkerLine);
        mOffsetUnitWidget->setObjectName(QString::fromUtf8("mOffsetUnitWidget"));
        mOffsetUnitWidget->setMinimumSize(QSize(0, 0));
        mOffsetUnitWidget->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mOffsetUnitWidget, 3, 3, 1, 1);

        mAverageAngleUnit = new QgsUnitSelectionWidget(WidgetMarkerLine);
        mAverageAngleUnit->setObjectName(QString::fromUtf8("mAverageAngleUnit"));
        mAverageAngleUnit->setMinimumSize(QSize(20, 0));
        mAverageAngleUnit->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mAverageAngleUnit, 2, 3, 1, 1);

        mAverageAngleDDBtn = new QgsPropertyOverrideButton(WidgetMarkerLine);
        mAverageAngleDDBtn->setObjectName(QString::fromUtf8("mAverageAngleDDBtn"));

        gridLayout->addWidget(mAverageAngleDDBtn, 2, 4, 1, 1);

        mOffsetAlongLineDDBtn = new QgsPropertyOverrideButton(WidgetMarkerLine);
        mOffsetAlongLineDDBtn->setObjectName(QString::fromUtf8("mOffsetAlongLineDDBtn"));

        gridLayout->addWidget(mOffsetAlongLineDDBtn, 0, 4, 1, 1);

        mSpinAverageAngleLength = new QgsDoubleSpinBox(WidgetMarkerLine);
        mSpinAverageAngleLength->setObjectName(QString::fromUtf8("mSpinAverageAngleLength"));
        sizePolicy.setHeightForWidth(mSpinAverageAngleLength->sizePolicy().hasHeightForWidth());
        mSpinAverageAngleLength->setSizePolicy(sizePolicy);
        mSpinAverageAngleLength->setDecimals(6);
        mSpinAverageAngleLength->setMaximum(10000000.000000000000000);
        mSpinAverageAngleLength->setSingleStep(0.200000000000000);
        mSpinAverageAngleLength->setValue(1.000000000000000);

        gridLayout->addWidget(mSpinAverageAngleLength, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        label = new QLabel(WidgetMarkerLine);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        chkRotateMarker = new QCheckBox(WidgetMarkerLine);
        chkRotateMarker->setObjectName(QString::fromUtf8("chkRotateMarker"));

        gridLayout->addWidget(chkRotateMarker, 1, 0, 1, 5);

        label_3 = new QLabel(WidgetMarkerLine);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 2);

        mRingsLabel = new QLabel(WidgetMarkerLine);
        mRingsLabel->setObjectName(QString::fromUtf8("mRingsLabel"));

        gridLayout->addWidget(mRingsLabel, 4, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 3);

        QWidget::setTabOrder(mPlacementDDBtn, radInterval);
        QWidget::setTabOrder(radInterval, spinInterval);
        QWidget::setTabOrder(spinInterval, mIntervalUnitWidget);
        QWidget::setTabOrder(mIntervalUnitWidget, mIntervalDDBtn);
        QWidget::setTabOrder(mIntervalDDBtn, radVertex);
        QWidget::setTabOrder(radVertex, radVertexLast);
        QWidget::setTabOrder(radVertexLast, radVertexFirst);
        QWidget::setTabOrder(radVertexFirst, radCentralPoint);
        QWidget::setTabOrder(radCentralPoint, radSegmentCentralPoint);
        QWidget::setTabOrder(radSegmentCentralPoint, radCurvePoint);
        QWidget::setTabOrder(radCurvePoint, mSpinOffsetAlongLine);
        QWidget::setTabOrder(mSpinOffsetAlongLine, mOffsetAlongLineUnitWidget);
        QWidget::setTabOrder(mOffsetAlongLineUnitWidget, mOffsetAlongLineDDBtn);
        QWidget::setTabOrder(mOffsetAlongLineDDBtn, chkRotateMarker);
        QWidget::setTabOrder(chkRotateMarker, mSpinAverageAngleLength);
        QWidget::setTabOrder(mSpinAverageAngleLength, mAverageAngleUnit);
        QWidget::setTabOrder(mAverageAngleUnit, mAverageAngleDDBtn);
        QWidget::setTabOrder(mAverageAngleDDBtn, spinOffset);
        QWidget::setTabOrder(spinOffset, mOffsetUnitWidget);
        QWidget::setTabOrder(mOffsetUnitWidget, mLineOffsetDDBtn);
        QWidget::setTabOrder(mLineOffsetDDBtn, mRingFilterComboBox);

        retranslateUi(WidgetMarkerLine);

        QMetaObject::connectSlotsByName(WidgetMarkerLine);
    } // setupUi

    void retranslateUi(QWidget *WidgetMarkerLine)
    {
        label_2->setText(QCoreApplication::translate("WidgetMarkerLine", "Marker placement", nullptr));
        radVertexLast->setText(QCoreApplication::translate("WidgetMarkerLine", "on last vertex only", nullptr));
        radCurvePoint->setText(QCoreApplication::translate("WidgetMarkerLine", "on every curve point", nullptr));
        mIntervalDDBtn->setText(QCoreApplication::translate("WidgetMarkerLine", "\342\200\246", nullptr));
        radVertexFirst->setText(QCoreApplication::translate("WidgetMarkerLine", "on first vertex only", nullptr));
        radVertex->setText(QCoreApplication::translate("WidgetMarkerLine", "on every vertex", nullptr));
        radInterval->setText(QCoreApplication::translate("WidgetMarkerLine", "with interval", nullptr));
        radCentralPoint->setText(QCoreApplication::translate("WidgetMarkerLine", "on central point", nullptr));
        radSegmentCentralPoint->setText(QCoreApplication::translate("WidgetMarkerLine", "on central point of segments", nullptr));
        mPlacementDDBtn->setText(QCoreApplication::translate("WidgetMarkerLine", "\342\200\246", nullptr));
        mLineOffsetDDBtn->setText(QCoreApplication::translate("WidgetMarkerLine", "\342\200\246", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetMarkerLine", "Average angle over", nullptr));
        mAverageAngleDDBtn->setText(QCoreApplication::translate("WidgetMarkerLine", "\342\200\246", nullptr));
        mOffsetAlongLineDDBtn->setText(QCoreApplication::translate("WidgetMarkerLine", "\342\200\246", nullptr));
        label->setText(QCoreApplication::translate("WidgetMarkerLine", "Offset along line", nullptr));
        chkRotateMarker->setText(QCoreApplication::translate("WidgetMarkerLine", "Rotate marker to follow line direction", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetMarkerLine", "Line offset", nullptr));
        mRingsLabel->setText(QCoreApplication::translate("WidgetMarkerLine", "Rings", nullptr));
        (void)WidgetMarkerLine;
    } // retranslateUi

};

namespace Ui {
    class WidgetMarkerLine: public Ui_WidgetMarkerLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MARKERLINE_H
