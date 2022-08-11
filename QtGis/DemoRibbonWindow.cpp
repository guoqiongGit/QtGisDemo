#include <QApplication>
#include <QScreen>
#include <QtnRibbonDef.h>
#include <QtnToolTip.h>

#include "DemoRibbonWindow.h"


/* DemoRibbonWindow */
DemoRibbonWindow::DemoRibbonWindow(QWidget* parent)
    : RibbonMainWindow(parent)
    , m_defaultStyle(qApp->style()->objectName())
    , m_styleName(QStringLiteral("Default"))
    , m_pointSizeDefault(9)
{
    ToolTip::setWrapMode(ToolTip::NativeWrap);
    createOptions();
    updateStyleActions(m_styleName);

    QAction* actionAbout = ribbonBar()->addAction(QIcon(QStringLiteral(":/QtGis/images/res/about.png")), tr("About"), Qt::ToolButtonIconOnly);
    actionAbout->setToolTip(tr("Display program<br />information, version number and copyright"));
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    m_actionRibbonMinimize = ribbonBar()->addAction(QIcon(QStringLiteral(":/QtGis/images/res/ribbonMinimize.png")), tr("Minimize the Ribbon"), Qt::ToolButtonIconOnly);
    m_actionRibbonMinimize->setStatusTip(tr("Show only the tab names on the Ribbon"));
    m_actionRibbonMinimize->setShortcut(tr("Ctrl+F1"));
    connect(m_actionRibbonMinimize, SIGNAL(triggered()), this, SLOT(maximizeToggle()));
    connect(ribbonBar(), SIGNAL(minimizationChanged(bool)), this, SLOT(minimizationChangedIcon(bool)));

    m_actionRibbonMinimizeMenu = new QAction(tr("Minimize the Ribbon"), this);
    m_actionRibbonMinimizeMenu->setCheckable(true);
    connect(m_actionRibbonMinimizeMenu, SIGNAL(triggered()), this, SLOT(maximizeToggle()));
    connect(ribbonBar()->quickAccessBar(), SIGNAL(showCustomizeMenu(QMenu*)), this, SLOT(showQuickAccessCustomizeMenu(QMenu*)));
    connect(ribbonBar(), SIGNAL(showRibbonContextMenu(QMenu*, QContextMenuEvent*)), this, SLOT(showRibbonContextMenu(QMenu*, QContextMenuEvent*)));
}


QIcon DemoRibbonWindow::createIcon(ImagesId id, bool onlyLarge)
{
    QIcon icon;
    switch (id)
    {
    case Image_New:
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/new32x32.png")));
        break;
    case Image_Open:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/open16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/open32x32.png")));
        break;
    case Image_Save:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/save16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/save32x32.png")));
        break;
    case Image_SaveAs:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/saveasfile16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/saveasfile32x32.png")));
        break;
    case Image_Clipboard:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/clipboard16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/clipboard32x32.png")));
        break;
    case Image_Close:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/close16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/close32x32.png")));
        break;
    case Image_Exit:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/close16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/close32x32.png")));
        break;
    case Image_Cut:
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/cut16x16.png")));
        break;
    case Image_Undo:
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/undo16x16.png")));
        break;
    case Image_Redo:
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/redo16x16.png")));
        break;
    case Image_Print:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/print16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/res/print32x32.png")));
        break;
    case Add_RasterLayer:
        icon.addFile(":/QtGis/images/res/mActionAddRasterLayer.svg");
        break;
    case Add_VectorLayer:
        icon.addFile(":/QtGis/images/res/mActionAddVectorLayer.svg");
        break;
    case Add_Group:
        icon.addFile(":/QtGis/images/res/mActionAddGroup.svg");
        break;
    case Expand_All:
        icon.addFile(":/QtGis/images/res/mActionExpandAll.svg");
        break;
    case Collapse_All:
        icon.addFile(":/QtGis/images/res/mActionCollapseAll.svg");
        break;
    default:
        Q_ASSERT(false);
        break;
    }
    return icon;
}

QIcon DemoRibbonWindow::createIcon(const QString& smallIcon, const QString& largeIcon)
{
    QIcon icon;
    if (!smallIcon.isEmpty())
        icon.addPixmap(QPixmap(smallIcon));
    if (!largeIcon.isEmpty())
        icon.addPixmap(QPixmap(largeIcon));
    return icon;
}

void DemoRibbonWindow::createOptions()
{
    m_menuOptions = ribbonBar()->addMenu(tr("Options"));
    QAction* actionStyle = m_menuOptions->addAction(tr("Style"));

    QMenu* menuStyle = new QMenu(ribbonBar());
    m_styleActions = new QActionGroup(this);

    QAction* actionDefault = menuStyle->addAction(tr("Default"));
    actionDefault->setObjectName(QStringLiteral("Default"));
    actionDefault->setCheckable(true);
    actionDefault->setChecked(true);

    QAction* actionFusion = menuStyle->addAction(tr("Fusion"));
    actionFusion->setObjectName(QStringLiteral("Fusion"));
    actionFusion->setCheckable(true);

    menuStyle->addSeparator();

    m_styleActions->addAction(actionDefault);
    m_styleActions->addAction(actionFusion);

    QMenu* menuAdobePhotoshop = new QMenu(tr("Adobe Photoshop"), this);

    QAction* actionAdobePhotoshopLightGray = menuAdobePhotoshop->addAction(tr("Light Gray"));
    actionAdobePhotoshopLightGray->setObjectName(QStringLiteral("AdobePhotoshopLightGray"));
    actionAdobePhotoshopLightGray->setCheckable(true);
    m_styleActions->addAction(actionAdobePhotoshopLightGray);

    QAction* actionAdobePhotoshopGray = menuAdobePhotoshop->addAction(tr("Gray"));
    actionAdobePhotoshopGray->setObjectName(QStringLiteral("AdobePhotoshopGray"));
    actionAdobePhotoshopGray->setCheckable(true);
    m_styleActions->addAction(actionAdobePhotoshopGray);

    QAction* actionAdobePhotoshopDarkGray = menuAdobePhotoshop->addAction(tr("Dark Gray"));
    actionAdobePhotoshopDarkGray->setObjectName(QStringLiteral("AdobePhotoshopDarkGray"));
    actionAdobePhotoshopDarkGray->setCheckable(true);
    m_styleActions->addAction(actionAdobePhotoshopDarkGray);

    QAction* actionAdobePhotoshopBlack = menuAdobePhotoshop->addAction(tr("Black"));
    actionAdobePhotoshopBlack->setObjectName(QStringLiteral("AdobePhotoshopBlack"));
    actionAdobePhotoshopBlack->setCheckable(true);
    m_styleActions->addAction(actionAdobePhotoshopBlack);

    menuStyle->addMenu(menuAdobePhotoshop);

    menuStyle->addSeparator();

    QMenu* menuStyle2007 = new QMenu(tr("Office 2007"), this);
    QAction* actionBlue = menuStyle2007->addAction(tr("Blue"));
    actionBlue->setCheckable(true);
    actionBlue->setObjectName(QStringLiteral("Office2007Blue"));

    QAction* actionBlack = menuStyle2007->addAction(tr("Black"));
    actionBlack->setObjectName(QStringLiteral("Office2007Black"));
    actionBlack->setCheckable(true);

    QAction* actionSilver = menuStyle2007->addAction(tr("Silver"));
    actionSilver->setObjectName(QStringLiteral("Office2007Silver"));
    actionSilver->setCheckable(true);

    QAction* actionAqua = menuStyle2007->addAction(tr("Aqua"));
    actionAqua->setObjectName(QStringLiteral("Office2007Aqua"));
    actionAqua->setCheckable(true);
    menuStyle->addMenu(menuStyle2007);

    menuStyle->addSeparator();

    QAction* actionScenic = menuStyle->addAction(tr("Windows 7 Scenic"));
    actionScenic->setObjectName(QStringLiteral("Windows7Scenic"));
    actionScenic->setCheckable(true);

    menuStyle->addSeparator();

    QMenu* menuStyle2010 = new QMenu(tr("Office 2010"), this);
    QAction* action2010Blue = menuStyle2010->addAction(tr("Blue"));
    action2010Blue->setObjectName(QStringLiteral("Office2010Blue"));
    action2010Blue->setCheckable(true);

    QAction* action2010Silver = menuStyle2010->addAction(tr("Silver"));
    action2010Silver->setObjectName(QStringLiteral("Office2010Silver"));
    action2010Silver->setCheckable(true);

    QAction* action2010Black = menuStyle2010->addAction(tr("Black"));
    action2010Black->setObjectName(QStringLiteral("Office2010Black"));
    action2010Black->setCheckable(true);

    menuStyle->addMenu(menuStyle2010);

    menuStyle->addSeparator();

    QMenu* menuStyle2013 = new QMenu(tr("Office 2013"), this);
    QAction* action2013White = menuStyle2013->addAction(tr("White"));
    action2013White->setObjectName(QStringLiteral("Office2013White"));
    action2013White->setCheckable(true);

    QAction* action2013Gray = menuStyle2013->addAction(tr("Light Gray"));
    action2013Gray->setObjectName(QStringLiteral("Office2013Gray"));
    action2013Gray->setCheckable(true);
    menuStyle->addMenu(menuStyle2013);

    QAction* action2013Dark = menuStyle2013->addAction(tr("Dark Gray"));
    action2013Dark->setObjectName(QStringLiteral("Office2013Dark"));
    action2013Dark->setCheckable(true);
    menuStyle->addMenu(menuStyle2013);

    menuStyle->addSeparator();

    QMenu* menuStyle2016 = new QMenu(tr("Office 2016"), this);
    QAction* action2016Colorful = menuStyle2016->addAction(tr("Colorful"));
    action2016Colorful->setObjectName(QStringLiteral("Office2016Colorful"));
    action2016Colorful->setCheckable(true);

    QAction* action2016White = menuStyle2016->addAction(tr("White"));
    action2016White->setObjectName(QStringLiteral("Office2016White"));
    action2016White->setCheckable(true);

    QAction* action2016DarkGray = menuStyle2016->addAction(tr("Dark Gray"));
    action2016DarkGray->setObjectName(QStringLiteral("Office2016DarkGray"));
    action2016DarkGray->setCheckable(true);

    QAction* action2016Black = menuStyle2016->addAction(tr("Black"));
    action2016Black->setObjectName(QStringLiteral("Office2016Black"));
    action2016Black->setCheckable(true);

    menuStyle->addMenu(menuStyle2016);

    m_styleActions->addAction(actionBlue);
    m_styleActions->addAction(actionBlack);
    m_styleActions->addAction(actionSilver);
    m_styleActions->addAction(actionAqua);
    m_styleActions->addAction(actionScenic);
    m_styleActions->addAction(action2010Blue);
    m_styleActions->addAction(action2010Silver);
    m_styleActions->addAction(action2010Black);
    m_styleActions->addAction(action2013White);
    m_styleActions->addAction(action2013Gray);
    m_styleActions->addAction(action2013Dark);
    m_styleActions->addAction(action2016Colorful);
    m_styleActions->addAction(action2016White);
    m_styleActions->addAction(action2016DarkGray);
    m_styleActions->addAction(action2016Black);

    actionStyle->setMenu(menuStyle);
    connect(m_styleActions, SIGNAL(triggered(QAction*)), this, SLOT(styleChanged(QAction*)));

    m_menuOptions->addSeparator();

    m_actionAnimation = m_menuOptions->addAction(tr("Animation"));
    m_actionAnimation->setCheckable(true);
    connect(m_actionAnimation, SIGNAL(triggered(bool)), this, SLOT(setAnimation(bool)));

    m_menuOptions->addSeparator();

    QAction* actionTitleGroupsVisible = m_menuOptions->addAction(tr("Title Groups Visible"));
    actionTitleGroupsVisible ->setCheckable(true);
    actionTitleGroupsVisible ->setChecked(true);
    connect(actionTitleGroupsVisible , SIGNAL(triggered(bool)), this, SLOT(setTitleGroupsVisible(bool)));

    m_menuOptions->addSeparator();

    QAction* actionMenu = m_menuOptions->addAction(tr("Font"));
    QMenu* menuFont = new QMenu(ribbonBar());
    QActionGroup* fontActions = new QActionGroup(this);
    m_actionMinimal = menuFont->addAction(tr("Minimal"));
    m_actionMinimal->setCheckable(true);
    fontActions->addAction(m_actionMinimal);

    m_actionNormal = menuFont->addAction(tr("Normal"));
    m_actionNormal->setCheckable(true);
    m_actionNormal->setChecked(true);
    fontActions->addAction(m_actionNormal);

    m_actionLarge = menuFont->addAction(tr("Large"));
    m_actionLarge->setCheckable(true);
    fontActions->addAction(m_actionLarge);

    m_actionExLarge = menuFont->addAction(tr("Extra Large"));
    m_actionExLarge->setCheckable(true);
    fontActions->addAction(m_actionExLarge);
    actionMenu->setMenu(menuFont);
    connect(fontActions, SIGNAL(triggered(QAction*)), this, SLOT(optionsFont(QAction*)));

    m_menuOptions->addSeparator();

    QAction* actionFrameThemeEnabled = m_menuOptions->addAction(tr("Styled TitleBar"));
    actionFrameThemeEnabled->setCheckable(true);
    connect(actionFrameThemeEnabled, SIGNAL(triggered(bool)), ribbonBar(), SLOT(setFrameThemeEnabled(bool)));
    connect(ribbonBar(), SIGNAL(frameThemeChanged(bool)), actionFrameThemeEnabled, SLOT(setChecked(bool)));

    m_menuOptions->addSeparator();
    m_actionNativeScrollBars = m_menuOptions->addAction(tr("Native Scroll Bars"));
    m_actionNativeScrollBars->setCheckable(true);
    connect(m_actionNativeScrollBars, SIGNAL(triggered(bool)), this, SLOT(setNativeScrollBars(bool)));
#ifdef Q_OS_MAC
    setNativeScrollBars(true);
#endif
    m_actionNativeDialogs = m_menuOptions->addAction(tr("Native Dialogs"));
    m_actionNativeDialogs->setCheckable(true);
    connect(m_actionNativeDialogs, SIGNAL(triggered(bool)), this, SLOT(setNativeDialogs(bool)));
 
    m_menuOptions->addSeparator();
    QAction* actionCusomize = m_menuOptions->addAction(tr("Cusomize..."));
    actionCusomize->setEnabled(false);
#if QTN_ACTION_RTL
    m_actionRTL = m_menuOptions->addAction(tr("Right to Left Layout"), this, &DemoRibbonWindow::switchLayoutDirection);
    m_actionRTL->setCheckable(true);
    m_actionRTL->setChecked(layoutDirection() == Qt::RightToLeft);
#endif
    m_actionShowBelowRibbon = new QAction(tr("Show Below the Ribbon"), this);
    m_actionShowAboveRibbon = new QAction(tr("Show Above the Ribbon"), this);
    connect(m_actionShowBelowRibbon, SIGNAL(triggered()), this, SLOT(switchQuickAccessBarPosition()));
    connect(m_actionShowAboveRibbon, SIGNAL(triggered()), this, SLOT(switchQuickAccessBarPosition()));

    QFont fnt = ribbonBar()->font();
    m_pointSizeDefault = fnt.pointSize();
}

void DemoRibbonWindow::updateStyleActions(const QString& styleName)
{
    QList<QAction*> actionList = m_styleActions->actions();
    for (QList<QAction*>::ConstIterator it = actionList.begin(); it != actionList.end(); ++it)
    {
        QAction* act = (*it);
        if (act->objectName() == styleName)
        {
            act->setChecked(true);
            break;
        }
    }

    CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style());
    if (style != Q_NULL && QLatin1String(style->metaObject()->className()) != QStringLiteral(QTITAN_META_CLASSNAME("CommonStyle")))
    {
        m_actionNativeScrollBars->setChecked(style->isScrollBarsIgnored());
        m_actionNativeDialogs->setChecked(style->isDialogsIgnored());
        m_actionAnimation->setChecked(style->isAnimationEnabled());
        
        m_actionNativeScrollBars->setEnabled(true);
        m_actionNativeDialogs->setEnabled(true);
        m_actionAnimation->setEnabled(true);
    }
    else
    {
        m_actionNativeScrollBars->setChecked(false);
        m_actionNativeDialogs->setChecked(false);
        m_actionAnimation->setChecked(false);

        m_actionNativeScrollBars->setEnabled(false);
        m_actionNativeDialogs->setEnabled(false);
        m_actionAnimation->setEnabled(false);
    }
}

void DemoRibbonWindow::setCustomStyle(const QString& styleName)
{
    if (ribbonBar()->systemButton())
        ribbonBar()->systemButton()->setToolButtonStyle(Qt::ToolButtonTextOnly);

    if (m_styleName == styleName)
        return;

    if (styleName == QLatin1String("Default"))
    {
        qApp->setStyle(m_defaultStyle);
    }
    else if (styleName == QLatin1String("Fusion"))
    {
        qApp->setStyle(QLatin1String("fusion"));
    }
    else if (styleName == QLatin1String("AdobePhotoshopLightGray") ||
             styleName == QLatin1String("AdobePhotoshopGray") ||
             styleName == QLatin1String("AdobePhotoshopDarkGray") ||
             styleName == QLatin1String("AdobePhotoshopBlack"))
    {
        AdobePhotoshopStyle* style = qobject_cast<AdobePhotoshopStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new AdobePhotoshopStyle();
        if (styleName == QLatin1String("AdobePhotoshopLightGray") && style->theme() != AdobePhotoshopStyle::LightGray)
            style->setTheme(AdobePhotoshopStyle::LightGray);
        if (styleName == QLatin1String("AdobePhotoshopGray") && style->theme() != AdobePhotoshopStyle::Gray)
            style->setTheme(AdobePhotoshopStyle::Gray);
        if (styleName == QLatin1String("AdobePhotoshopDarkGray") && style->theme() != AdobePhotoshopStyle::DarkGray)
            style->setTheme(AdobePhotoshopStyle::DarkGray);
        if (styleName == QLatin1String("AdobePhotoshopBlack") && style->theme() != AdobePhotoshopStyle::Black)
            style->setTheme(AdobePhotoshopStyle::Black);
        qApp->setStyle(style);
    }
    else if (styleName == QLatin1String("Office2007Blue")  ||
             styleName == QLatin1String("Office2007Black") ||
             styleName == QLatin1String("Office2007Silver")||
             styleName == QLatin1String("Office2007Aqua"))
    {
        if (ribbonBar()->systemButton())
            ribbonBar()->systemButton()->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        Office2007Style* style = qobject_cast<Office2007Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2007Style();
        if (styleName == QLatin1String("Office2007Blue") && style->theme() != Office2007Style::Blue)
            style->setTheme(Office2007Style::Blue);
        else if (styleName == QLatin1String("Office2007Black") && style->theme() != Office2007Style::Black)
            style->setTheme(Office2007Style::Black);
        else if (styleName == QLatin1String("Office2007Silver") && style->theme() != Office2007Style::Silver)
            style->setTheme(Office2007Style::Silver);
        else if (styleName == QLatin1String("Office2007Aqua") && style->theme() != Office2007Style::Aqua)
            style->setTheme(Office2007Style::Aqua);
        qApp->setStyle(style);
    }
    else if (styleName == QLatin1String("Windows7Scenic"))
    {
        if (ribbonBar()->systemButton())
            ribbonBar()->systemButton()->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        Windows7ScenicStyle* style = qobject_cast<Windows7ScenicStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new Windows7ScenicStyle();
        qApp->setStyle(style);
    }
    else if (styleName == QLatin1String("Office2010Black") ||
             styleName == QLatin1String("Office2010Blue")  ||
             styleName == QLatin1String("Office2010Silver"))
    {
        Office2010Style* style = qobject_cast<Office2010Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2010Style();
        if (styleName == QLatin1String("Office2010Black") && style->theme() != Office2010Style::Black)
            style->setTheme(Office2010Style::Black);
        else if (styleName == QLatin1String("Office2010Blue") && style->theme() != Office2010Style::Blue)
            style->setTheme(Office2010Style::Blue);
        else if (styleName == QLatin1String("Office2010Silver") && style->theme() != Office2010Style::Silver)
            style->setTheme(Office2010Style::Silver);
        qApp->setStyle(style);
    }
    else if (styleName == QLatin1String("Office2013White") ||
             styleName == QLatin1String("Office2013Gray")  ||
             styleName == QLatin1String("Office2013Dark"))
    {
        Office2013Style* style = qobject_cast<Office2013Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2013Style();
        if (styleName == QLatin1String("Office2013White") && style->theme() != Office2013Style::White)
            style->setTheme(Office2013Style::White);
        else if (styleName == QLatin1String("Office2013Gray") && style->theme() != Office2013Style::Gray)
            style->setTheme(Office2013Style::Gray);
        else if (styleName == QLatin1String("Office2013Dark") && style->theme() != Office2013Style::Dark)
            style->setTheme(Office2013Style::Dark);
        qApp->setStyle(style);
    }
    else if (styleName == QLatin1String("Office2016Colorful") ||
             styleName == QLatin1String("Office2016White")    ||
             styleName == QLatin1String("Office2016DarkGray") ||
             styleName == QLatin1String("Office2016Black"))
    {
        Office2016Style* style = qobject_cast<Office2016Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2016Style();
        if (styleName == QLatin1String("Office2016Colorful") && style->theme() != Office2016Style::Colorful)
            style->setTheme(Office2016Style::Colorful);
        else if (styleName == QLatin1String("Office2016White") && style->theme() != Office2016Style::White)
            style->setTheme(Office2016Style::White);
        else if (styleName == QLatin1String("Office2016DarkGray") && style->theme() != Office2016Style::DarkGray)
            style->setTheme(Office2016Style::DarkGray);
        else if (styleName == QLatin1String("Office2016Black") && style->theme() != Office2016Style::Black)
            style->setTheme(Office2016Style::Black);
        qApp->setStyle(style);
    }
    m_styleName = styleName;
    m_actionNormal->setChecked(true);
    updateStyleActions(styleName);
}

void DemoRibbonWindow::about()
{
}

void DemoRibbonWindow::styleChanged(QAction* action)
{
    setCustomStyle(action->objectName());
}

void DemoRibbonWindow::setAnimation(bool checked)
{
    if (CommonStyle* st = qobject_cast<CommonStyle*>(qApp->style()))
        st->setAnimationEnabled(checked);
}

void DemoRibbonWindow::setTitleGroupsVisible(bool checked)
{
    ribbonBar()->setTitleGroupsVisible(checked);
}

void DemoRibbonWindow::maximizeToggle()
{
    ribbonBar()->setMinimized(!ribbonBar()->isMinimized());
}

void DemoRibbonWindow::minimizationChangedIcon(bool minimized)
{
    m_actionRibbonMinimize->setChecked(minimized);
    m_actionRibbonMinimizeMenu->setChecked(minimized);
    m_actionRibbonMinimize->setIcon(minimized ? QIcon(QStringLiteral(":/QtGis/images/res/ribbonMaximize.png")) :
        QIcon(QStringLiteral(":/QtGis/images/res/ribbonMinimize.png")));
}

void DemoRibbonWindow::showQuickAccessCustomizeMenu(QMenu* menu)
{
    menu->addSeparator()->setText(tr("Common Customization"));
    menu->addAction(ribbonBar()->quickAccessBarPosition() == RibbonBar::QATopPosition ? m_actionShowBelowRibbon : m_actionShowAboveRibbon);
    menu->addSeparator();
    menu->addAction(m_actionRibbonMinimizeMenu);
}

void DemoRibbonWindow::switchQuickAccessBarPosition()
{
    ribbonBar()->setQuickAccessBarPosition(ribbonBar()->quickAccessBarPosition() == RibbonBar::QATopPosition ? 
        RibbonBar::QABottomPosition : RibbonBar::QATopPosition);
}

void DemoRibbonWindow::setNativeScrollBars(bool on)
{
    if (CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style()))
        style->setScrollBarsIgnored(on);
}

void DemoRibbonWindow::setNativeDialogs(bool on)
{
    if (CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style()))
        style->setDialogsIgnored(on);
}

void DemoRibbonWindow::optionsFont(QAction* act)
{
    int psz = m_pointSizeDefault;
    QFont fnt = ribbonBar()->font();
    fnt.setPointSize(psz);
    if (m_actionMinimal == act)
        fnt.setPointSize(psz - 1);
    else if (m_actionLarge == act)
        fnt.setPointSize(psz + 1);
    else if (m_actionExLarge == act)
        fnt.setPointSize(psz + 2);
    ribbonBar()->setFont(fnt);
}

void DemoRibbonWindow::switchLayoutDirection()
{
    if (layoutDirection() == Qt::LeftToRight)
        QApplication::setLayoutDirection(Qt::RightToLeft);
    else
        QApplication::setLayoutDirection(Qt::LeftToRight);
}

void DemoRibbonWindow::showRibbonContextMenu(QMenu* menu, QContextMenuEvent* event)
{
    Q_UNUSED(menu)
    event->setAccepted(false);
}

void setDefaultWidgetGeometry(QWidget* widget, int factor)
{
    Q_ASSERT(widget != Q_NULL);
    Q_ASSERT(factor > 0);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    const QRect availableGeometry = widget->screen()->availableGeometry();
    widget->resize(2 * availableGeometry.width() / factor, 2 * availableGeometry.height() / factor);
    widget->move((availableGeometry.width() - widget->width()) / 2, (availableGeometry.height() - widget->height()) / 2);
#else
    widget->resize(800, 640); widget->move(200, 200);
#endif
}
