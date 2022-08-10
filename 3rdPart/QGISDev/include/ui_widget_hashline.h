/********************************************************************************
** Form generated from reading UI file 'widget_hashline.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_HASHLINE_H
#define UI_WIDGET_HASHLINE_H

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

class Ui_WidgetHashedLine
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radInterval;
    QgsDoubleSpinBox *spinInterval;
    QgsUnitSelectionWidget *mIntervalUnitWidget;
    QRadioButton *radVertex;
    QRadioButton *radVertexLast;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radVertexFirst;
    QRadioButton *radCurvePoint;
    QgsPropertyOverrideButton *mIntervalDDBtn;
    QRadioButton *radCentralPoint;
    QRadioButton *radSegmentCentralPoint;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QgsPropertyOverrideButton *mPlacementDDBtn;
    QGridLayout *gridLayout;
    QgsPropertyOverrideButton *mHashRotationDDBtn;
    QgsPropertyOverrideButton *mAverageAngleDDBtn;
    QgsPropertyOverrideButton *mOffsetAlongLineDDBtn;
    QgsUnitSelectionWidget *mAverageAngleUnit;
    QLabel *label_3;
    QgsPropertyOverrideButton *mHashLengthDDBtn;
    QgsDoubleSpinBox *mHashRotationSpinBox;
    QLabel *label_4;
    QgsUnitSelectionWidget *mOffsetUnitWidget;
    QLabel *label;
    QLabel *label_5;
    QgsDoubleSpinBox *mSpinHashLength;
    QComboBox *mRingFilterComboBox;
    QgsUnitSelectionWidget *mOffsetAlongLineUnitWidget;
    QLabel *mRingsLabel;
    QgsDoubleSpinBox *spinOffset;
    QLabel *label_6;
    QgsUnitSelectionWidget *mHashLengthUnitWidget;
    QSpacerItem *horizontalSpacer_3;
    QgsDoubleSpinBox *mSpinAverageAngleLength;
    QgsPropertyOverrideButton *mLineOffsetDDBtn;
    QgsDoubleSpinBox *mSpinOffsetAlongLine;
    QCheckBox *chkRotateMarker;

    void setupUi(QWidget *WidgetHashedLine)
    {
        if (WidgetHashedLine->objectName().isEmpty())
            WidgetHashedLine->setObjectName(QString::fromUtf8("WidgetHashedLine"));
        WidgetHashedLine->resize(371, 380);
        WidgetHashedLine->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout_2 = new QGridLayout(WidgetHashedLine);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, -1, 1, 1);
        label_2 = new QLabel(WidgetHashedLine);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, -1, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radInterval = new QRadioButton(WidgetHashedLine);
        radInterval->setObjectName(QString::fromUtf8("radInterval"));
        radInterval->setChecked(true);

        horizontalLayout_4->addWidget(radInterval);

        spinInterval = new QgsDoubleSpinBox(WidgetHashedLine);
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

        mIntervalUnitWidget = new QgsUnitSelectionWidget(WidgetHashedLine);
        mIntervalUnitWidget->setObjectName(QString::fromUtf8("mIntervalUnitWidget"));
        mIntervalUnitWidget->setMinimumSize(QSize(0, 0));
        mIntervalUnitWidget->setFocusPolicy(Qt::TabFocus);

        horizontalLayout_4->addWidget(mIntervalUnitWidget);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        radVertex = new QRadioButton(WidgetHashedLine);
        radVertex->setObjectName(QString::fromUtf8("radVertex"));

        gridLayout_3->addWidget(radVertex, 4, 1, 1, 1);

        radVertexLast = new QRadioButton(WidgetHashedLine);
        radVertexLast->setObjectName(QString::fromUtf8("radVertexLast"));

        gridLayout_3->addWidget(radVertexLast, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 6, 0, 1, 1);

        radVertexFirst = new QRadioButton(WidgetHashedLine);
        radVertexFirst->setObjectName(QString::fromUtf8("radVertexFirst"));

        gridLayout_3->addWidget(radVertexFirst, 6, 1, 1, 1);

        radCurvePoint = new QRadioButton(WidgetHashedLine);
        radCurvePoint->setObjectName(QString::fromUtf8("radCurvePoint"));

        gridLayout_3->addWidget(radCurvePoint, 9, 1, 1, 1);

        mIntervalDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mIntervalDDBtn->setObjectName(QString::fromUtf8("mIntervalDDBtn"));

        gridLayout_3->addWidget(mIntervalDDBtn, 3, 2, 1, 1);

        radCentralPoint = new QRadioButton(WidgetHashedLine);
        radCentralPoint->setObjectName(QString::fromUtf8("radCentralPoint"));

        gridLayout_3->addWidget(radCentralPoint, 7, 1, 1, 1);

        radSegmentCentralPoint = new QRadioButton(WidgetHashedLine);
        radSegmentCentralPoint->setObjectName(QString::fromUtf8("radSegmentCentralPoint"));

        gridLayout_3->addWidget(radSegmentCentralPoint, 8, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        mPlacementDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mPlacementDDBtn->setObjectName(QString::fromUtf8("mPlacementDDBtn"));

        gridLayout_2->addWidget(mPlacementDDBtn, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        mHashRotationDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mHashRotationDDBtn->setObjectName(QString::fromUtf8("mHashRotationDDBtn"));

        gridLayout->addWidget(mHashRotationDDBtn, 2, 4, 1, 1);

        mAverageAngleDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mAverageAngleDDBtn->setObjectName(QString::fromUtf8("mAverageAngleDDBtn"));

        gridLayout->addWidget(mAverageAngleDDBtn, 4, 4, 1, 1);

        mOffsetAlongLineDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mOffsetAlongLineDDBtn->setObjectName(QString::fromUtf8("mOffsetAlongLineDDBtn"));

        gridLayout->addWidget(mOffsetAlongLineDDBtn, 0, 4, 1, 1);

        mAverageAngleUnit = new QgsUnitSelectionWidget(WidgetHashedLine);
        mAverageAngleUnit->setObjectName(QString::fromUtf8("mAverageAngleUnit"));
        mAverageAngleUnit->setMinimumSize(QSize(20, 0));
        mAverageAngleUnit->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mAverageAngleUnit, 4, 3, 1, 1);

        label_3 = new QLabel(WidgetHashedLine);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 2);

        mHashLengthDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mHashLengthDDBtn->setObjectName(QString::fromUtf8("mHashLengthDDBtn"));

        gridLayout->addWidget(mHashLengthDDBtn, 1, 4, 1, 1);

        mHashRotationSpinBox = new QgsDoubleSpinBox(WidgetHashedLine);
        mHashRotationSpinBox->setObjectName(QString::fromUtf8("mHashRotationSpinBox"));
        sizePolicy.setHeightForWidth(mHashRotationSpinBox->sizePolicy().hasHeightForWidth());
        mHashRotationSpinBox->setSizePolicy(sizePolicy);
        mHashRotationSpinBox->setWrapping(true);
        mHashRotationSpinBox->setDecimals(2);
        mHashRotationSpinBox->setMinimum(-360.000000000000000);
        mHashRotationSpinBox->setMaximum(360.000000000000000);
        mHashRotationSpinBox->setSingleStep(0.500000000000000);

        gridLayout->addWidget(mHashRotationSpinBox, 2, 2, 1, 1);

        label_4 = new QLabel(WidgetHashedLine);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 2);

        mOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetHashedLine);
        mOffsetUnitWidget->setObjectName(QString::fromUtf8("mOffsetUnitWidget"));
        mOffsetUnitWidget->setMinimumSize(QSize(20, 0));
        mOffsetUnitWidget->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mOffsetUnitWidget, 5, 3, 1, 1);

        label = new QLabel(WidgetHashedLine);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_5 = new QLabel(WidgetHashedLine);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 2);

        mSpinHashLength = new QgsDoubleSpinBox(WidgetHashedLine);
        mSpinHashLength->setObjectName(QString::fromUtf8("mSpinHashLength"));
        sizePolicy.setHeightForWidth(mSpinHashLength->sizePolicy().hasHeightForWidth());
        mSpinHashLength->setSizePolicy(sizePolicy);
        mSpinHashLength->setDecimals(6);
        mSpinHashLength->setMaximum(10000000.000000000000000);
        mSpinHashLength->setSingleStep(0.200000000000000);
        mSpinHashLength->setValue(1.000000000000000);

        gridLayout->addWidget(mSpinHashLength, 1, 2, 1, 1);

        mRingFilterComboBox = new QComboBox(WidgetHashedLine);
        mRingFilterComboBox->setObjectName(QString::fromUtf8("mRingFilterComboBox"));

        gridLayout->addWidget(mRingFilterComboBox, 6, 2, 1, 3);

        mOffsetAlongLineUnitWidget = new QgsUnitSelectionWidget(WidgetHashedLine);
        mOffsetAlongLineUnitWidget->setObjectName(QString::fromUtf8("mOffsetAlongLineUnitWidget"));
        mOffsetAlongLineUnitWidget->setMinimumSize(QSize(0, 0));
        mOffsetAlongLineUnitWidget->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mOffsetAlongLineUnitWidget, 0, 3, 1, 1);

        mRingsLabel = new QLabel(WidgetHashedLine);
        mRingsLabel->setObjectName(QString::fromUtf8("mRingsLabel"));

        gridLayout->addWidget(mRingsLabel, 6, 0, 1, 2);

        spinOffset = new QgsDoubleSpinBox(WidgetHashedLine);
        spinOffset->setObjectName(QString::fromUtf8("spinOffset"));
        sizePolicy.setHeightForWidth(spinOffset->sizePolicy().hasHeightForWidth());
        spinOffset->setSizePolicy(sizePolicy);
        spinOffset->setDecimals(6);
        spinOffset->setMinimum(-999999999.000000000000000);
        spinOffset->setMaximum(999999999.000000000000000);
        spinOffset->setSingleStep(0.200000000000000);

        gridLayout->addWidget(spinOffset, 5, 2, 1, 1);

        label_6 = new QLabel(WidgetHashedLine);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        mHashLengthUnitWidget = new QgsUnitSelectionWidget(WidgetHashedLine);
        mHashLengthUnitWidget->setObjectName(QString::fromUtf8("mHashLengthUnitWidget"));
        mHashLengthUnitWidget->setMinimumSize(QSize(20, 0));
        mHashLengthUnitWidget->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(mHashLengthUnitWidget, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 0, 1, 1);

        mSpinAverageAngleLength = new QgsDoubleSpinBox(WidgetHashedLine);
        mSpinAverageAngleLength->setObjectName(QString::fromUtf8("mSpinAverageAngleLength"));
        sizePolicy.setHeightForWidth(mSpinAverageAngleLength->sizePolicy().hasHeightForWidth());
        mSpinAverageAngleLength->setSizePolicy(sizePolicy);
        mSpinAverageAngleLength->setDecimals(6);
        mSpinAverageAngleLength->setMaximum(10000000.000000000000000);
        mSpinAverageAngleLength->setSingleStep(0.200000000000000);
        mSpinAverageAngleLength->setValue(1.000000000000000);

        gridLayout->addWidget(mSpinAverageAngleLength, 4, 2, 1, 1);

        mLineOffsetDDBtn = new QgsPropertyOverrideButton(WidgetHashedLine);
        mLineOffsetDDBtn->setObjectName(QString::fromUtf8("mLineOffsetDDBtn"));

        gridLayout->addWidget(mLineOffsetDDBtn, 5, 4, 1, 1);

        mSpinOffsetAlongLine = new QgsDoubleSpinBox(WidgetHashedLine);
        mSpinOffsetAlongLine->setObjectName(QString::fromUtf8("mSpinOffsetAlongLine"));
        sizePolicy.setHeightForWidth(mSpinOffsetAlongLine->sizePolicy().hasHeightForWidth());
        mSpinOffsetAlongLine->setSizePolicy(sizePolicy);
        mSpinOffsetAlongLine->setDecimals(6);
        mSpinOffsetAlongLine->setMaximum(10000000.000000000000000);
        mSpinOffsetAlongLine->setSingleStep(0.200000000000000);
        mSpinOffsetAlongLine->setValue(1.000000000000000);

        gridLayout->addWidget(mSpinOffsetAlongLine, 0, 2, 1, 1);

        chkRotateMarker = new QCheckBox(WidgetHashedLine);
        chkRotateMarker->setObjectName(QString::fromUtf8("chkRotateMarker"));

        gridLayout->addWidget(chkRotateMarker, 3, 0, 1, 5);


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
        QWidget::setTabOrder(mOffsetAlongLineDDBtn, mSpinHashLength);
        QWidget::setTabOrder(mSpinHashLength, mHashLengthUnitWidget);
        QWidget::setTabOrder(mHashLengthUnitWidget, mHashLengthDDBtn);
        QWidget::setTabOrder(mHashLengthDDBtn, mHashRotationSpinBox);
        QWidget::setTabOrder(mHashRotationSpinBox, mHashRotationDDBtn);
        QWidget::setTabOrder(mHashRotationDDBtn, chkRotateMarker);
        QWidget::setTabOrder(chkRotateMarker, mSpinAverageAngleLength);
        QWidget::setTabOrder(mSpinAverageAngleLength, mAverageAngleUnit);
        QWidget::setTabOrder(mAverageAngleUnit, mAverageAngleDDBtn);
        QWidget::setTabOrder(mAverageAngleDDBtn, spinOffset);
        QWidget::setTabOrder(spinOffset, mOffsetUnitWidget);
        QWidget::setTabOrder(mOffsetUnitWidget, mLineOffsetDDBtn);
        QWidget::setTabOrder(mLineOffsetDDBtn, mRingFilterComboBox);

        retranslateUi(WidgetHashedLine);

        QMetaObject::connectSlotsByName(WidgetHashedLine);
    } // setupUi

    void retranslateUi(QWidget *WidgetHashedLine)
    {
        label_2->setText(QCoreApplication::translate("WidgetHashedLine", "Hash placement", nullptr));
        radInterval->setText(QCoreApplication::translate("WidgetHashedLine", "with interval", nullptr));
        radVertex->setText(QCoreApplication::translate("WidgetHashedLine", "on every vertex", nullptr));
        radVertexLast->setText(QCoreApplication::translate("WidgetHashedLine", "on last vertex only", nullptr));
        radVertexFirst->setText(QCoreApplication::translate("WidgetHashedLine", "on first vertex only", nullptr));
        radCurvePoint->setText(QCoreApplication::translate("WidgetHashedLine", "on every curve point", nullptr));
        mIntervalDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        radCentralPoint->setText(QCoreApplication::translate("WidgetHashedLine", "on central point", nullptr));
        radSegmentCentralPoint->setText(QCoreApplication::translate("WidgetHashedLine", "on central point of segments", nullptr));
        mPlacementDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        mHashRotationDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        mAverageAngleDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        mOffsetAlongLineDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetHashedLine", "Line offset", nullptr));
        mHashLengthDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        mHashRotationSpinBox->setSuffix(QCoreApplication::translate("WidgetHashedLine", " \302\260", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetHashedLine", "Hash rotation", nullptr));
        label->setText(QCoreApplication::translate("WidgetHashedLine", "Offset along line", nullptr));
        label_5->setText(QCoreApplication::translate("WidgetHashedLine", "Hash length", nullptr));
        mRingsLabel->setText(QCoreApplication::translate("WidgetHashedLine", "Rings", nullptr));
        label_6->setText(QCoreApplication::translate("WidgetHashedLine", "Average angle over", nullptr));
        mLineOffsetDDBtn->setText(QCoreApplication::translate("WidgetHashedLine", "\342\200\246", nullptr));
        chkRotateMarker->setText(QCoreApplication::translate("WidgetHashedLine", "Rotate hash to follow line direction", nullptr));
        (void)WidgetHashedLine;
    } // retranslateUi

};

namespace Ui {
    class WidgetHashedLine: public Ui_WidgetHashedLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_HASHLINE_H
