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
#include <QMainWindow>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QWindow>
#endif
#include <QStyleOption>
#include <QPainter>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QLayout>
#include <QWidgetAction>
#include <qevent.h>
#include <QTranslator>

#include <QtnPlatform.h>
#include "QtnRibbonPrivate.h"
#include "QtnStyleHelperPrivate.h"
#include "QtnStyleOption.h"
#include "QtnToolTip.h"
#include "QtnCommonStylePrivate.h"
#include "QtnRibbonButtonPrivate.h"
#include "QtnRibbonBarPrivate.h"
#include "QtnRibbonSystemMenu.h"
#include "QtnRibbonBackstageView.h"
#include "QtnRibbonBackstageViewPrivate.h"
#include "QtnRibbonKeyTipPrivate.h"
#include "QtnRibbonGroup.h"
#include "QtnRibbonGallery.h"
#include "QtnRibbonCustomizeManager.h"
#include "QtnRibbonPagePrivate.h"
#include "QtnRibbonDef.h"
#include "QtnOfficePopupMenu.h"

#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

const QString strCustomizeQAToolBar = QStringLiteral("customizeQAToolBar");
const QString strCustomizeRibbonBar = QStringLiteral("customizeRibbonBar");

static void qtn_fixupQtMainLayout(RibbonBar* ribbonBar)
{
    Q_UNUSED(ribbonBar);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    QMainWindow* mainWindow = qobject_cast<QMainWindow*>(ribbonBar->parentWidget());
    if (mainWindow == Q_NULL)
        return;
    if (WindowTitleBar::find(mainWindow) == Q_NULL || !WindowTitleBar::find(mainWindow)->isVisible())
        return;
    QWidgetData* data = qt_qwidget_data(ribbonBar);
    Q_ASSERT(data != Q_NULL);
    data->crect.setRect(mainWindow->contentsMargins().left(), data->crect.top(),
                        mainWindow->width() - mainWindow->contentsMargins().left() - mainWindow->contentsMargins().right(),
                        data->crect.height());
#endif

#if 0
    bool old = testAttribute(Qt::WA_WState_Created);
    setAttribute(Qt::WA_WState_Created, false);
    resize(QSize(event->size().width() - 100, event->size().height()));
    setAttribute(Qt::WA_WState_Created, old);
    setAttribute(Qt::WA_PendingResizeEvent, false);
#endif
}


/*!
*/
LogotypeLabel::LogotypeLabel(QWidget* parent)
    : QLabel( parent )
    , m_alignment(Qt::AlignRight)
{
}

/*! \reimp */
void LogotypeLabel::paintEvent(QPaintEvent* event)
{
    bool visible = true;
    if (RibbonBar* ribbonBar = qobject_cast<RibbonBar*>(parentWidget()))
        visible = ribbonBar->isMaximized();

    if (!visible)
        return;

    QPainter p(this);
    RibbonStyleOption opt;
    opt.init(this);

    QRect rect = parentWidget()->geometry();
    if (m_alignment == Qt::AlignRight)
    {
        QPoint pnt = mapFromParent(rect.topLeft());
        opt.rect.setLeft(pnt.x());
        opt.rect.setWidth(rect.width());
    }
    else
        opt.rect.setWidth(rect.width());

    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonFrameGroups, &opt, &p, this);
    QLabel::paintEvent(event);
}


/*!
    \enum RibbonBar::QuickAccessBarPosition
    This enum describes the position of quick access bar widget on ribbon.
    \inmodule QtitanRibbon
    \value QATopPosition quick access bar is placed on the title (or the top) of the ribbon.
    \value QABottomPosition quick access bar is placed on the bottom of the ribbon.    
*/

/*!
\property RibbonBar::currentPageIndex
\inmodule QtitanRibbon
Holds the index of the current page.
*/

/*!
\property RibbonBar::minimized
\inmodule QtitanRibbon
Allows  to switch the Ribbon Bar to the minimized mode and back.
*/

RibbonBarPagePopup::RibbonBarPagePopup(RibbonBar* ribbonBar)
    : QWidget(ribbonBar, Qt::Popup), m_ribbonBar(ribbonBar)
{
}

/*! \internal */
RibbonBar* RibbonBarPagePopup::ribbonBar() const
{
    return m_ribbonBar;
}

/*! \reimp */
void RibbonBarPagePopup::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
}

/*! \reimp */
bool RibbonBarPagePopup::event(QEvent* event)
{
    switch (event->type())
    {
        case QEvent::Show:
        {
        }
        break;
#ifdef Q_OS_MAC
        case QEvent::Close:
        {
            if (event->spontaneous())
            {
                event->ignore();
                return true;
            }
        }
        break;
#endif
        case QEvent::Hide:
        {
            RibbonBar* _ribbonBar = ribbonBar();
            if (_ribbonBar == Q_NULL)
                break;
            _ribbonBar->update();
        }
        break;
        case QEvent::MouseButtonDblClick:
        case QEvent::MouseButtonPress:
        {
            RibbonBar* _ribbonBar = ribbonBar();
            if (_ribbonBar == Q_NULL)
                break;
            if (_ribbonBar->isMinimized())
            {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                QWidget* widget = QApplication::widgetAt(mouseEvent->globalPos());
                RibbonTab* tab = qobject_cast<RibbonTab *>(widget);
                if (tab != Q_NULL)
                {
                    if (mouseEvent->type() == QEvent::MouseButtonDblClick)
                        QMetaObject::invokeMethod(tab, "dblClicked", Qt::QueuedConnection);
                    else
                        QMetaObject::invokeMethod(tab, "clicked", Qt::QueuedConnection);
                    return true;
                }
            }
        }
        break;
        default:
        break;
    }
    return QWidget::event(event);
}

/*!
\class RibbonToolTipManager
\internal
*/
RibbonToolTipManager::RibbonToolTipManager(QObject* parent)
    : QObject(parent)
{
    qApp->installEventFilter(this);
}

RibbonToolTipManager::~RibbonToolTipManager()
{
    qApp->removeEventFilter(this);
}

/*! \internal */
bool RibbonToolTipManager::showToolTip(const QPoint& pos, QWidget* w)
{
    if (QtnPrivate::qtn_isAncestor(w, QTITAN_META_CLASSNAME("RibbonSystemMenu")))
        return true;
    if (QtnPrivate::qtn_isAncestor(w, "QDialog"))
        return false;
    if (!QtnPrivate::qtn_isAncestor(w, QTITAN_META_CLASSNAME("RibbonQuickAccessBar")) && !QtnPrivate::qtn_isAncestor(w, QTITAN_META_CLASSNAME("RibbonBar")))
        return false;

    QPoint p = pos;
    p += QPoint(2,
#ifdef Q_WS_WIN
        21
#else
        16
#endif
    );

    int posX = p.x();
    int posY = p.y();

    if (const RibbonGroup* group = qtn_getParentWidget<RibbonGroup>(w))
    {
        Q_UNUSED(group);
        posX = w->mapToGlobal(w->rect().topLeft()).x();

        if (QWidget* prevWidget = qtn_getPrevParentWidget<RibbonGroup>(w))
        {
            if (RibbonGallery* gallery = qobject_cast<RibbonGallery*>(w))
            {
                QRect rect = gallery->getDrawItemRect(gallery->selectedItem());
                posX = prevWidget->mapToGlobal(rect.topLeft()).x();
            }
            else
            {
                posX = prevWidget->mapToGlobal(prevWidget->rect().topLeft()).x();
                if (qobject_cast<RibbonToolBarControl*>(prevWidget))
                    posX = w->mapToGlobal(w->rect().topLeft()).x();
            }
        }
        if (group->windowFlags() & Qt::Popup)
            posY = group->mapToGlobal(group->rect().bottomRight()).y() + int(CommonStylePrivate::dpiScaled(2., w));
        else if (const RibbonPage* page = qtn_getParentWidget<RibbonPage>(w))
            posY = page->mapToGlobal(page->rect().bottomRight()).y() + int(CommonStylePrivate::dpiScaled(2., w));
    }

    QIcon icon;
    QString strTitleText;
    QString strTipText = w->toolTip();

    if (RibbonGallery* gallery = qobject_cast<RibbonGallery*>(w))
    {
        if (RibbonGalleryItem* item = gallery->item(gallery->selectedItem()))
        {
            QString str = item->toolTip();
            if (strTipText != str)
                strTipText = str;
        }
    }
    else if (strTipText.isEmpty())
    {
        QWidget* widget = w->parentWidget();

        if (!qobject_cast<RibbonGroup*>(widget))
        {
            if (RibbonPageSystemRecentFileList* recentFile = qobject_cast<RibbonPageSystemRecentFileList*>(w))
            {
                if (QAction* currentAction = recentFile->getCurrentAction())
                    strTipText = currentAction->data().toString();
            }
            else
            {
                while (widget)
                {
                    strTipText = widget->toolTip();
                    if (!strTipText.isEmpty())
                        break;
                    widget = widget->parentWidget();
                    if (qobject_cast<RibbonGroup*>(widget))
                        break;
                }
            }
        }
    }
    else if (QToolButton* button = qobject_cast<QToolButton*>(w))
    {
        icon = button->icon();
        QString str = button->text();
        if (strTipText != str)
            strTitleText = str;

        if (QAction * defAction = button->defaultAction())
        {
            QString strShortcuts;
            QKeySequence keySequence;
            QList<QKeySequence> lstShortcuts = defAction->shortcuts();

            foreach(keySequence, lstShortcuts)
            {
                QString strShortcutString = keySequence.toString(QKeySequence::NativeText);
                if (strShortcuts != QString())
                    strShortcuts += QStringLiteral(", ");
                strShortcuts += strShortcutString;
            }
            if (strShortcuts != QString())
            {
                if (strTitleText != QString())
                    strTitleText += QStringLiteral(" (") + strShortcuts + QStringLiteral(")");
                else
                    strTipText += QStringLiteral(" (") + strShortcuts + QStringLiteral(")");
            }
        }
    }

    if (!strTitleText.isEmpty() || !strTipText.isEmpty() || !icon.isNull())
    {
        QPoint globalPos(posX, posY);
        ToolTip::showToolTip(globalPos, strTitleText, strTipText, icon, w);
        return true;
    }
    return false;
}

/*! \reimp */
bool RibbonToolTipManager::eventFilter(QObject* watched, QEvent* event)
{
    switch (event->type())
    {
        case QEvent::ToolTip:
            if (QWidget* widget = qobject_cast<QWidget*>(watched))
            {
                if (showToolTip(static_cast<QHelpEvent*>(event)->globalPos(), widget))
                    return true;
            }
            break;
        default:
            break;
    }
    return QObject::eventFilter(watched, event);
}

CornerButtonsUpdater::CornerButtonsUpdater(RibbonBar* parent)
    : QObject(parent)
    , m_ribbon(parent)
{
    qApp->installEventFilter(this);
}
CornerButtonsUpdater::~CornerButtonsUpdater()
{
    qApp->removeEventFilter(this);
}

/*! \reimp */
bool CornerButtonsUpdater::eventFilter(QObject* watched, QEvent* event)
{
    if (qobject_cast<QMdiSubWindow*>(watched))
    {
        if (event->type() == QEvent::WindowStateChange)
        {
            QWindowStateChangeEvent* changeEvent = static_cast<QWindowStateChangeEvent*>(event);
            if (changeEvent->isOverride())
                RibbonBarPrivate::_get(m_ribbon)->layoutRibbon();
        }
    }
    return QObject::eventFilter(watched, event);
}


/* RibbonBarPrivate */
RibbonBarPrivate::RibbonBarPrivate()
    : m_heightTabs(-1)
    , m_ribbonItemHeight(24)
    , m_ribbonToolTipManager(Q_NULL)
    , m_ribbonTitleBarWidget(Q_NULL)
    , m_ribbonTabBar(Q_NULL)
    , m_pagePopupWidget(Q_NULL)
    , m_quickAccessBar(Q_NULL)
    , m_controlSystemButton(Q_NULL)
    , m_saveVisibleSysMenu(true)
    , m_showTitleAlways(true)
    , m_ribbonBarVisible(true)
    , m_minimizationEnabled(true)
    , m_minimized(false)
    , m_keyboardState(false)
    , m_altPressed(false)
    , m_keyTipsComplement(true)
    , m_keyTipsEnabled(true)
    , m_keyTipsShowing(false)
    , m_titleGroupsVisible(true)
    , m_keyboardFocusWidget(Q_NULL)
    , m_quickAccessBarPosition(RibbonBar::QATopPosition)
    , m_tabBarPosition(RibbonBar::TabBarTopPosition)
    , m_countKey(0)
    , m_hoveredSubControl(QStyle::SC_None)
    , m_activeSubControl(QStyle::SC_None)
    , m_customizeManager(Q_NULL)
    , m_customizeDialog(Q_NULL)
    , m_buttonsUpdater(Q_NULL)
    , m_oldDpi(0)
    , m_rowItemCount(3)
    , m_updateLayoutCount(0)
{
}

/*! \internal */
RibbonBarPrivate::~RibbonBarPrivate()
{
    deleteRibbonTitleBarWidget();
}

/*! \internal */
void RibbonBarPrivate::init()
{
    QTN_P(RibbonBar);
    CommonStyle::ensureStyle();
    p.ensurePolished();
    p.setNativeMenuBar(false);

    p.setAttribute(Qt::WA_Hover, true);
    p.setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum); 

    m_ribbonToolTipManager = new RibbonToolTipManager(this);
    m_ribbonTabBar = new RibbonTabBar(&p);
    m_ribbonTabBar->show();

    QObject::connect(m_ribbonTabBar, SIGNAL(currentChanged(int)), this, SLOT(currentTabBarChanged(int)), Qt::DirectConnection);
    QObject::connect(m_ribbonTabBar, SIGNAL(pageAboutToBeChanged(RibbonPage*, bool&)), &p, SIGNAL(pageAboutToBeChanged(RibbonPage*, bool&)), Qt::DirectConnection);
    m_pagePopupWidget = new RibbonBarPagePopup(&p);
    m_buttonsUpdater = new CornerButtonsUpdater(&p);

    createRibbonTitleBarWidget();
    m_logotypeLabel = new LogotypeLabel(&p);
    m_logotypeLabel->setVisible(false);
    p.setProperty(_qtn_TitleGroupsVisible, m_titleGroupsVisible);
//    p.setFont(QApplication::font("QMenuBar"));
    calcRibbonItemHeight();
}

/*! \internal */
void RibbonBarPrivate::calcRibbonItemHeight(bool calc)
{
    QTN_P(RibbonBar);
    QFont fontRegular = p.font();
    if (!calc)
    {
        int dpi = qRound(CommonStylePrivate::dpiScaled(1.0, &p) * 100.0);
        if (m_oldfontRegular == fontRegular && dpi == m_oldDpi)
            return;
        m_oldDpi = dpi;
    }

    QFontMetrics fm(fontRegular);
#if QTN_DEPRECATED_CODE
    int rowItemHeight = fm.height();
#else
    int rowItemHeight = fm.height() + ((fm.descent() + fm.ascent()) / 3) + 2;
#endif
    QLineEdit ed;
    ed.setAttribute(Qt::WA_MacSmallSize);
    ed.setFont(fontRegular);
    QSize sizeHint = ed.sizeHint();
    rowItemHeight = qMax(sizeHint.height(), rowItemHeight);

    QComboBox box1;
    box1.setAttribute(Qt::WA_MacSmallSize);
    box1.setFont(fontRegular);
    sizeHint = box1.sizeHint();
    rowItemHeight = qMax(sizeHint.height(), rowItemHeight);

    QComboBox box2;
    box2.setAttribute(Qt::WA_MacSmallSize);
    box2.setEditable(true); //Affects on MacOSX widget
    box2.setFont(fontRegular);
    sizeHint = box2.sizeHint();
    rowItemHeight = qMax(sizeHint.height(), rowItemHeight);

    QSpinBox box3;
    box3.setAttribute(Qt::WA_MacSmallSize);
    box3.setFont(fontRegular);
    sizeHint = box3.sizeHint();
    rowItemHeight = qMax(sizeHint.height(), rowItemHeight);
    m_ribbonItemHeight = rowItemHeight + CommonStylePrivate::dpiScaled(6, &p);
    m_oldfontRegular = fontRegular;
}

/*! \internal */
void RibbonBarPrivate::calcHeightItem()
{
    const int hFrame = 2;
    m_heightTabs = m_ribbonItemHeight + hFrame;
}

/*! \internal */
void RibbonBarPrivate::layoutRibbon()
{
    QTN_P(RibbonBar);
    /* In MacOSX the font has been selected in RibbonStyle::polish(), so we have non valid reference to the tabbar. */
    if (m_ribbonTabBar == Q_NULL)
        return;
    calcRibbonItemHeight();
    calcHeightItem();

    bool saveRibbonBarVisible = m_ribbonBarVisible;
    m_ribbonBarVisible = true;

    QStyleOption opt; opt.init(&p);
    const int vmargin = p.style()->pixelMetric(QStyle::PM_MenuBarVMargin, &opt, &p);
    int heightGroup = maxGroupHeight();
    const int tabsHeight = m_heightTabs;
    const int pageAreaHeight = heightGroup;

    const int quickAccessHeight = m_quickAccessBar ? m_quickAccessBar->sizeHint().height() : 0;

    bool frameThemeEnabled = p.isFrameThemeEnabled();
    bool showTitle = frameThemeEnabled || m_showTitleAlways;

    QRect rcTabBar(QPoint(0, 0), QSize(opt.rect.width(), tabsHeight));
    QRect pageRect(QPoint(0, tabsHeight - 1), QSize(opt.rect.width(), pageAreaHeight + vmargin * 2 + 1));

    if (p.tabBarPosition() == RibbonBar::TabBarBottomPosition)
    {
        rcTabBar.translate(0, pageRect.height() - 2);
        pageRect.translate(0, -tabsHeight);
    }

    if (showTitle && !p.isFrameThemeEnabled())
    {
        QRect rcTitle = QRect(QPoint(0, 0), QPoint(opt.rect.width(), p.titleBarHeight()));
        rcTabBar.translate(0, rcTitle.height());
        pageRect.translate(0, rcTitle.height());
        if (m_ribbonTitleBarWidget != Q_NULL)
            m_ribbonTitleBarWidget->setGeometry(rcTitle);
    }

    if (m_controlSystemButton && m_controlSystemButton->toolButtonStyle() == Qt::ToolButtonTextBesideIcon)
        m_controlSystemButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

    int corner = quickAccessHeight + tabsHeight;

    if (!m_controlSystemButton || m_controlSystemButton->toolButtonStyle() != Qt::ToolButtonFollowStyle)
    {
//        QSize szIcon = m_frameHelper ? m_frameHelper->sizeSystemIcon(titleBarOpt.icon, titleBarOpt.rect) : QSize(16, 16);
//        corner = 5 + (!titleBarOpt.icon.isNull() ? szIcon.width() : 0);
    }

    if (m_quickAccessBar && qobject_cast<RibbonBar*>(m_quickAccessBar->parentWidget()) && !m_quickAccessBar->isHidden())
    {
        QRect rcQuickAccess;
        QSize szBar = m_quickAccessBar->sizeHint();
        if (m_quickAccessBarPosition == RibbonBar::QATopPosition)
        {
            rcQuickAccess = QRect(QPoint(5 + corner, 0), szBar);
        }
        else if (m_quickAccessBarPosition == RibbonBar::QABottomPosition)
        {
            if (m_minimized)
                rcQuickAccess = QRect(QPoint(0, rcTabBar.bottom()), QPoint(pageRect.right(), rcTabBar.bottom() + quickAccessHeight));
            else if (m_tabBarPosition == RibbonBar::TabBarTopPosition)
                rcQuickAccess = QRect(QPoint(0, pageRect.bottom()), QPoint(pageRect.right(), pageRect.bottom() + quickAccessHeight));
            else if (m_tabBarPosition == RibbonBar::TabBarBottomPosition)
                rcQuickAccess = QRect(QPoint(0, rcTabBar.bottom() + 2), QPoint(pageRect.right(), rcTabBar.bottom() + quickAccessHeight + 2));
        }
        m_quickAccessBar->setGeometry(rcQuickAccess);
    }

    int left = 2;
    if (m_controlSystemButton)
    {
        left = 0;
        int top = 0;
        QSize szControl(corner, corner);
        if (p.tabBarPosition() == RibbonBar::TabBarBottomPosition && 
            m_controlSystemButton->toolButtonStyle() == Qt::ToolButtonFollowStyle)
        {
            top = pageRect.bottom() - m_controlSystemButton->sizeHint().height();
        }
        else if (m_controlSystemButton->toolButtonStyle() != Qt::ToolButtonFollowStyle)
        {
            szControl = m_controlSystemButton->sizeHint();
            szControl.setHeight(tabsHeight);
            top = rcTabBar.top() + (tabsHeight - szControl.height()) * 0.5;
        }
        else if (!showTitle)
        {
            szControl = m_controlSystemButton->sizeHint();
            top = rcTabBar.top() + (tabsHeight - szControl.height()) * 0.5;
        }
        else
        {
            if (m_ribbonTitleBarWidget != Q_NULL && m_controlSystemButton->toolButtonStyle() == Qt::ToolButtonFollowStyle)
            {
                int height = m_ribbonTitleBarWidget->sizeHint().height();
                if (height == 0)
                    height = p.style()->pixelMetric(QStyle::PM_TitleBarHeight, Q_NULL);
                int def = szControl.height() - (rcTabBar.height() + height);
                top = (rcTabBar.bottom() - szControl.height()) + def/* + 2*/;
            }
            szControl -= QSize(2, 2);
        }

        int add = p.tabBarPosition() == RibbonBar::TabBarBottomPosition ? 2 : 0;
        szControl.setHeight(szControl.height() - add);

        QRect rcControl(QPoint(left, top + add), szControl);
        left += szControl.width() - 1;
        m_controlSystemButton->raise();
        m_controlSystemButton->setGeometry(QStyle::visualRect(p.layoutDirection(), p.rect(), rcControl));
    }

    if (qobject_cast<RibbonBar*>(m_quickAccessBar->parentWidget()) && 
        !m_quickAccessBar->isHidden() && m_quickAccessBarPosition == RibbonBar::QATopPosition && !m_showTitleAlways)
    {
        left += m_quickAccessBar->width();
    }

    int right = opt.rect.width();
    if (left + 6 > right)
        rcTabBar = QRect(QPoint(0, rcTabBar.top()), QPoint(0, rcTabBar.bottom()));
    else
        rcTabBar = QRect(QPoint(left, rcTabBar.top()), QPoint(right, rcTabBar.bottom()));

    // It's needed to apply a width of the logo if exists.
    QRect logoRect = !m_logotypeLabel->isHidden() ? m_logotypeLabel->geometry() : QRect();
    if (!logoRect.isNull() && m_logotypeLabel->alignment() == Qt::AlignLeft)
        rcTabBar.setLeft(qMax(rcTabBar.left(), logoRect.width()));

    layoutCorner();
    m_ribbonTabBar->setGeometry(QStyle::visualRect(p.layoutDirection(), p.rect(), rcTabBar));
    m_ribbonTabBar->layoutWidgets();

    if (!m_logotypeLabel->isHidden())
    {
        if (m_logotypeLabel->alignment() == Qt::AlignRight)
            pageRect.adjust(0, 0, -4, 0);
        else
            pageRect.adjust(2, 0, 0, 0);
    }

    m_rcPageArea = pageRect;

    if (p.isMinimized())
    {
        m_rcPageArea.setHeight(0);
        pageRect.moveTo(0, 0);
    }

    for (QList<RibbonPage*>::iterator it = m_listPages.begin(); it != m_listPages.end(); ++it)
    {
        RibbonPage* page = *(it);
        page->setGeometry(pageRect);
    }

    m_ribbonBarVisible = saveRibbonBarVisible;

    bool ribbonBarVisible = true;
/*
    if (p.isTitleBarVisible())
    {
        ribbonBarVisible = m_ribbonTitleBarWidget->width() > 3;
        
        if (m_quickAccessBarPosition == RibbonBar::QABottomPosition)
        {
            if (m_controlSystemButton && m_controlSystemButton->toolButtonStyle() == Qt::ToolButtonFollowStyle)
            {
                const int wd = m_controlSystemButton->sizeHint().width();
                ribbonBarVisible = m_ribbonTitleBarWidget->width() - (wd*2) > 3;
            }
            else
            {
                const int left = m_ribbonTitleBarWidget->geometry().left();
                ribbonBarVisible = m_ribbonTitleBarWidget->width() - left * 2 > 3;
            }
        }
    }
    else
        ribbonBarVisible = opt.rect.width() >= 250;
*/
    if (m_ribbonBarVisible != ribbonBarVisible && p.QMenuBar::isVisible())
        m_ribbonBarVisible = ribbonBarVisible;

    if (!m_logotypeLabel->isHidden())
    {
        QRect rectLogotype;
        int width = m_logotypeLabel->pixmap()->width();
        int height = m_logotypeLabel->pixmap()->height();

        if (height < m_rcPageArea.height())
            rectLogotype.setTop(m_rcPageArea.top());
        else
        {
            rectLogotype.setTop(0);
        }

        if ( m_logotypeLabel->alignment() == Qt::AlignRight )
            rectLogotype.setLeft(m_rcPageArea.right() - width + 4);

        rectLogotype.setWidth(width);
        rectLogotype.setHeight(m_rcPageArea.height());

        m_logotypeLabel->setGeometry(rectLogotype);
        m_logotypeLabel->raise();
    }

    RibbonPage* currentPage = isValidIndex(m_ribbonTabBar->currentIndex()) ? m_listPages.at(m_ribbonTabBar->currentIndex()) : Q_NULL;
    if (currentPage != Q_NULL)
        currentPage->updateLayout();
    if (m_ribbonTitleBarWidget != Q_NULL)
        m_ribbonTitleBarWidget->update();
}

/*! \internal */
void RibbonBarPrivate::layoutCorner()
{
    QTN_P(RibbonBar);
    if (QWidget* rightWidget = p.cornerWidget(Qt::TopRightCorner)) 
    {
        if (rightWidget && rightWidget->isVisible()) 
        {
            const int hmargin = p.style()->pixelMetric(QStyle::PM_MenuBarHMargin, 0, &p);
            QRect rcTab = m_ribbonTabBar->geometry();
            QRect rc = rightWidget->geometry();
            QPoint pos(p.width() - rc.width() - hmargin + 1, rcTab.top() + (rcTab.height() - rc.height())/2);
            QRect vRect = QStyle::visualRect(p.layoutDirection(), p.rect(), QRect(pos, rc.size()));
            rightWidget->setGeometry(vRect);
        }
    }
}

/*! \internal */
void RibbonBarPrivate::createRibbonTitleBarWidget()
{
    QTN_P(RibbonBar);
    if (m_ribbonTitleBarWidget == Q_NULL)
    {
        m_ribbonTitleBarWidget = new RibbonTitleBarWidget(&p);
        m_quickAccessBar = new RibbonQuickAccessBar(m_ribbonTitleBarWidget);
        m_quickAccessBar->setObjectName(QStringLiteral("qtn_Ribbon_Quick_Access_Bar"));
        m_ribbonTitleBarWidget->addWidget(m_quickAccessBar);
        m_quickAccessBar->setVisible(false);
        QObject::connect(this, SIGNAL(updateContextHeaders()), m_ribbonTitleBarWidget, SLOT(updateContextHeaders()));
    }
}

/*! \internal */
void RibbonBarPrivate::deleteRibbonTitleBarWidget()
{
    if (m_ribbonTitleBarWidget == Q_NULL)
        return;
    if (WindowTitleBar* titleBar = findTitleBar())
    {
        titleBar->setWidget(Q_NULL);
        titleBar->removeAndDelete();
        m_ribbonTitleBarWidget->setParent(Q_NULL);
        Q_DELETE_AND_NULL(m_ribbonTitleBarWidget);
    }
}

/*! \internal */
void RibbonBarPrivate::setVisibleBackstage(bool visible)
{
    QTN_P(RibbonBar);
    if ((bool)p.style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonBackstageHideTabs))
    {
        if (visible)
        {
            if (m_ribbonTabBar && !m_ribbonTabBar->isHidden())
            {
                m_visibleWidgets << m_ribbonTabBar;
                m_ribbonTabBar->setVisible(false);
            }

            if (m_quickAccessBar && !m_quickAccessBar->isHidden())
            {
                m_visibleWidgets << m_quickAccessBar;
                m_quickAccessBar->setVisible(false);
            }

            if (m_controlSystemButton && m_controlSystemButton->isHidden())
            {
                m_visibleWidgets << m_controlSystemButton;
                m_controlSystemButton->setVisible(false);
            }
            if (WindowTitleBar* titleBar = findTitleBar())
            {
                m_saveVisibleSysMenu = titleBar->isSysMenuButtonVisible();
                titleBar->setSysMenuButtonVisible(false);
            }
        }
        else
        {
            RibbonBarAutoUpdater autoUpdater(&p);

            for (QVector<QWidget*>::ConstIterator it = m_visibleWidgets.begin(); it != m_visibleWidgets.end(); ++it)
                (*it)->setVisible(true);
            m_visibleWidgets.clear();

            if (WindowTitleBar* titleBar = findTitleBar())
                titleBar->setSysMenuButtonVisible(m_saveVisibleSysMenu);
        }
    }
}

/*! \internal */
void RibbonBarPrivate::updateQuickAccessBarPosition()
{
    QTN_P(RibbonBar);
    if (m_ribbonTitleBarWidget == Q_NULL)
        return;

    if (m_quickAccessBarPosition == RibbonBar::QABottomPosition || !m_showTitleAlways)
    {
        m_ribbonTitleBarWidget->removeWidget(m_quickAccessBar);
        m_quickAccessBar->setParent(Q_NULL);
        m_quickAccessBar->setParent(&p);
        m_quickAccessBar->setFont(QApplication::font("QMdiSubWindowTitleBar"));
        if (m_showTitleAlways)
            m_quickAccessBar->setVisible(true);
    }
    else if (m_quickAccessBarPosition == RibbonBar::QATopPosition)
    {
        m_quickAccessBar->setParent(Q_NULL);
        m_ribbonTitleBarWidget->addWidget(m_quickAccessBar);
    }
}

/*! \internal */
QAction* RibbonBarPrivate::createSystemButton(const QIcon& icon, const QString& text)
{
    QTN_P(RibbonBar);
    QAction* actionSystemPopupBar = Q_NULL;
    if (icon.isNull())
    {
        QIcon iconQtnLogo;
        QIcon qtitan(QStringLiteral(":/res/qtitan.png"));
        iconQtnLogo.addPixmap(qtitan.pixmap(QSize(64,56), QIcon::Disabled));
        QIcon icon32(QStringLiteral(":/res/qtitanlogo32x32.png"));
        iconQtnLogo.addPixmap(icon32.pixmap(QSize(32,32), QIcon::Disabled));
        actionSystemPopupBar = new QAction(&p);
        actionSystemPopupBar->setIcon(iconQtnLogo);
        actionSystemPopupBar->setText(text);
    }
    else
    {
        actionSystemPopupBar = new QAction(&p);
        actionSystemPopupBar->setIcon(icon);
        actionSystemPopupBar->setText(text);
    }

    m_controlSystemButton = new RibbonSystemButton(&p);
    m_controlSystemButton->show();
    m_controlSystemButton->setAutoRaise(true);
    m_controlSystemButton->setFocusPolicy(Qt::NoFocus);
    m_controlSystemButton->setDefaultAction(actionSystemPopupBar);

    m_controlSystemButton->setPopupMode(QToolButton::InstantPopup);
    m_controlSystemButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
    actionSystemPopupBar->setIconText(actionSystemPopupBar->text());

    return actionSystemPopupBar;
}

/*! \internal */
void RibbonBarPrivate::insertPage(int indTab, int index, RibbonPage* page)
{
    Q_ASSERT(page != Q_NULL);
    QTN_P(RibbonBar);
    if (!isValidIndex(index)) 
    {
        index = m_listPages.count();
        m_listPages.append(page);
    }
    else
        m_listPages.insert(index, page);

    if (RibbonTab* tab = m_ribbonTabBar->getTab(indTab))
        page->setAssociativeTab(tab);

    preparePages();
    p.updateLayout();
}

/*! \internal */
void RibbonBarPrivate::removePage(int index, bool deletePage)
{
    if (isValidIndex(index))
    {
        RibbonPage* ribbonPage = m_listPages[index];
        m_listPages.removeAt(index);
        if (deletePage)
        {
            Q_DELETE_AND_NULL(ribbonPage);
            if (m_ribbonTitleBarWidget != Q_NULL)
                m_ribbonTitleBarWidget->adjustSizeTitleBar();
        }
        else
        {
            ribbonPage->setAssociativeTab(Q_NULL);
            ribbonPage->setParent(Q_NULL);
        }
    }
}

/*! \internal */
int RibbonBarPrivate::pageIndex(RibbonPage* page) const
{
    return m_listPages.indexOf(page);
}

/*! \internal */
void RibbonBarPrivate::showPagePopup(RibbonPage* page)
{
    QTN_P(RibbonBar);
    const int height = page->height();
    QPoint pnt(0, 0);
    QRect rcTabBar = m_ribbonTabBar->geometry();
    QRect rect = page->rect();
    rect.setTop(rcTabBar.top());
    rect.setBottom(rcTabBar.bottom());

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    int ribbonTopBorder = 0;//topBorder();
    if (p.parentWidget() && p.parentWidget()->windowState() & Qt::WindowMaximized)
        rect.translate(0, ribbonTopBorder);
#endif // QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

    QRect screen = qtn_availableGeometry(&p);
    int h = height;
    if (p.mapToGlobal(QPoint(0, rect.bottom())).y() + h <= screen.height())
        pnt = p.mapToGlobal(rect.bottomLeft());
    else
        pnt = p.mapToGlobal(rect.topLeft() - QPoint(0, h));
    int margin = p.style()->pixelMetric(QStyle::PM_MenuVMargin, Q_NULL, &p);
    QRect rc(pnt, QSize(rect.width(), height + margin * 2));
    m_pagePopupWidget->setGeometry(rc);
    m_pagePopupWidget->setPalette(p.palette());
    m_pagePopupWidget->show();
}

/*! \internal */
void RibbonBarPrivate::hidePagePopup()
{
    m_pagePopupWidget->hide();
}

/*! \internal */
bool RibbonBarPrivate::isPagePopupVisible() const
{
    return m_pagePopupWidget->isVisible();
}

/*! \internal */
QWidget* RibbonBarPrivate::getPageParent()
{
    QTN_P(RibbonBar)
    if (p.isMinimized())
        return m_pagePopupWidget;
    else
        return &p;
}

/*! \internal */
WindowTitleBar* RibbonBarPrivate::findTitleBar() const
{
    QTN_P(const RibbonBar)
    QWidget* parent = p.parentWidget();
    return parent != Q_NULL && parent->isTopLevel() ? WindowTitleBar::find(parent) : Q_NULL;
}

/*! \internal */
bool RibbonBarPrivate::isUpdating() const
{
    Q_ASSERT(m_updateLayoutCount >= 0);
    return m_updateLayoutCount > 0;
}

/*! \internal */
void RibbonBarPrivate::preparePages()
{
    const QList<RibbonTab*>& tabs = m_ribbonTabBar->tabs();
    QWidget* parent = getPageParent();
    for (QList<RibbonTab*>::const_iterator it = tabs.constBegin(); it != tabs.constEnd(); ++it)
    {
        RibbonTab* tab = *it;
        if (tab->page() != Q_NULL && tab->page()->parent() != parent)
        {
            RibbonPageVisibleAutoUpdater autoUpdater(RibbonPagePrivate::_get(tab->page()));
            tab->page()->setParent(parent);
            tab->page()->setVisible(tab->isSelected());
        }
    }
}

/*! \internal */
void RibbonBarPrivate::currentTabBarChanged(int index)
{
    QTN_P(RibbonBar);
    RibbonTab* tab = m_ribbonTabBar->getTab(index);
    emit p.currentPageIndexChanged(index);
    emit p.currentPageChanged(tab != Q_NULL ? tab->page() : Q_NULL);
    if (p.currentPageIndex() != -1 && p.currentPageIndex() != index)
    {
        if (p.parentWidget() != Q_NULL)
            p.parentWidget()->setFocus();
    }
}

/*! \internal */
QMenu* RibbonBarPrivate::createContextMenu()
{
    QTN_P(RibbonBar)
    if (p.isBackstageVisible())
        return Q_NULL;

    QMenu* popup = new QMenu(&p);
    QAction* action = Q_NULL;
    RibbonQuickAccessBar* quickAccessBar = p.quickAccessBar();
    if (quickAccessBar && !quickAccessBar->isHidden())
    {
        QList<QAction*> actions = quickAccessBar->actions();
        if (actions.size() > 0)
        {
            action = popup->addAction(RibbonBar::tr_compatible(QtnRibbonCustomizeQuickAccessToolBarDotString));
            action->setObjectName(strCustomizeQAToolBar);
            connect(action, SIGNAL(triggered()), this, SLOT(toggledCustomizeBar()));

            action = popup->addAction(p.quickAccessBarPosition() == RibbonBar::QATopPosition ? RibbonBar::tr_compatible(QtnRibbonShowQuickAccessToolBarBelowString)
                : RibbonBar::tr_compatible(QtnRibbonShowQuickAccessToolBarAboveString));
            action->setObjectName(strCustomizeRibbonBar);
            connect(action, SIGNAL(triggered()), this, SLOT(toggledQuickAccessBarPos()));
        }
        popup->addSeparator();
    }

    action = popup->addAction(RibbonBar::tr_compatible(QtnRibbonCustomizeActionString));
    action->setObjectName(strCustomizeRibbonBar);
    connect(action, SIGNAL(triggered()), this, SLOT(toggledCustomizeBar()));

    if (p.isMinimizationEnabled())
    {
        action = popup->addAction(RibbonBar::tr_compatible(QtnRibbonMinimizeActionString));
        action->setCheckable(true);
        action->setChecked(p.isMinimized());
        connect(action, SIGNAL(triggered()), this, SLOT(toggledMinimized()));
    }
    return popup;
}

/*! \internal */
static QString findAccel(const QString &text)
{
    if (text.isEmpty())
        return text;

    int fa = 0;
    QChar ac;
    while ((fa = text.indexOf(QLatin1Char('&'), fa)) != -1) 
    {
        ++fa;
        if (fa < text.length()) 
        {
            // ignore "&&"
            if (text.at(fa) == QLatin1Char('&')) 
            {
                ++fa;
                continue;
            } 
            else 
            {
                ac = text.at(fa);
                break;
            }
        }
    }
    if (ac.isNull())
        return QString();
    return (QString)ac.toUpper();
}

/*! \internal */
void RibbonBarPrivate::setKeyboardMode(bool b)
{
    QTN_P(RibbonBar);
    if (b && !p.style()->styleHint(QStyle::SH_MenuBar_AltKeyNavigation, 0, &p)) 
        return;

    m_keyboardState = b;

    if (m_keyboardState)
    {
        QWidget* fw = QApplication::focusWidget();
        if (fw != &p)
            m_keyboardFocusWidget = fw;
        p.setFocus(Qt::MenuBarFocusReason);

        if (m_levels.indexOf(&p) == -1)
        {
            m_keyTipsShowing = true;
            emit p.keyTipsShowed(true);
            showKeyTips(&p);
        }
    }
    else
    {
        hideKeyTips();
        m_levels.clear();

        if (m_keyboardFocusWidget)
        {
            if (QApplication::focusWidget() == &p)
                m_keyboardFocusWidget->setFocus(Qt::MenuBarFocusReason);
            m_keyboardFocusWidget = Q_NULL;
        }
    }
}

/*! \internal */
void RibbonBarPrivate::showKeyTips(QWidget* w)
{
    hideKeyTips();
    m_countKey = 0;

    if (qobject_cast<RibbonBar*>(w))
        createKeyTips();
    else if (qobject_cast<RibbonPage*>(w))
        createGroupKeyTips();
    else if (QMenu* menu = qobject_cast<QMenu*>(w))
        createPopupKeyTips(menu);

    int count = m_keyTips.count();
    if (count == 0)
        return;

    for (int i = count - 1; i >= 0; i--)
    {
        RibbonKeyTip* keyTip = m_keyTips.at(i);
        keyTip->setExplicit(!keyTip->getStringTip().isEmpty());

        if (keyTip->isExplicit())
            continue;

        QString strCaption = keyTip->getCaption();
        if (strCaption.isEmpty())
        {
            keyTip->close();
            keyTip->deleteLater();
            m_keyTips.removeAt(i);
            continue;
        }

        strCaption = strCaption.toUpper();
        keyTip->setCaption(strCaption);

        if (keyTip->getPrefix().isEmpty())
        {
            QString key = ::findAccel(strCaption);
            if (key.isEmpty())
            {
                if (!strCaption.isEmpty())
                    keyTip->setStringTip(QChar(strCaption[0]));
            }
            else
                keyTip->setStringTip(key);
        }
        else
        {
            keyTip->setStringTip(keyTip->getPrefix());
        }
    }

    count = m_keyTips.count();
    for (int i = 0; i < count; i++)
    {
        RibbonKeyTip* keyTip = m_keyTips.at(i);

        QString strTip = keyTip->getStringTip();

        QList<RibbonKeyTip*> list;
        list.append(keyTip);

        QString strUsed(QStringLiteral("& "));
        for ( int j = i + 1; j < count; j++)
        {
            RibbonKeyTip* keyTipWidget = m_keyTips.at(j);;
            if (keyTipWidget->getStringTip()[0] == strTip[0])
            {
                list.append(keyTipWidget);
                if (keyTipWidget->getStringTip().length() == 2)
                    strUsed += keyTipWidget->getStringTip()[1];
            }
        }

        if (list.count() < 2)
            continue;

        int k = 1;
        for (int j = 0; j < list.count(); j++)
        {
            RibbonKeyTip* keyTipWidget = list.at(j);
            if (keyTipWidget->getStringTip().length() > 1)
                continue;

            QChar chAccel(0);
            QString strCaption = keyTipWidget->getCaption();
            for (int n = 0; n < strCaption.length() - 1; n++)
            {
                if ((strCaption[n] == QLatin1Char(' ')) && (strUsed.indexOf(strCaption[n + 1]) == -1))
                {
                    chAccel = strCaption[n + 1];
                    strUsed += chAccel;
                    break;
                }
            }

            if (chAccel.isNull())
            {
                int start = strCaption[0] == QLatin1Char('&') ? 1 : 0;
                if (strCaption[start] == keyTipWidget->getStringTip()[0])
                    start++;

                for (int n = start; n < strCaption.length(); n++)
                {
                    if (strUsed.indexOf(strCaption[n]) == -1)
                    {
                        chAccel = keyTipWidget->getCaption()[n];
                        strUsed += chAccel;
                        break;
                    }
                }
            }
            if (chAccel.isNull())
            {
                QString str = QStringLiteral("%1").arg(k);
                chAccel = str[0];
                k++;
            }
            keyTipWidget->setStringTip(keyTipWidget->getStringTip() + chAccel);
        }
    }

    calcPositionKeyTips();

    if (m_keyTips.count() > 0)
        qApp->installEventFilter(this);

    QTN_P(RibbonBar);
    p.setFocus();
}

/*! \internal */
bool RibbonBarPrivate::hideKeyTips()
{
    bool res = false;
    if (m_keyTips.count() > 0)
    {
        qApp->removeEventFilter(this);
        res = true;
    }
    destroyKeyTips();
    m_countKey = 0;
    return res;
}

/*! \internal */
void RibbonBarPrivate::createKeyTips()
{
    QTN_P(RibbonBar);
    qtn_updateTitleBarWidgetPosition(p.parentWidget());

    m_levels.push(&p);
    QList<QToolButton*> list = m_quickAccessBar->findChildren<QToolButton*>();
    for (int i = 0, count = list.count(); i < count; i++)
    {
        QToolButton* button = list.at(i);
        if (!button->isVisible() || button->objectName() == QStringLiteral("QtnRibbonQuickAccessButton"))
            continue;

        int k = 1;
        QString strCaption;
        if (QAction* act = button->defaultAction())
        {
            strCaption = act->property(_qtn_KeyTip).toString();
            if (strCaption.isEmpty())
            {
                QList<QAction*> listActs = m_quickAccessBar->actions();
                int index = listActs.indexOf(act);
                if (index != -1)
                    k = index;
            }
        }

        if (strCaption.isEmpty())
        {
            if (k < 10)
                strCaption = QStringLiteral("%1").arg(k);
            else if (k < 19)
                strCaption = QStringLiteral("%1").arg(k - 9);
            else 
                break;
        }

        m_keyTips.append(new RibbonKeyTip(&p, button, strCaption, button->mapToGlobal(QPoint(button->rect().center().x(), button->rect().bottom() - 11)), 
            RibbonKeyTip::AlignTipCenter | RibbonKeyTip::AlignTipTop, button->isEnabled()));
    }

    if (m_ribbonTabBar && m_ribbonTabBar->isVisible())
    {
        for (int i = 0, count = m_ribbonTabBar->getTabCount(); i < count; i++)
        {
            RibbonTab* tab = m_ribbonTabBar->getTab(i);

            bool propKeyTip = true;
            QString strCaption = tab->defaultAction()->property(_qtn_KeyTip).toString();

            if (strCaption.isEmpty())
            {
                strCaption = tab->text();
                propKeyTip = false;
            }

            if (!m_keyTipsComplement && !propKeyTip && ::findAccel(strCaption).isEmpty())
                strCaption = QString();

            if (!strCaption.isEmpty() && tab->isEnabled() && tab->isVisible())
            {
                QPoint pt(tab->rect().center().x(), tab->rect().bottom() - 9);
                RibbonKeyTip* keyTip = new RibbonKeyTip(&p, tab, strCaption, tab->mapToGlobal(pt), 
                    RibbonKeyTip::AlignTipCenter | RibbonKeyTip::AlignTipTop, true);
                m_keyTips.append(keyTip);
            }
        }
    }

    if (m_controlSystemButton)
    {
        QPoint pt(m_controlSystemButton->rect().center().x(), m_controlSystemButton->rect().center().y());

        QString strCaption = m_controlSystemButton->defaultAction()->property(_qtn_KeyTip).toString();
        if (strCaption.isEmpty())
            strCaption = m_controlSystemButton->text();

        m_keyTips.append(new RibbonKeyTip(&p, m_controlSystemButton, strCaption, 
            m_controlSystemButton->mapToGlobal(pt), RibbonKeyTip::AlignTipCenter | RibbonKeyTip::AlignTipVCenter, m_controlSystemButton->isEnabled()));
    }
}

/*! \internal */
void RibbonBarPrivate::createGroupKeyTips()
{
    int index = m_ribbonTabBar->currentIndex();
    if (!isValidIndex(index))
        return;

    RibbonPage* page = m_listPages.at(index);
    m_levels.push(page);
    for (int i = 0, count = page->groupCount(); i < count; i++)
    {
        RibbonGroup* group = page->groupAt(i);
        bool visible = group->isVisible();

        QList<QWidget*> list = group->findChildren<QWidget*>();
        for (int j = 0; j < list.count(); j++)
        {
            QWidget* widget = list.at(j);
            createWidgetKeyTips(group, widget, QString(), page->rect().translated(page->mapToGlobal(page->rect().topLeft())), visible);
        }
    }
}

/*! \internal */
static QString getTextAction(const RibbonGroup& group, QWidget& widget, bool& propKeyTip)
{
    QString strCaption;
    foreach (QAction* action, group.actions())
    {
        if (QWidgetAction* widgetAction = qobject_cast<QWidgetAction*>(action))
        {
            if (&widget == widgetAction->defaultWidget())
            {
                strCaption = widgetAction->property(_qtn_KeyTip).toString();
                if (strCaption.isEmpty())
                {
                    strCaption = widgetAction->text();
                    propKeyTip = false;
                }
                break;
            }
        }
    }
    return strCaption;
}

/*! \internal */
void RibbonBarPrivate::createWidgetKeyTips(RibbonGroup* group, QWidget* widget, const QString& prefix, const QRect& rcGroups, bool visible)
{
    QTN_P(RibbonBar);

    if (!widget)
        return;

    bool propKeyTip = true;
    QString strCaption;
    if (QAbstractButton* button = qobject_cast<QAbstractButton*>(widget))
    {
        strCaption = ::getTextAction(*group, *button, propKeyTip);
        if (strCaption.isEmpty())
        {
            if (QToolButton* toolButton = qobject_cast<QToolButton*>(button))
            {
                if (QAction* action = toolButton->defaultAction())
                {
                    strCaption = action->property(_qtn_KeyTip).toString();
                    if (strCaption.isEmpty())
                    {
                        strCaption = action->text();
                        propKeyTip = false;
                    }
                }

                if (strCaption.isEmpty())
                {
                    if (RibbonGallery* ribGallery = qobject_cast<RibbonGallery*>(toolButton->parentWidget()))
                    {
                        if (toolButton->property(_qtn_PopupButtonGallery).toBool())
                        {
                            if (OfficePopupMenu* menu = ribGallery->popupMenu())
                            {
                                if (QAction* act = menu->defaultAction())
                                    strCaption = act->text();
                            }
                            if (strCaption.isEmpty())
                                strCaption = ::getTextAction(*group, *toolButton->parentWidget(), propKeyTip);
                        }
                    }
                    else if (strCaption.isEmpty())
                        strCaption = group->title();
                }
            }
            else
            {
                strCaption = ::getTextAction(*group, *widget, propKeyTip);
                if (strCaption.isEmpty())
                    strCaption = button->text();
            }
        }
    }

    bool textWidget = true;
    if (RibbonGallery* gallery = qobject_cast<RibbonGallery*>(widget))
        textWidget = !gallery->popupMenu();

    if (strCaption.isEmpty() && textWidget)
        strCaption = ::getTextAction(*group, *widget, propKeyTip);

    if (!m_keyTipsComplement && !propKeyTip && ::findAccel(strCaption).isEmpty())
        strCaption = QString();

    if (strCaption.isEmpty())
        return;

    QRect rc = widget->rect();
    rc.translate(widget->mapToGlobal(rc.topLeft()));

    if (rc.isEmpty())
        return;

    QPoint pt(rc.left() + 21, rc.bottom() - 4);
    uint align = RibbonKeyTip::AlignTipTop;

    QStyleOptionGroupBox opt;
    opt.init(&p);
    opt.text = group->title();

    QRect rcGroup = group->rect();
    rcGroup.translate(group->mapToGlobal(rcGroup.topLeft()));

    const int heightCaptionGroup = p.style()->pixelMetric((QStyle::PixelMetric)CommonStyle::PM_RibbonHeightCaptionGroup, &opt, group);
    QRect rcCaption(QPoint(rcGroup.left(), rcGroup.bottom() - heightCaptionGroup + 2), QPoint(rcGroup.right(), rcGroup.bottom()));
    rcGroup.setBottom(rcCaption.top());

    QFontMetrics fm(p.font());
    const int h = fm.boundingRect(QLatin1Char('X')).height() / 2;

    if (rc.intersects(rcCaption))
    {
        pt = QPoint(rc.center().x(), rcGroups.bottom() - 6);
        align = RibbonKeyTip::AlignTipTop | RibbonKeyTip::AlignTipCenter;
    }
    else if ((Qt::ToolButtonStyle)widget->property("toolButtonStyle").toInt() == Qt::ToolButtonTextUnderIcon && rc.height() > rcGroup.height() * 0.5)
    {
        pt = QPoint(rc.center().x(), rc.bottom() + h);
        align = RibbonKeyTip::AlignTipCenter | RibbonKeyTip::AlignTipVCenter;
    }
    else if (qobject_cast<RibbonGallery*>(widget))
    {
        pt = QPoint(rc.right(), rcGroup.bottom() - 2);
        align = RibbonKeyTip::AlignTipCenter | RibbonKeyTip::AlignTipVCenter;
    }
    else if (rc.center().y() < rcGroup.top() + rcGroup.height() * 1 / 3)
    {
        /// top
        pt = QPoint(rc.left() + 11, rcGroup.top());
        align = RibbonKeyTip::AlignTipLeft | RibbonKeyTip::AlignTipVCenter;
    }
    else if (rc.center().y() > rcGroup.top() + rcGroup.height() * 2 / 3)
    {
        pt = QPoint(rc.left() + 11, rcGroup.bottom());
        align = RibbonKeyTip::AlignTipLeft | RibbonKeyTip::AlignTipVCenter;
    }
    else
    {
        if (qobject_cast<RibbonButton*>(widget) && qobject_cast<RibbonToolBarControl*>(widget->parentWidget()))
            pt = QPoint(rc.left() + 11, rc.bottom() + h * 2);
        else
            pt = QPoint(rc.left() + 11, rcGroup.center().y() - 1);
        align = RibbonKeyTip::AlignTipLeft | RibbonKeyTip::AlignTipVCenter;
    }

    if (qobject_cast<QCheckBox*>(widget) || qobject_cast<QRadioButton*>(widget))
        pt.setX(rc.left() + 6);

    RibbonKeyTip* keyTip = new RibbonKeyTip(&p, widget, strCaption, pt, align, widget->isEnabled());

    if (!prefix.isEmpty())
        keyTip->setPrefix(prefix);

    QRect rcIntersect;
    rcIntersect = rcGroups.intersected(rc);
    keyTip->setVisibleTip(visible && (rcIntersect == rc) && (widget->isVisible()));
    m_keyTips.append(keyTip);
}

/*! \internal */
bool RibbonBarPrivate::createPopupKeyTips(QMenu* levalMenu)
{
    QTN_P(RibbonBar);
    QMenu* menu = levalMenu ? levalMenu : qobject_cast<QMenu*>(QApplication::activePopupWidget());
    if (menu)
    {
        m_levels.push(menu);

        QList<QAction*> list = menu->actions();
        for (int i = 0; i < list.count(); i++)
        {
            QAction* action = list.at(i);
            bool propKeyTip = true;
            QString strCaption = action->property(_qtn_KeyTip).toString();

            if (strCaption.isEmpty())
            {
                strCaption = action->text();
                propKeyTip = false;
            }

            if (!m_keyTipsComplement && !propKeyTip && ::findAccel(strCaption).isEmpty())
                strCaption = QString();

            if (!action->isVisible() || strCaption.isEmpty())
                continue;

            QRect rect = menu->actionGeometry(action);
            QPoint pt(rect.left() + 12, rect.bottom() - 11);
            RibbonKeyTip* keyTip = new RibbonKeyTip(&p, menu, strCaption, menu->mapToGlobal(pt), RibbonKeyTip::AlignTipTop, action->isEnabled(), action);

            m_keyTips.append(keyTip);
        }

        QList<QWidget*> listWidget = menu->findChildren<QWidget*>();
        for (int i = 0; i < listWidget.count(); i++)
        {
            QWidget* widget = listWidget.at(i);

            bool propKeyTip = true;
            QString strCaption;

            if (QToolButton* toolButton = qobject_cast<QToolButton*>(widget))
            {
                if (QAction* action = toolButton->defaultAction())
                {
                    strCaption = action->property(_qtn_KeyTip).toString();
                    if (strCaption.isEmpty())
                    {
                        strCaption = action->text();
                        propKeyTip = false;
                    }
                }
            }

            if (!m_keyTipsComplement && !propKeyTip && ::findAccel(strCaption).isEmpty())
                strCaption = QString();

            if (!widget->isVisible() || strCaption.isEmpty())
                continue;

            QPoint pt(widget->rect().left() + 12, widget->rect().bottom() - 11);
            RibbonKeyTip* keyTip = new RibbonKeyTip(&p, widget, strCaption, widget->mapToGlobal(pt), 
                RibbonKeyTip::AlignTipTop, widget->isEnabled());
            m_keyTips.append(keyTip);
        }
        return true;
    }
    return false;
}

/*! \internal */
void RibbonBarPrivate::destroyKeyTips()
{
    for (int i = 0; i < m_keyTips.count(); i++)
    {
        RibbonKeyTip* keyTip = m_keyTips.at(i);
        keyTip->close();
        keyTip->deleteLater();
    }
    m_keyTips.clear();
}

/*! \internal */
void RibbonBarPrivate::calcPositionKeyTips()
{
    for (int i = 0, count = m_keyTips.count(); i < count; i++)
    {
        RibbonKeyTip* keyTip = m_keyTips.at(i);
        if (!keyTip->isVisibleTip())
            continue;

        QSize sz(0, 0);
        QFontMetrics fontMetrics(keyTip->font());
        QRect rect = fontMetrics.boundingRect(keyTip->getStringTip());
        sz = QSize(qMax(rect.width() + 6, 16), qMax(rect.height() + 2, 15));

        QPoint pt = keyTip->posTip();
        uint flagAlign = keyTip->getAlign();

        QRect rc(QPoint(pt.x() - ((flagAlign & RibbonKeyTip::AlignTipCenter) ?  sz.width() * 0.5 : (flagAlign & RibbonKeyTip::AlignTipRight) ? sz.width() : 0),
            pt.y() - (flagAlign & RibbonKeyTip::AlignTipVCenter ?  sz.height() * 0.5 : flagAlign & RibbonKeyTip::AlignTipBottom ? sz.height() : 0)), sz);

        keyTip->setGeometry(rc);
        keyTip->show();
    }
}

/*! \internal */
int RibbonBarPrivate::rowItemHeight() const
{
    return m_ribbonItemHeight;
}

/*! \internal */
int RibbonBarPrivate::rowItemCount() const
{
    return m_rowItemCount;
}

/*! \internal */
int RibbonBarPrivate::maxGroupHeight() const
{
    int ret = rowItemHeight() * rowItemCount();
    for (QList<RibbonPage*>::const_iterator it = m_listPages.begin(); it != m_listPages.end(); ++it)
    {
        RibbonPage* page = (*it);
        for (int g = 0, countG = page->groupCount(); countG > g; g++)
        {
            if (RibbonGroup* group = page->groupAt(g))
                ret = qMax(ret, group->sizeHint().height());
        }
    }
    return ret;
}

/*! \internal */
bool RibbonBarPrivate::pressTipCharEvent(const QKeyEvent* key)
{
    QTN_P(RibbonBar);
    QString str = key->text().toUpper();
    if (str.isEmpty())
        return false;
    for (int i = 0; i < m_keyTips.count(); i++)
    {
        RibbonKeyTip* keyTip = m_keyTips.at(i);
        int length = keyTip->getStringTip().length();
        if (length > m_countKey)
        {
            if (keyTip->getStringTip()[m_countKey] == str[0])
            {
                if (length - 1 > m_countKey)
                {
                    m_countKey++;

                    QString str = keyTip->getStringTip().left(m_countKey);
                    for (int j = m_keyTips.count() - 1; j >= 0; j--)
                    {
                        keyTip = m_keyTips.at(j);
                        if (keyTip->getStringTip().left(m_countKey) != str)
                        {
                            m_keyTips.removeAt(j);
                            keyTip->hide();
                            keyTip->deleteLater();
                        }
                    }
                }
                else
                {
                    if (QAbstractButton* absButton = qobject_cast<QAbstractButton*>(keyTip->getOwner()))
                    {
                        if (keyTip->isEnabledTip() && keyTip->isVisibleTip())
                        {
                            m_keyTipsShowing = false;
                            emit p.keyTipsShowed(false);

                            bool clearLevel = true;
                            bool showMenu = false;
                            if (QToolButton* button = qobject_cast<QToolButton*>(absButton))
                            {
                                if (button->popupMode() == QToolButton::InstantPopup)
                                    clearLevel = false;
                                else if (button->popupMode() == QToolButton::MenuButtonPopup)
                                {
                                    button->showMenu();
                                    clearLevel = false;
                                    showMenu = true;
                                }
                            }
                            if (clearLevel)
                                m_levels.clear();

                            if (!showMenu)
                                absButton->animateClick(0);
                        }
                        return false;
                    }
                    else if (qobject_cast<QMenu*>(keyTip->getOwner()) && keyTip->isEnabledTip() && keyTip->isVisibleTip())
                    {
                        hideKeyTips();

                        m_keyTipsShowing = false;
                        emit p.keyTipsShowed(false);

                        if (QAction* action = keyTip->getAction())
                        {
                            if (qobject_cast<RibbonPageSystemPopup*>(action->menu()))
                            {
                                if (QMenu* activSystemMenu = qobject_cast<RibbonSystemMenu*>(QApplication::activePopupWidget()))
                                    activSystemMenu->setActiveAction(action);
                                return false;
                            }
                            else
                            {
                                m_levels.clear();
                                action->trigger();
                                QWidget* owner = keyTip->getOwner();
                                owner->close();

                                if (qobject_cast<RibbonPageSystemPopup*>(owner))
                                {
                                    if (QWidget* activPopup = qobject_cast<RibbonSystemMenu*>(QApplication::activePopupWidget()))
                                        activPopup->close();
                                }
                                return false;
                            }
                        }
                    } 
                    else if (qobject_cast<RibbonTab*>(keyTip->getOwner()))
                    {
                        if (RibbonTab* tab = qobject_cast<RibbonTab*>(keyTip->getOwner()))
                        {
                            int index = m_ribbonTabBar->getTabIndex(tab);
                            if (index != -1)
                            {
                                p.setCurrentPageIndex(index);
                                showKeyTips(p.page(index));
                            }
                        }
                        return false;
                    }
                    else if (keyTip->getOwner() && keyTip->isEnabledTip() && keyTip->isVisibleTip())
                    {
                        hideKeyTips();

                        m_keyTipsShowing = false;
                        emit p.keyTipsShowed(false);

                        m_levels.clear();
                        keyTip->getOwner()->setFocus();
                    }
                }
                return false;
            }
        }
    }
    return false;
}

/*! \reimp */
bool RibbonBarPrivate::eventFilter(QObject* obj, QEvent* event)
{
    QTN_P(RibbonBar)
    switch (event->type()) 
    {
        case QEvent::WindowActivate:
        case QEvent::WindowDeactivate:
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
        case QEvent::MouseButtonDblClick:
        case QEvent::NonClientAreaMouseButtonPress :
        case QEvent::NonClientAreaMouseButtonRelease :
        case QEvent::NonClientAreaMouseButtonDblClick :
            {
                m_keyTipsShowing = false;
                emit p.keyTipsShowed(false);

                hideKeyTips();
                m_levels.clear();
            }
            break;
        case QEvent::Show :
            if (QMenu* menu = qobject_cast<QMenu*>(obj))
            {
                if (m_levels.size() > 0 || ((qobject_cast<RibbonPageSystemPopup*>(obj) || qobject_cast<RibbonSystemMenu*>(obj))))
                {
                    if (m_levels.indexOf(menu) == -1)
                    {
                        m_keyTipsShowing = true;
                        emit p.keyTipsShowed(true);
                        hideKeyTips();
                        showKeyTips(menu);
                    }
                }
            }
            else if (qobject_cast<RibbonPageSystemPopup*>(obj))
            {
                m_keyTipsShowing = false;
                hideKeyTips();
                m_levels.clear();
            }
            break;
        case QEvent::KeyPress :
            if (QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event))
            {
                if (keyEvent->key() != Qt::Key_Escape)
                {
                    if ((qobject_cast<QMainWindow*>(obj) || (m_minimized && qobject_cast<RibbonPage*>(obj))))
                        pressTipCharEvent(keyEvent);
                    else if (qobject_cast<QMenu*>(obj))
                        return !pressTipCharEvent(keyEvent);
                }
                else
                {
                    if (m_levels.size() > 1 && m_levels.pop())
                        showKeyTips(m_levels.pop());
                    else if (m_levels.size() > 0 && m_levels.pop())
                    {
                        hideKeyTips();

                        m_keyTipsShowing = false;
                        emit p.keyTipsShowed(false);
                    }
                }
            }
            break;
        case QEvent::Close :
            if (m_minimized && m_levels.size() > 1 && m_levels.pop())
                showKeyTips(m_levels.pop());
            break;
        default:
            break;
    }
    return false;
}

/*! \internal */
void RibbonBarPrivate::createCustomizeDialog()
{
    QTN_P(RibbonBar)
    if (m_customizeDialog != Q_NULL)
        return;

    m_customizeDialog = new RibbonCustomizeDialog(p.parentWidget());
    // Create "Customize QAT" page:
    RibbonQuickAccessBarCustomizePage* quickAccessBarCustomizePage = new RibbonQuickAccessBarCustomizePage(&p);
    m_customizeDialog->addPage(quickAccessBarCustomizePage);
    // Create "Customize Ribbon" page:
    RibbonBarCustomizePage* ribbonBarCustomizePage = new RibbonBarCustomizePage(&p);
    m_customizeDialog->addPage(ribbonBarCustomizePage);
}

/*! \internal */
void RibbonBarPrivate::toggledCustomizeBar()
{
    QTN_P(RibbonBar)
    p.showCustomizeDialog();
}

/*! \internal */
void RibbonBarPrivate::toggledQuickAccessBarPos()
{
    QTN_P(RibbonBar)
    p.setQuickAccessBarPosition(p.quickAccessBarPosition() == RibbonBar::QATopPosition ? RibbonBar::QABottomPosition : RibbonBar::QATopPosition);
}

/*! \internal */
void RibbonBarPrivate::toggledMinimized()
{
    QTN_P(RibbonBar)
    p.setMinimized(!p.isMinimized());
}

/*!
\class RibbonBar
\inmodule QtitanRibbon

\brief RibbonBar class represents a component Ribbon UI used in Microsoft Office 2007/2010/2013.
Please note, after the ribbon bar has been added to the main window you need to setup the Ribbon's style (or MS-Office Style) to the application.
To do that please use the following code:
\code
QApplication app(...);
app.setStyle(new Qtitan::RibbonStyle());
\endcode
or
\code
QApplication app(...);
app.setStyle("ribbonstyle");
\endcode

Note: To display RibbonBar correctly the Ribbon style (or Office style) should be installed into your application by calling qApp.setStyle(new Qtitan::RibbonStyle()); or app.setStyle("ribbonstyle");
RibbonBar does not work with platform's specific or standard Qt styles.
*/

/*!
\fn void RibbonBar::minimizationChanged(bool minimized);
The signal is used to get notification about changes of the minimization state of the ribbon bar.
The parameter \a minimized contains the current state of the minimization.
*/

/*!
\fn void RibbonBar::currentPageIndexChanged(int index);
The signal is emitted when the active page at the ribbon bar was changed.
Parameter \a index - the index of the new active page.
*/

/*!
\fn void RibbonBar::currentPageChanged(RibbonPage * page);
The signal is emitted when the active page at the ribbon bar was changed.
Parameter \a page is a reference to the active ribbon page object.
*/

/*!
Constructs RibbonBar object with the given \a parent.
*/
RibbonBar::RibbonBar(QWidget* parent)
    : QMenuBar(parent)
{
    initRibbonResource();
    QTN_INIT_PRIVATE(RibbonBar);
    QTN_D(RibbonBar);
    d.init();
}

/*!
Destructor of the RibbonBar object.
*/
RibbonBar::~RibbonBar()
{
    QTN_FINI_PRIVATE();
}

/*!
Returns the visible flag of the Ribbon Bar.
*/ 
bool RibbonBar::isVisible() const
{
    QTN_D(const RibbonBar);
    return QMenuBar::isVisible() && d.m_ribbonBarVisible;
}

/*!
Adds a new page on RibbonBar. Parameter \a text is used to initialize the page title. 
The function returns a pointer to the new object RibbonPage.
*/
RibbonPage* RibbonBar::addPage(const QString& text)
{
    return insertPage(-1, text);
}

/*!
Adds an existing \a page to the RibbonBar. \a page - is a pointer to the RibbonPage object.
*/
void RibbonBar::addPage(RibbonPage* page)
{
    insertPage(-1, page);
}

/*!
Creates a new page with the \a text title and insert it into the position \a index. 
The function returns a pointer to the new object RibbonPage.
*/
RibbonPage* RibbonBar::insertPage(int index, const QString& text)
{
    RibbonBarAutoUpdater autoUpdater(this);
    QTN_D(RibbonBar);
    int indTab = d.m_ribbonTabBar->insertTab(index, text);
    RibbonPage* page = new RibbonPage(this);
    d.insertPage(indTab, index, page);
    page->setTitle(text);
    return page;
}

/*!
Inserts an existing \a page at the specified position \a index of the RibbonBar. 
The \a index - is the position of the page, \a page - a pointer to the new object RibbonPage.
*/
void RibbonBar::insertPage(int index, RibbonPage* page)
{
    Q_ASSERT(page != Q_NULL);
    QTN_D(RibbonBar);
    if (d.pageIndex(page) != -1)
    {
        qWarning("RibbonBar::insertPage: Can't add page twice.");
        return;
    }
    RibbonBarAutoUpdater autoUpdater(this);
    page->setParent(this);
    int indTab = d.m_ribbonTabBar->insertTab(index, page->title());
    d.insertPage(indTab, index, page);
}

/*!
Moves the \a page from current position to the position \a newIndex.
*/
void RibbonBar::movePage(RibbonPage* page, int newIndex)
{
    QTN_D(RibbonBar);
    movePage(d.pageIndex(page), newIndex);
}

/*!
Moves the page in the position \a index to the position \a newIndex.
*/
void RibbonBar::movePage(int index, int newIndex)
{
    QTN_D(RibbonBar);
    if (d.isValidIndex(index) && d.isValidIndex(newIndex))
    {
        RibbonBarAutoUpdater autoUpdater(this);
        d.m_ribbonTabBar->moveTab(index, newIndex);
        d.m_listPages.move(index, newIndex);
    }
}

/*!
Removes an existing \a page. Parameter \a page is a pointer to page that will be removed. 
The object that is referenced by \a page will be destroyed.
\sa detachPage
*/
void RibbonBar::removePage(RibbonPage* page)
{
    QTN_D(RibbonBar);
    int index = d.pageIndex(page);
    if (index != -1)
        removePage(index);
}

/*!
Removes the page at the given \a index. 
An object that represents the page at position \a index will be destroyed.
\sa detachPage
*/
void RibbonBar::removePage(int index)
{
    QTN_D(RibbonBar);
    RibbonBarAutoUpdater autoUpdater(this);
    d.removePage(index);
    d.m_ribbonTabBar->removeTab(index);
}

/*!
Removes page from the ribbon by the given \a page.
Important: The function does not destroy the page.
\sa removePage
*/
void RibbonBar::detachPage(RibbonPage* page)
{
    QTN_D(RibbonBar);
    int index = d.pageIndex(page);
    if (index != -1)
        detachPage(index);
}

/*!
Removes page from the ribbon by the given position \a index.
Important: The function does not destroy the page at position \a index.
\sa removePage
*/
void RibbonBar::detachPage(int index)
{
    QTN_D(RibbonBar);
    RibbonBarAutoUpdater autoUpdater(this);
    d.removePage(index, false);
    d.m_ribbonTabBar->removeTab(index);
}

/*!
Removes all pages from the ribbon bar.
*/
void RibbonBar::clearPages()
{
    for (int i = pageCount() - 1; i >= 0; i--)
        removePage(i);
}

/*!
Returns the current state of showing Key-Tips. If true then Key-Tips visible on screen at the moment.
*/ 
bool RibbonBar::isKeyTipsShowing() const
{
    QTN_D(const RibbonBar);
    return d.m_keyTipsShowing;
}

/*!
Returns the flag is mechanizm of Key-Tips enabled or not.
*/ 
bool RibbonBar::keyTipsEnabled() const
{
    QTN_D(const RibbonBar);
    return d.m_keyTipsEnabled;
}

/*!
Enabled or disabled mechanizm of Key-Tips.
*/ 
void RibbonBar::setKeyTipsEnable(bool enable)
{
    QTN_D(RibbonBar);
    d.m_keyTipsEnabled = enable;
}


/*!
Returns the policy of assignment for KeyTips of the buttons and other controls. If return value
is true then the keytips assigned automatically, based on keyboard shortcuts <&File, &Open...>. 
If return value is false keytips will be assigned only if user set it by RibbonBar::setKeyTip() function.
\sa setKeyTip()
*/ 
bool RibbonBar::isKeyTipsComplement() const
{
    QTN_D(const RibbonBar);
    return d.m_keyTipsComplement;
}

/*!
The function sets the policy of assignment for KeyTips of the buttons and other controls. If the parameter \a complement
is true then the keytips assigned automatically, based on keyboard shortcuts <&File, &Open...>. 
If parameter \a complement is false keytips will be assigned only if user set it by RibbonBar::setKeyTip() function.
\sa setKeyTip()
*/ 
void RibbonBar::setKeyTipsComplement(bool complement)
{
    QTN_D(RibbonBar);
    d.m_keyTipsComplement = complement;
}

/*!
Sets the \a keyTip for the control associated with given \a action. Function is taken effect if RibbonBar::isKeyTipsComplement() return true.
\sa setKeyTipsComplement()
*/
void RibbonBar::setKeyTip(QAction* action, const QString& keyTip)
{
    if (!action)
    {
        Q_ASSERT(false);
        return;
    }
    action->setProperty(_qtn_KeyTip, keyTip);
}

/*!
Sets custom logo \a pixmap for the ribbon bar. Logo can be aligned at the left or at the right of the ribbon bar. 
*/
void RibbonBar::setLogoPixmap(const QPixmap& pixmap, Qt::AlignmentFlag alignment)
{
    QTN_D(RibbonBar);

    if ( alignment == Qt::AlignRight || alignment == Qt::AlignLeft)
    {
        if (pixmap.isNull())
        {
            Q_ASSERT(false);
            return;
        }
        d.m_logotypeLabel->setPixmap(pixmap);
        d.m_logotypeLabel->setAlignment(alignment);
        d.m_logotypeLabel->setVisible(!pixmap.isNull());
        updateLayout();

        int index = -1;// currentPageIndex();
        if (index != -1)
        {
            if (RibbonPage* p = page(index))
                p->updateLayout();
        }
        return;
    }
    Q_ASSERT(false);
}

/*!
Returns the logo pixmap of the ribbon bar.
*/
QPixmap RibbonBar::logoPixmap() const
{
    QTN_D(const RibbonBar);
    return !d.m_logotypeLabel->isHidden() ? *d.m_logotypeLabel->pixmap() : QPixmap();
}

/*!
Sets the background image for the title of the ribbon bar. 
*/
void RibbonBar::setTitleBackground(const QPixmap& px)
{
    QTN_D(RibbonBar);
    d.m_pixTitleBackground = px;
    update();
}

/*!
Returns the current background image of the ribbon bar title. 
*/
const QPixmap& RibbonBar::titleBackground() const
{
    QTN_D(const RibbonBar);
    return d.m_pixTitleBackground;
}

/*!
Returns pointer to the quick access bar. See description of class RibbonQuickAccessBar for more details.
*/
RibbonQuickAccessBar* RibbonBar::quickAccessBar() const
{
    QTN_D(const RibbonBar);
    return d.m_quickAccessBar;
}

/*!
Sets quick access bar position on the ribbon. \sa QuickAccessBarPosition
*/
void RibbonBar::setQuickAccessBarPosition(RibbonBar::QuickAccessBarPosition position)
{
    QTN_D(RibbonBar);
    if (d.m_quickAccessBarPosition != position)
    {
        d.m_quickAccessBarPosition = position;
        d.updateQuickAccessBarPosition();
        updateLayout();
        updateGeometry();
    }
}

/*!
Retruns current position of quick access bar on the ribbon. \sa QuickAccessBarPosition
*/
RibbonBar::QuickAccessBarPosition RibbonBar::quickAccessBarPosition() const
{
    QTN_D(const RibbonBar);
    return d.m_quickAccessBarPosition;
}

void RibbonBar::setTabBarPosition(RibbonBar::TabBarPosition position)
{
    QTN_D(RibbonBar);
    if (d.m_tabBarPosition != position)
    {
        d.m_tabBarPosition = position;
        updateLayout();
        updateGeometry();
    }
}

RibbonBar::TabBarPosition RibbonBar::tabBarPosition() const
{
    QTN_D(const RibbonBar);
    RibbonBar::TabBarPosition pos = d.m_tabBarPosition;
    if (pos == RibbonBar::TabBarBottomPosition && isMinimized())
        pos = RibbonBar::TabBarTopPosition;
    return pos;
}

/*! \internal */
void RibbonBar::setMinimizedFlag(bool flag)
{
    QTN_D(RibbonBar);
    if (d.m_minimized != flag)
    {
        d.m_minimized = flag;
        d.m_pagePopupWidget->hide();
        d.m_ribbonTabBar->refresh();
        d.preparePages();
        updateLayout();
        if (QLayout* layout = parentWidget()->layout())
            layout->invalidate();
        emit minimizationChanged(d.m_minimized);
    }
}

/*!
Minimizes the ribbon bar if it was maximized before.
This is equivalent of setMinimized(true) or setMaximized(false) call.
*/
void RibbonBar::minimize()
{
    setMinimizedFlag(true);
}

/*!
Returns true if ribbon bar is minimized. Otherwise returns false.
*/
bool RibbonBar::isMinimized() const
{
    QTN_D(const RibbonBar);
    return d.m_minimized;
}

/*!
Sets minimized \a flag for the ribbon bar.
*/
void RibbonBar::setMinimized(bool flag)
{
    setMinimizedFlag(flag);
}

/*!
Maximizes the ribbon bar if it was minimized before.
This is equivalent of setMaximized(true) or setMinimized(false) call.
*/
void RibbonBar::maximize()
{
    setMinimizedFlag(false);
}

/*!
Returns true if ribbon bar is maximized. Otherwise returns false.
*/
bool RibbonBar::isMaximized() const
{
    return !isMinimized();
}

/*!
Sets maximized \a flag for the ribbon bar.
*/
void RibbonBar::setMaximized(bool flag)
{
    setMinimizedFlag(!flag);
}

/*!
Sets the minimization feature of the Ribbon Bar to the \a enabled.
*/ 
void RibbonBar::setMinimizationEnabled(bool enabled)
{
    QTN_D(RibbonBar);
    d.m_minimizationEnabled = enabled;
}

/*!
Returns the enable flag of the minimization feature of the Ribbon Bar.
*/ 
bool RibbonBar::isMinimizationEnabled() const
{
    QTN_D(const RibbonBar);
    return d.m_minimizationEnabled;
}

/*!
Returns customize manager. It is used to configure customization via a special dialog RibbonCustomizeDialog.
\sa RibbonCustomizeDialog
*/ 
RibbonCustomizeManager* RibbonBar::customizeManager()
{
    QTN_D(RibbonBar);
    if (d.m_customizeManager == Q_NULL)
        d.m_customizeManager = new RibbonCustomizeManager(this);
    return d.m_customizeManager;
}

/*!
Returns customize dialog. You can use the reference to add custom setting pages to the standard dialog. 
\sa RibbonCustomizeManager, showCustomizeDialog()
*/
RibbonCustomizeDialog* RibbonBar::customizeDialog()
{
    QTN_D(RibbonBar);
    d.createCustomizeDialog();
    return d.m_customizeDialog;
}

/*!
Shows customization dialog related to customizeDialog() function. Dialog is shown in modal mode to window that holds a ribbon bar.
\sa customizeDialog
*/
void RibbonBar::showCustomizeDialog()
{
    QTN_D(RibbonBar)
    RibbonCustomizeDialog* dialog = customizeDialog();
    Q_ASSERT(dialog != Q_NULL);
    if (QAction* action = qobject_cast<QAction*>(d.sender()))
    {
        if (action->objectName() == strCustomizeQAToolBar)
        {
            RibbonQuickAccessBarCustomizePage* page = Q_NULL;
            for (int i = 0; i < dialog->pageCount(); ++i)
            {
                page = qobject_cast<RibbonQuickAccessBarCustomizePage *>(dialog->pageByIndex(i));
                if (page != Q_NULL)
                {
                    dialog->setCurrentPage(page);
                    break;
                }
            }
        }
        else if (action->objectName() == strCustomizeRibbonBar)
        {
            RibbonBarCustomizePage* page = Q_NULL;
            for (int i = 0; i < dialog->pageCount(); ++i)
            {
                page = qobject_cast<RibbonBarCustomizePage *>(dialog->pageByIndex(i));
                if (page != Q_NULL)
                {
                    dialog->setCurrentPage(page);
                    break;
                }
            }
        }
    }
    dialog->exec();
}

/*!
Make a page in the position specified by \a index, the current one.
*/ 
void RibbonBar::setCurrentPageIndex(int index)
{
    QTN_D(RibbonBar);
    d.m_ribbonTabBar->setCurrentIndex(index);
}

/*!
Returns the index of the current page.
*/ 
int RibbonBar::currentPageIndex() const
{
    QTN_D(const RibbonBar);
    return d.m_ribbonTabBar->currentIndex();
}

/*!
Returns the list of all pages in the ribbon bar.
*/
QList<RibbonPage*> RibbonBar::pages() const
{
    QTN_D(const RibbonBar);
    return d.m_listPages;
}

/*!
Returns the ribbon page by \a index. See description of class RibbonPage for more details.
*/ 
RibbonPage* RibbonBar::page(int index) const
{
    QTN_D(const RibbonBar);
    if (d.isValidIndex(index))
        return d.m_listPages[index];
    return Q_NULL;
}

/*!
Returns the number of the pages inside the ribbon bar.
*/ 
int RibbonBar::pageCount() const
{
    QTN_D(const RibbonBar);
    return d.m_listPages.count();
}

/*!
Adds the menu at the top right ribbon bar with a given \a text. Returns a pointer to the new object QMenu.
*/
QMenu* RibbonBar::addMenu(const QString& text)
{
    QTN_D(RibbonBar);
    return d.m_ribbonTabBar->addMenu(text);
}

/*!
Adds button in the upper part of ribbon bar. 
Parameter \a icon specifies the icon on the button.
Parameter \a text specifies the button text.
Parameter \a style specifies the button style and parameter \a menu specifies the pointer to QMenu object. 
Function returns a pointer to the new QAction object.
*/
QAction* RibbonBar::addAction(const QIcon& icon, const QString& text, Qt::ToolButtonStyle style, QMenu* menu)
{
    QTN_D(RibbonBar);
    QAction* action = d.m_ribbonTabBar->addAction(icon, text, style, menu);
    QMenuBar::addAction(action);
    return action;
}

/*!
Adds button to the upper part of the ribbon bar associated with an existing \a action.
Parameter \a style specifies the style of the button.
*/
QAction* RibbonBar::addAction(QAction* action, Qt::ToolButtonStyle style)
{
    QTN_D(RibbonBar);
    QMenuBar::addAction(action);
    return d.m_ribbonTabBar->addAction(action, style);
}

/*!
Adds system button to the upper left part of ribbon bar.
Parameter \a text specifies the text on the system button.
Function returns a pointer to the new QAction object.
*/
QAction* RibbonBar::addSystemButton(const QString& text)
{
    return addSystemButton(QIcon(), text);
}

/*!
Adds system button to the upper left part of ribbon bar with \a icon.
Parameter \a text specifies the text on the system button.
Parameter icon specifies the icon. Function returns a pointer to the new QAction object.
*/
QAction* RibbonBar::addSystemButton(const QIcon& icon, const QString& text)
{
    QTN_D(RibbonBar);
    QAction* action = d.m_controlSystemButton ? 
        d.m_controlSystemButton->defaultAction() : d.createSystemButton(icon, text);
    if (QMenu* menu = action->menu())
        delete menu;
    RibbonSystemMenu* systemMenu = new RibbonSystemMenu(this);
    action->setMenu(systemMenu);
    return action;
}

/*!
Returns pointer to the RibbonSystemButton object.
*/
RibbonSystemButton* RibbonBar::systemButton() const
{
    QTN_D(const RibbonBar);
    return d.m_controlSystemButton;
}

/*!
Returns the visibility of the BackStage view at the moment.
*/ 
bool RibbonBar::isBackstageVisible() const
{
    QTN_D(const RibbonBar);
    if (d.m_controlSystemButton)
    {
        if (RibbonBackstageView* backstage = qobject_cast<RibbonBackstageView*>(d.m_controlSystemButton->backstage()))
            return backstage->isVisible();
    }
    return false;
}

void RibbonBar::setFrameThemeEnabled(bool enable)
{
#ifndef QTITAN_DESIGNER
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))

    QTN_D(RibbonBar);
    Q_ASSERT(this->parentWidget());
    Q_ASSERT(this->parentWidget()->isTopLevel());
    if (enable)
    {
        WindowTitleBar* titleBar = WindowTitleBar::get(this->parentWidget());
        titleBar->setStyledFrame(style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonStyledFrame));
        titleBar->setSysMenuButtonVisible(style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonsSysMenuButtonVisible));
        titleBar->setBorderThickness(style()->pixelMetric(QStyle::PM_MdiSubWindowFrameWidth, Q_NULL, this->parentWidget()));
        d.m_ribbonTitleBarWidget->setParent(Q_NULL);
        titleBar->setWidget(d.m_ribbonTitleBarWidget, WindowTitleBar::AlignClient);
        titleBar->setVisible(true);
    }
    else
    {
        if (WindowTitleBar* titleBar = d.findTitleBar())
        {
            titleBar->setWidget(Q_NULL);
            titleBar->removeAndDelete();
            d.m_ribbonTitleBarWidget->setParent(this);
            d.m_ribbonTitleBarWidget->setVisible(d.m_showTitleAlways);
        }

    }
    emit frameThemeChanged(isFrameThemeEnabled());
    updateLayout();
#else
    Q_UNUSED(enable)
#endif // QT_VERSION_CHECK
#else
    Q_UNUSED(enable)
#endif // QTITAN_DESIGNER
}

/*!
\property RibbonBar::frameThemeEnabled
    This property holds whether display the content for modern Office 2007, 2010, 2013, 2016 styles on the window title bar and 
    activate Windows Air support (applications under Windows 10, 8, 7, Vista) is enabled. 
    By default parameter is enabled. The property supports Windows, Linux and MacOSX.
\sa WindowTitleBar
\inmodule QtitanRibbon
*/ 
bool RibbonBar::isFrameThemeEnabled() const
{
#ifndef QTITAN_DESIGNER
    QTN_D(const RibbonBar);
    return d.m_ribbonTitleBarWidget != Q_NULL && d.m_ribbonTitleBarWidget->getWindowTitleBar() != Q_NULL;
#else
    return false;
#endif
}

int RibbonBar::backstageViewTop() const
{
    return /*titleBarHeight() +*/ tabBarHeight(true);
}

int RibbonBar::tabBarHeight(bool isVisible) const
{
    QTN_D(const RibbonBar);
    return (d.m_ribbonTabBar && (d.m_ribbonTabBar->isVisible()||isVisible)) ? d.m_ribbonTabBar->height() : 2;
}

/*!
Returns the visible state for the ribbon title bar. By default it is true.
*/
bool RibbonBar::isTitleBarVisible() const
{
    QTN_D(const RibbonBar);
    return isFrameThemeEnabled() || d.m_showTitleAlways;
}

/*!
Sets the \a visible state for the ribbon title bar defined by \a visible parameter.
Note, function makes sense if the Office frame is not used.
*/
void RibbonBar::setTitleBarVisible(bool visible)
{
    QTN_D(RibbonBar);
    if (d.m_showTitleAlways != visible && d.m_ribbonTitleBarWidget != Q_NULL)
    {
        d.m_showTitleAlways = visible;
        d.m_ribbonTitleBarWidget->setVisible(visible);
        d.updateQuickAccessBarPosition();
        updateLayout();
    }
}

/*!
\property RibbonBar::titleGroupsVisible
Sets the visibility of title on all ribbon groups. 
\inmodule QtitanRibbon
*/
bool RibbonBar::isTitleGroupsVisible() const
{
    QTN_D(const RibbonBar);
    return d.m_titleGroupsVisible;
}

void RibbonBar::setTitleGroupsVisible(bool visible)
{
    QTN_D(RibbonBar);
    if (d.m_titleGroupsVisible != visible)
    {
        d.m_titleGroupsVisible = visible;
        for (QList<RibbonPage*>::iterator it = d.m_listPages.begin(); it != d.m_listPages.end(); ++it)
        {
            RibbonPage* page = (*it);
            for (int j = 0, size = page->groupCount(); size > j; ++j)
            {
                if (RibbonGroup* group = page->groupAt(j))
                    group->setProperty(_qtn_TitleGroupsVisible, d.m_titleGroupsVisible);
            }
        }
        updateLayout();
        updateGeometry();
    }
}

int RibbonBar::titleBarHeight() const
{
    QTN_D(const RibbonBar);
    if (!isFrameThemeEnabled() && !d.m_showTitleAlways)
        return 0;
    
    int height = style()->pixelMetric(QStyle::PM_TitleBarHeight, Q_NULL, this->window());

    if (d.m_ribbonTabBar == Q_NULL)
        return height;

    int quickAccessHeight = d.m_quickAccessBar ? d.m_quickAccessBar->sizeHint().height() : 0;
    quickAccessHeight = qMax(quickAccessHeight, height);
    quickAccessHeight = qMax(quickAccessHeight, d.m_ribbonTabBar->height() - 2);

    if (height >= quickAccessHeight)
        return height;

    return quickAccessHeight;
}

int RibbonBar::rowItemHeight() const
{
    QTN_D(const RibbonBar);
    return d.rowItemHeight();
}

int RibbonBar::rowItemCount() const
{
    QTN_D(const RibbonBar);
    return d.rowItemCount();
}

/*!
Performs a full rebuild of the ribbon bar layout.
*/
void RibbonBar::updateLayout()
{
    QTN_D(RibbonBar);
    if (d.m_updateLayoutCount > 0)
        return;
    d.layoutRibbon();
    emit d.updateContextHeaders();
}

/*!
Begin an updating the contents of the ribon bar. 
Use this method to prevent unnecessary calls to rebuild the lay-out at the time of ribbon bar initialization. 
Using the method allows to significantly increase the speed of creation and filling of the ribbon bar.
\sa endUpdate
*/
void RibbonBar::beginUpdate()
{
    QTN_D(RibbonBar);
    d.m_updateLayoutCount++;
    Q_ASSERT(d.m_updateLayoutCount > 0);
}

/*!
Ends the ribbon bar update. The method is always preceded by a call beginUpdate().
*/
void RibbonBar::endUpdate()
{
    QTN_D(RibbonBar);
    d.m_updateLayoutCount--;
    if (d.isUpdating())
        return;
    updateLayout();
}

void QTITAN_PREPEND_NAMESPACE(qtn_set_font_to_ribbon_children)(QWidget* parent, const QFont& font)
{
    QObjectList list = parent->children();
    for (QObjectList::iterator it = list.begin(); it != list.end(); ++it)
    {
        QWidget* widget = qobject_cast<QWidget*>(*it);
        if (widget == Q_NULL)
            continue;

        QMenu* menu = qobject_cast<QMenu*>(widget);
        RibbonPage* page = qobject_cast<RibbonPage*>(widget);
        RibbonBarPagePopup* pagePopup = qobject_cast<RibbonBarPagePopup*>(widget);
        RibbonGroup* group = qobject_cast<RibbonGroup*>(widget);
        if (menu != Q_NULL)
            menu->setFont(QApplication::font(menu));
        if (pagePopup != Q_NULL)
            pagePopup->setFont(pagePopup->ribbonBar()->font());
        else if (page != Q_NULL)
            page->setFont(font);
        else if (group != Q_NULL)
            group->setFont(font);
        else
        {
            widget->setFont(font);
            qtn_set_font_to_ribbon_children(widget, font);
        }
    }
}

/*! \reimp */
bool RibbonBar::event(QEvent* event)
{
    QTN_D(RibbonBar);
    if (event->type() == QEvent::Move || event->type() == QEvent::Resize)
        qtn_fixupQtMainLayout(this);

    bool result = QMenuBar::event(event);
    switch(event->type())
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
                        if (qobject_cast<RibbonPage *>(widget) == Q_NULL)
                            qtn_set_font_to_ribbon_children(widget, f);
                    }
                }
            }
            break;
        case QEvent::StyleChange:
        case QEvent::FontChange:
            {
                d.calcRibbonItemHeight(true);
                if (event->type() == QEvent::StyleChange)
                {
                    CommonStyle::ensureStyle();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
                    if (WindowTitleBar* titleBar = d.findTitleBar())
                    {
                        titleBar->setStyledFrame(style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonStyledFrame));
                        titleBar->setBorderThickness(style()->pixelMetric(QStyle::PM_MdiSubWindowFrameWidth, Q_NULL, this->parentWidget()));

                        WindowTitleBar::SysButtonKind buttonKind = titleBar->sysButtonKind();
                        bool realVisible = buttonKind == WindowTitleBar::SysMenuButton || buttonKind == WindowTitleBar::BackButton;
                        bool buttonVisible = style()->styleHint((QStyle::StyleHint)CommonStyle::SH_RibbonsSysMenuButtonVisible);
                        if (buttonVisible != realVisible)
                            titleBar->setSysMenuButtonVisible(buttonVisible);

                        titleBar->update();
                    }
#endif
                }
#ifdef RIBBON_FONT_SET
                QFont f = font();
#else
                QFont f = QFont();
#endif
                qtn_set_font_to_ribbon_children(this, f);
                updateLayout();
            }
            break;
        case QEvent::LayoutDirectionChange:
        case QEvent::WindowStateChange: 
                updateLayout();
            break;
        case QEvent::WindowTitleChange :
                updateLayout();
            break;
        case QEvent::ActionRemoved :
        case QEvent::ActionChanged :
                QApplication::sendEvent(d.m_ribbonTabBar, event);
            break;
        case QEvent::Show :
        case QEvent::Hide :
            {
                bool show = event->type() == QEvent::Show;
                if (show != d.m_ribbonBarVisible)
                    d.m_ribbonBarVisible = show;
                if (show)
                    updateLayout();
            }
            break;
        default:
            break;
    }
    return result;
}

/*! \reimp */
bool RibbonBar::eventFilter(QObject* object, QEvent* event)
{
    QTN_D(RibbonBar);
    Q_UNUSED(object);
    const QEvent::Type type = event->type();
    if (style()->styleHint(QStyle::SH_MenuBar_AltKeyNavigation, 0, this)) 
    {
        if (d.m_altPressed) 
        {
            switch (type) 
            {
                case QEvent::KeyPress:
                case QEvent::KeyRelease:
                {
                    QKeyEvent* key = static_cast<QKeyEvent*>(event);
                    if (key->key() == Qt::Key_Alt || key->key() == Qt::Key_Meta)
                    {
                        if (event->type() == QEvent::KeyPress) // Alt-press does not interest us, we have the shortcut-override event
                            break;

                        if (keyTipsEnabled())
                            d.setKeyboardMode(!d.m_keyboardState);
                    }
                }
//                break;
                // fall through
                case QEvent::MouseButtonPress:
                case QEvent::MouseButtonRelease:
                case QEvent::MouseMove:
                case QEvent::FocusIn:
                case QEvent::FocusOut:
                case QEvent::ActivationChange:
                    d.m_altPressed = false;
                    qApp->removeEventFilter(this);
                    break;
                default:
                    break;
            }
        }
        else if (isVisible() && !isBackstageVisible())
        {
            if (event->type() == QEvent::ShortcutOverride) 
            {
                QKeyEvent* key = static_cast<QKeyEvent*>(event);
                if ((key->key() == Qt::Key_Alt || key->key() == Qt::Key_Meta) && key->modifiers() == Qt::AltModifier)
                {
                    d.m_altPressed = true;
                    qApp->installEventFilter(this);
                }
            }
        }
    }
    return false;
}

/*! \reimp */
void RibbonBar::paintEvent(QPaintEvent* event)
{
    QTN_D(RibbonBar);
    QWidget* leftCorner = cornerWidget(Qt::TopLeftCorner);
    if(leftCorner && leftCorner->isVisible())
        leftCorner->setVisible(false);

    // draw ribbon
    QPainter p(this);
    QRect rectEvent = event->rect();
    p.setClipRect(rectEvent);

    RibbonStyleOption opt;
    opt.initFrom(this);
    opt.rectTabBar = d.m_ribbonTabBar->geometry();
    opt.minimized = d.m_minimized;
    opt.isBackstageVisible = isBackstageVisible();
    opt.pixTitleBackground = d.m_pixTitleBackground;
    opt.titleBarHeight = titleBarHeight();
    opt.airRegion = event->region();
    opt.quickAccessBarPosition = static_cast<uint>(d.m_quickAccessBarPosition);
    if (d.m_tabBarPosition == RibbonBar::TabBarTopPosition)
        opt.tabBarPosition = RibbonBar::TabBarTopPosition;
    else if (d.m_tabBarPosition == RibbonBar::TabBarBottomPosition)
        opt.tabBarPosition = RibbonBar::TabBarBottomPosition;

    if (RibbonTab* tab = d.m_ribbonTabBar->getTab(d.m_ribbonTabBar->currentIndex()))
    {
        opt.rectCurrentTab = tab->rect();
        QPoint pntrb(tab->mapTo(this, opt.rectCurrentTab.topLeft()));
        opt.rectCurrentTab.translate(pntrb);
    }
    if (RibbonPage* p = page(currentPageIndex()))
        opt.pageColor = p->contextColor();

    p.setBackgroundMode(Qt::TransparentMode);
    if (rectEvent.intersects(opt.rect))
        style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_PanelRibbonBar, &opt, &p, this);

    if (!d.m_minimized && pageCount() > 0 && rectEvent.intersects(opt.rect))
    {
        opt.rect = d.m_rcPageArea;
        if (!d.m_logotypeLabel->isHidden())
        {
            QRect rectPage = opt.rect;
            QRect rect = d.m_logotypeLabel->geometry();
            if (d.m_logotypeLabel->alignment() == Qt::AlignRight)
            {
                rectPage.adjust(0, 0, 4, 0);
                rectPage.setRight(rectPage.right() - rect.width());
                p.setClipRect(rectPage);
            }
            else    
            {
                rectPage.adjust(-2, 0, 0, 0);
                rectPage.setLeft(rect.width());
                p.setClipRect(rectPage);
            }
        }
        style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonFrameGroups, &opt, &p, this);
    }
}

/*! \reimp */
void RibbonBar::changeEvent(QEvent* event)
{
    return QMenuBar::changeEvent(event);
}

/*! \reimp */
void RibbonBar::resizeEvent(QResizeEvent* event)
{
    if (event->oldSize().width() != event->size().width())
        updateLayout();
}

/*! \reimp */
void RibbonBar::mouseDoubleClickEvent(QMouseEvent* event)
{
    QMenuBar::mouseDoubleClickEvent(event);

    if (event->button() != Qt::LeftButton)
        return;
}

/*! \reimp */
void RibbonBar::mousePressEvent(QMouseEvent* event)
{
    // block the function call QMenuBar
    QWidget::mousePressEvent(event);
}

/*! \reimp */
void RibbonBar::wheelEvent(QWheelEvent* event)
{
    QTN_D(RibbonBar);
    if (QApplication::activePopupWidget())
        return;

    if (!isMaximized())
        return;

    QPoint pos = event->pos();

    if (!geometry().contains(pos))
        return;

    d.m_ribbonTabBar->nextTab(event->delta() < 0);
}

void RibbonBar::contextMenuEvent(QContextMenuEvent* event)
{
    QTN_D(RibbonBar)
    if (QMenu* menu = d.createContextMenu()) 
    {
        menu->setAttribute(Qt::WA_DeleteOnClose);
        event->accept();
        emit showRibbonContextMenu(menu, event);
        if (event->isAccepted())
            menu->exec(event->globalPos());
    }
}

int RibbonBar::heightForWidth(int) const
{
    QTN_D(const RibbonBar);
    const int tabsHeight = d.m_ribbonTabBar ? d.m_ribbonTabBar->height() : 0;
    const int ribbonTopBorder = 0;
    const int pageAreaHeight = d.m_rcPageArea.height();

    int height = tabsHeight + pageAreaHeight + ribbonTopBorder;
    if (d.m_ribbonTitleBarWidget != Q_NULL && !d.m_ribbonTitleBarWidget->isHidden() && !isFrameThemeEnabled())
        height += d.m_ribbonTitleBarWidget->height();

    if (d.m_quickAccessBarPosition != RibbonBar::QATopPosition)
        height += d.m_quickAccessBar->sizeHint().height();

    if (d.m_ribbonBarVisible)
        return height;
    return 0;
}

/*! \reimp */
QSize RibbonBar::sizeHint() const
{
    return QSize(minimumWidth(), heightForWidth(0)).expandedTo(QApplication::globalStrut());
}

/*!
Installs translator to QApplication based on \a country variable. Format variable is de_de, ru_ru, fr_fr. If \a country is empty then loaded QTranslator based on current locale setting.
*/
bool RibbonBar::loadTranslation(const QString& country)
{
    static bool loaded = false;
    if (loaded)
        return true;

    const QString directory = QStringLiteral(":/translations/ribbon");
    QTranslator* translator = new QTranslator(qApp);
    if (country.isEmpty())
    {
#if (QT_VERSION >= QT_VERSION_CHECK(4, 8, 0))
        foreach(const QLocale locale, QLocale().uiLanguages())
        {
            if (translator->load(locale, QString(), QString(), directory))
            {
                qApp->installTranslator(translator);
                loaded = true;
                return true;
            }
        }
#endif
    }
    else
    {
        if (translator->load(country, directory))
        {
            qApp->installTranslator(translator);
            loaded = true;
            return true;
        }
    }

    delete translator;
    return false;
}

QString RibbonBar::tr_compatible(const char *s, const char *c)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    return QCoreApplication::translate("Qtitan::RibbonBar", s, c);
#else
    return QCoreApplication::translate("Qtitan::RibbonBar", s, c, QCoreApplication::CodecForTr);
#endif
}
