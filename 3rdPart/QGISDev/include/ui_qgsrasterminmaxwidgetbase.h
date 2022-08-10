/********************************************************************************
** Form generated from reading UI file 'qgsrasterminmaxwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSRASTERMINMAXWIDGETBASE_H
#define UI_QGSRASTERMINMAXWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgsdoublespinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsRasterMinMaxWidgetBase
{
public:
    QVBoxLayout *verticalLayout_3;
    QgsCollapsibleGroupBox *mLoadMinMaxValuesGroupBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QRadioButton *mUserDefinedRadioButton;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *mCumulativeCutRadioButton;
    QgsDoubleSpinBox *mCumulativeCutLowerDoubleSpinBox;
    QLabel *label;
    QgsDoubleSpinBox *mCumulativeCutUpperDoubleSpinBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *mStdDevRadioButton;
    QgsDoubleSpinBox *mStdDevSpinBox;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *mMinMaxRadioButton;
    QGridLayout *gridLayout_2;
    QComboBox *mStatisticsExtentCombo;
    QLabel *mStatisticsExtentLabel;
    QLabel *mAccuracyLabel;
    QComboBox *cboAccuracy;
    QButtonGroup *mMinMaxMethodRadioButtonGroup;

    void setupUi(QWidget *QgsRasterMinMaxWidgetBase)
    {
        if (QgsRasterMinMaxWidgetBase->objectName().isEmpty())
            QgsRasterMinMaxWidgetBase->setObjectName(QString::fromUtf8("QgsRasterMinMaxWidgetBase"));
        QgsRasterMinMaxWidgetBase->resize(324, 250);
        QgsRasterMinMaxWidgetBase->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout_3 = new QVBoxLayout(QgsRasterMinMaxWidgetBase);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mLoadMinMaxValuesGroupBox = new QgsCollapsibleGroupBox(QgsRasterMinMaxWidgetBase);
        mLoadMinMaxValuesGroupBox->setObjectName(QString::fromUtf8("mLoadMinMaxValuesGroupBox"));
        mLoadMinMaxValuesGroupBox->setFlat(true);
        mLoadMinMaxValuesGroupBox->setCheckable(false);
        mLoadMinMaxValuesGroupBox->setProperty("collapsed", QVariant(true));
        mLoadMinMaxValuesGroupBox->setProperty("saveCollapsedState", QVariant(false));
        verticalLayout_4 = new QVBoxLayout(mLoadMinMaxValuesGroupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mUserDefinedRadioButton = new QRadioButton(mLoadMinMaxValuesGroupBox);
        mMinMaxMethodRadioButtonGroup = new QButtonGroup(QgsRasterMinMaxWidgetBase);
        mMinMaxMethodRadioButtonGroup->setObjectName(QString::fromUtf8("mMinMaxMethodRadioButtonGroup"));
        mMinMaxMethodRadioButtonGroup->addButton(mUserDefinedRadioButton);
        mUserDefinedRadioButton->setObjectName(QString::fromUtf8("mUserDefinedRadioButton"));
        mUserDefinedRadioButton->setChecked(true);

        gridLayout->addWidget(mUserDefinedRadioButton, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mCumulativeCutRadioButton = new QRadioButton(mLoadMinMaxValuesGroupBox);
        mMinMaxMethodRadioButtonGroup->addButton(mCumulativeCutRadioButton);
        mCumulativeCutRadioButton->setObjectName(QString::fromUtf8("mCumulativeCutRadioButton"));
        mCumulativeCutRadioButton->setChecked(false);

        horizontalLayout_4->addWidget(mCumulativeCutRadioButton);

        mCumulativeCutLowerDoubleSpinBox = new QgsDoubleSpinBox(mLoadMinMaxValuesGroupBox);
        mCumulativeCutLowerDoubleSpinBox->setObjectName(QString::fromUtf8("mCumulativeCutLowerDoubleSpinBox"));
        mCumulativeCutLowerDoubleSpinBox->setDecimals(1);

        horizontalLayout_4->addWidget(mCumulativeCutLowerDoubleSpinBox);

        label = new QLabel(mLoadMinMaxValuesGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        mCumulativeCutUpperDoubleSpinBox = new QgsDoubleSpinBox(mLoadMinMaxValuesGroupBox);
        mCumulativeCutUpperDoubleSpinBox->setObjectName(QString::fromUtf8("mCumulativeCutUpperDoubleSpinBox"));
        mCumulativeCutUpperDoubleSpinBox->setDecimals(1);

        horizontalLayout_4->addWidget(mCumulativeCutUpperDoubleSpinBox);

        label_2 = new QLabel(mLoadMinMaxValuesGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_8 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        mStdDevRadioButton = new QRadioButton(mLoadMinMaxValuesGroupBox);
        mMinMaxMethodRadioButtonGroup->addButton(mStdDevRadioButton);
        mStdDevRadioButton->setObjectName(QString::fromUtf8("mStdDevRadioButton"));

        horizontalLayout_6->addWidget(mStdDevRadioButton);

        mStdDevSpinBox = new QgsDoubleSpinBox(mLoadMinMaxValuesGroupBox);
        mStdDevSpinBox->setObjectName(QString::fromUtf8("mStdDevSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mStdDevSpinBox->sizePolicy().hasHeightForWidth());
        mStdDevSpinBox->setSizePolicy(sizePolicy);
        mStdDevSpinBox->setValue(1.000000000000000);

        horizontalLayout_6->addWidget(mStdDevSpinBox);

        horizontalSpacer_6 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        mMinMaxRadioButton = new QRadioButton(mLoadMinMaxValuesGroupBox);
        mMinMaxMethodRadioButtonGroup->addButton(mMinMaxRadioButton);
        mMinMaxRadioButton->setObjectName(QString::fromUtf8("mMinMaxRadioButton"));

        gridLayout->addWidget(mMinMaxRadioButton, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mStatisticsExtentCombo = new QComboBox(mLoadMinMaxValuesGroupBox);
        mStatisticsExtentCombo->addItem(QString());
        mStatisticsExtentCombo->addItem(QString());
        mStatisticsExtentCombo->addItem(QString());
        mStatisticsExtentCombo->setObjectName(QString::fromUtf8("mStatisticsExtentCombo"));

        gridLayout_2->addWidget(mStatisticsExtentCombo, 0, 1, 1, 1);

        mStatisticsExtentLabel = new QLabel(mLoadMinMaxValuesGroupBox);
        mStatisticsExtentLabel->setObjectName(QString::fromUtf8("mStatisticsExtentLabel"));
        mStatisticsExtentLabel->setMargin(0);

        gridLayout_2->addWidget(mStatisticsExtentLabel, 0, 0, 1, 1);

        mAccuracyLabel = new QLabel(mLoadMinMaxValuesGroupBox);
        mAccuracyLabel->setObjectName(QString::fromUtf8("mAccuracyLabel"));

        gridLayout_2->addWidget(mAccuracyLabel, 1, 0, 1, 1);

        cboAccuracy = new QComboBox(mLoadMinMaxValuesGroupBox);
        cboAccuracy->addItem(QString());
        cboAccuracy->addItem(QString());
        cboAccuracy->setObjectName(QString::fromUtf8("cboAccuracy"));

        gridLayout_2->addWidget(cboAccuracy, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 6, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);


        verticalLayout_3->addWidget(mLoadMinMaxValuesGroupBox);

        QWidget::setTabOrder(mUserDefinedRadioButton, mCumulativeCutRadioButton);
        QWidget::setTabOrder(mCumulativeCutRadioButton, mCumulativeCutLowerDoubleSpinBox);
        QWidget::setTabOrder(mCumulativeCutLowerDoubleSpinBox, mCumulativeCutUpperDoubleSpinBox);
        QWidget::setTabOrder(mCumulativeCutUpperDoubleSpinBox, mMinMaxRadioButton);
        QWidget::setTabOrder(mMinMaxRadioButton, mStdDevRadioButton);
        QWidget::setTabOrder(mStdDevRadioButton, mStdDevSpinBox);

        retranslateUi(QgsRasterMinMaxWidgetBase);

        QMetaObject::connectSlotsByName(QgsRasterMinMaxWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsRasterMinMaxWidgetBase)
    {
        mLoadMinMaxValuesGroupBox->setTitle(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Min / Max Value Settings", nullptr));
        mUserDefinedRadioButton->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Use&r defined", nullptr));
        mCumulativeCutRadioButton->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Cumula&tive\n"
"count cut", nullptr));
        label->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "-", nullptr));
        label_2->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "%", nullptr));
        mStdDevRadioButton->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Mean +/-\n"
"standard de&viation \303\227", nullptr));
        mMinMaxRadioButton->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "&Min / max", nullptr));
        mStatisticsExtentCombo->setItemText(0, QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Whole raster", nullptr));
        mStatisticsExtentCombo->setItemText(1, QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Current canvas", nullptr));
        mStatisticsExtentCombo->setItemText(2, QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Updated canvas", nullptr));

        mStatisticsExtentLabel->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Statistics extent", nullptr));
        mAccuracyLabel->setText(QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Accuracy", nullptr));
        cboAccuracy->setItemText(0, QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Estimate (faster)", nullptr));
        cboAccuracy->setItemText(1, QCoreApplication::translate("QgsRasterMinMaxWidgetBase", "Actual (slower)", nullptr));

        (void)QgsRasterMinMaxWidgetBase;
    } // retranslateUi

};

namespace Ui {
    class QgsRasterMinMaxWidgetBase: public Ui_QgsRasterMinMaxWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSRASTERMINMAXWIDGETBASE_H
