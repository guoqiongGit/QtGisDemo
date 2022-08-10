/********************************************************************************
** Form generated from reading UI file 'qgsdb2newconnectionbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSDB2NEWCONNECTIONBASE_H
#define UI_QGSDB2NEWCONNECTIONBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "auth/qgsauthsettingswidget.h"
#include "qgsmessagebar.h"

QT_BEGIN_NAMESPACE

class Ui_QgsDb2NewConnectionBase
{
public:
    QVBoxLayout *verticalLayout;
    QgsMessageBar *bar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *txtPort;
    QLineEdit *txtHost;
    QLabel *DB2ServiceLabel;
    QLineEdit *txtService;
    QLabel *DB2ServiceLabel_2;
    QLineEdit *txtName;
    QLabel *DB2HostLabel;
    QLabel *database;
    QLineEdit *txtDatabase;
    QLabel *DB2port;
    QLabel *DB2ServiceLabel_3;
    QLineEdit *txtDriver;
    QGroupBox *mAuthGroupBox;
    QGridLayout *gridLayout;
    QgsAuthSettingsWidget *mAuthSettings;
    QPushButton *btnConnect;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsDb2NewConnectionBase)
    {
        if (QgsDb2NewConnectionBase->objectName().isEmpty())
            QgsDb2NewConnectionBase->setObjectName(QString::fromUtf8("QgsDb2NewConnectionBase"));
        QgsDb2NewConnectionBase->resize(506, 583);
        verticalLayout = new QVBoxLayout(QgsDb2NewConnectionBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bar = new QgsMessageBar(QgsDb2NewConnectionBase);
        bar->setObjectName(QString::fromUtf8("bar"));

        verticalLayout->addWidget(bar);

        groupBox = new QGroupBox(QgsDb2NewConnectionBase);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtPort = new QLineEdit(groupBox);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));

        gridLayout_2->addWidget(txtPort, 4, 1, 1, 1);

        txtHost = new QLineEdit(groupBox);
        txtHost->setObjectName(QString::fromUtf8("txtHost"));

        gridLayout_2->addWidget(txtHost, 3, 1, 1, 1);

        DB2ServiceLabel = new QLabel(groupBox);
        DB2ServiceLabel->setObjectName(QString::fromUtf8("DB2ServiceLabel"));

        gridLayout_2->addWidget(DB2ServiceLabel, 1, 0, 1, 1);

        txtService = new QLineEdit(groupBox);
        txtService->setObjectName(QString::fromUtf8("txtService"));

        gridLayout_2->addWidget(txtService, 1, 1, 1, 1);

        DB2ServiceLabel_2 = new QLabel(groupBox);
        DB2ServiceLabel_2->setObjectName(QString::fromUtf8("DB2ServiceLabel_2"));

        gridLayout_2->addWidget(DB2ServiceLabel_2, 2, 0, 1, 1);

        txtName = new QLineEdit(groupBox);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        gridLayout_2->addWidget(txtName, 0, 1, 1, 1);

        DB2HostLabel = new QLabel(groupBox);
        DB2HostLabel->setObjectName(QString::fromUtf8("DB2HostLabel"));

        gridLayout_2->addWidget(DB2HostLabel, 3, 0, 1, 1);

        database = new QLabel(groupBox);
        database->setObjectName(QString::fromUtf8("database"));

        gridLayout_2->addWidget(database, 5, 0, 1, 1);

        txtDatabase = new QLineEdit(groupBox);
        txtDatabase->setObjectName(QString::fromUtf8("txtDatabase"));

        gridLayout_2->addWidget(txtDatabase, 5, 1, 1, 1);

        DB2port = new QLabel(groupBox);
        DB2port->setObjectName(QString::fromUtf8("DB2port"));

        gridLayout_2->addWidget(DB2port, 4, 0, 1, 1);

        DB2ServiceLabel_3 = new QLabel(groupBox);
        DB2ServiceLabel_3->setObjectName(QString::fromUtf8("DB2ServiceLabel_3"));

        gridLayout_2->addWidget(DB2ServiceLabel_3, 0, 0, 1, 1);

        txtDriver = new QLineEdit(groupBox);
        txtDriver->setObjectName(QString::fromUtf8("txtDriver"));

        gridLayout_2->addWidget(txtDriver, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        mAuthGroupBox = new QGroupBox(QgsDb2NewConnectionBase);
        mAuthGroupBox->setObjectName(QString::fromUtf8("mAuthGroupBox"));
        gridLayout = new QGridLayout(mAuthGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        mAuthSettings = new QgsAuthSettingsWidget(mAuthGroupBox);
        mAuthSettings->setObjectName(QString::fromUtf8("mAuthSettings"));

        gridLayout->addWidget(mAuthSettings, 0, 0, 1, 1);


        verticalLayout->addWidget(mAuthGroupBox);

        btnConnect = new QPushButton(QgsDb2NewConnectionBase);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout->addWidget(btnConnect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(QgsDb2NewConnectionBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(txtName, txtService);
        QWidget::setTabOrder(txtService, txtDriver);
        QWidget::setTabOrder(txtDriver, txtHost);
        QWidget::setTabOrder(txtHost, txtPort);
        QWidget::setTabOrder(txtPort, txtDatabase);

        retranslateUi(QgsDb2NewConnectionBase);
        QObject::connect(btnConnect, SIGNAL(released()), QgsDb2NewConnectionBase, SLOT(on_btnConnect_clicked()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsDb2NewConnectionBase, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsDb2NewConnectionBase, SLOT(reject()));

        QMetaObject::connectSlotsByName(QgsDb2NewConnectionBase);
    } // setupUi

    void retranslateUi(QDialog *QgsDb2NewConnectionBase)
    {
        QgsDb2NewConnectionBase->setWindowTitle(QCoreApplication::translate("QgsDb2NewConnectionBase", "Create a New DB2 Connection", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QgsDb2NewConnectionBase", "Connection Information", nullptr));
        DB2ServiceLabel->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "Service/DSN", nullptr));
        DB2ServiceLabel_2->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "Driver", nullptr));
        DB2HostLabel->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "Host", nullptr));
        database->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "Database", nullptr));
        DB2port->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "Port", nullptr));
        DB2ServiceLabel_3->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "Name", nullptr));
        mAuthGroupBox->setTitle(QCoreApplication::translate("QgsDb2NewConnectionBase", "Authentication", nullptr));
        btnConnect->setText(QCoreApplication::translate("QgsDb2NewConnectionBase", "&Test Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsDb2NewConnectionBase: public Ui_QgsDb2NewConnectionBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSDB2NEWCONNECTIONBASE_H
