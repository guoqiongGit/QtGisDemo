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
#include <QtDesigner/QDesignerFormEditorInterface>
#include <QVariant>
#include "QtnRibbonWorkspaceDsgnPlugin.h"
#include "QtnRibbonWorkspace.h"

QTITAN_USE_NAMESPACE


/* RibbonWorkspaceDsgnPlugin */
RibbonWorkspaceDsgnPlugin::RibbonWorkspaceDsgnPlugin(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_core(Q_NULL)
{
}

RibbonWorkspaceDsgnPlugin::~RibbonWorkspaceDsgnPlugin()
{
}

QString RibbonWorkspaceDsgnPlugin::name() const
{
    return create_qtitan_className(QStringLiteral("RibbonWorkspace"));
}

QString RibbonWorkspaceDsgnPlugin::group() const
{
    return QStringLiteral("[invisible]");
}

QString RibbonWorkspaceDsgnPlugin::toolTip() const
{
    return tr("Advanced RibbonWorkspace for Qt.C++");
}

QString RibbonWorkspaceDsgnPlugin::whatsThis() const
{
    return tr("Advanced RibbonWorkspace for Qt.C++");
}

QString RibbonWorkspaceDsgnPlugin::includeFile() const
{
    return QStringLiteral("DevMachines/QtitanRibbon");
}

QIcon RibbonWorkspaceDsgnPlugin::icon() const
{
    return QIcon();
}

bool RibbonWorkspaceDsgnPlugin::isContainer() const
{
    return false;
}

static const char *formEditorDynamicProperty = "_q_formEditorObject";

QWidget* RibbonWorkspaceDsgnPlugin::createWidget(QWidget* parent)
{
    RibbonWorkspace* workspace = new RibbonWorkspace(parent);
    workspace->setProperty(formEditorDynamicProperty, QVariant(true));
    workspace->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    workspace->setFocusPolicy(Qt::NoFocus);
    workspace->setWindowFlags(workspace->windowFlags() & ~Qt::Window);
    // Make sure it is non-modal (for example, Dialog calls setModal(true) in the constructor).
    workspace->setWindowModality(Qt::NonModal);
    return workspace;
}

bool RibbonWorkspaceDsgnPlugin::isInitialized() const
{
    return m_initialized;
}

void RibbonWorkspaceDsgnPlugin::initialize(QDesignerFormEditorInterface* formEditor)
{
    Q_UNUSED(formEditor);

    if (m_initialized)
        return;
    m_core = formEditor;
    m_initialized = true;
}

QString RibbonWorkspaceDsgnPlugin::domXml() const
{
    return QString();
}



