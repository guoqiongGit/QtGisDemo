/********************************************************************************
** Form generated from reading UI file 'qgsrelationeditorconfigwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSRELATIONEDITORCONFIGWIDGETBASE_H
#define UI_QGSRELATIONEDITORCONFIGWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QgsRelationEditorConfigWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *mShowFirstFeature;
    QGroupBox *mButtonsVisibility;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *mRelationShowLinkCheckBox;
    QCheckBox *mRelationShowUnlinkCheckBox;
    QCheckBox *mRelationShowSaveChildEditsCheckBox;
    QCheckBox *mRelationShowAddChildCheckBox;
    QCheckBox *mRelationShowDuplicateChildFeatureCheckBox;
    QCheckBox *mRelationDeleteChildFeatureCheckBox;
    QCheckBox *mRelationShowZoomToFeatureCheckBox;

    void setupUi(QWidget *QgsRelationEditorConfigWidgetBase)
    {
        if (QgsRelationEditorConfigWidgetBase->objectName().isEmpty())
            QgsRelationEditorConfigWidgetBase->setObjectName(QString::fromUtf8("QgsRelationEditorConfigWidgetBase"));
        QgsRelationEditorConfigWidgetBase->resize(274, 215);
        verticalLayout = new QVBoxLayout(QgsRelationEditorConfigWidgetBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mShowFirstFeature = new QCheckBox(QgsRelationEditorConfigWidgetBase);
        mShowFirstFeature->setObjectName(QString::fromUtf8("mShowFirstFeature"));

        verticalLayout->addWidget(mShowFirstFeature);

        mButtonsVisibility = new QGroupBox(QgsRelationEditorConfigWidgetBase);
        mButtonsVisibility->setObjectName(QString::fromUtf8("mButtonsVisibility"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(mButtonsVisibility->sizePolicy().hasHeightForWidth());
        mButtonsVisibility->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(mButtonsVisibility);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mRelationShowLinkCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationShowLinkCheckBox->setObjectName(QString::fromUtf8("mRelationShowLinkCheckBox"));

        verticalLayout_2->addWidget(mRelationShowLinkCheckBox);

        mRelationShowUnlinkCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationShowUnlinkCheckBox->setObjectName(QString::fromUtf8("mRelationShowUnlinkCheckBox"));

        verticalLayout_2->addWidget(mRelationShowUnlinkCheckBox);

        mRelationShowSaveChildEditsCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationShowSaveChildEditsCheckBox->setObjectName(QString::fromUtf8("mRelationShowSaveChildEditsCheckBox"));

        verticalLayout_2->addWidget(mRelationShowSaveChildEditsCheckBox);

        mRelationShowAddChildCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationShowAddChildCheckBox->setObjectName(QString::fromUtf8("mRelationShowAddChildCheckBox"));

        verticalLayout_2->addWidget(mRelationShowAddChildCheckBox);

        mRelationShowDuplicateChildFeatureCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationShowDuplicateChildFeatureCheckBox->setObjectName(QString::fromUtf8("mRelationShowDuplicateChildFeatureCheckBox"));

        verticalLayout_2->addWidget(mRelationShowDuplicateChildFeatureCheckBox);

        mRelationDeleteChildFeatureCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationDeleteChildFeatureCheckBox->setObjectName(QString::fromUtf8("mRelationDeleteChildFeatureCheckBox"));

        verticalLayout_2->addWidget(mRelationDeleteChildFeatureCheckBox);

        mRelationShowZoomToFeatureCheckBox = new QCheckBox(mButtonsVisibility);
        mRelationShowZoomToFeatureCheckBox->setObjectName(QString::fromUtf8("mRelationShowZoomToFeatureCheckBox"));

        verticalLayout_2->addWidget(mRelationShowZoomToFeatureCheckBox);


        verticalLayout->addWidget(mButtonsVisibility);


        retranslateUi(QgsRelationEditorConfigWidgetBase);

        QMetaObject::connectSlotsByName(QgsRelationEditorConfigWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsRelationEditorConfigWidgetBase)
    {
        QgsRelationEditorConfigWidgetBase->setWindowTitle(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Attribute Widget Relation Edit Widget", nullptr));
        mShowFirstFeature->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Automatically select first child feature and show attribute form", nullptr));
#if QT_CONFIG(tooltip)
        mShowFirstFeature->setToolTip(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Unchecking this can lead to faster loading time of attribute forms and avoid unnecessary queries.", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonsVisibility->setTitle(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Toolbar settings", nullptr));
        mRelationShowLinkCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Show link button", nullptr));
        mRelationShowUnlinkCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Show unlink button", nullptr));
        mRelationShowSaveChildEditsCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Show save child layer edits button", nullptr));
        mRelationShowAddChildCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Add child feature button", nullptr));
        mRelationShowDuplicateChildFeatureCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Duplicate child feature button", nullptr));
        mRelationDeleteChildFeatureCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Delete child feature button", nullptr));
        mRelationShowZoomToFeatureCheckBox->setText(QCoreApplication::translate("QgsRelationEditorConfigWidgetBase", "Zoom to child feature button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsRelationEditorConfigWidgetBase: public Ui_QgsRelationEditorConfigWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSRELATIONEDITORCONFIGWIDGETBASE_H
