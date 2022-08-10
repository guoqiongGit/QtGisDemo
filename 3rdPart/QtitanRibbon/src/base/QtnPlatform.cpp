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
#include <QScreen>

#ifdef QTN_PRIVATE_HEADERS
#include <qpa/qplatformnativeinterface.h>
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        #define QT_VERSION_SUPPORT_HIGHDPI
        #include <QtGui/private/qhighdpiscaling_p.h>
    #endif
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QGuiApplication>
#include <QWindow>
#endif
#if (QT_VERSION < QT_VERSION_CHECK(5, 14, 0))
#include <QDesktopWidget>
#endif

#include "QtnPlatform.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

int QTITAN_PREPEND_NAMESPACE(qtn_horizontalAdvanceFont)(const QFontMetrics& fm, const QString& str, int len)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 11, 0))
    return fm.horizontalAdvance(str, len);
#else
    return fm.width(str, len);
#endif
}

int QTITAN_PREPEND_NAMESPACE(qtn_horizontalAdvanceFont)(const QFontMetrics& fm, const QChar& ch)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 11, 0))
    return fm.horizontalAdvance(ch);
#else
    return fm.width(ch);
#endif
}

#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
qreal qtn_highDpiScale(qreal value, qreal scaleFactor, QPointF /* origin */ = QPointF(0, 0))
{ return value * scaleFactor;}

QSize qtn_highDpiScale(const QSize& value, qreal scaleFactor, QPointF /* origin */ = QPointF(0, 0))
{ return value * scaleFactor;}

QSizeF qtn_highDpiScale(const QSizeF& value, qreal scaleFactor, QPointF /* origin */ = QPointF(0, 0))
{ return value * scaleFactor; }

QVector2D qtn_highDpiScale(const QVector2D& value, qreal scaleFactor, QPointF /* origin */ = QPointF(0, 0))
{ return value * float(scaleFactor); }

QPointF qtn_highDpiScale(const QPointF& pos, qreal scaleFactor, QPointF origin = QPointF(0, 0))
{ return (pos - origin) * scaleFactor + origin; }

QPoint qtn_highDpiScale(const QPoint& pos, qreal scaleFactor, QPoint origin = QPoint(0, 0))
{ return (pos - origin) * scaleFactor + origin; }

QRect qtn_highDpiScale(const QRect& rect, qreal scaleFactor, QPoint origin = QPoint(0, 0))
{ return QRect(qtn_highDpiScale(rect.topLeft(), scaleFactor, origin), qtn_highDpiScale(rect.size(), scaleFactor)); }

QRectF qtn_highDpiScale(const QRectF& rect, qreal scaleFactor, QPoint origin = QPoint(0, 0))
{ return QRectF(qtn_highDpiScale(rect.topLeft(), scaleFactor, origin), qtn_highDpiScale(rect.size(), scaleFactor)); }

QMargins qtn_highDpiScale(const QMargins& margins, qreal scaleFactor, QPoint origin = QPoint(0, 0))
{
    Q_UNUSED(origin)
    return QMargins(qRound(qreal(margins.left()) * scaleFactor), qRound(qreal(margins.top()) * scaleFactor),
            qRound(qreal(margins.right()) * scaleFactor), qRound(qreal(margins.bottom()) * scaleFactor));
}

QPair<qreal, QPoint> qtn_highDpiScaleAndOrigin(const QWindow* window)
{
    qreal factor = 1.0;
    QPoint origin = QPoint(0, 0);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 12, 5))
    QHighDpiScaling::ScaleAndOrigin so = QHighDpiScaling::scaleAndOrigin(window, Q_NULL);
    factor = so.factor;
    origin = so.origin;
#else
    if (!QHighDpiScaling::isActive())
        return QPair<qreal, QPoint>(factor, origin);
    factor = QHighDpiScaling::factor(window);
    QScreen* screen = window != Q_NULL ? window->screen() : QGuiApplication::primaryScreen();
    if (screen == Q_NULL)
        return QPair<qreal, QPoint>(factor, origin);
    origin = QHighDpiScaling::origin(screen->handle());
#endif
    return QPair<qreal, QPoint>(factor, origin);
}

template <typename T, typename C>
T qtn_fromNativePixels(const T& value, const C* context)
{
    QPair<qreal, QPoint> so = qtn_highDpiScaleAndOrigin(context);
    return qtn_highDpiScale(value, qreal(1) / so.first, so.second);
}
#endif

QRect QTITAN_PREPEND_NAMESPACE(qtn_fromNativeDPI)(const QRect& rect, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return rect;
    return qtn_fromNativePixels(rect, window->windowHandle());
#else
    Q_UNUSED(window);
    return rect;
#endif
}

QRect QTITAN_PREPEND_NAMESPACE(qtn_toNativeDPI)(const QRect& rect, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return rect;
    return QHighDpi::toNativePixels(rect, window->windowHandle());
#else
    Q_UNUSED(window);
    return rect;
#endif
}

QSize QTITAN_PREPEND_NAMESPACE(qtn_fromNativeDPI)(const QSize& size, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return size;
    return qtn_fromNativePixels(size, window->windowHandle());
#else
    Q_UNUSED(window);
    return size;
#endif
}

QSize QTITAN_PREPEND_NAMESPACE(qtn_toNativeDPI)(const QSize& size, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return size;
    return QHighDpi::toNativePixels(size, window->windowHandle());
#else
    Q_UNUSED(window);
    return size;
#endif
}

QPoint QTITAN_PREPEND_NAMESPACE(qtn_fromNativeDPI)(const QPoint& point, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return point;
    return QHighDpi::fromNativeLocalPosition(point, window->windowHandle());
#else
    Q_UNUSED(window);
    return point;
#endif
}

QPoint QTITAN_PREPEND_NAMESPACE(qtn_toNativeDPI)(const QPoint& point, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return point;
    return QHighDpi::toNativeLocalPosition(point, window->windowHandle());
#else
    Q_UNUSED(window);
    return point;
#endif
}

QMargins QTITAN_PREPEND_NAMESPACE(qtn_fromNativeDPI)(const QMargins& margins, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return margins;
    return qtn_fromNativePixels(margins, window->windowHandle());
#else
    Q_UNUSED(window);
    return margins;
#endif
}

QRegion QTITAN_PREPEND_NAMESPACE(qtn_toNativeDPI)(const QRegion& region, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return region;
    return QHighDpi::toNativeLocalRegion(region, window->windowHandle());
#else
    Q_UNUSED(window);
    return region;
#endif
}

QMargins QTITAN_PREPEND_NAMESPACE(qtn_toNativeDPI)(const QMargins& margins, const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return margins;
    return QHighDpi::toNativePixels(margins, window->windowHandle());
#else
    Q_UNUSED(window);
    return margins;
#endif
}

qreal QTITAN_PREPEND_NAMESPACE(qtn_pixelRatioDPI)(const QWidget* window)
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    if (window == Q_NULL)
        return 1.0;
    return QHighDpiScaling::factor(window->windowHandle());
#else
    Q_UNUSED(window);
    return 1.0;
#endif
}

bool QTITAN_PREPEND_NAMESPACE(qtn_isDPIScalingActive)()
{
#if defined(QTN_PRIVATE_HEADERS) && defined(QT_VERSION_SUPPORT_HIGHDPI)
    return QHighDpiScaling::isActive();
#else
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    return QApplication::testAttribute(Qt::AA_EnableHighDpiScaling);
#else
    return false;
#endif
#endif
}

#if defined(Q_OS_LINUX) || defined(Q_OS_MAC) || defined(Q_OS_WASM)
void QTITAN_PREPEND_NAMESPACE(qtn_initializeDrawingResources)()
{
    static bool tried = false;
    if (!tried)
    {
        tried = true;
    }
}

QColor QTITAN_PREPEND_NAMESPACE(qtn_getColorizationColor)()
{
    return Qt::darkGray;
}

void QTITAN_PREPEND_NAMESPACE(qtn_initTitleBarPalette)(QPalette& palette)
{
    QColor bgcolor = Qt::gray;
    QColor fgcolor = Qt::black;
    QColor frameColor = Qt::darkGray;

    palette.setColor(QPalette::Active, QPalette::Window, bgcolor);
    palette.setColor(QPalette::Active, QPalette::WindowText, fgcolor);
    palette.setColor(QPalette::Active, QPalette::ButtonText, fgcolor);
    palette.setColor(QPalette::Active, QPalette::Shadow, frameColor);

    bgcolor = Qt::white;
    fgcolor = Qt::gray;
    frameColor = Qt::darkGray;

    palette.setColor(QPalette::Inactive, QPalette::Window, bgcolor);
    palette.setColor(QPalette::Inactive, QPalette::WindowText, fgcolor);
    palette.setColor(QPalette::Inactive, QPalette::ButtonText, fgcolor);
    palette.setColor(QPalette::Inactive, QPalette::Shadow, frameColor);
}

int QTITAN_PREPEND_NAMESPACE(qtn_getWindowDPI)(const QWidget* window)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    if (QCoreApplication::instance()->testAttribute(Qt::AA_Use96Dpi))
        return 96;

    QScreen* screen = Q_NULL;
    if (window)
    {
        if (QWidget* topLevel = window->window())
        {
            if (QWindow* topLevelWindow = topLevel->windowHandle())
                screen = topLevelWindow->screen();
        }
    }
    if (!screen && QGuiApplication::primaryScreen())
        screen = QGuiApplication::primaryScreen();
    return qRound(screen->logicalDotsPerInch());
#else // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_UNUSED(window)
#ifdef Q_OS_MAC
        return 72;
#else
        return 96;
#endif
#endif // (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
}

#endif

#if defined(Q_OS_LINUX) || defined(Q_OS_WASM)
QImage QTITAN_PREPEND_NAMESPACE(qtn_getDesktopImage)(int screen)
{
    Q_UNUSED(screen)
    return QImage();
}

DesktopImageAspectStyle QTITAN_PREPEND_NAMESPACE(qtn_getDesktopAspectStyle)(int screen)
{
    Q_UNUSED(screen)
        DesktopImageAspectStyle ret = AspectStyleCentral;
    return ret;
}
#endif

QRect QTITAN_PREPEND_NAMESPACE(qtn_screenGeometry)(const QPoint& pos, const QWidget* widget)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    if (QGuiApplication::primaryScreen()->virtualSiblings().size() > 1)
    {
        QScreen* screen = QGuiApplication::screenAt(pos);
        if (!screen)
            screen = QGuiApplication::primaryScreen();
        return screen->geometry();
    }
    else
        return widget->screen()->geometry();
#else
    int index = 0;
    if (QApplication::desktop()->isVirtualDesktop())
        index = QApplication::desktop()->screenNumber(pos);
    else
        index = QApplication::desktop()->screenNumber(widget);
    return QApplication::desktop()->screenGeometry(index);
#endif
}

QRect QTITAN_PREPEND_NAMESPACE(qtn_availableGeometry)(const QWidget* widget)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    if (widget == Q_NULL)
        return QGuiApplication::primaryScreen()->virtualGeometry();
    else
        return widget->screen()->availableGeometry();
#else
    return QApplication::desktop()->availableGeometry(widget);
#endif
}

