/****************************************************************************
**
** Qtitan Library by Developer Machines
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

#ifndef QTN_SCROLLWIDGETBAR_H
#define QTN_SCROLLWIDGETBAR_H

#include <QWidget>
#include <QAbstractButton>
#include <QPropertyAnimation>

#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class ScrollWidgetBarButton;

class QTITAN_BASE_EXPORT AbstractScrollWidgetBar : public QWidget
{
    Q_OBJECT 
public:
    AbstractScrollWidgetBar(QWidget* parent, Qt::Orientation orientation = Qt::Horizontal);
    virtual ~AbstractScrollWidgetBar();
public:
    Qt::Orientation orientation() const;
    void setOrientation(Qt::Orientation orientation);
    QWidget* viewWidget() const;
    int pageIndent() const;
    void setPageIndent(int indent);
    const QMargins& margins() const;
    void setMargins(const QMargins& margins);
    int itemIndent() const;
    void setItemIndent(int indent);
    void setAmimationSettings(int duration, const QEasingCurve& curve);
    int maxViewItemCount() const;
    void setMaxViewItemCount(int count);
    virtual QSize sizeHint() const;
    virtual int getColumnCount() const = 0;
    virtual QSize getColumnSize(int column) const = 0;
public Q_SLOTS:
    void movePrev();
    void moveNext();
    void moveTo(int column);
protected:
    virtual void resizeEvent(QResizeEvent* event);
    virtual void paintEvent(QPaintEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
protected:
    virtual QWidget* createViewWidget();
    void setPrevButtonVisible(bool visible);
    void setNextButtonVisible(bool visible);
    virtual void updateLayout();
    virtual void updateItemsLayout() = 0;
    int getColumnLength(int column) const;
    virtual QColor getButtonColor() const;
    virtual int calcColumnsLength(int columnCount) const;
    bool isColumnFirst(int first) const;
    bool isColumnLast(int last) const;
    void ensureVisible(int column);
    int calcNextColumn(int column, bool back) const;
    QPoint getViewOffset() const;
    void startScrollAnimation();
protected Q_SLOTS:
    void scrollAnimationFinished();
protected:
    friend class ScrollWidgetBarButton;
    ScrollWidgetBarButton* m_prevButton;
    ScrollWidgetBarButton* m_nextButton;
    Qt::Orientation m_orientation;
    int m_columnNum;
    int m_columnFirst;
    int m_columnLast;
    QWidget* m_viewWidget;
    int m_pageIndent;
    QMargins m_margins;
    int m_itemIndent;
    QPropertyAnimation* m_animation;
    int m_maxViewItemCount;
    Q_DISABLE_COPY(AbstractScrollWidgetBar)
};

class QTITAN_BASE_EXPORT ScrollWidgetBar : public AbstractScrollWidgetBar
{
    Q_OBJECT
public:
    ScrollWidgetBar(QWidget* parent, Qt::Orientation orientation = Qt::Horizontal);
    virtual ~ScrollWidgetBar();
    void addWidget(QWidget* widget);
    void removeWidget(QWidget* widget);
    void beginUpdate();
    void endUpdate();
    QWidget* getWidget(int index) const;
    int getWidgetCount() const;
    virtual int getColumnCount() const;
    virtual QSize getColumnSize(int column) const;
    virtual int getColumnIndex(QWidget* widget) const;
protected:
    virtual void updateItemsLayout();
    virtual bool focusNextPrevChild(bool next);
    QVector<QWidget *> m_widgets;
    int m_updateCount;
private:
    Q_DISABLE_COPY(ScrollWidgetBar)
};

class ScrollWidgetBarButton : public QAbstractButton
{
public:
    explicit ScrollWidgetBarButton(AbstractScrollWidgetBar* bar);
    virtual ~ScrollWidgetBarButton();
    virtual QSize sizeHint() const;
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
private:
private:
    Q_DISABLE_COPY(ScrollWidgetBarButton)
};

QTITAN_END_NAMESPACE

#endif// QTN_SCROLLWIDGETBAR_H


