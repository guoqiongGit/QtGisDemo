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
#ifndef QTN_RIBBONSYSTEMMENU_H
#define QTN_RIBBONSYSTEMMENU_H

#include "QtnPopupMenu.h"
#include <QToolButton>

#include "QtitanDef.h"

QTITAN_BEGIN_NAMESPACE

class SystemToolButtonStyleOption;
class RibbonBackstageView;
class RibbonSystemButtonPrivate;
class RibbonSystemMenu;
class QTITAN_EXPORT RibbonSystemButton : public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(Qt::ToolButtonStyle toolButtonStyle READ toolButtonStyle WRITE setToolButtonStyle)
public:
    explicit RibbonSystemButton(QWidget* parent);
    virtual ~RibbonSystemButton();
public:
    RibbonBackstageView* backstage() const;
    void setBackstage(RibbonBackstageView* backstage);

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor& color);

    RibbonSystemMenu* systemMenu() const;
    void setSystemMenu(RibbonSystemMenu* menu);

    void initButtonStyleOption(SystemToolButtonStyleOption* option) const;
public:
    virtual QSize sizeHint() const;
protected:
    virtual bool event(QEvent* event);
    virtual bool eventFilter(QObject* watched, QEvent* event);
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
private:
    friend class RibbonSystemMenu;
    Q_DISABLE_COPY(RibbonSystemButton)
    QTN_DECLARE_PRIVATE(RibbonSystemButton)
};

class RibbonPageSystemRecentFileList;
class RibbonPageSystemPopup;
class RibbonFrameMenuStyleOption;
class RibbonSystemMenuPrivate;
class QTITAN_EXPORT RibbonSystemMenu : public PopupMenu
{
    Q_OBJECT
public:
    explicit RibbonSystemMenu(QWidget* parent);
    virtual ~RibbonSystemMenu();
public:
    QAction* addPopupBarAction(const QString& text);
    void addPopupBarAction(QAction* action, Qt::ToolButtonStyle style = Qt::ToolButtonTextOnly);
    RibbonPageSystemRecentFileList* addPageRecentFile(const QString& caption);
    RibbonPageSystemPopup* addPageSystemPopup(const QString& caption, QAction* defaultAction, bool splitAction);
public:
    virtual QSize sizeHint() const;
protected:
    void initFrameMenuStyleOption(RibbonFrameMenuStyleOption* option) const;
protected:
    virtual void showEvent(QShowEvent* event);
    virtual void paintEvent(QPaintEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void resizeEvent(QResizeEvent* event);
    virtual void changeEvent(QEvent* event);
private:
    friend class RibbonPageSystemPopup;
    friend class RibbonPageSystemPopupPrivate;
    friend class RibbonPageSystemRecentFileList;
    Q_DISABLE_COPY(RibbonSystemMenu)
    QTN_DECLARE_EX_PRIVATE(RibbonSystemMenu)
};

class RibbonPageSystemRecentFileListPrivate;
class QTITAN_EXPORT RibbonPageSystemRecentFileList : public QWidget
{
    Q_OBJECT
public:
    RibbonPageSystemRecentFileList(const QString& caption);
    virtual ~RibbonPageSystemRecentFileList();
public:
    virtual QSize sizeHint() const;
    void setSize(int size);
    int getSize() const; 
    QAction* getCurrentAction() const;
public Q_SLOTS:
    void updateRecentFileActions(const QStringList& files);
Q_SIGNALS:
    void openRecentFile(const QString& file);
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void drawEvent(QPaintEvent* event, QPainter* p);
protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void resizeEvent(QResizeEvent* event);
private:
    friend class RibbonSystemMenu;
    Q_DISABLE_COPY(RibbonPageSystemRecentFileList)
    QTN_DECLARE_PRIVATE(RibbonPageSystemRecentFileList)
};

class RibbonPageSystemPopupPrivate;
class QTITAN_EXPORT RibbonPageSystemPopup : public PopupMenu
{
    Q_OBJECT
public:
    RibbonPageSystemPopup(const QString& caption, QWidget* parent = Q_NULL);
    virtual ~RibbonPageSystemPopup();
public:
    virtual QSize sizeHint() const;
protected:
    virtual bool event(QEvent* event);
    virtual void paintEvent(QPaintEvent* event);
private:
    Q_DISABLE_COPY(RibbonPageSystemPopup)
    QTN_DECLARE_EX_PRIVATE(RibbonPageSystemPopup)
};

QTITAN_END_NAMESPACE

#endif // QTN_RIBBONSYSTEMMENU_H
