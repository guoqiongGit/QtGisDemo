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
#ifndef QTN_RIBBONTITLEBAR_H
#define QTN_RIBBONTITLEBAR_H

#include <QStyle>
#include <QWidget>
#include <QToolButton>

#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class RibbonTitleButton : public QToolButton
{
    Q_OBJECT
public:
    RibbonTitleButton(QWidget* parent, QStyle::SubControl subControl);
    virtual ~RibbonTitleButton();
public:
    QStyle::SubControl subControl() const;
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    QStyle::SubControl m_subControl;
private:
    Q_DISABLE_COPY(RibbonTitleButton)
};

class RibbonBar;
class WindowTitleBar;
class ContextHeader;
class TitleBarStyleOption;
class RibbonTitleBarLayout;

class RibbonTitleBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RibbonTitleBarWidget(RibbonBar* ribbonBar);
    virtual ~RibbonTitleBarWidget();
public:
    void addWidget(QWidget* widget);
    void removeWidget(QWidget* widget);
    void adjustSizeTitleBar();
    RibbonBar* ribbonBar() const;
    WindowTitleBar* getWindowTitleBar() const;
public Q_SLOTS:
    void windowTitleChanged(const QString&);
    void updateContextHeaders();
protected:
    QWidget* topWidget() const;
    void updateTextTitle();
    void updateBorder();
    void initTitleBarOption(TitleBarStyleOption* opt) const;
    ContextHeader* hitTestContextHeaders(const QPoint& point) const;
protected:
    virtual bool event(QEvent* event);
    virtual bool eventFilter(QObject* watched, QEvent* event);
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
private:
    bool m_dirtyTextTitle;
    RibbonBar* m_ribbonBar;
    RibbonTitleBarLayout* m_titleBarLayout;
private:
    Q_DISABLE_COPY(RibbonTitleBarWidget)
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONTITLEBAR_H
