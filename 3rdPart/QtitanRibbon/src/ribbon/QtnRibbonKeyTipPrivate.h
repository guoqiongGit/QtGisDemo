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
#ifndef QTN_RIBBONTOOLTIP_H
#define QTN_RIBBONTOOLTIP_H

#include <QLabel>
#include <QTimer>
#include <QIcon>
#include <QEvent>
#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class RibbonKeyTipPrivate;
/* KeyTip */
class RibbonKeyTip : public QFrame
{
    Q_OBJECT
public:
    enum AlignTip
    {
        AlignTipTop      = 0x00000000,
        AlignTipLeft     = 0x00000000,
        AlignTipCenter   = 0x00000001,
        AlignTipRight    = 0x00000002,
        AlignTipVCenter  = 0x00000004,
        AlignTipBottom   = 0x00000008,
    };
public:
    RibbonKeyTip(QWidget* bars, QWidget* owner, const QString& caption, 
        const QPoint& pt, uint align, bool enabled, QAction* action = Q_NULL);
    virtual ~RibbonKeyTip();
public:
    QPoint posTip() const;
    void setVisibleTip(bool visible);
    bool isVisibleTip() const;
    bool isEnabledTip() const;

    QWidget* getBars() const;
    uint getAlign() const;

    void setExplicit(bool exp);
    bool isExplicit() const;

    QString getStringTip() const;
    void setStringTip(const QString& str);

    QString getCaption() const;
    void setCaption(const QString& str);

    QString getPrefix() const;
    void setPrefix(const QString& pref);

    QWidget* getOwner() const;
    QAction* getAction() const;
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void resizeEvent(QResizeEvent* event);
private:
    QTN_DECLARE_PRIVATE(RibbonKeyTip)
    Q_DISABLE_COPY(RibbonKeyTip)
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONTOOLTIP_H
