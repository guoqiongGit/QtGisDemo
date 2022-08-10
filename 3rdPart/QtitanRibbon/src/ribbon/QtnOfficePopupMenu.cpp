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
#include <QWidgetAction>
#include <QPainter>
#include <qevent.h>
#include <QLayout>

#include "QtnCommonStylePrivate.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnOfficePopupMenu.h"
#include "QtnRibbonGallery.h"
#include "QtnRibbonBarPrivate.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

//static const int popupMenuGripHeight = 12; // height of the MenuGrip

/*!
\property OfficePopupMenu::gripVisible
*/

QTITAN_BEGIN_NAMESPACE

class OfficePopupMenuPrivate : public QObject
{
public:
    QTN_DECLARE_PUBLIC(OfficePopupMenu)
public:
    explicit OfficePopupMenuPrivate();
public:
    void init();
    int calcMinimumHeight(bool without = false) const;
    QWidget* findWidget(const char* nameWidget) const;
    void updateSizeGallery();
    void setTransparentWidgetForMouseEvents(bool transparent);
    void setDragCursor();
    void unsetDragCursor();
public:
    QWidget* m_widgetPopup; 
    bool m_resizable;
    bool m_pressSizeGrip;
    bool m_showGrip;
    bool m_hasCursor;
    int m_offsetHeight;
    int m_minimumHeight;
    int m_minimumWidth;
    int m_lastWidth;
};

QTITAN_END_NAMESPACE

OfficePopupMenuPrivate::OfficePopupMenuPrivate()
    : m_widgetPopup(Q_NULL)
    , m_resizable(false)
    , m_pressSizeGrip(false)
    , m_showGrip(true)
    , m_hasCursor(false)
    , m_offsetHeight(0)
    , m_minimumHeight(-1)
    , m_minimumWidth(-1)
    , m_lastWidth(-1)
{
}

void OfficePopupMenuPrivate::init()
{
    QTN_P(OfficePopupMenu);
    p.setProperty(_qtn_PopupBar, true);
    p.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    p.setMouseTracking(true);
    p.setContentsMargins(QMargins(1, 1, 1, m_resizable ?
        p.style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonPopupMenuGripHeight), Q_NULL, &p) + 2 : 1));
}

int OfficePopupMenuPrivate::calcMinimumHeight(bool without) const
{
    QTN_P(const OfficePopupMenu);
    int height = p.style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonPopupMenuGripHeight), Q_NULL, &p);
    QList<QAction*> listActions = p.actions();
    for (int i = 0; i < listActions.count(); i++) 
    {
        if (QWidgetAction* widgetAction = qobject_cast<QWidgetAction*>(listActions.at(i)))
        {
            if (QWidget* w = widgetAction->defaultWidget())
            {
                if (!without)
                {
                    int minHeight = w->minimumSizeHint().height();
                    if (minHeight == -1)
                        minHeight = w->sizeHint().height();
                    height += minHeight;
                }
            }
        }
        else
            height += p.actionGeometry(listActions.at(i)).height();
    }
    return height;
}

QWidget* OfficePopupMenuPrivate::findWidget(const char* nameWidget) const
{
    QTN_P(const OfficePopupMenu);
    const QObjectList& listChildren = p.children();
    for (int i = 0; i < listChildren.size(); ++i) 
    {
        QWidget* w = qobject_cast<QWidget*>(listChildren.at(i));
        if (w && w->property(nameWidget).toBool() )
            return w;
    }
    return Q_NULL;
}

void OfficePopupMenuPrivate::setTransparentWidgetForMouseEvents(bool transparent)
{
    QTN_P(OfficePopupMenu);
    const QObjectList& listChildren = p.children();
    for (int i = 0; i < listChildren.size(); ++i)
    {
        if (QWidget* widget = qobject_cast<QWidget*>(listChildren.at(i)))
        {
            if (!widget->isWindow() && !widget->isHidden())
                widget->setAttribute(Qt::WA_TransparentForMouseEvents, transparent);
        }
    }
}

void OfficePopupMenuPrivate::setDragCursor()
{
    if (m_hasCursor)
        return;
    m_hasCursor = true;
    QApplication::setOverrideCursor(Qt::SizeFDiagCursor);
}

void OfficePopupMenuPrivate::unsetDragCursor()
{
    if (!m_hasCursor)
        return;
    QApplication::restoreOverrideCursor();
    m_hasCursor = false;
}

void OfficePopupMenuPrivate::updateSizeGallery()
{
    QTN_P(const OfficePopupMenu);
    const QObjectList& listChildren = p.children();
    for (QObjectList::const_iterator it = listChildren.begin(); it != listChildren.end(); ++it)
    {
        if (QWidget* w = qobject_cast<QWidget*>(*it))
        {
            if (!w->isWindow() && !w->isHidden() && w->property("isResizable").toBool())
            {
                QSize sizeWidget = w->geometry().size();
                sizeWidget.setWidth(sizeWidget.width());
                sizeWidget.setHeight(sizeWidget.height() - m_offsetHeight);
                w->resize(sizeWidget);
                if (RibbonGallery* gallery = qobject_cast<RibbonGallery*>(w))
                    gallery->updatelayout();
            }
        }
    }
}

/*!
class OfficePopupMenu
\brief Constructs the OfficePopupMenu object with the given \a parent.
*/ 
OfficePopupMenu::OfficePopupMenu(QWidget* parent)
    : QMenu(parent)
{
    QTN_INIT_PRIVATE(OfficePopupMenu);
    QTN_D(OfficePopupMenu);
    d.init();
}


/*!
\brief Destructor of the OfficePopupMenu object.
*/ 
OfficePopupMenu::~OfficePopupMenu()
{
    QTN_FINI_PRIVATE();
}

/*!
\brief Creates an instance of the OfficePopupMenu object with given \a parent.
*/ 
OfficePopupMenu* OfficePopupMenu::createPopupMenu(QWidget* parent)
{
    OfficePopupMenu* popupBar = new OfficePopupMenu(parent);
    return popupBar;
}

/*!
\brief Adds \a widget to the Office Popup Window and return an action associated with them.
*/ 
QAction* OfficePopupMenu::addWidget(QWidget* widget)
{
    QTN_D(OfficePopupMenu);
    QWidgetAction* action = new QWidgetAction(this);
    action->setDefaultWidget(widget);
    addAction(action);
    d.m_resizable = widget && widget->property("isResizable").toBool();
    setContentsMargins(QMargins(1, 1, 1, d.m_resizable ?
        style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonPopupMenuGripHeight), Q_NULL, this) + 2 : 1));
    return action;
}

/*!
\brief Sets visibility of the Popup Window Grip to \a visible.
*/ 
void OfficePopupMenu::setGripVisible(bool visible)
{
    QTN_D(OfficePopupMenu);
    d.m_showGrip = visible;
}

/*!
\brief Returns the visibility of the Popup Window Grip.
*/ 
bool OfficePopupMenu::isGripVisible() const
{
    QTN_D(const OfficePopupMenu);
    return d.m_showGrip;
}

/*! \internal */
void OfficePopupMenu::setWidgetBar(QWidget* widget)
{
    QTN_D(OfficePopupMenu);
    Q_ASSERT(widget != Q_NULL && d.m_widgetPopup == Q_NULL);
    d.m_widgetPopup = widget;
}

/*! \reimp */
bool OfficePopupMenu::event(QEvent* event)
{
    QTN_D(OfficePopupMenu);
    if (event->type() == QEvent::ChildAdded && d.m_resizable)
    {
        QSize sz = sizeHint();
        if (sz.isValid()) 
        {
            QSize minSz = minimumSize();
            if (minSz.height() > sz.height())
                setMinimumHeight(minSz.height() - (minSz.height() - sz.height()));
        }
    }

    bool ok = QMenu::event(event);

    if (event->type() == QEvent::Resize)
    {
        QList<QAction*> listActions = actions();
        for (int i = 0; i < listActions.count(); i++)
        {
            if (QWidgetAction* action = qobject_cast<QWidgetAction*>(listActions.at(i)))
            {
                QRect rect = actionGeometry(action);
                if (QWidget* wd = action->defaultWidget())
                    wd->resize(QSize(width() - 3, rect.height()));
            }
        }
    }
    return ok;
}

/*! \reimp */
void OfficePopupMenu::paintEvent(QPaintEvent* event)
{
    QTN_D(OfficePopupMenu);
    QMenu::paintEvent(event);
    if (d.m_resizable)
    {
        QPainter p(this);
        QStyleOptionSizeGrip opt;
        opt.init(this);
        opt.rect.adjust(1, 0, -1, -1);
        opt.rect.setTop(opt.rect.bottom() - style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonPopupMenuGripHeight), Q_NULL, this));
        style()->drawControl((QStyle::ControlElement)CommonStyle::CE_RibbonGripBar, &opt, &p, this);
    }
}

/*! \reimp */
void OfficePopupMenu::mousePressEvent(QMouseEvent* event)
{
    QTN_D(OfficePopupMenu);
    if (d.m_resizable)
    {
        if (event->buttons() == Qt::LeftButton) 
        {
            QRect rcResizeGripper(rect());
            rcResizeGripper.setTop(rcResizeGripper.bottom() - style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonPopupMenuGripHeight), Q_NULL, this));
            QRect rcResizeGripperAll = rcResizeGripper;
            rcResizeGripper.setLeft(rcResizeGripper.right() - rcResizeGripper.height());
            if (rcResizeGripper.contains(event->pos()))
            {
                d.setTransparentWidgetForMouseEvents(true);
                d.m_pressSizeGrip = true;
                d.m_offsetHeight = 0;
                return;
            }
            else if (rcResizeGripperAll.contains(event->pos()))
                return;
        }
    }
    QMenu::mousePressEvent(event);
}

/*! \reimp */
void OfficePopupMenu::mouseMoveEvent(QMouseEvent* event)
{
    QTN_D(OfficePopupMenu);
    if (d.m_resizable)
    {
        QRect rcResizeGripper(rect());
        rcResizeGripper.setTop(rcResizeGripper.bottom() - style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonPopupMenuGripHeight), Q_NULL, this));
        rcResizeGripper.setLeft(rcResizeGripper.right() - rcResizeGripper.height());

        if (d.m_pressSizeGrip || rcResizeGripper.contains(event->pos()))
            d.setDragCursor();
        else
            d.unsetDragCursor();

        if (d.m_pressSizeGrip)
        {
            QPoint pnt(event->globalPos());
            QRect rect = geometry();

            if (pnt.x() - rect.left() > minimumWidth())
                rect.setRight(pnt.x());
            else
                rect.setWidth(minimumWidth());

            if (pnt.y() - rect.top() > minimumHeight())
                rect.setBottom(pnt.y());
            else
                rect.setHeight(minimumHeight());

            d.m_offsetHeight = height() - rect.height();
            d.updateSizeGallery();

            resize(rect.size());
            d.m_lastWidth = width();
            return;
        }
    }

    if (!d.m_pressSizeGrip)
        QMenu::mouseMoveEvent(event);
}

/*! \reimp */
void OfficePopupMenu::mouseReleaseEvent(QMouseEvent* event)
{
    QTN_D(OfficePopupMenu);
    d.m_pressSizeGrip = false;
    d.m_offsetHeight = 0;
    d.setTransparentWidgetForMouseEvents(false);
    QMenu::mouseReleaseEvent(event);
}

/*! \reimp */
void OfficePopupMenu::moveEvent(QMoveEvent* event)
{
    Q_UNUSED(event);
    QTN_D(OfficePopupMenu);
    if (d.m_pressSizeGrip)
        setCursor(Qt::SizeFDiagCursor);
}

/*! \reimp */
void OfficePopupMenu::showEvent(QShowEvent* event)
{
    QTN_D(OfficePopupMenu);
    QMenu::showEvent(event);
    d.m_offsetHeight = 0;
    if (d.m_widgetPopup && d.m_resizable)
    {
        d.m_minimumWidth = d.m_widgetPopup->width() + 4;
        d.m_minimumHeight = d.calcMinimumHeight();
    }

    if (d.m_widgetPopup)
    {
        setMinimumHeight(d.m_minimumHeight);
        setMinimumWidth(d.m_minimumWidth);
    }
}

void OfficePopupMenu::hideEvent(QHideEvent* event)
{
    QTN_D(OfficePopupMenu);
    d.unsetDragCursor();
    QMenu::hideEvent(event);
}
