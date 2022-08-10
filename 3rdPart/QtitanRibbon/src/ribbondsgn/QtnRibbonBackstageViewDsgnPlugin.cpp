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
#include <QApplication>
#include <QAction>
#include <QLineEdit>

#include <QtDesigner/QDesignerFormEditorInterface>
#include <QtDesigner/QExtensionManager>
#include <QtDesigner/QDesignerContainerExtension>

#include "QtnRibbonBackstageViewDsgnPlugin.h"
#include "QtnRibbonBackstageView.h"
#include "QtnOffice2016Style.h"

QTITAN_USE_NAMESPACE

/* RibbonBackstageButtonPlugin */
RibbonBackstageSeparatorPlugin::RibbonBackstageSeparatorPlugin(QObject* parent)
    : QObject(parent)
    , m_pStyle(new Office2016Style())
{
    initialized = false;
}

RibbonBackstageSeparatorPlugin::~RibbonBackstageSeparatorPlugin()
{
    delete m_pStyle;
}

QString RibbonBackstageSeparatorPlugin::name() const
{
    return create_qtitan_className(QStringLiteral("RibbonBackstageSeparator"));
}

QString RibbonBackstageSeparatorPlugin::group() const
{
     return QStringLiteral("Developer Machines (Components)");
}

QString RibbonBackstageSeparatorPlugin::toolTip() const
{
    return tr("Backstage separator for Ribbon Interface");
}

QString RibbonBackstageSeparatorPlugin::whatsThis() const
{
    return tr("Backstage separator for Ribbon Interface");
}

QString RibbonBackstageSeparatorPlugin::includeFile() const
{
    return QStringLiteral("DevMachines/QtitanRibbon");
}

QIcon RibbonBackstageSeparatorPlugin::icon() const
{
    return QIcon(QStringLiteral(":res/ribbonbackstageseparator_icon.png"));
}

bool RibbonBackstageSeparatorPlugin::isContainer() const
{
    return false;
}

QWidget* RibbonBackstageSeparatorPlugin::createWidget(QWidget* parent)
{
    RibbonBackstageSeparator* separator = new RibbonBackstageSeparator(parent);
    separator->setStyle(m_pStyle);
    return separator;
}

bool RibbonBackstageSeparatorPlugin::isInitialized() const
{
    return initialized;
}

void RibbonBackstageSeparatorPlugin::initialize(QDesignerFormEditorInterface* formEditor)
{
    Q_UNUSED(formEditor);
    if (initialized)
        return;

    initialized = true;
}

QString RibbonBackstageSeparatorPlugin::codeTemplate() const
{ 
    return QString(); 
}

QString RibbonBackstageSeparatorPlugin::domXml() const
{
    QString className = create_qtitan_className(QStringLiteral("RibbonBackstageSeparator"));
    return QStringLiteral("<ui language=\"c++\">\n"
        " <widget class=\"" "%1" "\" name=\"backstageSeparator\">\n"
        "  <property name=\"geometry\">\n"
        "   <rect>\n"
        "    <width>120</width>\n"
        "    <height>3</height>\n"
        "   </rect>\n"
        "  </property>\n"
        " </widget>\n"
        "</ui>\n").arg(className);
}




/* RibbonBackstageButtonPlugin */
RibbonBackstageButtonPlugin::RibbonBackstageButtonPlugin(QObject *parent)
    : QObject(parent)
    , m_pStyle(new Office2016Style())
{
    initialized = false;
}

RibbonBackstageButtonPlugin::~RibbonBackstageButtonPlugin()
{
    delete m_pStyle;
}

QString RibbonBackstageButtonPlugin::name() const
{
    return create_qtitan_className(QStringLiteral("RibbonBackstageButton"));
}

QString RibbonBackstageButtonPlugin::group() const
{
    return QStringLiteral("Developer Machines (Components)");
}

QString RibbonBackstageButtonPlugin::toolTip() const
{
    return tr("Backstage Button for Ribbon Interface");
}

QString RibbonBackstageButtonPlugin::whatsThis() const
{
    return tr("Backstage Button for Ribbon Interface");
}

QString RibbonBackstageButtonPlugin::includeFile() const
{
    return QStringLiteral("DevMachines/QtitanRibbon");
}

QIcon RibbonBackstageButtonPlugin::icon() const
{
    return QIcon(QStringLiteral(":res/ribbonbackstagebutton_icon.png"));
}

bool RibbonBackstageButtonPlugin::isContainer() const
{
    return false;
}

QWidget* RibbonBackstageButtonPlugin::createWidget(QWidget* parent)
{
    RibbonBackstageButton* button = new RibbonBackstageButton(parent);
    button->setStyle(m_pStyle);
    return button;
}

bool RibbonBackstageButtonPlugin::isInitialized() const
{
    return initialized;
}

void RibbonBackstageButtonPlugin::initialize(QDesignerFormEditorInterface* formEditor)
{
    Q_UNUSED(formEditor);
    if (initialized)
        return;
    initialized = true;

//    QExtensionManager* manager = formEditor->extensionManager();
//    Q_ASSERT(manager != Q_NULL);
//    pManager->registerExtensions(new MainWindowContainerFactory(m_pStyle, pManager), Q_TYPEID(QDesignerContainerExtension));
}

QString RibbonBackstageButtonPlugin::codeTemplate() const
{ 
    return QString(); 
}

QString RibbonBackstageButtonPlugin::domXml() const
{
    QString className = create_qtitan_className(QStringLiteral("RibbonBackstageButton"));
    return QStringLiteral("<ui language=\"c++\">\n"
        " <widget class=\"" "%1" "\" name=\"backstageButton\">\n"
        "  <property name=\"geometry\">\n"
        "   <rect>\n"
        "    <width>100</width>\n"
        "    <height>100</height>\n"
        "   </rect>\n"
        "  </property>\n"
        " </widget>\n"
        "</ui>\n").arg(className);
}



/* RibbonBackstageButtonPlugin */
RibbonBackstagePagePlugin::RibbonBackstagePagePlugin(QObject* parent)
    : QObject(parent)
    , m_pStyle(new Office2016Style())
{
    initialized = false;
}

RibbonBackstagePagePlugin::~RibbonBackstagePagePlugin()
{
    delete m_pStyle;
}

QString RibbonBackstagePagePlugin::name() const
{
    return create_qtitan_className(QStringLiteral("RibbonBackstagePage"));
}

QString RibbonBackstagePagePlugin::group() const
{
    return QStringLiteral("[invisible]");
}

QString RibbonBackstagePagePlugin::toolTip() const
{
    return tr("Advanced RibbonBackstagePage for Qt/C++");
}

QString RibbonBackstagePagePlugin::whatsThis() const
{
    return tr("Advanced RibbonBackstagePage for Qt/C++");
}

QString RibbonBackstagePagePlugin::includeFile() const
{
    return QStringLiteral("DevMachines/QtitanRibbon");
}

QIcon RibbonBackstagePagePlugin::icon() const
{
    return QIcon();
}

bool RibbonBackstagePagePlugin::isContainer() const
{
    return false;
}

QWidget* RibbonBackstagePagePlugin::createWidget(QWidget* parent)
{
    RibbonBackstagePage* page = new RibbonBackstagePage(parent);
    page->setStyle(m_pStyle);
    return page;
}

bool RibbonBackstagePagePlugin::isInitialized() const
{
    return initialized;
}

void RibbonBackstagePagePlugin::initialize(QDesignerFormEditorInterface* formEditor)
{
    Q_UNUSED(formEditor);
    if (initialized)
        return;
    initialized = true;
}

QString RibbonBackstagePagePlugin::domXml() const
{
    return QString();
}

