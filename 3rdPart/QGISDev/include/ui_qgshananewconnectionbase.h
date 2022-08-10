/********************************************************************************
** Form generated from reading UI file 'qgshananewconnectionbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSHANANEWCONNECTIONBASE_H
#define UI_QGSHANANEWCONNECTIONBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "auth/qgsauthsettingswidget.h"
#include "qgsmessagebar.h"

QT_BEGIN_NAMESPACE

class Ui_QgsHanaNewConnectionBase
{
public:
    QVBoxLayout *verticalLayout_2;
    QgsMessageBar *bar;
    QGroupBox *GroupBox1;
    QVBoxLayout *verticalLayout;
    QGridLayout *grdConnectionSettings;
    QLabel *lbIdentifier;
    QLineEdit *txtName;
    QLabel *lblSchema;
    QLabel *lblDriver;
    QLabel *lblHost;
    QLineEdit *txtHost;
    QLabel *lblName;
    QFrame *frmMode;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rbtnSingleContainer;
    QFrame *frmMultipleContainers;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *rbtnMultipleContainers;
    QFrame *frmMultitenantSettings;
    QFormLayout *formLayout;
    QRadioButton *rbtnTenantDatabase;
    QFrame *frame;
    QFormLayout *formLayout_4;
    QLabel *lblTenantDatabaseName;
    QLineEdit *txtTenantDatabaseName;
    QRadioButton *rbtnSystemDatabase;
    QLineEdit *txtDriver;
    QLabel *lblMode;
    QLineEdit *txtSchema;
    QFrame *frmIdentifier;
    QComboBox *cmbIdentifierType;
    QLineEdit *txtIdentifier;
    QTabWidget *tabWidget;
    QWidget *tbpAuthentication;
    QVBoxLayout *verticalLayout_3;
    QgsAuthSettingsWidget *mAuthSettings;
    QWidget *tbpSSLSettings;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *chkEnableSSL;
    QFrame *line;
    QFormLayout *frmLayoutSSL;
    QLabel *lblCryptoProvider;
    QComboBox *cbxCryptoProvider;
    QCheckBox *chkValidateCertificate;
    QLabel *lblOverrideHostName;
    QLineEdit *txtOverrideHostName;
    QLabel *lblKeyStore;
    QLabel *lblTrustStore;
    QLineEdit *txtKeyStore;
    QLineEdit *txtTrustStore;
    QPushButton *btnConnect;
    QCheckBox *chkUserTablesOnly;
    QCheckBox *chkAllowGeometrylessTables;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *QgsHanaNewConnectionBase)
    {
        if (QgsHanaNewConnectionBase->objectName().isEmpty())
            QgsHanaNewConnectionBase->setObjectName(QString::fromUtf8("QgsHanaNewConnectionBase"));
        QgsHanaNewConnectionBase->resize(464, 729);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QgsHanaNewConnectionBase->sizePolicy().hasHeightForWidth());
        QgsHanaNewConnectionBase->setSizePolicy(sizePolicy);
        QgsHanaNewConnectionBase->setSizeGripEnabled(true);
        QgsHanaNewConnectionBase->setModal(true);
        verticalLayout_2 = new QVBoxLayout(QgsHanaNewConnectionBase);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        bar = new QgsMessageBar(QgsHanaNewConnectionBase);
        bar->setObjectName(QString::fromUtf8("bar"));

        verticalLayout_2->addWidget(bar);

        GroupBox1 = new QGroupBox(QgsHanaNewConnectionBase);
        GroupBox1->setObjectName(QString::fromUtf8("GroupBox1"));
        verticalLayout = new QVBoxLayout(GroupBox1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        grdConnectionSettings = new QGridLayout();
        grdConnectionSettings->setSpacing(6);
        grdConnectionSettings->setObjectName(QString::fromUtf8("grdConnectionSettings"));
        lbIdentifier = new QLabel(GroupBox1);
        lbIdentifier->setObjectName(QString::fromUtf8("lbIdentifier"));

        grdConnectionSettings->addWidget(lbIdentifier, 3, 0, 1, 1);

        txtName = new QLineEdit(GroupBox1);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        grdConnectionSettings->addWidget(txtName, 0, 1, 1, 1);

        lblSchema = new QLabel(GroupBox1);
        lblSchema->setObjectName(QString::fromUtf8("lblSchema"));

        grdConnectionSettings->addWidget(lblSchema, 5, 0, 1, 1);

        lblDriver = new QLabel(GroupBox1);
        lblDriver->setObjectName(QString::fromUtf8("lblDriver"));

        grdConnectionSettings->addWidget(lblDriver, 1, 0, 1, 1);

        lblHost = new QLabel(GroupBox1);
        lblHost->setObjectName(QString::fromUtf8("lblHost"));

        grdConnectionSettings->addWidget(lblHost, 2, 0, 1, 1);

        txtHost = new QLineEdit(GroupBox1);
        txtHost->setObjectName(QString::fromUtf8("txtHost"));

        grdConnectionSettings->addWidget(txtHost, 2, 1, 1, 1);

        lblName = new QLabel(GroupBox1);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        grdConnectionSettings->addWidget(lblName, 0, 0, 1, 1);

        frmMode = new QFrame(GroupBox1);
        frmMode->setObjectName(QString::fromUtf8("frmMode"));
        frmMode->setMinimumSize(QSize(0, 124));
        frmMode->setMaximumSize(QSize(16777215, 124));
        frmMode->setFrameShape(QFrame::NoFrame);
        frmMode->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frmMode);
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        rbtnSingleContainer = new QRadioButton(frmMode);
        buttonGroup = new QButtonGroup(QgsHanaNewConnectionBase);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(rbtnSingleContainer);
        rbtnSingleContainer->setObjectName(QString::fromUtf8("rbtnSingleContainer"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rbtnSingleContainer->sizePolicy().hasHeightForWidth());
        rbtnSingleContainer->setSizePolicy(sizePolicy1);
        rbtnSingleContainer->setChecked(true);

        verticalLayout_5->addWidget(rbtnSingleContainer);

        frmMultipleContainers = new QFrame(frmMode);
        frmMultipleContainers->setObjectName(QString::fromUtf8("frmMultipleContainers"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frmMultipleContainers->sizePolicy().hasHeightForWidth());
        frmMultipleContainers->setSizePolicy(sizePolicy2);
        frmMultipleContainers->setFrameShape(QFrame::NoFrame);
        frmMultipleContainers->setFrameShadow(QFrame::Raised);
        frmMultipleContainers->setLineWidth(0);
        verticalLayout_6 = new QVBoxLayout(frmMultipleContainers);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        rbtnMultipleContainers = new QRadioButton(frmMultipleContainers);
        buttonGroup->addButton(rbtnMultipleContainers);
        rbtnMultipleContainers->setObjectName(QString::fromUtf8("rbtnMultipleContainers"));
        rbtnMultipleContainers->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rbtnMultipleContainers->sizePolicy().hasHeightForWidth());
        rbtnMultipleContainers->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(rbtnMultipleContainers);

        frmMultitenantSettings = new QFrame(frmMultipleContainers);
        frmMultitenantSettings->setObjectName(QString::fromUtf8("frmMultitenantSettings"));
        frmMultitenantSettings->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frmMultitenantSettings->sizePolicy().hasHeightForWidth());
        frmMultitenantSettings->setSizePolicy(sizePolicy4);
        frmMultitenantSettings->setFrameShape(QFrame::NoFrame);
        frmMultitenantSettings->setFrameShadow(QFrame::Plain);
        formLayout = new QFormLayout(frmMultitenantSettings);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(1);
        formLayout->setContentsMargins(20, 0, 0, 0);
        rbtnTenantDatabase = new QRadioButton(frmMultitenantSettings);
        buttonGroup_2 = new QButtonGroup(QgsHanaNewConnectionBase);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(rbtnTenantDatabase);
        rbtnTenantDatabase->setObjectName(QString::fromUtf8("rbtnTenantDatabase"));
        rbtnTenantDatabase->setEnabled(true);
        rbtnTenantDatabase->setChecked(true);

        formLayout->setWidget(0, QFormLayout::SpanningRole, rbtnTenantDatabase);

        frame = new QFrame(frmMultitenantSettings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_4 = new QFormLayout(frame);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setHorizontalSpacing(2);
        formLayout_4->setVerticalSpacing(2);
        formLayout_4->setContentsMargins(16, 0, 0, 0);
        lblTenantDatabaseName = new QLabel(frame);
        lblTenantDatabaseName->setObjectName(QString::fromUtf8("lblTenantDatabaseName"));
        lblTenantDatabaseName->setEnabled(true);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, lblTenantDatabaseName);

        txtTenantDatabaseName = new QLineEdit(frame);
        txtTenantDatabaseName->setObjectName(QString::fromUtf8("txtTenantDatabaseName"));
        txtTenantDatabaseName->setEnabled(true);
        txtTenantDatabaseName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, txtTenantDatabaseName);


        formLayout->setWidget(1, QFormLayout::FieldRole, frame);

        rbtnSystemDatabase = new QRadioButton(frmMultitenantSettings);
        buttonGroup_2->addButton(rbtnSystemDatabase);
        rbtnSystemDatabase->setObjectName(QString::fromUtf8("rbtnSystemDatabase"));
        rbtnSystemDatabase->setEnabled(true);

        formLayout->setWidget(3, QFormLayout::SpanningRole, rbtnSystemDatabase);


        verticalLayout_6->addWidget(frmMultitenantSettings);


        verticalLayout_5->addWidget(frmMultipleContainers);


        grdConnectionSettings->addWidget(frmMode, 4, 1, 1, 1);

        txtDriver = new QLineEdit(GroupBox1);
        txtDriver->setObjectName(QString::fromUtf8("txtDriver"));

        grdConnectionSettings->addWidget(txtDriver, 1, 1, 1, 1);

        lblMode = new QLabel(GroupBox1);
        lblMode->setObjectName(QString::fromUtf8("lblMode"));
        lblMode->setMinimumSize(QSize(82, 100));
        lblMode->setMaximumSize(QSize(16777215, 100));
        lblMode->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        grdConnectionSettings->addWidget(lblMode, 4, 0, 1, 1);

        txtSchema = new QLineEdit(GroupBox1);
        txtSchema->setObjectName(QString::fromUtf8("txtSchema"));

        grdConnectionSettings->addWidget(txtSchema, 5, 1, 1, 1);

        frmIdentifier = new QFrame(GroupBox1);
        frmIdentifier->setObjectName(QString::fromUtf8("frmIdentifier"));
        frmIdentifier->setMinimumSize(QSize(0, 25));
        frmIdentifier->setMaximumSize(QSize(16777215, 25));
        frmIdentifier->setFrameShadow(QFrame::Raised);
        cmbIdentifierType = new QComboBox(frmIdentifier);
        cmbIdentifierType->addItem(QString());
        cmbIdentifierType->addItem(QString());
        cmbIdentifierType->setObjectName(QString::fromUtf8("cmbIdentifierType"));
        cmbIdentifierType->setGeometry(QRect(0, 0, 151, 25));
        txtIdentifier = new QLineEdit(frmIdentifier);
        txtIdentifier->setObjectName(QString::fromUtf8("txtIdentifier"));
        txtIdentifier->setGeometry(QRect(160, 0, 51, 25));
        txtIdentifier->setMinimumSize(QSize(0, 0));
        txtIdentifier->setMaximumSize(QSize(16777215, 16777215));
        txtIdentifier->setMaxLength(5);

        grdConnectionSettings->addWidget(frmIdentifier, 3, 1, 1, 1);


        verticalLayout->addLayout(grdConnectionSettings);

        tabWidget = new QTabWidget(GroupBox1);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tbpAuthentication = new QWidget();
        tbpAuthentication->setObjectName(QString::fromUtf8("tbpAuthentication"));
        verticalLayout_3 = new QVBoxLayout(tbpAuthentication);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mAuthSettings = new QgsAuthSettingsWidget(tbpAuthentication);
        mAuthSettings->setObjectName(QString::fromUtf8("mAuthSettings"));
        mAuthSettings->setAutoFillBackground(false);

        verticalLayout_3->addWidget(mAuthSettings);

        tabWidget->addTab(tbpAuthentication, QString());
        tbpSSLSettings = new QWidget();
        tbpSSLSettings->setObjectName(QString::fromUtf8("tbpSSLSettings"));
        verticalLayout_4 = new QVBoxLayout(tbpSSLSettings);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        chkEnableSSL = new QCheckBox(tbpSSLSettings);
        chkEnableSSL->setObjectName(QString::fromUtf8("chkEnableSSL"));

        verticalLayout_4->addWidget(chkEnableSSL);

        line = new QFrame(tbpSSLSettings);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        frmLayoutSSL = new QFormLayout();
        frmLayoutSSL->setSpacing(6);
        frmLayoutSSL->setObjectName(QString::fromUtf8("frmLayoutSSL"));
        lblCryptoProvider = new QLabel(tbpSSLSettings);
        lblCryptoProvider->setObjectName(QString::fromUtf8("lblCryptoProvider"));

        frmLayoutSSL->setWidget(0, QFormLayout::LabelRole, lblCryptoProvider);

        cbxCryptoProvider = new QComboBox(tbpSSLSettings);
        cbxCryptoProvider->setObjectName(QString::fromUtf8("cbxCryptoProvider"));

        frmLayoutSSL->setWidget(0, QFormLayout::FieldRole, cbxCryptoProvider);

        chkValidateCertificate = new QCheckBox(tbpSSLSettings);
        chkValidateCertificate->setObjectName(QString::fromUtf8("chkValidateCertificate"));

        frmLayoutSSL->setWidget(1, QFormLayout::LabelRole, chkValidateCertificate);

        lblOverrideHostName = new QLabel(tbpSSLSettings);
        lblOverrideHostName->setObjectName(QString::fromUtf8("lblOverrideHostName"));

        frmLayoutSSL->setWidget(2, QFormLayout::LabelRole, lblOverrideHostName);

        txtOverrideHostName = new QLineEdit(tbpSSLSettings);
        txtOverrideHostName->setObjectName(QString::fromUtf8("txtOverrideHostName"));

        frmLayoutSSL->setWidget(2, QFormLayout::FieldRole, txtOverrideHostName);

        lblKeyStore = new QLabel(tbpSSLSettings);
        lblKeyStore->setObjectName(QString::fromUtf8("lblKeyStore"));

        frmLayoutSSL->setWidget(3, QFormLayout::LabelRole, lblKeyStore);

        lblTrustStore = new QLabel(tbpSSLSettings);
        lblTrustStore->setObjectName(QString::fromUtf8("lblTrustStore"));

        frmLayoutSSL->setWidget(4, QFormLayout::LabelRole, lblTrustStore);

        txtKeyStore = new QLineEdit(tbpSSLSettings);
        txtKeyStore->setObjectName(QString::fromUtf8("txtKeyStore"));

        frmLayoutSSL->setWidget(3, QFormLayout::FieldRole, txtKeyStore);

        txtTrustStore = new QLineEdit(tbpSSLSettings);
        txtTrustStore->setObjectName(QString::fromUtf8("txtTrustStore"));

        frmLayoutSSL->setWidget(4, QFormLayout::FieldRole, txtTrustStore);


        verticalLayout_4->addLayout(frmLayoutSSL);

        tabWidget->addTab(tbpSSLSettings, QString());

        verticalLayout->addWidget(tabWidget);

        btnConnect = new QPushButton(GroupBox1);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout->addWidget(btnConnect);

        chkUserTablesOnly = new QCheckBox(GroupBox1);
        chkUserTablesOnly->setObjectName(QString::fromUtf8("chkUserTablesOnly"));

        verticalLayout->addWidget(chkUserTablesOnly);

        chkAllowGeometrylessTables = new QCheckBox(GroupBox1);
        chkAllowGeometrylessTables->setObjectName(QString::fromUtf8("chkAllowGeometrylessTables"));
        chkAllowGeometrylessTables->setChecked(false);

        verticalLayout->addWidget(chkAllowGeometrylessTables);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addWidget(GroupBox1);

        buttonBox = new QDialogButtonBox(QgsHanaNewConnectionBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        lblSchema->setBuddy(txtSchema);
        lblDriver->setBuddy(txtDriver);
        lblHost->setBuddy(txtHost);
        lblName->setBuddy(txtName);
        lblTenantDatabaseName->setBuddy(txtDriver);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(txtName, txtDriver);
        QWidget::setTabOrder(txtDriver, txtHost);
        QWidget::setTabOrder(txtHost, cmbIdentifierType);
        QWidget::setTabOrder(cmbIdentifierType, txtIdentifier);
        QWidget::setTabOrder(txtIdentifier, rbtnSingleContainer);
        QWidget::setTabOrder(rbtnSingleContainer, rbtnMultipleContainers);
        QWidget::setTabOrder(rbtnMultipleContainers, rbtnTenantDatabase);
        QWidget::setTabOrder(rbtnTenantDatabase, txtTenantDatabaseName);
        QWidget::setTabOrder(txtTenantDatabaseName, rbtnSystemDatabase);
        QWidget::setTabOrder(rbtnSystemDatabase, txtSchema);
        QWidget::setTabOrder(txtSchema, tabWidget);
        QWidget::setTabOrder(tabWidget, btnConnect);
        QWidget::setTabOrder(btnConnect, chkUserTablesOnly);
        QWidget::setTabOrder(chkUserTablesOnly, chkAllowGeometrylessTables);
        QWidget::setTabOrder(chkAllowGeometrylessTables, txtOverrideHostName);
        QWidget::setTabOrder(txtOverrideHostName, txtKeyStore);
        QWidget::setTabOrder(txtKeyStore, txtTrustStore);
        QWidget::setTabOrder(txtTrustStore, chkValidateCertificate);
        QWidget::setTabOrder(chkValidateCertificate, cbxCryptoProvider);
        QWidget::setTabOrder(cbxCryptoProvider, chkEnableSSL);

        retranslateUi(QgsHanaNewConnectionBase);
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsHanaNewConnectionBase, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsHanaNewConnectionBase, SLOT(accept()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsHanaNewConnectionBase);
    } // setupUi

    void retranslateUi(QDialog *QgsHanaNewConnectionBase)
    {
        QgsHanaNewConnectionBase->setWindowTitle(QCoreApplication::translate("QgsHanaNewConnectionBase", "Create a New SAP HANA Connection", nullptr));
        GroupBox1->setTitle(QCoreApplication::translate("QgsHanaNewConnectionBase", "Connection Information", nullptr));
        lbIdentifier->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Identifier", nullptr));
#if QT_CONFIG(tooltip)
        txtName->setToolTip(QCoreApplication::translate("QgsHanaNewConnectionBase", "Name of the new connection", nullptr));
#endif // QT_CONFIG(tooltip)
        lblSchema->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "&Schema", nullptr));
        lblDriver->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Driver", nullptr));
        lblHost->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Hos&t", nullptr));
        lblName->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "&Name", nullptr));
        rbtnSingleContainer->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Single container", nullptr));
        rbtnMultipleContainers->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Multiple containers", nullptr));
        rbtnTenantDatabase->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Tenant database", nullptr));
        lblTenantDatabaseName->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Name:", nullptr));
        rbtnSystemDatabase->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "System database", nullptr));
        lblMode->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Mode", nullptr));
        cmbIdentifierType->setItemText(0, QCoreApplication::translate("QgsHanaNewConnectionBase", "Instance Number", nullptr));
        cmbIdentifierType->setItemText(1, QCoreApplication::translate("QgsHanaNewConnectionBase", "Port Number", nullptr));

        txtIdentifier->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "00", nullptr));
#if QT_CONFIG(whatsthis)
        tbpAuthentication->setWhatsThis(QCoreApplication::translate("QgsHanaNewConnectionBase", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(tbpAuthentication), QCoreApplication::translate("QgsHanaNewConnectionBase", "Authentication", nullptr));
        chkEnableSSL->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Enable TLS/SSL encryption", nullptr));
        lblCryptoProvider->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Provider", nullptr));
#if QT_CONFIG(tooltip)
        chkValidateCertificate->setToolTip(QCoreApplication::translate("QgsHanaNewConnectionBase", "Restrict the displayed tables to those that are in the layer registries.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        chkValidateCertificate->setWhatsThis(QCoreApplication::translate("QgsHanaNewConnectionBase", "Restricts the displayed tables to those that are found in the layer registries (geometry_columns, geography_columns, topology.layer). This can speed up the initial display of spatial tables.", nullptr));
#endif // QT_CONFIG(whatsthis)
        chkValidateCertificate->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Validate SSL certificate", nullptr));
        lblOverrideHostName->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Override host name in the certificate", nullptr));
        lblKeyStore->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Keystore file with private key", nullptr));
        lblTrustStore->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Trust store file with public key", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tbpSSLSettings), QCoreApplication::translate("QgsHanaNewConnectionBase", "SSL Settings", nullptr));
        btnConnect->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "&Test Connection", nullptr));
#if QT_CONFIG(tooltip)
        chkUserTablesOnly->setToolTip(QCoreApplication::translate("QgsHanaNewConnectionBase", "Restrict the displayed tables to those that are in the layer registries.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        chkUserTablesOnly->setWhatsThis(QCoreApplication::translate("QgsHanaNewConnectionBase", "Restricts the displayed tables to those that are found in the layer registries (geometry_columns, geography_columns, topology.layer). This can speed up the initial display of spatial tables.", nullptr));
#endif // QT_CONFIG(whatsthis)
        chkUserTablesOnly->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Only look for user's tables", nullptr));
        chkAllowGeometrylessTables->setText(QCoreApplication::translate("QgsHanaNewConnectionBase", "Also list tables with no geometry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsHanaNewConnectionBase: public Ui_QgsHanaNewConnectionBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSHANANEWCONNECTIONBASE_H
