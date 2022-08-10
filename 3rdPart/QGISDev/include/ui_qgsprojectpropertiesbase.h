/********************************************************************************
** Form generated from reading UI file 'qgsprojectpropertiesbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSPROJECTPROPERTIESBASE_H
#define UI_QGSPROJECTPROPERTIESBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qgscolorschemelist.h>
#include <qgsvariableeditorwidget.h>
#include "qgscodeeditorpython.h"
#include "qgscollapsiblegroupbox.h"
#include "qgscolorbutton.h"
#include "qgsdatetimeedit.h"
#include "qgsdatumtransformtablewidget.h"
#include "qgsextentgroupbox.h"
#include "qgsfilterlineedit.h"
#include "qgsopacitywidget.h"
#include "qgsprojectionselectiontreewidget.h"
#include "qgspropertyoverridebutton.h"
#include "qgsscrollarea.h"
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsProjectPropertiesBase
{
public:
    QGridLayout *gridLayout_21;
    QSplitter *mOptionsSplitter;
    QFrame *mOptionsListFrame;
    QVBoxLayout *verticalLayout_2;
    QgsFilterLineEdit *mSearchLineEdit;
    QListWidget *mOptionsListWidget;
    QFrame *mOptionsFrame;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *mOptionsStackedWidget;
    QWidget *mProjOptsGeneral;
    QVBoxLayout *verticalLayout_6;
    QgsScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QgsCollapsibleGroupBox *titleBox;
    QGridLayout *gridLayout_26;
    QLabel *label_4;
    QLabel *textLabel1;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_14;
    QgsFilterLineEdit *mProjectHomeLineEdit;
    QToolButton *mButtonSetProjectHome;
    QLineEdit *titleEdit;
    QLabel *label_2;
    QCheckBox *mMapTileRenderingCheckBox;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *mProjectFileLineEdit;
    QToolButton *mButtonOpenProjectFolder;
    QComboBox *cbxAbsolutePath;
    QLabel *label_30;
    QSpacerItem *spacerItem;
    QHBoxLayout *horizontalLayout_5;
    QgsColorButton *pbnSelectionColor;
    QLabel *label;
    QgsColorButton *pbnCanvasColor;
    QSpacerItem *horizontalSpacer_4;
    QgsCollapsibleGroupBox *btnGrpMeasureEllipsoid;
    QGridLayout *gridLayoutMeasureTool;
    QComboBox *mDistanceUnitsCombo;
    QLabel *label_28;
    QLabel *textLabel1_8;
    QLineEdit *leSemiMajor;
    QLabel *label_41;
    QComboBox *cmbEllipsoid;
    QLineEdit *leSemiMinor;
    QLabel *label_42;
    QLabel *label_29;
    QComboBox *mAreaUnitsCombo;
    QgsCollapsibleGroupBox *mCoordinateDisplayGroup;
    QGridLayout *gridLayout_18;
    QLabel *label_26;
    QLabel *label_25;
    QComboBox *mCoordinateDisplayComboBox;
    QFrame *mFramePrecision;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radAutomatic;
    QRadioButton *radManual;
    QgsSpinBox *spinBoxDP;
    QLabel *labelDP;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *mCustomizeBearingFormatButton;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *sourceLanguageLabel;
    QComboBox *cbtsLocale;
    QPushButton *generateTsFileButton;
    QSpacerItem *verticalSpacer_5;
    QWidget *mMetadataPage;
    QVBoxLayout *verticalLayout_19;
    QWidget *mViewSettingsPage;
    QVBoxLayout *verticalLayout_25;
    QgsCollapsibleGroupBox *grpProjectScales;
    QGridLayout *gridLayout_7;
    QListWidget *lstScales;
    QVBoxLayout *verticalLayout_4;
    QToolButton *pbnAddScale;
    QToolButton *pbnRemoveScale;
    QToolButton *pbnImportScales;
    QToolButton *pbnExportScales;
    QSpacerItem *verticalSpacer;
    QgsExtentGroupBox *mExtentGroupBox;
    QSpacerItem *verticalSpacer_4;
    QWidget *mProjOptsCRS;
    QVBoxLayout *verticalLayout_5;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *cbxProjectionEnabled;
    QVBoxLayout *verticalLayout_21;
    QgsProjectionSelectionTreeWidget *projectionSelector;
    QWidget *mProjTransformations;
    QVBoxLayout *verticalLayout_8;
    QgsScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *mDatumTransformGroupBox;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *mShowDatumTransformDialogCheckBox;
    QgsDatumTransformTableWidget *mDatumTransformTableWidget;
    QWidget *mProjOptsSymbols;
    QVBoxLayout *verticalLayout_11;
    QgsScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_12;
    QgsCollapsibleGroupBox *groupBox;
    QGridLayout *gridLayout_11;
    QToolButton *pbtnStyleMarker;
    QLabel *lblStyleLine;
    QLabel *label_14;
    QLabel *pixStyleFill;
    QToolButton *pbtnStyleLine;
    QLabel *pixStyleLine;
    QComboBox *cboStyleFill;
    QLabel *lblStyleColorRamp;
    QComboBox *cboStyleMarker;
    QLabel *pixStyleMarker;
    QLabel *lblStyleMarker;
    QToolButton *pbtnStyleFill;
    QLabel *lblStyleFill;
    QComboBox *cboStyleLine;
    QComboBox *cboStyleColorRamp;
    QToolButton *pbtnStyleColorRamp;
    QgsCollapsibleGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_27;
    QgsOpacityWidget *mDefaultOpacityWidget;
    QCheckBox *cbxStyleRandomColors;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbtnStyleManager;
    QSpacerItem *horizontalSpacer;
    QgsCollapsibleGroupBox *groupBox_7;
    QGridLayout *gridLayout_12;
    QToolButton *mButtonCopyColors;
    QSpacerItem *verticalSpacer_12;
    QToolButton *mButtonAddColor;
    QToolButton *mButtonPasteColors;
    QToolButton *mButtonRemoveColor;
    QgsColorSchemeList *mTreeProjectColors;
    QToolButton *mButtonImportColors;
    QToolButton *mButtonExportColors;
    QWidget *mTab_DataSources;
    QFormLayout *formLayout;
    QCheckBox *mAutoTransaction;
    QCheckBox *mEvaluateDefaultValues;
    QCheckBox *mTrustProjectCheckBox;
    QgsCollapsibleGroupBox *groupBox_5;
    QGridLayout *gridLayout_19;
    QSpacerItem *horizontalSpacer_5;
    QTreeView *mLayerCapabilitiesTree;
    QPushButton *mLayerCapabilitiesToggleSelectionButton;
    QCheckBox *mShowSpatialLayersCheckBox;
    QgsFilterLineEdit *mLayerCapabilitiesTreeFilterLineEdit;
    QWidget *mTabRelations;
    QGridLayout *gridLayout_16;
    QWidget *mTab_Variables;
    QVBoxLayout *verticalLayout_23;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_7;
    QgsVariableEditorWidget *mVariableEditor;
    QWidget *mProjOptsMacros;
    QVBoxLayout *verticalLayout_15;
    QgsScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_6;
    QVBoxLayout *verticalLayout_17;
    QGroupBox *grpPythonMacros;
    QVBoxLayout *verticalLayout_16;
    QgsCodeEditorPython *ptePythonMacros;
    QWidget *mProjOptsOWS;
    QVBoxLayout *verticalLayout_14;
    QgsScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_13;
    QgsCollapsibleGroupBox *grpOWSServiceCapabilities;
    QGridLayout *gridLayout_6;
    QLineEdit *mWMSName;
    QComboBox *mWMSContactPositionCb;
    QComboBox *mWMSAccessConstraintsCb;
    QLineEdit *mWMSContactPerson;
    QGridLayout *wmsOnlineResourceGrid;
    QLineEdit *mWMSOnlineResourceLineEdit;
    QgsPropertyOverrideButton *mWMSOnlineResourceExpressionButton;
    QLabel *label_20;
    QLineEdit *mWMSTitle;
    QComboBox *mWMSFeesCb;
    QLineEdit *mWMSContactMail;
    QTextEdit *mWMSAbstract;
    QLabel *label_11;
    QLabel *mWMSAccessConstraintsLabel;
    QLabel *label_12;
    QLineEdit *mWMSContactPhone;
    QLabel *label_10;
    QFrame *wmsWarningBox;
    QGridLayout *gridLayout_23;
    QLabel *warningLabel;
    QLineEdit *mWMSKeywordList;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *mWMSKeywordListLabel;
    QLabel *label_9;
    QLineEdit *mWMSContactOrganization;
    QLabel *mWMSFeesLabel;
    QLabel *mWMSOnlineResourceLabel;
    QLabel *label_6;
    QgsCollapsibleGroupBox *grpWMSCapabilities;
    QGridLayout *gridLayout_13;
    QCheckBox *mAddWktGeometryCheckBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *mWMSImageQualityLabel;
    QgsSpinBox *mWMSImageQualitySpinBox;
    QHBoxLayout *horizontalLayout_17;
    QLabel *mWMSMaxAtlasFeaturesLabel;
    QgsSpinBox *mWMSMaxAtlasFeaturesSpinBox;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_33;
    QgsSpinBox *mWMSTileBufferSpinBox;
    QGridLayout *gridLayout_3;
    QLabel *mMaxWidthLabel;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *mMaxHeightLineEdit;
    QLineEdit *mMaxWidthLineEdit;
    QLabel *mMaxHeightLabel;
    QLabel *label_21;
    QgsCollapsibleGroupBox *mWMSInspire;
    QGridLayout *gridLayout_14;
    QComboBox *mWMSInspireLanguage;
    QLabel *label_7;
    QGroupBox *mWMSInspireScenario2;
    QGridLayout *gridLayout_17;
    QDateEdit *mWMSInspireTemporalReference;
    QLabel *label_23;
    QDateEdit *mWMSInspireMetadataDate;
    QLabel *label_22;
    QGroupBox *mWMSInspireScenario1;
    QGridLayout *gridLayout_15;
    QLineEdit *mWMSInspireMetadataUrl;
    QLabel *label_8;
    QComboBox *mWMSInspireMetadataUrlType;
    QLabel *label_24;
    QgsCollapsibleGroupBox *grpWMSList;
    QGridLayout *gridLayout_5;
    QToolButton *pbnWMSRemoveSRS;
    QListWidget *mWMSList;
    QPushButton *pbnWMSSetUsedSRS;
    QToolButton *pbnWMSAddSRS;
    QgsCollapsibleGroupBox *grpWMSExt;
    QGridLayout *gridLayout_4;
    QLineEdit *mWMSExtMinX;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_16;
    QLineEdit *mWMSExtMinY;
    QLabel *label_18;
    QPushButton *pbnWMSExtCanvas;
    QLabel *label_19;
    QLineEdit *mWMSExtMaxY;
    QLineEdit *mWMSExtMaxX;
    QCheckBox *mSegmentizeFeatureInfoGeometryCheckBox;
    QHBoxLayout *grpWMSPrecision;
    QLabel *label_5;
    QgsSpinBox *mWMSPrecisionSpinBox;
    QgsCollapsibleGroupBox *mWMSPrintLayoutGroupBox;
    QGridLayout *gridLayout_10;
    QListWidget *mPrintLayoutListWidget;
    QToolButton *mAddWMSPrintLayoutButton;
    QToolButton *mRemoveWMSPrintLayoutButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mWMSUrlLabel;
    QLineEdit *mWMSUrlLineEdit;
    QCheckBox *mWmsUseLayerIDs;
    QHBoxLayout *mWMSDefaultMapUnitsPerMmLayout;
    QLabel *mWMSDefaultMapUnitsPerMmLabel;
    QgsCollapsibleGroupBox *mLayerRestrictionsGroupBox;
    QGridLayout *gridLayout;
    QListWidget *mLayerRestrictionsListWidget;
    QToolButton *mAddLayerRestrictionButton;
    QToolButton *mRemoveLayerRestrictionButton;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *mUseAttributeFormSettingsCheckBox;
    QgsCollapsibleGroupBox *grpWmtsCapabilities;
    QGridLayout *gridLayout_20;
    QHBoxLayout *horizontalLayout_16;
    QLabel *mWMTSMinScaleLabel;
    QgsSpinBox *mWMTSMinScaleSpinBox;
    QHBoxLayout *horizontalLayout_15;
    QLabel *mWMTSUrlLabel;
    QLineEdit *mWMTSUrlLineEdit;
    QHBoxLayout *horizontalLayout_17a;
    QVBoxLayout *vlWmtsLayers;
    QLabel *label_31;
    QTreeWidget *twWmtsLayers;
    QVBoxLayout *vlWmtsGrids;
    QLabel *label_32;
    QTreeWidget *twWmtsGrids;
    QgsCollapsibleGroupBox *grpWFSCapabilities;
    QGridLayout *gridLayout_8;
    QTableWidget *twWFSLayers;
    QPushButton *pbnWFSLayersDeselectAll;
    QPushButton *pbnWFSLayersSelectAll;
    QHBoxLayout *horizontalLayout_8;
    QLabel *mWFSUrlLabel;
    QLineEdit *mWFSUrlLineEdit;
    QgsCollapsibleGroupBox *grpWCSCapabilities;
    QGridLayout *gridLayout_9;
    QPushButton *pbnWCSLayersDeselectAll;
    QHBoxLayout *horizontalLayout_9;
    QLabel *mWCSUrlLabel;
    QLineEdit *mWCSUrlLineEdit;
    QPushButton *pbnWCSLayersSelectAll;
    QTableWidget *twWCSLayers;
    QgsCollapsibleGroupBox *mOWSCheckerGroupBox;
    QVBoxLayout *verticalLayout_24;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pbnLaunchOWSChecker;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *teOWSChecker;
    QSpacerItem *verticalSpacer_6;
    QWidget *mTemporalOptions;
    QVBoxLayout *verticalLayout_20;
    QGroupBox *mTemporalOptionsGroup;
    QGridLayout *gridLayout_22;
    QgsDateTimeEdit *mStartDateTimeEdit;
    QLabel *label_35;
    QPushButton *mCalculateFromLayerButton;
    QLabel *label_36;
    QgsDateTimeEdit *mEndDateTimeEdit;
    QSpacerItem *verticalSpacer_2;
    QFrame *mButtonBoxFrame;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsProjectPropertiesBase)
    {
        if (QgsProjectPropertiesBase->objectName().isEmpty())
            QgsProjectPropertiesBase->setObjectName(QString::fromUtf8("QgsProjectPropertiesBase"));
        QgsProjectPropertiesBase->resize(857, 730);
        QgsProjectPropertiesBase->setMinimumSize(QSize(700, 0));
        gridLayout_21 = new QGridLayout(QgsProjectPropertiesBase);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        mOptionsSplitter = new QSplitter(QgsProjectPropertiesBase);
        mOptionsSplitter->setObjectName(QString::fromUtf8("mOptionsSplitter"));
        mOptionsSplitter->setOrientation(Qt::Horizontal);
        mOptionsSplitter->setChildrenCollapsible(false);
        mOptionsListFrame = new QFrame(mOptionsSplitter);
        mOptionsListFrame->setObjectName(QString::fromUtf8("mOptionsListFrame"));
        mOptionsListFrame->setMinimumSize(QSize(0, 0));
        mOptionsListFrame->setFrameShape(QFrame::NoFrame);
        mOptionsListFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(mOptionsListFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mSearchLineEdit = new QgsFilterLineEdit(mOptionsListFrame);
        mSearchLineEdit->setObjectName(QString::fromUtf8("mSearchLineEdit"));

        verticalLayout_2->addWidget(mSearchLineEdit);

        mOptionsListWidget = new QListWidget(mOptionsListFrame);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/general.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/editmetadata.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/overlay.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/CRS.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/transformation.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem4->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/symbology.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem5->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/attributes.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem6->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/themes/default/relation.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem7->setIcon(icon7);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/themes/default/mIconExpression.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem8->setIcon(icon8);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/action.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem9->setIcon(icon9);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/network_and_proxy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem10->setIcon(icon10);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/temporal.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(mOptionsListWidget);
        __qlistwidgetitem11->setIcon(icon11);
        mOptionsListWidget->setObjectName(QString::fromUtf8("mOptionsListWidget"));
        mOptionsListWidget->setMinimumSize(QSize(58, 0));
        mOptionsListWidget->setMaximumSize(QSize(150, 16777215));
        mOptionsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mOptionsListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mOptionsListWidget->setIconSize(QSize(32, 32));
        mOptionsListWidget->setTextElideMode(Qt::ElideNone);
        mOptionsListWidget->setResizeMode(QListView::Adjust);
        mOptionsListWidget->setWordWrap(true);

        verticalLayout_2->addWidget(mOptionsListWidget);

        mOptionsSplitter->addWidget(mOptionsListFrame);
        mOptionsFrame = new QFrame(mOptionsSplitter);
        mOptionsFrame->setObjectName(QString::fromUtf8("mOptionsFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mOptionsFrame->sizePolicy().hasHeightForWidth());
        mOptionsFrame->setSizePolicy(sizePolicy);
        mOptionsFrame->setFrameShape(QFrame::NoFrame);
        mOptionsFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(mOptionsFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mOptionsStackedWidget = new QStackedWidget(mOptionsFrame);
        mOptionsStackedWidget->setObjectName(QString::fromUtf8("mOptionsStackedWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mOptionsStackedWidget->sizePolicy().hasHeightForWidth());
        mOptionsStackedWidget->setSizePolicy(sizePolicy1);
        mProjOptsGeneral = new QWidget();
        mProjOptsGeneral->setObjectName(QString::fromUtf8("mProjOptsGeneral"));
        verticalLayout_6 = new QVBoxLayout(mProjOptsGeneral);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QgsScrollArea(mProjOptsGeneral);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 685, 681));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_2);
        titleBox->setObjectName(QString::fromUtf8("titleBox"));
        titleBox->setProperty("syncGroup", QVariant(QString::fromUtf8("projgeneral")));
        gridLayout_26 = new QGridLayout(titleBox);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        label_4 = new QLabel(titleBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout_26->addWidget(label_4, 0, 0, 1, 1);

        textLabel1 = new QLabel(titleBox);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        sizePolicy2.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy2);

        gridLayout_26->addWidget(textLabel1, 3, 0, 1, 1);

        label_3 = new QLabel(titleBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout_26->addWidget(label_3, 4, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        mProjectHomeLineEdit = new QgsFilterLineEdit(titleBox);
        mProjectHomeLineEdit->setObjectName(QString::fromUtf8("mProjectHomeLineEdit"));
        mProjectHomeLineEdit->setReadOnly(false);
        mProjectHomeLineEdit->setClearButtonEnabled(false);

        horizontalLayout_14->addWidget(mProjectHomeLineEdit);

        mButtonSetProjectHome = new QToolButton(titleBox);
        mButtonSetProjectHome->setObjectName(QString::fromUtf8("mButtonSetProjectHome"));
        mButtonSetProjectHome->setAutoRaise(false);

        horizontalLayout_14->addWidget(mButtonSetProjectHome);


        gridLayout_26->addLayout(horizontalLayout_14, 1, 1, 1, 3);

        titleEdit = new QLineEdit(titleBox);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));

        gridLayout_26->addWidget(titleEdit, 2, 1, 1, 3);

        label_2 = new QLabel(titleBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout_26->addWidget(label_2, 2, 0, 1, 1);

        mMapTileRenderingCheckBox = new QCheckBox(titleBox);
        mMapTileRenderingCheckBox->setObjectName(QString::fromUtf8("mMapTileRenderingCheckBox"));

        gridLayout_26->addWidget(mMapTileRenderingCheckBox, 5, 0, 1, 4);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        mProjectFileLineEdit = new QLineEdit(titleBox);
        mProjectFileLineEdit->setObjectName(QString::fromUtf8("mProjectFileLineEdit"));
        mProjectFileLineEdit->setReadOnly(true);

        horizontalLayout_13->addWidget(mProjectFileLineEdit);

        mButtonOpenProjectFolder = new QToolButton(titleBox);
        mButtonOpenProjectFolder->setObjectName(QString::fromUtf8("mButtonOpenProjectFolder"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/themes/default/mActionFileOpen.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonOpenProjectFolder->setIcon(icon12);
        mButtonOpenProjectFolder->setAutoRaise(true);

        horizontalLayout_13->addWidget(mButtonOpenProjectFolder);


        gridLayout_26->addLayout(horizontalLayout_13, 0, 1, 1, 3);

        cbxAbsolutePath = new QComboBox(titleBox);
        cbxAbsolutePath->setObjectName(QString::fromUtf8("cbxAbsolutePath"));

        gridLayout_26->addWidget(cbxAbsolutePath, 4, 1, 1, 1);

        label_30 = new QLabel(titleBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy2.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy2);

        gridLayout_26->addWidget(label_30, 1, 0, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_26->addItem(spacerItem, 4, 2, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pbnSelectionColor = new QgsColorButton(titleBox);
        pbnSelectionColor->setObjectName(QString::fromUtf8("pbnSelectionColor"));
        pbnSelectionColor->setMinimumSize(QSize(120, 0));
        pbnSelectionColor->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(pbnSelectionColor);

        label = new QLabel(titleBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label);

        pbnCanvasColor = new QgsColorButton(titleBox);
        pbnCanvasColor->setObjectName(QString::fromUtf8("pbnCanvasColor"));
        pbnCanvasColor->setMinimumSize(QSize(120, 0));
        pbnCanvasColor->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(pbnCanvasColor);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        gridLayout_26->addLayout(horizontalLayout_5, 3, 1, 1, 3);


        verticalLayout->addWidget(titleBox);

        btnGrpMeasureEllipsoid = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_2);
        btnGrpMeasureEllipsoid->setObjectName(QString::fromUtf8("btnGrpMeasureEllipsoid"));
        btnGrpMeasureEllipsoid->setProperty("syncGroup", QVariant(QString::fromUtf8("projgeneral")));
        gridLayoutMeasureTool = new QGridLayout(btnGrpMeasureEllipsoid);
        gridLayoutMeasureTool->setObjectName(QString::fromUtf8("gridLayoutMeasureTool"));
        mDistanceUnitsCombo = new QComboBox(btnGrpMeasureEllipsoid);
        mDistanceUnitsCombo->setObjectName(QString::fromUtf8("mDistanceUnitsCombo"));

        gridLayoutMeasureTool->addWidget(mDistanceUnitsCombo, 2, 1, 1, 4);

        label_28 = new QLabel(btnGrpMeasureEllipsoid);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayoutMeasureTool->addWidget(label_28, 2, 0, 1, 1);

        textLabel1_8 = new QLabel(btnGrpMeasureEllipsoid);
        textLabel1_8->setObjectName(QString::fromUtf8("textLabel1_8"));

        gridLayoutMeasureTool->addWidget(textLabel1_8, 0, 0, 1, 1);

        leSemiMajor = new QLineEdit(btnGrpMeasureEllipsoid);
        leSemiMajor->setObjectName(QString::fromUtf8("leSemiMajor"));

        gridLayoutMeasureTool->addWidget(leSemiMajor, 1, 2, 1, 1);

        label_41 = new QLabel(btnGrpMeasureEllipsoid);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayoutMeasureTool->addWidget(label_41, 1, 1, 1, 1);

        cmbEllipsoid = new QComboBox(btnGrpMeasureEllipsoid);
        cmbEllipsoid->setObjectName(QString::fromUtf8("cmbEllipsoid"));

        gridLayoutMeasureTool->addWidget(cmbEllipsoid, 0, 1, 1, 4);

        leSemiMinor = new QLineEdit(btnGrpMeasureEllipsoid);
        leSemiMinor->setObjectName(QString::fromUtf8("leSemiMinor"));

        gridLayoutMeasureTool->addWidget(leSemiMinor, 1, 4, 1, 1);

        label_42 = new QLabel(btnGrpMeasureEllipsoid);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayoutMeasureTool->addWidget(label_42, 1, 3, 1, 1);

        label_29 = new QLabel(btnGrpMeasureEllipsoid);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayoutMeasureTool->addWidget(label_29, 3, 0, 1, 1);

        mAreaUnitsCombo = new QComboBox(btnGrpMeasureEllipsoid);
        mAreaUnitsCombo->setObjectName(QString::fromUtf8("mAreaUnitsCombo"));

        gridLayoutMeasureTool->addWidget(mAreaUnitsCombo, 3, 1, 1, 4);


        verticalLayout->addWidget(btnGrpMeasureEllipsoid);

        mCoordinateDisplayGroup = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_2);
        mCoordinateDisplayGroup->setObjectName(QString::fromUtf8("mCoordinateDisplayGroup"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mCoordinateDisplayGroup->sizePolicy().hasHeightForWidth());
        mCoordinateDisplayGroup->setSizePolicy(sizePolicy3);
        mCoordinateDisplayGroup->setProperty("syncGroup", QVariant(QString::fromUtf8("projgeneral")));
        gridLayout_18 = new QGridLayout(mCoordinateDisplayGroup);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        label_26 = new QLabel(mCoordinateDisplayGroup);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_18->addWidget(label_26, 1, 0, 1, 1);

        label_25 = new QLabel(mCoordinateDisplayGroup);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_18->addWidget(label_25, 0, 0, 1, 1);

        mCoordinateDisplayComboBox = new QComboBox(mCoordinateDisplayGroup);
        mCoordinateDisplayComboBox->setObjectName(QString::fromUtf8("mCoordinateDisplayComboBox"));

        gridLayout_18->addWidget(mCoordinateDisplayComboBox, 0, 1, 1, 1);

        mFramePrecision = new QFrame(mCoordinateDisplayGroup);
        mFramePrecision->setObjectName(QString::fromUtf8("mFramePrecision"));
        horizontalLayout_12 = new QHBoxLayout(mFramePrecision);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        radAutomatic = new QRadioButton(mFramePrecision);
        radAutomatic->setObjectName(QString::fromUtf8("radAutomatic"));
        radAutomatic->setChecked(true);

        horizontalLayout_12->addWidget(radAutomatic);

        radManual = new QRadioButton(mFramePrecision);
        radManual->setObjectName(QString::fromUtf8("radManual"));

        horizontalLayout_12->addWidget(radManual);

        spinBoxDP = new QgsSpinBox(mFramePrecision);
        spinBoxDP->setObjectName(QString::fromUtf8("spinBoxDP"));

        horizontalLayout_12->addWidget(spinBoxDP);

        labelDP = new QLabel(mFramePrecision);
        labelDP->setObjectName(QString::fromUtf8("labelDP"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelDP->sizePolicy().hasHeightForWidth());
        labelDP->setSizePolicy(sizePolicy4);

        horizontalLayout_12->addWidget(labelDP);


        gridLayout_18->addWidget(mFramePrecision, 1, 1, 1, 1);

        label_34 = new QLabel(mCoordinateDisplayGroup);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_18->addWidget(label_34, 2, 0, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        mCustomizeBearingFormatButton = new QPushButton(mCoordinateDisplayGroup);
        mCustomizeBearingFormatButton->setObjectName(QString::fromUtf8("mCustomizeBearingFormatButton"));

        horizontalLayout_19->addWidget(mCustomizeBearingFormatButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_8);

        horizontalLayout_19->setStretch(0, 3);
        horizontalLayout_19->setStretch(1, 6);

        gridLayout_18->addLayout(horizontalLayout_19, 2, 1, 1, 1);


        verticalLayout->addWidget(mCoordinateDisplayGroup);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sourceLanguageLabel = new QLabel(groupBox_6);
        sourceLanguageLabel->setObjectName(QString::fromUtf8("sourceLanguageLabel"));

        horizontalLayout_4->addWidget(sourceLanguageLabel);

        cbtsLocale = new QComboBox(groupBox_6);
        cbtsLocale->setObjectName(QString::fromUtf8("cbtsLocale"));

        horizontalLayout_4->addWidget(cbtsLocale);

        generateTsFileButton = new QPushButton(groupBox_6);
        generateTsFileButton->setObjectName(QString::fromUtf8("generateTsFileButton"));

        horizontalLayout_4->addWidget(generateTsFileButton);


        verticalLayout->addWidget(groupBox_6);

        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_6->addWidget(scrollArea_2);

        mOptionsStackedWidget->addWidget(mProjOptsGeneral);
        mMetadataPage = new QWidget();
        mMetadataPage->setObjectName(QString::fromUtf8("mMetadataPage"));
        verticalLayout_19 = new QVBoxLayout(mMetadataPage);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        mOptionsStackedWidget->addWidget(mMetadataPage);
        mViewSettingsPage = new QWidget();
        mViewSettingsPage->setObjectName(QString::fromUtf8("mViewSettingsPage"));
        verticalLayout_25 = new QVBoxLayout(mViewSettingsPage);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        grpProjectScales = new QgsCollapsibleGroupBox(mViewSettingsPage);
        grpProjectScales->setObjectName(QString::fromUtf8("grpProjectScales"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(3);
        sizePolicy5.setHeightForWidth(grpProjectScales->sizePolicy().hasHeightForWidth());
        grpProjectScales->setSizePolicy(sizePolicy5);
        grpProjectScales->setCheckable(true);
        grpProjectScales->setChecked(false);
        grpProjectScales->setProperty("syncGroup", QVariant(QString::fromUtf8("projgeneral")));
        gridLayout_7 = new QGridLayout(grpProjectScales);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lstScales = new QListWidget(grpProjectScales);
        lstScales->setObjectName(QString::fromUtf8("lstScales"));

        gridLayout_7->addWidget(lstScales, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pbnAddScale = new QToolButton(grpProjectScales);
        pbnAddScale->setObjectName(QString::fromUtf8("pbnAddScale"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/themes/default/symbologyAdd.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnAddScale->setIcon(icon13);

        verticalLayout_4->addWidget(pbnAddScale);

        pbnRemoveScale = new QToolButton(grpProjectScales);
        pbnRemoveScale->setObjectName(QString::fromUtf8("pbnRemoveScale"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/themes/default/symbologyRemove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnRemoveScale->setIcon(icon14);

        verticalLayout_4->addWidget(pbnRemoveScale);

        pbnImportScales = new QToolButton(grpProjectScales);
        pbnImportScales->setObjectName(QString::fromUtf8("pbnImportScales"));
        pbnImportScales->setIcon(icon12);

        verticalLayout_4->addWidget(pbnImportScales);

        pbnExportScales = new QToolButton(grpProjectScales);
        pbnExportScales->setObjectName(QString::fromUtf8("pbnExportScales"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/themes/default/mActionFileSave.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnExportScales->setIcon(icon15);

        verticalLayout_4->addWidget(pbnExportScales);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_7->addLayout(verticalLayout_4, 0, 1, 1, 1);


        verticalLayout_25->addWidget(grpProjectScales);

        mExtentGroupBox = new QgsExtentGroupBox(mViewSettingsPage);
        mExtentGroupBox->setObjectName(QString::fromUtf8("mExtentGroupBox"));
        mExtentGroupBox->setCheckable(true);
        mExtentGroupBox->setChecked(false);

        verticalLayout_25->addWidget(mExtentGroupBox);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_4);

        mOptionsStackedWidget->addWidget(mViewSettingsPage);
        mProjOptsCRS = new QWidget();
        mProjOptsCRS->setObjectName(QString::fromUtf8("mProjOptsCRS"));
        verticalLayout_5 = new QVBoxLayout(mProjOptsCRS);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QgsScrollArea(mProjOptsCRS);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 685, 681));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        cbxProjectionEnabled = new QGroupBox(scrollAreaWidgetContents);
        cbxProjectionEnabled->setObjectName(QString::fromUtf8("cbxProjectionEnabled"));
        cbxProjectionEnabled->setCheckable(false);
        verticalLayout_21 = new QVBoxLayout(cbxProjectionEnabled);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        projectionSelector = new QgsProjectionSelectionTreeWidget(cbxProjectionEnabled);
        projectionSelector->setObjectName(QString::fromUtf8("projectionSelector"));

        verticalLayout_21->addWidget(projectionSelector);


        verticalLayout_7->addWidget(cbxProjectionEnabled);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        mOptionsStackedWidget->addWidget(mProjOptsCRS);
        mProjTransformations = new QWidget();
        mProjTransformations->setObjectName(QString::fromUtf8("mProjTransformations"));
        verticalLayout_8 = new QVBoxLayout(mProjTransformations);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QgsScrollArea(mProjTransformations);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setFrameShape(QFrame::NoFrame);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 685, 681));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        mDatumTransformGroupBox = new QGroupBox(scrollAreaWidgetContents_3);
        mDatumTransformGroupBox->setObjectName(QString::fromUtf8("mDatumTransformGroupBox"));
        verticalLayout_10 = new QVBoxLayout(mDatumTransformGroupBox);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        mShowDatumTransformDialogCheckBox = new QCheckBox(mDatumTransformGroupBox);
        mShowDatumTransformDialogCheckBox->setObjectName(QString::fromUtf8("mShowDatumTransformDialogCheckBox"));
        mShowDatumTransformDialogCheckBox->setEnabled(false);

        verticalLayout_10->addWidget(mShowDatumTransformDialogCheckBox);

        mDatumTransformTableWidget = new QgsDatumTransformTableWidget(mDatumTransformGroupBox);
        mDatumTransformTableWidget->setObjectName(QString::fromUtf8("mDatumTransformTableWidget"));

        verticalLayout_10->addWidget(mDatumTransformTableWidget);


        verticalLayout_9->addWidget(mDatumTransformGroupBox);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_8->addWidget(scrollArea_3);

        mOptionsStackedWidget->addWidget(mProjTransformations);
        mProjOptsSymbols = new QWidget();
        mProjOptsSymbols->setObjectName(QString::fromUtf8("mProjOptsSymbols"));
        verticalLayout_11 = new QVBoxLayout(mProjOptsSymbols);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        scrollArea_4 = new QgsScrollArea(mProjOptsSymbols);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setFrameShape(QFrame::NoFrame);
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 685, 681));
        verticalLayout_12 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        groupBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("projstyles")));
        gridLayout_11 = new QGridLayout(groupBox);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(9, -1, -1, -1);
        pbtnStyleMarker = new QToolButton(groupBox);
        pbtnStyleMarker->setObjectName(QString::fromUtf8("pbtnStyleMarker"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/themes/default/symbologyEdit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbtnStyleMarker->setIcon(icon16);

        gridLayout_11->addWidget(pbtnStyleMarker, 0, 5, 1, 1);

        lblStyleLine = new QLabel(groupBox);
        lblStyleLine->setObjectName(QString::fromUtf8("lblStyleLine"));
        lblStyleLine->setMargin(5);

        gridLayout_11->addWidget(lblStyleLine, 1, 2, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy6);
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/images/themes/default/styleicons/color.svg")));

        gridLayout_11->addWidget(label_14, 3, 0, 1, 1);

        pixStyleFill = new QLabel(groupBox);
        pixStyleFill->setObjectName(QString::fromUtf8("pixStyleFill"));
        sizePolicy6.setHeightForWidth(pixStyleFill->sizePolicy().hasHeightForWidth());
        pixStyleFill->setSizePolicy(sizePolicy6);
        pixStyleFill->setPixmap(QPixmap(QString::fromUtf8(":/images/themes/default/mIconPolygonLayer.svg")));

        gridLayout_11->addWidget(pixStyleFill, 2, 0, 1, 1);

        pbtnStyleLine = new QToolButton(groupBox);
        pbtnStyleLine->setObjectName(QString::fromUtf8("pbtnStyleLine"));
        pbtnStyleLine->setIcon(icon16);

        gridLayout_11->addWidget(pbtnStyleLine, 1, 5, 1, 1);

        pixStyleLine = new QLabel(groupBox);
        pixStyleLine->setObjectName(QString::fromUtf8("pixStyleLine"));
        sizePolicy6.setHeightForWidth(pixStyleLine->sizePolicy().hasHeightForWidth());
        pixStyleLine->setSizePolicy(sizePolicy6);
        pixStyleLine->setPixmap(QPixmap(QString::fromUtf8(":/images/themes/default/mIconLineLayer.svg")));

        gridLayout_11->addWidget(pixStyleLine, 1, 0, 1, 1);

        cboStyleFill = new QComboBox(groupBox);
        cboStyleFill->setObjectName(QString::fromUtf8("cboStyleFill"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(cboStyleFill->sizePolicy().hasHeightForWidth());
        cboStyleFill->setSizePolicy(sizePolicy7);
        cboStyleFill->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_11->addWidget(cboStyleFill, 2, 4, 1, 1);

        lblStyleColorRamp = new QLabel(groupBox);
        lblStyleColorRamp->setObjectName(QString::fromUtf8("lblStyleColorRamp"));
        lblStyleColorRamp->setMargin(5);

        gridLayout_11->addWidget(lblStyleColorRamp, 3, 2, 1, 1);

        cboStyleMarker = new QComboBox(groupBox);
        cboStyleMarker->setObjectName(QString::fromUtf8("cboStyleMarker"));
        sizePolicy7.setHeightForWidth(cboStyleMarker->sizePolicy().hasHeightForWidth());
        cboStyleMarker->setSizePolicy(sizePolicy7);
        cboStyleMarker->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_11->addWidget(cboStyleMarker, 0, 4, 1, 1);

        pixStyleMarker = new QLabel(groupBox);
        pixStyleMarker->setObjectName(QString::fromUtf8("pixStyleMarker"));
        sizePolicy6.setHeightForWidth(pixStyleMarker->sizePolicy().hasHeightForWidth());
        pixStyleMarker->setSizePolicy(sizePolicy6);
        pixStyleMarker->setPixmap(QPixmap(QString::fromUtf8(":/images/themes/default/mIconPointLayer.svg")));

        gridLayout_11->addWidget(pixStyleMarker, 0, 0, 1, 1);

        lblStyleMarker = new QLabel(groupBox);
        lblStyleMarker->setObjectName(QString::fromUtf8("lblStyleMarker"));
        lblStyleMarker->setMargin(5);

        gridLayout_11->addWidget(lblStyleMarker, 0, 2, 1, 1);

        pbtnStyleFill = new QToolButton(groupBox);
        pbtnStyleFill->setObjectName(QString::fromUtf8("pbtnStyleFill"));
        pbtnStyleFill->setIcon(icon16);

        gridLayout_11->addWidget(pbtnStyleFill, 2, 5, 1, 1);

        lblStyleFill = new QLabel(groupBox);
        lblStyleFill->setObjectName(QString::fromUtf8("lblStyleFill"));
        lblStyleFill->setMargin(5);

        gridLayout_11->addWidget(lblStyleFill, 2, 2, 1, 1);

        cboStyleLine = new QComboBox(groupBox);
        cboStyleLine->setObjectName(QString::fromUtf8("cboStyleLine"));
        sizePolicy7.setHeightForWidth(cboStyleLine->sizePolicy().hasHeightForWidth());
        cboStyleLine->setSizePolicy(sizePolicy7);
        cboStyleLine->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_11->addWidget(cboStyleLine, 1, 4, 1, 1);

        cboStyleColorRamp = new QComboBox(groupBox);
        cboStyleColorRamp->setObjectName(QString::fromUtf8("cboStyleColorRamp"));
        sizePolicy7.setHeightForWidth(cboStyleColorRamp->sizePolicy().hasHeightForWidth());
        cboStyleColorRamp->setSizePolicy(sizePolicy7);
        cboStyleColorRamp->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_11->addWidget(cboStyleColorRamp, 3, 4, 1, 1);

        pbtnStyleColorRamp = new QToolButton(groupBox);
        pbtnStyleColorRamp->setObjectName(QString::fromUtf8("pbtnStyleColorRamp"));
        pbtnStyleColorRamp->setIcon(icon16);

        gridLayout_11->addWidget(pbtnStyleColorRamp, 3, 5, 1, 1);


        verticalLayout_12->addWidget(groupBox);

        groupBox_2 = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setProperty("syncGroup", QVariant(QString::fromUtf8("projstyles")));
        verticalLayout_18 = new QVBoxLayout(groupBox_2);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_6->addWidget(label_27);

        mDefaultOpacityWidget = new QgsOpacityWidget(groupBox_2);
        mDefaultOpacityWidget->setObjectName(QString::fromUtf8("mDefaultOpacityWidget"));
        mDefaultOpacityWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_6->addWidget(mDefaultOpacityWidget);

        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_18->addLayout(horizontalLayout_6);

        cbxStyleRandomColors = new QCheckBox(groupBox_2);
        cbxStyleRandomColors->setObjectName(QString::fromUtf8("cbxStyleRandomColors"));

        verticalLayout_18->addWidget(cbxStyleRandomColors);


        verticalLayout_12->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pbtnStyleManager = new QPushButton(scrollAreaWidgetContents_4);
        pbtnStyleManager->setObjectName(QString::fromUtf8("pbtnStyleManager"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/themes/default/mActionStyleManager.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbtnStyleManager->setIcon(icon17);

        horizontalLayout_3->addWidget(pbtnStyleManager);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_12->addLayout(horizontalLayout_3);

        groupBox_7 = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_12 = new QGridLayout(groupBox_7);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        mButtonCopyColors = new QToolButton(groupBox_7);
        mButtonCopyColors->setObjectName(QString::fromUtf8("mButtonCopyColors"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCopy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonCopyColors->setIcon(icon18);

        gridLayout_12->addWidget(mButtonCopyColors, 2, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_12, 6, 1, 1, 1);

        mButtonAddColor = new QToolButton(groupBox_7);
        mButtonAddColor->setObjectName(QString::fromUtf8("mButtonAddColor"));
        mButtonAddColor->setIcon(icon13);

        gridLayout_12->addWidget(mButtonAddColor, 0, 1, 1, 1);

        mButtonPasteColors = new QToolButton(groupBox_7);
        mButtonPasteColors->setObjectName(QString::fromUtf8("mButtonPasteColors"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/themes/default/mActionEditPaste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonPasteColors->setIcon(icon19);

        gridLayout_12->addWidget(mButtonPasteColors, 3, 1, 1, 1);

        mButtonRemoveColor = new QToolButton(groupBox_7);
        mButtonRemoveColor->setObjectName(QString::fromUtf8("mButtonRemoveColor"));
        mButtonRemoveColor->setIcon(icon14);

        gridLayout_12->addWidget(mButtonRemoveColor, 1, 1, 1, 1);

        mTreeProjectColors = new QgsColorSchemeList(groupBox_7);
        mTreeProjectColors->setObjectName(QString::fromUtf8("mTreeProjectColors"));

        gridLayout_12->addWidget(mTreeProjectColors, 0, 0, 8, 1);

        mButtonImportColors = new QToolButton(groupBox_7);
        mButtonImportColors->setObjectName(QString::fromUtf8("mButtonImportColors"));
        mButtonImportColors->setIcon(icon12);

        gridLayout_12->addWidget(mButtonImportColors, 4, 1, 1, 1);

        mButtonExportColors = new QToolButton(groupBox_7);
        mButtonExportColors->setObjectName(QString::fromUtf8("mButtonExportColors"));
        mButtonExportColors->setIcon(icon15);

        gridLayout_12->addWidget(mButtonExportColors, 5, 1, 1, 1);


        verticalLayout_12->addWidget(groupBox_7);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_11->addWidget(scrollArea_4);

        mOptionsStackedWidget->addWidget(mProjOptsSymbols);
        mTab_DataSources = new QWidget();
        mTab_DataSources->setObjectName(QString::fromUtf8("mTab_DataSources"));
        formLayout = new QFormLayout(mTab_DataSources);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        mAutoTransaction = new QCheckBox(mTab_DataSources);
        mAutoTransaction->setObjectName(QString::fromUtf8("mAutoTransaction"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, mAutoTransaction);

        mEvaluateDefaultValues = new QCheckBox(mTab_DataSources);
        mEvaluateDefaultValues->setObjectName(QString::fromUtf8("mEvaluateDefaultValues"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, mEvaluateDefaultValues);

        mTrustProjectCheckBox = new QCheckBox(mTab_DataSources);
        mTrustProjectCheckBox->setObjectName(QString::fromUtf8("mTrustProjectCheckBox"));

        formLayout->setWidget(3, QFormLayout::LabelRole, mTrustProjectCheckBox);

        groupBox_5 = new QgsCollapsibleGroupBox(mTab_DataSources);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(1);
        sizePolicy8.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy8);
        gridLayout_19 = new QGridLayout(groupBox_5);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setVerticalSpacing(0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_5, 3, 1, 1, 1);

        mLayerCapabilitiesTree = new QTreeView(groupBox_5);
        mLayerCapabilitiesTree->setObjectName(QString::fromUtf8("mLayerCapabilitiesTree"));
        sizePolicy8.setHeightForWidth(mLayerCapabilitiesTree->sizePolicy().hasHeightForWidth());
        mLayerCapabilitiesTree->setSizePolicy(sizePolicy8);

        gridLayout_19->addWidget(mLayerCapabilitiesTree, 0, 0, 1, 4);

        mLayerCapabilitiesToggleSelectionButton = new QPushButton(groupBox_5);
        mLayerCapabilitiesToggleSelectionButton->setObjectName(QString::fromUtf8("mLayerCapabilitiesToggleSelectionButton"));
        mLayerCapabilitiesToggleSelectionButton->setEnabled(false);

        gridLayout_19->addWidget(mLayerCapabilitiesToggleSelectionButton, 3, 0, 1, 1);

        mShowSpatialLayersCheckBox = new QCheckBox(groupBox_5);
        mShowSpatialLayersCheckBox->setObjectName(QString::fromUtf8("mShowSpatialLayersCheckBox"));
        mShowSpatialLayersCheckBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout_19->addWidget(mShowSpatialLayersCheckBox, 3, 2, 1, 1);

        mLayerCapabilitiesTreeFilterLineEdit = new QgsFilterLineEdit(groupBox_5);
        mLayerCapabilitiesTreeFilterLineEdit->setObjectName(QString::fromUtf8("mLayerCapabilitiesTreeFilterLineEdit"));

        gridLayout_19->addWidget(mLayerCapabilitiesTreeFilterLineEdit, 3, 3, 1, 1);


        formLayout->setWidget(4, QFormLayout::SpanningRole, groupBox_5);

        mOptionsStackedWidget->addWidget(mTab_DataSources);
        mTabRelations = new QWidget();
        mTabRelations->setObjectName(QString::fromUtf8("mTabRelations"));
        gridLayout_16 = new QGridLayout(mTabRelations);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        mOptionsStackedWidget->addWidget(mTabRelations);
        mTab_Variables = new QWidget();
        mTab_Variables->setObjectName(QString::fromUtf8("mTab_Variables"));
        verticalLayout_23 = new QVBoxLayout(mTab_Variables);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        groupBox_4 = new QGroupBox(mTab_Variables);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        mVariableEditor = new QgsVariableEditorWidget(groupBox_4);
        mVariableEditor->setObjectName(QString::fromUtf8("mVariableEditor"));
        mVariableEditor->setProperty("settingGroup", QVariant(QString::fromUtf8("projectProperties")));

        horizontalLayout_7->addWidget(mVariableEditor);


        verticalLayout_23->addWidget(groupBox_4);

        mOptionsStackedWidget->addWidget(mTab_Variables);
        mProjOptsMacros = new QWidget();
        mProjOptsMacros->setObjectName(QString::fromUtf8("mProjOptsMacros"));
        verticalLayout_15 = new QVBoxLayout(mProjOptsMacros);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        scrollArea_6 = new QgsScrollArea(mProjOptsMacros);
        scrollArea_6->setObjectName(QString::fromUtf8("scrollArea_6"));
        scrollArea_6->setFrameShape(QFrame::NoFrame);
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 685, 681));
        verticalLayout_17 = new QVBoxLayout(scrollAreaWidgetContents_6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(-1, 0, -1, 0);
        grpPythonMacros = new QGroupBox(scrollAreaWidgetContents_6);
        grpPythonMacros->setObjectName(QString::fromUtf8("grpPythonMacros"));
        grpPythonMacros->setCheckable(true);
        grpPythonMacros->setChecked(false);
        verticalLayout_16 = new QVBoxLayout(grpPythonMacros);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        ptePythonMacros = new QgsCodeEditorPython(grpPythonMacros);
        ptePythonMacros->setObjectName(QString::fromUtf8("ptePythonMacros"));

        verticalLayout_16->addWidget(ptePythonMacros);


        verticalLayout_17->addWidget(grpPythonMacros);

        scrollArea_6->setWidget(scrollAreaWidgetContents_6);

        verticalLayout_15->addWidget(scrollArea_6);

        mOptionsStackedWidget->addWidget(mProjOptsMacros);
        mProjOptsOWS = new QWidget();
        mProjOptsOWS->setObjectName(QString::fromUtf8("mProjOptsOWS"));
        verticalLayout_14 = new QVBoxLayout(mProjOptsOWS);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        scrollArea_5 = new QgsScrollArea(mProjOptsOWS);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setFrameShape(QFrame::NoFrame);
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 671, 3119));
        verticalLayout_13 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(-1, 0, -1, 0);
        grpOWSServiceCapabilities = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_5);
        grpOWSServiceCapabilities->setObjectName(QString::fromUtf8("grpOWSServiceCapabilities"));
        grpOWSServiceCapabilities->setCheckable(true);
        grpOWSServiceCapabilities->setChecked(false);
        grpOWSServiceCapabilities->setProperty("collapsed", QVariant(false));
        grpOWSServiceCapabilities->setProperty("syncGroup", QVariant(QString::fromUtf8("projowsserver")));
        grpOWSServiceCapabilities->setProperty("saveCollapsedState", QVariant(true));
        gridLayout_6 = new QGridLayout(grpOWSServiceCapabilities);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        mWMSName = new QLineEdit(grpOWSServiceCapabilities);
        mWMSName->setObjectName(QString::fromUtf8("mWMSName"));

        gridLayout_6->addWidget(mWMSName, 7, 1, 1, 1);

        mWMSContactPositionCb = new QComboBox(grpOWSServiceCapabilities);
        mWMSContactPositionCb->setObjectName(QString::fromUtf8("mWMSContactPositionCb"));
        mWMSContactPositionCb->setEditable(true);

        gridLayout_6->addWidget(mWMSContactPositionCb, 16, 1, 1, 1);

        mWMSAccessConstraintsCb = new QComboBox(grpOWSServiceCapabilities);
        mWMSAccessConstraintsCb->setObjectName(QString::fromUtf8("mWMSAccessConstraintsCb"));
        mWMSAccessConstraintsCb->setEditable(true);

        gridLayout_6->addWidget(mWMSAccessConstraintsCb, 21, 1, 1, 1);

        mWMSContactPerson = new QLineEdit(grpOWSServiceCapabilities);
        mWMSContactPerson->setObjectName(QString::fromUtf8("mWMSContactPerson"));

        gridLayout_6->addWidget(mWMSContactPerson, 15, 1, 1, 1);

        wmsOnlineResourceGrid = new QGridLayout();
        wmsOnlineResourceGrid->setObjectName(QString::fromUtf8("wmsOnlineResourceGrid"));
        mWMSOnlineResourceLineEdit = new QLineEdit(grpOWSServiceCapabilities);
        mWMSOnlineResourceLineEdit->setObjectName(QString::fromUtf8("mWMSOnlineResourceLineEdit"));

        wmsOnlineResourceGrid->addWidget(mWMSOnlineResourceLineEdit, 0, 0, 1, 1);

        mWMSOnlineResourceExpressionButton = new QgsPropertyOverrideButton(grpOWSServiceCapabilities);
        mWMSOnlineResourceExpressionButton->setObjectName(QString::fromUtf8("mWMSOnlineResourceExpressionButton"));

        wmsOnlineResourceGrid->addWidget(mWMSOnlineResourceExpressionButton, 0, 1, 1, 1);


        gridLayout_6->addLayout(wmsOnlineResourceGrid, 11, 1, 1, 1);

        label_20 = new QLabel(grpOWSServiceCapabilities);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_6->addWidget(label_20, 16, 0, 1, 1);

        mWMSTitle = new QLineEdit(grpOWSServiceCapabilities);
        mWMSTitle->setObjectName(QString::fromUtf8("mWMSTitle"));

        gridLayout_6->addWidget(mWMSTitle, 8, 1, 1, 1);

        mWMSFeesCb = new QComboBox(grpOWSServiceCapabilities);
        mWMSFeesCb->setObjectName(QString::fromUtf8("mWMSFeesCb"));
        mWMSFeesCb->setEditable(true);

        gridLayout_6->addWidget(mWMSFeesCb, 20, 1, 1, 1);

        mWMSContactMail = new QLineEdit(grpOWSServiceCapabilities);
        mWMSContactMail->setObjectName(QString::fromUtf8("mWMSContactMail"));

        gridLayout_6->addWidget(mWMSContactMail, 17, 1, 1, 1);

        mWMSAbstract = new QTextEdit(grpOWSServiceCapabilities);
        mWMSAbstract->setObjectName(QString::fromUtf8("mWMSAbstract"));

        gridLayout_6->addWidget(mWMSAbstract, 19, 1, 1, 1);

        label_11 = new QLabel(grpOWSServiceCapabilities);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 9, 0, 1, 1);

        mWMSAccessConstraintsLabel = new QLabel(grpOWSServiceCapabilities);
        mWMSAccessConstraintsLabel->setObjectName(QString::fromUtf8("mWMSAccessConstraintsLabel"));

        gridLayout_6->addWidget(mWMSAccessConstraintsLabel, 21, 0, 1, 1);

        label_12 = new QLabel(grpOWSServiceCapabilities);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_6->addWidget(label_12, 18, 0, 1, 1);

        mWMSContactPhone = new QLineEdit(grpOWSServiceCapabilities);
        mWMSContactPhone->setObjectName(QString::fromUtf8("mWMSContactPhone"));

        gridLayout_6->addWidget(mWMSContactPhone, 18, 1, 1, 1);

        label_10 = new QLabel(grpOWSServiceCapabilities);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 8, 0, 1, 1);

        wmsWarningBox = new QFrame(grpOWSServiceCapabilities);
        wmsWarningBox->setObjectName(QString::fromUtf8("wmsWarningBox"));
        wmsWarningBox->setAutoFillBackground(false);
        wmsWarningBox->setStyleSheet(QString::fromUtf8(""));
        wmsWarningBox->setFrameShape(QFrame::StyledPanel);
        wmsWarningBox->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(wmsWarningBox);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        warningLabel = new QLabel(wmsWarningBox);
        warningLabel->setObjectName(QString::fromUtf8("warningLabel"));
        warningLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255,165,0,0.3);"));
        warningLabel->setFrameShape(QFrame::NoFrame);
        warningLabel->setTextFormat(Qt::AutoText);
        warningLabel->setWordWrap(true);
        warningLabel->setMargin(9);

        gridLayout_23->addWidget(warningLabel, 0, 0, 1, 1);


        gridLayout_6->addWidget(wmsWarningBox, 1, 0, 1, 2);

        mWMSKeywordList = new QLineEdit(grpOWSServiceCapabilities);
        mWMSKeywordList->setObjectName(QString::fromUtf8("mWMSKeywordList"));

        gridLayout_6->addWidget(mWMSKeywordList, 22, 1, 1, 1);

        label_13 = new QLabel(grpOWSServiceCapabilities);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 17, 0, 1, 1);

        label_15 = new QLabel(grpOWSServiceCapabilities);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 19, 0, 1, 1);

        mWMSKeywordListLabel = new QLabel(grpOWSServiceCapabilities);
        mWMSKeywordListLabel->setObjectName(QString::fromUtf8("mWMSKeywordListLabel"));

        gridLayout_6->addWidget(mWMSKeywordListLabel, 22, 0, 1, 1);

        label_9 = new QLabel(grpOWSServiceCapabilities);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 15, 0, 1, 1);

        mWMSContactOrganization = new QLineEdit(grpOWSServiceCapabilities);
        mWMSContactOrganization->setObjectName(QString::fromUtf8("mWMSContactOrganization"));

        gridLayout_6->addWidget(mWMSContactOrganization, 9, 1, 1, 1);

        mWMSFeesLabel = new QLabel(grpOWSServiceCapabilities);
        mWMSFeesLabel->setObjectName(QString::fromUtf8("mWMSFeesLabel"));

        gridLayout_6->addWidget(mWMSFeesLabel, 20, 0, 1, 1);

        mWMSOnlineResourceLabel = new QLabel(grpOWSServiceCapabilities);
        mWMSOnlineResourceLabel->setObjectName(QString::fromUtf8("mWMSOnlineResourceLabel"));

        gridLayout_6->addWidget(mWMSOnlineResourceLabel, 11, 0, 1, 1);

        label_6 = new QLabel(grpOWSServiceCapabilities);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 7, 0, 1, 1);


        verticalLayout_13->addWidget(grpOWSServiceCapabilities);

        grpWMSCapabilities = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_5);
        grpWMSCapabilities->setObjectName(QString::fromUtf8("grpWMSCapabilities"));
        grpWMSCapabilities->setProperty("syncGroup", QVariant(QString::fromUtf8("projowsserver")));
        gridLayout_13 = new QGridLayout(grpWMSCapabilities);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        mAddWktGeometryCheckBox = new QCheckBox(grpWMSCapabilities);
        mAddWktGeometryCheckBox->setObjectName(QString::fromUtf8("mAddWktGeometryCheckBox"));

        gridLayout_13->addWidget(mAddWktGeometryCheckBox, 5, 0, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        mWMSImageQualityLabel = new QLabel(grpWMSCapabilities);
        mWMSImageQualityLabel->setObjectName(QString::fromUtf8("mWMSImageQualityLabel"));

        horizontalLayout_10->addWidget(mWMSImageQualityLabel);

        mWMSImageQualitySpinBox = new QgsSpinBox(grpWMSCapabilities);
        mWMSImageQualitySpinBox->setObjectName(QString::fromUtf8("mWMSImageQualitySpinBox"));
        mWMSImageQualitySpinBox->setMinimum(10);
        mWMSImageQualitySpinBox->setMaximum(100);
        mWMSImageQualitySpinBox->setSingleStep(5);
        mWMSImageQualitySpinBox->setValue(90);

        horizontalLayout_10->addWidget(mWMSImageQualitySpinBox);


        gridLayout_13->addLayout(horizontalLayout_10, 10, 0, 1, 3);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        mWMSMaxAtlasFeaturesLabel = new QLabel(grpWMSCapabilities);
        mWMSMaxAtlasFeaturesLabel->setObjectName(QString::fromUtf8("mWMSMaxAtlasFeaturesLabel"));

        horizontalLayout_17->addWidget(mWMSMaxAtlasFeaturesLabel);

        mWMSMaxAtlasFeaturesSpinBox = new QgsSpinBox(grpWMSCapabilities);
        mWMSMaxAtlasFeaturesSpinBox->setObjectName(QString::fromUtf8("mWMSMaxAtlasFeaturesSpinBox"));
        mWMSMaxAtlasFeaturesSpinBox->setMaximum(9999999);
        mWMSMaxAtlasFeaturesSpinBox->setValue(1);

        horizontalLayout_17->addWidget(mWMSMaxAtlasFeaturesSpinBox);


        gridLayout_13->addLayout(horizontalLayout_17, 11, 0, 1, 3);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_33 = new QLabel(grpWMSCapabilities);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_18->addWidget(label_33);

        mWMSTileBufferSpinBox = new QgsSpinBox(grpWMSCapabilities);
        mWMSTileBufferSpinBox->setObjectName(QString::fromUtf8("mWMSTileBufferSpinBox"));

        horizontalLayout_18->addWidget(mWMSTileBufferSpinBox);


        gridLayout_13->addLayout(horizontalLayout_18, 12, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mMaxWidthLabel = new QLabel(grpWMSCapabilities);
        mMaxWidthLabel->setObjectName(QString::fromUtf8("mMaxWidthLabel"));

        gridLayout_3->addWidget(mMaxWidthLabel, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(6, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        mMaxHeightLineEdit = new QLineEdit(grpWMSCapabilities);
        mMaxHeightLineEdit->setObjectName(QString::fromUtf8("mMaxHeightLineEdit"));

        gridLayout_3->addWidget(mMaxHeightLineEdit, 1, 4, 1, 1);

        mMaxWidthLineEdit = new QLineEdit(grpWMSCapabilities);
        mMaxWidthLineEdit->setObjectName(QString::fromUtf8("mMaxWidthLineEdit"));

        gridLayout_3->addWidget(mMaxWidthLineEdit, 1, 2, 1, 1);

        mMaxHeightLabel = new QLabel(grpWMSCapabilities);
        mMaxHeightLabel->setObjectName(QString::fromUtf8("mMaxHeightLabel"));

        gridLayout_3->addWidget(mMaxHeightLabel, 1, 3, 1, 1);

        label_21 = new QLabel(grpWMSCapabilities);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 0, 0, 1, 5);


        gridLayout_13->addLayout(gridLayout_3, 9, 0, 1, 3);

        mWMSInspire = new QgsCollapsibleGroupBox(grpWMSCapabilities);
        mWMSInspire->setObjectName(QString::fromUtf8("mWMSInspire"));
        mWMSInspire->setCheckable(true);
        mWMSInspire->setChecked(false);
        gridLayout_14 = new QGridLayout(mWMSInspire);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        mWMSInspireLanguage = new QComboBox(mWMSInspire);
        mWMSInspireLanguage->setObjectName(QString::fromUtf8("mWMSInspireLanguage"));
        sizePolicy7.setHeightForWidth(mWMSInspireLanguage->sizePolicy().hasHeightForWidth());
        mWMSInspireLanguage->setSizePolicy(sizePolicy7);

        gridLayout_14->addWidget(mWMSInspireLanguage, 0, 1, 1, 1);

        label_7 = new QLabel(mWMSInspire);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_14->addWidget(label_7, 0, 0, 1, 1);

        mWMSInspireScenario2 = new QGroupBox(mWMSInspire);
        mWMSInspireScenario2->setObjectName(QString::fromUtf8("mWMSInspireScenario2"));
        mWMSInspireScenario2->setCheckable(true);
        mWMSInspireScenario2->setChecked(false);
        gridLayout_17 = new QGridLayout(mWMSInspireScenario2);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        mWMSInspireTemporalReference = new QDateEdit(mWMSInspireScenario2);
        mWMSInspireTemporalReference->setObjectName(QString::fromUtf8("mWMSInspireTemporalReference"));
        sizePolicy7.setHeightForWidth(mWMSInspireTemporalReference->sizePolicy().hasHeightForWidth());
        mWMSInspireTemporalReference->setSizePolicy(sizePolicy7);

        gridLayout_17->addWidget(mWMSInspireTemporalReference, 0, 1, 1, 1);

        label_23 = new QLabel(mWMSInspireScenario2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_17->addWidget(label_23, 1, 0, 1, 1);

        mWMSInspireMetadataDate = new QDateEdit(mWMSInspireScenario2);
        mWMSInspireMetadataDate->setObjectName(QString::fromUtf8("mWMSInspireMetadataDate"));
        sizePolicy7.setHeightForWidth(mWMSInspireMetadataDate->sizePolicy().hasHeightForWidth());
        mWMSInspireMetadataDate->setSizePolicy(sizePolicy7);

        gridLayout_17->addWidget(mWMSInspireMetadataDate, 1, 1, 1, 1);

        label_22 = new QLabel(mWMSInspireScenario2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_17->addWidget(label_22, 0, 0, 1, 1);


        gridLayout_14->addWidget(mWMSInspireScenario2, 4, 0, 1, 2);

        mWMSInspireScenario1 = new QGroupBox(mWMSInspire);
        mWMSInspireScenario1->setObjectName(QString::fromUtf8("mWMSInspireScenario1"));
        mWMSInspireScenario1->setCheckable(true);
        mWMSInspireScenario1->setChecked(false);
        gridLayout_15 = new QGridLayout(mWMSInspireScenario1);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        mWMSInspireMetadataUrl = new QLineEdit(mWMSInspireScenario1);
        mWMSInspireMetadataUrl->setObjectName(QString::fromUtf8("mWMSInspireMetadataUrl"));

        gridLayout_15->addWidget(mWMSInspireMetadataUrl, 0, 1, 1, 1);

        label_8 = new QLabel(mWMSInspireScenario1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_15->addWidget(label_8, 0, 0, 1, 1);

        mWMSInspireMetadataUrlType = new QComboBox(mWMSInspireScenario1);
        mWMSInspireMetadataUrlType->addItem(QString());
        mWMSInspireMetadataUrlType->addItem(QString());
        mWMSInspireMetadataUrlType->addItem(QString());
        mWMSInspireMetadataUrlType->setObjectName(QString::fromUtf8("mWMSInspireMetadataUrlType"));

        gridLayout_15->addWidget(mWMSInspireMetadataUrlType, 1, 1, 1, 1);

        label_24 = new QLabel(mWMSInspireScenario1);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_15->addWidget(label_24, 1, 0, 1, 1);


        gridLayout_14->addWidget(mWMSInspireScenario1, 3, 0, 1, 2);


        gridLayout_13->addWidget(mWMSInspire, 2, 0, 1, 3);

        grpWMSList = new QgsCollapsibleGroupBox(grpWMSCapabilities);
        grpWMSList->setObjectName(QString::fromUtf8("grpWMSList"));
        grpWMSList->setCheckable(true);
        grpWMSList->setChecked(false);
        grpWMSList->setProperty("collapsed", QVariant(false));
        grpWMSList->setProperty("saveCollapsedState", QVariant(true));
        gridLayout_5 = new QGridLayout(grpWMSList);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pbnWMSRemoveSRS = new QToolButton(grpWMSList);
        pbnWMSRemoveSRS->setObjectName(QString::fromUtf8("pbnWMSRemoveSRS"));
        pbnWMSRemoveSRS->setIcon(icon14);

        gridLayout_5->addWidget(pbnWMSRemoveSRS, 1, 1, 1, 1);

        mWMSList = new QListWidget(grpWMSList);
        mWMSList->setObjectName(QString::fromUtf8("mWMSList"));

        gridLayout_5->addWidget(mWMSList, 0, 0, 1, 4);

        pbnWMSSetUsedSRS = new QPushButton(grpWMSList);
        pbnWMSSetUsedSRS->setObjectName(QString::fromUtf8("pbnWMSSetUsedSRS"));

        gridLayout_5->addWidget(pbnWMSSetUsedSRS, 1, 2, 1, 1);

        pbnWMSAddSRS = new QToolButton(grpWMSList);
        pbnWMSAddSRS->setObjectName(QString::fromUtf8("pbnWMSAddSRS"));
        pbnWMSAddSRS->setIcon(icon13);

        gridLayout_5->addWidget(pbnWMSAddSRS, 1, 0, 1, 1);


        gridLayout_13->addWidget(grpWMSList, 0, 2, 1, 1);

        grpWMSExt = new QgsCollapsibleGroupBox(grpWMSCapabilities);
        grpWMSExt->setObjectName(QString::fromUtf8("grpWMSExt"));
        grpWMSExt->setCheckable(true);
        grpWMSExt->setChecked(false);
        grpWMSExt->setProperty("collapsed", QVariant(false));
        grpWMSExt->setProperty("saveCollapsedState", QVariant(true));
        gridLayout_4 = new QGridLayout(grpWMSExt);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mWMSExtMinX = new QLineEdit(grpWMSExt);
        mWMSExtMinX->setObjectName(QString::fromUtf8("mWMSExtMinX"));

        gridLayout_4->addWidget(mWMSExtMinX, 0, 1, 1, 1);

        label_17 = new QLabel(grpWMSExt);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 5, 0, 1, 2);

        label_16 = new QLabel(grpWMSExt);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 0, 0, 1, 1);

        mWMSExtMinY = new QLineEdit(grpWMSExt);
        mWMSExtMinY->setObjectName(QString::fromUtf8("mWMSExtMinY"));

        gridLayout_4->addWidget(mWMSExtMinY, 1, 1, 1, 1);

        label_18 = new QLabel(grpWMSExt);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 2, 0, 1, 1);

        pbnWMSExtCanvas = new QPushButton(grpWMSExt);
        pbnWMSExtCanvas->setObjectName(QString::fromUtf8("pbnWMSExtCanvas"));

        gridLayout_4->addWidget(pbnWMSExtCanvas, 4, 0, 1, 2);

        label_19 = new QLabel(grpWMSExt);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 3, 0, 1, 1);

        mWMSExtMaxY = new QLineEdit(grpWMSExt);
        mWMSExtMaxY->setObjectName(QString::fromUtf8("mWMSExtMaxY"));

        gridLayout_4->addWidget(mWMSExtMaxY, 3, 1, 1, 1);

        mWMSExtMaxX = new QLineEdit(grpWMSExt);
        mWMSExtMaxX->setObjectName(QString::fromUtf8("mWMSExtMaxX"));

        gridLayout_4->addWidget(mWMSExtMaxX, 2, 1, 1, 1);


        gridLayout_13->addWidget(grpWMSExt, 0, 0, 1, 2);

        mSegmentizeFeatureInfoGeometryCheckBox = new QCheckBox(grpWMSCapabilities);
        mSegmentizeFeatureInfoGeometryCheckBox->setObjectName(QString::fromUtf8("mSegmentizeFeatureInfoGeometryCheckBox"));

        gridLayout_13->addWidget(mSegmentizeFeatureInfoGeometryCheckBox, 6, 0, 1, 2);

        grpWMSPrecision = new QHBoxLayout();
        grpWMSPrecision->setObjectName(QString::fromUtf8("grpWMSPrecision"));
        label_5 = new QLabel(grpWMSCapabilities);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        grpWMSPrecision->addWidget(label_5);

        mWMSPrecisionSpinBox = new QgsSpinBox(grpWMSCapabilities);
        mWMSPrecisionSpinBox->setObjectName(QString::fromUtf8("mWMSPrecisionSpinBox"));
        mWMSPrecisionSpinBox->setMinimum(1);
        mWMSPrecisionSpinBox->setMaximum(17);
        mWMSPrecisionSpinBox->setValue(8);

        grpWMSPrecision->addWidget(mWMSPrecisionSpinBox);


        gridLayout_13->addLayout(grpWMSPrecision, 7, 0, 1, 3);

        mWMSPrintLayoutGroupBox = new QgsCollapsibleGroupBox(grpWMSCapabilities);
        mWMSPrintLayoutGroupBox->setObjectName(QString::fromUtf8("mWMSPrintLayoutGroupBox"));
        mWMSPrintLayoutGroupBox->setCheckable(true);
        mWMSPrintLayoutGroupBox->setChecked(false);
        mWMSPrintLayoutGroupBox->setProperty("collapsed", QVariant(false));
        mWMSPrintLayoutGroupBox->setProperty("saveCollapsedState", QVariant(true));
        gridLayout_10 = new QGridLayout(mWMSPrintLayoutGroupBox);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        mPrintLayoutListWidget = new QListWidget(mWMSPrintLayoutGroupBox);
        mPrintLayoutListWidget->setObjectName(QString::fromUtf8("mPrintLayoutListWidget"));

        gridLayout_10->addWidget(mPrintLayoutListWidget, 0, 0, 1, 3);

        mAddWMSPrintLayoutButton = new QToolButton(mWMSPrintLayoutGroupBox);
        mAddWMSPrintLayoutButton->setObjectName(QString::fromUtf8("mAddWMSPrintLayoutButton"));
        mAddWMSPrintLayoutButton->setIcon(icon13);

        gridLayout_10->addWidget(mAddWMSPrintLayoutButton, 1, 0, 1, 1);

        mRemoveWMSPrintLayoutButton = new QToolButton(mWMSPrintLayoutGroupBox);
        mRemoveWMSPrintLayoutButton->setObjectName(QString::fromUtf8("mRemoveWMSPrintLayoutButton"));
        mRemoveWMSPrintLayoutButton->setIcon(icon14);

        gridLayout_10->addWidget(mRemoveWMSPrintLayoutButton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_13->addWidget(mWMSPrintLayoutGroupBox, 1, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mWMSUrlLabel = new QLabel(grpWMSCapabilities);
        mWMSUrlLabel->setObjectName(QString::fromUtf8("mWMSUrlLabel"));

        horizontalLayout_2->addWidget(mWMSUrlLabel);

        mWMSUrlLineEdit = new QLineEdit(grpWMSCapabilities);
        mWMSUrlLineEdit->setObjectName(QString::fromUtf8("mWMSUrlLineEdit"));

        horizontalLayout_2->addWidget(mWMSUrlLineEdit);


        gridLayout_13->addLayout(horizontalLayout_2, 8, 0, 1, 2);

        mWmsUseLayerIDs = new QCheckBox(grpWMSCapabilities);
        mWmsUseLayerIDs->setObjectName(QString::fromUtf8("mWmsUseLayerIDs"));

        gridLayout_13->addWidget(mWmsUseLayerIDs, 3, 0, 1, 1);

        mWMSDefaultMapUnitsPerMmLayout = new QHBoxLayout();
        mWMSDefaultMapUnitsPerMmLayout->setObjectName(QString::fromUtf8("mWMSDefaultMapUnitsPerMmLayout"));
        mWMSDefaultMapUnitsPerMmLabel = new QLabel(grpWMSCapabilities);
        mWMSDefaultMapUnitsPerMmLabel->setObjectName(QString::fromUtf8("mWMSDefaultMapUnitsPerMmLabel"));

        mWMSDefaultMapUnitsPerMmLayout->addWidget(mWMSDefaultMapUnitsPerMmLabel);


        gridLayout_13->addLayout(mWMSDefaultMapUnitsPerMmLayout, 13, 0, 1, 3);

        mLayerRestrictionsGroupBox = new QgsCollapsibleGroupBox(grpWMSCapabilities);
        mLayerRestrictionsGroupBox->setObjectName(QString::fromUtf8("mLayerRestrictionsGroupBox"));
        mLayerRestrictionsGroupBox->setCheckable(true);
        mLayerRestrictionsGroupBox->setChecked(false);
        mLayerRestrictionsGroupBox->setProperty("collapsed", QVariant(false));
        mLayerRestrictionsGroupBox->setProperty("saveCollapsedState", QVariant(true));
        gridLayout = new QGridLayout(mLayerRestrictionsGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mLayerRestrictionsListWidget = new QListWidget(mLayerRestrictionsGroupBox);
        mLayerRestrictionsListWidget->setObjectName(QString::fromUtf8("mLayerRestrictionsListWidget"));

        gridLayout->addWidget(mLayerRestrictionsListWidget, 0, 0, 1, 3);

        mAddLayerRestrictionButton = new QToolButton(mLayerRestrictionsGroupBox);
        mAddLayerRestrictionButton->setObjectName(QString::fromUtf8("mAddLayerRestrictionButton"));
        mAddLayerRestrictionButton->setIcon(icon13);

        gridLayout->addWidget(mAddLayerRestrictionButton, 1, 0, 1, 1);

        mRemoveLayerRestrictionButton = new QToolButton(mLayerRestrictionsGroupBox);
        mRemoveLayerRestrictionButton->setObjectName(QString::fromUtf8("mRemoveLayerRestrictionButton"));
        mRemoveLayerRestrictionButton->setIcon(icon14);

        gridLayout->addWidget(mRemoveLayerRestrictionButton, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);


        gridLayout_13->addWidget(mLayerRestrictionsGroupBox, 1, 2, 1, 1);

        mUseAttributeFormSettingsCheckBox = new QCheckBox(grpWMSCapabilities);
        mUseAttributeFormSettingsCheckBox->setObjectName(QString::fromUtf8("mUseAttributeFormSettingsCheckBox"));

        gridLayout_13->addWidget(mUseAttributeFormSettingsCheckBox, 4, 0, 1, 1);


        verticalLayout_13->addWidget(grpWMSCapabilities);

        grpWmtsCapabilities = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_5);
        grpWmtsCapabilities->setObjectName(QString::fromUtf8("grpWmtsCapabilities"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(3);
        sizePolicy9.setHeightForWidth(grpWmtsCapabilities->sizePolicy().hasHeightForWidth());
        grpWmtsCapabilities->setSizePolicy(sizePolicy9);
        gridLayout_20 = new QGridLayout(grpWmtsCapabilities);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        mWMTSMinScaleLabel = new QLabel(grpWmtsCapabilities);
        mWMTSMinScaleLabel->setObjectName(QString::fromUtf8("mWMTSMinScaleLabel"));

        horizontalLayout_16->addWidget(mWMTSMinScaleLabel);

        mWMTSMinScaleSpinBox = new QgsSpinBox(grpWmtsCapabilities);
        mWMTSMinScaleSpinBox->setObjectName(QString::fromUtf8("mWMTSMinScaleSpinBox"));
        mWMTSMinScaleSpinBox->setMinimum(1);
        mWMTSMinScaleSpinBox->setMaximum(1000000000);
        mWMTSMinScaleSpinBox->setValue(5000);

        horizontalLayout_16->addWidget(mWMTSMinScaleSpinBox);


        gridLayout_20->addLayout(horizontalLayout_16, 3, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        mWMTSUrlLabel = new QLabel(grpWmtsCapabilities);
        mWMTSUrlLabel->setObjectName(QString::fromUtf8("mWMTSUrlLabel"));

        horizontalLayout_15->addWidget(mWMTSUrlLabel);

        mWMTSUrlLineEdit = new QLineEdit(grpWmtsCapabilities);
        mWMTSUrlLineEdit->setObjectName(QString::fromUtf8("mWMTSUrlLineEdit"));

        horizontalLayout_15->addWidget(mWMTSUrlLineEdit);


        gridLayout_20->addLayout(horizontalLayout_15, 4, 0, 1, 1);

        horizontalLayout_17a = new QHBoxLayout();
        horizontalLayout_17a->setObjectName(QString::fromUtf8("horizontalLayout_17a"));
        vlWmtsLayers = new QVBoxLayout();
        vlWmtsLayers->setObjectName(QString::fromUtf8("vlWmtsLayers"));
        label_31 = new QLabel(grpWmtsCapabilities);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        vlWmtsLayers->addWidget(label_31);

        twWmtsLayers = new QTreeWidget(grpWmtsCapabilities);
        twWmtsLayers->setObjectName(QString::fromUtf8("twWmtsLayers"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(twWmtsLayers->sizePolicy().hasHeightForWidth());
        twWmtsLayers->setSizePolicy(sizePolicy10);

        vlWmtsLayers->addWidget(twWmtsLayers);


        horizontalLayout_17a->addLayout(vlWmtsLayers);

        vlWmtsGrids = new QVBoxLayout();
        vlWmtsGrids->setObjectName(QString::fromUtf8("vlWmtsGrids"));
        label_32 = new QLabel(grpWmtsCapabilities);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        vlWmtsGrids->addWidget(label_32);

        twWmtsGrids = new QTreeWidget(grpWmtsCapabilities);
        twWmtsGrids->setObjectName(QString::fromUtf8("twWmtsGrids"));

        vlWmtsGrids->addWidget(twWmtsGrids);


        horizontalLayout_17a->addLayout(vlWmtsGrids);


        gridLayout_20->addLayout(horizontalLayout_17a, 0, 0, 1, 1);


        verticalLayout_13->addWidget(grpWmtsCapabilities);

        grpWFSCapabilities = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_5);
        grpWFSCapabilities->setObjectName(QString::fromUtf8("grpWFSCapabilities"));
        sizePolicy9.setHeightForWidth(grpWFSCapabilities->sizePolicy().hasHeightForWidth());
        grpWFSCapabilities->setSizePolicy(sizePolicy9);
        grpWFSCapabilities->setProperty("syncGroup", QVariant(QString::fromUtf8("projowsserver")));
        gridLayout_8 = new QGridLayout(grpWFSCapabilities);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        twWFSLayers = new QTableWidget(grpWFSCapabilities);
        if (twWFSLayers->columnCount() < 6)
            twWFSLayers->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twWFSLayers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twWFSLayers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twWFSLayers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twWFSLayers->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twWFSLayers->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twWFSLayers->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        twWFSLayers->setObjectName(QString::fromUtf8("twWFSLayers"));
        sizePolicy10.setHeightForWidth(twWFSLayers->sizePolicy().hasHeightForWidth());
        twWFSLayers->setSizePolicy(sizePolicy10);

        gridLayout_8->addWidget(twWFSLayers, 0, 0, 1, 2);

        pbnWFSLayersDeselectAll = new QPushButton(grpWFSCapabilities);
        pbnWFSLayersDeselectAll->setObjectName(QString::fromUtf8("pbnWFSLayersDeselectAll"));

        gridLayout_8->addWidget(pbnWFSLayersDeselectAll, 1, 1, 1, 1);

        pbnWFSLayersSelectAll = new QPushButton(grpWFSCapabilities);
        pbnWFSLayersSelectAll->setObjectName(QString::fromUtf8("pbnWFSLayersSelectAll"));

        gridLayout_8->addWidget(pbnWFSLayersSelectAll, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        mWFSUrlLabel = new QLabel(grpWFSCapabilities);
        mWFSUrlLabel->setObjectName(QString::fromUtf8("mWFSUrlLabel"));

        horizontalLayout_8->addWidget(mWFSUrlLabel);

        mWFSUrlLineEdit = new QLineEdit(grpWFSCapabilities);
        mWFSUrlLineEdit->setObjectName(QString::fromUtf8("mWFSUrlLineEdit"));

        horizontalLayout_8->addWidget(mWFSUrlLineEdit);


        gridLayout_8->addLayout(horizontalLayout_8, 3, 0, 1, 2);


        verticalLayout_13->addWidget(grpWFSCapabilities);

        grpWCSCapabilities = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_5);
        grpWCSCapabilities->setObjectName(QString::fromUtf8("grpWCSCapabilities"));
        sizePolicy9.setHeightForWidth(grpWCSCapabilities->sizePolicy().hasHeightForWidth());
        grpWCSCapabilities->setSizePolicy(sizePolicy9);
        grpWCSCapabilities->setProperty("syncGroup", QVariant(QString::fromUtf8("projowsserver")));
        gridLayout_9 = new QGridLayout(grpWCSCapabilities);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        pbnWCSLayersDeselectAll = new QPushButton(grpWCSCapabilities);
        pbnWCSLayersDeselectAll->setObjectName(QString::fromUtf8("pbnWCSLayersDeselectAll"));

        gridLayout_9->addWidget(pbnWCSLayersDeselectAll, 1, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        mWCSUrlLabel = new QLabel(grpWCSCapabilities);
        mWCSUrlLabel->setObjectName(QString::fromUtf8("mWCSUrlLabel"));

        horizontalLayout_9->addWidget(mWCSUrlLabel);

        mWCSUrlLineEdit = new QLineEdit(grpWCSCapabilities);
        mWCSUrlLineEdit->setObjectName(QString::fromUtf8("mWCSUrlLineEdit"));

        horizontalLayout_9->addWidget(mWCSUrlLineEdit);


        gridLayout_9->addLayout(horizontalLayout_9, 3, 0, 1, 2);

        pbnWCSLayersSelectAll = new QPushButton(grpWCSCapabilities);
        pbnWCSLayersSelectAll->setObjectName(QString::fromUtf8("pbnWCSLayersSelectAll"));

        gridLayout_9->addWidget(pbnWCSLayersSelectAll, 1, 0, 1, 1);

        twWCSLayers = new QTableWidget(grpWCSCapabilities);
        if (twWCSLayers->columnCount() < 2)
            twWCSLayers->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twWCSLayers->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        twWCSLayers->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        twWCSLayers->setObjectName(QString::fromUtf8("twWCSLayers"));
        sizePolicy10.setHeightForWidth(twWCSLayers->sizePolicy().hasHeightForWidth());
        twWCSLayers->setSizePolicy(sizePolicy10);

        gridLayout_9->addWidget(twWCSLayers, 0, 0, 1, 2);


        verticalLayout_13->addWidget(grpWCSCapabilities);

        mOWSCheckerGroupBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents_5);
        mOWSCheckerGroupBox->setObjectName(QString::fromUtf8("mOWSCheckerGroupBox"));
        sizePolicy9.setHeightForWidth(mOWSCheckerGroupBox->sizePolicy().hasHeightForWidth());
        mOWSCheckerGroupBox->setSizePolicy(sizePolicy9);
        verticalLayout_24 = new QVBoxLayout(mOWSCheckerGroupBox);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pbnLaunchOWSChecker = new QPushButton(mOWSCheckerGroupBox);
        pbnLaunchOWSChecker->setObjectName(QString::fromUtf8("pbnLaunchOWSChecker"));

        horizontalLayout_11->addWidget(pbnLaunchOWSChecker);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        verticalLayout_24->addLayout(horizontalLayout_11);

        teOWSChecker = new QTextEdit(mOWSCheckerGroupBox);
        teOWSChecker->setObjectName(QString::fromUtf8("teOWSChecker"));
        teOWSChecker->setEnabled(true);
        teOWSChecker->setMinimumSize(QSize(0, 200));
        teOWSChecker->setAcceptDrops(true);
        teOWSChecker->setLineWidth(2);
        teOWSChecker->setReadOnly(true);
        teOWSChecker->setAcceptRichText(true);

        verticalLayout_24->addWidget(teOWSChecker);


        verticalLayout_13->addWidget(mOWSCheckerGroupBox);

        verticalSpacer_6 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_6);

        scrollArea_5->setWidget(scrollAreaWidgetContents_5);

        verticalLayout_14->addWidget(scrollArea_5);

        mOptionsStackedWidget->addWidget(mProjOptsOWS);
        mTemporalOptions = new QWidget();
        mTemporalOptions->setObjectName(QString::fromUtf8("mTemporalOptions"));
        verticalLayout_20 = new QVBoxLayout(mTemporalOptions);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        mTemporalOptionsGroup = new QGroupBox(mTemporalOptions);
        mTemporalOptionsGroup->setObjectName(QString::fromUtf8("mTemporalOptionsGroup"));
        gridLayout_22 = new QGridLayout(mTemporalOptionsGroup);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        mStartDateTimeEdit = new QgsDateTimeEdit(mTemporalOptionsGroup);
        mStartDateTimeEdit->setObjectName(QString::fromUtf8("mStartDateTimeEdit"));
        mStartDateTimeEdit->setTimeSpec(Qt::UTC);

        gridLayout_22->addWidget(mStartDateTimeEdit, 0, 1, 1, 1);

        label_35 = new QLabel(mTemporalOptionsGroup);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_22->addWidget(label_35, 0, 0, 1, 1);

        mCalculateFromLayerButton = new QPushButton(mTemporalOptionsGroup);
        mCalculateFromLayerButton->setObjectName(QString::fromUtf8("mCalculateFromLayerButton"));

        gridLayout_22->addWidget(mCalculateFromLayerButton, 3, 1, 1, 1);

        label_36 = new QLabel(mTemporalOptionsGroup);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_22->addWidget(label_36, 2, 0, 1, 1);

        mEndDateTimeEdit = new QgsDateTimeEdit(mTemporalOptionsGroup);
        mEndDateTimeEdit->setObjectName(QString::fromUtf8("mEndDateTimeEdit"));
        mEndDateTimeEdit->setTimeSpec(Qt::UTC);

        gridLayout_22->addWidget(mEndDateTimeEdit, 2, 1, 1, 1);

        gridLayout_22->setColumnStretch(1, 1);

        verticalLayout_20->addWidget(mTemporalOptionsGroup);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_20->addItem(verticalSpacer_2);

        mOptionsStackedWidget->addWidget(mTemporalOptions);

        verticalLayout_3->addWidget(mOptionsStackedWidget);

        mOptionsSplitter->addWidget(mOptionsFrame);

        gridLayout_21->addWidget(mOptionsSplitter, 0, 0, 1, 1);

        mButtonBoxFrame = new QFrame(QgsProjectPropertiesBase);
        mButtonBoxFrame->setObjectName(QString::fromUtf8("mButtonBoxFrame"));
        sizePolicy3.setHeightForWidth(mButtonBoxFrame->sizePolicy().hasHeightForWidth());
        mButtonBoxFrame->setSizePolicy(sizePolicy3);
        mButtonBoxFrame->setFrameShape(QFrame::NoFrame);
        mButtonBoxFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(mButtonBoxFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(mButtonBoxFrame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout_21->addWidget(mButtonBoxFrame, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_4->setBuddy(titleEdit);
        textLabel1->setBuddy(pbnSelectionColor);
        label_3->setBuddy(cbxAbsolutePath);
        label_30->setBuddy(titleEdit);
        label->setBuddy(pbnCanvasColor);
        label_11->setBuddy(mWMSContactOrganization);
        label_12->setBuddy(mWMSContactPhone);
        label_10->setBuddy(mWMSTitle);
        label_15->setBuddy(mWMSAbstract);
        label_9->setBuddy(mWMSContactPerson);
        label_17->setBuddy(mWMSExtMinY);
        label_16->setBuddy(mWMSExtMinX);
        label_18->setBuddy(mWMSExtMaxX);
        label_19->setBuddy(mWMSExtMaxY);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(mSearchLineEdit, mOptionsListWidget);
        QWidget::setTabOrder(mOptionsListWidget, scrollArea_2);
        QWidget::setTabOrder(scrollArea_2, mProjectFileLineEdit);
        QWidget::setTabOrder(mProjectFileLineEdit, mButtonOpenProjectFolder);
        QWidget::setTabOrder(mButtonOpenProjectFolder, mProjectHomeLineEdit);
        QWidget::setTabOrder(mProjectHomeLineEdit, mButtonSetProjectHome);
        QWidget::setTabOrder(mButtonSetProjectHome, titleEdit);
        QWidget::setTabOrder(titleEdit, pbnSelectionColor);
        QWidget::setTabOrder(pbnSelectionColor, pbnCanvasColor);
        QWidget::setTabOrder(pbnCanvasColor, cbxAbsolutePath);
        QWidget::setTabOrder(cbxAbsolutePath, mMapTileRenderingCheckBox);
        QWidget::setTabOrder(mMapTileRenderingCheckBox, cmbEllipsoid);
        QWidget::setTabOrder(cmbEllipsoid, leSemiMajor);
        QWidget::setTabOrder(leSemiMajor, leSemiMinor);
        QWidget::setTabOrder(leSemiMinor, mDistanceUnitsCombo);
        QWidget::setTabOrder(mDistanceUnitsCombo, mAreaUnitsCombo);
        QWidget::setTabOrder(mAreaUnitsCombo, mCoordinateDisplayComboBox);
        QWidget::setTabOrder(mCoordinateDisplayComboBox, radAutomatic);
        QWidget::setTabOrder(radAutomatic, radManual);
        QWidget::setTabOrder(radManual, spinBoxDP);
        QWidget::setTabOrder(spinBoxDP, mCustomizeBearingFormatButton);
        QWidget::setTabOrder(mCustomizeBearingFormatButton, cbtsLocale);
        QWidget::setTabOrder(cbtsLocale, generateTsFileButton);
        QWidget::setTabOrder(generateTsFileButton, grpProjectScales);
        QWidget::setTabOrder(grpProjectScales, lstScales);
        QWidget::setTabOrder(lstScales, pbnAddScale);
        QWidget::setTabOrder(pbnAddScale, pbnRemoveScale);
        QWidget::setTabOrder(pbnRemoveScale, pbnImportScales);
        QWidget::setTabOrder(pbnImportScales, pbnExportScales);
        QWidget::setTabOrder(pbnExportScales, mExtentGroupBox);
        QWidget::setTabOrder(mExtentGroupBox, scrollArea);
        QWidget::setTabOrder(scrollArea, scrollArea_3);
        QWidget::setTabOrder(scrollArea_3, mShowDatumTransformDialogCheckBox);
        QWidget::setTabOrder(mShowDatumTransformDialogCheckBox, scrollArea_4);
        QWidget::setTabOrder(scrollArea_4, cboStyleMarker);
        QWidget::setTabOrder(cboStyleMarker, pbtnStyleMarker);
        QWidget::setTabOrder(pbtnStyleMarker, cboStyleLine);
        QWidget::setTabOrder(cboStyleLine, pbtnStyleLine);
        QWidget::setTabOrder(pbtnStyleLine, cboStyleFill);
        QWidget::setTabOrder(cboStyleFill, pbtnStyleFill);
        QWidget::setTabOrder(pbtnStyleFill, cboStyleColorRamp);
        QWidget::setTabOrder(cboStyleColorRamp, pbtnStyleColorRamp);
        QWidget::setTabOrder(pbtnStyleColorRamp, mDefaultOpacityWidget);
        QWidget::setTabOrder(mDefaultOpacityWidget, cbxStyleRandomColors);
        QWidget::setTabOrder(cbxStyleRandomColors, pbtnStyleManager);
        QWidget::setTabOrder(pbtnStyleManager, mButtonAddColor);
        QWidget::setTabOrder(mButtonAddColor, mButtonRemoveColor);
        QWidget::setTabOrder(mButtonRemoveColor, mButtonCopyColors);
        QWidget::setTabOrder(mButtonCopyColors, mButtonPasteColors);
        QWidget::setTabOrder(mButtonPasteColors, mButtonImportColors);
        QWidget::setTabOrder(mButtonImportColors, mButtonExportColors);
        QWidget::setTabOrder(mButtonExportColors, mAutoTransaction);
        QWidget::setTabOrder(mAutoTransaction, mEvaluateDefaultValues);
        QWidget::setTabOrder(mEvaluateDefaultValues, mTrustProjectCheckBox);
        QWidget::setTabOrder(mTrustProjectCheckBox, mLayerCapabilitiesTree);
        QWidget::setTabOrder(mLayerCapabilitiesTree, mLayerCapabilitiesToggleSelectionButton);
        QWidget::setTabOrder(mLayerCapabilitiesToggleSelectionButton, mShowSpatialLayersCheckBox);
        QWidget::setTabOrder(mShowSpatialLayersCheckBox, mLayerCapabilitiesTreeFilterLineEdit);
        QWidget::setTabOrder(mLayerCapabilitiesTreeFilterLineEdit, scrollArea_6);
        QWidget::setTabOrder(scrollArea_6, grpPythonMacros);
        QWidget::setTabOrder(grpPythonMacros, scrollArea_5);
        QWidget::setTabOrder(scrollArea_5, grpOWSServiceCapabilities);
        QWidget::setTabOrder(grpOWSServiceCapabilities, mWMSName);
        QWidget::setTabOrder(mWMSName, mWMSTitle);
        QWidget::setTabOrder(mWMSTitle, mWMSContactOrganization);
        QWidget::setTabOrder(mWMSContactOrganization, mWMSOnlineResourceLineEdit);
        QWidget::setTabOrder(mWMSOnlineResourceLineEdit, mWMSOnlineResourceExpressionButton);
        QWidget::setTabOrder(mWMSOnlineResourceExpressionButton, mWMSContactPerson);
        QWidget::setTabOrder(mWMSContactPerson, mWMSContactPositionCb);
        QWidget::setTabOrder(mWMSContactPositionCb, mWMSContactMail);
        QWidget::setTabOrder(mWMSContactMail, mWMSContactPhone);
        QWidget::setTabOrder(mWMSContactPhone, mWMSAbstract);
        QWidget::setTabOrder(mWMSAbstract, mWMSFeesCb);
        QWidget::setTabOrder(mWMSFeesCb, mWMSAccessConstraintsCb);
        QWidget::setTabOrder(mWMSAccessConstraintsCb, mWMSKeywordList);
        QWidget::setTabOrder(mWMSKeywordList, grpWMSExt);
        QWidget::setTabOrder(grpWMSExt, mWMSExtMinX);
        QWidget::setTabOrder(mWMSExtMinX, mWMSExtMinY);
        QWidget::setTabOrder(mWMSExtMinY, mWMSExtMaxX);
        QWidget::setTabOrder(mWMSExtMaxX, mWMSExtMaxY);
        QWidget::setTabOrder(mWMSExtMaxY, pbnWMSExtCanvas);
        QWidget::setTabOrder(pbnWMSExtCanvas, grpWMSList);
        QWidget::setTabOrder(grpWMSList, pbnWMSAddSRS);
        QWidget::setTabOrder(pbnWMSAddSRS, pbnWMSRemoveSRS);
        QWidget::setTabOrder(pbnWMSRemoveSRS, pbnWMSSetUsedSRS);
        QWidget::setTabOrder(pbnWMSSetUsedSRS, mWMSList);
        QWidget::setTabOrder(mWMSList, mWMSPrintLayoutGroupBox);
        QWidget::setTabOrder(mWMSPrintLayoutGroupBox, mAddWMSPrintLayoutButton);
        QWidget::setTabOrder(mAddWMSPrintLayoutButton, mRemoveWMSPrintLayoutButton);
        QWidget::setTabOrder(mRemoveWMSPrintLayoutButton, mPrintLayoutListWidget);
        QWidget::setTabOrder(mPrintLayoutListWidget, mLayerRestrictionsGroupBox);
        QWidget::setTabOrder(mLayerRestrictionsGroupBox, mAddLayerRestrictionButton);
        QWidget::setTabOrder(mAddLayerRestrictionButton, mRemoveLayerRestrictionButton);
        QWidget::setTabOrder(mRemoveLayerRestrictionButton, mLayerRestrictionsListWidget);
        QWidget::setTabOrder(mLayerRestrictionsListWidget, mWMSInspire);
        QWidget::setTabOrder(mWMSInspire, mWMSInspireLanguage);
        QWidget::setTabOrder(mWMSInspireLanguage, mWMSInspireScenario1);
        QWidget::setTabOrder(mWMSInspireScenario1, mWMSInspireMetadataUrl);
        QWidget::setTabOrder(mWMSInspireMetadataUrl, mWMSInspireMetadataUrlType);
        QWidget::setTabOrder(mWMSInspireMetadataUrlType, mWMSInspireScenario2);
        QWidget::setTabOrder(mWMSInspireScenario2, mWMSInspireTemporalReference);
        QWidget::setTabOrder(mWMSInspireTemporalReference, mWMSInspireMetadataDate);
        QWidget::setTabOrder(mWMSInspireMetadataDate, mWmsUseLayerIDs);
        QWidget::setTabOrder(mWmsUseLayerIDs, mUseAttributeFormSettingsCheckBox);
        QWidget::setTabOrder(mUseAttributeFormSettingsCheckBox, mAddWktGeometryCheckBox);
        QWidget::setTabOrder(mAddWktGeometryCheckBox, mSegmentizeFeatureInfoGeometryCheckBox);
        QWidget::setTabOrder(mSegmentizeFeatureInfoGeometryCheckBox, mWMSPrecisionSpinBox);
        QWidget::setTabOrder(mWMSPrecisionSpinBox, mWMSUrlLineEdit);
        QWidget::setTabOrder(mWMSUrlLineEdit, mMaxWidthLineEdit);
        QWidget::setTabOrder(mMaxWidthLineEdit, mMaxHeightLineEdit);
        QWidget::setTabOrder(mMaxHeightLineEdit, mWMSImageQualitySpinBox);
        QWidget::setTabOrder(mWMSImageQualitySpinBox, mWMSMaxAtlasFeaturesSpinBox);
        QWidget::setTabOrder(mWMSMaxAtlasFeaturesSpinBox, mWMSTileBufferSpinBox);
        QWidget::setTabOrder(mWMSTileBufferSpinBox, twWmtsLayers);
        QWidget::setTabOrder(twWmtsLayers, twWmtsGrids);
        QWidget::setTabOrder(twWmtsGrids, mWMTSMinScaleSpinBox);
        QWidget::setTabOrder(mWMTSMinScaleSpinBox, mWMTSUrlLineEdit);
        QWidget::setTabOrder(mWMTSUrlLineEdit, twWFSLayers);
        QWidget::setTabOrder(twWFSLayers, pbnWFSLayersSelectAll);
        QWidget::setTabOrder(pbnWFSLayersSelectAll, pbnWFSLayersDeselectAll);
        QWidget::setTabOrder(pbnWFSLayersDeselectAll, mWFSUrlLineEdit);
        QWidget::setTabOrder(mWFSUrlLineEdit, twWCSLayers);
        QWidget::setTabOrder(twWCSLayers, pbnWCSLayersSelectAll);
        QWidget::setTabOrder(pbnWCSLayersSelectAll, pbnWCSLayersDeselectAll);
        QWidget::setTabOrder(pbnWCSLayersDeselectAll, mWCSUrlLineEdit);
        QWidget::setTabOrder(mWCSUrlLineEdit, pbnLaunchOWSChecker);
        QWidget::setTabOrder(pbnLaunchOWSChecker, teOWSChecker);
        QWidget::setTabOrder(teOWSChecker, mStartDateTimeEdit);
        QWidget::setTabOrder(mStartDateTimeEdit, mEndDateTimeEdit);
        QWidget::setTabOrder(mEndDateTimeEdit, mCalculateFromLayerButton);

        retranslateUi(QgsProjectPropertiesBase);
        QObject::connect(mOptionsListWidget, SIGNAL(currentRowChanged(int)), mOptionsStackedWidget, SLOT(setCurrentIndex(int)));

        mOptionsStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsProjectPropertiesBase);
    } // setupUi

    void retranslateUi(QDialog *QgsProjectPropertiesBase)
    {
        QgsProjectPropertiesBase->setWindowTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Project Properties", nullptr));

        const bool __sortingEnabled = mOptionsListWidget->isSortingEnabled();
        mOptionsListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = mOptionsListWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "General", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "General", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem1 = mOptionsListWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Metadata", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = mOptionsListWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "View Settings", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem2->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "View Settings", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem3 = mOptionsListWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "CRS", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem3->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Coordinate Reference System", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem4 = mOptionsListWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Transformations", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem4->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Coordinate transformations and operations", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem5 = mOptionsListWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Default Styles", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem5->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Default styles", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem6 = mOptionsListWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Data Sources", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem6->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Data sources", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem7 = mOptionsListWidget->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Relations", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem7->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Relations", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem8 = mOptionsListWidget->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Variables", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem8->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Variables", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem9 = mOptionsListWidget->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Macros", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem9->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Macros", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem10 = mOptionsListWidget->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "QGIS Server", nullptr));
#if QT_CONFIG(tooltip)
        ___qlistwidgetitem10->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "WMS/WFS/WCS Server Configuration", nullptr));
#endif // QT_CONFIG(tooltip)
        QListWidgetItem *___qlistwidgetitem11 = mOptionsListWidget->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Temporal", nullptr));
        mOptionsListWidget->setSortingEnabled(__sortingEnabled);

        titleBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "General Settings", nullptr));
        label_4->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Pro&ject file", nullptr));
        textLabel1->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Selection color", nullptr));
        label_3->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Sa&ve paths", nullptr));
#if QT_CONFIG(tooltip)
        mProjectHomeLineEdit->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Project home path. Leave blank to use the current project file location.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mButtonSetProjectHome->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Set the project home path", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonSetProjectHome->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        titleEdit->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Descriptive project name", nullptr));
#endif // QT_CONFIG(tooltip)
        titleEdit->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Default project title", nullptr));
        label_2->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Project title", nullptr));
#if QT_CONFIG(tooltip)
        mMapTileRenderingCheckBox->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Checking this setting avoids visible edge artifacts when rendering this project as separate map tiles. Rendering performance will be degraded.", nullptr));
#endif // QT_CONFIG(tooltip)
        mMapTileRenderingCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Avoid artifacts when project is rendered as map tiles (degrades performance)", nullptr));
#if QT_CONFIG(tooltip)
        mButtonOpenProjectFolder->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Open folder containing the project", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonOpenProjectFolder->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
        label_30->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "&Project home", nullptr));
        pbnSelectionColor->setText(QString());
        label->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Back&ground color", nullptr));
        pbnCanvasColor->setText(QString());
        btnGrpMeasureEllipsoid->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Measurements", nullptr));
        label_28->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Units for distance measurement", nullptr));
        textLabel1_8->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Ellipsoid\n"
"(for distance and area calculations)", nullptr));
        label_41->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Semi-major", nullptr));
        label_42->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Semi-minor", nullptr));
        label_29->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Units for area measurement", nullptr));
        mCoordinateDisplayGroup->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Coordinate and Bearing Display", nullptr));
        label_26->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Coordinate precision", nullptr));
        label_25->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Display coordinates using", nullptr));
#if QT_CONFIG(tooltip)
        radAutomatic->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Automatically sets the number of decimal places to use when displaying coordinates", nullptr));
#endif // QT_CONFIG(tooltip)
        radAutomatic->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "A&utomatic", nullptr));
#if QT_CONFIG(tooltip)
        radManual->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Manually set the number of decimal places to use when displaying coordinates", nullptr));
#endif // QT_CONFIG(tooltip)
        radManual->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Manual", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxDP->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The number of decimal places for the manual option", nullptr));
#endif // QT_CONFIG(tooltip)
        labelDP->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "decimal places", nullptr));
        label_34->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Bearing format", nullptr));
        mCustomizeBearingFormatButton->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Customize\342\200\246", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Generate Project Translation File", nullptr));
        sourceLanguageLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Source language", nullptr));
        generateTsFileButton->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Generate TS File", nullptr));
        grpProjectScales->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Project Predefined Scales", nullptr));
#if QT_CONFIG(tooltip)
        pbnAddScale->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Add predefined scale", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnAddScale->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        pbnRemoveScale->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Remove selected scale", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnRemoveScale->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        pbnImportScales->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Import from file", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnImportScales->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        pbnExportScales->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Save to file", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnExportScales->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        mExtentGroupBox->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "If checked the preset extent will be used as the full extent of the project. If unchecked, the project's full extent will be calculated using the full extent of all layers in the project.", nullptr));
#endif // QT_CONFIG(tooltip)
        mExtentGroupBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Set Project Full Extent", nullptr));
        cbxProjectionEnabled->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Project Coordinate Reference System (CRS)", nullptr));
        mDatumTransformGroupBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Datum Transformations", nullptr));
        mShowDatumTransformDialogCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Ask for datum transformation if several are available (defined in global setting)", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Default Symbols", nullptr));
#if QT_CONFIG(tooltip)
        pbtnStyleMarker->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Edit symbol", nullptr));
#endif // QT_CONFIG(tooltip)
        pbtnStyleMarker->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
        lblStyleLine->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Line", nullptr));
        label_14->setText(QString());
        pixStyleFill->setText(QString());
#if QT_CONFIG(tooltip)
        pbtnStyleLine->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Edit symbol", nullptr));
#endif // QT_CONFIG(tooltip)
        pbtnStyleLine->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
        pixStyleLine->setText(QString());
        lblStyleColorRamp->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Color Ramp", nullptr));
        pixStyleMarker->setText(QString());
        lblStyleMarker->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Marker", nullptr));
#if QT_CONFIG(tooltip)
        pbtnStyleFill->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Edit symbol", nullptr));
#endif // QT_CONFIG(tooltip)
        pbtnStyleFill->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
        lblStyleFill->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Fill", nullptr));
#if QT_CONFIG(tooltip)
        pbtnStyleColorRamp->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Edit symbol", nullptr));
#endif // QT_CONFIG(tooltip)
        pbtnStyleColorRamp->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "\342\200\246", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Options", nullptr));
        label_27->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Opacity", nullptr));
        cbxStyleRandomColors->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Assign random colors to symbols", nullptr));
        pbtnStyleManager->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Style Manager", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Project Colors", nullptr));
#if QT_CONFIG(tooltip)
        mButtonCopyColors->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Copy colors", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonCopyColors->setText(QString());
#if QT_CONFIG(tooltip)
        mButtonAddColor->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Add color", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonAddColor->setText(QString());
#if QT_CONFIG(tooltip)
        mButtonPasteColors->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Paste colors", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonPasteColors->setText(QString());
#if QT_CONFIG(tooltip)
        mButtonRemoveColor->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Remove color", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonRemoveColor->setText(QString());
#if QT_CONFIG(tooltip)
        mButtonImportColors->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Import colors", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        mButtonImportColors->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        mButtonImportColors->setText(QString());
#if QT_CONFIG(tooltip)
        mButtonExportColors->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Export colors", nullptr));
#endif // QT_CONFIG(tooltip)
        mButtonExportColors->setText(QString());
#if QT_CONFIG(tooltip)
        mAutoTransaction->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "When enabled, layers from the same database connection will be put into a transaction group. Their edit state will be synchronized and changes to these layers will be sent to the provider immediately. Only supported for postgres, GPKG, spatialite and oracle.", nullptr));
#endif // QT_CONFIG(tooltip)
        mAutoTransaction->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Automatically create transaction groups where possible", nullptr));
#if QT_CONFIG(tooltip)
        mEvaluateDefaultValues->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "When enabled, default values will be evaluated as early as possible. This will fill default values in the add feature form already and not only create them on commit. Only supported for postgres, GPKG, spatialite and oracle.", nullptr));
#endif // QT_CONFIG(tooltip)
        mEvaluateDefaultValues->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Evaluate default values on provider side", nullptr));
#if QT_CONFIG(tooltip)
        mTrustProjectCheckBox->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Speed up project loading by skipping data checks in PostgreSQL layers. Useful in QGIS server context or project with huge database views or materialized views.", nullptr));
#endif // QT_CONFIG(tooltip)
        mTrustProjectCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Trust project when data source has no metadata", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Layers Capabilities", nullptr));
        mLayerCapabilitiesToggleSelectionButton->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Toggle Selection", nullptr));
#if QT_CONFIG(tooltip)
        mLayerCapabilitiesToggleSelectionButton->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Inverts the state of the selected checkboxes", nullptr));
#endif // QT_CONFIG(tooltip)
        mShowSpatialLayersCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Show spatial layers only", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Expression Variables", nullptr));
        grpPythonMacros->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "&Python Macros", nullptr));
        grpOWSServiceCapabilities->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Service Capabilities", nullptr));
#if QT_CONFIG(tooltip)
        mWMSName->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "A name used to identify the root layer. The short name is a text string used for machine-to-machine communication.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSName->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "A name used to identify the root layer. The short name is a text string used for machine-to-machine communication.", nullptr));
#if QT_CONFIG(tooltip)
        mWMSContactPositionCb->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person position for the service.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        mWMSContactPositionCb->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        mWMSAccessConstraintsCb->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Access constraints applied to the service.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mWMSContactPerson->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person name for the service.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSContactPerson->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person name for the service.", nullptr));
#if QT_CONFIG(tooltip)
        mWMSOnlineResourceLineEdit->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The web site URL of the service provider.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSOnlineResourceLineEdit->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "The web site URL of the service provider.", nullptr));
        mWMSOnlineResourceExpressionButton->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "...", nullptr));
        label_20->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Position", nullptr));
#if QT_CONFIG(tooltip)
        mWMSTitle->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The title should be brief yet descriptive enough to identify this service.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSTitle->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "The title should be brief yet descriptive enough to identify this service.", nullptr));
#if QT_CONFIG(tooltip)
        mWMSFeesCb->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Fees applied to the service.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mWMSContactMail->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person e-mail for the service.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSContactMail->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person e-mail for the service.", nullptr));
#if QT_CONFIG(tooltip)
        mWMSAbstract->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The abstract is a descriptive narrative providing more information about the service.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        mWMSAbstract->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        mWMSAbstract->setDocumentTitle(QString());
        label_11->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Or&ganization", nullptr));
        mWMSAccessConstraintsLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Access constraints", nullptr));
        label_12->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Phone", nullptr));
#if QT_CONFIG(tooltip)
        mWMSContactPhone->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person phone for the service.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSContactPhone->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "The contact person phone for the service.", nullptr));
        label_10->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Title", nullptr));
        warningLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "These parameters are used to generate the GetCapabilities document and shall be chosen carefully to avoid interoperability and security issues.", nullptr));
#if QT_CONFIG(tooltip)
        mWMSKeywordList->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "List of keywords separated by comma to help catalog searching.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSKeywordList->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "List of keywords separated by comma to help catalog searching.", nullptr));
        label_13->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "E-Mail", nullptr));
        label_15->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Abstract", nullptr));
        mWMSKeywordListLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Keyword list", nullptr));
        label_9->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "&Person", nullptr));
#if QT_CONFIG(tooltip)
        mWMSContactOrganization->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "The name of the service provider.", nullptr));
#endif // QT_CONFIG(tooltip)
        mWMSContactOrganization->setPlaceholderText(QCoreApplication::translate("QgsProjectPropertiesBase", "The name of the service provider.", nullptr));
        mWMSFeesLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Fees", nullptr));
        mWMSOnlineResourceLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Online resource", nullptr));
        label_6->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Short name", nullptr));
        grpWMSCapabilities->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "WMS capabilities", nullptr));
        mAddWktGeometryCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Add geometry to feature response", nullptr));
        mWMSImageQualityLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Quality for JPEG images ( 10 : smaller image - 100 : best quality )", nullptr));
        mWMSMaxAtlasFeaturesLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Maximum features for Atlas print requests", nullptr));
#if QT_CONFIG(tooltip)
        label_33->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "When using tiles set this to the size of the larger symbols to avoid cut symbols at tile boundaries. This works by drawing features that are outside the tile extent.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_33->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Tile buffer in pixels", nullptr));
        mMaxWidthLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Width", nullptr));
        mMaxHeightLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Height", nullptr));
        label_21->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Maximum image size for GetMap and GetLegendGraphic requests", nullptr));
        mWMSInspire->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "INSPIRE (European directive)", nullptr));
        label_7->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Service language", nullptr));
        mWMSInspireScenario2->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Scenario &2 - INSPIRE related fields using embedded service metadata", nullptr));
        label_23->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Metadata date", nullptr));
        label_22->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Last revision date", nullptr));
        mWMSInspireScenario1->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Scenario &1 - INSPIRE related fields using referenced external service metadata", nullptr));
        label_8->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Metadata URL", nullptr));
        mWMSInspireMetadataUrlType->setItemText(0, QCoreApplication::translate("QgsProjectPropertiesBase", "application/vnd.iso.19139+xml", nullptr));
        mWMSInspireMetadataUrlType->setItemText(1, QCoreApplication::translate("QgsProjectPropertiesBase", "application/vnd.ogc.csw.GetRecordByIdResponse_xml", nullptr));
        mWMSInspireMetadataUrlType->setItemText(2, QCoreApplication::translate("QgsProjectPropertiesBase", "application/vnd.ogc.csw_xml", nullptr));

        label_24->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "URL mime/type", nullptr));
        grpWMSList->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "CRS restrictions", nullptr));
#if QT_CONFIG(tooltip)
        pbnWMSRemoveSRS->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Remove selected CRS", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbnWMSSetUsedSRS->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Fetch all CRS's from layers", nullptr));
#endif // QT_CONFIG(tooltip)
        pbnWMSSetUsedSRS->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Used", nullptr));
#if QT_CONFIG(tooltip)
        pbnWMSAddSRS->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Add new CRS", nullptr));
#endif // QT_CONFIG(tooltip)
        grpWMSExt->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Ad&vertised extent", nullptr));
        mWMSExtMinX->setText(QString());
        label_17->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Min. &Y", nullptr));
        label_16->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Min. &X", nullptr));
        mWMSExtMinY->setText(QString());
        label_18->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Max. X", nullptr));
        pbnWMSExtCanvas->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Use Current Canvas Extent", nullptr));
        label_19->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Max. Y", nullptr));
        mWMSExtMaxY->setText(QString());
        mWMSExtMaxX->setText(QString());
        mSegmentizeFeatureInfoGeometryCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Segmentize feature info geometry", nullptr));
        label_5->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "GetFeatureInfo geometry precision (decimal places)", nullptr));
        mWMSPrintLayoutGroupBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Excl&ude layouts", nullptr));
#if QT_CONFIG(tooltip)
        mAddWMSPrintLayoutButton->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Add layout to exclude", nullptr));
#endif // QT_CONFIG(tooltip)
        mAddWMSPrintLayoutButton->setText(QString());
#if QT_CONFIG(tooltip)
        mRemoveWMSPrintLayoutButton->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Remove selected layout", nullptr));
#endif // QT_CONFIG(tooltip)
        mRemoveWMSPrintLayoutButton->setText(QString());
        mWMSUrlLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Advertised URL", nullptr));
        mWmsUseLayerIDs->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Use layer ids as names", nullptr));
        mWMSDefaultMapUnitsPerMmLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Default map units per mm in legend", nullptr));
        mLayerRestrictionsGroupBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Exclude layers", nullptr));
#if QT_CONFIG(tooltip)
        mAddLayerRestrictionButton->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Add layer to exclude", nullptr));
#endif // QT_CONFIG(tooltip)
        mAddLayerRestrictionButton->setText(QString());
#if QT_CONFIG(tooltip)
        mRemoveLayerRestrictionButton->setToolTip(QCoreApplication::translate("QgsProjectPropertiesBase", "Remove selected layer", nullptr));
#endif // QT_CONFIG(tooltip)
        mRemoveLayerRestrictionButton->setText(QString());
        mUseAttributeFormSettingsCheckBox->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Use attribute form settings for GetFeatureInfo response", nullptr));
        grpWmtsCapabilities->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "WMTS capabilities", nullptr));
        mWMTSMinScaleLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Minimum scale", nullptr));
        mWMTSUrlLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Advertised URL", nullptr));
        label_31->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Published layers", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = twWmtsLayers->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("QgsProjectPropertiesBase", "JPEG", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("QgsProjectPropertiesBase", "PNG", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("QgsProjectPropertiesBase", "Published", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("QgsProjectPropertiesBase", "Layer", nullptr));
        label_32->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Grids", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = twWmtsGrids->headerItem();
        ___qtreewidgetitem1->setText(6, QCoreApplication::translate("QgsProjectPropertiesBase", "Max. scale", nullptr));
        ___qtreewidgetitem1->setText(5, QCoreApplication::translate("QgsProjectPropertiesBase", "Last level", nullptr));
        ___qtreewidgetitem1->setText(4, QCoreApplication::translate("QgsProjectPropertiesBase", "Min. scale", nullptr));
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("QgsProjectPropertiesBase", "Left", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("QgsProjectPropertiesBase", "Top", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("QgsProjectPropertiesBase", "Published", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("QgsProjectPropertiesBase", "CRS", nullptr));
        grpWFSCapabilities->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "WFS capabilities (also influences DXF export)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = twWFSLayers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Layer", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = twWFSLayers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Published", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = twWFSLayers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Geometry precision (decimal places)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = twWFSLayers->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Update", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = twWFSLayers->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Insert", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = twWFSLayers->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Delete", nullptr));
        pbnWFSLayersDeselectAll->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Deselect All", nullptr));
        pbnWFSLayersSelectAll->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Select All", nullptr));
        mWFSUrlLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Advertised URL", nullptr));
        grpWCSCapabilities->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "WCS capabilities", nullptr));
        pbnWCSLayersDeselectAll->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Deselect All", nullptr));
        mWCSUrlLabel->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Advertised URL", nullptr));
        pbnWCSLayersSelectAll->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Select All", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = twWCSLayers->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Layer", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = twWCSLayers->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Published", nullptr));
        mOWSCheckerGroupBox->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Test Configuration", nullptr));
        pbnLaunchOWSChecker->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Launch", nullptr));
        mTemporalOptionsGroup->setTitle(QCoreApplication::translate("QgsProjectPropertiesBase", "Temporal Options", nullptr));
        mStartDateTimeEdit->setDisplayFormat(QCoreApplication::translate("QgsProjectPropertiesBase", "M/d/yyyy h:mm AP", nullptr));
        label_35->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Start date", nullptr));
        mCalculateFromLayerButton->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "Calculate from Layers", nullptr));
        label_36->setText(QCoreApplication::translate("QgsProjectPropertiesBase", "End date", nullptr));
        mEndDateTimeEdit->setDisplayFormat(QCoreApplication::translate("QgsProjectPropertiesBase", "M/d/yyyy h:mm AP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsProjectPropertiesBase: public Ui_QgsProjectPropertiesBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSPROJECTPROPERTIESBASE_H
