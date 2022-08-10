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
#include <QPainter>
#include <QTime>
#include <QWidgetAction>
#include <QStyleOption>
#include <qevent.h>

#include "QtnRibbonBar.h"
#include "QtnRibbonPrivate.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonButtonPrivate.h"
#include "QtnRibbonTabBar.h"
#include "QtnRibbonPagePrivate.h"
#include "QtnRibbonBackstageView.h"

#include "QtnStyleHelperPrivate.h"
#include "QtnStyleOption.h"
#include "QtnCommonStylePrivate.h"
#include "QtnRibbonQuickAccessBar.h"
#include "QtnRibbonDef.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

/* Qtitan::ContextHeader */
ContextHeader::ContextHeader(RibbonTabBar* bar, RibbonTab* tab)
    : tabBar(bar)
    , firstTab(tab)
    , lastTab(tab)
{
    Q_ASSERT(bar != Q_NULL && tab != Q_NULL);
    color = firstTab->contextColor();
    strTitle = firstTab->contextText();
    strGroupName = firstTab->contextGroupName();
    rcRect = QRect();
    firstTab->setContextHeader(this);
}

ContextHeader::~ContextHeader()
{
    for (int i = 0; i < tabBar->getTabCount(); ++i)
    {
        RibbonTab* tab = tabBar->getTab(i);
        if (tab->getContextHeader() == this)
            tab->setContextHeader(Q_NULL);
    }
}

QTITAN_BEGIN_NAMESPACE

class RibbonTabPrivate : public QObject
{
public:
    QTN_DECLARE_PUBLIC(RibbonTab)
public:
    explicit RibbonTabPrivate();
    static RibbonTabPrivate* get(RibbonTab* tab);
public:
    void init();
    QSize sizeForWidth(int w) const;
    void updateLabel();
    QRect documentRect() const;
    QRectF layoutRect() const;
public:
    mutable bool m_valid_hints;
    mutable QSize m_sh;
    mutable QSizePolicy m_sizePolicy;
    mutable QSize m_msh;

    bool m_selected;
    int m_margin;
    int m_width;
    Qt::Alignment m_align;
    short m_indent;
    short m_frameWidth;
    QString m_text;
    QString m_contextText;
    QString m_contextGroupName;
    Qtitan::ContextColor m_contextColor;
    ContextHeader* m_contextHeader;
    QAction* m_defaultAction;
    RibbonPage* m_page;

    int m_shortcutId;
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
    QTime m_dblClickInterval;
#endif
    mutable uint m_isTextLabel     : 1;
    mutable uint m_textLayoutDirty : 1;
    mutable uint m_textDirty       : 1;
    mutable uint m_tabMouseOver    : 1;
};

class RibbonTabBarPrivate : public QObject
{
public:
    QTN_DECLARE_PUBLIC(RibbonTabBar)
public:
    explicit RibbonTabBarPrivate();
public:
    void layoutWidgets();
    bool validIndex(int index) const { return index >= 0 && index < m_tabList.count(); }
    bool validWidth() const;
    RibbonBar* ribbonBar() const;
public:
    QList<RibbonTab*> m_tabList;
    QList<QWidget*> m_controls;
    QList<QWidget*> m_listEnabledWidgets;
    QAction* m_actionSystemPopupBar;
    int m_currentIndex;
    int m_margin;
    RibbonTabBar::SelectionBehavior selectionBehaviorOnRemove;
    bool m_validRect;
};

QTITAN_END_NAMESPACE

void QTITAN_PREPEND_NAMESPACE(qtn_set_tab_selected)(RibbonTab* tab, bool selected)
{
    RibbonTabPrivate::get(tab)->m_selected = selected;
}

RibbonTabPrivate::RibbonTabPrivate()
    : m_width(-1)
    , m_page(Q_NULL) 
    , m_shortcutId(0)
{
}

RibbonTabPrivate* RibbonTabPrivate::get(RibbonTab* tab)
{
    return &tab->qtn_d();
}

void RibbonTabPrivate::init()
{
    QTN_P(RibbonTab);
    m_contextColor = Qtitan::ContextColorNone;
    m_contextHeader = Q_NULL;
    m_valid_hints   = false;
    m_sh            = QSize(0, 0);
    m_margin        = 0;
    m_isTextLabel   = false;
    m_textDirty     = false;
    m_tabMouseOver  = false;
    m_selected        = false;
    m_shortcutId = -1;
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
    m_dblClickInterval.start();
#endif
    m_align = Qt::AlignLeft | Qt::AlignVCenter /*| Qt::TextExpandTabs*/;
    m_indent = -1;
    m_frameWidth = 1;
    m_defaultAction = new QWidgetAction(&p);
    p.setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred, QSizePolicy::Label));
}

