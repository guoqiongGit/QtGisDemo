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
#include <QResizeEvent>
#include <QScreen>
#include <QLineEdit>
#include <QComboBox>
#include <QPainter>
#include <QLayout>
#include <QEvent>
#include <QLabel>
#include <QPointer>

#include "QtnCommonStyle.h"
#include "QtnStyleOption.h"
#include "QtnRibbonPrivate.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnRibbonGroupPrivate.h"
#include "QtnRibbonGroup.h"
#include "QtnRibbonButtonPrivate.h"
#include "QtnCommonStylePrivate.h"
#include "QtnRibbonPage.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE


/* RibbonGroupPopupButton */
RibbonGroupPopupButton::RibbonGroupPopupButton(QWidget* parent, RibbonGroup* group)
    : QToolButton(parent)
{
    m_ribbonGroup = group;
    m_eventLoop = Q_NULL;
    m_hasPopup = false;

    m_ribbonGroup->adjustSize();

    ensurePolished();

    setAttribute(Qt::WA_LayoutUsesWidgetRect);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    setPopupMode(QToolButton::MenuButtonPopup);
    setText(m_ribbonGroup->title());

    m_popupMenu = new RibbonGroupPopupMenu(group);
    m_popupMenu->setWindowFlags(Qt::Popup); //TODO
}

 RibbonGroupPopupMenu* RibbonGroupPopupButton::popupMenu()
 {
     return m_popupMenu;
 }

RibbonGroupPopupButton::~RibbonGroupPopupButton()
{
    if (m_eventLoop)
        m_eventLoop->exit();
    Q_DELETE_AND_NULL(m_popupMenu);
}

bool RibbonGroupPopupButton::isShowPopup() const
{
    return m_hasPopup;
}

void RibbonGroupPopupButton::setVisible(bool visible)
{
    QToolButton::setVisible(visible);
}

void RibbonGroupPopupButton::resetReducedGroup()
{
    Q_ASSERT(false);
    if (m_ribbonGroup->isReduced())
    {
        //m_ribbonGroup->qtn_d().m_reduced = false;
        m_ribbonGroup->show();
    }
}

void RibbonGroupPopupButton::resetPopopGroup()
{
    if (m_eventLoop)
        m_eventLoop->exit(); 
//    m_hasPopup = false;
    update();
}

QSize RibbonGroupPopupButton::sizeHint() const
{
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    return QSize(style()->pixelMetric((QStyle::PixelMetric)CommonStyle::PM_RibbonReducedGroupWidth, &opt, this), 50/*m_ribbonGroup->sizeHint().height()*/);
}

void RibbonGroupPopupButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this );
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    if (m_hasPopup)
        opt.features |= QStyleOptionToolButton::HasMenu;
    QRect rcGroup = opt.rect;
    rcGroup.setBottom(rcGroup.bottom() - 1);
    opt.rect = rcGroup;
    style()->drawControl((QStyle::ControlElement)CommonStyle::CE_RibbonReducedGroup, &opt, &p, this);
}

void RibbonGroupPopupButton::mousePressEvent(QMouseEvent* event)
{
    if (!m_ribbonGroup)
        return;

    if (m_ribbonGroup->isReduced())
    {
        QStyleOptionToolButton opt;
        initStyleOption(&opt);
        if (event->button() == Qt::LeftButton && popupMode() == QToolButton::MenuButtonPopup) 
        {
            QRect popupr = style()->subControlRect(QStyle::CC_ToolButton, &opt, QStyle::SC_ToolButtonMenu, this);
            if (popupr.isValid() && popupr.contains(event->pos())) 
            {
                QPoint pnt(0, 0);
                QRect rc = rect();
                QRect screen = qtn_availableGeometry(this);
                int h = rc.height();
                if (this->mapToGlobal(QPoint(0, rc.bottom())).y() + h <= screen.height()) 
                    pnt = this->mapToGlobal(rc.bottomLeft());
                else 
                    pnt = this->mapToGlobal(rc.topLeft() - QPoint(0, h));

                QSize size = m_ribbonGroup->sizeHint();
                const int desktopFrame = style()->pixelMetric(QStyle::PM_MenuDesktopFrameWidth, 0, this);
                if (pnt.x() + size.width() - 1 > screen.right() - desktopFrame)
                    pnt.setX(screen.right() - desktopFrame - size.width() + 1);
                if (pnt.x() < screen.left() + desktopFrame)
                    pnt.setX(screen.left() + desktopFrame);

                m_hasPopup = true;
                m_ribbonGroup->setGeometry(QRect(pnt, size));
                m_ribbonGroup->show();
    
                QObject::connect(m_ribbonGroup, SIGNAL(hidePopup()), this, SLOT(resetPopopGroup()));
                QEventLoop eventLoop;
                m_eventLoop = &eventLoop;
                QPointer<QWidget> guard = m_ribbonGroup;
                (void) eventLoop.exec();
                if (guard.isNull())
                    return;
                
                m_hasPopup = false;
                QObject::disconnect(m_ribbonGroup, SIGNAL(hidePopup()), this, SLOT(resetPopopGroup()));
                m_eventLoop = Q_NULL;
                return;
            }
        }
    }
}

void RibbonGroupPopupButton::mouseReleaseEvent(QMouseEvent* event)
{
    m_hasPopup = false;
    QToolButton::mouseReleaseEvent(event);
}

/* RibbonGroupPopupMenu */
RibbonGroupPopupMenu::RibbonGroupPopupMenu(RibbonGroup* group)
    : QMenu()
    , m_group(group)
{
    setFont(group->font());
    setProperty(_qtn_TitleGroupsVisible, true);
    setPalette(group->palette());
}

RibbonGroupPopupMenu::~RibbonGroupPopupMenu()
{
}

/*! \reimp */
QSize RibbonGroupPopupMenu::sizeHint() const
{
    QSize size = RibbonGroupPrivate::_get(m_group)->sizeHint();
    return size.expandedTo(QApplication::globalStrut());
}

/*! \reimp */
void RibbonGroupPopupMenu::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    QRect rectEvent = event->rect();
    p.setClipRect(rectEvent);

    QStyle* ribbonStyle = style();

    if (windowFlags() & Qt::Popup)
    {
        RibbonStyleOption opt;
        opt.init(this);
        opt.rect.adjust(-1, 0, 2, 4);
        style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonFrameGroups, &opt, &p, this);
    }

    RibbonGroupStyleOption opt;
    RibbonGroupPrivate::_get(m_group)->initStyleOption(opt);
    opt.rect.setWidth(width());
    opt.rect.adjust(0, 0, 1, 1);
    if (rectEvent.intersects(opt.rect))
        ribbonStyle->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonFrameGroup, &opt, &p, this);

    int flags = opt.textAlignment;
    flags |= Qt::TextHideMnemonic;

    QRect rcEntryCaption = opt.rect;
    rcEntryCaption.setTop(rcEntryCaption.bottom() - opt.heightCaption);

    int indent = 0;
    if (m_group->isOptionButtonVisible())
        indent = RibbonGroupPrivate::_get(m_group)->m_optionButton->width();

    rcEntryCaption.adjust(0, -1, -indent, -2);
    opt.text = p.fontMetrics().elidedText(opt.text, RibbonGroupPrivate::_get(m_group)->titleTextElideMode(), rcEntryCaption.adjusted(2, 0, -2, 0).width());
    ribbonStyle->drawItemText(&p, rcEntryCaption, flags, opt.palette, opt.state & QStyle::State_Enabled, opt.text, QPalette::WindowText);
}

/*! \reimp */
void RibbonGroupPopupMenu::mousePressEvent(QMouseEvent* event)
{
    if ((windowFlags() & Qt::Popup) && !rect().contains(event->pos()) && m_group->isVisible()) 
    {
        QRect rect = m_group->rect();
        rect.moveTopLeft(m_group->mapToGlobal(rect.topLeft()));
        if (rect.contains(event->globalPos()))
            setAttribute(Qt::WA_NoMouseReplay);
        hide();
        return;
    }

    QMenu::mousePressEvent(event);
}

/* RibbonGroupOption */
RibbonGroupOption::RibbonGroupOption(QWidget* parent)
    : QToolButton(parent)
{
}

RibbonGroupOption::~RibbonGroupOption()
{
}

QString RibbonGroupOption::text() const
{ return QString(); }

/*! \reimp */
QSize RibbonGroupOption::sizeHint() const
{
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    opt.iconSize = QSize(15, 14);
    QSize sizeHint = style()->sizeFromContents(QStyle::CT_ToolButton, &opt, QSize(15, 14), this).
        expandedTo(QApplication::globalStrut());
    return sizeHint;
}

void RibbonGroupOption::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this);
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    opt.iconSize = QSize(15, 14); 
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonOptionButton, &opt, &p, this);
}

/*! \reimp */
void RibbonGroupOption::actionEvent(QActionEvent* event)
{
    QToolButton::actionEvent(event);
    if (event->type() == QEvent::ActionChanged)
    {
        QAction* action = event->action();
        setPopupMode(action->menu() ? QToolButton::MenuButtonPopup : QToolButton::DelayedPopup);
    }
}


/*!
\class RibbonGroupScrollButton
\internal
*/
RibbonGroupScrollButton::RibbonGroupScrollButton(QWidget* parent, bool scrollLeft)
    : QToolButton(parent)
    , m_scrollLeft( scrollLeft )
{
}

/*! \internal */
RibbonGroupScrollButton::~RibbonGroupScrollButton()
{
}

/*! \reimp */
void RibbonGroupScrollButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this);
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    opt.arrowType = m_scrollLeft ? Qt::LeftArrow : Qt::RightArrow;
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonGroupScrollButton, &opt, &p, this);
}

/*! \reimp */
void RibbonGroupScrollButton::leaveEvent(QEvent* event)
{
    QToolButton::leaveEvent(event);
    emit stopScrollTimer();
}

