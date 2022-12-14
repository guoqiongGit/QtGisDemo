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
#ifndef QTN_COMMONSTYLE_H
#define QTN_COMMONSTYLE_H

#include <QProxyStyle>
#include <QStyleOption>

#include "QtitanDef.h"
#include "QtnWindowTitleBar.h"

inline void initBaseResource() { Q_INIT_RESOURCE(QtnBaseResources); }

QTITAN_BEGIN_NAMESPACE

class CommonStylePrivate;

/* CommonStyle */
class QTITAN_BASE_EXPORT CommonStyle : public QProxyStyle
{
    Q_OBJECT
    Q_PROPERTY(bool animationEnabled READ isAnimationEnabled WRITE setAnimationEnabled)
    Q_PROPERTY(bool ignoreDialogs READ isDialogsIgnored WRITE setDialogsIgnored)
    Q_PROPERTY(bool ignoreScrollBars READ isScrollBarsIgnored WRITE setScrollBarsIgnored)
public:
    /*! \internal */
    enum PixelMetricEx
    {
        PM_BaseScrollButtonItem = PM_CustomBase + 1,
        PM_RibbonReducedGroupWidth,
        PM_RibbonHeightCaptionGroup,
        PM_RibbonVMarginCaptionSysMenu,
        PM_RibbonHMarginCaptionSysMenu,
        PM_RibbonPopupMenuGripHeight,
        PM_RibbonQuickAccessBarMargin,
        PM_GridGroupPanelHeight,
        PM_GridSmallToolButtonSize
    };

    /*! \internal */
    enum PrimitiveElementEx
    {
        // PE_CustomBase = 0xf0000000 - base
        PE_PanelRibbonBar = PE_CustomBase + 1,
        PE_RibbonFrameGroups,
        PE_RibbonFrameGroup,
        PE_RibbonFrameGallery,
        PE_RibbonSysFrameMenu,
        PE_RibbonSysFramePagePopupList,
        PE_RibbonSysFramePagePopup,
        PE_RibbonPanelButton,
        PE_RibbonOptionButton,
        PE_RibbonQuickAccessButton,
        PE_RibbonBackstageFrame,
        PE_RibbonBackstagePanelButton,
        PE_RibbonBackstageCloseButton,
        PE_RibbonGroupScrollButton,
        PE_RibbonPopupBarButton,
        PE_RibbonSliderButton,
        PE_RibbonKeyTip,
        PE_RibbonImageBackground,
        PE_DockAutoHideFrameWindow,
        PE_DockMarker,
        PE_DockWidgetPhantom,
        PE_Workspace,
    };

    /*! \internal */
    enum ContentsTypeEx
    {
        CT_RibbonSliderButton = CT_CustomBase + 1,
        CT_RibbonGroupButton,
    };

    /*! \internal */
    enum ControlElementEx
    {
        CE_RibbonTabShapeLabel = CE_CustomBase + 1,
        CE_RibbonTab,
        CE_RibbonTabBar,
        CE_RibbonGroupLabel,
        CE_RibbonSysMenuItem,
        CE_RibbonBackstageMenuItem,
        CE_RibbonBackstageButtonLabel,
        CE_RibbonSysRecentFileItem,
        CE_RibbonButtonLabel,
        CE_RibbonGalleryItem,
        CE_RibbonReducedGroup,
        CE_RibbonGripBar,
        CE_NavigationBackButton
    };

    /*! \internal */
    enum ComplexControlEx
    {
        CC_RibbonFileButton = CC_CustomBase + 1,
        CC_RibbonTitleBarWidget,
        CC_RibbonGalleryButton,
        CC_RibbonBackstageButton,
        CC_RibbonButton,
    };

    /*! \internal */
    enum SubElementEx
    {
        SE_RibbonSysHeaderLabelPopupList = SE_CustomBase + 1,
    };

    /*! \internal */
    enum SubControlEx {
        SC_TitleBarFrame = SC_CustomBase + 1,
    };

    /*! \internal */
    enum StyleHintEx
    {
        SH_QtitanBegin = SH_CustomBase + 1,
        SH_RibbonBegin = SH_QtitanBegin,
        SH_RibbonSysFrameMenu = SH_RibbonBegin,
        SH_RibbonStyledFrame,
        SH_RibbonsSysMenuButtonVisible,
        SH_RecentFileListBackground,
        SH_RibbonItemUpperCase,
        SH_RibbonBackstageHideTabs,
        SH_WindowTitleBarPalette,
        SH_RibbonEnd = SH_WindowTitleBarPalette,
        SH_DockStyledFrame,
        SH_DockSysMenuButtonVisible,
    };

    /*! \internal */
    enum StandardPixmapEx
    {
        SP_RibbonButtonPopupMenu = SP_CustomBase + 1,
        SP_RibbonButtonScrollUp,
        SP_RibbonButtonScrollDown,
        SP_RibbonButtonGroupOption,
        SP_RibbonShadedArrowUp,
        SP_RibbonShadedArrowDown,
        SP_TitleBarPinButton,
        SP_TitleBarPinFillButton,
        SP_TitleBarPinnedButton,
        SP_TitleBarPinnedFillButton,
        SP_NavigationBackButton,

        SP_DockMarkerBasis,
        SP_DockMarkerBasisEx,
        SP_DockMarkerLeft,
        SP_DockMarkerBasisLeft,

        SP_DockMarkerRight,
        SP_DockMarkerBasisRight,

        SP_DockMarkerCenterLeft,
        SP_DockMarkerCenterSplitLeft,

        SP_DockMarkerCenterRight,
        SP_DockMarkerCenterSplitRight,

        SP_DockMarkerCenterTop,
        SP_DockMarkerCenterSplitTop,

        SP_DockMarkerCenterBottom,
        SP_DockMarkerCenterSplitBottom,

        SP_DockMarkerTop,
        SP_DockMarkerBasisTop,

        SP_DockMarkerBottom,
        SP_DockMarkerBasisBottom,
        SP_DockMarkerCenter
    };
public:
    virtual ~CommonStyle();
    static CommonStyle* ensureStyle();
protected:
    CommonStyle(QStyle* style = Q_NULL);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    CommonStyle(const QString& key);
#endif
public:
    bool isAnimationEnabled() const;
    void setAnimationEnabled(bool enabled = true);
    void setDialogsIgnored(bool ignore = false);
    bool isDialogsIgnored() const;

    void setScrollBarsIgnored(bool ignore = false);
    bool isScrollBarsIgnored() const;
public:
    virtual QPalette standardPalette() const;
    virtual void polish(QPalette& palette);
    virtual void polish(QApplication* app);
    virtual void polish(QWidget* widget);
    virtual void unpolish(QApplication* app);
    virtual void unpolish(QWidget* widget);
public:
    virtual QRect itemTextRect(const QFontMetrics& fm, const QRect& r, int flags, bool enabled, const QString& text) const;
    virtual QRect itemPixmapRect(const QRect& r, int flags, const QPixmap& pixmap) const;

    virtual void drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption* opt, QPainter* p, const QWidget* widget = QWIDGET_NULL) const;
    virtual void drawControl(QStyle::ControlElement element, const QStyleOption* opt, QPainter* p, const QWidget* widget = QWIDGET_NULL) const;
    virtual void drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex* opt, QPainter* p, const QWidget* widget = QWIDGET_NULL) const;
    virtual QRect subElementRect(QStyle::SubElement r, const QStyleOption* opt, const QWidget* widget = QWIDGET_NULL) const;
    virtual SubControl hitTestComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex* opt, const QPoint& pt, const QWidget* widget = QWIDGET_NULL) const;
    virtual QRect subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex* opt, SubControl sc, const QWidget* widget = QWIDGET_NULL) const;
    virtual QSize sizeFromContents(QStyle::ContentsType ct, const QStyleOption* opt, const QSize& contentsSize, const QWidget* widget = QWIDGET_NULL) const;

    virtual int pixelMetric(QStyle::PixelMetric m, const QStyleOption* opt = QSTYLEOPTION_NULL, const QWidget* widget = QWIDGET_NULL) const;
    virtual int styleHint(QStyle::StyleHint sh, const QStyleOption* opt = QSTYLEOPTION_NULL, const QWidget* w = QWIDGET_NULL, QStyleHintReturn* shret = Q_NULL) const;
    virtual QIcon standardIcon(QStyle::StandardPixmap standardIcon, const QStyleOption* opt = QSTYLEOPTION_NULL, const QWidget* widget = QWIDGET_NULL) const;
    virtual QPixmap standardPixmap(QStyle::StandardPixmap sp, const QStyleOption* opt = QSTYLEOPTION_NULL, const QWidget* widget = QWIDGET_NULL) const;
    virtual QPixmap generatedIconPixmap(QIcon::Mode iconMode, const QPixmap& pixmap, const QStyleOption* opt) const;

    virtual int layoutSpacing(QSizePolicy::ControlType control1, QSizePolicy::ControlType control2, Qt::Orientation orientation, 
        const QStyleOption *option = QSTYLEOPTION_NULL, const QWidget *widget = QWIDGET_NULL) const;
public:
    void setStyleConfig(const QString& fileName, const QString& themeName);
    static QRgb qtn_lightColor(QRgb clr, int nTint);
    static QRgb qtn_darkColor(QRgb clr, int nShade);
    static QColor qtn_getColorToRGB(Qtitan::ContextColor color);
    static QString qtn_getColorToString(Qtitan::ContextColor color);
    static QImage qtn_addaptColors(const QImage& imageSrc, QRgb clrBase, QRgb clrTone, bool clampHue = true);
    static QImage qtn_invertColors(const QImage& pxSrc);
Q_SIGNALS:
    void widgetPolished(QWidget* w);
protected:
    CommonStyle(CommonStylePrivate& dd);
protected:
    virtual bool event(QEvent* event);
    virtual bool eventFilter(QObject* watched, QEvent* event);
protected:
    QTN_DECLARE_PRIVATE(CommonStyle)
private:
    Q_DISABLE_COPY(CommonStyle)
};

QTITAN_BASE_EXPORT int qtn_DPIScaled(int value, const QWidget* widget);
QTITAN_BASE_EXPORT qreal qtn_DPIScaledF(qreal value, const QWidget* widget);
QTITAN_BASE_EXPORT QPointF qtn_DPIScaledF(const QPointF& point, const QWidget* widget);
QTITAN_BASE_EXPORT QSize qtn_DPIScaled(const QSize& size, const QWidget* widget);
QTITAN_BASE_EXPORT QSizeF qtn_DPIScaledF(const QSizeF& size, const QWidget* widget);
QTITAN_BASE_EXPORT int qtn_getPixelMetric(int metric, const QWidget* widget);
QTITAN_BASE_EXPORT QRect qtn_paint_icon_and_text(QPainter& painter, Qt::LayoutDirection direction,
    const QPalette& palette,
    const QRect& r, const QPixmap& icon, Qt::Alignment iconAlignment,
    const QString& text, Qt::Alignment textAlignment, Qt::TextElideMode textElideMode = Qt::ElideRight,
    int margin = 5, bool* textFullyVisible = Q_NULL,
    const QString& selectedText = QString(), Qt::CaseSensitivity selectCaseSensitivity = Qt::CaseInsensitive);
QTITAN_BASE_EXPORT void qtn_draw_pixmap_texture(QPainter* painter, const QRect& rect, const QPixmap& texture, int left, int top, int right, int bottom);
QTITAN_BASE_EXPORT void qtn_paint_keyboard_focus(QPainter* painter, const QRect& rect, const QColor& color);
QTITAN_BASE_EXPORT bool qtn_isColorLight(const QColor& color);

QTITAN_END_NAMESPACE

#endif // QTN_COMMONSTYLE_H