QSize RibbonTabPrivate::sizeForWidth(int w) const
{
    QTN_P(const RibbonTab);
    if(p.minimumWidth() > 0)
        w = qMax(w, p.minimumWidth());

    QSize contentsMargin(2,0);

    QRect br;
    int hextra = 2 * m_margin;
    int vextra = hextra;
    QFontMetrics fm = p.fontMetrics();

    QString text = m_text;
    int countText = text.count();
    int countContextText = m_contextText.count();

    if (countText < countContextText)
        text = m_contextText;

    bool itemUpperCase = static_cast<bool>(p.style()->styleHint(static_cast<QStyle::StyleHint>(CommonStyle::SH_RibbonItemUpperCase), Q_NULL, &p));
    if (!text.isEmpty()) 
    {
        if (itemUpperCase)
            text = text.toUpper();

        uint m_align = QStyle::visualAlignment(p.layoutDirection(), QFlag(this->m_align));
        int m = m_indent;

        if (m < 0 && m_frameWidth)
        {
            if (itemUpperCase)
                m = qtn_horizontalAdvanceFont(fm, QLatin1Char('X')) - m_margin*2;
            else
                m = qtn_horizontalAdvanceFont(fm, QLatin1Char('x')) - m_margin*2;
        }
        if (m > 0) 
        {
            if ((m_align & Qt::AlignLeft) || (m_align & Qt::AlignRight))
                hextra += m;
            if ((m_align & Qt::AlignTop) || (m_align & Qt::AlignBottom))
                vextra += m;
        }

        int flags = static_cast<int>(m_align & ~(Qt::AlignVCenter | Qt::AlignHCenter));
        bool tryWidth = (w < 0) && (m_align & Qt::TextWordWrap);
        if (tryWidth)
            w = fm.averageCharWidth() * 80;
        else if (w < 0)
            w = 2000;
        w -= (hextra + contentsMargin.width());
        br = fm.boundingRect(0, 0, w, 2000, flags, text);
        if (tryWidth && br.height() < 4*fm.lineSpacing() && br.width() > w/2)
            br = fm.boundingRect(0, 0, w/2, 2000, flags, text);
        if (tryWidth && br.height() < 2*fm.lineSpacing() && br.width() > w/4)
            br = fm.boundingRect(0, 0, w/4, 2000, flags, text);
    } else
        br = QRect(QPoint(0, 0), QSize(fm.averageCharWidth(), fm.lineSpacing()));

    int hframe = itemUpperCase ? qtn_horizontalAdvanceFont(fm, QLatin1Char('X'))*2 : qtn_horizontalAdvanceFont(fm, QLatin1Char('x'))*2;

    const QSize contentsSize(br.width() + hextra + hframe, br.height() + vextra);
    return (contentsSize + contentsMargin).expandedTo(p.minimumSize());
}

void RibbonTabPrivate::updateLabel()
{
    QTN_P(RibbonTab);
    m_valid_hints = false;

    if (m_isTextLabel)
    {
        QSizePolicy policy = p.sizePolicy();
        const bool wrap = m_align & Qt::TextWordWrap;
        policy.setHeightForWidth(wrap);
        // should be replaced by WA_WState_OwnSizePolicy idiom
        if (policy != p.sizePolicy())  
            p.setSizePolicy(policy);
        m_textLayoutDirty = true;
    }
    p.updateGeometry();
    p.update(p.contentsRect());
}

QRect RibbonTabPrivate::documentRect() const
{
    QTN_P(const RibbonTab);
    Q_ASSERT_X(m_isTextLabel, "documentRect", "document rect called for tab that is not a m_text tab!");
    QRect cr = p.contentsRect();
    cr.setLeft(cr.left());
    cr.adjust(m_margin, m_margin, -m_margin, -m_margin);
    const int m_align = QStyle::visualAlignment(p.layoutDirection(), QFlag(this->m_align));
    int m = m_indent;
    if (m < 0 && m_frameWidth )
        m = qtn_horizontalAdvanceFont(p.fontMetrics(), QLatin1Char('x')) / 2 - m_margin;
    if (m > 0) 
    {
        if (m_align & Qt::AlignLeft)
            cr.setLeft(cr.left() + m);
        if (m_align & Qt::AlignRight)
            cr.setRight(cr.right() - m);
        if (m_align & Qt::AlignTop)
            cr.setTop(cr.top() + m);
        if (m_align & Qt::AlignBottom)
            cr.setBottom(cr.bottom() - m);
    }
    return cr;
}

QRectF RibbonTabPrivate::layoutRect() const
{
    return documentRect();
}


/* RibbonTab */
RibbonTab::RibbonTab(QWidget* parent, const QString& text)
    : QWidget(parent)
    , lastTab(-1)
{
    QTN_INIT_PRIVATE(RibbonTab);
    QTN_D(RibbonTab);
    d.init();
    setText(text);
    setMargin(4);
    setAlignment(Qt::AlignCenter);
}

RibbonTab::~RibbonTab()
{
    QTN_D(RibbonTab);
    QWidget* pParent = parentWidget();
    pParent->releaseShortcut(d.m_shortcutId);

    if (d.m_contextHeader)
    {
        if (d.m_contextHeader->firstTab == this)
            d.m_contextHeader->firstTab = Q_NULL;
        if (d.m_contextHeader->lastTab == this)
            d.m_contextHeader->lastTab  = Q_NULL;
    }

    if (d.m_page)
        d.m_page->setAssociativeTab(Q_NULL);
    QTN_FINI_PRIVATE();
}

RibbonBar* RibbonTab::ribbonBar() const
{
    if (RibbonTabBar* tabBar = qobject_cast<RibbonTabBar *>(parentWidget()))
        return tabBar->ribbonBar();
    else
        return Q_NULL;
}

RibbonPage* RibbonTab::page() const
{
    QTN_D(const RibbonTab);
    return d.m_page;
}

void RibbonTab::setPage(RibbonPage* page)
{
    QTN_D(RibbonTab);
    d.m_page = page;
    if (page != Q_NULL)
        qtn_set_page_visible(page, isSelected());
}

bool RibbonTab::isSelected() const
{
    QTN_D(const RibbonTab);
    return d.m_selected;
}

void RibbonTab::setSelected(bool selected)
{
    QTN_D(RibbonTab);
    d.m_selected = selected;
    d.updateLabel();

    if (page() == Q_NULL)
        return;

    qtn_set_page_visible(page(), selected);

    if (selected)
        page()->updateLayout();
}

void RibbonTab::setIndent(int indent)
{
    QTN_D(RibbonTab);
    d.m_indent = static_cast<short>(indent);
    d.updateLabel();
}

int RibbonTab::indent() const
{
    QTN_D(const RibbonTab);
    return d.m_indent;
}

int RibbonTab::margin() const
{
    QTN_D(const RibbonTab);
    return d.m_margin;
}

void RibbonTab::setMargin(int margin)
{
    QTN_D(RibbonTab);
    if (d.m_margin == margin)
        return;
    d.m_margin = margin;
    d.updateLabel();
}

Qt::Alignment RibbonTab::alignment() const
{
    QTN_D(const RibbonTab);
    return QFlag(d.m_align & (Qt::AlignVertical_Mask|Qt::AlignHorizontal_Mask));
}

void RibbonTab::setAlignment(Qt::Alignment alignment)
{
    QTN_D(RibbonTab);
    if (alignment == (d.m_align & (Qt::AlignVertical_Mask|Qt::AlignHorizontal_Mask)))
        return;
    d.m_align = (d.m_align & ~(Qt::AlignVertical_Mask|Qt::AlignHorizontal_Mask)) | 
        (alignment & (Qt::AlignVertical_Mask|Qt::AlignHorizontal_Mask));

    d.updateLabel();
}

void RibbonTab::setText(const QString& text)
{
    QTN_D(RibbonTab);
    if (d.m_text == text)
        return;
    d.m_text = text;
    d.m_isTextLabel = true;
    d.m_textDirty = true;
    d.updateLabel();

    RibbonTabBar* pParent = qobject_cast<RibbonTabBar*>(parentWidget());
    Q_ASSERT(pParent != NULL);
    pParent->releaseShortcut(d.m_shortcutId);
    d.m_shortcutId = pParent->grabShortcut(QKeySequence::mnemonic(text));
    pParent->setShortcutEnabled(d.m_shortcutId, isEnabled());
    pParent->layoutWidgets();
}

const QString& RibbonTab::text() const
{
    QTN_D(const RibbonTab);
    return d.m_text;
}

void RibbonTab::setContextText(const QString& text)
{
    QTN_D(RibbonTab);
    d.m_contextText = text;
}

const QString& RibbonTab::contextText() const
{
    QTN_D(const RibbonTab);
    return d.m_contextText;
}

void RibbonTab::setContextGroupName(const QString& groupName)
{
    QTN_D(RibbonTab);
    d.m_contextGroupName = groupName;
}

const QString& RibbonTab::contextGroupName() const
{
    QTN_D(const RibbonTab);
    return d.m_contextGroupName;
}

void RibbonTab::setContextColor(Qtitan::ContextColor color)
{
    QTN_D(RibbonTab);
    d.m_contextColor = color;
    if (d.m_contextHeader)
        d.m_contextHeader->color = color;
}

Qtitan::ContextColor RibbonTab::contextColor() const
{
    QTN_D(const RibbonTab);
    return d.m_contextColor;
}

void RibbonTab::setContextHeader(ContextHeader* contextHeader)
{
    QTN_D(RibbonTab);
    d.m_contextHeader = contextHeader;
}

ContextHeader* RibbonTab::getContextHeader() const
{
    QTN_D(const RibbonTab);
    return d.m_contextHeader;
}

void RibbonTab::setTabWidth(int width)
{
    QTN_D(RibbonTab);
    if (width == d.m_width)
        return;
    d.m_width = width;
}

int RibbonTab::tabWidth() const
{
    QTN_D(const RibbonTab);
    return d.m_width;
}

QAction* RibbonTab::defaultAction() const
{
    QTN_D(const RibbonTab);
    return d.m_defaultAction;
}

void RibbonTab::clicked()
{
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
    QTN_D(RibbonTab);
    if (d.m_dblClickInterval.elapsed() <= QApplication::doubleClickInterval())
    {
        dblClicked();
        return;
    }
    d.m_dblClickInterval.start();
#endif
    RibbonBar* _ribbonBar = ribbonBar();
    
    Q_ASSERT(_ribbonBar != Q_NULL);
    if (_ribbonBar == Q_NULL)
        return;

    if (_ribbonBar->isBackstageVisible())
    {
        if (RibbonSystemButton* button = _ribbonBar->systemButton())
        {
            if (RibbonBackstageView* backstage = qobject_cast<RibbonBackstageView*>(button->backstage()))
                backstage->close();
        }
    }

    bool selectionChanged = false;
    if (!isSelected())
    {
        RibbonTabBar* ribbonTabBar = qobject_cast<RibbonTabBar*>(parentWidget());
        if (ribbonTabBar != Q_NULL)
            ribbonTabBar->setCurrentIndex(ribbonTabBar->getTabIndex(this));
        selectionChanged = isSelected();
    }

    if (_ribbonBar->isMinimized())
    {
        RibbonBarPrivate* barprivate = RibbonBarPrivate::_get(_ribbonBar);
        if (selectionChanged || !barprivate->isPagePopupVisible())
            barprivate->showPagePopup(page());
        else
            barprivate->hidePagePopup();
    }
}

void RibbonTab::dblClicked()
{
    RibbonBar* _ribbonBar = ribbonBar();
    if (_ribbonBar != Q_NULL)
        RibbonBarPrivate::_get(_ribbonBar)->toggledMinimized();
}

int RibbonTab::shortcut() const
{
    QTN_D(const RibbonTab);
    return d.m_shortcutId;
}

bool RibbonTab::validRect() const
{
    QTN_D(const RibbonTab);
    int wid = 0;    
    RibbonOptionHeaderStyleOption opt;
    opt.initFrom(this);
    opt.contextText = contextText();
    int clientWidth = opt.rect.width();
    if (!d.m_text.isEmpty())
    {
        QString text = d.m_text;
        wid = qtn_horizontalAdvanceFont(opt.fontMetrics, text.remove(QLatin1Char('&')));
    }
    else
        wid = 10;

    return clientWidth >= wid;
}

/*! \reimp */
void RibbonTab::paintEvent(QPaintEvent* event)
{
    QTN_D(RibbonTab);
    QPainter p(this);
    p.setClipRegion(event->region());

    RibbonOptionHeaderStyleOption opt;
    opt.initFrom(this);
    opt.firstTab = getContextHeader() && getContextHeader()->firstTab == this;
    opt.lastTab = getContextHeader() && getContextHeader()->lastTab == this;
    opt.rcFirst = getContextHeader() ? getContextHeader()->firstTab->rect() : QRect();
    opt.rcLast = getContextHeader() ? getContextHeader()->lastTab->rect() : QRect();
    opt.text = p.fontMetrics().elidedText(d.m_text, Qt::ElideRight, opt.rect.adjusted(2, 0, -2, 0).width());
    opt.contextText = contextText();
    opt.textAlignment = d.m_align;
    opt.pageColor = contextColor();

    bool minimized = false;
    bool backstageVisible = false;
    if (RibbonBar* _ribbonBar = ribbonBar())
    {
        RibbonBar::TabBarPosition position = _ribbonBar->tabBarPosition();
        if (position == RibbonBar::TabBarTopPosition)
            opt.tabBarPosition = RibbonBar::TabBarTopPosition;
        else if (position == RibbonBar::TabBarBottomPosition)
            opt.tabBarPosition = RibbonBar::TabBarBottomPosition;

        minimized = _ribbonBar->isMinimized();
        opt.minimized = minimized;
        backstageVisible = _ribbonBar->isBackstageVisible();
    }

    int w1 = d.m_sh.width();
    int w2 = opt.rect.width();
    if (w1 != w2)
        opt.state |= QStyle::State_Small;
    else
        opt.state &= ~QStyle::State_Small;

    bool selected = !backstageVisible && d.m_selected && d.m_page != Q_NULL && static_cast<QWidget *>(d.m_page)->isVisible();
    if (selected)
    {
        opt.state |= QStyle::State_Selected;
        if (minimized || backstageVisible)
            opt.state |= QStyle::State_Sunken;
    }
    else
    {
        opt.state &= ~QStyle::State_Selected;
        if (minimized || backstageVisible)
            opt.state &= ~QStyle::State_Sunken;
    }

    style()->drawControl(static_cast<QStyle::ControlElement>(CommonStyle::CE_RibbonTab), &opt, &p, this);
    style()->drawControl(static_cast<QStyle::ControlElement>(CommonStyle::CE_RibbonTabShapeLabel), &opt, &p, this);
}

