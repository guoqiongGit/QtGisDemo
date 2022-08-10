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
#ifndef QTN_RIBBONSYSTEMMENUPRIVATE_H
#define QTN_RIBBONSYSTEMMENUPRIVATE_H

#include "QtnRibbonSystemMenu.h"
#include "QtnScrollWidgetBar.h"
#include "QtnPopupMenuPrivate.h"

#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

static const int systemPopupBorderLeft = 6;
static const int systemPopupBorderRight = 6;
static const int systemPopupBorderTop = 18;
static const int systemPopupBorderBottom = 29;
static const int splitActionPopupWidth = 20; // Split button drop down width in popups


/* RibbonSystemButtonPrivate */
class RibbonSystemButtonPrivate : public QObject
{
public:
    QTN_DECLARE_PUBLIC(RibbonSystemButton)
public:
    explicit RibbonSystemButtonPrivate()
        : m_widget(Q_NULL) {}
public:
    void updateExtension();
public:
    QWidget* m_widget;
};

/* RibbonSystemMenuButton */
class RibbonSystemMenuButton : public QToolButton
{
    Q_OBJECT
public:
    RibbonSystemMenuButton(QWidget* parent);
    virtual ~RibbonSystemMenuButton();
protected:
    virtual bool event(QEvent* event);
    virtual void paintEvent(QPaintEvent* event);
private:
    Q_DISABLE_COPY(RibbonSystemMenuButton);
};

/* RibbonSystemMenuPrivate */
class RibbonSystemMenuPrivate : public PopupMenuPrivate
{
    QTN_DECLARE_EX_PUBLIC(RibbonSystemMenu)
public:
    explicit RibbonSystemMenuPrivate();
public:
    void initMargins();
public:
    QList<RibbonSystemMenuButton*> m_systemButtonList;
    QList<QWidget*> m_pageList;
    int m_ribbonItemHeight;
private:
    Q_DISABLE_COPY(RibbonSystemMenuPrivate)
};

/* RibbonPageSystemRecentFileListPrivate */
class RibbonPageSystemRecentFileListPrivate : public QObject
{
public:
    QTN_DECLARE_PUBLIC(RibbonPageSystemRecentFileList)
public:
    explicit RibbonPageSystemRecentFileListPrivate();
public:
    void updateActionRects() const;
    void initStyleOption(QStyleOptionMenuItem *option, const QAction *action) const;
    QAction* actionAt(const QPoint& p) const;
    QRect actionRect(QAction* act) const;
    void setCurrentAction(QAction* currentAction);
    void activateAction(QAction* action, QAction::ActionEvent action_e, bool self = true);
public:
    bool m_itemsDirty;
    bool m_mouseDown;
    QAction* m_currentAction;
    QList<QAction*> m_recentFileActs; // contents of the MRU list 
    int m_totalHeight;

    mutable bool m_hasCheckableItems;
    mutable QVector<QRect> m_actionRects;
};

/* RibbonPageSystemPopupPrivate */
class RibbonPageSystemPopupPrivate : public PopupMenuPrivate
{
    QTN_DECLARE_EX_PUBLIC(RibbonPageSystemPopup)
public:
    explicit RibbonPageSystemPopupPrivate() {}
    QSize captionSize() const;
    void initGeometry();
public:
    QString m_caption;
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONSYSTEMMENUPRIVATE_H
