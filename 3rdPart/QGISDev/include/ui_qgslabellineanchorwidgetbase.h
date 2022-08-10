/********************************************************************************
** Form generated from reading UI file 'qgslabellineanchorwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSLABELLINEANCHORWIDGETBASE_H
#define UI_QGSLABELLINEANCHORWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include "qgsdoublespinbox.h"
#include "qgspanelwidget.h"
#include "qgspropertyoverridebutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsLabelLineAnchorWidgetBase
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QComboBox *mClippingComboBox;
    QLabel *label_2;
    QLabel *label;
    QgsPropertyOverrideButton *mLineClippingDDBtn;
    QGridLayout *gridLayout_2;
    QgsPropertyOverrideButton *mLinePlacementDDBtn;
    QgsDoubleSpinBox *mCustomPlacementSpinBox;
    QComboBox *mPercentPlacementComboBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *mAnchorTypeComboBox;
    QLabel *mAnchorTypeHintLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QgsPanelWidget *QgsLabelLineAnchorWidgetBase)
    {
        if (QgsLabelLineAnchorWidgetBase->objectName().isEmpty())
            QgsLabelLineAnchorWidgetBase->setObjectName(QString::fromUtf8("QgsLabelLineAnchorWidgetBase"));
        QgsLabelLineAnchorWidgetBase->resize(271, 315);
        QgsLabelLineAnchorWidgetBase->setWindowTitle(QString::fromUtf8("Obstacle Settings"));
        gridLayout = new QGridLayout(QgsLabelLineAnchorWidgetBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(QgsLabelLineAnchorWidgetBase);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mClippingComboBox = new QComboBox(groupBox);
        mClippingComboBox->setObjectName(QString::fromUtf8("mClippingComboBox"));

        gridLayout_4->addWidget(mClippingComboBox, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        gridLayout_4->addWidget(label, 0, 0, 1, 2);

        mLineClippingDDBtn = new QgsPropertyOverrideButton(groupBox);
        mLineClippingDDBtn->setObjectName(QString::fromUtf8("mLineClippingDDBtn"));

        gridLayout_4->addWidget(mLineClippingDDBtn, 2, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 10, -1, -1);
        mLinePlacementDDBtn = new QgsPropertyOverrideButton(groupBox);
        mLinePlacementDDBtn->setObjectName(QString::fromUtf8("mLinePlacementDDBtn"));

        gridLayout_2->addWidget(mLinePlacementDDBtn, 0, 2, 1, 1);

        mCustomPlacementSpinBox = new QgsDoubleSpinBox(groupBox);
        mCustomPlacementSpinBox->setObjectName(QString::fromUtf8("mCustomPlacementSpinBox"));
        mCustomPlacementSpinBox->setMaximum(100.000000000000000);

        gridLayout_2->addWidget(mCustomPlacementSpinBox, 1, 0, 1, 3);

        mPercentPlacementComboBox = new QComboBox(groupBox);
        mPercentPlacementComboBox->setObjectName(QString::fromUtf8("mPercentPlacementComboBox"));

        gridLayout_2->addWidget(mPercentPlacementComboBox, 0, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 3);

        gridLayout_4->setColumnStretch(1, 1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_2 = new QGroupBox(QgsLabelLineAnchorWidgetBase);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mAnchorTypeComboBox = new QComboBox(groupBox_2);
        mAnchorTypeComboBox->setObjectName(QString::fromUtf8("mAnchorTypeComboBox"));

        gridLayout_3->addWidget(mAnchorTypeComboBox, 0, 0, 1, 1);

        mAnchorTypeHintLabel = new QLabel(groupBox_2);
        mAnchorTypeHintLabel->setObjectName(QString::fromUtf8("mAnchorTypeHintLabel"));
        mAnchorTypeHintLabel->setWordWrap(true);

        gridLayout_3->addWidget(mAnchorTypeHintLabel, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        QWidget::setTabOrder(mPercentPlacementComboBox, mLinePlacementDDBtn);
        QWidget::setTabOrder(mLinePlacementDDBtn, mCustomPlacementSpinBox);
        QWidget::setTabOrder(mCustomPlacementSpinBox, mAnchorTypeComboBox);

        retranslateUi(QgsLabelLineAnchorWidgetBase);

        QMetaObject::connectSlotsByName(QgsLabelLineAnchorWidgetBase);
    } // setupUi

    void retranslateUi(QgsPanelWidget *QgsLabelLineAnchorWidgetBase)
    {
        groupBox->setTitle(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "Label Anchoring", nullptr));
        label_2->setText(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "Clipping", nullptr));
        label->setText(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "<b>Controls the position along the line which labels will be placed close to.</b>", nullptr));
        mLineClippingDDBtn->setText(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "\342\200\246", nullptr));
        mLinePlacementDDBtn->setText(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "\342\200\246", nullptr));
        mCustomPlacementSpinBox->setSuffix(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", " %", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "Placement Behavior", nullptr));
        mAnchorTypeHintLabel->setText(QCoreApplication::translate("QgsLabelLineAnchorWidgetBase", "Hint", nullptr));
        (void)QgsLabelLineAnchorWidgetBase;
    } // retranslateUi

};

namespace Ui {
    class QgsLabelLineAnchorWidgetBase: public Ui_QgsLabelLineAnchorWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSLABELLINEANCHORWIDGETBASE_H
