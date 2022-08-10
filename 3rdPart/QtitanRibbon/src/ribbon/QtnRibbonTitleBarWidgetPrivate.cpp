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
#include <QPainter>
#include <QLayout>
#include <QEvent>
#include <QStyleOption>
#include <QApplication>

#include "QtnPlatform.h"
#include "QtnRibbonBar.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonBackstageViewPrivate.h"
#include "QtnCommonStyle.h"
#include "QtnCommonStylePrivate.h"
#include "QtnStyleOption.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonQuickAccessBar.h"
#include "QtnRibbonTitleBarWidgetPrivate.h"

#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

QTITAN_BEGIN_NAMESPACE
/* RibbonTitleButton */
RibbonTitleButton::RibbonTitleButton(QWidget* parent, QStyle::SubControl subControl)
    : QToolButton(parent)
{
    m_subControl = subControl;
    setAttribute(Qt::WA_Hover, true);
}

RibbonTitleButton::~RibbonTitleButton()
{
}

QStyle::SubControl RibbonTitleButton::subControl() const
{
    return m_subControl;
}

/*! \reimp */
void RibbonTitleButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p(this);
    CaptionButtonStyleOption opt;
    initStyleOption(&opt);
    opt.activeSubControls = m_subControl;
    style()->drawPrimitive(QStyle::PE_PanelButtonTool, &opt, &p, this);
}

/* SysButtonItem */
class SysButtonItem : public QLayoutItem
{
public:
    SysButtonItem(RibbonSystemButton* sysButton)
        : m_sysButton(sysButton) {}
public:
    virtual QSize sizeHint() const { return m_sysButton->sizeHint(); }
    virtual QSize minimumSize() const { return m_sysButton->rect().size(); }
    virtual QSize maximumSize() const { return m_sysButton->size(); }
    virtual Qt::Orientations expandingDirections() const { return Qt::Horizontal; }
    virtual QRect geometry() const { return m_sysButton->rect(); }
    virtual void setGeometry(const QRect& /*rect*/) {}
    virtual bool isEmpty() const { return false; }
public:
    RibbonSystemButton* m_sysButton;
};

/* TitleTextItem */
class TitleTextItem : public QLayoutItem
{
public:
    explicit TitleTextItem(Qt::Alignment alignment = Qt::Alignment())
        : QLayoutItem(alignment) {}
public:
    virtual QSize sizeHint() const;
    virtual QSize minimumSize() const { return m_rect.size(); }
    virtual QSize maximumSize() const { return m_rect.size(); }
    virtual Qt::Orientations expandingDirections() const { return Qt::Horizontal; }
    virtual QRect geometry() const { return m_rect; }
    virtual void setGeometry(const QRect& rect);
    virtual bool isEmpty() const { return m_text.isEmpty(); }
public:
    QFont m_font;
    QString m_text;
    QRect m_rect;
};

QSize TitleTextItem::sizeHint() const 
{
    if (m_text.isEmpty())
        return QSize();
    QFontMetrics fm(m_font);
    QSize size(fm.size(Qt::TextSingleLine, m_text));
    size.setWidth(size.width() + qtn_horizontalAdvanceFont(fm, QStringLiteral("XX")));
    return size;
}

void TitleTextItem::setGeometry(const QRect& rect) 
{ 
    QSize size = TitleTextItem::sizeHint();
    size.setHeight(rect.height());
    size.setWidth(qMin(rect.width(), size.width()));
    m_rect = QRect(QPoint(rect.left() + (rect.width() - size.width()) / 2, rect.top()), size);
}

/* TitleContextTabItem */
class TitleContextTabItem : public QLayoutItem
{
public:
    explicit TitleContextTabItem(ContextHeader* contextHeader, Qt::Alignment alignment = Qt::Alignment())
        : QLayoutItem(alignment)
        , m_contextHeader(contextHeader)
    {
    }
public:
    virtual QSize sizeHint() const { return m_contextHeader->rcRect.size(); }
    virtual QSize minimumSize() const { return m_contextHeader->rcRect.size(); }
    virtual QSize maximumSize() const { return m_contextHeader->rcRect.size(); }
    virtual Qt::Orientations expandingDirections() const { return Qt::Horizontal; }
    virtual void setGeometry(const QRect& rect);
    virtual QRect geometry() const { return m_contextHeader->rcRect; }
    virtual bool isEmpty() const { return m_contextHeader->strTitle.isEmpty(); }
public:
    ContextHeader* m_contextHeader;
};

void TitleContextTabItem::setGeometry(const QRect& rect) 
{ 
    m_contextHeader->rcRect.setHeight(rect.height());
}


/* RibbonTitleBarLayout */
class RibbonTitleBarLayout : public QLayout
{
public:
    explicit RibbonTitleBarLayout();
    ~RibbonTitleBarLayout();
public:
    int addWidget(QWidget* w);
    int insertItem(int index, QLayoutItem* item);
    void removeItem(int index);
    int insertWidget(int index, QWidget* w);
    void removeSysButton();

    void setTitleText(const QString& text);
    QFont titleFont() const;
    void setTitleFont(const QFont& font);
    void setTopBorder(int border) { m_topBorder = border; }

    // abstract virtual functions:
    virtual void addItem(QLayoutItem* item);
    virtual QLayoutItem* itemAt(int index) const;
    virtual QLayoutItem* takeAt(int index);
    virtual int count() const;
    virtual QSize sizeHint() const;
    virtual void setGeometry(const QRect& rect);
public:
    SysButtonItem* sysButtonItem() const;
    TitleTextItem* titleTextItem() const;
    RibbonQuickAccessBar* quickAccessBar() const;
protected:
    void effectiveMargins(int *left, int *top, int *right, int *bottom) const;
    void deleteAll() { while (!m_list.isEmpty()) delete m_list.takeFirst(); }
    void layoutContextHeaders(const QRect& rect);
    void removeAllContextHeaders();
    bool reduceContextHeaders(const QRect& rect);
private:
    QList<QLayoutItem*> m_list;
    QList<ContextHeader*> m_listContextHeaders;
    TitleTextItem* m_titleTextItem;
    int m_topBorder;
    int leftMargin, topMargin, rightMargin, bottomMargin;
    bool m_calcGeometry;
private:
    Q_DISABLE_COPY(RibbonTitleBarLayout)
};
QTITAN_END_NAMESPACE

RibbonTitleBarLayout::RibbonTitleBarLayout()
    : m_titleTextItem(new TitleTextItem(Qt::AlignCenter))
    , m_topBorder(0)
    , m_calcGeometry(false)
{
}

RibbonTitleBarLayout::~RibbonTitleBarLayout()
{
    deleteAll(); // must do it before QObject deletes children, so can't be in ~RibbonTitleBarLayout
    delete m_titleTextItem;
}

int RibbonTitleBarLayout::addWidget(QWidget* widget)
{
    return insertWidget(m_list.count(), widget);
}

int RibbonTitleBarLayout::insertItem(int index, QLayoutItem* item)
{
    index = qMin(index, m_list.count());
    if (index < 0)
        index = m_list.count();

    m_list.insert(index, item);
    invalidate();
    return index;
}

void RibbonTitleBarLayout::removeItem(int index)
{
    m_list.removeAt(index);
    invalidate();
}

int RibbonTitleBarLayout::insertWidget(int index, QWidget* widget)
{
    addChildWidget(widget);
    index = qMin(index, m_list.count());
    if (index < 0)
        index = m_list.count();

    QWidgetItem* wi = new QWidgetItemV2(widget);
    m_list.insert(index, wi);
    invalidate();
    return index;
}

void RibbonTitleBarLayout::removeSysButton()
{
    for (int i = 0, count = m_list.count(); i < count; ++i)
    {
        if (SysButtonItem* item = dynamic_cast<SysButtonItem*>(m_list.at(i)))
        {
            m_list.removeAt(i);
            delete item;
            return;
        }
    }
}

void RibbonTitleBarLayout::setTitleText(const QString& text)
{
    if (TitleTextItem* titleText = titleTextItem())
    {
        if (titleText->m_text != text)
        {
            titleText->m_text = text;
            invalidate();
        }
    }
}

QFont RibbonTitleBarLayout::titleFont() const
{
    if (TitleTextItem* titleText = titleTextItem())
        return titleText->m_font;
    return QApplication::font("QTitleBar");
}

void RibbonTitleBarLayout::setTitleFont(const QFont& font)
{
    if (TitleTextItem* titleText = titleTextItem())
    {
        titleText->m_font = font;
        invalidate();
    }
}

SysButtonItem* RibbonTitleBarLayout::sysButtonItem() const
{
    for (int i = 0, count = m_list.count(); i < count; ++i)
    {
        if (SysButtonItem* item = dynamic_cast<SysButtonItem*>(m_list.at(i)))
            return item;
    }
    return Q_NULL;
}

TitleTextItem* RibbonTitleBarLayout::titleTextItem() const
{
    return m_titleTextItem;
}

RibbonQuickAccessBar* RibbonTitleBarLayout::quickAccessBar() const
{
    for (int i = 0, count = m_list.count(); i < count; ++i)
    {
        QLayoutItem* item = m_list.at(i);
        if (RibbonQuickAccessBar* quickAccessBar = qobject_cast<RibbonQuickAccessBar*>(item->widget()))
            return quickAccessBar;
    }
    return Q_NULL;
}

/*! \reimp */
void RibbonTitleBarLayout::addItem(QLayoutItem* item)
{
    m_list.append(item);
}

/*! \reimp */
QLayoutItem* RibbonTitleBarLayout::itemAt(int index) const
{
    return m_list.value(index);
}

/*! \reimp */
QLayoutItem* RibbonTitleBarLayout::takeAt(int index)
{
    if (index < 0 || index >= m_list.size())
        return 0;
    QLayoutItem* item = m_list.takeAt(index);
    if (item->widget())
        item->widget()->hide();
    return item;
}

/*! \reimp */
int RibbonTitleBarLayout::count() const
{
    return m_list.size();
}

/*! \reimp */
QSize RibbonTitleBarLayout::sizeHint() const
{
    QSize s(0, 0);
    int n = m_list.count();

    for (int i = 0; i < n; ++i)
    {
        if (QWidget* widget = m_list.at(i)->widget())
        {
            QSize ws(widget->sizeHint());
            if (widget->sizePolicy().horizontalPolicy() == QSizePolicy::Ignored)
                ws.setWidth(0);
            if (widget->sizePolicy().verticalPolicy() == QSizePolicy::Ignored)
                ws.setHeight(0);
            s = s.expandedTo(ws);
        }
    }
    return s;
}

/*! \reimp */
void RibbonTitleBarLayout::setGeometry(const QRect& rect)
{
    if (!m_calcGeometry && rect != geometry())
    {
        m_calcGeometry = true;
        RibbonTitleBarWidget* widget = qobject_cast<RibbonTitleBarWidget*>(parent());
        Q_ASSERT(widget != Q_NULL);
        int offsetX = widget->x();

        if (WindowTitleBar* titleBar = widget->getWindowTitleBar())
            offsetX -= titleBar->borderThickness();

        layoutContextHeaders(widget->geometry());

        QLayout::setGeometry(rect);
        QRect cr = alignment() ? alignmentRect(rect) : rect;

        getContentsMargins(&leftMargin, &topMargin, &rightMargin, &bottomMargin);

        int left, top, right, bottom;
        effectiveMargins(&left, &top, &right, &bottom);
        QRect s(cr.x() + left, cr.y() + top, cr.width() - (left + right), cr.height() - (top + bottom));

        QList<TitleContextTabItem*> listContextHeaders;
        for (int i = 0, count = m_list.count(); i < count; ++i)
        {
            if (TitleContextTabItem* item = dynamic_cast<TitleContextTabItem*>(itemAt(i)))
            {
                QRect rectContext = item->m_contextHeader->rcRect;
                rectContext.setTop(s.y() + m_topBorder);
                rectContext.setBottom(s.bottom());
                rectContext.translate(-offsetX, 0);
                item->m_contextHeader->rcRect = rectContext.adjusted(0, 0, -1, 0);
                listContextHeaders << item;
            }
        }

        int posX = 0;
        int size = 0;
        int offsetRight = 0;
        for (int i = 0, count = m_list.count(); i < count; ++i)
        {
            int posY = s.y();
            QLayoutItem* item = m_list.at(i);
            if (!dynamic_cast<TitleContextTabItem*>(item))
            {
                size = count - 1 == i ? rect.width() - size : item->geometry().width();
                if (RibbonQuickAccessBar* quickAccessBar = qobject_cast<RibbonQuickAccessBar*>(item->widget()))
                {
                    posX += quickAccessBar->style()->pixelMetric((QStyle::PixelMetric)CommonStyle::PM_RibbonQuickAccessBarMargin, Q_NULL, item->widget());
                    size = item->sizeHint().width();
                }

                item->setGeometry(QRect(posX, posY, size, s.height()));
                offsetRight += item->geometry().width();
                posX += size;
            }
        }
        QRect freeRect(QPoint(offsetRight, s.y()), QSize(s.width() - offsetRight, s.height()));
        TitleTextItem* textItem = titleTextItem();
        textItem->setGeometry(freeRect);

        if (listContextHeaders.count() > 0)
        {
            QRect rcTitleText = textItem->geometry();
            if (!rcTitleText.isNull())
            {
                QRect rcHeaders(QPoint(listContextHeaders.at(0)->geometry().left(), cr.top() + 6),
                    QPoint(listContextHeaders.at(listContextHeaders.count() - 1)->geometry().right(), cr.bottom()));

                // position calculation of text
                int captionLength = rcTitleText.width();
                QRect rcCaptionText(rcTitleText);
                if (rcCaptionText.intersects(rcHeaders))
                {
                    if (rcCaptionText.center().x() > rcHeaders.center().x())
                    {
                        if (cr.right() - rcHeaders.right() < captionLength)
                        {
                            rcTitleText.setLeft(rcHeaders.right());
                            rcTitleText.setRight(cr.right());
                        }
                        else
                        {
                            rcTitleText.setLeft(rcHeaders.right());
                            rcTitleText.setRight(rcHeaders.right() + captionLength);
                        }
                    }
                    else
                    {
                        if (rcHeaders.left() - cr.left() < captionLength)
                        {
                            rcTitleText.setLeft(cr.left());
                            rcTitleText.setRight(rcHeaders.left());
                        }
                        else
                        {
                            rcTitleText.setLeft(offsetRight/*rcHeaders.left() - captionLength*/);
                            rcTitleText.setRight(rcHeaders.left());
                        }
                    }
                }
            }
            textItem->setGeometry(rcTitleText);
        }
        m_calcGeometry = false;
    }
}

/*! \internal */
void RibbonTitleBarLayout::effectiveMargins(int *left, int *top, int *right, int *bottom) const
{
    int l = leftMargin;
    int t = topMargin;
    int r = rightMargin;
    int b = bottomMargin;
    if (left)   *left = l;
    if (top)    *top = t;
    if (right)  *right = r;
    if (bottom) *bottom = b;
}

/*! \internal */
void RibbonTitleBarLayout::layoutContextHeaders(const QRect& rect)
{
    removeAllContextHeaders();

    RibbonTitleBarWidget* that = qobject_cast<RibbonTitleBarWidget*>(parent());
    Q_ASSERT(that != Q_NULL);
    ContextHeader* prevContextHeader = Q_NULL;
    RibbonTabBar* ribbonTabBar = RibbonBarPrivate::_get(that->ribbonBar())->m_ribbonTabBar;
    int count = ribbonTabBar->getTabCount();
    if (count == 0)
        return;

    QRect rectTitleText = rect;
    for (int i = 0; i < count; ++i)
    {
        RibbonTab* tab = ribbonTabBar->getTab(i);

        if (tab->isHidden())
            continue;

        if (tab->contextColor() == Qtitan::ContextColorNone || tab->contextText().isEmpty())
        {
            prevContextHeader = Q_NULL;
            continue;
        }

        QRect rect = tab->geometry();
        QPoint topLeft = ribbonTabBar->mapToParent(rect.topLeft());
        QPoint bottomRight = ribbonTabBar->mapToParent(rect.bottomRight());

        if (prevContextHeader && !prevContextHeader->strGroupName.isEmpty() && prevContextHeader->strGroupName == tab->contextGroupName())
        {
            prevContextHeader->rcRect.setRight(bottomRight.x());
            prevContextHeader->lastTab = tab;
            tab->setContextHeader(prevContextHeader);
        }
        else
        {
            ContextHeader* header = new ContextHeader(ribbonTabBar, tab);
            header->rcRect = QRect(QPoint(topLeft.x(), rectTitleText.top()), QPoint(bottomRight.x(), rectTitleText.bottom()));
            m_listContextHeaders.append(header);
            prevContextHeader = header;
        }
    }
    count = m_listContextHeaders.count();
    if (count == 0)
        return;

    if (!reduceContextHeaders(rect))
    {
        removeAllContextHeaders();
        return;
    }
    for (QList<ContextHeader*>::ConstIterator it = m_listContextHeaders.begin(); it != m_listContextHeaders.end(); ++it)
        addItem(new TitleContextTabItem(*it, Qt::AlignCenter));
}

/*! \internal */
void RibbonTitleBarLayout::removeAllContextHeaders()
{
    for (int i = 0; i < this->count(); )
    {
        if (dynamic_cast<TitleContextTabItem*>(itemAt(i)))
        {
            QLayoutItem* item = this->takeAt(i);
            delete item;
        }
        else ++i;
    }
    for (int i = 0; i < m_listContextHeaders.count(); i++)
        delete m_listContextHeaders.at(i);
    m_listContextHeaders.clear();
}

/*! \internal */
bool RibbonTitleBarLayout::reduceContextHeaders(const QRect& rect)
{
    if (rect.isNull())
        return false;

    int left = rect.left();
    int right = rect.right();

    int count = m_listContextHeaders.count();
    for (int i = 0; i < count; i++)
    {
        ContextHeader* header = m_listContextHeaders.at(i);
        if (header->rcRect.left() < left)
        {
            header->rcRect.setLeft(left);
            if (header->rcRect.width()  < 40)
                header->rcRect.setRight(left + 40);

            left = header->rcRect.right();
        }
        else break;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        ContextHeader* header = m_listContextHeaders.at(i);
        if (header->rcRect.right() > right)
        {
            header->rcRect.setRight(right);
            if (header->rcRect.width() < 40)
                header->rcRect.setLeft(right - 40);

            right = header->rcRect.left();

            if (right < left)
                return false;
        }
        else break;
    }
    return true;
}


/*!
    \class RibbonTitleBarWidget
    \internal
*/
RibbonTitleBarWidget::RibbonTitleBarWidget(RibbonBar* ribbonBar)
    : QWidget(ribbonBar)
    , m_dirtyTextTitle(false)
    , m_ribbonBar(ribbonBar)
    , m_titleBarLayout(new RibbonTitleBarLayout)
{
    Q_ASSERT(m_ribbonBar != Q_NULL);
    setAutoFillBackground(false);
    setMouseTracking(true);
    setAttribute(Qt::WA_NoSystemBackground);

    m_titleBarLayout->setContentsMargins(0, 0, 0, 0);
    m_titleBarLayout->setSpacing(0);
    setLayout(m_titleBarLayout);
    topWidget()->installEventFilter(this);
}

RibbonTitleBarWidget::~RibbonTitleBarWidget()
{
}

void RibbonTitleBarWidget::addWidget(QWidget* widget)
{
    m_titleBarLayout->addWidget(widget);
}

void RibbonTitleBarWidget::removeWidget(QWidget* widget)
{
    m_titleBarLayout->removeWidget(widget);
}

void RibbonTitleBarWidget::adjustSizeTitleBar()
{
    adjustSize();
    if (WindowTitleBar* titleBar = getWindowTitleBar())
        titleBar->update();
}

RibbonBar* RibbonTitleBarWidget::ribbonBar() const
{
    return m_ribbonBar;
}

WindowTitleBar* RibbonTitleBarWidget::getWindowTitleBar() const
{
    if (WindowTitleBar* titleBar = RibbonBarPrivate::_get(m_ribbonBar)->findTitleBar())
    {
        if (titleBar->widget() == this)
            return titleBar;
    }
    return Q_NULL;
}

void RibbonTitleBarWidget::windowTitleChanged(const QString& text)
{
    m_titleBarLayout->setTitleText(text);
    m_dirtyTextTitle = true;
    m_titleBarLayout->activate();
}

void RibbonTitleBarWidget::updateContextHeaders()
{
    m_titleBarLayout->invalidate();
}

/*! \internal */
QWidget* RibbonTitleBarWidget::topWidget() const
{
#ifndef QTITAN_DESIGNER
    if (m_ribbonBar->parentWidget() && m_ribbonBar->parentWidget()->isTopLevel())
        return m_ribbonBar->parentWidget();
    else
        return m_ribbonBar;
#else
    return m_ribbonBar;
#endif
}

void RibbonTitleBarWidget::updateTextTitle()
{
    if (!m_dirtyTextTitle)
        return;
    Q_ASSERT(topWidget() != Q_NULL);
    TitleTextItem* itemText = m_titleBarLayout->titleTextItem();
    Q_ASSERT(itemText != Q_NULL);

    const bool inRibbon = parentWidget() == ribbonBar();
    if (inRibbon)
        m_titleBarLayout->setTitleText(QString());

    if (!inRibbon && itemText->m_text.isEmpty())
        m_titleBarLayout->setTitleText(qobject_cast<RibbonBar*>(parentWidget()) ? QString() : topWidget()->window()->windowTitle());

    m_titleBarLayout->setTitleFont(m_ribbonBar->font());
    m_dirtyTextTitle = false;
}

void RibbonTitleBarWidget::updateBorder()
{
    m_titleBarLayout->setTopBorder(getWindowTitleBar() != Q_NULL && !topWidget()->isMaximized() ?
        getWindowTitleBar()->borderThickness() / 2 : 0);
}

void RibbonTitleBarWidget::initTitleBarOption(TitleBarStyleOption* opt) const
{
    WindowTitleBar* titleBar = getWindowTitleBar();
    if (titleBar != Q_NULL)
        titleBar->initStyleOption(opt);
    else
        opt->initFrom(this);

    if (RibbonSystemButton* button = m_ribbonBar->systemButton())
    {
        if (const RibbonBackstageView* backstage = qobject_cast<const RibbonBackstageView*>(button->backstage()))
        {
            opt->isBackstageVisible = !backstage->isHidden();
            opt->menuWidth = RibbonBackstageViewPrivate::_get(backstage)->m_backstageMenu->width();
            opt->paletteBackstageFrameMenu = RibbonBackstageViewPrivate::_get(backstage)->m_backstageMenu->palette();
        }
    }

    if (!opt->isBackstageVisible)
    {
        for (int i = 0, count = m_titleBarLayout->count(); i < count; ++i)
        {
            if (TitleContextTabItem* item = dynamic_cast<TitleContextTabItem*>(m_titleBarLayout->itemAt(i)))
            {
                if (!item->m_contextHeader || !item->m_contextHeader->firstTab || !item->m_contextHeader->lastTab || item->m_contextHeader->color == Qtitan::ContextColorNone)
                    continue;
                opt->listContextHeaders << TitleBarStyleOption::ContextData(item->m_contextHeader->rcRect, item->m_contextHeader->strTitle, item->m_contextHeader->color);
            }
        }
    }

    TitleTextItem* itemText = m_titleBarLayout->titleTextItem();
    Q_ASSERT(itemText != Q_NULL);
    opt->text = itemText->m_text;
    opt->alignment = itemText->alignment() | Qt::TextSingleLine;
    opt->rcTitleText = itemText->geometry();
    opt->fontTextTitle = m_titleBarLayout->titleFont();

    if (SysButtonItem* item = m_titleBarLayout->sysButtonItem())
    {
        SystemToolButtonStyleOption butOpt;
        item->m_sysButton->initButtonStyleOption(&butOpt);
        opt->optButton = butOpt;

        if (item->m_sysButton->toolButtonStyle() == Qt::ToolButtonFollowStyle)
        {
            const int halfHeight = item->m_sysButton->height() / 2;
            opt->optButton.rect.moveTop(geometry().bottom() - halfHeight);
        }

        if (opt->optButton.state & QStyle::State_Sunken)
            opt->optButton.state |= QStyle::State_Sunken;
    }
}

ContextHeader* RibbonTitleBarWidget::hitTestContextHeaders(const QPoint& point) const
{
    for (int i = 0, count = m_titleBarLayout->count(); i < count; ++i)
    {
        if (TitleContextTabItem* item = dynamic_cast<TitleContextTabItem*>(m_titleBarLayout->itemAt(i)))
        {
            if (item->m_contextHeader->rcRect.contains(point) && item->m_contextHeader->firstTab)
                return item->m_contextHeader;
        }
    }
    return Q_NULL;
}

/*! \reimp */
bool RibbonTitleBarWidget::event(QEvent* event)
{
    switch (event->type())
    {
        case QEvent::ParentChange:
        {
            m_dirtyTextTitle = true;
            m_titleBarLayout->invalidate();
            break;
        }
        case QEvent::StyleChange:
        {
            if (RibbonSystemButton* systemButton = m_ribbonBar->systemButton())
            {
                m_titleBarLayout->removeSysButton();
                if (systemButton->toolButtonStyle() == Qt::ToolButtonFollowStyle)
                    m_titleBarLayout->insertItem(0, new SysButtonItem(systemButton));
            }
            break;
        }
        default:
            break;
    }
    return QWidget::event(event);
}

/*! \reimp */
bool RibbonTitleBarWidget::eventFilter(QObject* watched, QEvent* event)
{
    if (topWidget() == watched)
    {
        if (event->type() == QEvent::WindowTitleChange ||
            event->type() == QEvent::FontChange)
        {
            m_dirtyTextTitle = true;
            m_titleBarLayout->activate();
        }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        else if (event->type() == QEvent::WinIdChange)
        {
            if (QObject* wnd = (QObject*)(topWidget()->windowHandle()))
                QObject::connect(wnd, SIGNAL(windowTitleChanged(const QString&)), this, SLOT(windowTitleChanged(const QString&)));
        }
#endif
    }
    return QWidget::eventFilter(watched, event);
}

/*! \reimp */
void RibbonTitleBarWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    updateTextTitle();
    QPainter painter(this);
    TitleBarStyleOption opt;
    initTitleBarOption(&opt);
    style()->drawComplexControl(static_cast<QStyle::ComplexControl>(CommonStyle::CC_RibbonTitleBarWidget), &opt, &painter, this);
    if (RibbonQuickAccessBar* accessBar = m_titleBarLayout->quickAccessBar())
    {
        if (accessBar->visibleCount() > 0)
        {
            RibbonQuickAccessBarStyleOption opt;
            opt.init(accessBar);
            const int hor = CommonStylePrivate::dpiScaled(2, accessBar);
            const int ver = CommonStylePrivate::dpiScaled(1, accessBar);
            opt.rect = accessBar->geometry().adjusted(-hor, -ver, hor, ver);
            opt.quickAccessBarPosition = RibbonBar::QATopPosition;
            RibbonSystemButton* systemButton = ribbonBar()->systemButton();
            opt.roundButton = systemButton && systemButton->toolButtonStyle() == Qt::ToolButtonFollowStyle;
            opt.palette.setColor(QPalette::Window, accessBar->parentWidget()->palette().color(QPalette::Window));
            style()->drawControl(QStyle::CE_ToolBar, &opt, &painter, accessBar);
        }
    }
}

/*! \reimp */
void RibbonTitleBarWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (ContextHeader* contextTab = hitTestContextHeaders(event->pos()))
        {
            RibbonBarPrivate* dd = RibbonBarPrivate::_get(m_ribbonBar);
            int index = dd->m_ribbonTabBar->getTabIndex(contextTab->firstTab);
            if (index != -1)
            {
                m_ribbonBar->setCurrentPageIndex(index);
                return;
            }
        }
    }
    event->ignore();
}

