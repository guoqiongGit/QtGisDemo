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
#ifndef QTN_ADOBEPHOTOSHOPSTYLE_H
#define QTN_ADOBEPHOTOSHOPSTYLE_H

#include <QStylePlugin>
#include "QtnCommonStyle.h"
#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class AdobePhotoshopStylePrivate;
/* AdobePhotoshopStyle */
class QTITAN_EXPORT AdobePhotoshopStyle : public CommonStyle
{
    Q_OBJECT
    Q_ENUMS(Theme)
    Q_PROPERTY(Theme theme READ theme WRITE setTheme)
public:
    enum Theme
    {
        LightGray,
        Gray,
        DarkGray,
        Black
    };
public:
    AdobePhotoshopStyle();
    virtual ~AdobePhotoshopStyle();
public:
    Theme theme() const;
    void setTheme(Theme theme);
public:
    virtual void polish(QWidget* widget);
public:
    virtual QIcon standardIcon(QStyle::StandardPixmap standardIcon, const QStyleOption* opt = QSTYLEOPTION_NULL, const QWidget* widget = QWIDGET_NULL) const;
    virtual QRect subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex* opt, SubControl sc, const QWidget* w = QWIDGET_NULL) const;
    virtual QSize sizeFromContents(QStyle::ContentsType type, const QStyleOption* opt, const QSize& size, const QWidget* widget = QWIDGET_NULL) const;
    virtual int styleHint(QStyle::StyleHint sh, const QStyleOption* opt = QSTYLEOPTION_NULL, const QWidget* w = QWIDGET_NULL, QStyleHintReturn* shret = Q_NULL) const;
private:
    QTN_DECLARE_EX_PRIVATE(AdobePhotoshopStyle)
    Q_DISABLE_COPY(AdobePhotoshopStyle)
};

QTITAN_END_NAMESPACE

#endif // QTN_ADOBEPHOTOSHOPSTYLE_H
