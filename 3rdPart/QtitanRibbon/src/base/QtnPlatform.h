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

#ifndef QTN_PLATFORM_H
#define QTN_PLATFORM_H

#include "QtitanDef.h"

#include <QWidget>
#include <QMouseEvent>
#include <QStyleOption>

#ifdef Q_OS_WIN
#include "QtnPlatform_win.h"
#endif
#ifdef Q_OS_LINUX
#endif
#ifdef Q_OS_MAC
#endif

QT_BEGIN_NAMESPACE

class MouseEventQt : public QMouseEvent
{
public:
    MouseEventQt(MouseEventQt& e) : QMouseEvent(e) {}
    MouseEventQt(QMouseEvent& e) : QMouseEvent(e) {}
    void setPos(const QPoint& pos) {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))        
        this->l = pos;
        this->w = pos;
#else
        this->p = pos;
#endif
    }
};

class WheelEventQt : public QWheelEvent
{
public:
    WheelEventQt(WheelEventQt& e) : QWheelEvent(e) {}
    WheelEventQt(QWheelEvent& e) : QWheelEvent(e) {}
    void setPos(const QPoint& pos) {
        this->p = pos;
    }
};

class ContextMenuEventQt : public QContextMenuEvent
{
public:
    ContextMenuEventQt(ContextMenuEventQt& e) : QContextMenuEvent(e) {}
    ContextMenuEventQt(QContextMenuEvent& e) : QContextMenuEvent(e) {}
    void setPos(const QPoint& pos) {
        this->p = pos;
    }
};

class PaintEventQt : public QPaintEvent
{
public:
    PaintEventQt(PaintEventQt& e) : QPaintEvent(e) {}
    PaintEventQt(QPaintEvent& e) : QPaintEvent(e) {}
    void setRect(const QRect& rect) { this->m_rect = rect; }
    void setRegion(const QRegion& region) { this->m_region = region; }
};

Q_GUI_EXPORT void qt_blurImage(QImage &blurImage, qreal radius, bool quality, int transposed = 0);
Q_GUI_EXPORT void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0);
Q_GUI_EXPORT QImage qt_halfScaled(const QImage &source);

QT_END_NAMESPACE

QTITAN_BEGIN_NAMESPACE

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
enum HBitmapFormat
{
    HBitmapNoAlpha,
    HBitmapPremultipliedAlpha,
    HBitmapAlpha
};
#endif

#ifdef Q_OS_MAC
bool qtn_set_window_hook(QWidget* w);
bool qtn_unset_window_hook(QWidget* w);
bool qtn_set_window_frameless_mac(QWidget* w);
void qtn_paint_title_bar_mac(const QStyleOptionComplex *option, QPainter* painter, const QWidget *widget);
bool qtn_window_start_native_drag_mac(QWidget* w, const QPoint& pos);
void qtn_window_resize_mac(QWidget* w);
QPixmap qtn_titlebar_standard_pixmap(QStyle::StandardPixmap sp, const QStyleOption* opt, const QWidget* widget);
Qt::MouseButtons qtn_get_mouseButtons_mac();
#endif
#ifdef Q_OS_LINUX
bool qtn_window_start_native_drag_linux(QWidget* w, const QPoint& pos, Qt::WindowFrameSection frameSection);
Qt::MouseButtons qtn_get_mouseButtons_linux();
QRect qtn_get_window_geometry_linux(QWidget* w);
#endif

QTITAN_BASE_EXPORT void qtn_initializeDrawingResources();
QTITAN_BASE_EXPORT void qtn_setWidgetPostion(QWidget* widget, const QPoint& position);
QTITAN_BASE_EXPORT void qtn_paintAirEffect(QPainter* painter, const QRect& rect, const QRegion& clip);
QTITAN_BASE_EXPORT bool qtn_setBlurBehindWindow(QWidget* widget, bool enabled);
QTITAN_BASE_EXPORT bool qtn_blurBehindEnabled(QWidget* widget);
QTITAN_BASE_EXPORT bool qtn_blurBehindSupported();
QTITAN_BASE_EXPORT QColor qtn_getColorizationColor();
QTITAN_BASE_EXPORT void qtn_initTitleBarPalette(QPalette& palette);
QTITAN_BASE_EXPORT bool qtn_getDesktopLightTheme();
QTITAN_BASE_EXPORT int qtn_getWindowDPI(const QWidget* window);

QTITAN_BASE_EXPORT QSize qtn_fromNativeDPI(const QSize& size, const QWidget* window);
QTITAN_BASE_EXPORT QSize qtn_toNativeDPI(const QSize& size, const QWidget* window);
QTITAN_BASE_EXPORT QRect qtn_fromNativeDPI(const QRect& rect, const QWidget* window);
QTITAN_BASE_EXPORT QRect qtn_toNativeDPI(const QRect& rect, const QWidget* window);
QTITAN_BASE_EXPORT QPoint qtn_fromNativeDPI(const QPoint& point, const QWidget* window);
QTITAN_BASE_EXPORT QPoint qtn_toNativeDPI(const QPoint& point, const QWidget* window);
QTITAN_BASE_EXPORT QMargins qtn_fromNativeDPI(const QMargins& margins, const QWidget* window);
QTITAN_BASE_EXPORT QMargins qtn_toNativeDPI(const QMargins& margins, const QWidget* window);
QTITAN_BASE_EXPORT QRegion qtn_toNativeDPI(const QRegion& region, const QWidget* window);
QTITAN_BASE_EXPORT qreal qtn_pixelRatioDPI(const QWidget* window);
QTITAN_BASE_EXPORT bool qtn_isDPIScalingActive();

QTITAN_BASE_EXPORT bool qtn_image_copy(QImage& dest, const QPoint& p, const QImage& src);
void qtn_paintTitleBarText(QPainter* painter, const QString& text, const QRect& rect, bool active, const QColor& color = QColor());
void qtn_paintTitleBarIcon(QPainter* painter, const QIcon& icon, const QRect& rect);
QTITAN_BASE_EXPORT QPixmap qtn_getTitleBarIcon(QWidget* window);
QTITAN_BASE_EXPORT void qtn_updateTitleBarWidgetPosition(QWidget* window);

enum DesktopImageAspectStyle
{
    AspectStyleCentral,
    AspectStyleTiled,
    AspectStyleIgnoreRatio,
    AspectStyleKeepRatio,
    AspectStyleKeepRatioByExpanding
};

QImage qtn_getDesktopImage(int screen = -1);
DesktopImageAspectStyle qtn_getDesktopAspectStyle(int screen = -1);

QTITAN_BASE_EXPORT int   qtn_horizontalAdvanceFont(const QFontMetrics& fm, const QString& str, int len = -1);
QTITAN_BASE_EXPORT int   qtn_horizontalAdvanceFont(const QFontMetrics& fm, const QChar& ch);
QTITAN_BASE_EXPORT QRect qtn_screenGeometry(const QPoint& pos, const QWidget* widget);
QTITAN_BASE_EXPORT QRect qtn_availableGeometry(const QWidget* widget = Q_NULL);

QTITAN_END_NAMESPACE


#endif //QTN_PLATFORM_H

