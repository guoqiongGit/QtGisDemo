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
#ifndef QTN_RIBBONGROUPPRIVATE_H
#define QTN_RIBBONGROUPPRIVATE_H

#include <QIcon>
#include "QtnRibbonGroup.h"
#include "QtnRibbonControls.h"
#include "QtnStyleOption.h"
#include "QtnStyleHelperPrivate.h"
#include "QtitanDef.h"

class QAction;

QTITAN_BEGIN_NAMESPACE

class RibbonGroupOption;
class RibbonGroupScrollButton;
class RibbonControl;
class RibbonGroupPopupMenu;

/* RibbonGroupPrivate */   
class RibbonGroupPrivate : public QObject
{
    Q_OBJECT
    QTN_DECLARE_PUBLIC(RibbonGroup)
public:
    explicit RibbonGroupPrivate();
    virtual ~RibbonGroupPrivate();
    inline static RibbonGroupPrivate* _get(RibbonGroup* group);
public:
    void init();
    void clear(bool deleteControls);
    void enableGroupScroll(bool scrollLeft, bool scrollRight);
    void showGroupScroll();

    void initStyleOption(RibbonGroupStyleOption& opt) const;
    int calcMinimumWidth(RibbonControlSizeDefinition::GroupSize size) const;
    int arrangeRowContent(QList<RibbonControl *>& row, int leftOffset, int rowItemHeight, int rowItemCount, QWidget* parent) const;
    void reposition(const QRect& rect);
    void updateOptionButtonLayout(QWidget* parent);
    QSize updateControlsLayout(QWidget* parent, int leftOffset = 0) const;
    void adjustCurrentSize(bool expand);
    void updateLayoutParent();
    Qt::TextElideMode titleTextElideMode() const;
    QSize sizeHint() const;

    void setReductionSize(RibbonControlSizeDefinition::GroupSize size);
    void reduce();
    void expand();
    bool canReduce();
    bool canExpand();
    RibbonGroupPopupMenu* groupPopupWidget();

    static bool visualIndexLessThan(RibbonControl* first, RibbonControl* second);
public Q_SLOTS:
    void pressLeftScrollButton();
    void pressRightScrollButton();
    void hidePopupMode(QAction* action);
public:
    RibbonGroupOption* m_optionButton;
    RibbonGroupScrollButton* m_buttonScrollGroupLeft;    // Button to draw left scroll
    RibbonGroupScrollButton* m_buttonScrollGroupRight;   // Button to draw right scroll
    RibbonGroupPopupMenu* m_groupPopupWidget;
    RibbonToolBarControl* m_toolBar;

    QList<RibbonControl*> m_controls;
    RibbonControlSizeDefinition::GroupSize m_currentSize;
    Qt::Alignment m_contentAlignment;
    Qt::Alignment m_controlsAlignment;
    int m_spacing;

    bool m_butOptionVisible;
    bool m_dirty;

    QAction* m_actOption;
    QString m_title;
    QIcon m_icon;
    QFont* m_font;
    QColor m_colorText;
    int m_pageScrollPos;
    int m_groupScrollPos;  // Scroll position
    Qt::TextElideMode m_titleElideMode;
private:
    Q_DISABLE_COPY(RibbonGroupPrivate)
};

inline RibbonGroupPrivate* RibbonGroupPrivate::_get(RibbonGroup* group)
{ return &group->qtn_d(); }

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONGROUPPRIVATE_H


