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
#include <QApplication>
#include <QStyleOption>
#include <QMenu>
#include <QPainter>
#include <QToolButton>
#include <QLayout>
#include <qevent.h>

#include "QtnCommonStyle.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnRibbonQuickAccessBarPrivate.h"
#include "QtnCommonStylePrivate.h"
#include "QtnRibbonDef.h"
#ifdef DEBUG_MEMORY_ENABLED
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

/* RibbonQuickAccessButton */
RibbonQuickAccessButton::RibbonQuickAccessButton(QWidget* parent)
    : QToolButton(parent)
{
    setObjectName(QStringLiteral("QtnRibbonQuickAccessButton"));
}

RibbonQuickAccessButton::~RibbonQuickAccessButton()
{
}

QSize RibbonQuickAccessButton::sizeHint() const
{
    QSize sz = QToolButton::sizeHint();
    return QSize(sz.width() / 2, sz.height());
}

void RibbonQuickAccessButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)
        QPainter p(this);
    QStyleOptionToolButton opt;
    initStyleOption(&opt);

    QStyleHintReturnVariant ret;
    if (!style()->styleHint((QStyle::StyleHint)CommonStyle::SH_WindowTitleBarPalette, &opt, window(), &ret))
    {
        QWidget* parent = this->parentWidget();
        if (parent && parent->parentWidget() &&
            parent->parentWidget()->inherits(QTITAN_META_CLASSNAME("RibbonTitleBarWidget")))
        {
            RibbonTitleBarWidget* titleBarWidget = (RibbonTitleBarWidget*)parent->parentWidget();
            if (WindowTitleBar* titleBar = titleBarWidget->getWindowTitleBar())
            {
                QStyleOptionTitleBar titleOpt;
                titleBar->initStyleOption(&titleOpt);
                opt.palette.setColor(QPalette::Window, titleOpt.palette.color(QPalette::Window));
            }
        }
    }
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonQuickAccessButton, &opt, &p, this);
}

/* RibbonQuickAccessBarPrivate */
RibbonQuickAccessBarPrivate::RibbonQuickAccessBarPrivate()
    : m_menu(Q_NULL)
    , m_actionAccessPopup(Q_NULL)
    , m_customizeGroupAction(Q_NULL)
    , m_accessPopup(Q_NULL)
    , m_ribbonToolTipManager(Q_NULL)
    , m_removeAction(false)
    , m_customizeAction(false)
{
}

RibbonQuickAccessBarPrivate::~RibbonQuickAccessBarPrivate()
{
}

void RibbonQuickAccessBarPrivate::init()
{
    QTN_P(RibbonQuickAccessBar);
    p.setAutoFillBackground(false);
    p.setAttribute(Qt::WA_NoSystemBackground);
    p.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    static int sz = p.style()->pixelMetric(QStyle::PM_SmallIconSize, Q_NULL, &p);
    p.setIconSize(QSize(sz, sz));

    m_accessPopup = new RibbonQuickAccessButton(&p);
    m_accessPopup->setPopupMode(QToolButton::InstantPopup);
    m_menu = new QMenu(&p);
    m_accessPopup->setMenu(m_menu);

    m_actionAccessPopup = p.addWidget(m_accessPopup);
    m_actionAccessPopup->setProperty(__qtn_Quick_Access_Button, QStringLiteral("__qtn_Quick_Access_Button"));

    m_customizeGroupAction = new QActionGroup(&p);
    m_customizeGroupAction->setExclusive(false);
    QObject::connect(m_customizeGroupAction, SIGNAL(triggered(QAction*)), &p, SLOT(customizeAction(QAction*)));

    QObject::connect(m_menu, SIGNAL(aboutToShow()), &p, SLOT(aboutToShowCustomizeMenu()));
    QObject::connect(m_menu, SIGNAL(aboutToHide()), &p, SLOT(aboutToHideCustomizeMenu()));

    m_ribbonToolTipManager = new RibbonToolTipManager(&p);

    p.addAction(new QuickAccessActionInvisible(&p, m_customizeGroupAction));
}

RibbonBar* RibbonQuickAccessBarPrivate::ribbonBar() const
{
    QTN_P(const RibbonQuickAccessBar);
    QWidget* parent = p.parentWidget();
    while (parent != Q_NULL)
    {
        if (RibbonBar* ribbonBar = qobject_cast<RibbonBar*>(parent))
        {
            return ribbonBar;
        }
        else if (RibbonTitleBarWidget* titleBar = qobject_cast<RibbonTitleBarWidget*>(parent))
        {
            if (RibbonBar* ribbonBar = titleBar->ribbonBar())
                return ribbonBar;
        }
        parent = parent->parentWidget();
    }
    return Q_NULL;
}

QuickAccessAction* RibbonQuickAccessBarPrivate::findQuickAccessAction(QAction* action) const
{
    if (m_customizeGroupAction == Q_NULL)
        return Q_NULL;

    QList<QAction*> list = m_customizeGroupAction->actions();
    for (int i = 0; i < list.count(); ++i)
    {
        QuickAccessAction* act = dynamic_cast<QuickAccessAction*>(list[i]);
        if (act && action == act->m_srcAction)
            return act;
    }
    return Q_NULL;
}

QAction* RibbonQuickAccessBarPrivate::findBeforeAction(QAction* action) const
{
    QList<QAction*> list = m_customizeGroupAction->actions();
    bool find = false;
    for (int i = 0, count = list.count(); i < count; ++i)
    {
        if (find)
        {
            if (QuickAccessAction* beforeAct = dynamic_cast<QuickAccessAction*>(list[i]))
            {
                if (beforeAct->isChecked())
                    return beforeAct->m_srcAction;
            }
        }
        if (!find && action == list[i])
            find = true;
    }
    return Q_NULL;
}

void RibbonQuickAccessBarPrivate::updateAction(QAction* action)
{
    if (QuickAccessAction* wrapper = findQuickAccessAction(action))
        wrapper->update();
}

void RibbonQuickAccessBarPrivate::setActionVisible(QAction* action, bool visible)
{
    QTN_P(RibbonQuickAccessBar);
    if (QuickAccessAction* wrapper = findQuickAccessAction(action))
    {
        if (visible)
        {
            if (m_customizeAction)
            {
                QAction* beforeAct = findBeforeAction(wrapper);
                p.insertAction(beforeAct, action);
            }
            else
                p.addAction(action);
        }
        else
        {
            p.removeAction(action);
            m_removeAction = false;
        }
        wrapper->update();
        p.adjustSize();
    }
}

void RibbonQuickAccessBarPrivate::initStyleOption(RibbonQuickAccessBarStyleOption* option) const
{
    if (RibbonBar* ribbonBar = this->ribbonBar())
    {
        option->init(ribbonBar);
        RibbonBar::QuickAccessBarPosition position = ribbonBar->quickAccessBarPosition();
        if (position == RibbonBar::QATopPosition)
            option->quickAccessBarPosition = RibbonBar::QATopPosition;
        else if (position == RibbonBar::QABottomPosition)
            option->quickAccessBarPosition = RibbonBar::QABottomPosition;
    }
}

/*!
\class RibbonQuickAccessBar
\inmodule QtitanRibbon
\brief RibbonQuickAccessBar class quick access ToolBar, which is located on RibbonBar.
Quick access toolbar contains a set of controls that are always available to users regardless of which page is selected.
*/

/*!
Constructs RibbonQuickAccessBar object with the given \a parent.
*/
RibbonQuickAccessBar::RibbonQuickAccessBar(QWidget* parent)
    : QToolBar(parent)
{
    QTN_INIT_PRIVATE(RibbonQuickAccessBar);
    QTN_D(RibbonQuickAccessBar);
    d.init();
}

/*!
Destructor of the RibbonQuickAccessBar object.
*/
RibbonQuickAccessBar::~RibbonQuickAccessBar()
{
    QTN_FINI_PRIVATE();
}

/*!
\brief Returns a pointer to the QAction that is associated with the customize button of Ribbon's Quick Access Bar.
*/
QAction* RibbonQuickAccessBar::actionCustomizeButton() const
{
    QTN_D(const RibbonQuickAccessBar);
    return d.m_actionAccessPopup;
}

/*!
\brief Sets the visibility of the visual representation of action on the quick access toolbar. Parameter \a action is action, parameter \a visible is a visibility.
*/
void RibbonQuickAccessBar::setActionVisible(QAction* action, bool visible)
{
    QTN_D(RibbonQuickAccessBar);
    d.setActionVisible(action, visible);
}

/*!
\brief Returns the visibility of the visual representation for the given \a action.
*/
bool RibbonQuickAccessBar::isActionVisible(QAction* action) const
{
    QTN_D(const RibbonQuickAccessBar);
    if (QuickAccessAction* wrapper = d.findQuickAccessAction(action))
        return wrapper->isChecked();
    return false;
}

/*!
\brief Returns the count of the elements visible on Ribbon's Quick Access Bar.
*/
int RibbonQuickAccessBar::visibleCount() const
{
    QTN_D(const RibbonQuickAccessBar);
    int visibleCount = 0;
    QList<QAction*> list = d.m_customizeGroupAction->actions();
    for (int i = 0, count = list.count(); i < count; ++i)
    {
        if (QuickAccessAction* beforeAct = dynamic_cast<QuickAccessAction*>(list[i]))
            if (beforeAct->isChecked())
                visibleCount++;
    }
    return visibleCount;
}

/*!
\brief Returns the recommended size for Ribbon's Quick Access Bar.
\reimp
*/
QSize RibbonQuickAccessBar::sizeHint() const
{
    QTN_D(const RibbonQuickAccessBar);
    RibbonQuickAccessBarStyleOption opt;
    d.initStyleOption(&opt);
    RibbonBar* ribbonBar = d.ribbonBar();
    if (ribbonBar != Q_NULL && opt.quickAccessBarPosition == RibbonBar::QABottomPosition)
        return QSize(QToolBar::sizeHint().width(), RibbonBarPrivate::_get(ribbonBar)->heightTabs() + 1);
    return QToolBar::sizeHint();
}

/*! \internal */
void RibbonQuickAccessBar::customizeAction(QAction* action)
{
    QTN_D(RibbonQuickAccessBar);
    d.m_customizeAction = true;
    if (QuickAccessAction* act = dynamic_cast<QuickAccessAction*>(action))
    {
        setActionVisible(act->m_srcAction, !widgetForAction(act->m_srcAction));
        if (RibbonBar* ribbonBar = d.ribbonBar())
        {
            RibbonCustomizeManager* manager = ribbonBar->customizeManager();
            manager->setEditMode();
            manager->qtn_d().m_ribbonManager->setQuickAccessBar();
            manager->setEditMode(false);
        }
    }
    d.m_customizeAction = false;
}

/*! \internal */
void RibbonQuickAccessBar::aboutToShowCustomizeMenu()
{
    QTN_D(RibbonQuickAccessBar);
    d.m_menu->clear();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    if (style()->styleHint(QStyle::SH_Menu_SupportsSections))
    {
        d.m_menu->setSeparatorsCollapsible(false);
        d.m_menu->addSection(RibbonBar::tr_compatible(QtnRibbonCustomizeQuickAccessToolBarString));
    }
#else
    d.m_menu->setSeparatorsCollapsible(false);
    d.m_menu->addSeparator()->setText(RibbonBar::tr_compatible(QtnRibbonCustomizeQuickAccessToolBarString));
#endif
    QListIterator<QAction*> itAction(d.m_actionList);
    while (itAction.hasNext())
    {
        QAction* action = itAction.next();
        d.m_menu->addAction(action);
    }
    emit showCustomizeMenu(d.m_menu);
}

/*! \internal */
void RibbonQuickAccessBar::aboutToHideCustomizeMenu()
{
    QTN_D(RibbonQuickAccessBar);
    d.m_menu->clear();
}

/*! \reimp */
bool RibbonQuickAccessBar::event(QEvent* event)
{
    if (parentWidget() && (event->type() == QEvent::Hide || event->type() == QEvent::Show))
    {
        adjustSize();
    }
    else if (event->type() == QEvent::StyleChange)
    {
        const int sz = style()->pixelMetric(QStyle::PM_SmallIconSize, Q_NULL, this);
        setIconSize(QSize(sz, sz));
    }
    return QToolBar::event(event);
}

/*! \reimp */
void RibbonQuickAccessBar::actionEvent(QActionEvent* event)
{
    QTN_D(RibbonQuickAccessBar);
    QToolBar::actionEvent(event);
    if (d.m_actionAccessPopup)
    {
        if (event->type() == QEvent::ActionAdded)
        {
            if (!d.m_removeAction)
                removeAction(d.m_actionAccessPopup);

            QuickAccessAction* quickAccessAction = d.findQuickAccessAction(event->action());
            if (event->action() != d.m_actionAccessPopup && !quickAccessAction &&
                !dynamic_cast<QuickAccessActionInvisible*>(event->action()))
            {
                QuickAccessAction* act = new QuickAccessAction(this, event->action());

                bool addActionToMenu = true;
                if (RibbonBar* ribbonBar = d.ribbonBar())
                {
                    RibbonCustomizeManager* manager = ribbonBar->customizeManager();
                    if (manager->isEditMode())
                    {
                        QList< QAction* > defaultActions = manager->qtn_d().m_ribbonManager->defaultToolBars().value(this);
                        if (!defaultActions.contains(event->action()))
                            addActionToMenu = false;
                    }
                }

                if (addActionToMenu)
                    d.m_actionList.append(act);

                d.m_customizeGroupAction->addAction(act);
                adjustSize();
            }
            else if (quickAccessAction)
                quickAccessAction->update();
        }
        else if (event->type() == QEvent::ActionRemoved)
        {
            if (event->action() == d.m_actionAccessPopup)
            {
                d.m_removeAction = true;
                addAction(d.m_actionAccessPopup);
                d.m_removeAction = false;
            }
            else if (QuickAccessActionInvisible* actInvisible = dynamic_cast<QuickAccessActionInvisible*>(event->action()))
            {
                d.m_actionList.clear();
                QList<QAction*> actList = actInvisible->m_data->actions();
                for (int i = actList.size() - 1; i >= 0; i--)
                {
                    QAction* actionWrapper = actList[i];
                    d.m_customizeGroupAction->removeAction(actionWrapper);
                    delete actionWrapper;
                }
                delete actInvisible;
                addAction(new QuickAccessActionInvisible(this, d.m_customizeGroupAction));
            }
            else
                d.updateAction(event->action());
        }
        else if (event->type() == QEvent::ActionChanged)
        {
            if (event->action() == d.m_actionAccessPopup)
                d.m_accessPopup->setDefaultAction(d.m_actionAccessPopup);
            else if (!dynamic_cast<QuickAccessAction*>(event->action()))
                d.updateAction(event->action());
        }
    }
}

/*! \reimp */
void RibbonQuickAccessBar::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QTN_D(RibbonQuickAccessBar);
    QPainter p(this);
    RibbonQuickAccessBarStyleOption opt;
    d.initStyleOption(&opt);
    style()->drawControl(QStyle::CE_ToolBar, &opt, &p, this);
}
