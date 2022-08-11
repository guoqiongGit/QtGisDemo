#ifndef QTN_DEMORIBBONWINDOW_H
#define QTN_DEMORIBBONWINDOW_H

#include <QtitanRibbon.h>
#define QTN_ACTION_RTL 0

class DemoRibbonWindow : public RibbonMainWindow
{
  Q_OBJECT
public:
    enum ImagesId
    {
        Image_New,
        Image_Open,
        Image_Save,
        Image_SaveAs,
        Image_Clipboard,
        Image_Close,
        Image_Cut,
        Image_Undo,
        Image_Redo,
        Image_Print,
        Image_Exit,
        Add_RasterLayer,
        Add_VectorLayer,
        Add_Group,
        Expand_All,
        Collapse_All,
    };
    explicit DemoRibbonWindow(QWidget* parent = Q_NULL);
    static QIcon createIcon(ImagesId id, bool onlyLarge = false);
    static QIcon createIcon(const QString& smallIcon, const QString& largeIcon);
public Q_SLOTS:
    virtual void setCustomStyle(const QString& styleName);
private:
    void createOptions();
protected:
    virtual void updateStyleActions(const QString& styleName);
protected Q_SLOTS:
    virtual void about();
    void styleChanged(QAction* action);
    void setAnimation(bool);
    void setTitleGroupsVisible(bool);
    void maximizeToggle();
    void minimizationChangedIcon(bool minimized);
    void showQuickAccessCustomizeMenu(QMenu* menu);
    void switchQuickAccessBarPosition();
    void setNativeScrollBars(bool);
    void setNativeDialogs(bool);
    void optionsFont(QAction* act);
    void switchLayoutDirection();
    virtual void showRibbonContextMenu(QMenu* menu, QContextMenuEvent* event);
protected:
    QString m_defaultStyle;
    QString m_styleName;
    QMenu* m_menuOptions;
    QActionGroup* m_styleActions;

    QAction* m_actionAnimation;
    QAction* m_actionNativeScrollBars;
    QAction* m_actionNativeDialogs;

    QAction* m_actionRibbonMinimize;
    QAction* m_actionRibbonMinimizeMenu;
    QAction* m_actionShowBelowRibbon;
    QAction* m_actionShowAboveRibbon;

    QAction* m_actionMinimal;
    QAction* m_actionNormal;
    QAction* m_actionLarge;
    QAction* m_actionExLarge;
#if QTN_ACTION_RTL
    QAction* m_actionRTL;
#endif
    int m_pointSizeDefault;
private:
    Q_DISABLE_COPY(DemoRibbonWindow)
};

void setDefaultWidgetGeometry(QWidget* wd, int factor = 3);

#endif // QTN_DEMORIBBONWINDOW_H
