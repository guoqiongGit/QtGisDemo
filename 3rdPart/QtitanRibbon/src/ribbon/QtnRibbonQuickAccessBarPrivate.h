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
#ifndef QTN_RIBBONQUICKACCESSBARPRIVATER_H
#define QTN_RIBBONQUICKACCESSBARPRIVATER_H

#include <QToolButton>
#include "QtnRibbonBar.h"
#include "QtnStyleOption.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonQuickAccessBar.h"
#include "QtnRibbonCustomizeManager.h"
#include "QtnRibbonCustomizeManagerPrivate.h"
#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

/* RibbonQuickAccessButton */
class RibbonQuickAccessButton : public QToolButton
{
    Q_OBJECT
public:
    RibbonQuickAccessButton(QWidget* parent = Q_NULL);
    virtual ~RibbonQuickAccessButton();
public:
    virtual QSize sizeHint() const;
protected:
    virtual void paintEvent(QPaintEvent* event);
private:
    Q_DISABLE_COPY(RibbonQuickAccessButton)
};

/* QuickAccessAction */
class QuickAccessAction : public QAction
{
    Q_OBJECT
public:
    QuickAccessAction(QObject* p, QAction* srcAction)
        : QAction(srcAction->text(), p)
        , m_srcAction(srcAction)
    {
        setCheckable(true);
        QToolBar* toolBar = qobject_cast<QToolBar*>(parent());
        Q_ASSERT(toolBar);
        setChecked(toolBar->widgetForAction(srcAction));
    }
    void update()
    {
        QToolBar* toolBar = qobject_cast<QToolBar*>(parent());
        Q_ASSERT(toolBar);
        setChecked(toolBar->widgetForAction(m_srcAction));
        setText(m_srcAction->text());
    }
public:
    QAction* m_srcAction;
private:
    Q_DISABLE_COPY(QuickAccessAction)
};

/* QuickAccessActionInvisible */
class QuickAccessActionInvisible : public QAction
{
    Q_OBJECT
public:
    QuickAccessActionInvisible(QObject* p, QActionGroup* data)
        : QAction(p)
        , m_data(data)
    {
        setProperty(__qtn_Action_Invisible, QLatin1String("__qtn_Action_Invisible"));
        setVisible(false);
    }
public:
    QActionGroup* m_data;
private:
    Q_DISABLE_COPY(QuickAccessActionInvisible)
};

/* RibbonQuickAccessBarPrivate */
class RibbonQuickAccessBarPrivate : public QObject
{
    Q_OBJECT
public:
    QTN_DECLARE_PUBLIC(RibbonQuickAccessBar)
public:
    explicit RibbonQuickAccessBarPrivate();
    virtual ~RibbonQuickAccessBarPrivate();
public:
    void init();
    RibbonBar* ribbonBar() const;
    QuickAccessAction* findQuickAccessAction(QAction* action) const;
    QAction* findBeforeAction(QAction* action) const;
    void updateAction(QAction* action);
    void setActionVisible(QAction* action, bool visible);
    void initStyleOption(RibbonQuickAccessBarStyleOption* option) const;
public:
    QMenu* m_menu;
    QAction* m_actionAccessPopup;
    QActionGroup* m_customizeGroupAction;
    RibbonQuickAccessButton* m_accessPopup;
    RibbonToolTipManager* m_ribbonToolTipManager;
    QList<QAction*> m_actionList;
    bool m_removeAction : 1;
    bool m_customizeAction : 1;
private:
    Q_DISABLE_COPY(RibbonQuickAccessBarPrivate)
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONQUICKACCESSBARPRIVATER_H
