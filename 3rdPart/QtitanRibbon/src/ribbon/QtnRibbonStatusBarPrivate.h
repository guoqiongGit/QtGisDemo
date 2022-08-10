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
#ifndef QTN_RIBBONSTATUSBARPRIVATE_H
#define QTN_RIBBONSTATUSBARPRIVATE_H

#include <QToolButton>
#include <QStyleOption>

#include "QtnRibbonStatusBar.h"
#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE
/* StatusButton */
class StatusButton : public QToolButton
{
    Q_OBJECT
public:
    StatusButton(QWidget* parent = Q_NULL);
public:
    virtual QSize sizeHint() const;
public:
    void initStyleOptionButton(QStyleOptionToolButton& option) const;
protected:
    virtual bool event(QEvent* event);
    virtual void paintEvent(QPaintEvent*);
};

/* StatusSeparator */
class StatusSeparator : public QToolButton
{
    Q_OBJECT
public:
    StatusSeparator(QWidget* parent = Q_NULL);
public:
    virtual QSize sizeHint() const;
protected:
    void initStyleOption(QStyleOption* option) const;
protected:
    virtual void paintEvent(QPaintEvent*);
};
QTITAN_END_NAMESPACE

#endif // QTN_RIBBONSTATUSBARPRIVATE_H
