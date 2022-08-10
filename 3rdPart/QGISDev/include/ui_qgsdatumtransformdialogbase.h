/********************************************************************************
** Form generated from reading UI file 'qgsdatumtransformdialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSDATUMTRANSFORMDIALOGBASE_H
#define UI_QGSDATUMTRANSFORMDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscoordinateoperationwidget.h"
#include "qgsprojectionselectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsDatumTransformDialogBase
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *mButtonBox;
    QTextEdit *textEdit;
    QStackedWidget *mCrsStackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QgsProjectionSelectionWidget *mSourceProjectionSelectionWidget;
    QLabel *label_2;
    QgsProjectionSelectionWidget *mDestinationProjectionSelectionWidget;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *mDestCrsLabel;
    QLabel *mSourceCrsLabel;
    QgsCoordinateOperationWidget *mCoordinateOperationsWidget;

    void setupUi(QDialog *QgsDatumTransformDialogBase)
    {
        if (QgsDatumTransformDialogBase->objectName().isEmpty())
            QgsDatumTransformDialogBase->setObjectName(QString::fromUtf8("QgsDatumTransformDialogBase"));
        QgsDatumTransformDialogBase->resize(651, 433);
        gridLayout = new QGridLayout(QgsDatumTransformDialogBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mButtonBox = new QDialogButtonBox(QgsDatumTransformDialogBase);
        mButtonBox->setObjectName(QString::fromUtf8("mButtonBox"));
        mButtonBox->setOrientation(Qt::Horizontal);
        mButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        gridLayout->addWidget(mButtonBox, 4, 0, 1, 2);

        textEdit = new QTextEdit(QgsDatumTransformDialogBase);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setAcceptDrops(false);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setLineWidth(2);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 2);

        mCrsStackedWidget = new QStackedWidget(QgsDatumTransformDialogBase);
        mCrsStackedWidget->setObjectName(QString::fromUtf8("mCrsStackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        mSourceProjectionSelectionWidget = new QgsProjectionSelectionWidget(page);
        mSourceProjectionSelectionWidget->setObjectName(QString::fromUtf8("mSourceProjectionSelectionWidget"));

        gridLayout_4->addWidget(mSourceProjectionSelectionWidget, 0, 1, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        mDestinationProjectionSelectionWidget = new QgsProjectionSelectionWidget(page);
        mDestinationProjectionSelectionWidget->setObjectName(QString::fromUtf8("mDestinationProjectionSelectionWidget"));

        gridLayout_4->addWidget(mDestinationProjectionSelectionWidget, 1, 1, 1, 1);

        gridLayout_4->setColumnStretch(1, 1);

        verticalLayout->addLayout(gridLayout_4);

        mCrsStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        mDestCrsLabel = new QLabel(page_2);
        mDestCrsLabel->setObjectName(QString::fromUtf8("mDestCrsLabel"));

        gridLayout_5->addWidget(mDestCrsLabel, 1, 1, 1, 1);

        mSourceCrsLabel = new QLabel(page_2);
        mSourceCrsLabel->setObjectName(QString::fromUtf8("mSourceCrsLabel"));

        gridLayout_5->addWidget(mSourceCrsLabel, 0, 1, 1, 1);

        gridLayout_5->setColumnStretch(1, 1);

        verticalLayout_2->addLayout(gridLayout_5);

        mCrsStackedWidget->addWidget(page_2);

        gridLayout->addWidget(mCrsStackedWidget, 1, 0, 1, 2);

        mCoordinateOperationsWidget = new QgsCoordinateOperationWidget(QgsDatumTransformDialogBase);
        mCoordinateOperationsWidget->setObjectName(QString::fromUtf8("mCoordinateOperationsWidget"));

        gridLayout->addWidget(mCoordinateOperationsWidget, 3, 0, 1, 2);

        gridLayout->setRowStretch(3, 1);

        retranslateUi(QgsDatumTransformDialogBase);
        QObject::connect(mButtonBox, SIGNAL(accepted()), QgsDatumTransformDialogBase, SLOT(accept()));
        QObject::connect(mButtonBox, SIGNAL(rejected()), QgsDatumTransformDialogBase, SLOT(reject()));

        mCrsStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsDatumTransformDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsDatumTransformDialogBase)
    {
        QgsDatumTransformDialogBase->setWindowTitle(QCoreApplication::translate("QgsDatumTransformDialogBase", "Select Datum Transformations", nullptr));
        textEdit->setHtml(QCoreApplication::translate("QgsDatumTransformDialogBase", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Multiple operations are possible for converting coordinates between these two Coordinate Reference Systems.</span> Please select the appropriate conversion operation, given the desired area of use, origins of your data, and any other constraints which may alter the &quot;fit for purpose&quot; for particular transformation operations.</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("QgsDatumTransformDialogBase", "Source CRS", nullptr));
        label_2->setText(QCoreApplication::translate("QgsDatumTransformDialogBase", "Destination CRS", nullptr));
        label_3->setText(QCoreApplication::translate("QgsDatumTransformDialogBase", "Source CRS", nullptr));
        label_4->setText(QCoreApplication::translate("QgsDatumTransformDialogBase", "Destination CRS", nullptr));
        mDestCrsLabel->setText(QString());
        mSourceCrsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QgsDatumTransformDialogBase: public Ui_QgsDatumTransformDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSDATUMTRANSFORMDIALOGBASE_H
