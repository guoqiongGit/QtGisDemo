/****************************************************************************
**
** Qtitan Library by Developer Machines (Microsoft-Ribbon implementation for Qt.C++)
** 
** Copyright (c) 2009-2021 Developer Machines (https://www.devmachines.com)
**           ALL RIGHTS RESERVED
** 
**  The entire contents of this file is protected by copyright law and
**  international treaties. Unauthorized reproduction, reverse-engineering
**  and distribution of all or any portion of the code contained in this
**  file is strictly prohibited and may result in severe civil and 
**  criminal penalties and will be prosecuted to the maximum extent 
**  possible under the law.
**
**  RESTRICTIONS
**
**  THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED
**  FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE
**  COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE
**  AVAILABLE TO OTHER INDIVIDUALS WITHOUT WRITTEN CONSENT
**  AND PERMISSION FROM DEVELOPER MACHINES
**
**  CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON
**  ADDITIONAL RESTRICTIONS.
**
****************************************************************************/

#ifndef QTN_RIBBONPAGE_DSGN_H
#define QTN_RIBBONPAGE_DSGN_H

#include <qglobal.h>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#else
#include <QDesignerCustomWidgetInterface>
#endif
#include <QtDesigner/QDesignerFormWindowInterface>
#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class DsgnRibbonPagePlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
#if (QT_VERSION >= 0x050000)
    Q_INTERFACES(QDesignerCustomWidgetInterface)
#endif
public:
    explicit DsgnRibbonPagePlugin(QObject* parent = 0);
    virtual ~DsgnRibbonPagePlugin();
public:
    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget* createWidget(QWidget* parent);
    void initialize(QDesignerFormEditorInterface* core);
private Q_SLOTS:
    void titleChanged(const QString& title);
private:
    bool m_initialized;
    QDesignerFormEditorInterface* m_core;
};

QTITAN_END_NAMESPACE

#endif //QTN_RIBBONPAGE_DSGN_H
