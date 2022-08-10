/********************************************************************************
** Form generated from reading UI file 'qgsdecorationgriddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSDECORATIONGRIDDIALOG_H
#define UI_QGSDECORATIONGRIDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qgsdoublespinbox.h"
#include "qgsfontbutton.h"
#include "qgsspinbox.h"
#include "qgssymbolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsDecorationGridDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *grpEnable;
    QGridLayout *gridLayout_3;
    QLabel *mOffsetYLabel;
    QLabel *mOffsetXLabel;
    QgsDoubleSpinBox *mOffsetYEdit;
    QgsSymbolButton *mMarkerSymbolButton;
    QgsSymbolButton *mLineSymbolButton;
    QGridLayout *gridLayout_4;
    QPushButton *mPbtnUpdateFromLayer;
    QPushButton *mPbtnUpdateFromExtents;
    QgsDoubleSpinBox *mIntervalYEdit;
    QGroupBox *mDrawAnnotationCheckBox;
    QGridLayout *gridLayout;
    QgsSpinBox *mCoordinatePrecisionSpinBox;
    QgsDoubleSpinBox *mDistanceToMapFrameSpinBox;
    QComboBox *mAnnotationDirectionComboBox;
    QLabel *mCoordinatePrecisionLabel;
    QLabel *mDistanceToFrameLabel;
    QLabel *mAnnotationDirectionLabel;
    QgsFontButton *mAnnotationFontButton;
    QLabel *mAnnotationFontLabel;
    QgsDoubleSpinBox *mOffsetXEdit;
    QLabel *mUpdateIntervalOffsetLabel;
    QLabel *mLineSymbolLabel;
    QLabel *mGridTypeLabel;
    QgsDoubleSpinBox *mIntervalXEdit;
    QLabel *mIntervalXLabel;
    QLabel *mIntervalYLabel;
    QSpacerItem *verticalSpacer;
    QComboBox *mGridTypeComboBox;
    QLabel *mMarkerSymbolLabel;
    QLabel *label;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsDecorationGridDialog)
    {
        if (QgsDecorationGridDialog->objectName().isEmpty())
            QgsDecorationGridDialog->setObjectName(QString::fromUtf8("QgsDecorationGridDialog"));
        QgsDecorationGridDialog->resize(390, 548);
        verticalLayout = new QVBoxLayout(QgsDecorationGridDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        grpEnable = new QGroupBox(QgsDecorationGridDialog);
        grpEnable->setObjectName(QString::fromUtf8("grpEnable"));
        grpEnable->setCheckable(true);
        grpEnable->setChecked(false);
        gridLayout_3 = new QGridLayout(grpEnable);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mOffsetYLabel = new QLabel(grpEnable);
        mOffsetYLabel->setObjectName(QString::fromUtf8("mOffsetYLabel"));
        mOffsetYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mOffsetYLabel->setWordWrap(true);

        gridLayout_3->addWidget(mOffsetYLabel, 10, 1, 1, 1);

        mOffsetXLabel = new QLabel(grpEnable);
        mOffsetXLabel->setObjectName(QString::fromUtf8("mOffsetXLabel"));
        mOffsetXLabel->setWordWrap(true);

        gridLayout_3->addWidget(mOffsetXLabel, 9, 0, 2, 1);

        mOffsetYEdit = new QgsDoubleSpinBox(grpEnable);
        mOffsetYEdit->setObjectName(QString::fromUtf8("mOffsetYEdit"));
        mOffsetYEdit->setMinimum(-10000000000000000.000000000000000);
        mOffsetYEdit->setMaximum(10000000000000000.000000000000000);

        gridLayout_3->addWidget(mOffsetYEdit, 10, 2, 1, 1);

        mMarkerSymbolButton = new QgsSymbolButton(grpEnable);
        mMarkerSymbolButton->setObjectName(QString::fromUtf8("mMarkerSymbolButton"));
        mMarkerSymbolButton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mMarkerSymbolButton->sizePolicy().hasHeightForWidth());
        mMarkerSymbolButton->setSizePolicy(sizePolicy);
        mMarkerSymbolButton->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(mMarkerSymbolButton, 2, 2, 1, 1);

        mLineSymbolButton = new QgsSymbolButton(grpEnable);
        mLineSymbolButton->setObjectName(QString::fromUtf8("mLineSymbolButton"));
        mLineSymbolButton->setEnabled(false);
        sizePolicy.setHeightForWidth(mLineSymbolButton->sizePolicy().hasHeightForWidth());
        mLineSymbolButton->setSizePolicy(sizePolicy);
        mLineSymbolButton->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(mLineSymbolButton, 1, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(9, 0, 0, 9);
        mPbtnUpdateFromLayer = new QPushButton(grpEnable);
        mPbtnUpdateFromLayer->setObjectName(QString::fromUtf8("mPbtnUpdateFromLayer"));

        gridLayout_4->addWidget(mPbtnUpdateFromLayer, 0, 1, 1, 1);

        mPbtnUpdateFromExtents = new QPushButton(grpEnable);
        mPbtnUpdateFromExtents->setObjectName(QString::fromUtf8("mPbtnUpdateFromExtents"));

        gridLayout_4->addWidget(mPbtnUpdateFromExtents, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 13, 0, 1, 3);

        mIntervalYEdit = new QgsDoubleSpinBox(grpEnable);
        mIntervalYEdit->setObjectName(QString::fromUtf8("mIntervalYEdit"));
        mIntervalYEdit->setMaximum(10000000000000000.000000000000000);

        gridLayout_3->addWidget(mIntervalYEdit, 7, 2, 1, 1);

        mDrawAnnotationCheckBox = new QGroupBox(grpEnable);
        mDrawAnnotationCheckBox->setObjectName(QString::fromUtf8("mDrawAnnotationCheckBox"));
        mDrawAnnotationCheckBox->setFlat(false);
        mDrawAnnotationCheckBox->setCheckable(true);
        mDrawAnnotationCheckBox->setChecked(false);
        gridLayout = new QGridLayout(mDrawAnnotationCheckBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        mCoordinatePrecisionSpinBox = new QgsSpinBox(mDrawAnnotationCheckBox);
        mCoordinatePrecisionSpinBox->setObjectName(QString::fromUtf8("mCoordinatePrecisionSpinBox"));

        gridLayout->addWidget(mCoordinatePrecisionSpinBox, 3, 1, 1, 1);

        mDistanceToMapFrameSpinBox = new QgsDoubleSpinBox(mDrawAnnotationCheckBox);
        mDistanceToMapFrameSpinBox->setObjectName(QString::fromUtf8("mDistanceToMapFrameSpinBox"));

        gridLayout->addWidget(mDistanceToMapFrameSpinBox, 2, 1, 1, 1);

        mAnnotationDirectionComboBox = new QComboBox(mDrawAnnotationCheckBox);
        mAnnotationDirectionComboBox->setObjectName(QString::fromUtf8("mAnnotationDirectionComboBox"));

        gridLayout->addWidget(mAnnotationDirectionComboBox, 0, 1, 1, 1);

        mCoordinatePrecisionLabel = new QLabel(mDrawAnnotationCheckBox);
        mCoordinatePrecisionLabel->setObjectName(QString::fromUtf8("mCoordinatePrecisionLabel"));
        mCoordinatePrecisionLabel->setWordWrap(true);

        gridLayout->addWidget(mCoordinatePrecisionLabel, 3, 0, 1, 1);

        mDistanceToFrameLabel = new QLabel(mDrawAnnotationCheckBox);
        mDistanceToFrameLabel->setObjectName(QString::fromUtf8("mDistanceToFrameLabel"));
        mDistanceToFrameLabel->setWordWrap(true);

        gridLayout->addWidget(mDistanceToFrameLabel, 2, 0, 1, 1);

        mAnnotationDirectionLabel = new QLabel(mDrawAnnotationCheckBox);
        mAnnotationDirectionLabel->setObjectName(QString::fromUtf8("mAnnotationDirectionLabel"));
        mAnnotationDirectionLabel->setFrameShape(QFrame::NoFrame);
        mAnnotationDirectionLabel->setWordWrap(true);

        gridLayout->addWidget(mAnnotationDirectionLabel, 0, 0, 1, 1);

        mAnnotationFontButton = new QgsFontButton(mDrawAnnotationCheckBox);
        mAnnotationFontButton->setObjectName(QString::fromUtf8("mAnnotationFontButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mAnnotationFontButton->sizePolicy().hasHeightForWidth());
        mAnnotationFontButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(mAnnotationFontButton, 1, 1, 1, 1);

        mAnnotationFontLabel = new QLabel(mDrawAnnotationCheckBox);
        mAnnotationFontLabel->setObjectName(QString::fromUtf8("mAnnotationFontLabel"));

        gridLayout->addWidget(mAnnotationFontLabel, 1, 0, 1, 1);


        gridLayout_3->addWidget(mDrawAnnotationCheckBox, 22, 0, 1, 3);

        mOffsetXEdit = new QgsDoubleSpinBox(grpEnable);
        mOffsetXEdit->setObjectName(QString::fromUtf8("mOffsetXEdit"));
        sizePolicy1.setHeightForWidth(mOffsetXEdit->sizePolicy().hasHeightForWidth());
        mOffsetXEdit->setSizePolicy(sizePolicy1);
        mOffsetXEdit->setMinimum(-10000000000000000.000000000000000);
        mOffsetXEdit->setMaximum(10000000000000000.000000000000000);

        gridLayout_3->addWidget(mOffsetXEdit, 9, 2, 1, 1);

        mUpdateIntervalOffsetLabel = new QLabel(grpEnable);
        mUpdateIntervalOffsetLabel->setObjectName(QString::fromUtf8("mUpdateIntervalOffsetLabel"));

        gridLayout_3->addWidget(mUpdateIntervalOffsetLabel, 12, 0, 1, 3);

        mLineSymbolLabel = new QLabel(grpEnable);
        mLineSymbolLabel->setObjectName(QString::fromUtf8("mLineSymbolLabel"));
        mLineSymbolLabel->setWordWrap(true);

        gridLayout_3->addWidget(mLineSymbolLabel, 1, 0, 1, 2);

        mGridTypeLabel = new QLabel(grpEnable);
        mGridTypeLabel->setObjectName(QString::fromUtf8("mGridTypeLabel"));
        mGridTypeLabel->setWordWrap(true);

        gridLayout_3->addWidget(mGridTypeLabel, 0, 0, 1, 2);

        mIntervalXEdit = new QgsDoubleSpinBox(grpEnable);
        mIntervalXEdit->setObjectName(QString::fromUtf8("mIntervalXEdit"));
        mIntervalXEdit->setMaximum(10000000000000000.000000000000000);

        gridLayout_3->addWidget(mIntervalXEdit, 4, 2, 1, 1);

        mIntervalXLabel = new QLabel(grpEnable);
        mIntervalXLabel->setObjectName(QString::fromUtf8("mIntervalXLabel"));
        mIntervalXLabel->setWordWrap(true);

        gridLayout_3->addWidget(mIntervalXLabel, 4, 0, 4, 1);

        mIntervalYLabel = new QLabel(grpEnable);
        mIntervalYLabel->setObjectName(QString::fromUtf8("mIntervalYLabel"));
        mIntervalYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mIntervalYLabel->setWordWrap(true);

        gridLayout_3->addWidget(mIntervalYLabel, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 23, 0, 1, 3);

        mGridTypeComboBox = new QComboBox(grpEnable);
        mGridTypeComboBox->setObjectName(QString::fromUtf8("mGridTypeComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mGridTypeComboBox->sizePolicy().hasHeightForWidth());
        mGridTypeComboBox->setSizePolicy(sizePolicy2);
        mGridTypeComboBox->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(mGridTypeComboBox, 0, 2, 1, 1);

        mMarkerSymbolLabel = new QLabel(grpEnable);
        mMarkerSymbolLabel->setObjectName(QString::fromUtf8("mMarkerSymbolLabel"));
        mMarkerSymbolLabel->setWordWrap(true);

        gridLayout_3->addWidget(mMarkerSymbolLabel, 2, 0, 1, 2);

        label = new QLabel(grpEnable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 9, 1, 1, 1);

        label_2 = new QLabel(grpEnable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 4, 1, 1, 1);


        verticalLayout->addWidget(grpEnable);

        buttonBox = new QDialogButtonBox(QgsDecorationGridDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(grpEnable, mGridTypeComboBox);
        QWidget::setTabOrder(mGridTypeComboBox, mLineSymbolButton);
        QWidget::setTabOrder(mLineSymbolButton, mMarkerSymbolButton);
        QWidget::setTabOrder(mMarkerSymbolButton, mIntervalXEdit);
        QWidget::setTabOrder(mIntervalXEdit, mIntervalYEdit);
        QWidget::setTabOrder(mIntervalYEdit, mOffsetXEdit);
        QWidget::setTabOrder(mOffsetXEdit, mOffsetYEdit);
        QWidget::setTabOrder(mOffsetYEdit, mPbtnUpdateFromExtents);
        QWidget::setTabOrder(mPbtnUpdateFromExtents, mPbtnUpdateFromLayer);
        QWidget::setTabOrder(mPbtnUpdateFromLayer, mDrawAnnotationCheckBox);
        QWidget::setTabOrder(mDrawAnnotationCheckBox, mAnnotationDirectionComboBox);
        QWidget::setTabOrder(mAnnotationDirectionComboBox, mAnnotationFontButton);
        QWidget::setTabOrder(mAnnotationFontButton, mDistanceToMapFrameSpinBox);
        QWidget::setTabOrder(mDistanceToMapFrameSpinBox, mCoordinatePrecisionSpinBox);

        retranslateUi(QgsDecorationGridDialog);

        QMetaObject::connectSlotsByName(QgsDecorationGridDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsDecorationGridDialog)
    {
        QgsDecorationGridDialog->setWindowTitle(QCoreApplication::translate("QgsDecorationGridDialog", "Grid Properties", nullptr));
        grpEnable->setTitle(QCoreApplication::translate("QgsDecorationGridDialog", "Enable Grid", nullptr));
        mOffsetYLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Y", nullptr));
        mOffsetXLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Offset", nullptr));
        mMarkerSymbolButton->setText(QString());
        mLineSymbolButton->setText(QString());
        mPbtnUpdateFromLayer->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Active Raster Layer", nullptr));
        mPbtnUpdateFromExtents->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Canvas Extents", nullptr));
        mDrawAnnotationCheckBox->setTitle(QCoreApplication::translate("QgsDecorationGridDialog", "Draw Annotation", nullptr));
        mCoordinatePrecisionLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Coordinate precision", nullptr));
        mDistanceToFrameLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Distance to map frame", nullptr));
        mAnnotationDirectionLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Annotation direction", nullptr));
        mAnnotationFontButton->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Font", nullptr));
        mAnnotationFontLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Annotation font", nullptr));
        mUpdateIntervalOffsetLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Update Interval / Offset from", nullptr));
        mLineSymbolLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Line symbol", nullptr));
        mGridTypeLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Grid type", nullptr));
        mIntervalXLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Interval", nullptr));
        mIntervalYLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Y", nullptr));
        mMarkerSymbolLabel->setText(QCoreApplication::translate("QgsDecorationGridDialog", "Marker symbol", nullptr));
        label->setText(QCoreApplication::translate("QgsDecorationGridDialog", "X", nullptr));
        label_2->setText(QCoreApplication::translate("QgsDecorationGridDialog", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsDecorationGridDialog: public Ui_QgsDecorationGridDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSDECORATIONGRIDDIALOG_H
