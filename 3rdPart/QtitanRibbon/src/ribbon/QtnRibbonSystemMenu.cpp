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
#include <QScreen>
#include <QPaintEvent>
#include <QPainter>
#include <QStyleOption>
#include <QWidgetAction>
#include <QFileInfo>
#include <QColor>
#include <QKeySequence>
#include <qevent.h>

#include "QtnRibbonSystemMenuPrivate.h"
#include "QtnRibbonBackstageView.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonButtonPrivate.h"
#include "QtnCommonStylePrivate.h"
#include "QtnCommonStyle.h"
#include "QtnStyleOption.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnRibbonDef.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

/* RibbonSystemButton */
RibbonSystemButton::RibbonSystemButton(QWidget* parent)
    : QToolButton(parent)
{
    QTN_INIT_PRIVATE(RibbonSystemButton);
    qApp->installEventFilter(this);
}

RibbonSystemButton::~RibbonSystemButton()
{
    QTN_FINI_PRIVATE();
}

RibbonBackstageView* RibbonSystemButton::backstage() const
{
    QTN_D(const RibbonSystemButton);
    return qobject_cast<RibbonBackstageView*>(d.m_widget);
}

void RibbonSystemButton::setBackstage(RibbonBackstageView* backstage)
{
    Q_ASSERT(backstage != Q_NULL);
    if (!backstage)
        return; 

    QTN_D(RibbonSystemButton);
    if (QAction* action = defaultAction())
    {
        d.m_widget = Q_NULL;
        if (QMenu* menu = action->menu())
        {
            action->setMenu(Q_NULL);
            delete menu;
        }

        d.m_widget = backstage;
        connect(action, SIGNAL(triggered()), backstage, SLOT(open()));
    }
}

void RibbonSystemButton::setBackgroundColor(const QColor& color)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Button, color);
    setPalette(pal);
    update();
}

QColor RibbonSystemButton::backgroundColor() const
{
    return palette().color(QPalette::Button);
}

RibbonSystemMenu* RibbonSystemButton::systemMenu() const
{
    if (defaultAction() == Q_NULL)
        return Q_NULL;
    return qobject_cast<RibbonSystemMenu *>(defaultAction()->menu());
}

void RibbonSystemButton::setSystemMenu(RibbonSystemMenu* menu)
{
    if (defaultAction() == Q_NULL)
    {
        QAction* action = new QAction(this);
        setDefaultAction(action);
    }
    defaultAction()->setMenu(menu);
}

void RibbonSystemButton::initButtonStyleOption(SystemToolButtonStyleOption* option) const
{
    Qt::ToolButtonStyle styleButton = toolButtonStyle();
    initStyleOption(option);
    option->toolButtonStyle = styleButton;
    if (!option->icon.isNull())
    {
        QPixmap pm = option->icon.pixmap(iconSize());
        option->iconSize = pm.size();
    }
}

/*! \reimp */
QSize RibbonSystemButton::sizeHint() const
{
    QSize sz = QToolButton::sizeHint();

    RibbonBar* ribbonBar = qobject_cast<RibbonBar*>(parentWidget());
    if (ribbonBar == Q_NULL)
        return sz;

    SystemToolButtonStyleOption opt;
    initStyleOption(&opt);

    QRect rc = opt.rect;
    if (opt.toolButtonStyle == Qt::ToolButtonFollowStyle)
        rc.adjust(2, 2, -2, -2);

    int index = -1;
    int curArea = 0;
    const int actualArea = rc.height()*rc.width();
    const QList<QSize> lSz = opt.icon.availableSizes();
    for (int i = 0, count = lSz.count(); count > i; i++)
    {
        QSize curSz = lSz[i];
        int area = curSz.height()*curSz.width();
        if (actualArea > area)
        {
            if (area > curArea)
                index = i;
            curArea = area;
        }
    }

    RibbonSystemButton* that = const_cast<RibbonSystemButton*>(this);
    if (index >= 0 && index < lSz.size())
        that->setIconSize(lSz[index]);

    int indent = 0;
    if (opt.toolButtonStyle == Qt::ToolButtonTextOnly)
        indent = qtn_horizontalAdvanceFont(opt.fontMetrics, QLatin1Char('x')) * 4;
    else if (opt.toolButtonStyle == Qt::ToolButtonIconOnly)
        indent = 24;

    int heightTabs = RibbonBarPrivate::_get(ribbonBar)->heightTabs();// -2;
    return QSize(sz.width() + indent, heightTabs).expandedTo(QApplication::globalStrut());
}

/*! \reimp */
bool RibbonSystemButton::event(QEvent* event)
{
    QTN_D(RibbonSystemButton)
    bool result = QToolButton::event(event);
    switch (event->type()) 
    {
        case QEvent::HoverEnter:
        case QEvent::HoverLeave:
        case QEvent::HoverMove:
            d.updateExtension();
            break;
        default:
            break;
    }
    return result;
}

/*! \reimp */
bool RibbonSystemButton::eventFilter(QObject* watched, QEvent* event)
{
    QTN_D(RibbonSystemButton)
    if (RibbonBar* ribbon = qobject_cast<RibbonBar*>(parentWidget()))
    {
        RibbonBarPrivate* privateRibbon = RibbonBarPrivate::_get(ribbon);
        if (watched == privateRibbon->m_ribbonTitleBarWidget)
        {
            switch (event->type())
            {
                case QEvent::MouseButtonPress:
                {
                    if (toolButtonStyle() != Qt::ToolButtonFollowStyle)
                        break;
                    if (const QMouseEvent* me = static_cast<const QMouseEvent*>(event))
                    {
                        QPoint pnt = this->window()->mapFromGlobal(QCursor::pos());
                        QRect rect = geometry();
                        if (rect.contains(pnt))
                        {
                            QMouseEvent mEvent(QEvent::MouseButtonPress, rect.bottomRight(),
                                rect.bottomRight(), me->button(), me->buttons(), me->modifiers());
                            this->event(&mEvent);
                        }
                    }
                    break;
                }
                case QEvent::HoverEnter:
                case QEvent::HoverLeave:
                case QEvent::HoverMove:
                {
                    if (toolButtonStyle() != Qt::ToolButtonFollowStyle)
                        break;
                    QPoint pnt = this->window()->mapFromGlobal(QCursor::pos());
                    QRect rect = geometry();
                    if (rect.contains(pnt))
                        setAttribute(Qt::WA_UnderMouse, true);
                    else if (event->type() == QEvent::HoverLeave)
                        setAttribute(Qt::WA_UnderMouse, false);
                    d.updateExtension();
                    break;
                }
                default:
                    break;
            }
        }
    }
    return QToolButton::eventFilter(watched, event);
}

/*! \reimp */
void RibbonSystemButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this);
    SystemToolButtonStyleOption opt;
    initButtonStyleOption(&opt);
    // draw pixmap ribbonFileButton
    style()->drawComplexControl(static_cast<QStyle::ComplexControl>(CommonStyle::CC_RibbonFileButton), &opt, &p, this);
}

/*! \reimp */
void RibbonSystemButton::mousePressEvent(QMouseEvent* event)
{
    QTN_D(RibbonSystemButton);
    if (RibbonBackstageView* backstage = qobject_cast<RibbonBackstageView*>(d.m_widget))
    {
        if (backstage->isVisible())
        {
            backstage->close();
            return; 
        }
    }
    d.updateExtension();
    QToolButton::mousePressEvent(event);
    d.updateExtension();
}

void RibbonSystemButtonPrivate::updateExtension()
{
    QTN_P(RibbonSystemButton);
    if (p.toolButtonStyle() != Qt::ToolButtonFollowStyle)
        return;
    if (RibbonBar* ribbon = qobject_cast<RibbonBar*>(p.parentWidget()))
    {
        RibbonBarPrivate* privateRibbon = RibbonBarPrivate::_get(ribbon);
        if (privateRibbon->m_ribbonTitleBarWidget)
            privateRibbon->m_ribbonTitleBarWidget->repaint(p.rect());
        p.repaint();
    }
}

/* RibbonSystemMenuButton */
RibbonSystemMenuButton::RibbonSystemMenuButton(QWidget* parent)
    : QToolButton(parent)
{
}

RibbonSystemMenuButton::~RibbonSystemMenuButton()
{
}

/*! \reimp */
bool RibbonSystemMenuButton::event(QEvent* event)
{
    if (event->type() == QEvent::ToolTip)
        event->setAccepted(false);
    return QToolButton::event(event);
}

/*! \reimp */
void RibbonSystemMenuButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    {
        QPainter p(this);
        QStyleOptionToolButton opt;
        initStyleOption(&opt);
        opt.iconSize = opt.icon.actualSize(QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));
        style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonPopupBarButton, &opt, &p, this);
    } //QToolButton::paintEvent() will create the second painter, so we need to destroy the first painter.
    QToolButton::paintEvent(event);
}


/* RibbonSystemMenuPrivate */
RibbonSystemMenuPrivate::RibbonSystemMenuPrivate()
    : m_ribbonItemHeight(systemPopupBorderTop)
{
}

void RibbonSystemMenuPrivate::initMargins()
{
    QTN_P(RibbonSystemMenu);
    HintReturnSysFrameMenuStyleOption marginsReturn(QMargins(systemPopupBorderLeft, m_ribbonItemHeight, systemPopupBorderRight, systemPopupBorderBottom));
    p.style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonSysFrameMenu, Q_NULL, Q_NULL, &marginsReturn);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    marginsReturn.margins += QMargins(0, 1, 0, 1);
#else
    marginsReturn.margins = QMargins(marginsReturn.margins.left(), marginsReturn.margins.top() + 1,
        marginsReturn.margins.right(), marginsReturn.margins.bottom() + 1);
#endif
    m_margins = marginsReturn.margins;
}


/*!
\class RibbonSystemMenu
\inmodule QtitanRibbon
\brief Implements the system menu for ribbon bar. 
Inherited from QMenu, but has a number of additional methods for adding items as a follow ms office specification.
*/

/*!
Constructs RibbonSystemMenu object with the given \a parent.
*/
RibbonSystemMenu::RibbonSystemMenu(QWidget* parent)
    : PopupMenu(*new RibbonSystemMenuPrivate, parent)
{
    QTN_D(RibbonSystemMenu);
    if (RibbonBar* ribbonBar = qobject_cast<RibbonBar*>(parentWidget()))
        d.m_ribbonItemHeight = RibbonBarPrivate::_get(ribbonBar)->rowItemHeight();
    d.initMargins();
}

/*!
Destructor of the RibbonSystemMenu object.
*/
RibbonSystemMenu::~RibbonSystemMenu()
{
}

/*!
Adds the button to the bottom of the menu. \a text - the text on the button. Returns a pointer to the QAction, associated with the button.
*/
QAction* RibbonSystemMenu::addPopupBarAction(const QString& text)
{
    QTN_D(RibbonSystemMenu);
    RibbonSystemMenuButton* systemPopupBarButton = new RibbonSystemMenuButton(this);
    systemPopupBarButton->setAutoRaise(true);
    systemPopupBarButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

    d.m_systemButtonList.append(systemPopupBarButton);
    systemPopupBarButton->setText(text);

    QAction* pAction = new QAction(text, systemPopupBarButton);
    systemPopupBarButton->setDefaultAction(pAction);
    return pAction;
}

/*!
Adds the button to the bottom of the menu with the given \a style.
Parameter \a action - is a pointer to the QAction object used to initialize the tips (ToolTip), the text in the Status Bar (StatusTip) and icon.
*/
void RibbonSystemMenu::addPopupBarAction(QAction* action, Qt::ToolButtonStyle style)
{
    QTN_D(RibbonSystemMenu);
    if (style == Qt::ToolButtonTextUnderIcon)
    {
        Q_ASSERT_X(false, Q_FUNC_INFO, "Invalid style button");
        return;
    }

    RibbonSystemMenuButton* systemPopupBarButton = new RibbonSystemMenuButton(this);
    systemPopupBarButton->setAutoRaise(true);
    systemPopupBarButton->setToolButtonStyle(style);

    d.m_systemButtonList.append(systemPopupBarButton);
    systemPopupBarButton->setText(action->text());
    systemPopupBarButton->setDefaultAction(action);
}

/*!
Adds the page to the right side of the system menu for a list of recently used files.
Parameter \a caption - is a title of the recent file list page. Returns a pointer to RibbonPageSystemRecentFileList for later use.
*/
RibbonPageSystemRecentFileList* RibbonSystemMenu::addPageRecentFile(const QString& caption)
{
    RibbonPageSystemRecentFileList* recentFileList = new RibbonPageSystemRecentFileList(caption);
    setPreviewWidget(recentFileList);
    return recentFileList;
}

/*!
Adds the system popup menu to the menu with the given \caption. Parameter \a defaultAction is a default action for the popup 
that can be additionaly configured with \a splitAction parameter. Returns a pointer to RibbonPageSystemPopup for later use.
*/
RibbonPageSystemPopup* RibbonSystemMenu::addPageSystemPopup(const QString& caption, QAction* defaultAction, bool splitAction)
{
    QTN_D(RibbonSystemMenu);
    RibbonPageSystemPopup* systemPopup = new RibbonPageSystemPopup(caption, this);
    systemPopup->setDefaultAction(defaultAction);
    if (splitAction)
        defaultAction->setProperty(_qtn_SplitActionPopup, true);
    defaultAction->setMenu(systemPopup);
    d.m_pageList.append(systemPopup);
    return systemPopup;
}

/*! \reimp */
QSize RibbonSystemMenu::sizeHint() const
{
    QTN_D(const RibbonSystemMenu);
    QSize sz = PopupMenu::sizeHint();
    int maxWidget = 0;
    for (QList<QWidget*>::const_iterator it = d.m_pageList.begin(); it != d.m_pageList.end(); ++it)
        maxWidget = qMax(maxWidget, (*it)->sizeHint().width());

    int previewWidth = 0;
    if (d.m_preview != Q_NULL)
        previewWidth = d.m_preview->sizeHint().width();

    QStyleOption opt(0); opt.init(this);
    const int margin = 0;
    if (previewWidth < maxWidget)
        sz.setWidth(sz.width() + (maxWidget - previewWidth) + margin);
    else
        sz.rwidth() += margin;
    return sz;
}

/*! \internal */
void RibbonSystemMenu::initFrameMenuStyleOption(RibbonFrameMenuStyleOption* option) const
{
    QTN_D(const RibbonSystemMenu);
    QSize szMenu = PopupMenu::sizeHint();
    option->initFrom(this);
    option->isAdditionalPages = d.m_pageList.size() > 0 || previewWidget() != Q_NULL;

    int width = d.m_scrollMenuBar->size().width();
    HintReturnSysFrameMenuStyleOption marginsReturn(QMargins(systemPopupBorderLeft, d.m_ribbonItemHeight, systemPopupBorderRight, systemPopupBorderBottom));
    style()->styleHint(static_cast<QStyle::StyleHint>(CommonStyle::SH_RibbonSysFrameMenu), Q_NULL, Q_NULL, &marginsReturn);
    option->margins = marginsReturn.margins;

    option->actionsWidth = width;
    option->actionsHeight = szMenu.height();
}

/*! \reimp */
void RibbonSystemMenu::showEvent(QShowEvent* event)
{
    Q_UNUSED(event);
    RibbonBar* ribbonBar = qobject_cast<RibbonBar*>(parentWidget());
    if (ribbonBar == Q_NULL)
        return;
    if (ribbonBar != Q_NULL)
    {
        RibbonBarPrivate* ribbinPrivate = RibbonBarPrivate::_get(ribbonBar);
        QRect rectMenu = geometry();
        QRect rectWidget = ribbinPrivate->m_ribbonTabBar->rect();
        QPoint posButton = ribbinPrivate->m_ribbonTabBar->mapToGlobal(rectWidget.topLeft());
        
        QRect screen = qtn_availableGeometry(this);
        const QSize menuSizeHint(sizeHint());
        if (screen.bottom() < menuSizeHint.height() + posButton.y())
        {
            if (QWidget* parentWidget = ribbonBar->parentWidget())
            {
                QRect frameRect = parentWidget->frameGeometry();
                QRect rect = parentWidget->geometry();
                if (posButton.y() - screen.top() < menuSizeHint.height())
                    posButton.setY(screen.top());
                else
                    posButton.setY(rect.y() - (menuSizeHint.height() + qAbs(frameRect.top() - rect.top())));
            }
        }
        move(QPoint(rectMenu.x(), posButton.y()));
    }
    else
    {
        QToolButton* button = ribbonBar ? ribbonBar->systemButton() : Q_NULL;
        if (button != Q_NULL)
        {
            QRect rectMenu = geometry();
            QPoint posButton = button->mapToGlobal(button->rect().topLeft());
            move(QPoint(rectMenu.x(), posButton.y()));
        }
    }
}

/*! \reimp */
void RibbonSystemMenu::mousePressEvent(QMouseEvent* event)
{
    if (RibbonBar* parent = qobject_cast<RibbonBar*>(parentWidget()))
    {
        if (QToolButton* button = parent->systemButton())
        {
            QRect rectButton = button->rect();
            if (rectButton.isValid())
            {
                QPoint posButton = button->mapToGlobal(rectButton.topLeft());
                if (QRect(posButton, button->size()).contains(event->globalPos()))
                {
                    QMouseEvent ev(QEvent::MouseButtonPress, QPoint(-1, -1), event->button(), event->buttons(), event->modifiers());
                    QMenu::mousePressEvent(&ev);
                    return;
                }
            }
        }
    }
    QMenu::mousePressEvent(event);
}

/*! \reimp */
void RibbonSystemMenu::mouseReleaseEvent(QMouseEvent* event)
{
    QAction* action = actionAt(event->pos());
    if (action && action->property(_qtn_SplitActionPopup).toBool())
    {
        QRect rect = actionGeometry(action);
        rect.adjust(0, 0, -splitActionPopupWidth, 0);
        if (rect.contains(event->pos()))
        {
            PopupMenu::mousePressEvent(event);
            action->trigger();
        }
    }
    else
        PopupMenu::mouseReleaseEvent(event);
}

/*! \reimp */
void RibbonSystemMenu::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this);
    RibbonFrameMenuStyleOption menuOpt;
    initFrameMenuStyleOption(&menuOpt);
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonSysFrameMenu, &menuOpt, &p, this);

    if (RibbonBar* parent = qobject_cast<RibbonBar*>(parentWidget()))
    {
        if (RibbonSystemButton* button = parent->systemButton())
        {
            if (button->geometry().top() != this->geometry().top())
            {
                QStyleOptionToolButton opt;
                button->initStyleOption(&opt);

                Qt::ToolButtonStyle styleButton = button->toolButtonStyle();
                opt.toolButtonStyle = styleButton;

                QRect rc = opt.rect;
                QPoint posButton = button->mapToGlobal(rc.topLeft());
                posButton = mapFromGlobal(posButton);
                rc.moveTo(posButton);
                opt.rect = rc;
                if (!opt.icon.isNull())
                {
                    QPixmap pm = opt.icon.pixmap(opt.iconSize);
                    opt.iconSize = pm.size();
                }
                style()->drawComplexControl((QStyle::ComplexControl)CommonStyle::CC_RibbonFileButton, &opt, &p, this);
            }
        }
    }
}

/*! \reimp */
void RibbonSystemMenu::keyPressEvent(QKeyEvent* event)
{
    PopupMenu::keyPressEvent(event);

    if (!event->isAccepted())
    {
        QTN_D(RibbonSystemMenu);
        for (int i = 0; i < d.m_pageList.count(); i++)
        {
            if (RibbonPageSystemRecentFileList* page = qobject_cast<RibbonPageSystemRecentFileList*>(d.m_pageList.at(i)))
            {
                page->keyPressEvent(event);
                break;
            }
        }
    }
}

/*! \reimp */
void RibbonSystemMenu::resizeEvent(QResizeEvent* event)
{
    QTN_D(RibbonSystemMenu);
    PopupMenu::resizeEvent(event);

    HintReturnSysFrameMenuStyleOption marginsReturn(QMargins(systemPopupBorderLeft, d.m_ribbonItemHeight, systemPopupBorderRight, systemPopupBorderBottom));
    style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonSysFrameMenu, Q_NULL, Q_NULL, &marginsReturn);

    QSize sz(rect().size());
    int right = sz.width() - marginsReturn.margins.right() - systemPopupBorderRight;
    for (QList<RibbonSystemMenuButton*>::iterator it = d.m_systemButtonList.begin(); it != d.m_systemButtonList.end(); ++it)
    {
        RibbonSystemMenuButton* barButton = (*it);
        QSize szControl = barButton->sizeHint();
        QRect rc( QPoint(right - szControl.width(), sz.height() - marginsReturn.margins.bottom() + 2), QPoint(right, sz.height() - 3));
        barButton->move( rc.left(), rc.top() );
        barButton->resize( rc.width(), rc.height() );
        right -= szControl.width() + 6;
    }

    int maxWidget = 0;
    for (QList<QWidget*>::iterator it = d.m_pageList.begin(); it != d.m_pageList.end(); ++it)
        maxWidget = qMax(maxWidget, (*it)->sizeHint().width());

    if (QWidget* preview = previewWidget())
        maxWidget = qMax(maxWidget, preview->sizeHint().width());

    for (QList<QWidget*>::iterator it = d.m_pageList.begin(); it != d.m_pageList.end(); ++it)
        (*it)->setMinimumWidth(maxWidget);

    if (d.m_preview != Q_NULL)
        d.m_preview->resize(maxWidget, d.m_preview->height());
}

/*! \reimp */
void RibbonSystemMenu::changeEvent(QEvent* event)
{
    QTN_D(RibbonSystemMenu);
    if (event->type() == QEvent::StyleChange)
        d.initMargins();
    PopupMenu::changeEvent(event);
}


/* RibbonPageSystemRecentFileListPrivate */
RibbonPageSystemRecentFileListPrivate::RibbonPageSystemRecentFileListPrivate()
{
    m_itemsDirty = true;
    m_hasCheckableItems = false;
    m_currentAction = Q_NULL;
}

QAction* RibbonPageSystemRecentFileListPrivate::actionAt(const QPoint& pt) const
{
    QTN_P(const RibbonPageSystemRecentFileList);

    if (!p.rect().contains(pt)) //sanity check
        return 0;

    for(int i = 0; i < m_actionRects.count(); i++)
    {
        if (m_actionRects.at(i).contains(pt))
            return m_recentFileActs.at(i);
    }
    return 0;
}

QRect RibbonPageSystemRecentFileListPrivate::actionRect(QAction* act) const
{
    int index = m_recentFileActs.indexOf(act);
    if (index == -1)
        return QRect();

    updateActionRects();

    //we found the action
    return m_actionRects.at(index);
}

void RibbonPageSystemRecentFileListPrivate::setCurrentAction(QAction* currentAction)
{
    QTN_P(RibbonPageSystemRecentFileList);

    if (m_currentAction && m_currentAction != currentAction)
        p.update(actionRect(m_currentAction));

    if (m_currentAction == currentAction)
        return;
    m_currentAction = currentAction;

    p.update(actionRect(m_currentAction));
}

void RibbonPageSystemRecentFileListPrivate::activateAction(QAction* action, QAction::ActionEvent action_e, bool self)
{
    Q_UNUSED(self);
    Q_UNUSED(action_e);

    QTN_P(RibbonPageSystemRecentFileList);
    p.parentWidget()->hide();

//    action->activate(action_e);
    emit p.openRecentFile(action->data().toString());
}

void RibbonPageSystemRecentFileListPrivate::updateActionRects() const
{
    QTN_P(const RibbonPageSystemRecentFileList);
    if (!m_itemsDirty)
        return;

    p.ensurePolished();

    m_actionRects.resize(m_recentFileActs.count());
    m_actionRects.fill(QRect());

    // let's try to get the last visible action
    int lastVisibleAction = m_recentFileActs.count() - 1;
    for(;lastVisibleAction >= 0; --lastVisibleAction) 
    {
        const QAction *action = m_recentFileActs.at(lastVisibleAction);
        if (action->isVisible())
            break;
    }

    QStyle* style = p.style();
    QStyleOption opt;
    opt.init(&p);

    const int hmargin = style->pixelMetric(QStyle::PM_MenuHMargin, &opt, &p),
        vmargin = style->pixelMetric(QStyle::PM_MenuVMargin, &opt, &p);

    const int fw = style->pixelMetric(QStyle::PM_MenuPanelWidth, &opt, &p);
    QRect rcCaption = style->subElementRect((QStyle::SubElement)CommonStyle::SE_RibbonSysHeaderLabelPopupList, &opt, &p);
    int max_column_width = rcCaption.width() - vmargin - fw;
    int y = rcCaption.bottom() + 4;

    // calculate size
    QFontMetrics qfm = p.fontMetrics();
    for(int i = 0; i <= lastVisibleAction; i++) 
    {
        QAction* action = m_recentFileActs.at(i);

        if (!action->isVisible())
            continue; // we continue, this action will get an empty QRect

        // let the style modify the above size..
        QStyleOptionMenuItem opt;
        initStyleOption(&opt, action);
        const QFontMetrics& fm = opt.fontMetrics;

        QSize sz;
        QString s = action->text();
        sz.setWidth(fm.boundingRect(QRect(), Qt::TextSingleLine | Qt::TextShowMnemonic, s).width());
        sz.setHeight(qMax(fm.height(), qfm.height()));
        sz = style->sizeFromContents(QStyle::CT_MenuItem, &opt, sz, &p);
        //update the item
        if (!sz.isEmpty()) 
            m_actionRects[i] = QRect(0, 0, sz.width(), sz.height());
    }

    int x = hmargin + fw;
    for(int i = 0; i < m_recentFileActs.count(); i++) 
    {
        QRect& rect = m_actionRects[i];
        if (rect.isNull())
            continue;

        rect.translate(x, y); // move
        rect.setWidth(max_column_width); // uniform width

        y += rect.height();
    }
    
    ((RibbonPageSystemRecentFileListPrivate*)this)->m_itemsDirty = false;
}

void RibbonPageSystemRecentFileListPrivate::initStyleOption(QStyleOptionMenuItem* option, const QAction* action) const
{
    QTN_P(const RibbonPageSystemRecentFileList);
    if (option == Q_NULL || action == Q_NULL)
        return;
    option->initFrom(&p);
    option->palette = p.palette();
    option->state = QStyle::State_None;

    if (p.isEnabled() && action->isEnabled())
        option->state |= QStyle::State_Enabled;
    else
        option->palette.setCurrentColorGroup(QPalette::Disabled);

    option->font = action->font().resolve(p.font());
    option->fontMetrics = QFontMetrics(option->font);

    if (m_currentAction && m_currentAction == action) 
        option->state |= QStyle::State_Selected | (m_mouseDown ? QStyle::State_Sunken : QStyle::State_None);

    option->menuHasCheckableItems = m_hasCheckableItems;
    if (!action->isCheckable()) 
    {
        option->checkType = QStyleOptionMenuItem::NotCheckable;
    } 
    else 
    {
        option->checkType = (action->actionGroup() && action->actionGroup()->isExclusive())
            ? QStyleOptionMenuItem::Exclusive : QStyleOptionMenuItem::NonExclusive;
        option->checked = action->isChecked();
    }

    option->menuItemType = QStyleOptionMenuItem::Normal;
    if (action->isIconVisibleInMenu())
        option->icon = action->icon();

    QString textAndAccel = action->text();
    if (textAndAccel.indexOf(QLatin1Char('\t')) == -1) 
    {
        QKeySequence seq = action->shortcut();
        if (!seq.isEmpty())
            textAndAccel += QLatin1Char('\t') + seq.toString();
    }

    option->text = textAndAccel;
    option->tabWidth = 0;
    option->maxIconWidth = 0;
    option->menuRect = p.rect();
}

/*!
\class RibbonPageSystemRecentFileList
\inmodule QtitanRibbon
\brief Class RibbonPageSystemRecentFileList Used to display a list of recently used files in the Ribbon UI system menu.
*/

/*!
\fn void RibbonPageSystemRecentFileList::openRecentFile(const QString& file);
The signal will be issued if the \a file has been choosed in the menu.
*/

/*!
Constructs RibbonPageSystemRecentFileList object with the given \a caption.
*/
RibbonPageSystemRecentFileList::RibbonPageSystemRecentFileList(const QString& caption)
{
    QTN_INIT_PRIVATE(RibbonPageSystemRecentFileList);
    setWindowTitle(caption);
    if (caption.isEmpty())
        setWindowTitle(RibbonBar::tr_compatible(QtnRibbonRecentDocumentsString));
    setAttribute(Qt::WA_MouseTracking, true);
}

/*!
Destructor of the RibbonPageSystemRecentFileList object.
*/
RibbonPageSystemRecentFileList::~RibbonPageSystemRecentFileList()
{
    QTN_FINI_PRIVATE();
}

/*! \reimp */
QSize RibbonPageSystemRecentFileList::sizeHint() const
{
    QSize s;
    RibbonSystemMenu* systemMenu = qobject_cast<RibbonSystemMenu*>(parentWidget());
    Q_ASSERT(systemMenu != Q_NULL);
    QList<QAction*> actionList = systemMenu->actions();
    for (QList<QAction*>::iterator it = actionList.begin(); it != actionList.end(); ++it)
    {
        QAction* action = (*it);
        QRect rect = systemMenu->actionGeometry(action);
        if (rect.isNull())
            continue;
        s.setHeight(rect.y() + rect.height());
    }
    s.setWidth(qMax(s.width(), int(CommonStylePrivate::dpiScaled(300., this))));
    return s;
}

/*!
Sets the \a size of the file list. The list size can not exceed 9 files.
*/
void RibbonPageSystemRecentFileList::setSize(int size)
{
    QTN_D(RibbonPageSystemRecentFileList);

    if (size < 0 || size > 9)
    {
        Q_ASSERT_X(false, Q_FUNC_INFO, "Number of files could not be more than 9.");
        return; 
    }
    // clean actions
    for (int i = 0, count = d.m_recentFileActs.count(); count > i; i++)
    {
        QAction* act = d.m_recentFileActs[i];
        removeAction(act);
        delete act;
    }
    d.m_recentFileActs.clear();

    for (int i = 0; i < size; ++i) 
    {
        QAction* recentFileAct = new QAction(this);
        recentFileAct->setVisible(false);
        addAction(recentFileAct);
        d.m_recentFileActs.append(recentFileAct);
//        connect(recentFileAct, SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }
}

/*!
Returns the size of the file list.
*/
int RibbonPageSystemRecentFileList::getSize() const
{
    QTN_D(const RibbonPageSystemRecentFileList);
    return d.m_recentFileActs.size();
}

/*!
Returns a pointer to the current QAction, which is under mouse and highlighted.
*/
QAction* RibbonPageSystemRecentFileList::getCurrentAction() const
{
    QTN_D(const RibbonPageSystemRecentFileList);
    return d.m_currentAction;
}

static QString strippedName(const QString& fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

/*!
Slot is intended to update the file list. Parameter \a files holds the file's names.
*/
void RibbonPageSystemRecentFileList::updateRecentFileActions(const QStringList& files)
{
    QTN_D(RibbonPageSystemRecentFileList);

    if (d.m_recentFileActs.size() == 0)
    {
        Q_ASSERT_X(false, Q_FUNC_INFO, "Number of files not defined.");
        return;
    }

    int numRecentFiles = qMin(files.size(), d.m_recentFileActs.size());
    for (int i = 0; i < numRecentFiles; ++i) 
    {
        QAction* recentFileAct = d.m_recentFileActs.at(i);
        QString text = QString(QStringLiteral("&%1")).arg(i + 1);
        text += QStringLiteral("%1 %2").arg(QLatin1Char(' ')).arg(strippedName(files[i]));;
        recentFileAct->setText(text);
        recentFileAct->setData(files[i]);
        recentFileAct->setVisible(true);
    }
    for (int j = numRecentFiles; j < d.m_recentFileActs.size(); ++j)
        d.m_recentFileActs[j]->setVisible(false);

    d.m_itemsDirty = true;
    d.updateActionRects();
}

/*! \reimp */
void RibbonPageSystemRecentFileList::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this);
    QStyleOption opt;
    opt.init(this);
#if 0
    p.fillRect(opt.rect, Qt::red);
#endif
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonSysFramePagePopupList, &opt, &p, this);
    drawEvent(event, &p);
    p.drawRect(opt.rect.adjusted(0, 0, -1, -1));
}

void RibbonPageSystemRecentFileList::drawEvent(QPaintEvent* event, QPainter* p)
{
    QTN_D(RibbonPageSystemRecentFileList);
    QRegion emptyArea = QRegion(rect());
    //draw the items that need updating..
    for (int i = 0; i < d.m_recentFileActs.count(); ++i) 
    {
        QAction* action = d.m_recentFileActs.at(i);
        QRect adjustedActionRect = d.m_actionRects.at(i);
        if (!event->rect().intersects(adjustedActionRect)/* || d->widgetItems.value(action)*/)
            continue;

        //set the clip region to be extra safe (and adjust for the scrollers)
        QRegion adjustedActionReg(adjustedActionRect);
        emptyArea -= adjustedActionReg;
        p->setClipRegion(adjustedActionReg);

        QStyleOptionMenuItem opt;
        d.initStyleOption(&opt, action);
        opt.rect = adjustedActionRect;
        style()->drawControl((QStyle::ControlElement)CommonStyle::CE_RibbonSysRecentFileItem, &opt, p, this);
    }
}

/*! \reimp */
void RibbonPageSystemRecentFileList::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
}

/*! \reimp */
void RibbonPageSystemRecentFileList::mouseMoveEvent(QMouseEvent* event)
{
    QTN_D(RibbonPageSystemRecentFileList);

    if (!isVisible())
        return;
    d.setCurrentAction(d.actionAt(event->pos()));
}

/*! \reimp */
void RibbonPageSystemRecentFileList::mouseReleaseEvent(QMouseEvent* event)
{
    QTN_D(RibbonPageSystemRecentFileList);

    QAction* action = d.actionAt(event->pos());
    if (action && action == d.m_currentAction) 
    {
#if defined(Q_WS_WIN)
        //On Windows only context menus can be activated with the right button
        if (event->button() == Qt::LeftButton)
#endif
            d.activateAction(action, QAction::Trigger);
    }
    else
        QWidget::mouseReleaseEvent(event);
}

/*! \reimp */
void RibbonPageSystemRecentFileList::enterEvent(QEvent* event)
{
    QWidget::enterEvent(event);

    QEvent leaveEvent(QEvent::Leave);
    QApplication::sendEvent(parentWidget(), &leaveEvent);

    setFocus();
}

/*! \reimp */
void RibbonPageSystemRecentFileList::leaveEvent(QEvent* event)
{
    Q_UNUSED(event);

    QTN_D(RibbonPageSystemRecentFileList);
    d.setCurrentAction(Q_NULL);
    parentWidget()->setFocus();
}

/*! \reimp */
void RibbonPageSystemRecentFileList::keyPressEvent(QKeyEvent* event)
{
    QTN_D(RibbonPageSystemRecentFileList);

    int key = event->key();
    bool key_consumed = false;
    switch(key) 
    {
        case Qt::Key_Up:
        case Qt::Key_Down: 
            {
                key_consumed = true;
                QAction* nextAction = Q_NULL;
                if (!d.m_currentAction) 
                {
                    if(key == Qt::Key_Down) 
                    {
                        for(int i = 0; i < d.m_recentFileActs.count(); ++i) 
                        {
                            QAction* act = d.m_recentFileActs.at(i);
                            if (d.m_actionRects.at(i).isNull())
                                continue;
                            if ( (style()->styleHint(QStyle::SH_Menu_AllowActiveAndDisabled, 0, this) || act->isEnabled())) 
                            {
                                nextAction = act;
                                break;
                            }
                        }
                    } 
                    else 
                    {
                        for (int i = d.m_recentFileActs.count()-1; i >= 0; --i) 
                        {
                            QAction* act = d.m_recentFileActs.at(i);
                            if (d.m_actionRects.at(i).isNull())
                                continue;
                            if ( (style()->styleHint(QStyle::SH_Menu_AllowActiveAndDisabled, 0, this) || act->isEnabled())) 
                            {
                                nextAction = act;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    for(int i = 0, y = 0; !nextAction && i < d.m_recentFileActs.count(); i++) 
                    {
                        QAction *act = d.m_recentFileActs.at(i);
                        if (act == d.m_currentAction) 
                        {
                            if (key == Qt::Key_Up) 
                            {
                                for(int next_i = i-1; true; next_i--) 
                                {
                                    if (next_i == -1) 
                                    {
                                        if(!style()->styleHint(QStyle::SH_Menu_SelectionWrap, 0, this))
                                            break;
                                        next_i = d.m_actionRects.count()-1;
                                    }
                                    QAction *next = d.m_recentFileActs.at(next_i);
                                    if (next == d.m_currentAction)
                                        break;
                                    if (d.m_actionRects.at(next_i).isNull())
                                        continue;
                                    if (next->isSeparator() ||
                                        (!next->isEnabled() &&
                                        !style()->styleHint(QStyle::SH_Menu_AllowActiveAndDisabled, 0, this)))
                                        continue;
                                    nextAction = next;
                                    break;
                                }
                            } 
                            else 
                            {
                                y += d.m_actionRects.at(i).height();
                                for(int next_i = i+1; true; next_i++) 
                                {
                                    if (next_i == d.m_recentFileActs.count()) 
                                    {
                                        if(!style()->styleHint(QStyle::SH_Menu_SelectionWrap, 0, this))
                                            break;
                                        next_i = 0;
                                    }
                                    QAction* next = d.m_recentFileActs.at(next_i);
                                    if (next == d.m_currentAction)
                                        break;
                                    if (d.m_actionRects.at(next_i).isNull())
                                        continue;
                                    if (!next->isEnabled() && !style()->styleHint(QStyle::SH_Menu_AllowActiveAndDisabled, 0, this))
                                        continue;
                                    nextAction = next;
                                    break;
                                }
                            }
                            break;
                        }
                        y += d.m_actionRects.at(i).height();
                    }
                }

                if (nextAction) 
                    d.setCurrentAction(nextAction);
            }
            break;
        case Qt::Key_Return:
        case Qt::Key_Enter: 
            {
                if (!d.m_currentAction) 
                {
                    key_consumed = true;
                    break;
                }
                d.activateAction(d.m_currentAction, QAction::Trigger);
                key_consumed = true;
            }
            break;
        default:
            key_consumed = false;
            break;
    }

    if (!key_consumed)
    {
        if ((!event->modifiers() || event->modifiers() == Qt::AltModifier || event->modifiers() == Qt::ShiftModifier) && event->text().length()==1 ) 
        {
            bool activateAction = false;
            QAction *nextAction = 0;

            int clashCount = 0;
            QAction* first = 0, *currentSelected = 0, *firstAfterCurrent = 0;
            QChar c = event->text().at(0).toUpper();
            for(int i = 0; i < d.m_recentFileActs.size(); ++i) 
            {
                if (d.m_actionRects.at(i).isNull())
                    continue;
                QAction *act = d.m_recentFileActs.at(i);
                QKeySequence sequence = QKeySequence::mnemonic(act->text());
                int key = sequence[0] & 0xffff;
                if (key == c.unicode()) 
                {
                    clashCount++;
                    if (!first)
                        first = act;
                    if (act == d.m_currentAction)
                        currentSelected = act;
                    else if (!firstAfterCurrent && currentSelected)
                        firstAfterCurrent = act;
                }
            }
            if (clashCount == 1)
                activateAction = true;

            if (clashCount >= 1) 
            {
                if (clashCount == 1 || !currentSelected || !firstAfterCurrent)
                    nextAction = first;
                else
                    nextAction = firstAfterCurrent;
            }

            if (nextAction) 
            {
                key_consumed = true;
                if (!nextAction->menu() && activateAction)
                    d.activateAction(nextAction, QAction::Trigger);
            }
        }

#ifdef Q_OS_WIN32
        if (key_consumed && (event->key() == Qt::Key_Control || event->key() == Qt::Key_Shift || event->key() == Qt::Key_Meta))
            QApplication::beep();
#endif // Q_OS_WIN32
    }

    if (key_consumed)
        event->accept();
    else
        event->ignore();
}

/*! \reimp */
void RibbonPageSystemRecentFileList::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    QTN_D(RibbonPageSystemRecentFileList);
    d.m_itemsDirty = true;
    d.updateActionRects();
}

QSize RibbonPageSystemPopupPrivate::captionSize() const
{
    QTN_P(const RibbonPageSystemPopup);
    QStyleOptionMenuItem menuOpt;
    menuOpt.initFrom(&p);
    QRect rcCaption = p.style()->subElementRect(static_cast<QStyle::SubElement>(CommonStyle::SE_RibbonSysHeaderLabelPopupList), &menuOpt, &p);
    const int hMarginCaption = p.style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonHMarginCaptionSysMenu), &menuOpt, &p);
    QFont fontCaption = p.font();
    fontCaption.setBold(true);
    QFontMetrics fm(fontCaption);
    QRect rect = fm.boundingRect(m_caption);
    QSize sz = rect.size();
    sz.rwidth() += hMarginCaption * 2;
    sz.setHeight(qMax(sz.height(), rcCaption.height()));

    QFontMetrics fmm(p.font());
    int height = fm.boundingRect(QStringLiteral("X")).height() * 2;

    int maxWidth = sz.width();
    QSize szAction = sz;
    QList<QAction*> actionList = p.actions();
    for (QList<QAction*>::iterator it = actionList.begin(); it != actionList.end(); ++it)
    {
        QAction* action = (*it);
        int alignment = Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap | Qt::TextHideMnemonic;
        QString str = action->toolTip();
        szAction.setHeight(height);
        szAction.setWidth(fmm.boundingRect(str).width() - height * 3);
        QRect rc = fmm.boundingRect(QRect(QPoint(0, 0), szAction), alignment, str);
        maxWidth = qMax(maxWidth, rc.width());
    }
    sz.setWidth(maxWidth);

    return sz;
}

void RibbonPageSystemPopupPrivate::initGeometry()
{
    QTN_P(RibbonPageSystemPopup);
    if (RibbonSystemMenu* parent = qobject_cast<RibbonSystemMenu*>(p.parentWidget()))
    {
        QSize szParent = parent->QMenu::sizeHint();
        szParent.setHeight(parent->height());
        HintReturnSysFrameMenuStyleOption marginsReturn(QMargins(systemPopupBorderLeft, parent->qtn_d().m_ribbonItemHeight, systemPopupBorderRight, systemPopupBorderBottom));
        p.style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonSysFrameMenu, Q_NULL, Q_NULL, &marginsReturn);
        QPoint pnt(szParent.width() - marginsReturn.margins.left(), marginsReturn.margins.top());
        QRect rect(parent->mapToGlobal(pnt), QSize(p.sizeHint().width() + marginsReturn.margins.right(), szParent.height() - marginsReturn.margins.top() - marginsReturn.margins.bottom()));
        p.setGeometry(rect.adjusted(0, 1, 0, -1));
    }
}


/* RibbonPageSystemPopup */
RibbonPageSystemPopup::RibbonPageSystemPopup(const QString& caption, QWidget* parent)
    : PopupMenu(*new RibbonPageSystemPopupPrivate, parent)
{
    QTN_D(RibbonPageSystemPopup);
    d.m_caption = caption;
    QSize sz = d.captionSize();
    QMargins margins(1, sz.height(), -2, 0);
    d.m_margins = margins;
}

RibbonPageSystemPopup::~RibbonPageSystemPopup()
{
}

/*! \reimp */
QSize RibbonPageSystemPopup::sizeHint() const
{
    QTN_D(const RibbonPageSystemPopup);
    QSize sz = PopupMenu::sizeHint();
    sz.setWidth(qMax(sz.width(), d.captionSize().width()));
    return sz;
}

/*! \reimp */
bool RibbonPageSystemPopup::event(QEvent* event)
{
    QTN_D(RibbonPageSystemPopup);
    bool result = PopupMenu::event(event);
    if (event->type() == QEvent::Show || event->type() == QEvent::Move)
        d.initGeometry();
    return  result;
}

/*! \reimp */
void RibbonPageSystemPopup::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QTN_D(RibbonPageSystemPopup);
    QPainter p(this);
    QStyleOptionMenuItem menuOpt;
    menuOpt.initFrom(this);
    menuOpt.state = QStyle::State_None;
    menuOpt.checkType = QStyleOptionMenuItem::NotCheckable;
    menuOpt.maxIconWidth = 0;
    menuOpt.tabWidth = 0;
    menuOpt.text = d.m_caption;
    menuOpt.menuRect = QRect(QPoint(0, 0), QSize(menuOpt.rect.width(), d.captionSize().height()));
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonSysFramePagePopup, &menuOpt, &p, this);
}
