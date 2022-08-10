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
#include <QFontDatabase>
#include <QPainter>
#include <QFontInfo>
#include <QTextOption>
#include "QtnSegoeMDL2Assets.h"
#include "QtnPlatform.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE

/*!
    \enum SegoeMDL2Font::IconSymbol
*/

static bool origSegoeMDL2 = false;
static void qtn_initSegoeMDL2AssetsFont()
{
    static bool initSegoeMDL2Assets = false;
    if (initSegoeMDL2Assets)
        return;
    initSegoeMDL2Assets = true;

#ifdef Q_OS_WIN
#if 1
    if (qtn_isWindows10())
#else
    if (QFontInfo(QFont("Segoe MDL2 Assets")).exactMatch())
#endif
    {
        origSegoeMDL2 = true;
        return;
    }
#if 0
    if (QFontInfo(QFont("micon")).exactMatch())
        return;
#endif
#endif
    //Use MIT license based "Micon" font as an alternative for "Segoe MDL2 Assets"
    QFontDatabase::addApplicationFont(QStringLiteral(":/res/micon.ttf"));
}

static QFont qtn_getSegoeMDL2AssetsFont()
{
    qtn_initSegoeMDL2AssetsFont();
    if (origSegoeMDL2)
        return QFont(QStringLiteral("Segoe MDL2 Assets"));
    else
        return QFont(QStringLiteral("micon"));
}

/* SymbolInfo */
struct SymbolInfo
{
    SegoeMDL2Font::IconSymbol symbol;
    const ushort code1;
    const ushort code2;
};

/*!
\internal 
*/
static const SymbolInfo knownIconSymbols[SegoeMDL2Font::NumSymbols] =
{
    { SegoeMDL2Font::None,           0x0000,  0x0000 },
    { SegoeMDL2Font::GlobalNavigationButton, 0xEB48,  0xE700 },
    { SegoeMDL2Font::Globe,          0xEB49,  0xE774 },
    { SegoeMDL2Font::World,          0xEDB0,  0xE909 },
    { SegoeMDL2Font::Wifi,           0xED94,  0xE701 },
    { SegoeMDL2Font::Home,           0xEB6F,  0xE80F },
    { SegoeMDL2Font::HomeSolid,      0xEB71,  0xEA8A },
    { SegoeMDL2Font::Accounts,       0xEA04,  0xE910 },
    { SegoeMDL2Font::Cut,            0xEAD1,  0xE8C6 },
    { SegoeMDL2Font::Copy,           0xEACE,  0xE8C8 },
    { SegoeMDL2Font::SaveCopy,       0xECE5,  0xEA35 },
    { SegoeMDL2Font::SaveAs,         0xECE4,  0xE792 },
    { SegoeMDL2Font::SaveLocal,      0xECE6,  0xE78C },
    { SegoeMDL2Font::Paste,          0xEC57,  0xE77F },
    { SegoeMDL2Font::Repair,         0xECAE,  0xE90F },
    { SegoeMDL2Font::Error,          0xEB17,  0xE783 },
    { SegoeMDL2Font::ErrorBadge,     0xEB18,  0xEA39 },
    { SegoeMDL2Font::Color,          0xEAB9,  0xE790 },
    { SegoeMDL2Font::Calendar,       0xEA72,  0xE787 },
    { SegoeMDL2Font::CalendarSolid,  0xEA76,  0xEA89 },
    { SegoeMDL2Font::CalendarDay,  0xEA73,  0xE8BF },
    { SegoeMDL2Font::CalendarWeek,  0xEA77,  0xE8C0 },
    { SegoeMDL2Font::CalendarMirrored,  0xEA74,  0xED28 },
    { SegoeMDL2Font::CalendarReply,  0xEA75,  0xE8F5 },
    { SegoeMDL2Font::Video,          0xED84,  0xE714 },
    { SegoeMDL2Font::VideoChat,      0xED85,  0xE8AA },
    { SegoeMDL2Font::PresenceChickletVideo, 0xEC7A,  0xE979 },
    { SegoeMDL2Font::People,         0xEC5F,  0xE716 },
    { SegoeMDL2Font::Walk,           0xED8E,  0xE805 },
    { SegoeMDL2Font::WalkSolid,      0xED8F,  0xE726 },
    { SegoeMDL2Font::Bluetooth,      0xEA52,  0xE702 },
    { SegoeMDL2Font::Back,           0xEA22,  0xE72B },
    { SegoeMDL2Font::Forward,        0xEB3D,  0xE72A },
    { SegoeMDL2Font::ChromeBack,     0xEA9F,  0xE830 },
    { SegoeMDL2Font::ChromeClose,    0xEAA2,  0xE8BB },
    { SegoeMDL2Font::ChromeMinimize, 0xEAA5,  0xE921 },
    { SegoeMDL2Font::ChromeMaximize, 0xEAA4,  0xE922 },
    { SegoeMDL2Font::ChromeRestore,  0xEAA6,  0xE923 },
    { SegoeMDL2Font::Help,           0xEB68,  0xE897 },
    { SegoeMDL2Font::HelpMirrored,   0xEB69,  0xEA51 },
    { SegoeMDL2Font::Pin,            0xEC6A,  0xE718 },
    { SegoeMDL2Font::PinFill,        0xEC6B,  0xE841 },
    { SegoeMDL2Font::Unpin,        0xED7B,  0xE77A },
    { SegoeMDL2Font::Pinned,         0xEC6C,  0xE840 },
    { SegoeMDL2Font::PinnedFill,     0xEC6D,  0xE842 },
    { SegoeMDL2Font::StockDown,      0xED2E,  0xEB0F },
    { SegoeMDL2Font::FlickDown,      0xEB32,  0xE935 },
    { SegoeMDL2Font::FlickUp,        0xEB33,  0xE936 },
    { SegoeMDL2Font::ChevronDown,    0xEA8E,  0xE70D },
    { SegoeMDL2Font::Settings,       0xECF5,  0xE713 }, //0xE115
    { SegoeMDL2Font::AddFriend,      0xEA0D,  0xE8FA },
    { SegoeMDL2Font::FavoriteStar,   0xEB24,  0xE734 },
    { SegoeMDL2Font::FavoriteStarFill, 0xEB22,  0xE735 },
    { SegoeMDL2Font::Unfavorite,     0xED78,  0xE8D9 },
    { SegoeMDL2Font::Touch,          0xED5F,  0xE815 },
    { SegoeMDL2Font::TouchPointer,   0xED60,  0xE7C9 }
};

static ushort qtn_getSegoeMDL2AssetsCode(SegoeMDL2Font::IconSymbol symbol)
{
    if (symbol == SegoeMDL2Font::None)
    {
        static QChar empty = QChar();
        return empty.unicode();
    }
    return origSegoeMDL2 ? knownIconSymbols[symbol].code2 : knownIconSymbols[symbol].code1;
}

static QPixmap qtn_symbolToPixmap(const SegoeMDL2Font& font, ushort code, const QSize& iconSize, const QColor& color)
{
    if (code == 0 || iconSize == QSize())
        return QPixmap();
    QPixmap symbolPixmap(iconSize.width(), iconSize.height());
    symbolPixmap.fill(Qt::transparent);
    QPainter p(&symbolPixmap);
    font.paint(&p, code, QRect(QPoint(0, 0), iconSize), color);
    return symbolPixmap;
}

/*!
\class SegoeMDL2Font
\inmodule QtitanBase
\brief Class adds support for Microsoft Segoe MDL2 Assets font to the Qt application. 
For MacOSX, Linux and old Windows it uses open source font "Micon".
For more details see:
\l {https://docs.microsoft.com/en-us/windows/uwp/design/style/segoe-ui-symbol-font} {Segoe MDL2 Assets Font}
and \l {http://xtoolkit.github.io/Micon/cheatsheet/} {Micon Iconic Font}
*/

/*!
Constructs the SegoeMDL2Font class.
*/
SegoeMDL2Font::SegoeMDL2Font()
    : QFont(qtn_getSegoeMDL2AssetsFont())
{
}

/*!
Constructs the SegoeMDL2Font class with the given \a font.
*/
SegoeMDL2Font::SegoeMDL2Font(const QFont& font)
    : QFont(qtn_getSegoeMDL2AssetsFont())
{
    if (font.pointSize() > 0)
        setPointSize(font.pointSize());
    if (font.pixelSize() > 0)
        setPixelSize(font.pixelSize());
    setBold(font.bold());
}

/*!
Returns native font code corresponding to its enumerator representative \a symbol.
*/
ushort SegoeMDL2Font::code(SegoeMDL2Font::IconSymbol symbol)
{
    return qtn_getSegoeMDL2AssetsCode(symbol);
}

QPixmap SegoeMDL2Font::pixmap(SegoeMDL2Font::IconSymbol symbol, const QSize& iconSize, const QColor& color)
{
    SegoeMDL2Font font;
    return qtn_symbolToPixmap(font, SegoeMDL2Font::code(symbol), iconSize, color);
}

QPixmap SegoeMDL2Font::pixmap(ushort code, const QSize& iconSize, const QColor& color)
{
    SegoeMDL2Font font;
    return qtn_symbolToPixmap(font, code, iconSize, color);
}

QPixmap SegoeMDL2Font::pixmap(SegoeMDL2Font::IconSymbol symbol, const QColor& color) const
{
    ushort code = qtn_getSegoeMDL2AssetsCode(symbol);
    QFontMetrics m(*this);   
    QSize s = m.boundingRect(QChar(code)).size();
    int iconSize = qMax(s.width(), s.height());
    return qtn_symbolToPixmap(*this, code, QSize(iconSize, iconSize), color);
}

QPixmap SegoeMDL2Font::pixmap(ushort code, const QColor& color) const
{
    QFontMetrics m(*this);
    QSize s = m.boundingRect(QChar(code)).size();
    int iconSize = qMax(s.width(), s.height());
    return qtn_symbolToPixmap(*this, code, QSize(iconSize, iconSize), color);
}

void SegoeMDL2Font::paint(QPainter* painter, ushort code, const QRect& rect, const QColor& color) const
{
    if (rect.width() <= 0 || rect.height() <= 0)
        return;

    QFont saveFont = painter->font();
    QPen savePen = painter->pen();
    bool saveAntialiasing = painter->testRenderHint(QPainter::TextAntialiasing);
    int savePixelSize = this->pixelSize();
    int savePointSize = this->pointSize();

    const_cast<SegoeMDL2Font *>(this)->setPixelSize(rect.height());
    painter->setFont(*this);
    painter->setPen(color);
    painter->setRenderHint(QPainter::TextAntialiasing, false);

    painter->drawText(rect, Qt::AlignCenter, QChar(code));

    if (savePixelSize > 0)
        const_cast<SegoeMDL2Font *>(this)->setPixelSize(savePixelSize);
    if (savePointSize > 0)
        const_cast<SegoeMDL2Font *>(this)->setPointSize(savePointSize);

    painter->setFont(saveFont);
    painter->setPen(savePen);
    painter->setRenderHint(QPainter::TextAntialiasing, saveAntialiasing);
}
