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
#ifndef QTN_RIBBONBUTTON_H
#define QTN_RIBBONBUTTON_H

#include <QStyle>
#include <QToolButton>
#include <QStringList>
#include "QtitanDef.h"


QTITAN_BEGIN_NAMESPACE

class QTITAN_EXPORT RibbonButton : public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(bool wordWrap READ wordWrap WRITE setWordWrap)
public:
    explicit RibbonButton(QWidget* parent = Q_NULL);
    virtual ~RibbonButton();
public:
    bool wordWrap() const;
    void setWordWrap(bool on);

    bool isLargeIcon() const;
    void setLargeIcon(bool large);
public:
    virtual QSize sizeHint() const;
protected:
    void resetWordWrap();
    QSize sizeWordWrap();
    void updateIconSize();
protected:
    virtual bool event(QEvent* event);
    virtual void paintEvent(QPaintEvent* event);
    virtual void actionEvent(QActionEvent* event);
    virtual void changeEvent(QEvent* event);
private:
    bool m_wordWrap;
    bool m_largeIcon;
    int m_wrapIndex;
    QSize m_sizeHint;
    QSize m_sizeWordWrap;
    Qt::ToolButtonStyle m_saveButtonStyle;
    Qt::ArrowType m_saveArrowType;
    QVector<int> m_wordIndexes;
private:
    Q_DISABLE_COPY(RibbonButton)
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONBUTTON_H
