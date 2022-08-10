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
#ifndef QTN_STYLEOPTION_H
#define QTN_STYLEOPTION_H

#include <QStyleOption>
#include <QStyleOptionFrame>
#include <QtnCommonStyle.h>
#include "QtitanDef.h"

class QTextDocument;

QTITAN_BEGIN_NAMESPACE

// to support Qt4
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
typedef QStyleOptionFrame QtStyleOptionFrame;
#else
typedef QStyleOptionFrameV3 QtStyleOptionFrame;
#endif

class QTITAN_BASE_EXPORT FrameStyleOption : public QStyleOptionFrame
{
public:
    FrameStyleOption();
    FrameStyleOption(const FrameStyleOption& other);
public:
    Qt::WindowFrameSection section;
};

class QTITAN_BASE_EXPORT BackstageButtonStyleOption : public QStyleOptionToolButton
{
public:
    BackstageButtonStyleOption();
    BackstageButtonStyleOption(const BackstageButtonStyleOption& other);
public:
    bool tabStyle;
    QTextDocument* document;
};

class QTITAN_BASE_EXPORT RibbonBackstageStyleOption : public QStyleOption
{
public:
    RibbonBackstageStyleOption();
    RibbonBackstageStyleOption(const RibbonBackstageStyleOption& other);
public:
    int menuWidth;
};

class QTITAN_BASE_EXPORT RibbonBackgroundStyleOption : public QStyleOption
{
public:
    RibbonBackgroundStyleOption();
    RibbonBackgroundStyleOption(const RibbonBackgroundStyleOption& other);
public:
    int titleBarHeight;
    QPixmap pixTitleBackground;
};

class QTITAN_BASE_EXPORT RibbonStyleOption : public QStyleOption
{
public:
    RibbonStyleOption();
    RibbonStyleOption(const RibbonStyleOption& other);
    ~RibbonStyleOption();
public:
    QRect rectTabBar;
    QRect rectCurrentTab;
    int titleBarHeight;
    bool minimized;
    bool isBackstageVisible;
    uint tabBarPosition;
    uint quickAccessBarPosition;
    Qtitan::ContextColor pageColor;
    QRegion airRegion;
    QPixmap pixTitleBackground;
};

class QTITAN_BASE_EXPORT SystemToolButtonStyleOption : public QStyleOptionToolButton
{
public:
    SystemToolButtonStyleOption();
    SystemToolButtonStyleOption(const SystemToolButtonStyleOption& other);
};

class ContextHeader;
class QTITAN_BASE_EXPORT TitleBarStyleOption : public QStyleOptionTitleBar
{
public:
    TitleBarStyleOption();
    TitleBarStyleOption(const TitleBarStyleOption &other);
    struct ContextData
    {
        ContextData()
            : rect(QRect())
            , strTitle()
            , color(Qtitan::ContextColorNone) {}
        ContextData(const QRect& _rect, const QString& _strTitle, Qtitan::ContextColor _color)
            : rect(_rect)
            , strTitle(_strTitle)
            , color(_color) {}
        QRect rect;
        QString strTitle;
        Qtitan::ContextColor color;
    };
public:
    QRect rcTitleText;
    QRect rectTabBar;
    QRect rcRibbonClient;
    QRect rcQuickAccess;
    bool drawIcon;
    bool isBackstageVisible;
    int menuWidth;
    QPalette paletteBackstageFrameMenu;
    int alignment;
    QVector<ContextData> listContextHeaders;
    QColor clrText;
    QFont fontTextTitle;
    SystemToolButtonStyleOption optButton;
protected:
    TitleBarStyleOption(int version);
};

class QTITAN_BASE_EXPORT CaptionButtonStyleOption : public QStyleOptionToolButton
{
public:
    CaptionButtonStyleOption();
    CaptionButtonStyleOption(const CaptionButtonStyleOption& other);
};

class QTITAN_BASE_EXPORT HintReturnThemeColorStyleOption : public QStyleHintReturn
{
public:
    HintReturnThemeColorStyleOption(const QString& secName, const QString& kName, QColor col = QColor());
    ~HintReturnThemeColorStyleOption();
public:
    QString sectionName;
    QString keyName;
    QColor color;
    bool isValid;
};

class QTITAN_BASE_EXPORT RibbonQuickAccessBarStyleOption : public QStyleOption
{
public:
    RibbonQuickAccessBarStyleOption();
    RibbonQuickAccessBarStyleOption(const RibbonQuickAccessBarStyleOption& other);
public:
    uint quickAccessBarPosition;
    bool roundButton;
};

class QTITAN_BASE_EXPORT RibbonOptionHeaderStyleOption : public QStyleOptionHeader
{
public:
    RibbonOptionHeaderStyleOption();
    RibbonOptionHeaderStyleOption(const RibbonOptionHeaderStyleOption& other);
public:
    bool firstTab;
    bool lastTab;
    bool minimized;
    QRect rcFirst;
    QRect rcLast;
    QString contextText;
    Qtitan::ContextColor pageColor;
    uint tabBarPosition;
};

class QTITAN_BASE_EXPORT RibbonGroupReducedStyleOption : public QStyleOptionToolButton
{
public:
    RibbonGroupReducedStyleOption();
    RibbonGroupReducedStyleOption(const RibbonGroupReducedStyleOption& other);
public:
    Qtitan::ContextColor pageColor;
};

class QTITAN_BASE_EXPORT RibbonGroupStyleOption : public QStyleOption
{
public:
    RibbonGroupStyleOption();
    RibbonGroupStyleOption(const RibbonGroupStyleOption& other);
public:
    int widthOptButton;
    int heightCaption;
    QString text;
    Qt::Alignment textAlignment;
    Qt::TextElideMode textElideMode;
    Qtitan::ContextColor pageColor;
};

class QTITAN_BASE_EXPORT RibbonFrameMenuStyleOption : public QStyleOption
{
public:
    RibbonFrameMenuStyleOption();
    RibbonFrameMenuStyleOption(const RibbonFrameMenuStyleOption& other);
public:
    bool isAdditionalPages;
    int actionsWidth;
    int actionsHeight;
    QMargins margins;
};

class QTITAN_BASE_EXPORT RibbonGalleryItemStyleOption : public QStyleOption
{
public:
    RibbonGalleryItemStyleOption();
    RibbonGalleryItemStyleOption(const RibbonGalleryItemStyleOption& other);
public:
    bool separator;
    QRect rectItem;
    QString caption;
    QIcon icon;
};

class QTITAN_BASE_EXPORT StyleOptionMenuScrollItem : public QStyleOptionMenuItem
{
public:
    StyleOptionMenuScrollItem();
    StyleOptionMenuScrollItem(const StyleOptionMenuScrollItem& other);
public:
    QString toolTip;
};

class QTITAN_BASE_EXPORT HintReturnSysFrameMenuStyleOption : public QStyleHintReturn
{
public:
    HintReturnSysFrameMenuStyleOption(const QMargins& mrgs);
    ~HintReturnSysFrameMenuStyleOption();
public:
    QMargins margins;
};

class QTITAN_BASE_EXPORT AutoHideWindowStyleOption : public QStyleOption
{
public:
    AutoHideWindowStyleOption();
    AutoHideWindowStyleOption(const AutoHideWindowStyleOption& other) : QStyleOption(other) { *this = other; }
public:
    Qtitan::LayoutArea position;
protected:
    AutoHideWindowStyleOption(int version);
};

class QTITAN_BASE_EXPORT DockTitleBarStyleOption : public QStyleOption
{
public:
    DockTitleBarStyleOption();
    DockTitleBarStyleOption(const DockTitleBarStyleOption& other) : QStyleOption(other) 
    { *this = other; }
public:
    QIcon icon;
    QString title;
    QRect rcText;
    QRect rcIcon;
    QRect lineRect;
    bool closable;
    bool movable;
    bool floatable;
    bool autohide;
    bool menu;
    bool verticalTitleBar;
protected:
    DockTitleBarStyleOption(int version);
};

class QTITAN_BASE_EXPORT DockMarkerStyleOption : public QStyleOption
{
public:
    DockMarkerStyleOption();
    DockMarkerStyleOption(const DockMarkerStyleOption& other) : QStyleOption(other)
    { *this = other; }
public:
    QStyle::StandardPixmap sp;
    QPointF position;
    bool basis;
protected:
    DockMarkerStyleOption(int version);
};

class QTITAN_BASE_EXPORT DockPhantomStyleOption : public QStyleOption
{
public:
    DockPhantomStyleOption();
    DockPhantomStyleOption(const DockPhantomStyleOption& other) : QStyleOption(other)
    { *this = other; }
public:
    bool drawFrame;
    Qtitan::LayoutArea posTab;
    int borderWidth;
    QRect rectTab;
protected:
    DockPhantomStyleOption(int version);
};

class QTITAN_BASE_EXPORT DockPaneStyleOption
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    : public QStyleOptionDockWidget
#else
    : public QStyleOptionDockWidgetV2
#endif // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
{
public:
    DockPaneStyleOption();
    DockPaneStyleOption(const DockPaneStyleOption& other)
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        : QStyleOptionDockWidget(other)
#else
        : QStyleOptionDockWidgetV2(other)
#endif // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    {
        *this = other;
    }
public:
    bool autohide;
    bool menu;
protected:
    DockPaneStyleOption(int version);
};

#define QTN_HEADER_OPTION_PROPERTY "qtn_header_style_option"
class QTITAN_BASE_EXPORT GridHeaderStyleOption : public QStyleOptionHeader
{
public:
    enum StyleOptionVersion { Version = QStyleOptionHeader::Version + 100 };
    GridHeaderStyleOption();
    GridHeaderStyleOption(const QStyleOptionHeader& option);
    QMargins margins;
    Qt::TextElideMode textElideMode;
    double scaleFactor;
    QColor decorationColor;
    QTextDocument* textDocument;
};

QTITAN_END_NAMESPACE

#endif // QTN_STYLEOPTION_H
