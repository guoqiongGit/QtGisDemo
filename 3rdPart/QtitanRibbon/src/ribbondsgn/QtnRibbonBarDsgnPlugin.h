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

#ifndef QTN_RIBBON_DSGN_H
#define QTN_RIBBON_DSGN_H

#include <QObject>
#include <QAction>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#else
#include <QDesignerCustomWidgetInterface>
#endif
#include <QtDesigner/QExtensionFactory>
#include "QtnRibbonBar.h"
#include "QtitanDef.h"

class QDesignerFormWindowInterface;
class QContextMenuEvent;

QTITAN_BEGIN_NAMESPACE

class DesignerRibbonBar : public RibbonBar
{
    Q_OBJECT
public:
    static DesignerRibbonBar* createRibbonBar(QWidget* parent);
    virtual ~DesignerRibbonBar();
protected:
    explicit DesignerRibbonBar(QWidget* parent);
private Q_SLOTS:
    void slotRemoveRibbonBar();
    void slotAddNewPage();
    void slotRemoveCurrentPage();
protected:
    virtual bool event(QEvent* event);
    virtual void contextMenuEvent(QContextMenuEvent* event);
    virtual void resizeEvent(QResizeEvent* event);
private:
    QAction* m_removeRibbonBar;
    QAction* m_addRibbonPage;
    QAction* m_removeRibbonPage;
private:
    Q_DISABLE_COPY(DesignerRibbonBar)
};

class DsgnFormRibbonManagerFilter;
/* DsgnRibbonBarPlugin */
class DsgnRibbonBarPlugin : public QObject, public QDesignerCustomWidgetInterface
{                                               
    Q_OBJECT
#if (QT_VERSION >= 0x050000)
    Q_INTERFACES(QDesignerCustomWidgetInterface)
#endif
public:
    explicit DsgnRibbonBarPlugin(QObject* parent = Q_NULL);
public:
    virtual bool isContainer() const;
    virtual bool isInitialized() const;
    virtual QIcon icon() const;
    virtual QString domXml() const;
    virtual QString group() const;
    virtual QString includeFile() const;
    virtual QString name() const;
    virtual QString toolTip() const;
    virtual QString whatsThis() const;
    virtual QWidget* createWidget(QWidget* parent);
    virtual void initialize(QDesignerFormEditorInterface* core);
private Q_SLOTS:
    void currentPageChanged(int index);
    void selectionChanged();
    void formWindowAdded(QDesignerFormWindowInterface *formWindow);
    void formWindowRemoved(QDesignerFormWindowInterface *formWindow);
    void widgetManaged(QWidget* widget);
private:
    bool m_initialized;
    QDesignerFormEditorInterface* m_core;
    DsgnFormRibbonManagerFilter* m_managerFilter;
private:
    Q_DISABLE_COPY(DsgnRibbonBarPlugin)
};


/* DsgnFormWindowManagerFilter */
class DsgnFormRibbonManagerFilter : public QObject
{
public:
    DsgnFormRibbonManagerFilter(QDesignerFormEditorInterface* core, QDesignerFormWindowInterface* formWindow, QObject* parent);
protected:
    virtual bool eventFilter(QObject* o, QEvent* event);
protected:
    QDesignerFormEditorInterface* m_core;
    QDesignerFormWindowInterface* m_formWindow;
private:
    Q_DISABLE_COPY(DsgnFormRibbonManagerFilter)
};


QTITAN_END_NAMESPACE

#endif //QTN_RIBBON_DSGN_H
