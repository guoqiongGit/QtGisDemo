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
#include <QBitmap>

#include "QtnRibbonKeyTipPrivate.h"
#include "QtnCommonStylePrivate.h"
#include "QtnStyleHelperPrivate.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

QTITAN_BEGIN_NAMESPACE
/* RibbonKeyTipPrivate */
class RibbonKeyTipPrivate : public QObject
{
    QTN_DECLARE_PUBLIC(RibbonKeyTip)
public:
    explicit RibbonKeyTipPrivate();
public:
    QString m_strTip;
    QString m_strCaption;
    QString m_strPrefix;
    QWidget* m_owner;
    QAction* m_action;
    QWidget* m_bars;
    QPoint m_pnt;
    bool m_enabled;
    bool m_visible;
    uint m_align;
    bool m_explicit;
};
QTITAN_END_NAMESPACE

/* RibbonKeyTipPrivate */
RibbonKeyTipPrivate::RibbonKeyTipPrivate()
    : m_owner(Q_NULL)
    , m_action(Q_NULL)
    , m_bars(Q_NULL)
    , m_enabled(false)
    , m_visible(true)
    , m_align(0)
    , m_explicit(false)
{
}

/*!
    \class RibbonKeyTip
    \internal
*/
RibbonKeyTip::RibbonKeyTip(QWidget* bars, QWidget* owner, const QString& caption, 
    const QPoint& pt, uint align, bool enabled, QAction* action)
    : QFrame(bars, Qt::ToolTip | Qt::BypassGraphicsProxyWidget)
{
    QTN_INIT_PRIVATE(RibbonKeyTip);
    QTN_D(RibbonKeyTip);
    setFocusPolicy(Qt::NoFocus);
    d.m_action = action;
    d.m_owner = owner;
    d.m_strCaption = caption;
    d.m_bars = bars;
    d.m_pnt = pt;
    d.m_enabled = enabled;
    d.m_align = align;

    setEnabled(enabled);

    setForegroundRole(QPalette::ToolTipText);
    setBackgroundRole(QPalette::ToolTipBase);
    QPalette pal = QApplication::palette("QToolTip");
    pal.setColor(QPalette::Light, pal.color(QPalette::ToolTipText));

    setPalette(pal);
    setFont(QApplication::font("QToolTip"));
    ensurePolished();

    if (!enabled)
        setWindowOpacity(0.5);
}

RibbonKeyTip::~RibbonKeyTip()
{
    QTN_FINI_PRIVATE();
}

QPoint RibbonKeyTip::posTip() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_pnt;
}

void RibbonKeyTip::setVisibleTip(bool visible)
{
    QTN_D(RibbonKeyTip);
    d.m_visible = visible;
}

bool RibbonKeyTip::isVisibleTip() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_visible;
}

bool RibbonKeyTip::isEnabledTip() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_enabled;
}

QWidget* RibbonKeyTip::getBars() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_bars;
}

uint RibbonKeyTip::getAlign() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_align;
}

void RibbonKeyTip::setExplicit(bool exp)
{
    QTN_D(RibbonKeyTip);
    d.m_explicit = exp;
}

bool RibbonKeyTip::isExplicit() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_explicit;
}

QString RibbonKeyTip::getStringTip() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_strTip;
}

void RibbonKeyTip::setStringTip(const QString& str)
{
    QTN_D(RibbonKeyTip);
    d.m_strTip = str;
}

QString RibbonKeyTip::getCaption() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_strCaption;
}

void RibbonKeyTip::setCaption(const QString& str)
{
    QTN_D(RibbonKeyTip);
    d.m_strCaption = str;
}

QString RibbonKeyTip::getPrefix() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_strPrefix;
}

void RibbonKeyTip::setPrefix(const QString& pref)
{
    QTN_D(RibbonKeyTip);
    d.m_strPrefix = pref;
}

QWidget* RibbonKeyTip::getOwner() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_owner;
}

QAction* RibbonKeyTip::getAction() const
{
    QTN_D(const RibbonKeyTip);
    return d.m_action;
}

/*! \reimp */
void RibbonKeyTip::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QTN_D(RibbonKeyTip);

    QPainter p(this);
    QStyleOption opt;
    opt.init(this);

    if (d.m_enabled)
        opt.state |= QStyle::State_Enabled;
    else
        opt.state &= ~QStyle::State_Enabled;

    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonKeyTip, &opt, &p, this);
    style()->drawItemText(&p, opt.rect, Qt::AlignVCenter | Qt::AlignCenter | Qt::TextSingleLine | Qt::TextWordWrap, 
        opt.palette, d.m_enabled, d.m_strTip, QPalette::ToolTipText);
}

/*! \reimp */
void RibbonKeyTip::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    return QFrame::resizeEvent(event);

    QBitmap maskBitmap(width(), height());
    maskBitmap.clear();
    QPainter p(&maskBitmap);
    p.setBrush(Qt::black);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    p.drawRoundedRect(0, 0, width(), height(), 2, 2, Qt::AbsoluteSize);
#else
    p.drawRoundedRect(0, 0, width()-1, height()-1, 2, 2, Qt::AbsoluteSize);
#endif
    p.end();
    setMask(maskBitmap);
}