/*! \reimp */
QSize RibbonTab::sizeHint() const
{
    QTN_D(const RibbonTab);
    if (!d.m_valid_hints)
        (void)RibbonTab::minimumSizeHint();

    QSize size = d.m_sh;
    if (d.m_width != -1)
       size.setWidth(d.m_width);

    return size;
}

QSize RibbonTab::minimumSizeHint() const
{
    QTN_D(const RibbonTab);
    if (d.m_valid_hints && d.m_sizePolicy == sizePolicy()) 
        return d.m_msh;
    ensurePolished();
    d.m_valid_hints = true;
    d.m_sh = d.sizeForWidth(-1);
    QSize msh(-1, -1);

    if (!d.m_isTextLabel) 
        msh = d.m_sh;
    else 
    {
        msh.rheight() = d.sizeForWidth(QWIDGETSIZE_MAX).height();
        msh.rwidth() = d.sizeForWidth(0).width();
        if (d.m_sh.height() < msh.height())
            msh.rheight() = d.m_sh.height();
    }
    const int nHeightTabs = RibbonBarPrivate::_get(ribbonBar())->m_heightTabs;
    msh.setHeight(nHeightTabs);
    d.m_sh.setHeight(nHeightTabs);
    d.m_msh = msh;
    d.m_sizePolicy = sizePolicy();
    return msh;
}

/*! \reimp */
void RibbonTab::enterEvent(QEvent* event)
{
    QWidget::enterEvent(event);
    QTN_D(RibbonTab);
    d.m_tabMouseOver = true;
    update();
}

/*! \reimp */
void RibbonTab::leaveEvent(QEvent* event)
{
    QWidget::leaveEvent(event);
    QTN_D(RibbonTab);
    d.m_tabMouseOver = false;
    update();
}

void RibbonTab::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        clicked();
        event->accept();
        return;
    }
    QWidget::mousePressEvent(event);
}


void RibbonTab::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        dblClicked();
        event->accept();
        return;
    }
    QWidget::mousePressEvent(event);
}

bool RibbonTab::event(QEvent* event)
{
    return QWidget::event(event);
}

void RibbonTab::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    if (event->button() != Qt::LeftButton)
        return;
    update();
}

/* RibbonTabBarPrivate */
RibbonTabBarPrivate::RibbonTabBarPrivate()
    : m_actionSystemPopupBar(Q_NULL)
    , m_currentIndex(-1)
    , m_margin(1) 
    , selectionBehaviorOnRemove(RibbonTabBar::SelectRightTab)
    , m_validRect(true)
{
}

void RibbonTabBarPrivate::layoutWidgets()
{
    QTN_P(RibbonTabBar);
    RibbonBar* ribBar = ribbonBar();
    Q_ASSERT(ribBar != NULL);

    if (p.geometry().isEmpty())
        return; 

    const Qt::LayoutDirection layoutDirection = p.layoutDirection();
    int rightSide = 0, offset = 0;
    if (QMenuBar* menuBar = qobject_cast<QMenuBar*>(p.parentWidget())) 
    {
        if (QWidget* rightCorner = menuBar->cornerWidget(Qt::TopRightCorner))
        {
            offset = rightCorner->size().width();
            offset += 1;
            rightSide = rightCorner->geometry().left();
        }
    }

    QSize szSumControls(0, 0);
    QRect rect = p.rect();
    for (QList<QWidget*>::iterator it = m_controls.begin(); it != m_controls.end(); ++it)
    {
        QWidget* widget = (*it);
        if (!widget->isHidden())
        {
            QSize szControl = widget->sizeHint();
            int top = ribBar->tabBarPosition() == RibbonBar::TabBarBottomPosition ? 2 : 0;
            QRect rectWidget = QRect(QPoint(rect.right() - szControl.width() - szSumControls.width() - offset, top), 
                QSize(widget->sizeHint().width(), p.sizeHint().height() - m_margin));
            widget->setGeometry(QStyle::visualRect(layoutDirection, rect, rectWidget));
            szSumControls += widget->sizeHint();
        }
    }

    int sumWidth = 0, sumCount = 0;
    QList<QRect> rectTabs;
    for (QList<RibbonTab*>::iterator it = m_tabList.begin(); it != m_tabList.end(); ++it)
    {
        RibbonTab* tab = (*it);
        tab->qtn_d().m_valid_hints = false;
        QRect rect = !tab->isHidden() ? QRect(QPoint(sumWidth + m_margin, 0), tab->sizeHint()) : QRect();
        if (!rect.isEmpty())
            sumCount++;
        sumWidth += rect.width();
        rectTabs << rect;
    }

    rightSide = m_controls.size() > 0 ? QStyle::visualRect(layoutDirection, rect, m_controls.at(m_controls.size() - 1)->geometry()).left() :
        rightSide == 0 ? QStyle::visualRect(layoutDirection, rect, p.geometry()).right() - m_margin * 8 : rightSide;

    int newWidth = 0;
    if (!rect.isEmpty() && sumCount > 0 && rightSide < sumWidth)
        newWidth = (sumWidth - rightSide) / sumCount;

    sumWidth = 0;
    bool validRect = true;
    for (int i = 0, count = m_tabList.count(); count > i; i++) 
    {
        RibbonTab* tab = m_tabList.at(i);
        QRect rectItem = rectTabs.at(i);
        if (rectItem.isEmpty())
            continue;

        if (newWidth != 0)
            rectItem.setWidth(rectItem.width() - newWidth);

        QRect rect = QRect(QPoint(sumWidth + m_margin, rectItem.y()), rectItem.size());
        tab->setGeometry(QStyle::visualRect(layoutDirection, p.rect(), rect));
        sumWidth += rectItem.width();

        if (!tab->isHidden() && !tab->validRect())
            validRect = false;
    }
    m_validRect = validRect;
}

bool RibbonTabBarPrivate::validWidth() const
{
    return m_validRect;
}

RibbonBar* RibbonTabBarPrivate::ribbonBar() const
{
    QTN_P(const RibbonTabBar);
    return qobject_cast<RibbonBar*>(p.parentWidget());
}

/* RibbonTabBar */
RibbonTabBar::RibbonTabBar(RibbonBar* ribbonBar)
    : QWidget(ribbonBar)
{
    QTN_INIT_PRIVATE(RibbonTabBar);
}

RibbonTabBar::~RibbonTabBar()
{
    QTN_FINI_PRIVATE();
}

RibbonBar* RibbonTabBar::ribbonBar() const
{
    return qobject_cast<RibbonBar *>(parentWidget());
}

int RibbonTabBar::addTab(const QString& text) 
{
    return insertTab(-1, text);
}

int RibbonTabBar::addTab(const QIcon& icon, const QString& text)
{
    return insertTab(-1, icon, text);
}

int RibbonTabBar::insertTab(int index, const QString& text)
{
    return insertTab(index, QIcon(), text);
}

int RibbonTabBar::insertTab(int index, const QIcon& icon, const QString& text)
{
    Q_UNUSED(icon);
    QTN_D(RibbonTabBar);

    QString strName = text;

    if (strName.isEmpty())
        strName = RibbonBar::tr_compatible(QtnRibbonUntitledString);

    RibbonTab* ribbonTab = new RibbonTab(this, strName);
    ribbonTab->setVisible(true);

    if (!d.validIndex(index)) 
    {
        index = d.m_tabList.count();
        d.m_tabList.append(ribbonTab);
    } 
    else 
        d.m_tabList.insert(index, ribbonTab);

    for (int i = 0; i < d.m_tabList.count(); ++i) 
    {
        if (d.m_tabList[i]->lastTab >= index)
            ++d.m_tabList[i]->lastTab;
    }

    if (d.m_currentIndex == -1)
        setCurrentIndex(index);
    else if (index <= d.m_currentIndex)
        ++d.m_currentIndex;

    d.layoutWidgets();
    return index;
}

void RibbonTabBar::moveTab(int index, int newIndex)
{
    QTN_D(RibbonTabBar);
    if (d.validIndex(index) && d.validIndex(newIndex))
    {
        RibbonTab* saveTab = d.m_tabList[d.m_currentIndex];
        d.m_tabList.move(index, newIndex);
        int ind = d.m_tabList.indexOf(saveTab);
        if (d.validIndex(ind) && ind != d.m_currentIndex)
            d.m_currentIndex = ind;
        d.layoutWidgets();
    }
}

void RibbonTabBar::removeTab(int index)
{
    QTN_D(RibbonTabBar);
    if (d.validIndex(index)) 
    {
        RibbonTab* tab = d.m_tabList[index];
        d.m_tabList.removeAt(index);
        delete tab;

        for (int i = 0; i < d.m_tabList.count(); ++i) 
        {
            if (d.m_tabList[i]->lastTab == index)
                d.m_tabList[i]->lastTab = -1;
            if (d.m_tabList[i]->lastTab > index)
                --d.m_tabList[i]->lastTab;
        }

        int newIndex = d.m_currentIndex;

        if (index == d.m_currentIndex) 
        {
            if (d.m_tabList.size() > 0) 
            {
                switch(d.selectionBehaviorOnRemove) 
                {
                    case SelectPreviousTab:
                    {
                        if (newIndex > index)
                            newIndex--;
                        if (d.validIndex(newIndex))
                            break;
                        QTN_FALLTHROUGH();
                    }
                    case SelectRightTab:
                    {
                        newIndex = index;
                        if (newIndex >= d.m_tabList.size())
                            newIndex = d.m_tabList.size() - 1;
                        break;
                    }
                    case SelectLeftTab:
                    {
                        newIndex = index - 1;
                        if (newIndex < 0)
                            newIndex = 0;
                        break;
                    }
                }
            } 
            else 
            {
                newIndex = -1;
            }
        } 
        else if (index < d.m_currentIndex) 
        {
            newIndex = d.m_currentIndex - 1;
        }

        setCurrentIndex(newIndex);
    }
}

int RibbonTabBar::currentIndex() const
{
    QTN_D(const RibbonTabBar);
    return d.m_currentIndex;
}

RibbonTab* RibbonTabBar::getTab(int nIndex) const
{
    QTN_D(const RibbonTabBar);
    if (d.validIndex(nIndex))
        return d.m_tabList[nIndex];
    return Q_NULL;
}

int RibbonTabBar::getTabCount() const
{
    QTN_D(const RibbonTabBar);
    return d.m_tabList.count();
}

int RibbonTabBar::getTabIndex(const RibbonTab* tab) const
{
    for (int i = 0, count = getTabCount(); count > i; i++)
    {
        if (getTab(i) == tab)
            return i;
    }
    return -1;
}

const QList<RibbonTab*>& RibbonTabBar::tabs() const
{
    QTN_D(const RibbonTabBar);
    return d.m_tabList;
}

RibbonTabBar::SelectionBehavior RibbonTabBar::selectionBehaviorOnRemove() const
{
    QTN_D(const RibbonTabBar);
    return d.selectionBehaviorOnRemove;
}

void RibbonTabBar::setSelectionBehaviorOnRemove(RibbonTabBar::SelectionBehavior behavior)
{
    QTN_D(RibbonTabBar);
    d.selectionBehaviorOnRemove = behavior;
}

void RibbonTabBar::setEnabledWidgets(bool enabled)
{
    QTN_D(RibbonTabBar);
    if (enabled)
    {
        for (QList<QWidget*>::iterator it = d.m_listEnabledWidgets.begin(); it != d.m_listEnabledWidgets.end(); ++it)
            (*it)->setEnabled(true);
        d.m_listEnabledWidgets.clear();
    }
    else
    {
        d.m_listEnabledWidgets.clear();
        for (QList<QWidget*>::iterator it = d.m_controls.begin(); it != d.m_controls.end(); ++it)
        {
            QWidget * widget = (*it);
            if (widget->isEnabled())
            {
                d.m_listEnabledWidgets << widget;
                widget->setEnabled(false);
            }
        }
    }
}

QAction* RibbonTabBar::addAction(const QIcon& icon, const QString& text, Qt::ToolButtonStyle style, QMenu* menu)
{
    QAction* action = new QAction(icon, text, this);
    if (menu)
        action->setMenu(menu);

    return addAction(action, style);
}

QAction* RibbonTabBar::addAction(QAction* action, Qt::ToolButtonStyle style)
{
    QTN_D(RibbonTabBar);
    if ( Qt::ToolButtonTextUnderIcon == style )
    {
        Q_ASSERT(false);
        style = Qt::ToolButtonTextBesideIcon;
    }
    QWidget::addAction(action);
    RibbonButton* button = new RibbonButton(this);

    button->setAutoRaise(true);
    button->setFocusPolicy(Qt::NoFocus);
    button->setToolButtonStyle(style);

    action->setIconText(action->text());
    button->setDefaultAction(action);
    d.m_controls.append(button);

    button->setVisible(true);
    layoutWidgets();
    return action;
}

QMenu* RibbonTabBar::addMenu(const QString& title)
{
    QTN_D(RibbonTabBar);
    QMenu* menu = new QMenu(title, this);

    RibbonButton * button = new RibbonButton(this);
    button->setAutoRaise(true);
    button->setFocusPolicy(Qt::NoFocus);
    button->setPopupMode(QToolButton::InstantPopup);
    button->setMenu(menu);
    button->setToolButtonStyle(Qt::ToolButtonTextOnly);

    button->setDefaultAction(menu->menuAction());
    d.m_controls.append(button);

    button->setVisible(true);
    layoutWidgets();
    return menu;
}

