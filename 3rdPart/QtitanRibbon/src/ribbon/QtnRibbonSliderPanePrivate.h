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
#ifndef QTN_RIBBONSLIDERPANEPRIVATE_H
#define QTN_RIBBONSLIDERPANEPRIVATE_H

#include <QEvent>
#include <QMouseEvent>
#include <QBasicTimer>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStyleOption>

#include "QtnRibbonSliderPane.h"

QTITAN_BEGIN_NAMESPACE

class RibbonSliderButton : public QPushButton
{
    Q_OBJECT
public:
    RibbonSliderButton(QWidget* parent, QStyle::PrimitiveElement typeBut = QStyle::PE_IndicatorArrowUp);
    ~RibbonSliderButton();
protected:
    virtual void  paintEvent(QPaintEvent* event);
    virtual QSize sizeHint() const;
protected:
    QStyle::PrimitiveElement m_typeBut;
private:
    Q_DISABLE_COPY(RibbonSliderButton)
};

class RibbonSliderSlider : public QSlider
{
    Q_OBJECT
public:
    explicit RibbonSliderSlider(Qt::Orientation orientation, QWidget* parent = Q_NULL)
        : QSlider(orientation, parent)
    {}
private:
    Q_DISABLE_COPY(RibbonSliderSlider)
};

class RibbonSliderPanePrivate : QObject
{
public:
    QTN_DECLARE_PUBLIC(RibbonSliderPane)
public:
    explicit RibbonSliderPanePrivate();
public:
    void initSlider();
public:
    RibbonSliderSlider* m_slider;
    RibbonSliderButton* m_buttonUp;
    RibbonSliderButton* m_buttonDown;
    QHBoxLayout* m_layout;
private:
    Q_DISABLE_COPY(RibbonSliderPanePrivate)
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONSLIDERPANEPRIVATE_H
