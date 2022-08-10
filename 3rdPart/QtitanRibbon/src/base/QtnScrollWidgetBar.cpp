/****************************************************************************
**
** Qtitan Library by Developer Machines (Components for Qt.C++)
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

#include <QStyle>
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include "QtnCommonStylePrivate.h"
#include "QtnScrollWidgetBar.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

static const int QtnScrollWidgetBarPageIndent = 25;
static const int QtnScrollWidgetBarItemIndent = 20;

AbstractScrollWidgetBar::AbstractScrollWidgetBar(QWidget* parent, Qt::Orientation orientation)
    : QWidget(parent), m_orientation(orientation), m_columnNum(0), m_columnFirst(0), m_columnLast(0),
    m_viewWidget(Q_NULL), m_pageIndent(QtnScrollWidgetBarPageIndent), 
    m_margins(0, 0, 0, 0), 
    m_itemIndent(QtnScrollWidgetBarItemIndent),
    m_maxViewItemCount(0)
{
    setFocusPolicy(Qt::WheelFocus);

    m_prevButton = new ScrollWidgetBarButton(this);
    connect(m_prevButton, SIGNAL(clicked()), this, SLOT(movePrev()));
    m_nextButton = new ScrollWidgetBarButton(this);
    connect(m_nextButton, SIGNAL(clicked()), this, SLOT(moveNext()));

    m_animation = new QPropertyAnimation(Q_NULL, "geometry");
    m_animation->setDuration(150);
    m_animation->setEasingCurve(QEasingCurve::InOutExpo /* QEasingCurve::OutCubic */);
    connect(m_animation, SIGNAL(finished()), this, SLOT(scrollAnimationFinished()));
}

AbstractScrollWidgetBar::~AbstractScrollWidgetBar()
{
    Q_DELETE_AND_NULL(m_animation);
    Q_DELETE_AND_NULL(m_viewWidget);
    Q_DELETE_AND_NULL(m_prevButton);
    Q_DELETE_AND_NULL(m_nextButton);
}

Qt::Orientation AbstractScrollWidgetBar::orientation() const
{
    return m_orientation;
}

void AbstractScrollWidgetBar::setOrientation(Qt::Orientation orientation)
{
    m_orientation = orientation;
}

QWidget* AbstractScrollWidgetBar::createViewWidget()
{
    QWidget* ret = new QWidget(this);
    ret->setAttribute(Qt::WA_NoSystemBackground, true);
    return ret;
}

QWidget* AbstractScrollWidgetBar::viewWidget() const
{
    if (m_viewWidget == Q_NULL)
    {
        AbstractScrollWidgetBar* bar = const_cast<AbstractScrollWidgetBar *>(this);
        bar->m_viewWidget = bar->createViewWidget();
        m_animation->setTargetObject(bar->m_viewWidget);
    }
    return m_viewWidget;
}

int AbstractScrollWidgetBar::pageIndent() const
{
    return m_pageIndent;
}

void AbstractScrollWidgetBar::setPageIndent(int indent)
{
    m_pageIndent = indent;
}

const QMargins& AbstractScrollWidgetBar::margins() const
{
    return m_margins;
}

void AbstractScrollWidgetBar::setMargins(const QMargins& margins)
{
    m_margins = margins;
}

/*!
* Returns indent between items.
*/
int AbstractScrollWidgetBar::itemIndent() const
{
    return m_itemIndent;
}

/*!
* Sets \a indent between items.
*/
void AbstractScrollWidgetBar::setItemIndent(int indent)
{
    if (m_itemIndent == indent)
        return;
    m_itemIndent = indent;
}

void AbstractScrollWidgetBar::setAmimationSettings(int duration, const QEasingCurve& curve)
{
    m_animation->setDuration(duration);
    m_animation->setEasingCurve(curve);
}

int AbstractScrollWidgetBar::maxViewItemCount() const
{
    return m_maxViewItemCount;
}

void AbstractScrollWidgetBar::setMaxViewItemCount(int count)
{
    m_maxViewItemCount = count;
}

QSize AbstractScrollWidgetBar::sizeHint() const
{
    QSize ret = QSize(0, 0);

    int count = 0;
    for (int i = 0; i < getColumnCount(); ++i)
    {
        /*QWidget* widget = *it;
        if (widget->isHidden())
            continue;*/

        QSize s = getColumnSize(i);

        if (orientation() == Qt::Horizontal)
        {
            ret.rheight() = qMax(ret.height(), s.height());
            if (maxViewItemCount() <= 0 || maxViewItemCount() > count)
            {
                if (ret.width() > 0)
                    ret.rwidth() += itemIndent();
                ret.rwidth() += s.width();
            }
        }
        else
        {
            ret.rwidth() = qMax(ret.width(), s.width());
            if (maxViewItemCount() <= 0 || maxViewItemCount() > count)
            {
                if (ret.height() > 0)
                    ret.rheight() += itemIndent();
                ret.rheight() += s.height();
            }
        }
        count++;
    }

    if (orientation() == Qt::Horizontal)
    {
        ret.rwidth() += pageIndent() * 2;
    }
    else
    {
        ret.rheight() += pageIndent() * 2;
    }

    ret.rwidth() += margins().left() + margins().right();
    ret.rheight() += margins().top() + margins().bottom();

    return ret;
}

/*! \reimp */
void AbstractScrollWidgetBar::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    updateLayout();
}

/*! \reimp */
void AbstractScrollWidgetBar::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
#if 0
    QPainter painter(this);
    QRect r = QRect(0, 0, width(), height());
    painter.fillRect(r, /*palette().color(backgroundRole())*/QColor(255, 0, 0, 20));
#endif
}

/*! \reimp */
void AbstractScrollWidgetBar::keyPressEvent(QKeyEvent* event)
{
    if (event->type() == QEvent::KeyPress)
    {
        int key = event->key();
        bool _prev = (orientation() == Qt::Horizontal && key == Qt::Key_Left) || (orientation() == Qt::Vertical && key == Qt::Key_Up);
        bool _next = (orientation() == Qt::Horizontal && key == Qt::Key_Right) || (orientation() == Qt::Vertical && key == Qt::Key_Down);
        if (_prev)
            movePrev();
        else if (_next)
            moveNext();
    }
}

/*! \reimp */
void AbstractScrollWidgetBar::wheelEvent(QWheelEvent* event)
{
    if (orientation() != event->orientation())
        return;
    int d = event->delta();
    if (d < 0)
        moveNext();
    else
        movePrev();
    event->accept();
}

void AbstractScrollWidgetBar::setPrevButtonVisible(bool visible)
{
    if (visible)
    {
        QRect r;
        QSize s = m_prevButton->sizeHint();
        if (orientation() == Qt::Horizontal)
        {
            s.rheight() = height();
            r = QStyle::alignedRect(Qt::LeftToRight, Qt::AlignLeft | Qt::AlignTop, s, QRect(0, 0, this->width(), this->height()));
        }
        else
        {
            s.rwidth() = width();
            r = QStyle::alignedRect(Qt::LeftToRight, Qt::AlignTop | Qt::AlignLeft, s, QRect(0, 0, this->width(), this->height()));
        }
        m_prevButton->setGeometry(r);
        m_prevButton->raise();
    }
    m_prevButton->setVisible(visible);
}

void AbstractScrollWidgetBar::setNextButtonVisible(bool visible)
{
    if (visible)
    {
        QSize s = m_nextButton->sizeHint();
        QRect r;
        if (orientation() == Qt::Horizontal)
        {
            s.rheight() = height();
            r = QStyle::alignedRect(Qt::LeftToRight, Qt::AlignRight | Qt::AlignTop, s, QRect(0, 0, this->width(), this->height()));
        }
        else
        {
            s.rwidth() = width();
            r = QStyle::alignedRect(Qt::LeftToRight, Qt::AlignBottom | Qt::AlignLeft, s, QRect(0, 0, this->width(), this->height()));
        }
        m_nextButton->setGeometry(r);
        m_nextButton->raise();
    }
    m_nextButton->setVisible(visible);
}

void AbstractScrollWidgetBar::scrollAnimationFinished()
{
    updateLayout();
}

void AbstractScrollWidgetBar::movePrev()
{
    if (m_prevButton->isHidden() || m_animation->state() == QAbstractAnimation::Running)
        return;

    m_columnNum = calcNextColumn(m_columnNum, true);
    startScrollAnimation();
}

void AbstractScrollWidgetBar::moveNext()
{
    if (m_nextButton->isHidden() || m_animation->state() == QAbstractAnimation::Running)
        return;

    m_columnNum = calcNextColumn(m_columnNum, false);
    startScrollAnimation();
}

void AbstractScrollWidgetBar::moveTo(int column)
{
    int first = 0;
    int last = calcNextColumn(0, false);

    while (true)
    {
        last = calcNextColumn(first, false);
        if (first == last)
            break;
        if (first <= column && last > column)
        {
            m_columnNum = first;
            startScrollAnimation();
            break;
        }
        first = last;
    }
}

int AbstractScrollWidgetBar::getColumnLength(int column) const
{
    if (orientation() == Qt::Horizontal)
        return getColumnSize(column).width();
    else
        return getColumnSize(column).height();
}

QColor AbstractScrollWidgetBar::getButtonColor() const
{
    return QColor();
}

int AbstractScrollWidgetBar::calcColumnsLength(int columnCount) const
{
    int ret = 0;
    for (int i = 0; i < columnCount; ++i)
        ret += getColumnLength(i);
    return ret;
}

bool AbstractScrollWidgetBar::isColumnFirst(int first) const
{
    return m_columnNum > first;
}

bool AbstractScrollWidgetBar::isColumnLast(int last) const
{
    return m_columnLast < last;
}

void AbstractScrollWidgetBar::ensureVisible(int column)
{
    int last = m_columnLast;
    if (last > m_columnFirst)
        --last;
    if (m_columnFirst <= column && column <= last)
        return;
    moveTo(column);
}

int AbstractScrollWidgetBar::calcNextColumn(int column, bool back) const
{
    int w = orientation() == Qt::Horizontal ? width() - pageIndent() : height() - pageIndent();
    bool first = true;
    while (w > 0)
    {
        if (back)
        {
            if (column == 0)
                break;
        }
        else
        {
            if (column == getColumnCount())
                break;
        }

        w -= (getColumnLength(column) + itemIndent());

        if (w < 0 && !first)
            break;

        first = false;

        if (back)
            column--;
        else
            column++;

        /*if (back)
        {
        if (column == 0)
        break;
        column--;
        }
        else
        {
        if (column == getColumnCount())
        break;
        column++;
        }*/
    }
    return column;
}

QPoint AbstractScrollWidgetBar::getViewOffset() const
{
    int columnsLen = calcColumnsLength(m_columnNum) + itemIndent() * m_columnNum;
    QPoint offset = orientation() == Qt::Horizontal ? QPoint(-columnsLen, 0) : QPoint(0, -columnsLen);
    return offset;
}

void AbstractScrollWidgetBar::startScrollAnimation()
{
    QRect rect = viewWidget()->geometry();
    m_animation->setStartValue(rect);
    rect.moveTo(getViewOffset());
    m_animation->setEndValue(rect);
    m_animation->start();
    updateLayout();
}

void AbstractScrollWidgetBar::updateLayout()
{
    bool prevVisible = m_columnNum > 0;
    int columnNum = calcNextColumn(m_columnNum, false);
    m_columnFirst = m_columnNum;
    m_columnLast = columnNum;

    bool nextVisible = columnNum < getColumnCount();

    QPoint offset = getViewOffset();

    int columnsLength = calcColumnsLength(getColumnCount());
    QSize s = sizeHint();
    QRect viewRect = orientation() == Qt::Horizontal ? 
        QRect(offset, QSize(pageIndent() * 2 + columnsLength + itemIndent() * (getColumnCount() - 1) + margins().left() + margins().right(), s.height())) :
        QRect(offset, QSize(s.width(), pageIndent() * 2 + columnsLength + itemIndent() * (getColumnCount() - 1) + margins().top() + margins().bottom()));
    viewWidget()->setGeometry(viewRect);

    setPrevButtonVisible(prevVisible);
    setNextButtonVisible(nextVisible);
}

/* ScrollWidgetBar */
ScrollWidgetBar::ScrollWidgetBar(QWidget* parent, Qt::Orientation orientation)
    : AbstractScrollWidgetBar(parent, orientation), m_updateCount(0)
{
}

ScrollWidgetBar::~ScrollWidgetBar()
{
}

void ScrollWidgetBar::addWidget(QWidget* widget)
{
    beginUpdate();
    widget->setParent(viewWidget());
    m_widgets.push_back(widget);
    endUpdate();
}

void ScrollWidgetBar::removeWidget(QWidget* widget)
{
    beginUpdate();
    int i = m_widgets.indexOf(widget);
    if (i >= 0)
        m_widgets.remove(i);
    endUpdate();
}

void ScrollWidgetBar::beginUpdate()
{
    m_updateCount++;
}

void ScrollWidgetBar::endUpdate()
{
    Q_ASSERT(m_updateCount > 0);
    m_updateCount--;
    if (m_updateCount == 0)
        updateItemsLayout();
}

QWidget* ScrollWidgetBar::getWidget(int index) const
{
    return m_widgets[index];
}

int ScrollWidgetBar::getWidgetCount() const
{
    return m_widgets.size();
}

int ScrollWidgetBar::getColumnCount() const
{
    return m_widgets.size();
}

QSize ScrollWidgetBar::getColumnSize(int column) const
{
    return m_widgets[column]->sizeHint();
}

int ScrollWidgetBar::getColumnIndex(QWidget* widget) const
{
    return m_widgets.indexOf(widget);
}

void ScrollWidgetBar::updateItemsLayout()
{
    if (m_updateCount > 0)
        return;

    QPoint topLeft = QPoint(0, 0);
    QPoint offset = orientation() == Qt::Horizontal ? 
        QPoint(pageIndent(), 0) : QPoint(0, pageIndent());
    offset += QPoint(margins().left(), margins().top());

    for (QVector<QWidget *>::iterator it = m_widgets.begin(); it != m_widgets.end(); ++it)
    {
        QWidget* widget = *it;
        if (widget->isHidden())
            continue;

        QSize s = widget->sizeHint();

        QRect rect = QRect(offset + topLeft, s);
        widget->setGeometry(rect);

        if (orientation() == Qt::Horizontal)
            topLeft.rx() += itemIndent() + s.width();
        else
            topLeft.ry() += itemIndent() + s.height();
    }
}

bool ScrollWidgetBar::focusNextPrevChild(bool next)
{
    QWidget* w = focusWidget();
    int index = m_widgets.indexOf(w);
    if (index == -1)
    {
        index = next ? 0 : getWidgetCount() - 1;
    }
    else
    {
        index = next ? index + 1 : index - 1;
    }
 
    if (index >= 0 && index < getWidgetCount())
    {
        w = m_widgets[index];
        w->setFocus(next ? Qt::TabFocusReason : Qt::BacktabFocusReason);
        ensureVisible(getColumnIndex(w));
        return true;
    }

    return AbstractScrollWidgetBar::focusNextPrevChild(next);


}

/* ScrollWidgetBarButton */
ScrollWidgetBarButton::ScrollWidgetBarButton(AbstractScrollWidgetBar* bar)
    : QAbstractButton(bar)
{
    setMouseTracking(true);
    setFocusPolicy(Qt::NoFocus);
}

ScrollWidgetBarButton::~ScrollWidgetBarButton()
{
}

QSize ScrollWidgetBarButton::sizeHint() const
{
#if 0
    AbstractScrollWidgetBar* bar = qobject_cast<AbstractScrollWidgetBar *>(parentWidget());
    if (bar != Q_NULL)
        return QSize(bar->pageIndent(), bar->pageIndent());
#endif
    int size = QtnScrollWidgetBarPageIndent;
    int val = style()->pixelMetric((QStyle::PixelMetric)CommonStyle::PM_BaseScrollButtonItem, Q_NULL, this);
    if (val > 0)
        size = val;
    return QSize(size, size);
}

void ScrollWidgetBarButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    AbstractScrollWidgetBar* bar = qobject_cast<AbstractScrollWidgetBar *>(parentWidget());
    if (bar == Q_NULL)
        return;
    QPainter painter(this);
    QStyleOptionToolButton opt;
    opt.initFrom(this);

    if (isDown())
        opt.state |= QStyle::State_Sunken;

    QColor color = bar->getButtonColor();
    if (color.isValid())
    {
        opt.palette.setColor(QPalette::Window, color);
        opt.palette.setColor(QPalette::Highlight, color.darker());
    }

    if (bar->orientation() == Qt::Horizontal)
        opt.arrowType = bar->m_prevButton == this ? Qt::LeftArrow : Qt::RightArrow;
    else
        opt.arrowType = bar->m_prevButton == this ? Qt::UpArrow : Qt::DownArrow;
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonGroupScrollButton, &opt, &painter, this);
}

void ScrollWidgetBarButton::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    update();
}

void ScrollWidgetBarButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    update();
}

void ScrollWidgetBarButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    update();
}
