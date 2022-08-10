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
#include <QApplication>
#include "QtnStyleOption.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

/* FrameStyleOption */
FrameStyleOption::FrameStyleOption()
    : section(Qt::NoSection)
{
}

FrameStyleOption::FrameStyleOption(const FrameStyleOption& other)
    : QStyleOptionFrame(other)
{
    *this = other;
}

/* BackstageButtonStyleOption */
BackstageButtonStyleOption::BackstageButtonStyleOption()
    : tabStyle(false)
    , document(Q_NULL)
{
}

BackstageButtonStyleOption::BackstageButtonStyleOption(const BackstageButtonStyleOption& other)
    : QStyleOptionToolButton(other)
{
    *this = other;
}

/* RibbonBackstageStyleOption */
RibbonBackstageStyleOption::RibbonBackstageStyleOption()
    : menuWidth(-1)
{
}

RibbonBackstageStyleOption::RibbonBackstageStyleOption(const RibbonBackstageStyleOption& other)
    : QStyleOption(Version, Type)
{
    *this = other;
}

/* RibbonBackgroundStyleOption */
RibbonBackgroundStyleOption::RibbonBackgroundStyleOption()
    : titleBarHeight(0)
{
}

RibbonBackgroundStyleOption::RibbonBackgroundStyleOption(const RibbonBackgroundStyleOption& other)
    : QStyleOption()
{
    *this = other;
}

/* RibbonStyleOption */
RibbonStyleOption::RibbonStyleOption()
    : titleBarHeight(0)
    , minimized(false)
    , isBackstageVisible(false)
    , tabBarPosition(1)
    , quickAccessBarPosition(1)
    , pageColor(Qtitan::ContextColorNone)
{
}

RibbonStyleOption::RibbonStyleOption(const RibbonStyleOption& other)
    : QStyleOption(Version, Type)
{
    *this = other;
}

RibbonStyleOption::~RibbonStyleOption()
{
}

/* SystemToolButtonStyleOption */
SystemToolButtonStyleOption::SystemToolButtonStyleOption()
{
}

SystemToolButtonStyleOption::SystemToolButtonStyleOption(const SystemToolButtonStyleOption& other)
    : QStyleOptionToolButton(other)
{
    *this = other;
}

/* TitleBarStyleOption */
TitleBarStyleOption::TitleBarStyleOption()
    : drawIcon(true)
    , isBackstageVisible(false)
    , menuWidth(0)
    , alignment(0)
    , clrText()
    , fontTextTitle(QApplication::font("QMdiSubWindowTitleBar"))
{
}

TitleBarStyleOption::TitleBarStyleOption(const TitleBarStyleOption &other)
    : QStyleOptionTitleBar(other)
{
    *this = other;
}

/* CaptionButtonStyleOption */
CaptionButtonStyleOption::CaptionButtonStyleOption()
{
}

CaptionButtonStyleOption::CaptionButtonStyleOption(const CaptionButtonStyleOption& other)
    : QStyleOptionToolButton(other)
{
    *this = other;
}


/* HintReturnThemeColorStyleOption */
HintReturnThemeColorStyleOption::HintReturnThemeColorStyleOption(const QString& secName, const QString& kName, QColor col)
    : QStyleHintReturn()
    , sectionName(secName)
    , keyName(kName)
    , color(col)
    , isValid(true)
{
}

HintReturnThemeColorStyleOption::~HintReturnThemeColorStyleOption()
{
}

/*! RibbonQuickAccessBarStyleOption */
RibbonQuickAccessBarStyleOption::RibbonQuickAccessBarStyleOption()
    : quickAccessBarPosition(1)
    , roundButton(false)
{
}

RibbonQuickAccessBarStyleOption::RibbonQuickAccessBarStyleOption(const RibbonQuickAccessBarStyleOption& other)
    : QStyleOption(other)
{
    *this = other;
}

/* RibbonOptionHeaderStyleOption */
RibbonOptionHeaderStyleOption::RibbonOptionHeaderStyleOption()
    : QStyleOptionHeader()
    , firstTab(false)
    , lastTab(false)
    , minimized(false)
    , pageColor(Qtitan::ContextColorNone)
    , tabBarPosition(1)
{
}

RibbonOptionHeaderStyleOption::RibbonOptionHeaderStyleOption(const RibbonOptionHeaderStyleOption& other)
    : QStyleOptionHeader(other)
    , firstTab(other.firstTab)
    , lastTab(other.lastTab)
    , minimized(other.minimized)
    , rcFirst(other.rcFirst)
    , rcLast(other.rcLast)
    , contextText(other.contextText)
    , pageColor(other.pageColor)
    , tabBarPosition(other.tabBarPosition)
{
    *this = other;
}

/* RibbonGroupReducedStyleOption */
RibbonGroupReducedStyleOption::RibbonGroupReducedStyleOption()
    : QStyleOptionToolButton()
    , pageColor(Qtitan::ContextColorNone)
{
}

RibbonGroupReducedStyleOption::RibbonGroupReducedStyleOption(const RibbonGroupReducedStyleOption& other)
    : QStyleOptionToolButton(other)
    , pageColor(other.pageColor)
{
    *this = other;
}

/* RibbonGroupStyleOption */
RibbonGroupStyleOption::RibbonGroupStyleOption()
    : QStyleOption()
    , widthOptButton(0)
    , heightCaption(0)
    , textAlignment(Qt::AlignCenter)
    , textElideMode(Qt::ElideNone)
    , pageColor(Qtitan::ContextColorNone)
{
}

RibbonGroupStyleOption::RibbonGroupStyleOption(const RibbonGroupStyleOption& other)
    : QStyleOption(other)
    , widthOptButton(other.widthOptButton)
    , heightCaption(other.heightCaption)
    , text(other.text)
    , textAlignment(other.textAlignment)
    , textElideMode(other.textElideMode)
    , pageColor(other.pageColor)
{
    *this = other;
}

/* RibbonFrameMenuStyleOption */
RibbonFrameMenuStyleOption::RibbonFrameMenuStyleOption()
    : isAdditionalPages(false)
    , actionsWidth(0)
    , actionsHeight(0)
    , margins()
{
}

RibbonFrameMenuStyleOption::RibbonFrameMenuStyleOption(const RibbonFrameMenuStyleOption& other)
    : QStyleOption(other)
    , isAdditionalPages(other.isAdditionalPages)
    , actionsWidth(other.actionsWidth)
    , actionsHeight(other.actionsHeight)
    , margins(other.margins)
{
    *this = other;
}

/* RibbonGalleryItemStyleOption */
RibbonGalleryItemStyleOption::RibbonGalleryItemStyleOption()
    : separator(false)
    , rectItem(QRect())
    , icon()
{
}

RibbonGalleryItemStyleOption::RibbonGalleryItemStyleOption(const RibbonGalleryItemStyleOption& other)
    : QStyleOption(other)
    , separator(other.separator)
    , rectItem(other.rectItem)
    , caption(other.caption)
    , icon(other.icon)
{
    *this = other;
}

/* StyleOptionMenuScrollItem */
StyleOptionMenuScrollItem::StyleOptionMenuScrollItem()
{
}

StyleOptionMenuScrollItem::StyleOptionMenuScrollItem(const StyleOptionMenuScrollItem& other) 
    : QStyleOptionMenuItem(other)
    , toolTip(other.toolTip)
{ 
    *this = other; 
}


/* HintReturnSysFrameMenuStyleOption */
HintReturnSysFrameMenuStyleOption::HintReturnSysFrameMenuStyleOption(const QMargins& mrgs)
    : QStyleHintReturn()
    , margins(mrgs)
{
}

HintReturnSysFrameMenuStyleOption::~HintReturnSysFrameMenuStyleOption()
{
}

/* AutoHideWindowStyleOption */
AutoHideWindowStyleOption::AutoHideWindowStyleOption()
    : QStyleOption(Version)
    , position(Qtitan::LeftArea)
{
}

AutoHideWindowStyleOption::AutoHideWindowStyleOption(int version)
    : QStyleOption(version)
    , position(Qtitan::LeftArea)
{
}

/* DockTitleBarStyleOption */
DockTitleBarStyleOption::DockTitleBarStyleOption()
    : QStyleOption(Version)
    , lineRect()
    , closable(false)
    , movable(false)
    , floatable(false)
    , autohide(false)
    , menu(false)
    , verticalTitleBar(false)
{
}

DockTitleBarStyleOption::DockTitleBarStyleOption(int version)
    : QStyleOption(version)
    , lineRect()
    , closable(false)
    , movable(false)
    , floatable(false)
    , autohide(false)
    , menu(false)
    , verticalTitleBar(false)
{
}

/* DockMarkerStyleOption */
DockMarkerStyleOption::DockMarkerStyleOption()
    : QStyleOption(Version)
    , sp(static_cast<QStyle::StandardPixmap>(CommonStyle::SP_DockMarkerBasis))
    , basis(false)
{
}

DockMarkerStyleOption::DockMarkerStyleOption(int version)
    : QStyleOption(version)
    , sp(static_cast<QStyle::StandardPixmap>(CommonStyle::SP_DockMarkerBasis))
    , basis(false)
{
}

/* DockPhantomStyleOption */
DockPhantomStyleOption::DockPhantomStyleOption()
    : QStyleOption(Version)
    , drawFrame(false)
    , posTab(Qtitan::DefaultArea)
    , borderWidth(7)
{
}

DockPhantomStyleOption::DockPhantomStyleOption(int version)
    : QStyleOption(version)
    , drawFrame(false)
    , posTab(Qtitan::DefaultArea)
    , borderWidth(7)
{
}


/* DockPaneStyleOption */
DockPaneStyleOption::DockPaneStyleOption()
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    : QStyleOptionDockWidget(Version)
#else
    : QStyleOptionDockWidgetV2(Version)
#endif // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    , autohide(false)
    , menu(false)
{
}

DockPaneStyleOption::DockPaneStyleOption(int version)
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    : QStyleOptionDockWidget(version)
#else
    : QStyleOptionDockWidgetV2(version)
#endif // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    , autohide(false)
    , menu(false)
{
}

/* GridHeaderStyleOption */
GridHeaderStyleOption::GridHeaderStyleOption()
    : QStyleOptionHeader(GridHeaderStyleOption::Version),
    margins(QMargins()), textElideMode(Qt::ElideRight),
    scaleFactor(1.0), decorationColor(Qt::transparent), textDocument(Q_NULL)
{
}

GridHeaderStyleOption::GridHeaderStyleOption(const QStyleOptionHeader& option)
    : QStyleOptionHeader(option),
    margins(QMargins()), textElideMode(Qt::ElideRight),
    scaleFactor(1.0), decorationColor(Qt::transparent), textDocument(Q_NULL)
{
    version = GridHeaderStyleOption::Version;
}
