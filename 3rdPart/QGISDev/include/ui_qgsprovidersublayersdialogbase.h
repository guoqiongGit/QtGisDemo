/********************************************************************************
** Form generated from reading UI file 'qgsprovidersublayersdialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSPROVIDERSUBLAYERSDIALOGBASE_H
#define UI_QGSPROVIDERSUBLAYERSDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include "qgsfilterlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_QgsProviderSublayersDialogBase
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *mButtonBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *mBtnSelectAll;
    QPushButton *mBtnDeselectAll;
    QSpacerItem *horizontalSpacer;
    QLabel *mLblFilePath;
    QCheckBox *mCheckShowSystem;
    QVBoxLayout *verticalLayout;
    QgsFilterLineEdit *mSearchLineEdit;
    QTreeView *mLayersTree;
    QCheckBox *mCbxAddToGroup;

    void setupUi(QDialog *QgsProviderSublayersDialogBase)
    {
        if (QgsProviderSublayersDialogBase->objectName().isEmpty())
            QgsProviderSublayersDialogBase->setObjectName(QString::fromUtf8("QgsProviderSublayersDialogBase"));
        QgsProviderSublayersDialogBase->resize(584, 236);
        gridLayout = new QGridLayout(QgsProviderSublayersDialogBase);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        mButtonBox = new QDialogButtonBox(QgsProviderSublayersDialogBase);
        mButtonBox->setObjectName(QString::fromUtf8("mButtonBox"));
        mButtonBox->setOrientation(Qt::Horizontal);
        mButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(mButtonBox, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mBtnSelectAll = new QPushButton(QgsProviderSublayersDialogBase);
        mBtnSelectAll->setObjectName(QString::fromUtf8("mBtnSelectAll"));

        horizontalLayout->addWidget(mBtnSelectAll);

        mBtnDeselectAll = new QPushButton(QgsProviderSublayersDialogBase);
        mBtnDeselectAll->setObjectName(QString::fromUtf8("mBtnDeselectAll"));

        horizontalLayout->addWidget(mBtnDeselectAll);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        mLblFilePath = new QLabel(QgsProviderSublayersDialogBase);
        mLblFilePath->setObjectName(QString::fromUtf8("mLblFilePath"));
        mLblFilePath->setWordWrap(true);
        mLblFilePath->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout->addWidget(mLblFilePath, 0, 0, 1, 1);

        mCheckShowSystem = new QCheckBox(QgsProviderSublayersDialogBase);
        mCheckShowSystem->setObjectName(QString::fromUtf8("mCheckShowSystem"));

        gridLayout->addWidget(mCheckShowSystem, 6, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        mSearchLineEdit = new QgsFilterLineEdit(QgsProviderSublayersDialogBase);
        mSearchLineEdit->setObjectName(QString::fromUtf8("mSearchLineEdit"));

        verticalLayout->addWidget(mSearchLineEdit);

        mLayersTree = new QTreeView(QgsProviderSublayersDialogBase);
        mLayersTree->setObjectName(QString::fromUtf8("mLayersTree"));
        mLayersTree->setSelectionMode(QAbstractItemView::ExtendedSelection);
        mLayersTree->setSelectionBehavior(QAbstractItemView::SelectRows);
        mLayersTree->setSortingEnabled(false);

        verticalLayout->addWidget(mLayersTree);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        mCbxAddToGroup = new QCheckBox(QgsProviderSublayersDialogBase);
        mCbxAddToGroup->setObjectName(QString::fromUtf8("mCbxAddToGroup"));

        gridLayout->addWidget(mCbxAddToGroup, 5, 0, 1, 1);

        QWidget::setTabOrder(mSearchLineEdit, mLayersTree);
        QWidget::setTabOrder(mLayersTree, mBtnSelectAll);
        QWidget::setTabOrder(mBtnSelectAll, mBtnDeselectAll);
        QWidget::setTabOrder(mBtnDeselectAll, mCbxAddToGroup);
        QWidget::setTabOrder(mCbxAddToGroup, mCheckShowSystem);

        retranslateUi(QgsProviderSublayersDialogBase);

        QMetaObject::connectSlotsByName(QgsProviderSublayersDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsProviderSublayersDialogBase)
    {
        QgsProviderSublayersDialogBase->setWindowTitle(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Select Layers to Load", nullptr));
        mBtnSelectAll->setText(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Select All", nullptr));
        mBtnDeselectAll->setText(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Deselect All", nullptr));
#if QT_CONFIG(tooltip)
        mLblFilePath->setToolTip(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Current file source", nullptr));
#endif // QT_CONFIG(tooltip)
        mCheckShowSystem->setText(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Show system and internal tables", nullptr));
        mSearchLineEdit->setPlaceholderText(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Search\342\200\246", nullptr));
        mCbxAddToGroup->setText(QCoreApplication::translate("QgsProviderSublayersDialogBase", "Add layers to a group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsProviderSublayersDialogBase: public Ui_QgsProviderSublayersDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSPROVIDERSUBLAYERSDIALOGBASE_H
