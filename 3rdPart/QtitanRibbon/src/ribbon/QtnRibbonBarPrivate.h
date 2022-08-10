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
#ifndef QTN_RIBBONBARPRIVATE_H
#define QTN_RIBBONBARPRIVATE_H

#include <QStyle>
#include <QStack>
#include <QLabel>
#include <QPointer>
#include <QMdiSubWindow>

#include "QtitanDef.h"
#include "QtnRibbonBar.h"
#include "QtnRibbonTabBar.h"
#include "QtnRibbonCustomizePage.h"
#include "QtnRibbonQuickAccessBar.h"
#include "QtnRibbonTitleBarWidgetPrivate.h"
#include "QtnRibbonSystemMenu.h"

QTITAN_BEGIN_NAMESPACE

#define _qtn_Index                  "Index"
#define _qtn_Wrap                   "Wrap"
#define _qtn_Wrap_Group             "WrapGroup"

#define _qtn_Begin_Group            "BeginToolBarGroup"
#define _qtn_Group                  "ToolBarGroup"
#define _qtn_End_Group              "EndToolBarGroup"

#define _qtn_Index_Group            "IndexGroup"
#define _qtn_Switch_Count           "SwitchCount"
#define _qtn_KeyTip                 "Qtitan::KeyTip"

class LogotypeLabel : public QLabel
{
public:
    LogotypeLabel(QWidget* parent);
public:
    Qt::AlignmentFlag alignment() const  { return m_alignment; }
    void setAlignment(Qt::AlignmentFlag alignment) { m_alignment = alignment; }
protected:
    virtual void paintEvent(QPaintEvent* p);
private:
    Qt::AlignmentFlag m_alignment;
};

class RibbonTitleButton;
class TitleBarStyleOption;
class RibbonBackstageCloseButton;
class MenuMinimizedGroups;
class RibbonKeyTip;
class RibbonCustomizeManager;
/* RibbonBarPrivate */
class RibbonBarPagePopup : public QWidget
{
    Q_OBJECT
public:
    RibbonBarPagePopup(RibbonBar* ribbonBar);
    RibbonBar* ribbonBar() const;
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual bool event(QEvent* event);
private:
    RibbonBar* m_ribbonBar;
};

/* RibbonToolTip */
class RibbonToolTipManager : public QObject
{
public:
    explicit RibbonToolTipManager(QObject* parent);
    virtual ~RibbonToolTipManager();
protected:
    bool showToolTip(const QPoint& pos, QWidget* w);
protected:
    virtual bool eventFilter(QObject*, QEvent* event);
};

class RibbonBarPrivate;
/* CornerButtonsUpdate */
class CornerButtonsUpdater : public QObject
{
    Q_OBJECT
public:
    CornerButtonsUpdater(RibbonBar* parent);
    virtual ~CornerButtonsUpdater();
protected:
    virtual bool eventFilter(QObject*, QEvent* event);
protected:
    RibbonBar* m_ribbon;
};


/* RibbonBarPrivate */
class RibbonBarPrivate : public QObject
{
public:
    Q_OBJECT
    QTN_DECLARE_PUBLIC(RibbonBar)
public:
    explicit RibbonBarPrivate();
    virtual ~RibbonBarPrivate();
    inline static RibbonBarPrivate* _get(RibbonBar* ribbon)
    { return &ribbon->qtn_d(); }
    inline static const RibbonBarPrivate* _get(const RibbonBar* ribbon)
    { return &ribbon->qtn_d(); }
public:
    void init(); 
    void calcRibbonItemHeight(bool calc = false);
    void calcHeightItem();

    void layoutRibbon();
    void layoutCorner();
    void createRibbonTitleBarWidget();
    void deleteRibbonTitleBarWidget();
    void setVisibleBackstage(bool visible);
    void updateQuickAccessBarPosition();

    QAction* createSystemButton(const QIcon& icon, const QString& text);

    void insertPage(int indTab, int index, RibbonPage* page);
    void removePage(int index, bool deletePage = true);
    int pageIndex(RibbonPage* page) const;

    inline bool isValidIndex(int index) const;
    inline int heightTabs() const;

    QMenu* createContextMenu();
    void setKeyboardMode(bool b);
    void showKeyTips(QWidget* w);
    bool hideKeyTips();
    void createKeyTips();
    void createGroupKeyTips();
    void createWidgetKeyTips(RibbonGroup* group, QWidget* widget, const QString& prefix, const QRect& rcGroups, bool visible);
    bool createPopupKeyTips(QMenu* levalMenu);
    void destroyKeyTips();
    void calcPositionKeyTips();
    int rowItemHeight() const;
    int rowItemCount() const;
    int maxGroupHeight() const;
    void createCustomizeDialog();
    void showPagePopup(RibbonPage* page);
    void hidePagePopup();
    bool isPagePopupVisible() const;
    void preparePages();
    QWidget* getPageParent();
    WindowTitleBar* findTitleBar() const;
    bool isUpdating() const;
public Q_SLOTS:
    void toggledCustomizeBar();
    void toggledQuickAccessBarPos();
    void toggledMinimized();
    void currentTabBarChanged(int index);
Q_SIGNALS:
    void updateContextHeaders();
protected:
    bool pressTipCharEvent(const QKeyEvent* key);
    virtual bool eventFilter(QObject*, QEvent* event);
public:
    QRect m_rcPageArea;
    int m_heightTabs;
    int m_ribbonItemHeight;
    RibbonToolTipManager* m_ribbonToolTipManager;
    RibbonTitleBarWidget* m_ribbonTitleBarWidget;
    RibbonTabBar* m_ribbonTabBar;
    RibbonBarPagePopup* m_pagePopupWidget;
    RibbonQuickAccessBar* m_quickAccessBar; 
    RibbonSystemButton* m_controlSystemButton;
    QVector<QWidget*> m_visibleWidgets;

    bool m_saveVisibleSysMenu;
    bool m_showTitleAlways;
    bool m_ribbonBarVisible;
    bool m_minimizationEnabled;
    bool m_minimized;
    bool m_keyboardState;
    bool m_altPressed;
    bool m_keyTipsComplement;
    bool m_keyTipsEnabled;
    bool m_keyTipsShowing;
    bool m_titleGroupsVisible;
    QPointer<QWidget> m_keyboardFocusWidget;
    RibbonBar::QuickAccessBarPosition m_quickAccessBarPosition;
    RibbonBar::TabBarPosition m_tabBarPosition;

    QList<RibbonKeyTip*> m_keyTips;
    QStack<QWidget*> m_levels;
    int m_countKey;

    QStyle::SubControl m_hoveredSubControl;
    QStyle::SubControl m_activeSubControl;

    LogotypeLabel* m_logotypeLabel;

    QPixmap m_pixTitleBackground;
    RibbonCustomizeManager* m_customizeManager;
    RibbonCustomizeDialog* m_customizeDialog;
    CornerButtonsUpdater* m_buttonsUpdater;
protected:
    QList<RibbonPage *> m_listPages;
    QFont m_oldfontRegular;
    int m_oldDpi;
    int m_rowItemCount;
    int m_updateLayoutCount;
private:
    Q_DISABLE_COPY(RibbonBarPrivate)
};

/*! \internal */
inline bool RibbonBarPrivate::isValidIndex(int index) const
{ return index >= 0 && index < m_listPages.count(); }

/*! \internal */
inline int RibbonBarPrivate::heightTabs() const
{ return m_heightTabs;}

template<class T>
const T* qtn_getParentWidget(const QWidget* widget)
{
    while (widget)
    {
        if (const T* parent = qobject_cast<const T*>(widget))
            return parent;
        widget = widget->parentWidget();
    }
    return Q_NULL;
}

template<class T>
static QWidget* qtn_getPrevParentWidget(QWidget* pWidget)
{
    if (qobject_cast<T*>(pWidget))
        return Q_NULL;

    QWidget* pPrevWidget = pWidget;
    while (pWidget)
    {
        pWidget = pWidget->parentWidget();
        if (qobject_cast<T*>(pWidget))
            return pPrevWidget;
        else
            pPrevWidget = pWidget;
    }
    return Q_NULL;
}

extern void qtn_set_font_to_ribbon_children(QWidget* widget, const QFont& font);

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONPRIVATE_H


