/********************************************************************************
** Form generated from reading UI file 'qgsattributeformcontaineredit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSATTRIBUTEFORMCONTAINEREDIT_H
#define UI_QGSATTRIBUTEFORMCONTAINEREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgscolorbutton.h"
#include "qgsfieldexpressionwidget.h"
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAttributeFormContainerEdit
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QCheckBox *mShowLabelCheckBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QgsCollapsibleGroupBox *mControlVisibilityGroupBox;
    QGridLayout *gridLayout_2;
    QgsFieldExpressionWidget *mVisibilityExpressionWidget;
    QgsSpinBox *mColumnCountSpinBox;
    QLineEdit *mTitleLineEdit;
    QCheckBox *mShowAsGroupBoxCheckBox;
    QgsCollapsibleGroupBox *mGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QgsColorButton *mBackgroundColorButton;

    void setupUi(QWidget *QgsAttributeFormContainerEdit)
    {
        if (QgsAttributeFormContainerEdit->objectName().isEmpty())
            QgsAttributeFormContainerEdit->setObjectName(QString::fromUtf8("QgsAttributeFormContainerEdit"));
        QgsAttributeFormContainerEdit->resize(401, 303);
        QgsAttributeFormContainerEdit->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(QgsAttributeFormContainerEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(QgsAttributeFormContainerEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        mShowLabelCheckBox = new QCheckBox(QgsAttributeFormContainerEdit);
        mShowLabelCheckBox->setObjectName(QString::fromUtf8("mShowLabelCheckBox"));

        gridLayout->addWidget(mShowLabelCheckBox, 0, 0, 1, 2);

        label = new QLabel(QgsAttributeFormContainerEdit);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        mControlVisibilityGroupBox = new QgsCollapsibleGroupBox(QgsAttributeFormContainerEdit);
        mControlVisibilityGroupBox->setObjectName(QString::fromUtf8("mControlVisibilityGroupBox"));
        mControlVisibilityGroupBox->setCheckable(true);
        gridLayout_2 = new QGridLayout(mControlVisibilityGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mVisibilityExpressionWidget = new QgsFieldExpressionWidget(mControlVisibilityGroupBox);
        mVisibilityExpressionWidget->setObjectName(QString::fromUtf8("mVisibilityExpressionWidget"));

        gridLayout_2->addWidget(mVisibilityExpressionWidget, 0, 0, 1, 1);


        gridLayout->addWidget(mControlVisibilityGroupBox, 4, 0, 1, 3);

        mColumnCountSpinBox = new QgsSpinBox(QgsAttributeFormContainerEdit);
        mColumnCountSpinBox->setObjectName(QString::fromUtf8("mColumnCountSpinBox"));
        mColumnCountSpinBox->setMinimum(1);
        mColumnCountSpinBox->setMaximum(10);

        gridLayout->addWidget(mColumnCountSpinBox, 3, 1, 1, 1);

        mTitleLineEdit = new QLineEdit(QgsAttributeFormContainerEdit);
        mTitleLineEdit->setObjectName(QString::fromUtf8("mTitleLineEdit"));

        gridLayout->addWidget(mTitleLineEdit, 2, 1, 1, 1);

        mShowAsGroupBoxCheckBox = new QCheckBox(QgsAttributeFormContainerEdit);
        mShowAsGroupBoxCheckBox->setObjectName(QString::fromUtf8("mShowAsGroupBoxCheckBox"));

        gridLayout->addWidget(mShowAsGroupBoxCheckBox, 1, 0, 1, 2);

        mGroupBox = new QgsCollapsibleGroupBox(QgsAttributeFormContainerEdit);
        mGroupBox->setObjectName(QString::fromUtf8("mGroupBox"));
        gridLayout_3 = new QGridLayout(mGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(mGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        mBackgroundColorButton = new QgsColorButton(mGroupBox);
        mBackgroundColorButton->setObjectName(QString::fromUtf8("mBackgroundColorButton"));

        gridLayout_3->addWidget(mBackgroundColorButton, 1, 1, 1, 1);


        gridLayout->addWidget(mGroupBox, 5, 0, 1, 2);

        QWidget::setTabOrder(mShowLabelCheckBox, mShowAsGroupBoxCheckBox);
        QWidget::setTabOrder(mShowAsGroupBoxCheckBox, mTitleLineEdit);
        QWidget::setTabOrder(mTitleLineEdit, mColumnCountSpinBox);
        QWidget::setTabOrder(mColumnCountSpinBox, mControlVisibilityGroupBox);
        QWidget::setTabOrder(mControlVisibilityGroupBox, mBackgroundColorButton);

        retranslateUi(QgsAttributeFormContainerEdit);

        QMetaObject::connectSlotsByName(QgsAttributeFormContainerEdit);
    } // setupUi

    void retranslateUi(QWidget *QgsAttributeFormContainerEdit)
    {
        label_2->setText(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Columns", nullptr));
        mShowLabelCheckBox->setText(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Show label", nullptr));
        label->setText(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Title", nullptr));
        mControlVisibilityGroupBox->setTitle(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Control Visibility by Expression", nullptr));
        mShowAsGroupBoxCheckBox->setText(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Show as group box", nullptr));
        mGroupBox->setTitle(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Style", nullptr));
        label_3->setText(QCoreApplication::translate("QgsAttributeFormContainerEdit", "Background color", nullptr));
        (void)QgsAttributeFormContainerEdit;
    } // retranslateUi

};

namespace Ui {
    class QgsAttributeFormContainerEdit: public Ui_QgsAttributeFormContainerEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSATTRIBUTEFORMCONTAINEREDIT_H
