/********************************************************************************
** Form generated from reading UI file 'qgsgpsinformationwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSGPSINFORMATIONWIDGETBASE_H
#define UI_QGSGPSINFORMATIONWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qgscollapsiblegroupbox.h>
#include "qgscollapsiblegroupbox.h"
#include "qgscolorbutton.h"
#include "qgsfieldcombobox.h"
#include "qgspanelwidget.h"
#include "qgsscrollarea.h"
#include "qgsspinbox.h"
#include "qgssymbolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsGpsInformationWidgetBase
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_15;
    QLabel *mLblStatusIndicator;
    QPushButton *mBtnCloseFeature;
    QPushButton *mBtnAddVertex;
    QToolButton *mBtnResetFeature;
    QStackedWidget *mStackedWidget;
    QWidget *stackedWidgetPage1;
    QGridLayout *gridLayout_11;
    QgsScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_10;
    QLineEdit *mTxtLatitude;
    QLabel *mLblHdop;
    QLineEdit *mTxtPdop;
    QLineEdit *mTxtAltitude;
    QSpacerItem *verticalSpacer_3;
    QLabel *mLblFixMode;
    QLineEdit *mTxtHacc;
    QSpacerItem *verticalSpacer_5;
    QLabel *mLblSpeed;
    QLabel *mLblAltitude;
    QLabel *mLblLongitude;
    QLineEdit *mTxtFixMode;
    QLabel *mLblLatitude;
    QLabel *mLblUtcTime;
    QLabel *mLblVacc;
    QSpacerItem *verticalSpacer_2;
    QLabel *mLblFixType;
    QLineEdit *mTxtSpeed;
    QLabel *mLblVdop;
    QLabel *mLbl3Dacc;
    QLineEdit *mTxtFixType;
    QLineEdit *mTxtQuality;
    QLabel *mLblStatus;
    QLineEdit *mTxtDateTime;
    QLineEdit *mTxt3Dacc;
    QLineEdit *mTxtVacc;
    QLineEdit *mTxtSatellitesUsed;
    QLabel *mLblQuality;
    QLineEdit *mTxtStatus;
    QLineEdit *mTxtDirection;
    QLabel *mLblDirection;
    QSpacerItem *verticalSpacer_4;
    QLabel *mLblSatellitesUsed;
    QLineEdit *mTxtVdop;
    QLabel *mLblPdop;
    QLineEdit *mTxtLongitude;
    QLineEdit *mTxtHdop;
    QLabel *mLblHacc;
    QLabel *label_13;
    QLineEdit *mTxtAltitudeDiff;
    QWidget *stackedWidgetPage2;
    QWidget *stackedWidgetPage3;
    QWidget *stackedWidgetPage4;
    QGridLayout *gridLayout_5;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_7;
    QgsCollapsibleGroupBox *mLogFileGroupBox;
    QGridLayout *gridLayout_13;
    QLineEdit *mTxtLogFile;
    QPushButton *mBtnLogFile;
    QgsCollapsibleGroupBox *groupBox_4;
    QGridLayout *gridLayout_14;
    QComboBox *mCboDistanceThreshold;
    QLabel *label_9;
    QLabel *label_8;
    QComboBox *mCboAcquisitionInterval;
    QgsCollapsibleGroupBox *mDeviceGroupBox;
    QGridLayout *gridLayout;
    QRadioButton *mRadInternal;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *mCboDevices;
    QToolButton *mBtnRefreshDevices;
    QRadioButton *mRadAutodetect;
    QGridLayout *gridLayout_12;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *mGpsdDevice;
    QLineEdit *mGpsdHost;
    QLineEdit *mGpsdPort;
    QRadioButton *mRadGpsd;
    QRadioButton *mRadUserPath;
    QgsCollapsibleGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_16;
    QLabel *label_6;
    QgsSpinBox *mSpinTrackWidth;
    QCheckBox *mCbxAutoAddVertices;
    QLabel *label_7;
    QgsColorButton *mBtnTrackColor;
    QCheckBox *mCbxAutoCommit;
    QGroupBox *mGboxTimestamp;
    QFormLayout *formLayout;
    QLabel *label_10;
    QgsFieldComboBox *mCboTimestampField;
    QLabel *mLblTimestampFormat;
    QComboBox *mCboTimestampFormat;
    QLabel *mLblTimeZone;
    QComboBox *mCboTimeZones;
    QgsSpinBox *mLeapSeconds;
    QCheckBox *mCbxLeapSeconds;
    QCheckBox *mTravelBearingCheckBox;
    QgsCollapsibleGroupBoxBasic *groupBox;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout;
    QgsSpinBox *mSpinMapExtentMultiplier;
    QRadioButton *radRecenterMap;
    QRadioButton *radRecenterWhenNeeded;
    QRadioButton *radNeverRecenter;
    QCheckBox *mRotateMapCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QgsSpinBox *mSpinMapRotateInterval;
    QgsCollapsibleGroupBox *mGroupShowMarker;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSlider *mSliderMarkerSize;
    QLabel *label;
    QgsCollapsibleGroupBox *mShowBearingLineCheck;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QgsSymbolButton *mBearingLineStyleButton;
    QWidget *stackedWidgetPage5;
    QGridLayout *gridLayout_6;
    QPlainTextEdit *mGPSPlainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *mBtnPosition;
    QToolButton *mBtnSignal;
    QToolButton *mBtnSatellites;
    QToolButton *mBtnOptions;
    QToolButton *mBtnDebug;
    QSpacerItem *horizontalSpacer;
    QPushButton *mRecenterButton;
    QPushButton *mConnectButton;

    void setupUi(QgsPanelWidget *QgsGpsInformationWidgetBase)
    {
        if (QgsGpsInformationWidgetBase->objectName().isEmpty())
            QgsGpsInformationWidgetBase->setObjectName(QString::fromUtf8("QgsGpsInformationWidgetBase"));
        QgsGpsInformationWidgetBase->resize(583, 837);
        gridLayout_4 = new QGridLayout(QgsGpsInformationWidgetBase);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(2);
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        mLblStatusIndicator = new QLabel(QgsGpsInformationWidgetBase);
        mLblStatusIndicator->setObjectName(QString::fromUtf8("mLblStatusIndicator"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLblStatusIndicator->sizePolicy().hasHeightForWidth());
        mLblStatusIndicator->setSizePolicy(sizePolicy);
        mLblStatusIndicator->setMinimumSize(QSize(42, 0));
        mLblStatusIndicator->setMaximumSize(QSize(42, 16777215));
        mLblStatusIndicator->setFrameShape(QFrame::Box);
        mLblStatusIndicator->setScaledContents(true);

        gridLayout_15->addWidget(mLblStatusIndicator, 0, 1, 1, 1);

        mBtnCloseFeature = new QPushButton(QgsGpsInformationWidgetBase);
        mBtnCloseFeature->setObjectName(QString::fromUtf8("mBtnCloseFeature"));
        mBtnCloseFeature->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mBtnCloseFeature->sizePolicy().hasHeightForWidth());
        mBtnCloseFeature->setSizePolicy(sizePolicy1);

        gridLayout_15->addWidget(mBtnCloseFeature, 0, 0, 1, 1);

        mBtnAddVertex = new QPushButton(QgsGpsInformationWidgetBase);
        mBtnAddVertex->setObjectName(QString::fromUtf8("mBtnAddVertex"));
        mBtnAddVertex->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mBtnAddVertex->sizePolicy().hasHeightForWidth());
        mBtnAddVertex->setSizePolicy(sizePolicy2);

        gridLayout_15->addWidget(mBtnAddVertex, 1, 0, 1, 1);

        mBtnResetFeature = new QToolButton(QgsGpsInformationWidgetBase);
        mBtnResetFeature->setObjectName(QString::fromUtf8("mBtnResetFeature"));
        sizePolicy1.setHeightForWidth(mBtnResetFeature->sizePolicy().hasHeightForWidth());
        mBtnResetFeature->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionDeleteSelected.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnResetFeature->setIcon(icon);

        gridLayout_15->addWidget(mBtnResetFeature, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_15, 0, 0, 1, 1);

        mStackedWidget = new QStackedWidget(QgsGpsInformationWidgetBase);
        mStackedWidget->setObjectName(QString::fromUtf8("mStackedWidget"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QString::fromUtf8("stackedWidgetPage1"));
        gridLayout_11 = new QGridLayout(stackedWidgetPage1);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QgsScrollArea(stackedWidgetPage1);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 579, 744));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(2);
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(2, 2, 2, 2);
        mTxtLatitude = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtLatitude->setObjectName(QString::fromUtf8("mTxtLatitude"));
        mTxtLatitude->setReadOnly(true);

        gridLayout_10->addWidget(mTxtLatitude, 0, 1, 1, 1);

        mLblHdop = new QLabel(scrollAreaWidgetContents_2);
        mLblHdop->setObjectName(QString::fromUtf8("mLblHdop"));

        gridLayout_10->addWidget(mLblHdop, 10, 0, 1, 1);

        mTxtPdop = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtPdop->setObjectName(QString::fromUtf8("mTxtPdop"));
        mTxtPdop->setReadOnly(true);

        gridLayout_10->addWidget(mTxtPdop, 12, 1, 1, 1);

        mTxtAltitude = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtAltitude->setObjectName(QString::fromUtf8("mTxtAltitude"));
        mTxtAltitude->setReadOnly(true);

        gridLayout_10->addWidget(mTxtAltitude, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_10->addItem(verticalSpacer_3, 16, 1, 1, 1);

        mLblFixMode = new QLabel(scrollAreaWidgetContents_2);
        mLblFixMode->setObjectName(QString::fromUtf8("mLblFixMode"));

        gridLayout_10->addWidget(mLblFixMode, 17, 0, 1, 1);

        mTxtHacc = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtHacc->setObjectName(QString::fromUtf8("mTxtHacc"));

        gridLayout_10->addWidget(mTxtHacc, 13, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_10->addItem(verticalSpacer_5, 6, 1, 1, 1);

        mLblSpeed = new QLabel(scrollAreaWidgetContents_2);
        mLblSpeed->setObjectName(QString::fromUtf8("mLblSpeed"));

        gridLayout_10->addWidget(mLblSpeed, 7, 0, 1, 1);

        mLblAltitude = new QLabel(scrollAreaWidgetContents_2);
        mLblAltitude->setObjectName(QString::fromUtf8("mLblAltitude"));

        gridLayout_10->addWidget(mLblAltitude, 2, 0, 1, 1);

        mLblLongitude = new QLabel(scrollAreaWidgetContents_2);
        mLblLongitude->setObjectName(QString::fromUtf8("mLblLongitude"));

        gridLayout_10->addWidget(mLblLongitude, 1, 0, 1, 1);

        mTxtFixMode = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtFixMode->setObjectName(QString::fromUtf8("mTxtFixMode"));
        mTxtFixMode->setReadOnly(true);

        gridLayout_10->addWidget(mTxtFixMode, 17, 1, 1, 1);

        mLblLatitude = new QLabel(scrollAreaWidgetContents_2);
        mLblLatitude->setObjectName(QString::fromUtf8("mLblLatitude"));

        gridLayout_10->addWidget(mLblLatitude, 0, 0, 1, 1);

        mLblUtcTime = new QLabel(scrollAreaWidgetContents_2);
        mLblUtcTime->setObjectName(QString::fromUtf8("mLblUtcTime"));

        gridLayout_10->addWidget(mLblUtcTime, 5, 0, 1, 1);

        mLblVacc = new QLabel(scrollAreaWidgetContents_2);
        mLblVacc->setObjectName(QString::fromUtf8("mLblVacc"));

        gridLayout_10->addWidget(mLblVacc, 14, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_10->addItem(verticalSpacer_2, 4, 1, 1, 1);

        mLblFixType = new QLabel(scrollAreaWidgetContents_2);
        mLblFixType->setObjectName(QString::fromUtf8("mLblFixType"));

        gridLayout_10->addWidget(mLblFixType, 18, 0, 1, 1);

        mTxtSpeed = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtSpeed->setObjectName(QString::fromUtf8("mTxtSpeed"));
        mTxtSpeed->setReadOnly(true);

        gridLayout_10->addWidget(mTxtSpeed, 7, 1, 1, 1);

        mLblVdop = new QLabel(scrollAreaWidgetContents_2);
        mLblVdop->setObjectName(QString::fromUtf8("mLblVdop"));

        gridLayout_10->addWidget(mLblVdop, 11, 0, 1, 1);

        mLbl3Dacc = new QLabel(scrollAreaWidgetContents_2);
        mLbl3Dacc->setObjectName(QString::fromUtf8("mLbl3Dacc"));

        gridLayout_10->addWidget(mLbl3Dacc, 15, 0, 1, 1);

        mTxtFixType = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtFixType->setObjectName(QString::fromUtf8("mTxtFixType"));
        mTxtFixType->setReadOnly(true);

        gridLayout_10->addWidget(mTxtFixType, 18, 1, 1, 1);

        mTxtQuality = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtQuality->setObjectName(QString::fromUtf8("mTxtQuality"));
        mTxtQuality->setReadOnly(true);

        gridLayout_10->addWidget(mTxtQuality, 19, 1, 1, 1);

        mLblStatus = new QLabel(scrollAreaWidgetContents_2);
        mLblStatus->setObjectName(QString::fromUtf8("mLblStatus"));

        gridLayout_10->addWidget(mLblStatus, 20, 0, 1, 1);

        mTxtDateTime = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtDateTime->setObjectName(QString::fromUtf8("mTxtDateTime"));
        mTxtDateTime->setReadOnly(true);

        gridLayout_10->addWidget(mTxtDateTime, 5, 1, 1, 1);

        mTxt3Dacc = new QLineEdit(scrollAreaWidgetContents_2);
        mTxt3Dacc->setObjectName(QString::fromUtf8("mTxt3Dacc"));

        gridLayout_10->addWidget(mTxt3Dacc, 15, 1, 1, 1);

        mTxtVacc = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtVacc->setObjectName(QString::fromUtf8("mTxtVacc"));

        gridLayout_10->addWidget(mTxtVacc, 14, 1, 1, 1);

        mTxtSatellitesUsed = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtSatellitesUsed->setObjectName(QString::fromUtf8("mTxtSatellitesUsed"));
        mTxtSatellitesUsed->setReadOnly(true);

        gridLayout_10->addWidget(mTxtSatellitesUsed, 21, 1, 1, 1);

        mLblQuality = new QLabel(scrollAreaWidgetContents_2);
        mLblQuality->setObjectName(QString::fromUtf8("mLblQuality"));

        gridLayout_10->addWidget(mLblQuality, 19, 0, 1, 1);

        mTxtStatus = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtStatus->setObjectName(QString::fromUtf8("mTxtStatus"));
        mTxtStatus->setReadOnly(true);

        gridLayout_10->addWidget(mTxtStatus, 20, 1, 1, 1);

        mTxtDirection = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtDirection->setObjectName(QString::fromUtf8("mTxtDirection"));
        mTxtDirection->setReadOnly(true);

        gridLayout_10->addWidget(mTxtDirection, 8, 1, 1, 1);

        mLblDirection = new QLabel(scrollAreaWidgetContents_2);
        mLblDirection->setObjectName(QString::fromUtf8("mLblDirection"));

        gridLayout_10->addWidget(mLblDirection, 8, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_10->addItem(verticalSpacer_4, 9, 1, 1, 1);

        mLblSatellitesUsed = new QLabel(scrollAreaWidgetContents_2);
        mLblSatellitesUsed->setObjectName(QString::fromUtf8("mLblSatellitesUsed"));

        gridLayout_10->addWidget(mLblSatellitesUsed, 21, 0, 1, 1);

        mTxtVdop = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtVdop->setObjectName(QString::fromUtf8("mTxtVdop"));
        mTxtVdop->setReadOnly(true);

        gridLayout_10->addWidget(mTxtVdop, 11, 1, 1, 1);

        mLblPdop = new QLabel(scrollAreaWidgetContents_2);
        mLblPdop->setObjectName(QString::fromUtf8("mLblPdop"));

        gridLayout_10->addWidget(mLblPdop, 12, 0, 1, 1);

        mTxtLongitude = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtLongitude->setObjectName(QString::fromUtf8("mTxtLongitude"));
        mTxtLongitude->setReadOnly(true);

        gridLayout_10->addWidget(mTxtLongitude, 1, 1, 1, 1);

        mTxtHdop = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtHdop->setObjectName(QString::fromUtf8("mTxtHdop"));
        mTxtHdop->setReadOnly(true);

        gridLayout_10->addWidget(mTxtHdop, 10, 1, 1, 1);

        mLblHacc = new QLabel(scrollAreaWidgetContents_2);
        mLblHacc->setObjectName(QString::fromUtf8("mLblHacc"));

        gridLayout_10->addWidget(mLblHacc, 13, 0, 1, 1);

        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_10->addWidget(label_13, 3, 0, 1, 1);

        mTxtAltitudeDiff = new QLineEdit(scrollAreaWidgetContents_2);
        mTxtAltitudeDiff->setObjectName(QString::fromUtf8("mTxtAltitudeDiff"));

        gridLayout_10->addWidget(mTxtAltitudeDiff, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_10, 2, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_11->addWidget(scrollArea_2, 0, 0, 1, 1);

        mStackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QString::fromUtf8("stackedWidgetPage2"));
        mStackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QString::fromUtf8("stackedWidgetPage3"));
        mStackedWidget->addWidget(stackedWidgetPage3);
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName(QString::fromUtf8("stackedWidgetPage4"));
        gridLayout_5 = new QGridLayout(stackedWidgetPage4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(6);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QgsScrollArea(stackedWidgetPage4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 565, 1126));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(4);
        gridLayout_7->setContentsMargins(2, 2, 2, 2);
        mLogFileGroupBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        mLogFileGroupBox->setObjectName(QString::fromUtf8("mLogFileGroupBox"));
        mLogFileGroupBox->setEnabled(true);
        mLogFileGroupBox->setMinimumSize(QSize(0, 0));
        mLogFileGroupBox->setCheckable(true);
        mLogFileGroupBox->setChecked(false);
        gridLayout_13 = new QGridLayout(mLogFileGroupBox);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(-1, 2, -1, 4);
        mTxtLogFile = new QLineEdit(mLogFileGroupBox);
        mTxtLogFile->setObjectName(QString::fromUtf8("mTxtLogFile"));
        mTxtLogFile->setEnabled(false);
        sizePolicy1.setHeightForWidth(mTxtLogFile->sizePolicy().hasHeightForWidth());
        mTxtLogFile->setSizePolicy(sizePolicy1);
        mTxtLogFile->setAcceptDrops(false);
        mTxtLogFile->setReadOnly(true);

        gridLayout_13->addWidget(mTxtLogFile, 0, 0, 1, 1);

        mBtnLogFile = new QPushButton(mLogFileGroupBox);
        mBtnLogFile->setObjectName(QString::fromUtf8("mBtnLogFile"));
        mBtnLogFile->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(23);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mBtnLogFile->sizePolicy().hasHeightForWidth());
        mBtnLogFile->setSizePolicy(sizePolicy3);
        mBtnLogFile->setMinimumSize(QSize(23, 0));

        gridLayout_13->addWidget(mBtnLogFile, 0, 1, 1, 1);

        gridLayout_13->setColumnStretch(0, 100);

        gridLayout_7->addWidget(mLogFileGroupBox, 7, 0, 1, 1);

        groupBox_4 = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_14 = new QGridLayout(groupBox_4);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        mCboDistanceThreshold = new QComboBox(groupBox_4);
        mCboDistanceThreshold->setObjectName(QString::fromUtf8("mCboDistanceThreshold"));
        mCboDistanceThreshold->setEditable(true);

        gridLayout_14->addWidget(mCboDistanceThreshold, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_14->addWidget(label_9, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_14->addWidget(label_8, 0, 0, 1, 1);

        mCboAcquisitionInterval = new QComboBox(groupBox_4);
        mCboAcquisitionInterval->setObjectName(QString::fromUtf8("mCboAcquisitionInterval"));
        mCboAcquisitionInterval->setEditable(true);

        gridLayout_14->addWidget(mCboAcquisitionInterval, 0, 1, 1, 1);

        gridLayout_14->setColumnStretch(1, 1);

        gridLayout_7->addWidget(groupBox_4, 4, 0, 1, 1);

        mDeviceGroupBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        mDeviceGroupBox->setObjectName(QString::fromUtf8("mDeviceGroupBox"));
        gridLayout = new QGridLayout(mDeviceGroupBox);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 2, -1, 4);
        mRadInternal = new QRadioButton(mDeviceGroupBox);
        mRadInternal->setObjectName(QString::fromUtf8("mRadInternal"));

        gridLayout->addWidget(mRadInternal, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, -1, -1, -1);
        mCboDevices = new QComboBox(mDeviceGroupBox);
        mCboDevices->setObjectName(QString::fromUtf8("mCboDevices"));
        mCboDevices->setEnabled(false);

        horizontalLayout_3->addWidget(mCboDevices);

        mBtnRefreshDevices = new QToolButton(mDeviceGroupBox);
        mBtnRefreshDevices->setObjectName(QString::fromUtf8("mBtnRefreshDevices"));
        mBtnRefreshDevices->setEnabled(false);
        sizePolicy.setHeightForWidth(mBtnRefreshDevices->sizePolicy().hasHeightForWidth());
        mBtnRefreshDevices->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnRefreshDevices->setIcon(icon1);

        horizontalLayout_3->addWidget(mBtnRefreshDevices);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        mRadAutodetect = new QRadioButton(mDeviceGroupBox);
        mRadAutodetect->setObjectName(QString::fromUtf8("mRadAutodetect"));
        mRadAutodetect->setChecked(true);

        gridLayout->addWidget(mRadAutodetect, 0, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setVerticalSpacing(2);
        gridLayout_12->setContentsMargins(20, -1, -1, -1);
        label_4 = new QLabel(mDeviceGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_12->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(mDeviceGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_12->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(mDeviceGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_12->addWidget(label_5, 2, 0, 1, 1);

        mGpsdDevice = new QLineEdit(mDeviceGroupBox);
        mGpsdDevice->setObjectName(QString::fromUtf8("mGpsdDevice"));
        mGpsdDevice->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mGpsdDevice->sizePolicy().hasHeightForWidth());
        mGpsdDevice->setSizePolicy(sizePolicy4);

        gridLayout_12->addWidget(mGpsdDevice, 2, 1, 1, 1);

        mGpsdHost = new QLineEdit(mDeviceGroupBox);
        mGpsdHost->setObjectName(QString::fromUtf8("mGpsdHost"));
        mGpsdHost->setEnabled(false);
        sizePolicy4.setHeightForWidth(mGpsdHost->sizePolicy().hasHeightForWidth());
        mGpsdHost->setSizePolicy(sizePolicy4);

        gridLayout_12->addWidget(mGpsdHost, 0, 1, 1, 1);

        mGpsdPort = new QLineEdit(mDeviceGroupBox);
        mGpsdPort->setObjectName(QString::fromUtf8("mGpsdPort"));
        mGpsdPort->setEnabled(false);
        sizePolicy4.setHeightForWidth(mGpsdPort->sizePolicy().hasHeightForWidth());
        mGpsdPort->setSizePolicy(sizePolicy4);
        mGpsdPort->setMaxLength(5);

        gridLayout_12->addWidget(mGpsdPort, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_12, 5, 0, 1, 1);

        mRadGpsd = new QRadioButton(mDeviceGroupBox);
        mRadGpsd->setObjectName(QString::fromUtf8("mRadGpsd"));

        gridLayout->addWidget(mRadGpsd, 4, 0, 1, 1);

        mRadUserPath = new QRadioButton(mDeviceGroupBox);
        mRadUserPath->setObjectName(QString::fromUtf8("mRadUserPath"));

        gridLayout->addWidget(mRadUserPath, 2, 0, 1, 1);


        gridLayout_7->addWidget(mDeviceGroupBox, 0, 0, 1, 1);

        groupBox_2 = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(2);
        gridLayout_9->setContentsMargins(-1, 2, -1, 4);
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_16 = new QGridLayout(groupBox_3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(-1, 2, -1, 4);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_16->addWidget(label_6, 1, 0, 1, 1);

        mSpinTrackWidth = new QgsSpinBox(groupBox_3);
        mSpinTrackWidth->setObjectName(QString::fromUtf8("mSpinTrackWidth"));

        gridLayout_16->addWidget(mSpinTrackWidth, 1, 1, 1, 1);

        mCbxAutoAddVertices = new QCheckBox(groupBox_3);
        mCbxAutoAddVertices->setObjectName(QString::fromUtf8("mCbxAutoAddVertices"));

        gridLayout_16->addWidget(mCbxAutoAddVertices, 0, 0, 1, 2);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_16->addWidget(label_7, 2, 0, 1, 1);

        mBtnTrackColor = new QgsColorButton(groupBox_3);
        mBtnTrackColor->setObjectName(QString::fromUtf8("mBtnTrackColor"));
        sizePolicy1.setHeightForWidth(mBtnTrackColor->sizePolicy().hasHeightForWidth());
        mBtnTrackColor->setSizePolicy(sizePolicy1);

        gridLayout_16->addWidget(mBtnTrackColor, 2, 1, 1, 1);

        gridLayout_16->setColumnStretch(1, 1);

        gridLayout_9->addWidget(groupBox_3, 2, 0, 1, 1);

        mCbxAutoCommit = new QCheckBox(groupBox_2);
        mCbxAutoCommit->setObjectName(QString::fromUtf8("mCbxAutoCommit"));

        gridLayout_9->addWidget(mCbxAutoCommit, 0, 0, 1, 1);

        mGboxTimestamp = new QGroupBox(groupBox_2);
        mGboxTimestamp->setObjectName(QString::fromUtf8("mGboxTimestamp"));
        formLayout = new QFormLayout(mGboxTimestamp);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_10 = new QLabel(mGboxTimestamp);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        mCboTimestampField = new QgsFieldComboBox(mGboxTimestamp);
        mCboTimestampField->setObjectName(QString::fromUtf8("mCboTimestampField"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mCboTimestampField);

        mLblTimestampFormat = new QLabel(mGboxTimestamp);
        mLblTimestampFormat->setObjectName(QString::fromUtf8("mLblTimestampFormat"));

        formLayout->setWidget(2, QFormLayout::LabelRole, mLblTimestampFormat);

        mCboTimestampFormat = new QComboBox(mGboxTimestamp);
        mCboTimestampFormat->setObjectName(QString::fromUtf8("mCboTimestampFormat"));

        formLayout->setWidget(2, QFormLayout::FieldRole, mCboTimestampFormat);

        mLblTimeZone = new QLabel(mGboxTimestamp);
        mLblTimeZone->setObjectName(QString::fromUtf8("mLblTimeZone"));

        formLayout->setWidget(3, QFormLayout::LabelRole, mLblTimeZone);

        mCboTimeZones = new QComboBox(mGboxTimestamp);
        mCboTimeZones->setObjectName(QString::fromUtf8("mCboTimeZones"));

        formLayout->setWidget(3, QFormLayout::FieldRole, mCboTimeZones);

        mLeapSeconds = new QgsSpinBox(mGboxTimestamp);
        mLeapSeconds->setObjectName(QString::fromUtf8("mLeapSeconds"));

        formLayout->setWidget(4, QFormLayout::FieldRole, mLeapSeconds);

        mCbxLeapSeconds = new QCheckBox(mGboxTimestamp);
        mCbxLeapSeconds->setObjectName(QString::fromUtf8("mCbxLeapSeconds"));

        formLayout->setWidget(4, QFormLayout::LabelRole, mCbxLeapSeconds);


        gridLayout_9->addWidget(mGboxTimestamp, 1, 0, 1, 1);

        mTravelBearingCheckBox = new QCheckBox(groupBox_2);
        mTravelBearingCheckBox->setObjectName(QString::fromUtf8("mTravelBearingCheckBox"));

        gridLayout_9->addWidget(mTravelBearingCheckBox, 3, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setVerticalSpacing(2);
        gridLayout_8->setContentsMargins(-1, 2, -1, 4);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, -1, -1);
        mSpinMapExtentMultiplier = new QgsSpinBox(groupBox);
        mSpinMapExtentMultiplier->setObjectName(QString::fromUtf8("mSpinMapExtentMultiplier"));
        mSpinMapExtentMultiplier->setEnabled(false);
        sizePolicy1.setHeightForWidth(mSpinMapExtentMultiplier->sizePolicy().hasHeightForWidth());
        mSpinMapExtentMultiplier->setSizePolicy(sizePolicy1);
        mSpinMapExtentMultiplier->setMinimum(5);
        mSpinMapExtentMultiplier->setMaximum(100);
        mSpinMapExtentMultiplier->setSingleStep(1);
        mSpinMapExtentMultiplier->setValue(50);

        horizontalLayout->addWidget(mSpinMapExtentMultiplier);


        gridLayout_8->addLayout(horizontalLayout, 2, 0, 1, 1);

        radRecenterMap = new QRadioButton(groupBox);
        radRecenterMap->setObjectName(QString::fromUtf8("radRecenterMap"));
        radRecenterMap->setChecked(true);

        gridLayout_8->addWidget(radRecenterMap, 0, 0, 1, 1);

        radRecenterWhenNeeded = new QRadioButton(groupBox);
        radRecenterWhenNeeded->setObjectName(QString::fromUtf8("radRecenterWhenNeeded"));

        gridLayout_8->addWidget(radRecenterWhenNeeded, 1, 0, 1, 1);

        radNeverRecenter = new QRadioButton(groupBox);
        radNeverRecenter->setObjectName(QString::fromUtf8("radNeverRecenter"));

        gridLayout_8->addWidget(radNeverRecenter, 3, 0, 1, 1);

        mRotateMapCheckBox = new QCheckBox(groupBox);
        mRotateMapCheckBox->setObjectName(QString::fromUtf8("mRotateMapCheckBox"));

        gridLayout_8->addWidget(mRotateMapCheckBox, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(20, -1, -1, -1);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        mSpinMapRotateInterval = new QgsSpinBox(groupBox);
        mSpinMapRotateInterval->setObjectName(QString::fromUtf8("mSpinMapRotateInterval"));
        mSpinMapRotateInterval->setEnabled(false);
        sizePolicy1.setHeightForWidth(mSpinMapRotateInterval->sizePolicy().hasHeightForWidth());
        mSpinMapRotateInterval->setSizePolicy(sizePolicy1);
        mSpinMapRotateInterval->setMinimum(0);
        mSpinMapRotateInterval->setMaximum(1000);
        mSpinMapRotateInterval->setSingleStep(1);
        mSpinMapRotateInterval->setValue(0);

        horizontalLayout_5->addWidget(mSpinMapRotateInterval);

        horizontalLayout_5->setStretch(1, 1);

        gridLayout_8->addLayout(horizontalLayout_5, 5, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 5, 0, 1, 1);

        mGroupShowMarker = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        mGroupShowMarker->setObjectName(QString::fromUtf8("mGroupShowMarker"));
        mGroupShowMarker->setCheckable(true);
        gridLayout_3 = new QGridLayout(mGroupShowMarker);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(2);
        gridLayout_3->setContentsMargins(-1, 4, -1, 4);
        label_2 = new QLabel(mGroupShowMarker);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_2, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        mSliderMarkerSize = new QSlider(mGroupShowMarker);
        mSliderMarkerSize->setObjectName(QString::fromUtf8("mSliderMarkerSize"));
        sizePolicy1.setHeightForWidth(mSliderMarkerSize->sizePolicy().hasHeightForWidth());
        mSliderMarkerSize->setSizePolicy(sizePolicy1);
        mSliderMarkerSize->setMinimum(8);
        mSliderMarkerSize->setMaximum(128);
        mSliderMarkerSize->setSingleStep(4);
        mSliderMarkerSize->setPageStep(8);
        mSliderMarkerSize->setSliderPosition(10);
        mSliderMarkerSize->setOrientation(Qt::Horizontal);
        mSliderMarkerSize->setTickPosition(QSlider::TicksBelow);

        gridLayout_3->addWidget(mSliderMarkerSize, 0, 0, 1, 3);

        label = new QLabel(mGroupShowMarker);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label, 1, 0, 1, 1);


        gridLayout_7->addWidget(mGroupShowMarker, 3, 0, 1, 1);

        mShowBearingLineCheck = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        mShowBearingLineCheck->setObjectName(QString::fromUtf8("mShowBearingLineCheck"));
        mShowBearingLineCheck->setCheckable(true);
        horizontalLayout_4 = new QHBoxLayout(mShowBearingLineCheck);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_11 = new QLabel(mShowBearingLineCheck);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_4->addWidget(label_11);

        mBearingLineStyleButton = new QgsSymbolButton(mShowBearingLineCheck);
        mBearingLineStyleButton->setObjectName(QString::fromUtf8("mBearingLineStyleButton"));
        sizePolicy1.setHeightForWidth(mBearingLineStyleButton->sizePolicy().hasHeightForWidth());
        mBearingLineStyleButton->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(mBearingLineStyleButton);

        horizontalLayout_4->setStretch(1, 1);

        gridLayout_7->addWidget(mShowBearingLineCheck, 6, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 0, 0, 1, 1);

        mStackedWidget->addWidget(stackedWidgetPage4);
        stackedWidgetPage5 = new QWidget();
        stackedWidgetPage5->setObjectName(QString::fromUtf8("stackedWidgetPage5"));
        gridLayout_6 = new QGridLayout(stackedWidgetPage5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        mGPSPlainTextEdit = new QPlainTextEdit(stackedWidgetPage5);
        mGPSPlainTextEdit->setObjectName(QString::fromUtf8("mGPSPlainTextEdit"));
        mGPSPlainTextEdit->setAcceptDrops(false);
        mGPSPlainTextEdit->setUndoRedoEnabled(false);

        gridLayout_6->addWidget(mGPSPlainTextEdit, 0, 0, 1, 1);

        mStackedWidget->addWidget(stackedWidgetPage5);

        gridLayout_4->addWidget(mStackedWidget, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mBtnPosition = new QToolButton(QgsGpsInformationWidgetBase);
        mBtnPosition->setObjectName(QString::fromUtf8("mBtnPosition"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionPropertiesWidget.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnPosition->setIcon(icon2);
        mBtnPosition->setAutoRaise(true);

        horizontalLayout_2->addWidget(mBtnPosition);

        mBtnSignal = new QToolButton(QgsGpsInformationWidgetBase);
        mBtnSignal->setObjectName(QString::fromUtf8("mBtnSignal"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/gpsicons/barchart.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnSignal->setIcon(icon3);
        mBtnSignal->setAutoRaise(true);

        horizontalLayout_2->addWidget(mBtnSignal);

        mBtnSatellites = new QToolButton(QgsGpsInformationWidgetBase);
        mBtnSatellites->setObjectName(QString::fromUtf8("mBtnSatellites"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/gpsicons/polarchart.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnSatellites->setIcon(icon4);
        mBtnSatellites->setAutoRaise(true);

        horizontalLayout_2->addWidget(mBtnSatellites);

        mBtnOptions = new QToolButton(QgsGpsInformationWidgetBase);
        mBtnOptions->setObjectName(QString::fromUtf8("mBtnOptions"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionOptions.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnOptions->setIcon(icon5);
        mBtnOptions->setAutoRaise(true);

        horizontalLayout_2->addWidget(mBtnOptions);

        mBtnDebug = new QToolButton(QgsGpsInformationWidgetBase);
        mBtnDebug->setObjectName(QString::fromUtf8("mBtnDebug"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCopy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnDebug->setIcon(icon6);
        mBtnDebug->setAutoRaise(true);

        horizontalLayout_2->addWidget(mBtnDebug);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        mRecenterButton = new QPushButton(QgsGpsInformationWidgetBase);
        mRecenterButton->setObjectName(QString::fromUtf8("mRecenterButton"));
        sizePolicy2.setHeightForWidth(mRecenterButton->sizePolicy().hasHeightForWidth());
        mRecenterButton->setSizePolicy(sizePolicy2);
        mRecenterButton->setCheckable(false);

        horizontalLayout_2->addWidget(mRecenterButton);

        mConnectButton = new QPushButton(QgsGpsInformationWidgetBase);
        mConnectButton->setObjectName(QString::fromUtf8("mConnectButton"));
        sizePolicy2.setHeightForWidth(mConnectButton->sizePolicy().hasHeightForWidth());
        mConnectButton->setSizePolicy(sizePolicy2);
        mConnectButton->setCheckable(true);

        horizontalLayout_2->addWidget(mConnectButton);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_4->setBuddy(mGpsdPort);
        label_3->setBuddy(mGpsdHost);
        label_5->setBuddy(mGpsdDevice);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(mBtnAddVertex, mBtnResetFeature);
        QWidget::setTabOrder(mBtnResetFeature, mBtnPosition);
        QWidget::setTabOrder(mBtnPosition, mBtnSignal);
        QWidget::setTabOrder(mBtnSignal, mBtnSatellites);
        QWidget::setTabOrder(mBtnSatellites, mBtnOptions);
        QWidget::setTabOrder(mBtnOptions, mBtnDebug);
        QWidget::setTabOrder(mBtnDebug, mRecenterButton);
        QWidget::setTabOrder(mRecenterButton, mConnectButton);
        QWidget::setTabOrder(mConnectButton, scrollArea);
        QWidget::setTabOrder(scrollArea, mRadAutodetect);
        QWidget::setTabOrder(mRadAutodetect, mRadInternal);
        QWidget::setTabOrder(mRadInternal, mRadUserPath);
        QWidget::setTabOrder(mRadUserPath, mCboDevices);
        QWidget::setTabOrder(mCboDevices, mBtnRefreshDevices);
        QWidget::setTabOrder(mBtnRefreshDevices, mRadGpsd);
        QWidget::setTabOrder(mRadGpsd, mGpsdHost);
        QWidget::setTabOrder(mGpsdHost, mGpsdPort);
        QWidget::setTabOrder(mGpsdPort, mGpsdDevice);
        QWidget::setTabOrder(mGpsdDevice, mCbxAutoCommit);
        QWidget::setTabOrder(mCbxAutoCommit, mCboTimestampField);
        QWidget::setTabOrder(mCboTimestampField, mCboTimestampFormat);
        QWidget::setTabOrder(mCboTimestampFormat, mCboTimeZones);
        QWidget::setTabOrder(mCboTimeZones, mCbxLeapSeconds);
        QWidget::setTabOrder(mCbxLeapSeconds, mLeapSeconds);
        QWidget::setTabOrder(mLeapSeconds, mCbxAutoAddVertices);
        QWidget::setTabOrder(mCbxAutoAddVertices, mSpinTrackWidth);
        QWidget::setTabOrder(mSpinTrackWidth, mBtnTrackColor);
        QWidget::setTabOrder(mBtnTrackColor, mTravelBearingCheckBox);
        QWidget::setTabOrder(mTravelBearingCheckBox, mGroupShowMarker);
        QWidget::setTabOrder(mGroupShowMarker, mSliderMarkerSize);
        QWidget::setTabOrder(mSliderMarkerSize, mCboAcquisitionInterval);
        QWidget::setTabOrder(mCboAcquisitionInterval, mCboDistanceThreshold);
        QWidget::setTabOrder(mCboDistanceThreshold, radRecenterMap);
        QWidget::setTabOrder(radRecenterMap, radRecenterWhenNeeded);
        QWidget::setTabOrder(radRecenterWhenNeeded, mSpinMapExtentMultiplier);
        QWidget::setTabOrder(mSpinMapExtentMultiplier, radNeverRecenter);
        QWidget::setTabOrder(radNeverRecenter, mRotateMapCheckBox);
        QWidget::setTabOrder(mRotateMapCheckBox, mSpinMapRotateInterval);
        QWidget::setTabOrder(mSpinMapRotateInterval, mShowBearingLineCheck);
        QWidget::setTabOrder(mShowBearingLineCheck, mBearingLineStyleButton);
        QWidget::setTabOrder(mBearingLineStyleButton, mLogFileGroupBox);
        QWidget::setTabOrder(mLogFileGroupBox, mTxtLogFile);
        QWidget::setTabOrder(mTxtLogFile, mBtnLogFile);
        QWidget::setTabOrder(mBtnLogFile, mGPSPlainTextEdit);
        QWidget::setTabOrder(mGPSPlainTextEdit, scrollArea_2);
        QWidget::setTabOrder(scrollArea_2, mTxtLatitude);
        QWidget::setTabOrder(mTxtLatitude, mTxtLongitude);
        QWidget::setTabOrder(mTxtLongitude, mTxtAltitude);
        QWidget::setTabOrder(mTxtAltitude, mTxtAltitudeDiff);
        QWidget::setTabOrder(mTxtAltitudeDiff, mTxtDateTime);
        QWidget::setTabOrder(mTxtDateTime, mTxtSpeed);
        QWidget::setTabOrder(mTxtSpeed, mTxtDirection);
        QWidget::setTabOrder(mTxtDirection, mTxtHdop);
        QWidget::setTabOrder(mTxtHdop, mTxtVdop);
        QWidget::setTabOrder(mTxtVdop, mTxtPdop);
        QWidget::setTabOrder(mTxtPdop, mTxtHacc);
        QWidget::setTabOrder(mTxtHacc, mTxtVacc);
        QWidget::setTabOrder(mTxtVacc, mTxt3Dacc);
        QWidget::setTabOrder(mTxt3Dacc, mTxtFixMode);
        QWidget::setTabOrder(mTxtFixMode, mTxtFixType);
        QWidget::setTabOrder(mTxtFixType, mTxtQuality);
        QWidget::setTabOrder(mTxtQuality, mTxtStatus);
        QWidget::setTabOrder(mTxtStatus, mTxtSatellitesUsed);
        QWidget::setTabOrder(mTxtSatellitesUsed, mBtnCloseFeature);

        retranslateUi(QgsGpsInformationWidgetBase);
        QObject::connect(mRadAutodetect, SIGNAL(toggled(bool)), mCboDevices, SLOT(setDisabled(bool)));
        QObject::connect(mRadUserPath, SIGNAL(toggled(bool)), mCboDevices, SLOT(setEnabled(bool)));
        QObject::connect(mRadAutodetect, SIGNAL(toggled(bool)), mGpsdHost, SLOT(setDisabled(bool)));
        QObject::connect(mRadAutodetect, SIGNAL(toggled(bool)), mGpsdPort, SLOT(setDisabled(bool)));
        QObject::connect(mRadAutodetect, SIGNAL(toggled(bool)), mGpsdDevice, SLOT(setDisabled(bool)));
        QObject::connect(mRadUserPath, SIGNAL(toggled(bool)), mGpsdHost, SLOT(setDisabled(bool)));
        QObject::connect(mRadUserPath, SIGNAL(toggled(bool)), mGpsdPort, SLOT(setDisabled(bool)));
        QObject::connect(mRadUserPath, SIGNAL(toggled(bool)), mGpsdDevice, SLOT(setDisabled(bool)));
        QObject::connect(mRadUserPath, SIGNAL(toggled(bool)), mCboDevices, SLOT(setEnabled(bool)));
        QObject::connect(mRadUserPath, SIGNAL(toggled(bool)), mBtnRefreshDevices, SLOT(setEnabled(bool)));
        QObject::connect(mRadAutodetect, SIGNAL(toggled(bool)), mBtnRefreshDevices, SLOT(setDisabled(bool)));
        QObject::connect(mRadGpsd, SIGNAL(toggled(bool)), mGpsdHost, SLOT(setEnabled(bool)));
        QObject::connect(mRadGpsd, SIGNAL(toggled(bool)), mGpsdPort, SLOT(setEnabled(bool)));
        QObject::connect(mRadGpsd, SIGNAL(toggled(bool)), mGpsdDevice, SLOT(setEnabled(bool)));
        QObject::connect(mRadGpsd, SIGNAL(toggled(bool)), mCboDevices, SLOT(setDisabled(bool)));
        QObject::connect(mRadGpsd, SIGNAL(toggled(bool)), mBtnRefreshDevices, SLOT(setDisabled(bool)));
        QObject::connect(radRecenterWhenNeeded, SIGNAL(toggled(bool)), mSpinMapExtentMultiplier, SLOT(setEnabled(bool)));
        QObject::connect(radRecenterMap, SIGNAL(toggled(bool)), mSpinMapExtentMultiplier, SLOT(setDisabled(bool)));
        QObject::connect(radNeverRecenter, SIGNAL(toggled(bool)), mSpinMapExtentMultiplier, SLOT(setDisabled(bool)));
        QObject::connect(mCbxAutoAddVertices, SIGNAL(toggled(bool)), mBtnAddVertex, SLOT(setDisabled(bool)));
        QObject::connect(mConnectButton, SIGNAL(toggled(bool)), mDeviceGroupBox, SLOT(setDisabled(bool)));
        QObject::connect(mConnectButton, SIGNAL(toggled(bool)), mLogFileGroupBox, SLOT(setDisabled(bool)));
        QObject::connect(mRadInternal, SIGNAL(toggled(bool)), mGpsdHost, SLOT(setDisabled(bool)));
        QObject::connect(mRadInternal, SIGNAL(toggled(bool)), mGpsdPort, SLOT(setDisabled(bool)));
        QObject::connect(mRadInternal, SIGNAL(toggled(bool)), mGpsdDevice, SLOT(setDisabled(bool)));
        QObject::connect(mRadInternal, SIGNAL(toggled(bool)), mCboDevices, SLOT(setDisabled(bool)));
        QObject::connect(mRadInternal, SIGNAL(toggled(bool)), mBtnRefreshDevices, SLOT(setDisabled(bool)));

        mStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsGpsInformationWidgetBase);
    } // setupUi

    void retranslateUi(QgsPanelWidget *QgsGpsInformationWidgetBase)
    {
        QgsGpsInformationWidgetBase->setWindowTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "GPS Connect", nullptr));
#if QT_CONFIG(tooltip)
        mLblStatusIndicator->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Quick status indicator:\n"
"green = good or 3D fix\n"
"yellow = good 2D fix\n"
"red = no fix or bad fix\n"
"gray = no data\n"
"\n"
"2D/3D depends on this information being available", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblStatusIndicator->setText(QString());
        mBtnCloseFeature->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "&Add Feature", nullptr));
        mBtnAddVertex->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Add Track Point", nullptr));
#if QT_CONFIG(tooltip)
        mBtnResetFeature->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Reset track", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnResetFeature->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        mTxtLatitude->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "latitude of position fix (degrees)", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblHdop->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "HDOP", nullptr));
#if QT_CONFIG(tooltip)
        mTxtPdop->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Position Dilution of Precision", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mTxtAltitude->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "antenna altitude with respect to geoid (mean sea level)", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblFixMode->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Mode", nullptr));
#if QT_CONFIG(tooltip)
        mLblSpeed->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        mLblSpeed->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Speed", nullptr));
        mLblAltitude->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Altitude", nullptr));
        mLblLongitude->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Longitude", nullptr));
#if QT_CONFIG(tooltip)
        mTxtFixMode->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "GPS receiver configuration 2D/3D mode: Automatic or Manual", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblLatitude->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Latitude", nullptr));
        mLblUtcTime->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Time of fix", nullptr));
        mLblVacc->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "V accuracy", nullptr));
        mLblFixType->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Dimensions", nullptr));
#if QT_CONFIG(tooltip)
        mTxtSpeed->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "speed over ground", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblVdop->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "VDOP", nullptr));
        mLbl3Dacc->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "3D accuracy", nullptr));
#if QT_CONFIG(tooltip)
        mTxtFixType->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "position fix dimensions: 2D, 3D or No fix", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mTxtQuality->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Positioning quality indicator (NMEA GGA or comparable sentence)", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblStatus->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Status", nullptr));
#if QT_CONFIG(tooltip)
        mTxtDateTime->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "date/time of position fix (UTC)", nullptr));
#endif // QT_CONFIG(tooltip)
        mTxtDateTime->setText(QString());
#if QT_CONFIG(tooltip)
        mTxtSatellitesUsed->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "number of satellites used in the position fix", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblQuality->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Quality", nullptr));
#if QT_CONFIG(tooltip)
        mTxtStatus->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "position fix status: Valid or Invalid", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mTxtDirection->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "track direction (degrees)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mLblDirection->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        mLblDirection->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Direction", nullptr));
        mLblSatellitesUsed->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Satellites", nullptr));
#if QT_CONFIG(tooltip)
        mTxtVdop->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Vertical Dilution of Precision", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblPdop->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "PDOP", nullptr));
#if QT_CONFIG(tooltip)
        mTxtLongitude->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "longitude of position fix (degrees)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        mTxtHdop->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Horizontal Dilution of Precision", nullptr));
#endif // QT_CONFIG(tooltip)
        mLblHacc->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "H accuracy", nullptr));
#if QT_CONFIG(tooltip)
        label_13->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "<html><head/><body><p>Difference between WGS-84 earth ellipsoid and mean sea level.  -=geoid is below WGS-84 ellipsoid</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Geoidal separation", nullptr));
#if QT_CONFIG(tooltip)
        mLogFileGroupBox->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "save GPS data (NMEA sentences) to a file", nullptr));
#endif // QT_CONFIG(tooltip)
        mLogFileGroupBox->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Log File", nullptr));
#if QT_CONFIG(tooltip)
        mBtnLogFile->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "browse for log file", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnLogFile->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Filtering", nullptr));
        label_9->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Distance threshold (meters)", nullptr));
        label_8->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Acquisition interval (seconds)", nullptr));
        mDeviceGroupBox->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Connection", nullptr));
        mRadInternal->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Internal", nullptr));
#if QT_CONFIG(tooltip)
        mBtnRefreshDevices->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Refresh serial device list", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnRefreshDevices->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
        mRadAutodetect->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Autodetect", nullptr));
        label_4->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Port", nullptr));
        label_3->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Host", nullptr));
        label_5->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Device", nullptr));
        mGpsdPort->setInputMask(QCoreApplication::translate("QgsGpsInformationWidgetBase", "00000", nullptr));
        mRadGpsd->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "gpsd", nullptr));
        mRadUserPath->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Serial device", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Digitizing", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Track", nullptr));
        label_6->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Line width", nullptr));
#if QT_CONFIG(tooltip)
        mSpinTrackWidth->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Track width in pixels", nullptr));
#endif // QT_CONFIG(tooltip)
        mSpinTrackWidth->setSuffix(QCoreApplication::translate("QgsGpsInformationWidgetBase", " px", nullptr));
        mCbxAutoAddVertices->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Automatically add points", nullptr));
        label_7->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Line color", nullptr));
        mBtnTrackColor->setStyleSheet(QString());
        mBtnTrackColor->setText(QString());
#if QT_CONFIG(tooltip)
        mCbxAutoCommit->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "save layer after every feature added", nullptr));
#endif // QT_CONFIG(tooltip)
        mCbxAutoCommit->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Automatically save added feature", nullptr));
        mGboxTimestamp->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Timestamp Properties", nullptr));
#if QT_CONFIG(tooltip)
        label_10->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Specify the field where the GPS timestamp will be saved, only string or datetime fields are supported", nullptr));
#endif // QT_CONFIG(tooltip)
        label_10->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Destination", nullptr));
        mLblTimestampFormat->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Format", nullptr));
        mLblTimeZone->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Timezone", nullptr));
#if QT_CONFIG(tooltip)
        mCbxLeapSeconds->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Apply leap seconds correction by adding the seconds to GPS timestamp", nullptr));
#endif // QT_CONFIG(tooltip)
        mCbxLeapSeconds->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Leap seconds", nullptr));
#if QT_CONFIG(tooltip)
        mTravelBearingCheckBox->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "If checked, the bearing reported by the GPS device will be ignored and the bearing will instead be calculated by the angle between the previous two GPS locations", nullptr));
#endif // QT_CONFIG(tooltip)
        mTravelBearingCheckBox->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Calculate bearing from travel direction", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Map Centering and Rotation", nullptr));
        mSpinMapExtentMultiplier->setSuffix(QCoreApplication::translate("QgsGpsInformationWidgetBase", "% of map extent", nullptr));
        radRecenterMap->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Always", nullptr));
        radRecenterWhenNeeded->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "When leaving", nullptr));
        radNeverRecenter->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Never", nullptr));
        mRotateMapCheckBox->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Rotate map to match GPS direction", nullptr));
        label_12->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Frequency", nullptr));
        mSpinMapRotateInterval->setSpecialValueText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "On GPS signal", nullptr));
        mSpinMapRotateInterval->setSuffix(QCoreApplication::translate("QgsGpsInformationWidgetBase", " s", nullptr));
        mGroupShowMarker->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Cursor", nullptr));
        label_2->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Large", nullptr));
        label->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Small", nullptr));
        mShowBearingLineCheck->setTitle(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Show Bearing Line", nullptr));
        label_11->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Line style", nullptr));
        mBearingLineStyleButton->setText(QString());
#if QT_CONFIG(tooltip)
        mBtnPosition->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Position", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnPosition->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        mBtnSignal->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Signal", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnSignal->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        mBtnSatellites->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Satellite", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnSatellites->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        mBtnOptions->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Options", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnOptions->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        mBtnDebug->setToolTip(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Debug", nullptr));
#endif // QT_CONFIG(tooltip)
        mBtnDebug->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "\342\200\246", nullptr));
        mRecenterButton->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "Recenter", nullptr));
        mConnectButton->setText(QCoreApplication::translate("QgsGpsInformationWidgetBase", "&Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsGpsInformationWidgetBase: public Ui_QgsGpsInformationWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSGPSINFORMATIONWIDGETBASE_H
