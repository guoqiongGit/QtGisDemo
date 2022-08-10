/********************************************************************************
** Form generated from reading UI file 'qgspointcloudelevationpropertieswidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSPOINTCLOUDELEVATIONPROPERTIESWIDGETBASE_H
#define UI_QGSPOINTCLOUDELEVATIONPROPERTIESWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgsdoublespinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsPointCloudElevationPropertiesWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QgsCollapsibleGroupBox *mCrsGroupBox_2;
    QGridLayout *gridLayout_2;
    QgsDoubleSpinBox *mOffsetZSpinBox;
    QFrame *line_3;
    QgsDoubleSpinBox *mScaleZSpinBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *mShifPointCloudZAxisButton;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QgsPointCloudElevationPropertiesWidgetBase)
    {
        if (QgsPointCloudElevationPropertiesWidgetBase->objectName().isEmpty())
            QgsPointCloudElevationPropertiesWidgetBase->setObjectName(QString::fromUtf8("QgsPointCloudElevationPropertiesWidgetBase"));
        QgsPointCloudElevationPropertiesWidgetBase->resize(400, 270);
        verticalLayout = new QVBoxLayout(QgsPointCloudElevationPropertiesWidgetBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mCrsGroupBox_2 = new QgsCollapsibleGroupBox(QgsPointCloudElevationPropertiesWidgetBase);
        mCrsGroupBox_2->setObjectName(QString::fromUtf8("mCrsGroupBox_2"));
        mCrsGroupBox_2->setFocusPolicy(Qt::StrongFocus);
        mCrsGroupBox_2->setCheckable(false);
        mCrsGroupBox_2->setProperty("syncGroup", QVariant(QString::fromUtf8("vectorgeneral")));
        gridLayout_2 = new QGridLayout(mCrsGroupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mOffsetZSpinBox = new QgsDoubleSpinBox(mCrsGroupBox_2);
        mOffsetZSpinBox->setObjectName(QString::fromUtf8("mOffsetZSpinBox"));
        mOffsetZSpinBox->setDecimals(6);
        mOffsetZSpinBox->setMinimum(-99999999999.000000000000000);
        mOffsetZSpinBox->setMaximum(99999999999.000000000000000);

        gridLayout_2->addWidget(mOffsetZSpinBox, 2, 1, 1, 1);

        line_3 = new QFrame(mCrsGroupBox_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 3, 0, 1, 1);

        mScaleZSpinBox = new QgsDoubleSpinBox(mCrsGroupBox_2);
        mScaleZSpinBox->setObjectName(QString::fromUtf8("mScaleZSpinBox"));
        mScaleZSpinBox->setDecimals(6);
        mScaleZSpinBox->setMinimum(0.000000000000000);
        mScaleZSpinBox->setMaximum(99999999999.000000000000000);
        mScaleZSpinBox->setValue(1.000000000000000);

        gridLayout_2->addWidget(mScaleZSpinBox, 1, 1, 1, 1);

        label = new QLabel(mCrsGroupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(mCrsGroupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        mShifPointCloudZAxisButton = new QPushButton(mCrsGroupBox_2);
        mShifPointCloudZAxisButton->setObjectName(QString::fromUtf8("mShifPointCloudZAxisButton"));
        mShifPointCloudZAxisButton->setMinimumSize(QSize(24, 24));
        mShifPointCloudZAxisButton->setMaximumSize(QSize(24, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::On);
        mShifPointCloudZAxisButton->setIcon(icon);

        gridLayout_2->addWidget(mShifPointCloudZAxisButton, 2, 2, 1, 1);

        label_3 = new QLabel(mCrsGroupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(true);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 3);


        verticalLayout->addWidget(mCrsGroupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(mCrsGroupBox_2, mScaleZSpinBox);
        QWidget::setTabOrder(mScaleZSpinBox, mOffsetZSpinBox);
        QWidget::setTabOrder(mOffsetZSpinBox, mShifPointCloudZAxisButton);

        retranslateUi(QgsPointCloudElevationPropertiesWidgetBase);

        QMetaObject::connectSlotsByName(QgsPointCloudElevationPropertiesWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsPointCloudElevationPropertiesWidgetBase)
    {
        QgsPointCloudElevationPropertiesWidgetBase->setWindowTitle(QCoreApplication::translate("QgsPointCloudElevationPropertiesWidgetBase", "Point Cloud Elevation Properties", nullptr));
        mCrsGroupBox_2->setTitle(QCoreApplication::translate("QgsPointCloudElevationPropertiesWidgetBase", "Elevation", nullptr));
        label->setText(QCoreApplication::translate("QgsPointCloudElevationPropertiesWidgetBase", "Offset", nullptr));
        label_2->setText(QCoreApplication::translate("QgsPointCloudElevationPropertiesWidgetBase", "Scale", nullptr));
#if QT_CONFIG(tooltip)
        mShifPointCloudZAxisButton->setToolTip(QCoreApplication::translate("QgsPointCloudElevationPropertiesWidgetBase", "Automatically sets the offset so that the lowest point in the cloud sits at an elevation of 0.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("QgsPointCloudElevationPropertiesWidgetBase", "<html><head/><body><p><span style=\" font-weight:600;\">Elevation scaling and offset can be used to manually correct elevation values in the point cloud at render time.</span></p><p>The scale is applied to the point cloud elevation values before adding the offset.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsPointCloudElevationPropertiesWidgetBase: public Ui_QgsPointCloudElevationPropertiesWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSPOINTCLOUDELEVATIONPROPERTIESWIDGETBASE_H
