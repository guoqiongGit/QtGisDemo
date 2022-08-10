/********************************************************************************
** Form generated from reading UI file 'qgsaddtaborgroupbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSADDTABORGROUPBASE_H
#define UI_QGSADDTABORGROUPBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAddTabOrGroupBase
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *mName;
    QLabel *label_2;
    QRadioButton *mTabButton;
    QRadioButton *mGroupButton;
    QComboBox *mTabList;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QgsSpinBox *mColumnCountSpinBox;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *QgsAddTabOrGroupBase)
    {
        if (QgsAddTabOrGroupBase->objectName().isEmpty())
            QgsAddTabOrGroupBase->setObjectName(QString::fromUtf8("QgsAddTabOrGroupBase"));
        QgsAddTabOrGroupBase->resize(447, 238);
        QgsAddTabOrGroupBase->setWindowTitle(QString::fromUtf8("Dialog"));
        formLayout = new QFormLayout(QgsAddTabOrGroupBase);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(QgsAddTabOrGroupBase);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        mName = new QLineEdit(QgsAddTabOrGroupBase);
        mName->setObjectName(QString::fromUtf8("mName"));

        gridLayout->addWidget(mName, 0, 1, 1, 2);

        label_2 = new QLabel(QgsAddTabOrGroupBase);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        mTabButton = new QRadioButton(QgsAddTabOrGroupBase);
        buttonGroup = new QButtonGroup(QgsAddTabOrGroupBase);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(mTabButton);
        mTabButton->setObjectName(QString::fromUtf8("mTabButton"));
        mTabButton->setChecked(true);

        gridLayout->addWidget(mTabButton, 1, 0, 1, 2);

        mGroupButton = new QRadioButton(QgsAddTabOrGroupBase);
        buttonGroup->addButton(mGroupButton);
        mGroupButton->setObjectName(QString::fromUtf8("mGroupButton"));
        mGroupButton->setChecked(false);

        gridLayout->addWidget(mGroupButton, 2, 0, 1, 2);

        mTabList = new QComboBox(QgsAddTabOrGroupBase);
        mTabList->setObjectName(QString::fromUtf8("mTabList"));
        mTabList->setEnabled(true);

        gridLayout->addWidget(mTabList, 2, 2, 1, 2);


        formLayout->setLayout(0, QFormLayout::SpanningRole, gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer);

        label_3 = new QLabel(QgsAddTabOrGroupBase);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        mColumnCountSpinBox = new QgsSpinBox(QgsAddTabOrGroupBase);
        mColumnCountSpinBox->setObjectName(QString::fromUtf8("mColumnCountSpinBox"));
        mColumnCountSpinBox->setMinimum(1);
        mColumnCountSpinBox->setMaximum(5);

        formLayout->setWidget(1, QFormLayout::FieldRole, mColumnCountSpinBox);

        buttonBox = new QDialogButtonBox(QgsAddTabOrGroupBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        formLayout->setWidget(4, QFormLayout::SpanningRole, buttonBox);

        QWidget::setTabOrder(mName, mTabButton);
        QWidget::setTabOrder(mTabButton, mGroupButton);
        QWidget::setTabOrder(mGroupButton, mTabList);
        QWidget::setTabOrder(mTabList, mColumnCountSpinBox);

        retranslateUi(QgsAddTabOrGroupBase);
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsAddTabOrGroupBase, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsAddTabOrGroupBase, SLOT(reject()));

        QMetaObject::connectSlotsByName(QgsAddTabOrGroupBase);
    } // setupUi

    void retranslateUi(QDialog *QgsAddTabOrGroupBase)
    {
        label->setText(QCoreApplication::translate("QgsAddTabOrGroupBase", "Create container", nullptr));
        label_2->setText(QCoreApplication::translate("QgsAddTabOrGroupBase", "as", nullptr));
        mTabButton->setText(QCoreApplication::translate("QgsAddTabOrGroupBase", "a tab", nullptr));
        mGroupButton->setText(QCoreApplication::translate("QgsAddTabOrGroupBase", "a group in container", nullptr));
        label_3->setText(QCoreApplication::translate("QgsAddTabOrGroupBase", "Number of columns", nullptr));
        (void)QgsAddTabOrGroupBase;
    } // retranslateUi

};

namespace Ui {
    class QgsAddTabOrGroupBase: public Ui_QgsAddTabOrGroupBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSADDTABORGROUPBASE_H
