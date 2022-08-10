/********************************************************************************
** Form generated from reading UI file 'qgscustomprojectiondialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSCUSTOMPROJECTIONDIALOGBASE_H
#define UI_QGSCUSTOMPROJECTIONDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgsscrollarea.h"

QT_BEGIN_NAMESPACE

class Ui_QgsCustomProjectionDialogBase
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QgsCollapsibleGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QGridLayout *gridLayout_4;
    QPushButton *mButtonValidate;
    QPushButton *pbnCopyCRS;
    QSpacerItem *verticalSpacer_2;
    QPlainTextEdit *teParameters;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *leNameList;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbnAdd;
    QPushButton *pbnRemove;
    QSpacerItem *verticalSpacer;
    QLineEdit *leName;
    QLabel *label_4;
    QComboBox *mFormatComboBox;
    QLabel *label_5;
    QgsCollapsibleGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QLabel *textLabel2_2_2;
    QLabel *label_2;
    QLabel *textLabel1_3;
    QLabel *textLabel2_3;
    QLabel *textLabel2_2;
    QLineEdit *northWGS84;
    QLabel *projectedX;
    QLineEdit *eastWGS84;
    QLabel *projectedY;
    QPushButton *pbnCalculate;

    void setupUi(QDialog *QgsCustomProjectionDialogBase)
    {
        if (QgsCustomProjectionDialogBase->objectName().isEmpty())
            QgsCustomProjectionDialogBase->setObjectName(QString::fromUtf8("QgsCustomProjectionDialogBase"));
        QgsCustomProjectionDialogBase->resize(542, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        QgsCustomProjectionDialogBase->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(QgsCustomProjectionDialogBase);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(QgsCustomProjectionDialogBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        scrollArea = new QgsScrollArea(QgsCustomProjectionDialogBase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFocusPolicy(Qt::NoFocus);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 536, 615));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        gridLayout_3->addWidget(label, 0, 0, 1, 3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mButtonValidate = new QPushButton(groupBox);
        mButtonValidate->setObjectName(QString::fromUtf8("mButtonValidate"));

        gridLayout_4->addWidget(mButtonValidate, 0, 2, 1, 1);

        pbnCopyCRS = new QPushButton(groupBox);
        pbnCopyCRS->setObjectName(QString::fromUtf8("pbnCopyCRS"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCopy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnCopyCRS->setIcon(icon1);

        gridLayout_4->addWidget(pbnCopyCRS, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 2, 1, 1);

        teParameters = new QPlainTextEdit(groupBox);
        teParameters->setObjectName(QString::fromUtf8("teParameters"));

        gridLayout_4->addWidget(teParameters, 0, 0, 2, 1);


        gridLayout_3->addLayout(gridLayout_4, 4, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leNameList = new QTreeWidget(groupBox);
        leNameList->setObjectName(QString::fromUtf8("leNameList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leNameList->sizePolicy().hasHeightForWidth());
        leNameList->setSizePolicy(sizePolicy);
        leNameList->setAlternatingRowColors(true);
        leNameList->setSortingEnabled(false);
        leNameList->header()->setProperty("showSortIndicator", QVariant(false));

        horizontalLayout->addWidget(leNameList);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pbnAdd = new QPushButton(groupBox);
        pbnAdd->setObjectName(QString::fromUtf8("pbnAdd"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/symbologyAdd.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnAdd->setIcon(icon2);

        verticalLayout_2->addWidget(pbnAdd);

        pbnRemove = new QPushButton(groupBox);
        pbnRemove->setObjectName(QString::fromUtf8("pbnRemove"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/symbologyRemove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnRemove->setIcon(icon3);

        verticalLayout_2->addWidget(pbnRemove);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 3);

        leName = new QLineEdit(groupBox);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout_3->addWidget(leName, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        mFormatComboBox = new QComboBox(groupBox);
        mFormatComboBox->setObjectName(QString::fromUtf8("mFormatComboBox"));

        gridLayout_3->addWidget(mFormatComboBox, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        gridLayout_3->setRowStretch(1, 3);
        gridLayout_3->setRowStretch(3, 1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setProperty("collapsed", QVariant(true));
        gridLayout1 = new QGridLayout(groupBox_2);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        textLabel2_2_2 = new QLabel(groupBox_2);
        textLabel2_2_2->setObjectName(QString::fromUtf8("textLabel2_2_2"));

        gridLayout1->addWidget(textLabel2_2_2, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        gridLayout1->addWidget(label_2, 0, 0, 1, 3);

        textLabel1_3 = new QLabel(groupBox_2);
        textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));

        gridLayout1->addWidget(textLabel1_3, 1, 1, 1, 1);

        textLabel2_3 = new QLabel(groupBox_2);
        textLabel2_3->setObjectName(QString::fromUtf8("textLabel2_3"));

        gridLayout1->addWidget(textLabel2_3, 1, 2, 1, 1);

        textLabel2_2 = new QLabel(groupBox_2);
        textLabel2_2->setObjectName(QString::fromUtf8("textLabel2_2"));

        gridLayout1->addWidget(textLabel2_2, 2, 0, 1, 1);

        northWGS84 = new QLineEdit(groupBox_2);
        northWGS84->setObjectName(QString::fromUtf8("northWGS84"));
        northWGS84->setEnabled(true);

        gridLayout1->addWidget(northWGS84, 2, 1, 1, 1);

        projectedX = new QLabel(groupBox_2);
        projectedX->setObjectName(QString::fromUtf8("projectedX"));
        projectedX->setEnabled(true);
        projectedX->setFrameShape(QFrame::Box);

        gridLayout1->addWidget(projectedX, 2, 2, 1, 1);

        eastWGS84 = new QLineEdit(groupBox_2);
        eastWGS84->setObjectName(QString::fromUtf8("eastWGS84"));

        gridLayout1->addWidget(eastWGS84, 3, 1, 1, 1);

        projectedY = new QLabel(groupBox_2);
        projectedY->setObjectName(QString::fromUtf8("projectedY"));
        projectedY->setEnabled(true);
        projectedY->setFrameShape(QFrame::Box);
        projectedY->setMargin(1);

        gridLayout1->addWidget(projectedY, 3, 2, 1, 1);

        pbnCalculate = new QPushButton(groupBox_2);
        pbnCalculate->setObjectName(QString::fromUtf8("pbnCalculate"));

        gridLayout1->addWidget(pbnCalculate, 4, 0, 1, 3);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        textLabel2_2_2->setBuddy(eastWGS84);
        textLabel2_2->setBuddy(northWGS84);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(leNameList, pbnAdd);
        QWidget::setTabOrder(pbnAdd, pbnRemove);
        QWidget::setTabOrder(pbnRemove, leName);
        QWidget::setTabOrder(leName, mFormatComboBox);
        QWidget::setTabOrder(mFormatComboBox, teParameters);
        QWidget::setTabOrder(teParameters, pbnCopyCRS);
        QWidget::setTabOrder(pbnCopyCRS, mButtonValidate);
        QWidget::setTabOrder(mButtonValidate, northWGS84);
        QWidget::setTabOrder(northWGS84, eastWGS84);
        QWidget::setTabOrder(eastWGS84, pbnCalculate);

        retranslateUi(QgsCustomProjectionDialogBase);
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsCustomProjectionDialogBase, SLOT(reject()));

        QMetaObject::connectSlotsByName(QgsCustomProjectionDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsCustomProjectionDialogBase)
    {
        QgsCustomProjectionDialogBase->setWindowTitle(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Custom Coordinate Reference System Definition", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Define", nullptr));
        label->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "You can define your own custom Coordinate Reference System (CRS) here. The definition must conform to a WKT or Proj string format for specifying a CRS.", nullptr));
#if QT_CONFIG(tooltip)
        mButtonValidate->setToolTip(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Validate the current CRS definition and test whether it is an acceptable projection definition", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonValidate->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "&Validate", nullptr));
#if QT_CONFIG(tooltip)
        pbnCopyCRS->setToolTip(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Copy parameters from existing CRS", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnCopyCRS->setText(QString());
        label_3->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Name", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = leNameList->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("QgsCustomProjectionDialogBase", "Parameters", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("QgsCustomProjectionDialogBase", "ID", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("QgsCustomProjectionDialogBase", "Name", nullptr));
#if QT_CONFIG(tooltip)
        pbnAdd->setToolTip(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Add new CRS", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnAdd->setText(QString());
#if QT_CONFIG(tooltip)
        pbnRemove->setToolTip(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Remove CRS", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnRemove->setText(QString());
        label_4->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Parameters", nullptr));
        label_5->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Format", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Test", nullptr));
        textLabel2_2_2->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "East", nullptr));
        label_2->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Use the text boxes below to test the CRS definition you are creating. Enter a coordinate where both the lat/long and the transformed result are known (for example by reading off a map). Then press the calculate button to see if the CRS definition you are creating is accurate.", nullptr));
        textLabel1_3->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Geographic / WGS84", nullptr));
        textLabel2_3->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Destination CRS        ", nullptr));
        textLabel2_2->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "North", nullptr));
        projectedX->setText(QString());
        projectedY->setText(QString());
        pbnCalculate->setText(QCoreApplication::translate("QgsCustomProjectionDialogBase", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsCustomProjectionDialogBase: public Ui_QgsCustomProjectionDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSCUSTOMPROJECTIONDIALOGBASE_H
