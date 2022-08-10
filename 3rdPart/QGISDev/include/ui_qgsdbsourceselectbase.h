/********************************************************************************
** Form generated from reading UI file 'qgsdbsourceselectbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSDBSOURCESELECTBASE_H
#define UI_QGSDBSOURCESELECTBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_QgsDbSourceSelectBase
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *connectionsGroupBox;
    QGridLayout *gridLayout;
    QComboBox *cmbConnections;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConnect;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnLoad;
    QPushButton *btnSave;
    QTreeView *mTablesTreeView;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbxAllowGeometrylessTables;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *mHoldDialogOpen;
    QGroupBox *mSearchGroupBox;
    QGridLayout *gridLayout1;
    QLabel *mSearchLabel;
    QLabel *mSearchModeLabel;
    QComboBox *mSearchModeComboBox;
    QLabel *mSearchColumnsLabel;
    QComboBox *mSearchColumnComboBox;
    QLineEdit *mSearchTableEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsDbSourceSelectBase)
    {
        if (QgsDbSourceSelectBase->objectName().isEmpty())
            QgsDbSourceSelectBase->setObjectName(QString::fromUtf8("QgsDbSourceSelectBase"));
        QgsDbSourceSelectBase->resize(773, 476);
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        QgsDbSourceSelectBase->setWindowIcon(icon);
        QgsDbSourceSelectBase->setSizeGripEnabled(true);
        QgsDbSourceSelectBase->setModal(true);
        gridLayout_2 = new QGridLayout(QgsDbSourceSelectBase);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        connectionsGroupBox = new QGroupBox(QgsDbSourceSelectBase);
        connectionsGroupBox->setObjectName(QString::fromUtf8("connectionsGroupBox"));
        gridLayout = new QGridLayout(connectionsGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cmbConnections = new QComboBox(connectionsGroupBox);
        cmbConnections->setObjectName(QString::fromUtf8("cmbConnections"));

        gridLayout->addWidget(cmbConnections, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnConnect = new QPushButton(connectionsGroupBox);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        horizontalLayout->addWidget(btnConnect);

        btnNew = new QPushButton(connectionsGroupBox);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        horizontalLayout->addWidget(btnNew);

        btnEdit = new QPushButton(connectionsGroupBox);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        horizontalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(connectionsGroupBox);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        horizontalLayout->addWidget(btnDelete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnLoad = new QPushButton(connectionsGroupBox);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        horizontalLayout->addWidget(btnLoad);

        btnSave = new QPushButton(connectionsGroupBox);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addWidget(connectionsGroupBox, 0, 0, 1, 1);

        mTablesTreeView = new QTreeView(QgsDbSourceSelectBase);
        mTablesTreeView->setObjectName(QString::fromUtf8("mTablesTreeView"));
        mTablesTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mTablesTreeView->setAlternatingRowColors(true);
        mTablesTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_2->addWidget(mTablesTreeView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cbxAllowGeometrylessTables = new QCheckBox(QgsDbSourceSelectBase);
        cbxAllowGeometrylessTables->setObjectName(QString::fromUtf8("cbxAllowGeometrylessTables"));

        horizontalLayout_2->addWidget(cbxAllowGeometrylessTables);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        mHoldDialogOpen = new QCheckBox(QgsDbSourceSelectBase);
        mHoldDialogOpen->setObjectName(QString::fromUtf8("mHoldDialogOpen"));

        horizontalLayout_2->addWidget(mHoldDialogOpen);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        mSearchGroupBox = new QGroupBox(QgsDbSourceSelectBase);
        mSearchGroupBox->setObjectName(QString::fromUtf8("mSearchGroupBox"));
        mSearchGroupBox->setFlat(true);
        mSearchGroupBox->setCheckable(true);
        mSearchGroupBox->setChecked(false);
        gridLayout1 = new QGridLayout(mSearchGroupBox);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setContentsMargins(9, 9, 9, 9);
        mSearchLabel = new QLabel(mSearchGroupBox);
        mSearchLabel->setObjectName(QString::fromUtf8("mSearchLabel"));
        mSearchLabel->setEnabled(true);

        gridLayout1->addWidget(mSearchLabel, 0, 0, 1, 1);

        mSearchModeLabel = new QLabel(mSearchGroupBox);
        mSearchModeLabel->setObjectName(QString::fromUtf8("mSearchModeLabel"));
        mSearchModeLabel->setEnabled(true);

        gridLayout1->addWidget(mSearchModeLabel, 2, 0, 1, 2);

        mSearchModeComboBox = new QComboBox(mSearchGroupBox);
        mSearchModeComboBox->setObjectName(QString::fromUtf8("mSearchModeComboBox"));
        mSearchModeComboBox->setEnabled(true);

        gridLayout1->addWidget(mSearchModeComboBox, 2, 2, 1, 1);

        mSearchColumnsLabel = new QLabel(mSearchGroupBox);
        mSearchColumnsLabel->setObjectName(QString::fromUtf8("mSearchColumnsLabel"));
        mSearchColumnsLabel->setEnabled(true);

        gridLayout1->addWidget(mSearchColumnsLabel, 1, 0, 1, 2);

        mSearchColumnComboBox = new QComboBox(mSearchGroupBox);
        mSearchColumnComboBox->setObjectName(QString::fromUtf8("mSearchColumnComboBox"));
        mSearchColumnComboBox->setEnabled(true);

        gridLayout1->addWidget(mSearchColumnComboBox, 1, 2, 1, 1);

        mSearchTableEdit = new QLineEdit(mSearchGroupBox);
        mSearchTableEdit->setObjectName(QString::fromUtf8("mSearchTableEdit"));
        mSearchTableEdit->setEnabled(true);

        gridLayout1->addWidget(mSearchTableEdit, 0, 1, 1, 2);


        gridLayout_2->addWidget(mSearchGroupBox, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QgsDbSourceSelectBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Help);

        gridLayout_2->addWidget(buttonBox, 4, 0, 1, 1);

#if QT_CONFIG(shortcut)
        mSearchLabel->setBuddy(mSearchTableEdit);
        mSearchModeLabel->setBuddy(mSearchModeComboBox);
        mSearchColumnsLabel->setBuddy(mSearchColumnComboBox);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(cmbConnections, btnConnect);
        QWidget::setTabOrder(btnConnect, btnNew);
        QWidget::setTabOrder(btnNew, btnEdit);
        QWidget::setTabOrder(btnEdit, btnDelete);
        QWidget::setTabOrder(btnDelete, btnLoad);
        QWidget::setTabOrder(btnLoad, btnSave);
        QWidget::setTabOrder(btnSave, mTablesTreeView);
        QWidget::setTabOrder(mTablesTreeView, cbxAllowGeometrylessTables);
        QWidget::setTabOrder(cbxAllowGeometrylessTables, mHoldDialogOpen);
        QWidget::setTabOrder(mHoldDialogOpen, mSearchGroupBox);
        QWidget::setTabOrder(mSearchGroupBox, mSearchTableEdit);
        QWidget::setTabOrder(mSearchTableEdit, mSearchColumnComboBox);
        QWidget::setTabOrder(mSearchColumnComboBox, mSearchModeComboBox);
        QWidget::setTabOrder(mSearchModeComboBox, buttonBox);

        retranslateUi(QgsDbSourceSelectBase);
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsDbSourceSelectBase, SLOT(reject()));
        QObject::connect(mSearchGroupBox, SIGNAL(toggled(bool)), mSearchTableEdit, SLOT(setVisible(bool)));
        QObject::connect(mSearchGroupBox, SIGNAL(toggled(bool)), mSearchColumnComboBox, SLOT(setVisible(bool)));
        QObject::connect(mSearchGroupBox, SIGNAL(toggled(bool)), mSearchModeComboBox, SLOT(setVisible(bool)));
        QObject::connect(mSearchGroupBox, SIGNAL(toggled(bool)), mSearchLabel, SLOT(setVisible(bool)));
        QObject::connect(mSearchGroupBox, SIGNAL(toggled(bool)), mSearchColumnsLabel, SLOT(setVisible(bool)));
        QObject::connect(mSearchGroupBox, SIGNAL(toggled(bool)), mSearchModeLabel, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(QgsDbSourceSelectBase);
    } // setupUi

    void retranslateUi(QDialog *QgsDbSourceSelectBase)
    {
        QgsDbSourceSelectBase->setWindowTitle(QCoreApplication::translate("QgsDbSourceSelectBase", "Add PostGIS Layers", nullptr));
        connectionsGroupBox->setTitle(QCoreApplication::translate("QgsDbSourceSelectBase", "Connections", nullptr));
#if QT_CONFIG(tooltip)
        btnConnect->setToolTip(QCoreApplication::translate("QgsDbSourceSelectBase", "Connect to selected database", nullptr));
#endif // QT_CONFIG(tooltip)
        btnConnect->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Connect", nullptr));
#if QT_CONFIG(tooltip)
        btnNew->setToolTip(QCoreApplication::translate("QgsDbSourceSelectBase", "Create a new database connection", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNew->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "New", nullptr));
#if QT_CONFIG(tooltip)
        btnEdit->setToolTip(QCoreApplication::translate("QgsDbSourceSelectBase", "Edit selected database connection", nullptr));
#endif // QT_CONFIG(tooltip)
        btnEdit->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Edit", nullptr));
#if QT_CONFIG(tooltip)
        btnDelete->setToolTip(QCoreApplication::translate("QgsDbSourceSelectBase", "Remove connection to selected database", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelete->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Remove", nullptr));
        btnLoad->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Load", "Load connections from file"));
#if QT_CONFIG(tooltip)
        btnSave->setToolTip(QCoreApplication::translate("QgsDbSourceSelectBase", "Save connections to file", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSave->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Save", nullptr));
        cbxAllowGeometrylessTables->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Also list tables with no geometry", nullptr));
        mHoldDialogOpen->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Keep dialog open", nullptr));
        mSearchGroupBox->setTitle(QCoreApplication::translate("QgsDbSourceSelectBase", "Search options", nullptr));
        mSearchLabel->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Search", nullptr));
        mSearchModeLabel->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Search mode", nullptr));
        mSearchColumnsLabel->setText(QCoreApplication::translate("QgsDbSourceSelectBase", "Search in columns", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsDbSourceSelectBase: public Ui_QgsDbSourceSelectBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSDBSOURCESELECTBASE_H
