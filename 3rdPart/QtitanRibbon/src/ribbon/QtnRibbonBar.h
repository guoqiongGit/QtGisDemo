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
#ifndef QTN_RIBBONBAR_H
#define QTN_RIBBONBAR_H

#include <QMenuBar>
#include <QMenu>

#include "QtnRibbonDef.h"

inline void initRibbonResource()
{
    Q_INIT_RESOURCE(QtnRibbonResources);
    Q_INIT_RESOURCE(QtnRibbonTranslations);
}

QTITAN_BEGIN_NAMESPACE

class RibbonPage;
class RibbonBarPrivate;
class RibbonSystemButton;
class RibbonSystemMenu;
class RibbonQuickAccessBar;
class RibbonCustomizeManager;
class RibbonCustomizeDialog;

//#define RIBBON_FONT_SET

/* RibbonBar */
class QTITAN_EXPORT RibbonBar : public QMenuBar
{
    Q_OBJECT
    Q_ENUMS(QuickAccessBarPosition)
    Q_ENUMS(TabBarPosition)
    Q_PROPERTY(QuickAccessBarPosition quickAccessBarPosition READ quickAccessBarPosition WRITE setQuickAccessBarPosition)
    Q_PROPERTY(TabBarPosition tabBarPosition READ tabBarPosition WRITE setTabBarPosition)
    Q_PROPERTY(QPixmap imageBackground READ titleBackground WRITE setTitleBackground)
    Q_PROPERTY(int currentPageIndex READ currentPageIndex WRITE setCurrentPageIndex NOTIFY currentPageIndexChanged)
    Q_PROPERTY(bool frameThemeEnabled READ isFrameThemeEnabled WRITE setFrameThemeEnabled NOTIFY frameThemeChanged DESIGNABLE true)
    Q_PROPERTY(bool minimized READ isMinimized WRITE setMinimized NOTIFY minimizationChanged)
    Q_PROPERTY(bool titleGroupsVisible READ isTitleGroupsVisible WRITE setTitleGroupsVisible)
    Q_PROPERTY(bool backstageVisible READ isBackstageVisible)
public:
    enum QuickAccessBarPosition
    {
        QATopPosition = 1,
        QABottomPosition
    };
    enum TabBarPosition
    {
        TabBarTopPosition = 1,
        TabBarBottomPosition
    };
public:
    explicit RibbonBar(QWidget* parent = Q_NULL);
    virtual ~RibbonBar();
public:
    bool isVisible() const;

    RibbonPage* addPage(const QString& text);
    void addPage(RibbonPage* page);
    RibbonPage* insertPage(int index, const QString& text);
    void insertPage(int index, RibbonPage* page);

    void movePage(RibbonPage* page, int newIndex);
    void movePage(int index, int newIndex);

    void removePage(RibbonPage* page);
    void removePage(int index);

    void detachPage(RibbonPage* page);
    void detachPage(int index);

    void clearPages();

    RibbonPage* page(int index) const;
    int pageCount() const;
    int currentPageIndex() const;
    QList<RibbonPage *> pages() const;

    bool isKeyTipsShowing() const;
    bool keyTipsEnabled() const;
    void setKeyTipsEnable(bool enable);
    bool isKeyTipsComplement() const;
    void setKeyTipsComplement(bool complement);
    void setKeyTip(QAction* action, const QString& keyTip);

    void setLogoPixmap(const QPixmap& pixmap, Qt::AlignmentFlag alignment);
    QPixmap logoPixmap() const;

    void setTitleBackground(const QPixmap& px);
    const QPixmap& titleBackground() const;

    RibbonQuickAccessBar* quickAccessBar() const;
    void setQuickAccessBarPosition(QuickAccessBarPosition position);
    QuickAccessBarPosition quickAccessBarPosition() const;

    void setTabBarPosition(TabBarPosition position);
    TabBarPosition tabBarPosition() const;

    void minimize();
    bool isMinimized() const;
    void setMinimized(bool flag);
        
    void maximize();
    bool isMaximized() const;
    void setMaximized(bool flag);

    void setMinimizationEnabled(bool enabled);
    bool isMinimizationEnabled() const;

    RibbonCustomizeManager* customizeManager();
    RibbonCustomizeDialog* customizeDialog();

    static bool loadTranslation(const QString& country = QString()); //Format de_de, fr_fr, ru_ru
    static QString tr_compatible(const char* s, const char* c = Q_NULL);

    QMenu* addMenu(const QString& text);

    using QWidget::addAction;
    QAction* addAction(const QIcon& icon, const QString& text, Qt::ToolButtonStyle style, QMenu* menu = Q_NULL);
    QAction* addAction(QAction* action, Qt::ToolButtonStyle style);

    QAction* addSystemButton(const QString& text);
    QAction* addSystemButton(const QIcon& icon, const QString& text);

    RibbonSystemButton* systemButton() const;
    
    bool isBackstageVisible() const;
    bool isFrameThemeEnabled() const;
    bool isTitleBarVisible() const;
    void setTitleBarVisible(bool visible);
    bool isTitleGroupsVisible() const;
    void setTitleGroupsVisible(bool visible);

    int rowItemHeight() const;
    int rowItemCount() const;
    int titleBarHeight() const;

    void updateLayout();
    void beginUpdate();
    void endUpdate();
public:
    virtual int heightForWidth(int) const;
    virtual QSize sizeHint() const;
public Q_SLOTS:
    void setCurrentPageIndex(int index);
    void showCustomizeDialog();
    void setFrameThemeEnabled(bool enable = true);
Q_SIGNALS:
    void minimizationChanged(bool minimized);
    void pageAboutToBeChanged(RibbonPage* page, bool& changed);
    void currentPageIndexChanged(int index);
    void currentPageChanged(RibbonPage* page);
    void keyTipsShowed(bool showed);
    void showRibbonContextMenu(QMenu* menu, QContextMenuEvent* event);
    void frameThemeChanged(bool enabled);
protected:
    int backstageViewTop() const;
    int tabBarHeight(bool isVisible = false) const;
    void setMinimizedFlag(bool flag);
protected:
    virtual bool event(QEvent* event);
    virtual bool eventFilter(QObject* object, QEvent* event);
    virtual void paintEvent(QPaintEvent* p);
    virtual void changeEvent(QEvent* event);
    virtual void resizeEvent(QResizeEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
    virtual void contextMenuEvent(QContextMenuEvent* event);
private:
    friend class RibbonPage;
    friend class RibbonBackstageViewPrivate;
    friend class RibbonBackstageViewMenu;
    #ifdef Q_OS_WIN
    friend class OfficeFrameHelperWin;
    #endif // Q_OS_WIN
    QTN_DECLARE_PRIVATE(RibbonBar)
    Q_DISABLE_COPY(RibbonBar)
};

class RibbonBarAutoUpdater
{
public:
    RibbonBarAutoUpdater(RibbonBar* ribbonBar)
        : m_ribbonBar(ribbonBar)
    {
        m_ribbonBar->beginUpdate();
    }

    ~RibbonBarAutoUpdater()
    {
        m_ribbonBar->endUpdate();
    }
private:
    RibbonBar* m_ribbonBar;
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONBAR_H


