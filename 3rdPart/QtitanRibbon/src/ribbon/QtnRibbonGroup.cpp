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
#include <QPainter>
#include <QLineEdit>
#include <QComboBox>
#include <QToolBar>
#include <QAbstractItemView>

#include "QtnRibbonGroup.h"
#include "QtnRibbonPage.h"
#include "QtnRibbonPagePrivate.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonGallery.h"
#include "QtnRibbonPrivate.h"
#include "QtnOfficePopupMenu.h"
#include "QtnRibbonGroupPrivate.h"
#include "QtnRibbonControlsPrivate.h"
#include "QtnRibbonButtonPrivate.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnOfficePopupColorButton.h"
#include "QtnRibbonButtonControls.h"
#include "QtnRibbonGalleryControls.h"
#include "QtnRibbonInputControls.h"
#include "QtnCommonStylePrivate.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

#define ADDITIVE_WIDTH 20

/*!
\property RibbonGroup::reduced
Returns true if the group is in the reduced mode.
*/

/*!
\property RibbonGroup::title
Holds the title of the group.
*/

/*!
\property RibbonGroup::titleFont
Holds the font that used to render the group title.
*/

/*!
\property RibbonGroup::titleColor
Holds the color that used to render the group title.
*/

/*!
\property RibbonGroup::icon
Holds the icon for the group title.
*/

/*!
\property RibbonGroup::spacing
Holds the spacing between the items inside the group in pixels.
*/

/*!
\property RibbonGroup::optionButtonVisible
Specifies the visibility of the option button for the group. The button is visible by default.
*/

/*!
\property RibbonGroup::contentAlignment
Specifies the alignment of the group content items.
*/

/*!
\property RibbonGroup::titleElideMode
Specifies is how to shorten the group title text if it does not fit in width.
*/

static void setSizeDefinitionByStyle(RibbonButtonControl* control, Qt::ToolButtonStyle style)
{
    if (Qt::ToolButtonTextUnderIcon == style)
    {
        control->sizeDefinition(RibbonControlSizeDefinition::GroupLarge)->setImageSize(RibbonControlSizeDefinition::ImageLarge);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupMedium)->setLabelVisible(true);
    }
    else if (Qt::ToolButtonTextBesideIcon == style)
    {
        control->sizeDefinition(RibbonControlSizeDefinition::GroupLarge)->setImageSize(RibbonControlSizeDefinition::ImageSmall);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupPopup)->setImageSize(RibbonControlSizeDefinition::ImageSmall);
    }
    else if (Qt::ToolButtonIconOnly == style)
    {
        control->sizeDefinition(RibbonControlSizeDefinition::GroupLarge)->setImageSize(RibbonControlSizeDefinition::ImageSmall);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupPopup)->setImageSize(RibbonControlSizeDefinition::ImageSmall);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupLarge)->setLabelVisible(false);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupMedium)->setLabelVisible(false);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupSmall)->setLabelVisible(false);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupPopup)->setLabelVisible(false);
    }
}


/* RibbonButtonAction */
class RibbonButtonAction : public QWidgetAction
{
public:
    explicit RibbonButtonAction(QObject* parent, const QIcon& icon, const QString& text, Qt::ToolButtonStyle style, 
        QMenu* menu, QToolButton::ToolButtonPopupMode mode = QToolButton::DelayedPopup);
    virtual ~RibbonButtonAction();
protected:
    virtual QWidget* createWidget(QWidget* parent);
private:
    Qt::ToolButtonStyle m_style;
    QToolButton::ToolButtonPopupMode m_mode;
};

RibbonButtonAction::RibbonButtonAction(QObject* parent, const QIcon& icon, const QString& text, Qt::ToolButtonStyle style, 
                                       QMenu* menu, QToolButton::ToolButtonPopupMode mode)
    : QWidgetAction(parent)
    , m_style(style)
    , m_mode(mode)
{
    setIcon(icon);
    setText(text);
    setMenu(menu);
}

RibbonButtonAction::~RibbonButtonAction()
{
}

QWidget* RibbonButtonAction::createWidget(QWidget* parent)
{
    if (QToolBar* toolBar = qobject_cast<QToolBar*>(parent))
    {
        RibbonButton* button = new RibbonButton(parent);
        button->setAutoRaise(true);
        button->setFocusPolicy(Qt::NoFocus);
        button->setIconSize(toolBar->iconSize());
        button->setToolButtonStyle(toolBar->toolButtonStyle());
        QObject::connect(toolBar, SIGNAL(iconSizeChanged(QSize)), button, SLOT(setIconSize(QSize)));
        QObject::connect(toolBar, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), button, SLOT(setToolButtonStyle(Qt::ToolButtonStyle)));
        button->setDefaultAction(this); 
        QObject::connect(button, SIGNAL(triggered(QAction*)), toolBar, SIGNAL(actionTriggered(QAction*)));
        return button;
    }
    else if (RibbonGroup* ribbonGroup = qobject_cast<RibbonGroup*>(parent))
    {
        RibbonButtonControl* control = new RibbonButtonControl(ribbonGroup);
        ::setSizeDefinitionByStyle(control, m_style);
        control->setDefaultAction(this);
        control->setToolButtonStyle(m_style);
        if (menu())
        {
            control->setPopupMode(m_mode);
            control->setMenu(menu());
            menu()->setDefaultAction(this);
        }
        return control;
    }
    return Q_NULL;
}


/* RibbonGroupPrivate */
RibbonGroupPrivate::RibbonGroupPrivate()
    : m_optionButton(Q_NULL)
    , m_buttonScrollGroupLeft(Q_NULL)    // Button to draw left scroll
    , m_buttonScrollGroupRight(Q_NULL)   // Button to draw right scroll
    , m_groupPopupWidget(Q_NULL)
    , m_toolBar(Q_NULL)
    , m_currentSize(RibbonControlSizeDefinition::GroupLarge)
    , m_contentAlignment(Qt::AlignTop)
    , m_controlsAlignment(Qt::AlignVCenter)
    , m_spacing(0)
    , m_butOptionVisible(false)
    , m_dirty(false)
    , m_actOption(Q_NULL)
    , m_font(Q_NULL)
    , m_pageScrollPos(0)
    , m_groupScrollPos(0)  // Scroll position
    , m_titleElideMode(Qt::ElideRight)
{
}

RibbonGroupPrivate::~RibbonGroupPrivate()
{
    Q_DELETE_AND_NULL(m_groupPopupWidget);
    Q_DELETE_AND_NULL(m_font);
}

void RibbonGroupPrivate::init()
{
    QTN_P(RibbonGroup);
    p.setMouseTracking(true);
    p.setProperty(_qtn_TitleGroupsVisible, true);

    m_buttonScrollGroupLeft = new RibbonGroupScrollButton(&p, true);
    m_buttonScrollGroupLeft->setVisible(false);

    m_buttonScrollGroupRight = new RibbonGroupScrollButton(&p, false);
    m_buttonScrollGroupRight->setVisible(false);

    QObject::connect(m_buttonScrollGroupLeft, SIGNAL(pressed()), this, SLOT(pressLeftScrollButton()));
    QObject::connect(m_buttonScrollGroupRight, SIGNAL(pressed()), this, SLOT(pressRightScrollButton()));

    m_optionButton = new RibbonGroupOption(&p);
    m_actOption = new QAction(&p);
    m_actOption->setObjectName(QStringLiteral("__qtn_Action_Option"));
    m_optionButton->setDefaultAction(m_actOption);
    QObject::connect(m_optionButton, SIGNAL(triggered(QAction*)), &p, SIGNAL(actionTriggered(QAction*)));
    m_optionButton->hide();
}

void RibbonGroupPrivate::clear(bool deleteControls)
{
    QTN_P(RibbonGroup);
    if (p.isControlsGrouping())
    {
        m_toolBar->clear();
        return;
    }

    QList<QAction*> actions = p.actions();
    for (int i = 0; i < actions.size(); ++i)
        p.removeAction(actions.at(i));

    while (m_controls.size() > 0)
    {
        RibbonControl* control = m_controls[0];
        if (RibbonWidgetControl* widgetcontrol = qobject_cast<RibbonWidgetControl*>(control))
            widgetcontrol->qtn_d().clearWidget();

        p.removeControl(control);

        if (deleteControls)
            delete control;
    }
}

void RibbonGroupPrivate::enableGroupScroll(bool scrollLeft, bool scrollRight)
{
    QTN_P(RibbonGroup);

    Q_ASSERT(m_buttonScrollGroupLeft);
    Q_ASSERT(m_buttonScrollGroupRight);

    if (!m_buttonScrollGroupRight || !m_buttonScrollGroupLeft)
        return;

    const RibbonBar* rb = p.ribbonBar();
    Q_ASSERT(rb != NULL);

    const int heightGroup = rb->rowItemHeight() * rb->rowItemCount();

    QRect rcGroup(p.geometry());
    rcGroup.setHeight(heightGroup + 4);

    if (scrollLeft)
    {
        m_buttonScrollGroupLeft->raise();
        m_buttonScrollGroupLeft->setVisible(true);
        m_buttonScrollGroupLeft->setGeometry(QRect(QPoint(rcGroup.left() - 1, rcGroup.top()), QPoint(rcGroup.left() + 12, rcGroup.bottom())));
    }
    else
        m_buttonScrollGroupLeft->setVisible(false);

    if (scrollRight)
    {
        m_buttonScrollGroupRight->raise();
        m_buttonScrollGroupRight->setVisible(true);
        m_buttonScrollGroupRight->setGeometry(QRect(QPoint(rcGroup.right() - 12, rcGroup.top()), QPoint(rcGroup.right() + 1, rcGroup.bottom())));
    }
    else
        m_buttonScrollGroupRight->setVisible(false);
}

void RibbonGroupPrivate::showGroupScroll()
{
    QTN_P(RibbonGroup);
    if (p.isReduced() && p.isVisible())
    {
        QRect screen = qtn_availableGeometry(&p);
        int totalWidth = p.layout()->minimumSize().width();
        int groupLength = screen.width();
        int scrollPos = m_groupScrollPos;

        if (totalWidth > groupLength)
        {
            if (scrollPos > totalWidth - groupLength)
                scrollPos = totalWidth - groupLength;
        }
        else
            scrollPos = 0;

        if (scrollPos < 0) 
            scrollPos = 0;

        m_groupScrollPos = scrollPos;
        enableGroupScroll(scrollPos > 0, totalWidth - groupLength - scrollPos > 0);
    }
}

void RibbonGroupPrivate::initStyleOption(RibbonGroupStyleOption& opt) const
{
    QTN_P(const RibbonGroup)
    opt.init(&p);
    if (RibbonPage* page = qobject_cast<RibbonPage *>(p.parentWidget()))
        opt.pageColor = page->contextColor();
    opt.text = m_title;
    opt.widthOptButton = m_optionButton->isVisible() ? m_optionButton->width() : 0;
    opt.fontMetrics = m_font ? QFontMetrics(*m_font) : opt.fontMetrics;
    opt.heightCaption = p.style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonHeightCaptionGroup), &opt, &p);
    opt.textAlignment = Qt::AlignCenter;
    opt.textElideMode = m_titleElideMode;
    if (m_colorText.isValid())
        opt.palette.setColor(QPalette::WindowText, m_colorText);
}

int RibbonGroupPrivate::calcMinimumWidth(RibbonControlSizeDefinition::GroupSize size) const
{
    QTN_P(const RibbonGroup)

    QStyleOptionToolButton opt;
    opt.init(&p);
    opt.text = m_title;
    opt.icon = m_icon;
    int width = p.style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonReducedGroupWidth), &opt, &p);

    if (size == RibbonControlSizeDefinition::GroupSmall)
        width += 1;
    else if (size == RibbonControlSizeDefinition::GroupMedium)
        width += 2;
    else if (size == RibbonControlSizeDefinition::GroupLarge)
        width += 3;
    return width;
}

int RibbonGroupPrivate::arrangeRowContent(QList<RibbonControl*>& row, int leftOffset, int rowItemHeight, int rowItemCount, QWidget* parent) const
{
    QTN_P(const RibbonGroup)
    static int margin = 4;

    int max = 0;
    int rowHeight = rowItemHeight;
    int topOffset = 0;

    if (p.contentAlignment() & Qt::AlignVCenter)
        topOffset = (rowItemHeight * (rowItemCount - row.size())) * 0.5;
    else if (p.contentAlignment() & Qt::AlignBottom)
        topOffset = rowItemHeight * (rowItemCount - row.size());

    for (QList<RibbonControl*>::const_iterator it = row.constBegin(); it != row.constEnd(); ++it)
        max = qMax((*it)->sizeHint().width(), max);

    if (parent == Q_NULL)
    {
        row.clear();
        return max;
    }

    topOffset += margin / 2;
    leftOffset += margin;

    for (QList<RibbonControl*>::const_iterator it = row.constBegin(); it != row.constEnd(); ++it)
    {
        QSize size = (*it)->sizeHint();
        size.rheight() = qMax(rowHeight, size.height());
        const bool stretchable = (*it)->sizeDefinition((*it)->currentSize())->isStretchable();
        QRect r = QRect(leftOffset, topOffset, max, rowHeight);
        size.rwidth() = stretchable ? max : size.width();

        QRect controlRect = QStyle::alignedRect(p.layoutDirection(), p.contentAlignment(), size, r);
        (*it)->setGeometry(controlRect);
        topOffset += rowHeight;
    }
    row.clear();
    return max;
}

void RibbonGroupPrivate::reposition(const QRect& rect)
{
    QTN_P(RibbonGroup)
    QSize sz(rect.width(), p.sizeHint().height());
    p.setGeometry(QRect(rect.topLeft(), sz));
    if (!p.isReduced())
    {
#ifdef QTITAN_DESIGNER
        if (RibbonBar* ribbonBar = p.ribbonBar())
        {
            if (ribbonBar->isMinimized())
                p.setFixedSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
            QSize sz = rect.size();
            if (!sz.isEmpty() && !ribbonBar->isMinimized())
                p.setFixedSize(sz);
        }
#endif // QTITAN_DESIGNER
    }
}

void RibbonGroupPrivate::updateOptionButtonLayout(QWidget* parent)
{
    QTN_P(RibbonGroup);
    if (parent != Q_NULL)
        m_optionButton->setParent(parent);

    m_optionButton->setVisible(p.isOptionButtonVisible());
    if (!m_optionButton->isHidden())
    {
        RibbonGroupStyleOption opt;
        initStyleOption(opt);
        if (parent && !qobject_cast<RibbonGroup*>(parent))
            opt.rect.setSize(parent->sizeHint());
        QRect rc = opt.rect;
        rc.setTop(rc.bottom() - opt.heightCaption);
        int space = CommonStylePrivate::dpiScaled(8, &p);
        QSize sz(opt.heightCaption - space, opt.heightCaption - space);
        space = CommonStylePrivate::dpiScaled(2, &p);
        QRect rectButOption(QPoint(rc.right() - sz.width() - space, rc.top() + (rc.height() - sz.height()) / 2), sz);
        m_optionButton->setGeometry(QStyle::visualRect(p.layoutDirection(), p.geometry(), rectButOption));
    }
}

QSize RibbonGroupPrivate::updateControlsLayout(QWidget* parent, int leftOffset) const
{
    QTN_P(const RibbonGroup);

    const RibbonBar* rb = p.ribbonBar();
    if (rb == Q_NULL)
        return QSize();

    static int margin = 4;
    const int maxRows = rb->rowItemCount(); // Get max row count from RibbonBar here. 
    const int rowItemHeight = rb->rowItemHeight();

    QList<RibbonControl *> rowControls;
    QList<RibbonControl *> controls = m_controls;

    std::sort(controls.begin(), controls.end(), RibbonGroupPrivate::visualIndexLessThan);

    RibbonControl* lastControl = controls.size() > 0 ? controls.last() : Q_NULL;
    for (QList<RibbonControl *>::const_iterator it = controls.constBegin(); it != controls.constEnd(); ++it)
    {
        RibbonControl* ribbonControl = *it;
        RibbonColumnBreakControl* sepatator = qobject_cast<RibbonColumnBreakControl *>(ribbonControl);
        bool visible = ribbonControl->sizeDefinition(ribbonControl->currentSize())->isVisible();
        if (ribbonControl->defaultAction() != Q_NULL)
            visible = visible && ribbonControl->defaultAction()->isVisible();
        if (parent != Q_NULL)
        {
            ribbonControl->setParent(parent);
            if (sepatator == Q_NULL)
                ribbonControl->setVisible(visible);
            else
                ribbonControl->setVisible(visible && sepatator->sizeDefinition(sepatator->currentSize())->showSeparator());
        }

        if (!visible)
            continue;

        ribbonControl->updateLayout();
        QSize sizeHint = ribbonControl->sizeHint();
        if (sepatator != Q_NULL || sizeHint.height() > rowItemHeight)
        {
            if (rowControls.size() > 0)
                leftOffset += arrangeRowContent(rowControls, leftOffset, rowItemHeight, maxRows, parent);

            if (sepatator != Q_NULL)
            {
                if (!sepatator->sizeDefinition(sepatator->currentSize())->showSeparator())
                    sizeHint = QSize(0, 0);
            }

            if (parent != Q_NULL)
            {
                int maxHeight = sizeHint.height();
                if (maxHeight > rowItemHeight * maxRows)
                    maxHeight = rowItemHeight * maxRows;
                else
                    maxHeight = qMax(rowItemHeight, sizeHint.height());

                ribbonControl->setGeometry(QRect(leftOffset + margin, margin / 2, sizeHint.width(), maxHeight));
            }
            leftOffset += sizeHint.width();
            if (lastControl != ribbonControl)
                leftOffset += m_spacing;
        }
        else 
        {
            rowControls.append(ribbonControl);
            if (rowControls.size() >= maxRows)
            {
                leftOffset += arrangeRowContent(rowControls, leftOffset, rowItemHeight, maxRows, parent);
                if (lastControl != ribbonControl)
                    leftOffset += m_spacing;
            }
        }
    }

    if (rowControls.size() > 0)
        leftOffset += arrangeRowContent(rowControls, leftOffset, rowItemHeight, maxRows, parent);

    leftOffset += (margin * 2 + 1);

    return QSize(leftOffset, rowItemHeight * maxRows);
}

void RibbonGroupPrivate::adjustCurrentSize(bool expand)
{
    for (QList<RibbonControl *>::const_iterator it = m_controls.constBegin(); it != m_controls.constEnd(); ++it)
        (*it)->adjustCurrentSize(expand);
}

void RibbonGroupPrivate::updateLayoutParent()
{
    QTN_P(RibbonGroup);
    if (RibbonPage* page = qobject_cast<RibbonPage *>(p.parentWidget()))
    {
        page->updateLayout();
        p.update();
    }
}

Qt::TextElideMode RibbonGroupPrivate::titleTextElideMode() const
{
    QTN_P(const RibbonGroup);
    return p.property(_qtn_TitleGroupsVisible).toBool() ? m_titleElideMode : Qt::ElideLeft;
}

/*! \reimp */
QSize RibbonGroupPrivate::sizeHint() const
{
    QTN_P(const RibbonGroup);

    const RibbonBar* rb = p.ribbonBar();
    if (rb == Q_NULL)
        return QSize();

    RibbonGroupStyleOption opt;
    initStyleOption(opt);

    QSize size = updateControlsLayout(Q_NULL);
    int minWidth = calcMinimumWidth(p.currentSize());
    if (minWidth > size.width())
        size.rwidth() = minWidth;

    const int heightGroup = qMax(rb->rowItemHeight() * rb->rowItemCount(), size.height());
    const int heightCaptionGroup = opt.heightCaption;

    QSize textSize = opt.fontMetrics.size(Qt::TextShowMnemonic, p.title());
    textSize.rwidth() += qtn_horizontalAdvanceFont(opt.fontMetrics, QLatin1Char(' ')) * 4;

    int buttonWidth = 0;
    if (p.isOptionButtonVisible())
        buttonWidth = m_optionButton->/*sizeHint().*/width();
    textSize.rwidth() += buttonWidth;

    if (p.minimumWidth() == 0)
        size.rwidth() = titleTextElideMode() == Qt::ElideNone ? qMax(textSize.width(), size.width()) : size.width();
    else
        size.rwidth() = qMax(p.minimumWidth(), size.width());

    if (p.isMinimized() && !p.isHidden())
    {
        QRect screen = qtn_availableGeometry(&p);
        size.rwidth() = qMin(screen.width(), size.width());
    }

    size.setHeight(heightGroup + heightCaptionGroup + 2 * 2);
    return size;
}

void RibbonGroupPrivate::setReductionSize(RibbonControlSizeDefinition::GroupSize size)
{
    if (m_currentSize == size)
        return;
    
    m_currentSize = size;

    for (QList<RibbonControl *>::const_iterator it = m_controls.constBegin(); it != m_controls.constEnd(); ++it)
        (*it)->sizeChanged(size);
}

void RibbonGroupPrivate::reduce()
{
    Q_ASSERT(canReduce());
    setReductionSize(static_cast<RibbonControlSizeDefinition::GroupSize>(m_currentSize + 1));
}

void RibbonGroupPrivate::expand()
{
    Q_ASSERT(canExpand());
    setReductionSize(static_cast<RibbonControlSizeDefinition::GroupSize>(m_currentSize - 1));
}

bool RibbonGroupPrivate::canReduce()
{
    return m_currentSize < RibbonControlSizeDefinition::GroupPopup;
}

bool RibbonGroupPrivate::canExpand()
{
    return m_currentSize > RibbonControlSizeDefinition::GroupLarge;
}

RibbonGroupPopupMenu* RibbonGroupPrivate::groupPopupWidget()
{
    QTN_P(RibbonGroup);
    if (m_groupPopupWidget == Q_NULL)
    {
        m_groupPopupWidget = new RibbonGroupPopupMenu(&p);
        m_groupPopupWidget->setFocusPolicy(Qt::NoFocus);
        QObject::connect(m_groupPopupWidget, SIGNAL(aboutToHide()), &p, SLOT(update()));
    }
    return m_groupPopupWidget;
}

static void listPageWidth(int totalWidth, int realWidth, QList<int>& pagesWidth) 
{
    if (totalWidth > realWidth)
    {
        pagesWidth << realWidth;
        listPageWidth(totalWidth - realWidth, realWidth, pagesWidth);
    }
    else
        pagesWidth << totalWidth;
    return;
}

void RibbonGroupPrivate::pressLeftScrollButton()
{
    QTN_P(RibbonGroup)
    QList<int> pagesWidth;
    listPageWidth(p.layout()->sizeHint().width(), p.geometry().width(), pagesWidth);

    if (0 < m_pageScrollPos)
        m_pageScrollPos--; 

    m_groupScrollPos -= pagesWidth[m_pageScrollPos];
    showGroupScroll();
    p.layout()->update();
}

void RibbonGroupPrivate::pressRightScrollButton()
{
    QTN_P(RibbonGroup)
    QList<int> pagesWidth;
    listPageWidth(p.layout()->sizeHint().width(), p.geometry().width(), pagesWidth);

    m_groupScrollPos += pagesWidth[m_pageScrollPos];
    showGroupScroll();
    p.layout()->update();

    if (pagesWidth.size() - 1 > m_pageScrollPos)
        m_pageScrollPos++; 
}

void RibbonGroupPrivate::hidePopupMode(QAction* action)
{
    Q_UNUSED(action);
    QTN_P(RibbonGroup)
    p.setVisible(false);
}

bool RibbonGroupPrivate::visualIndexLessThan(RibbonControl* first, RibbonControl* second)
{
    int v1 = first->sizeDefinition(first->currentSize())->visualIndex();
    if (v1 == -1)
    {
        RibbonGroup* group = first->parentGroup();
        v1 = group->qtn_d().m_controls.indexOf(first);
    }

    int v2 = second->sizeDefinition(second->currentSize())->visualIndex();
    if (v2 == -1)
    {
        RibbonGroup* group = second->parentGroup();
        v2 = group->qtn_d().m_controls.indexOf(second);
    }
    return v1 < v2;
}

RibbonBar* RibbonGroup::ribbonBar() const
{
    if (RibbonPage* page = qobject_cast<RibbonPage *>(parentWidget()))
        return page->ribbonBar();
    return Q_NULL;
}

/*!
\class RibbonGroup
\inmodule QtitanRibbon
\brief RibbonGroup class implements a group of items that is hosted within RibbonPage.
*/

/*!
Constructs RibbonGroup object with the given \a page and \a title.
*/
RibbonGroup::RibbonGroup(RibbonPage* page, const QString& title)
    : QWidget(page)
{
    QTN_INIT_PRIVATE(RibbonGroup);
    QTN_D(RibbonGroup);
    d.init();
    setTitle(title);
}

/*!
Constructs RibbonGroup object with the given \a parent.
*/
RibbonGroup::RibbonGroup(QWidget* parent)
    : QWidget(parent)
{
    QTN_INIT_PRIVATE(RibbonGroup);
    QTN_D(RibbonGroup);
    d.init();
}

/*!
Destructor of the RibbonGroup object.
*/
RibbonGroup::~RibbonGroup()
{
    QTN_D(RibbonGroup);
    d.clear(true);
    QTN_FINI_PRIVATE();
}

/*!
Returns true if the group is reduced.
*/ 
bool RibbonGroup::isReduced() const
{
    QTN_D(const RibbonGroup);
    if (d.m_controls.size() == 1)
    {
        if (!d.m_controls.at(0)->sizeDefinition(RibbonControlSizeDefinition::GroupLarge)->isStretchable())
            return false;
    }
    return d.m_currentSize == RibbonControlSizeDefinition::GroupPopup;
}

/*!
Returns the title of the group.
*/ 
const QString& RibbonGroup::title() const
{
    QTN_D(const RibbonGroup);
    return d.m_title;
}

/*!
Sets the \a title for the group.
 */
void RibbonGroup::setTitle(const QString& title)
{
    QTN_D(RibbonGroup);
    if (d.m_title == title)
        return;
    d.m_title = title;
    d.updateLayoutParent();
    emit titleChanged(d.m_title);
}

/*!
Returns the title font of the group.
*/ 
const QFont& RibbonGroup::titleFont() const
{
    QTN_D(const RibbonGroup);
    return d.m_font != Q_NULL ? *d.m_font : font();
}

/*!
Sets the \a title font for the group.
 */
void RibbonGroup::setTitleFont(const QFont& font)
{
    QTN_D(RibbonGroup);
    if (d.m_font && *d.m_font == font)
        return;
    Q_DELETE_AND_NULL(d.m_font);
    d.m_font = new QFont(font);
    d.updateLayoutParent();
    emit titleFontChanged(*d.m_font);
}

/*!
Returns the title color of the group.
*/ 
const QColor& RibbonGroup::titleColor() const
{
    QTN_D(const RibbonGroup);
    return d.m_colorText;
}

/*!
Sets the \a title color for the group.
 */
void RibbonGroup::setTitleColor(const QColor& color)
{
    QTN_D(RibbonGroup);
    if (d.m_colorText == color)
        return;
    d.m_colorText = color;
    update();
}

/*!
Returns the icon of the group.
*/ 
const QIcon& RibbonGroup::icon() const
{
    QTN_D(const RibbonGroup);
    return d.m_icon;
}

/*!
Sets the \a icon for the group.
 */
void RibbonGroup::setIcon(const QIcon& icon)
{
    QTN_D(RibbonGroup);
    d.m_icon = icon;
    d.updateLayoutParent();
}

/*!
Returns the visible state for the option button used in the caption of the group.
*/
bool RibbonGroup::isOptionButtonVisible() const
{
    QTN_D(const RibbonGroup);
    return d.m_butOptionVisible && property(_qtn_TitleGroupsVisible).toBool();
}

/*!
Sets the visible state for the option button used in the group caption.
Notes: Option button is usually used to start the dialogue associated with the group.
*/
void RibbonGroup::setOptionButtonVisible(bool visible)
{
    QTN_D(RibbonGroup);
    if (d.m_butOptionVisible == visible)
        return;
    d.m_butOptionVisible = visible;
    d.updateLayoutParent();
}


/*!
Returns the pointer to action associated with the option button. 
Notes: Use this action if you want to initialize tooltips, the text in the status bar (StatusTip), icons or for to define custom events.
*/ 
QAction* RibbonGroup::optionButtonAction() const
{
    QTN_D(const RibbonGroup);
    return d.m_actOption;
}

/*!
  Sets the given \a action for the option button of the group. Option button is a small button on the bottom of the group. If action is not set then the option button is not visible.
*/ 
void RibbonGroup::setOptionButtonAction(QAction* action)
{
    QTN_D(RibbonGroup);
    if ( d.m_actOption != Q_NULL )
        delete d.m_actOption;
    d.m_actOption = action;
    d.m_optionButton->setDefaultAction(d.m_actOption);
}

/*!
Returns the enum that describes the ribbon control alignment for the control's column within the given group. 
*/
Qt::Alignment RibbonGroup::contentAlignment() const
{
    QTN_D(const RibbonGroup);
    return d.m_contentAlignment;
}

/*!
Sets the enum that describes the ribbon control alignment for the control's column within the given group.
*/
void RibbonGroup::setContentAlignment(Qt::Alignment alignment)
{
    QTN_D(RibbonGroup);
    if (d.m_contentAlignment == alignment)
        return;
    d.m_contentAlignment = alignment;
    d.updateLayoutParent();
}

/*!
Returns the alignment of block ribbon controls if width of the all controls is more than minmum width of the group.
*/
Qt::Alignment RibbonGroup::controlsAlignment() const
{
    QTN_D(const RibbonGroup);
    return d.m_controlsAlignment;
}

/*!
Sets the alignment of the block ribbon controls.
*/
void RibbonGroup::setControlsAlignment(Qt::Alignment alignment)
{
    QTN_D(RibbonGroup);
    if (d.m_controlsAlignment == alignment)
        return;
    d.m_controlsAlignment = alignment;
    d.updateLayoutParent();
}

/*!
Returns the spacing between the items inside the group.
*/
int RibbonGroup::spacing() const
{
    QTN_D(const RibbonGroup);
    return d.m_spacing;
}

/*!
Sets the spacing between the items inside the group.
*/
void RibbonGroup::setSpacing(int spacing)
{
    QTN_D(RibbonGroup);
    if (d.m_spacing == spacing)
        return;
    d.m_spacing = spacing;
    d.updateLayoutParent();
}

/*!
Returns the count of ribbon controls within the group.
\sa controlByWidget, controlByIndex, controlByAction
*/
int RibbonGroup::controlCount() const
{
    QTN_D(const RibbonGroup);
    return d.m_controls.size();
}

/*!
Sets the feature controls centering to \a enabled.

\sa setContentAlignment()
*/
void RibbonGroup::setControlsCentering(bool enabled)
{
    QTN_D(RibbonGroup);
    if (enabled)
        d.m_contentAlignment = Qt::AlignVCenter;
    else
        d.m_contentAlignment = Qt::Alignment();
    d.updateLayoutParent();
}

/*!
Returns the value of the feature controls centering.
*/
bool RibbonGroup::isControlsCentering() const
{
    QTN_D(const RibbonGroup);
    return d.m_contentAlignment.testFlag(Qt::AlignVCenter);
}

/*!
Sets the feature grouping controls to \a enabled.
*/
void RibbonGroup::setControlsGrouping(bool enabled)
{
    QTN_D(RibbonGroup);
    if (enabled)
    {
        if (isControlsGrouping())
            return;
        d.m_toolBar = new RibbonToolBarControl(this);
        addControl(d.m_toolBar);
    }
    else
    {
        if (d.m_toolBar != Q_NULL)
            removeControl(d.m_toolBar);
        Q_DELETE_AND_NULL(d.m_toolBar);
    }
}

/*!
Returns the value of the feature grouping controls.
*/
bool RibbonGroup::isControlsGrouping() const
{
    QTN_D(const RibbonGroup);
    return d.m_toolBar != Q_NULL;
}

/*!
Returns the ribbon control by \a index.
\sa controlByWidget, controlByIndex, controlByAction
*/
RibbonControl* RibbonGroup::controlByIndex(int index) const
{
    QTN_D(const RibbonGroup);
    return d.m_controls[index];
}

/*!
Returns the ribbon control by \a action.
\sa controlCount, controlByIndex, controlByWidget
*/
RibbonControl* RibbonGroup::controlByAction(QAction* action) const
{
    QTN_D(const RibbonGroup);
    Q_ASSERT(action != Q_NULL);
    for (QList<RibbonControl *>::const_iterator it = d.m_controls.constBegin(); it != d.m_controls.constEnd(); ++it)
    {
        if ((*it)->defaultAction() == action)
            return *it;
    }
    return Q_NULL;
}

/*!
Returns the widget ribbon control by \a widget.
\sa controlCount, controlByIndex, controlByAction
*/
RibbonWidgetControl* RibbonGroup::controlByWidget(QWidget* widget) const
{
    QTN_D(const RibbonGroup);
    Q_ASSERT(widget != Q_NULL);
    for (QList<RibbonControl *>::const_iterator it = d.m_controls.constBegin(); it != d.m_controls.constEnd(); ++it)
    {
        if (RibbonWidgetControl* widgetControl = qobject_cast<RibbonWidgetControl*>((*it)))
        {
            if (widgetControl->contentWidget() == widget)
                return widgetControl;
        }
    }
    return Q_NULL;
}

RibbonControlSizeDefinition::GroupSize RibbonGroup::currentSize() const
{
    QTN_D(const RibbonGroup);
    return d.m_currentSize;
}

/*!
Adds the ribbon \a control to the group. In most cases you have to use addAction to create and add ribbon control. 
*/
void RibbonGroup::addControl(RibbonControl* control)
{
    QTN_D(RibbonGroup);
    if (d.m_controls.indexOf(control) != -1)
        return; // Already was added. 

    control->qtn_d().m_parentGroup = this;
    d.m_controls.append(control);
    control->sizeChanged(currentSize());
    d.updateLayoutParent();
}

/*!
Removes the ribbon \a control from the group.
*/
void RibbonGroup::removeControl(RibbonControl* control)
{
    QTN_D(RibbonGroup);
    if (d.m_controls.removeAll(control) > 0)
    {
        control->qtn_d().m_parentGroup = Q_NULL;
        control->setParent(Q_NULL);
        d.updateLayoutParent();
    }
}

/*!
  Creates and adds the action to the group with the given \a icon, \a text and \a style. If you specify the parameter \a menu, then will be constructed a special split button which will allow to cause this menu. Parameter \a mode defines the mode of the popup emerging.
*/ 
QAction* RibbonGroup::addAction(const QIcon& icon, const QString& text, Qt::ToolButtonStyle style, 
                                QMenu* menu, QToolButton::ToolButtonPopupMode mode)
{
    QTN_D(const RibbonGroup);

    if (isControlsGrouping())
        return d.m_toolBar->addAction(icon, text, style, menu, mode);

    RibbonButtonAction* action = new RibbonButtonAction(this, icon, text, style, menu, mode);
    addAction(action);
    return action;
}

/*!
  Adds the \a action to the group with the given parameters \a style, \a menu and \a mode.
*/ 
QAction* RibbonGroup::addAction(QAction* action, Qt::ToolButtonStyle style, QMenu* menu, QToolButton::ToolButtonPopupMode mode)
{
    QTN_D(RibbonGroup);

    if (isControlsGrouping())
        return d.m_toolBar->addAction(action, style, menu, mode);

    addAction(action);

    RibbonButtonControl* control = qobject_cast<RibbonButtonControl*>(controlByAction(action));
    Q_ASSERT(control != Q_NULL);

    control->setToolButtonStyle(style);
    if (menu || action->menu())
        control->setPopupMode(mode);
    if (menu)
        control->setMenu(menu);

    return action;
}

/*!
  Adds \a action before other action that specified in \a before argument. In result action's widget will be placed before widget that is associated with action \a before. 
*/ 
QAction* RibbonGroup::insertAction(QAction* before, QAction* action, Qt::ToolButtonStyle style, QMenu* menu, QToolButton::ToolButtonPopupMode mode)
{
    QTN_D(RibbonGroup);

    if (isControlsGrouping())
        return d.m_toolBar->insertAction(before, action, style, menu, mode);

    insertAction(before, action);

    RibbonButtonControl* control = qobject_cast<RibbonButtonControl*>(controlByAction(action));
    Q_ASSERT(control != Q_NULL);

    control->setToolButtonStyle(style);
    if (menu || action->menu())
        control->setPopupMode(mode);
    if (menu)
        control->setMenu(menu);

    return action;
}

/*!
Adds the \a widget to the group. As alternative can be created QWidgetAction and added it via addAction method.  
*/
QAction* RibbonGroup::addWidget(QWidget* widget)
{
    QTN_D(RibbonGroup);
    if (isControlsGrouping())
        return d.m_toolBar->addWidget(widget);
    return addWidget(QIcon(), QString(), widget);
}

/*!
Overloaded method. Adds the \a widget to the group with given \a icon and \a text. As alternative can be created QWidgetAction and added it via addAction method.
*/
QAction* RibbonGroup::addWidget(const QIcon& icon, const QString& text, QWidget* widget)
{
    QTN_D(RibbonGroup);

    if (isControlsGrouping())
        return d.m_toolBar->addWidget(icon, text, widget);

    QWidgetAction* action = new QWidgetAction(this);
    action->setIcon(icon);
    action->setText(text);

    RibbonWidgetControl* control = new RibbonWidgetControl(this, false);
    control->setContentWidget(widget);
    control->setDefaultAction(action);
    action->setDefaultWidget(control);
    addAction(action);

    return action;
}

/*!
Overloaded method. Adds the \a widget to the group with given \a icon and \a text.
Parameter \a stretch specifies a the ability to adjust the ribbon control which corresponds to the widget
on the control's column width within the group.
*/
QAction* RibbonGroup::addWidget(const QIcon& icon, const QString& text, bool stretch, QWidget* widget)
{
    QTN_D(RibbonGroup);

    if (isControlsGrouping())
        return d.m_toolBar->addWidget(icon, text, widget);

    QAction* action = addWidget(icon, text, widget);
    if (stretch)
    {
        RibbonControl* control = controlByAction(action);
        Q_ASSERT(control != Q_NULL);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupLarge)->setStretchable(true);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupMedium)->setStretchable(true);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupSmall)->setStretchable(true);
        control->sizeDefinition(RibbonControlSizeDefinition::GroupPopup)->setStretchable(true);
    }
    return action;
}

/*!
Adds the ribbon button with the given \a icon and \a text that holds the QMenu.
Note, parameter \a style can be any value of type Qt::ToolButtonStyle except Qt::ToolButtonFollowStyle. 
In the case of Qt::ToolButtonFollowStyle will be used Qt::ToolButtonTextUnderIcon instead.
*/
QMenu* RibbonGroup::addMenu(const QIcon& icon, const QString& text, Qt::ToolButtonStyle style)
{
    QTN_D(RibbonGroup);

    QMenu* menu = new QMenu(text, this);
    if (isControlsGrouping())
    {
        d.m_toolBar->addMenu(icon, text, menu, QToolButton::InstantPopup);
    }
    else
    {
        RibbonButtonAction* action = new RibbonButtonAction(this, icon, text, style, menu, QToolButton::InstantPopup);
        addAction(action);
    }
    return menu;
}

/*!
Adds a separator action to the given group.
*/
QAction* RibbonGroup::addSeparator()
{
    QTN_D(RibbonGroup);

    if (isControlsGrouping())
        return d.m_toolBar->addSeparator();

    QAction*action = new QAction(this);
    action->setSeparator(true);
    addAction(action);
    return action;
}

/*!
Removes ribbon control from the group which corresponds to the \a widget.
*/
void RibbonGroup::remove(QWidget* widget)
{
    if (isControlsGrouping())
    {
        Q_ASSERT(false);
        //d.m_toolBar->removeWidget(widget);
        return;
    }

    if (!widget)
        return;

    if (RibbonWidgetControl* widgetcontrol = controlByWidget(widget))
        widgetcontrol->qtn_d().clearWidget();

    QList<QAction*> actions = this->actions();
    for (int i = 0; i < actions.size(); i++)
    {
        if (QWidgetAction* widgetAction = qobject_cast<QWidgetAction*>(actions.at(i)))
        {
            if (widgetAction->defaultWidget() == widget)
            {
                removeAction(actions.at(i));
                return;
            }
        }
    }
}

/*!
Removes all ribbon controls from the given group.
*/
void RibbonGroup::clear()
{
    QTN_D(RibbonGroup);
    d.clear(false);
}

/*!
Returns the enum where ellipsis should be added for group title.
\sa setTitleElideMode
*/
Qt::TextElideMode RibbonGroup::titleElideMode() const
{
    QTN_D(const RibbonGroup);
    return d.m_titleElideMode;
}

/*!
Sets the enum where ellipsis should be added for group title.
The \a mode parameter affects the calculation of the width of the group and can take the following values:
\table
\row
\li Qt::ElideLeft
\li The text of the group name has an ellipsis on the left. The width of the group will be equal to the width of the content of the group depending on RibbonControlSizeDefinition::GroupSize.
\row
\li Qt::ElideRight
\li The text of the group name has an ellipsis on the right. The width of the group will be equal to the width of the content of the group depending on RibbonControlSizeDefinition::GroupSize.
\row
\li Qt::ElideMiddle
\li The text of the group name has an ellipsis on the middle. The width of the group will be equal to the width of the content of the group depending on RibbonControlSizeDefinition::GroupSize.
\row
\li Qt::ElideNone
\li The text of the group name occupies the entire width of the group and does not have ellipses. The group width will be equal to the maximum width of the group content depending on the RibbonControlSizeDefinition::GroupSize or text length.
\endtable
*/
void RibbonGroup::setTitleElideMode(Qt::TextElideMode mode)
{
    QTN_D(RibbonGroup);
    if (d.m_titleElideMode != mode)
    {
        d.m_titleElideMode = mode;
        d.updateLayoutParent();
    }
}

/*!
Returns the recommended size for RibbonGroup.
\reimp
*/
QSize RibbonGroup::sizeHint() const
{
    QTN_D(const RibbonGroup);
    QSize size = d.sizeHint();
    if (isReduced())
    {
        QStyleOptionToolButton opt;
        opt.init(this);
        opt.text = d.m_title;
        opt.icon = d.m_icon;
        return QSize(style()->pixelMetric(static_cast<QStyle::PixelMetric>(CommonStyle::PM_RibbonReducedGroupWidth),
                                          &opt, this), size.height());
    }
    else
        return size.expandedTo(QApplication::globalStrut());
}

void RibbonGroup::currentIndexChanged(int index)
{
    Q_UNUSED(index);
    if (isVisible())
    {
        bool doReleased = true;
        QComboBox* comboBox = qobject_cast<QComboBox*>(sender());
        if (comboBox)
        {
            QAbstractItemView* itemView = comboBox->view();
            if (itemView && !itemView->isVisible())
                doReleased = false;
        }
        if (doReleased)
            emit released();
    }
}

static void qtn_set_font_to_group_children(RibbonGroup* group, const QFont& font)
{
    for (int i = 0, count = group->controlCount(); count > i; ++i)
    {
        if (RibbonControl* control = group->controlByIndex(i))
        { 
            control->setFont(font);
            qtn_set_font_to_ribbon_children(control, font);
        }
    }
}

/*! \reimp */
bool RibbonGroup::event(QEvent* event)
{
    QTN_D(RibbonGroup);
    if (d.m_dirty && event->type() == QEvent::LayoutRequest)
    {
        d.updateLayoutParent();
        d.groupPopupWidget()->hide();
        d.m_dirty = false;
    }

    switch (event->type())
    {
        case QEvent::ChildAdded:
            {
                QChildEvent* e = static_cast<QChildEvent *>(event);
                if (e->added())
                {
                    QWidget* widget = qobject_cast<QWidget *>(e->child());
                    if (widget != Q_NULL)
                    {
#ifdef RIBBON_FONT_SET
                        QFont f = font();
#else
                        QFont f = QFont();
#endif
                        widget->setFont(f);
                        qtn_set_font_to_ribbon_children(widget, f);
                    }
                }
            }
            break;
        case QEvent::StyleChange:
        case QEvent::FontChange:
        {
#ifdef RIBBON_FONT_SET
            QFont f = font();
#else
            QFont f = QFont();
#endif
            qtn_set_font_to_group_children(this, f);
        }
        break;
        default:
            break;
    }

    if (isMinimized())
    {
        if (event->type() == QEvent::Show)
            d.showGroupScroll();
        else if (event->type() == QEvent::Hide)
        {
            d.m_groupScrollPos = 0;
            d.m_pageScrollPos = 0;
            layout()->update();
            if (windowFlags() & Qt::Popup)
                emit hidePopup();
        }
    }
    else
    {
        switch(event->type())
        {
            case QEvent::KeyPress :
                {
                    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
                    if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
                    {
                        if (QWidget* focus = focusWidget())
                        {
                            if (qobject_cast<QComboBox*>(focus) || qobject_cast<QLineEdit*>(focus))
                                emit released();
                        }
                    }
                }
                break;
            case QEvent::Show :
            case QEvent::Hide :
                    updateGeometry();
                break;
            case QEvent::ParentChange :
                break;
            default:
                break;
        }
    }
    return QWidget::event(event);
}

/*! \reimp */
void RibbonGroup::paintEvent(QPaintEvent* event)
{
    QTN_D(RibbonGroup);
    QPainter p(this);
    if (isReduced())
    {
        RibbonGroupReducedStyleOption opt;
        opt.initFrom(this);
        opt.text = d.m_title;
        opt.icon = d.m_icon;
        static int sz = style()->pixelMetric(QStyle::PM_SmallIconSize, &opt, this);
        opt.iconSize = QSize(sz, sz);

        opt.subControls = QStyle::SC_ToolButton;
        opt.activeSubControls = QStyle::SC_None;

        if (RibbonPage* page = qobject_cast<RibbonPage *>(parentWidget()))
            opt.pageColor = page->contextColor();

        if (!d.groupPopupWidget()->isHidden())
        {
            opt.state |= QStyle::State_Sunken;
            opt.features |= QStyleOptionToolButton::HasMenu;
        }
        else if (underMouse())
            opt.state |= QStyle::State_MouseOver;

        QRect rcGroup = opt.rect;
        rcGroup.setBottom(rcGroup.bottom() - 2);
        opt.rect = rcGroup;
        style()->drawControl(static_cast<QStyle::ControlElement>(CommonStyle::CE_RibbonReducedGroup), &opt, &p, this);
    }
    else
    {
        QRect rectEvent = event->rect();
        p.setClipRect(rectEvent);

        if (windowFlags() & Qt::Popup)
        {
            RibbonStyleOption opt;
            opt.init(this);
            if (RibbonPage* page = qobject_cast<RibbonPage *>(parentWidget()))
                opt.pageColor = page->contextColor();
            style()->drawPrimitive(static_cast<QStyle::PrimitiveElement>(CommonStyle::PE_RibbonFrameGroups), &opt, &p, this);
        }

        RibbonGroupStyleOption opt;
        d.initStyleOption(opt);
        if (rectEvent.intersects(opt.rect))
            style()->drawPrimitive(static_cast<QStyle::PrimitiveElement>(CommonStyle::PE_RibbonFrameGroup), &opt, &p, this);

        QFont saveFont = p.font();
        // Set the font to draw the group name
        if (d.m_font != Q_NULL)
            p.setFont(*d.m_font);
        if (property(_qtn_TitleGroupsVisible).toBool())
            style()->drawControl(static_cast<QStyle::ControlElement>(CommonStyle::CE_RibbonGroupLabel), &opt, &p, this);
        p.setFont(saveFont);
    }
}

/*! \reimp */
void RibbonGroup::actionEvent(QActionEvent* event)
{
    QTN_D(RibbonGroup);

    QAction* action = event->action();
    RibbonControl* control = controlByAction(action);

    switch (event->type()) 
    {
        case QEvent::ActionAdded: 
        {
            if (control == Q_NULL)
            {
                if (QWidgetAction* widgetAction = qobject_cast<QWidgetAction*>(action)) 
                {
                    QWidget* widget = widgetAction->requestWidget(this);
                    if (widget != Q_NULL) 
                    {
                        control = qobject_cast<RibbonControl*>(widget);
                        if (control == Q_NULL)
                        {
                            RibbonWidgetControl* widgetControl = new RibbonWidgetControl(this, false);
                            widgetControl->setContentWidget(widget);
                            control = widgetControl;
                            control->setDefaultAction(action);
                            widgetAction->setDefaultWidget(control);
                        }
                    }
                    else
                    {
                        Q_ASSERT(false);
                        return;
                    }
                }
                else if (action->isSeparator())
                    control = new RibbonColumnBreakControl(this);

                if (control == Q_NULL)
                    control = new RibbonButtonControl(this);

                control->setDefaultAction(action);
                addControl(control);
            }
        }
        break;
        case QEvent::ActionRemoved:
        {
            if (control != Q_NULL)
            {
                removeControl(control);
                if (QWidgetAction* widgetAction = qobject_cast<QWidgetAction*>(action))
                {
                    bool forceDelete = false;
                    if (widgetAction->defaultWidget() == control)
                        widgetAction->releaseWidget(control);
                    else if (RibbonWidgetControl* widgetControl = qobject_cast<RibbonWidgetControl*>(control))
                    {
                        if (QWidget* contentWidget = widgetControl->contentWidget())
                        {
                            widgetAction->releaseWidget(contentWidget);
                            if (widgetAction->defaultWidget() == contentWidget)
                                forceDelete = true;
                        }
                    }

                    if (forceDelete || widgetAction->defaultWidget() == Q_NULL)
                        delete control;
                }
                else
                {
                    control->hide();
                    delete control;
                }
            }
        }
        break;
        case QEvent::ActionChanged:
            {
                Q_ASSERT(control != Q_NULL);
                if (control != Q_NULL)
                    control->actionChanged();
                d.m_dirty = true;
                QApplication::postEvent(this, new QEvent(QEvent::LayoutRequest));
                break;
            }
        default:
            Q_ASSERT_X(false, "RibbonGroup::actionEvent", "internal error");
    }
}

/*! \reimp */
void RibbonGroup::enterEvent(QEvent* event)
{
    Q_UNUSED(event);
    update();
}

/*! \reimp */
void RibbonGroup::leaveEvent( QEvent* event )
{
    Q_UNUSED(event);
    update();
}

/*! \reimp */
void RibbonGroup::mousePressEvent(QMouseEvent* event)
{
    QTN_D(RibbonGroup);
    if (isReduced())
    {
        if (event->button() == Qt::LeftButton) 
        {
            QPoint pnt(0, 0);
            QRect rc = rect();

            QRect screen = qtn_availableGeometry(this);
            int h = rc.height();
            if (this->mapToGlobal(QPoint(0, rc.bottom())).y() + h <= screen.height()) 
                pnt = this->mapToGlobal(rc.bottomLeft());
            else 
                pnt = this->mapToGlobal(rc.topLeft() - QPoint(0, h));

            const int desktopFrame = style()->pixelMetric(QStyle::PM_MenuDesktopFrameWidth, Q_NULL, this);
            if (pnt.x() + rc.width() - 1 > screen.right() - desktopFrame)
                pnt.setX(screen.right() - desktopFrame - rc.width() + 1);
            if (pnt.x() < screen.left() + desktopFrame)
                pnt.setX(screen.left() + desktopFrame);

            d.groupPopupWidget()->popup(pnt, Q_NULL);
            return;
        }
    }
    QWidget::mousePressEvent(event);
}

