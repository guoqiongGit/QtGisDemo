/********************************************************************************
** Form generated from reading UI file 'qgsannotationwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSANNOTATIONWIDGETBASE_H
#define UI_QGSANNOTATIONWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <qgsmaplayercombobox.h>
#include "qgscollapsiblegroupbox.h"
#include "qgsdoublespinbox.h"
#include "qgssymbolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAnnotationWidgetBase
{
public:
    QGridLayout *gridLayout;
    QgsSymbolButton *mFrameStyleButton;
    QLabel *mMapMarkerLabel_3;
    QCheckBox *mMapPositionFixedCheckBox;
    QgsCollapsibleGroupBox *mMarginsGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QgsDoubleSpinBox *mSpinTopMargin;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QgsDoubleSpinBox *mSpinLeftMargin;
    QgsDoubleSpinBox *mSpinRightMargin;
    QgsDoubleSpinBox *mSpinBottomMargin;
    QSpacerItem *verticalSpacer;
    QgsMapLayerComboBox *mLayerComboBox;
    QLabel *mMapMarkerLabel;
    QgsSymbolButton *mMapMarkerButton;
    QLabel *mMapMarkerLabel_2;

    void setupUi(QWidget *QgsAnnotationWidgetBase)
    {
        if (QgsAnnotationWidgetBase->objectName().isEmpty())
            QgsAnnotationWidgetBase->setObjectName(QString::fromUtf8("QgsAnnotationWidgetBase"));
        QgsAnnotationWidgetBase->resize(319, 402);
        QgsAnnotationWidgetBase->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(QgsAnnotationWidgetBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mFrameStyleButton = new QgsSymbolButton(QgsAnnotationWidgetBase);
        mFrameStyleButton->setObjectName(QString::fromUtf8("mFrameStyleButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mFrameStyleButton->sizePolicy().hasHeightForWidth());
        mFrameStyleButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mFrameStyleButton, 3, 1, 1, 1);

        mMapMarkerLabel_3 = new QLabel(QgsAnnotationWidgetBase);
        mMapMarkerLabel_3->setObjectName(QString::fromUtf8("mMapMarkerLabel_3"));

        gridLayout->addWidget(mMapMarkerLabel_3, 3, 0, 1, 1);

        mMapPositionFixedCheckBox = new QCheckBox(QgsAnnotationWidgetBase);
        mMapPositionFixedCheckBox->setObjectName(QString::fromUtf8("mMapPositionFixedCheckBox"));

        gridLayout->addWidget(mMapPositionFixedCheckBox, 0, 0, 1, 2);

        mMarginsGroupBox = new QgsCollapsibleGroupBox(QgsAnnotationWidgetBase);
        mMarginsGroupBox->setObjectName(QString::fromUtf8("mMarginsGroupBox"));
        gridLayout_2 = new QGridLayout(mMarginsGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(mMarginsGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        mSpinTopMargin = new QgsDoubleSpinBox(mMarginsGroupBox);
        mSpinTopMargin->setObjectName(QString::fromUtf8("mSpinTopMargin"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mSpinTopMargin->sizePolicy().hasHeightForWidth());
        mSpinTopMargin->setSizePolicy(sizePolicy1);
        mSpinTopMargin->setDecimals(2);
        mSpinTopMargin->setMaximum(10000000.000000000000000);
        mSpinTopMargin->setSingleStep(0.200000000000000);
        mSpinTopMargin->setValue(1.000000000000000);

        gridLayout_2->addWidget(mSpinTopMargin, 0, 1, 1, 1);

        label_4 = new QLabel(mMarginsGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(mMarginsGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(mMarginsGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        mSpinLeftMargin = new QgsDoubleSpinBox(mMarginsGroupBox);
        mSpinLeftMargin->setObjectName(QString::fromUtf8("mSpinLeftMargin"));
        sizePolicy1.setHeightForWidth(mSpinLeftMargin->sizePolicy().hasHeightForWidth());
        mSpinLeftMargin->setSizePolicy(sizePolicy1);
        mSpinLeftMargin->setDecimals(2);
        mSpinLeftMargin->setMaximum(10000000.000000000000000);
        mSpinLeftMargin->setSingleStep(0.200000000000000);
        mSpinLeftMargin->setValue(1.000000000000000);

        gridLayout_2->addWidget(mSpinLeftMargin, 1, 1, 1, 1);

        mSpinRightMargin = new QgsDoubleSpinBox(mMarginsGroupBox);
        mSpinRightMargin->setObjectName(QString::fromUtf8("mSpinRightMargin"));
        sizePolicy1.setHeightForWidth(mSpinRightMargin->sizePolicy().hasHeightForWidth());
        mSpinRightMargin->setSizePolicy(sizePolicy1);
        mSpinRightMargin->setDecimals(2);
        mSpinRightMargin->setMaximum(10000000.000000000000000);
        mSpinRightMargin->setSingleStep(0.200000000000000);
        mSpinRightMargin->setValue(1.000000000000000);

        gridLayout_2->addWidget(mSpinRightMargin, 2, 1, 1, 1);

        mSpinBottomMargin = new QgsDoubleSpinBox(mMarginsGroupBox);
        mSpinBottomMargin->setObjectName(QString::fromUtf8("mSpinBottomMargin"));
        sizePolicy1.setHeightForWidth(mSpinBottomMargin->sizePolicy().hasHeightForWidth());
        mSpinBottomMargin->setSizePolicy(sizePolicy1);
        mSpinBottomMargin->setDecimals(2);
        mSpinBottomMargin->setMaximum(10000000.000000000000000);
        mSpinBottomMargin->setSingleStep(0.200000000000000);
        mSpinBottomMargin->setValue(1.000000000000000);

        gridLayout_2->addWidget(mSpinBottomMargin, 3, 1, 1, 1);


        gridLayout->addWidget(mMarginsGroupBox, 5, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);

        mLayerComboBox = new QgsMapLayerComboBox(QgsAnnotationWidgetBase);
        mLayerComboBox->setObjectName(QString::fromUtf8("mLayerComboBox"));

        gridLayout->addWidget(mLayerComboBox, 1, 1, 1, 1);

        mMapMarkerLabel = new QLabel(QgsAnnotationWidgetBase);
        mMapMarkerLabel->setObjectName(QString::fromUtf8("mMapMarkerLabel"));

        gridLayout->addWidget(mMapMarkerLabel, 2, 0, 1, 1);

        mMapMarkerButton = new QgsSymbolButton(QgsAnnotationWidgetBase);
        mMapMarkerButton->setObjectName(QString::fromUtf8("mMapMarkerButton"));
        sizePolicy.setHeightForWidth(mMapMarkerButton->sizePolicy().hasHeightForWidth());
        mMapMarkerButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mMapMarkerButton, 2, 1, 1, 1);

        mMapMarkerLabel_2 = new QLabel(QgsAnnotationWidgetBase);
        mMapMarkerLabel_2->setObjectName(QString::fromUtf8("mMapMarkerLabel_2"));

        gridLayout->addWidget(mMapMarkerLabel_2, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        mMapMarkerLabel_3->setBuddy(mMapMarkerButton);
        mMapMarkerLabel->setBuddy(mMapMarkerButton);
        mMapMarkerLabel_2->setBuddy(mMapMarkerButton);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(mMapPositionFixedCheckBox, mLayerComboBox);
        QWidget::setTabOrder(mLayerComboBox, mMapMarkerButton);

        retranslateUi(QgsAnnotationWidgetBase);

        QMetaObject::connectSlotsByName(QgsAnnotationWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsAnnotationWidgetBase)
    {
        mFrameStyleButton->setText(QString());
        mMapMarkerLabel_3->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Frame style", nullptr));
        mMapPositionFixedCheckBox->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Fixed map position", nullptr));
        mMarginsGroupBox->setTitle(QCoreApplication::translate("QgsAnnotationWidgetBase", "Contents Margins", nullptr));
        label->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Top", nullptr));
        mSpinTopMargin->setSuffix(QCoreApplication::translate("QgsAnnotationWidgetBase", " mm", nullptr));
        label_4->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Bottom", nullptr));
        label_2->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Left", nullptr));
        label_3->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Right", nullptr));
        mSpinLeftMargin->setSuffix(QCoreApplication::translate("QgsAnnotationWidgetBase", " mm", nullptr));
        mSpinRightMargin->setSuffix(QCoreApplication::translate("QgsAnnotationWidgetBase", " mm", nullptr));
        mSpinBottomMargin->setSuffix(QCoreApplication::translate("QgsAnnotationWidgetBase", " mm", nullptr));
#if QT_CONFIG(tooltip)
        mLayerComboBox->setToolTip(QCoreApplication::translate("QgsAnnotationWidgetBase", "Allows the annotation to be associated with a map layer. If set, the annotation will only be visible when the layer is visible.", nullptr));
#endif // QT_CONFIG(tooltip)
        mMapMarkerLabel->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Map marker", nullptr));
        mMapMarkerButton->setText(QString());
        mMapMarkerLabel_2->setText(QCoreApplication::translate("QgsAnnotationWidgetBase", "Linked layer", nullptr));
        (void)QgsAnnotationWidgetBase;
    } // retranslateUi

};

namespace Ui {
    class QgsAnnotationWidgetBase: public Ui_QgsAnnotationWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSANNOTATIONWIDGETBASE_H
