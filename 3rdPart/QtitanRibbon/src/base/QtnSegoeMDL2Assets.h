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
#ifndef QTN_SEGOEMDL2ASSETS_H
#define QTN_SEGOEMDL2ASSETS_H

#include <QColor>
#include <QFont>
#include <QPixmap>

#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class QTITAN_BASE_EXPORT SegoeMDL2Font : public QFont
{
public:
    enum IconSymbol
    {
        None,
        GlobalNavigationButton,
        Globe,
        World,
        Wifi,
        Home,
        HomeSolid,
        Accounts,
        Cut,
        Copy,
        SaveCopy,
        SaveAs,
        SaveLocal,
        Paste,
        Repair,
        Error,
        ErrorBadge,
        Color,
        Calendar,
        CalendarSolid,
        CalendarDay,
        CalendarWeek,
        CalendarMirrored,
        CalendarReply,
        Video,
        VideoChat,
        PresenceChickletVideo,
        People,
        Walk,
        WalkSolid,
        Bluetooth,
        Back,
        Forward,
        ChromeBack,
        ChromeClose,
        ChromeMinimize,
        ChromeMaximize,
        ChromeRestore,
        Help,
        HelpMirrored,
        Pin,
        PinFill,
        Unpin,
        Pinned,
        PinnedFill,
        StockDown,
        FlickDown,
        FlickUp,
        ChevronDown,
        Settings,
        AddFriend,
        FavoriteStar,
        FavoriteStarFill,
        Unfavorite,
        Touch,
        TouchPointer,
        NumSymbols = TouchPointer + 1,
    };
    SegoeMDL2Font();
    SegoeMDL2Font(const QFont& font);
    QPixmap pixmap(SegoeMDL2Font::IconSymbol symbol, const QColor& color = Qt::black) const;
    QPixmap pixmap(ushort code, const QColor& color = Qt::black) const;
    void paint(QPainter* painter, ushort code, const QRect& rect, const QColor& color) const;
    static ushort code(SegoeMDL2Font::IconSymbol symbol);
    static QPixmap pixmap(SegoeMDL2Font::IconSymbol symbol, const QSize& iconSize, const QColor& color = Qt::black);
    static QPixmap pixmap(ushort code, const QSize& iconSize, const QColor& color = Qt::black);
};

QTITAN_END_NAMESPACE

#endif// QTN_SEGOEMDL2ASSETS_H