void RibbonTabBar::setCurrentIndex(int index)
{
    QTN_D(RibbonTabBar);
    if (!d.validIndex(index))
        index = -1;

    const RibbonTab* tab = (index != -1) ? d.m_tabList.at(index) : Q_NULL;
    bool changed = true;
    emit pageAboutToBeChanged(tab ? tab->page() : Q_NULL, changed);
    if (!changed)
        return;

    int newIndex = activateTab(tab);
    if (d.m_currentIndex != newIndex)
    {
        d.m_currentIndex = newIndex;
        emit currentChanged(newIndex);
    }
}

void RibbonTabBar::nextTab(bool next)
{
    QTN_D(RibbonTabBar);

    int nextIndex = currentIndex();
    if (next)
    {
        for (int i = currentIndex() + 1; i < d.m_tabList.count(); i++) 
        {
            if (d.m_tabList.at(i)->isVisible())
            {
                nextIndex = i;
                break;
            }
        }
    }
    else
    {
        for (int i = currentIndex() - 1; i >= 0; --i) 
        {
            if (d.m_tabList.at(i)->isVisible())
            {
                nextIndex = i;
                break;
            }
        }
    }
    setCurrentIndex(nextIndex);
}

int RibbonTabBar::activateTab(const RibbonTab* tab)
{
    QTN_D(RibbonTabBar);
    int newIndex = -1;
    for (int index = 0; index < d.m_tabList.count(); ++index)
    {
        RibbonTab* currentTab = d.m_tabList.at(index);
        bool selected = currentTab == tab && !currentTab->isHidden();
        if (selected)
            newIndex = index;
        currentTab->setSelected(selected);
    }
    update();
    return newIndex;
}

void RibbonTabBar::layoutWidgets()
{
    QTN_D(RibbonTabBar);
    d.layoutWidgets();
}

void RibbonTabBar::refresh()
{
    QTN_D(RibbonTabBar);
    for (QList<RibbonTab*>::iterator it = d.m_tabList.begin(); it != d.m_tabList.end(); ++it)
        (*it)->qtn_d().updateLabel();
}

bool RibbonTabBar::validWidth() const
{
    QTN_D(const RibbonTabBar);
    return d.validWidth();
}

/*! \reimp */
bool RibbonTabBar::event(QEvent* event)
{
    QTN_D(RibbonTabBar);
    switch(event->type())
    {
        case QEvent::Shortcut :
            if (QShortcutEvent* se = static_cast<QShortcutEvent*>(event))
            {
                for (int i = 0; i < d.m_tabList.count(); ++i) 
                {
                    const RibbonTab* tab = d.m_tabList.at(i);
                    if (tab->shortcut() == se->shortcutId()) 
                    {
                        setCurrentIndex(i);
                        return true;
                    }
                }
            }
            break;
        case QEvent::Resize :
                layoutWidgets();
            break;
        case QEvent::ActionRemoved :
            if (QActionEvent* actionEvent = static_cast<QActionEvent*>(event))
            {
                for (int i = d.m_controls.count() - 1; i >= 0; --i) 
                {
                    if (QToolButton* widget = qobject_cast<QToolButton*>(d.m_controls.at(i)))
                    {
                        if (actionEvent->action() == widget->defaultAction())
                        {   
                             d.m_controls.removeAt(i);
                            delete widget;
                        }
                    }
                }
                layoutWidgets();
            }
            break;
        case QEvent::ActionChanged :
            if (QActionEvent* actionEvent = static_cast<QActionEvent*>(event))
            {
                for (QList<QWidget*>::iterator it = d.m_controls.begin(); it != d.m_controls.end(); ++it)
                {
                    QWidget* widget = (*it);
                    if (QToolButton* button = qobject_cast<QToolButton*>(widget))
                    {
                        QAction* action = actionEvent->action();
                        if (action == button->defaultAction())
                        {
                            widget->setVisible(action->isVisible());
                            widget->setEnabled(action->isEnabled());
                        }
                    }
                }
                layoutWidgets();
            }
            break;
        default:
            break;
    }

    return QWidget::event(event);
}

/*! \reimp */
void RibbonTabBar::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)
    QPainter p(this);
    QStyleOption opt;
    opt.init(this);
    style()->drawControl(static_cast<QStyle::ControlElement>(CommonStyle::CE_RibbonTabBar), &opt, &p, this);
}

/*! \reimp */
void RibbonTabBar::mouseDoubleClickEvent(QMouseEvent* event)
{
    event->setAccepted(false);
    QWidget::mouseDoubleClickEvent(event);
}

/*! \reimp */
QSize RibbonTabBar::sizeHint() const
{
    QTN_D(const RibbonTabBar);
    if (!d.ribbonBar())
        return QWidget::sizeHint();
    const int heightTabs = RibbonBarPrivate::_get(d.ribbonBar())->m_heightTabs;
    return QSize(0, heightTabs).expandedTo(QApplication::globalStrut());
}
