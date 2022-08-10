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
#ifndef QTN_OFFICE2013STYLEPRIVATE_H
#define QTN_OFFICE2013STYLEPRIVATE_H

#include "QtnCommonStylePrivate.h"
#include "QtnOfficeStylePrivate.h"
#include "QtnOffice2013Style.h"

QTITAN_BEGIN_NAMESPACE

class Office2013StylePrivate : public OfficeStylePrivate
{
    Q_OBJECT
public:
    QTN_DECLARE_EX_PUBLIC(Office2013Style)
public:
    explicit Office2013StylePrivate();
    virtual ~Office2013StylePrivate();
public:
    void initialization();
    QColor accentIndexToColor(OfficeStyle::AccentColor accentcolor) const;
    virtual void initStandardPalette(QPalette& palette) const;
public:
    // for standard controls
    // draw PrimitiveElement
    virtual bool drawFrame(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawFrameWindow(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawFrameMenu(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawPanelMenu(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawPanelStatusBar(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawIndicatorToolBarSeparator(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawFrameGroupBox(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawIndicatorCheckBox(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawIndicatorRadioButton(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawIndicatorMenuCheckMark(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawIndicatorButtonDropDown(const QStyleOption*, QPainter*, const QWidget*) const;
    virtual bool drawPanelButtonBevel(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawIndicatorToolBarHandle(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawFrameTabBarBase(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawFrameFocusRect(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    // PE - ButtonTool
    virtual bool drawPanelButtonTool(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawFrameLineEdit(const QStyleOption* opt, QPainter* p, const QWidget* w) const;
    virtual bool drawPanelButtonCommand(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    // draw ComplexControl
    virtual bool drawRibbonFileButton(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* widget = Q_NULL) const;
    virtual bool drawRibbonTitleBarWidget(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawTitleBar(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawScrollBar(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawComboBox(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawSlider(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawSpinBox(const QStyleOptionComplex* opt, QPainter* painter, const QWidget* w) const;
    // draw ControlElement
    virtual bool drawRibbonTabShapeLabel(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonTab(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonTabBar(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonGalleryItem(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual void drawMenuItemSeparator(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawShapedFrame(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawMenuItem(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawSizeGrip(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawToolBar(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawScrollBarAddSubLine(QStyle::ControlElement ce, const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawScrollBarAddSubPage(QStyle::ControlElement ce, const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawScrollBarSlider(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawToolBoxTabShape(const QStyleOption* opt, QPainter* p, const QWidget* w) const;
    virtual bool drawTabBarTabShape(const QStyleOption* opt, QPainter* p, const QWidget* w) const;
    virtual bool drawHeaderSection(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    virtual bool drawDockWidgetTitle(const QStyleOption* opt, QPainter* painter, const QWidget* w) const;
    ///////////////////////////////////////////////////////////////////////////////
    // for RibbonBar
    // draw PrimitiveElement
    virtual bool drawRibbonBar(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonFrameGroup(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonFrameGallery(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonImageBackground(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonBackstageFrame(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawRibbonBackstageCloseButton(const QStyleOption* opt, QPainter* p, const QWidget* widget) const;
    virtual bool drawRibbonSliderButton(const QStyleOption* opt, QPainter* p, const QWidget* w = Q_NULL) const;
    virtual bool drawPanelTipLabel(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;
    virtual bool drawKeyTip(const QStyleOption* opt, QPainter* painter, const QWidget* w = Q_NULL) const;

    virtual int ribbonStyleHint(QStyle::StyleHint stylehint, const QStyleOption* opt, const QWidget* widget, QStyleHintReturn* returnData) const;
protected:
    virtual void drawHighlightItemGallery(const QStyleOption* option, QPainter* painter, const QWidget* widget) const;
protected:
    virtual QColor textGalleryItem(const QPalette& pal) const;
    virtual QColor darkBackgroundLight(const QPalette& pal) const;
    virtual QColor buttonHighlightColor(const QPalette& pal, bool highlightDn, bool border = false, const QWidget* wd = Q_NULL) const;
    virtual QColor fillTitleBarColor(const QPalette& /*pal*/, bool isBackstageVisible) const;
    virtual QColor textRibbonTabBarColor(const QStyleOption* /*opt*/) const { return m_clrAccent; }
    virtual QColor buttonRibbonFileColor(const SystemToolButtonStyleOption* /*opt*/) const;
    virtual QColor fillBackstageFrameColor(const QPalette& /*pal*/) const;
    virtual QColor titleBarWindowColor(const QPalette& pal, bool isActive, const QWidget* wd) const;
    virtual QColor titleBarFrameColor(const QPalette& pal, bool isActive, const QWidget* wd) const;
protected:
    virtual QBrush brushFromConfig(const QString& className, const QString& subControlId, QPalette::ColorGroup group, 
        QPalette::ColorRole role, QStyle::State state, bool isBackstageVisible) const;
    static QWidget* qtn_findRibbonBar(const QWidget* parent);
    static bool qtn_isBackstageVisible(const QWidget* widget);
public:
    virtual void updateTheme();
    virtual QPalette getWidgetPalette(QWidget* widget) const;
public:
    uint m_themeType;
    OfficeStyle::OfficePopupDecoration m_typePopupStyle;
};

QTITAN_END_NAMESPACE

#endif // QTN_OFFICE2013STYLEPRIVATE_H
