/********************************************************************************
** Form generated from reading UI file 'qgsvectorlayersavestyledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSVECTORLAYERSAVESTYLEDIALOG_H
#define UI_QGSVECTORLAYERSAVESTYLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>
#include "qgsfilewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsVectorLayerSaveStyleDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *mModeLabel;
    QWidget *mSaveToDbWidget;
    QGridLayout *gridLayout_3;
    QLabel *nameLabel;
    QLineEdit *mDbStyleNameEdit;
    QLabel *descriptionLabel;
    QPlainTextEdit *mDbStyleDescriptionEdit;
    QLabel *mUILabel;
    QCheckBox *mDbStyleUseAsDefault;
    QgsFileWidget *mDbStyleUIFileWidget;
    QComboBox *mStyleTypeComboBox;
    QWidget *mSaveToFileWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label;
    QListView *mStyleCategoriesListView;
    QgsFileWidget *mFileWidget;
    QDialogButtonBox *buttonBox;
    QListWidget *mStylesWidget;
    QLabel *mStylesWidgetLabel;

    void setupUi(QDialog *QgsVectorLayerSaveStyleDialog)
    {
        if (QgsVectorLayerSaveStyleDialog->objectName().isEmpty())
            QgsVectorLayerSaveStyleDialog->setObjectName(QString::fromUtf8("QgsVectorLayerSaveStyleDialog"));
        QgsVectorLayerSaveStyleDialog->resize(491, 535);
        gridLayout = new QGridLayout(QgsVectorLayerSaveStyleDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mModeLabel = new QLabel(QgsVectorLayerSaveStyleDialog);
        mModeLabel->setObjectName(QString::fromUtf8("mModeLabel"));

        gridLayout->addWidget(mModeLabel, 0, 0, 1, 1);

        mSaveToDbWidget = new QWidget(QgsVectorLayerSaveStyleDialog);
        mSaveToDbWidget->setObjectName(QString::fromUtf8("mSaveToDbWidget"));
        gridLayout_3 = new QGridLayout(mSaveToDbWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(mSaveToDbWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        gridLayout_3->addWidget(nameLabel, 0, 0, 1, 1);

        mDbStyleNameEdit = new QLineEdit(mSaveToDbWidget);
        mDbStyleNameEdit->setObjectName(QString::fromUtf8("mDbStyleNameEdit"));

        gridLayout_3->addWidget(mDbStyleNameEdit, 0, 1, 1, 1);

        descriptionLabel = new QLabel(mSaveToDbWidget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        gridLayout_3->addWidget(descriptionLabel, 1, 0, 1, 1);

        mDbStyleDescriptionEdit = new QPlainTextEdit(mSaveToDbWidget);
        mDbStyleDescriptionEdit->setObjectName(QString::fromUtf8("mDbStyleDescriptionEdit"));

        gridLayout_3->addWidget(mDbStyleDescriptionEdit, 1, 1, 1, 1);

        mUILabel = new QLabel(mSaveToDbWidget);
        mUILabel->setObjectName(QString::fromUtf8("mUILabel"));

        gridLayout_3->addWidget(mUILabel, 2, 0, 1, 1);

        mDbStyleUseAsDefault = new QCheckBox(mSaveToDbWidget);
        mDbStyleUseAsDefault->setObjectName(QString::fromUtf8("mDbStyleUseAsDefault"));

        gridLayout_3->addWidget(mDbStyleUseAsDefault, 3, 1, 1, 1);

        mDbStyleUIFileWidget = new QgsFileWidget(mSaveToDbWidget);
        mDbStyleUIFileWidget->setObjectName(QString::fromUtf8("mDbStyleUIFileWidget"));

        gridLayout_3->addWidget(mDbStyleUIFileWidget, 2, 1, 1, 1);


        gridLayout->addWidget(mSaveToDbWidget, 3, 0, 1, 2);

        mStyleTypeComboBox = new QComboBox(QgsVectorLayerSaveStyleDialog);
        mStyleTypeComboBox->setObjectName(QString::fromUtf8("mStyleTypeComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mStyleTypeComboBox->sizePolicy().hasHeightForWidth());
        mStyleTypeComboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mStyleTypeComboBox, 0, 1, 1, 1);

        mSaveToFileWidget = new QWidget(QgsVectorLayerSaveStyleDialog);
        mSaveToFileWidget->setObjectName(QString::fromUtf8("mSaveToFileWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mSaveToFileWidget->sizePolicy().hasHeightForWidth());
        mSaveToFileWidget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(mSaveToFileWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(mSaveToFileWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(mSaveToFileWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        mStyleCategoriesListView = new QListView(mSaveToFileWidget);
        mStyleCategoriesListView->setObjectName(QString::fromUtf8("mStyleCategoriesListView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mStyleCategoriesListView->sizePolicy().hasHeightForWidth());
        mStyleCategoriesListView->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(mStyleCategoriesListView, 2, 1, 1, 1);

        mFileWidget = new QgsFileWidget(mSaveToFileWidget);
        mFileWidget->setObjectName(QString::fromUtf8("mFileWidget"));

        gridLayout_2->addWidget(mFileWidget, 0, 1, 1, 1);


        gridLayout->addWidget(mSaveToFileWidget, 2, 0, 1, 2);

        buttonBox = new QDialogButtonBox(QgsVectorLayerSaveStyleDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);

        mStylesWidget = new QListWidget(QgsVectorLayerSaveStyleDialog);
        mStylesWidget->setObjectName(QString::fromUtf8("mStylesWidget"));

        gridLayout->addWidget(mStylesWidget, 1, 1, 1, 1);

        mStylesWidgetLabel = new QLabel(QgsVectorLayerSaveStyleDialog);
        mStylesWidgetLabel->setObjectName(QString::fromUtf8("mStylesWidgetLabel"));

        gridLayout->addWidget(mStylesWidgetLabel, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        nameLabel->setBuddy(mDbStyleNameEdit);
        mUILabel->setBuddy(mDbStyleNameEdit);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(mStyleTypeComboBox, mStylesWidget);
        QWidget::setTabOrder(mStylesWidget, mStyleCategoriesListView);
        QWidget::setTabOrder(mStyleCategoriesListView, mDbStyleNameEdit);
        QWidget::setTabOrder(mDbStyleNameEdit, mDbStyleDescriptionEdit);
        QWidget::setTabOrder(mDbStyleDescriptionEdit, mDbStyleUseAsDefault);

        retranslateUi(QgsVectorLayerSaveStyleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsVectorLayerSaveStyleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsVectorLayerSaveStyleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QgsVectorLayerSaveStyleDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsVectorLayerSaveStyleDialog)
    {
        QgsVectorLayerSaveStyleDialog->setWindowTitle(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Save Layer Style", nullptr));
        mModeLabel->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Save style", nullptr));
        nameLabel->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Style name", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Description", nullptr));
        mUILabel->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "UI", nullptr));
        mDbStyleUseAsDefault->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Use as default style for this layer", nullptr));
#if QT_CONFIG(tooltip)
        mDbStyleUIFileWidget->setToolTip(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Optionally pick an input form for attribute editing (QT Designer UI format), it will be stored in the database", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Categories", nullptr));
        label->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "File", nullptr));
        mStylesWidgetLabel->setText(QCoreApplication::translate("QgsVectorLayerSaveStyleDialog", "Styles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsVectorLayerSaveStyleDialog: public Ui_QgsVectorLayerSaveStyleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSVECTORLAYERSAVESTYLEDIALOG_H
