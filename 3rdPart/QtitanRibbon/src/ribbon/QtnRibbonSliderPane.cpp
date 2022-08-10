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
#include "QtnCommonStyle.h"
#include "QtnCommonStylePrivate.h"
#include "QtnRibbonSliderPanePrivate.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif

QTITAN_USE_NAMESPACE


/* RibbonSliderButton */
RibbonSliderButton::RibbonSliderButton(QWidget* parent, QStyle::PrimitiveElement typeBut)
  : QPushButton(parent)
{
    m_typeBut = typeBut;
}

RibbonSliderButton::~RibbonSliderButton()
{
}

/*! \reimp */
void RibbonSliderButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QStyleOptionButton option;
    initStyleOption(&option);
    option.direction = m_typeBut == QStyle::PE_IndicatorArrowUp ? Qt::LeftToRight : Qt::RightToLeft;
    style()->drawPrimitive((QStyle::PrimitiveElement)CommonStyle::PE_RibbonSliderButton, &option, &painter, this);
}

/*! \reimp */
QSize RibbonSliderButton::sizeHint() const
{
    QSize sz(CommonStylePrivate::dpiScaled(12., this), CommonStylePrivate::dpiScaled(12., this));
    QStyleOptionButton option;
    initStyleOption(&option);
    option.direction = m_typeBut == QStyle::PE_IndicatorArrowUp ? Qt::LeftToRight : Qt::RightToLeft;
    sz = style()->sizeFromContents((QStyle::ContentsType)CommonStyle::CT_RibbonSliderButton, &option, sz, this);
    return sz;
}


/* RibbonSliderPanePrivate */
RibbonSliderPanePrivate::RibbonSliderPanePrivate()
    : m_slider(Q_NULL)
    , m_buttonUp(Q_NULL)
    , m_buttonDown(Q_NULL)
    , m_layout(Q_NULL)
{
}

void RibbonSliderPanePrivate::initSlider()
{
    QTN_P(RibbonSliderPane);
    m_slider = new RibbonSliderSlider(Qt::Horizontal, &p);
    m_slider->setTickPosition(QSlider::NoTicks);

    m_layout = new QHBoxLayout();
    m_layout->setMargin(0);
    m_layout->setSpacing(4);

    m_layout->addWidget(m_slider);
    p.setLayout(m_layout);
}


/* RibbonSliderPane */
RibbonSliderPane::RibbonSliderPane(QWidget* parent)
    : QWidget(parent)
{
    QTN_INIT_PRIVATE(RibbonSliderPane);
    QTN_D(RibbonSliderPane);
    d.initSlider();
    connect(d.m_slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));
    connect(d.m_slider, SIGNAL(sliderMoved(int)), this, SIGNAL(sliderMoved(int)));
}

RibbonSliderPane::~RibbonSliderPane()
{
    QTN_FINI_PRIVATE();
}

void RibbonSliderPane::setRange(int min, int max)
{
    QTN_D(RibbonSliderPane);
    d.m_slider->setMinimum( min ); // min - Range
    d.m_slider->setMaximum( max ); // max - Range
}

void RibbonSliderPane::setScrollButtons(bool on)
{
    QTN_D(RibbonSliderPane);
    if (on)
    {
        d.m_buttonDown = new RibbonSliderButton(this, QStyle::PE_IndicatorArrowDown );
        d.m_layout->insertWidget(0, d.m_buttonDown, 0, Qt::AlignLeft | Qt::AlignVCenter);
        d.m_buttonUp   = new RibbonSliderButton(this, QStyle::PE_IndicatorArrowUp);
        d.m_layout->addWidget(d.m_buttonUp, 0, Qt::AlignRight | Qt::AlignVCenter);
        connect(d.m_buttonDown, SIGNAL(pressed()), this, SLOT(decrement()));
        connect(d.m_buttonUp,   SIGNAL(pressed()), this, SLOT(increment()));
    } 
    else 
    {
        disconnect(d.m_buttonUp, SIGNAL(pressed()), this, SLOT(increment()));
        disconnect(d.m_buttonDown, SIGNAL(pressed()), this, SLOT(decrement()));
        Q_DELETE_AND_NULL(d.m_buttonUp);
        Q_DELETE_AND_NULL(d.m_buttonDown);
    }
}

void RibbonSliderPane::setSliderPosition(int position)
{
    QTN_D(RibbonSliderPane);
    d.m_slider->setSliderPosition(position);
}

int RibbonSliderPane::sliderPosition() const
{
    QTN_D(const RibbonSliderPane);
    return d.m_slider->sliderPosition();
}

void RibbonSliderPane::setSingleStep(int nPos)
{
    QTN_D(RibbonSliderPane);
    d.m_slider->setSingleStep(nPos);
}

int RibbonSliderPane::singleStep() const
{
    QTN_D(const RibbonSliderPane);
    return d.m_slider->singleStep();
}

int RibbonSliderPane::value() const
{
    QTN_D(const RibbonSliderPane);
    return d.m_slider->value();
}

void RibbonSliderPane::setValue(int value)
{
    QTN_D(RibbonSliderPane);
    d.m_slider->setValue(value);
}

void RibbonSliderPane::increment()
{
    QTN_D(RibbonSliderPane);
    int nPos = d.m_slider->sliderPosition() + d.m_slider->singleStep();
    if (nPos <= d.m_slider->maximum()) 
        d.m_slider->setSliderPosition(nPos);
}

void RibbonSliderPane::decrement()
{
    QTN_D(RibbonSliderPane);
    int nPos = d.m_slider->sliderPosition() - d.m_slider->singleStep();
    if (nPos >= d.m_slider->minimum()) 
        d.m_slider->setSliderPosition(nPos);
}

