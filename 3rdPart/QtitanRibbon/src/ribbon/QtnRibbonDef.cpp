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

#include "QtnRibbonDef.h"
#ifdef QTN_MEMORY_DEBUG
#include "QtitanMSVSDebug.h"
#endif


const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonCustomizeQuickAccessToolBarDotString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Customize Quick Access Toolbar...");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonCustomizeQuickAccessToolBarString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Customize Quick Access Toolbar");

const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonShowQuickAccessToolBarBelowString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Show Quick Access Toolbar Below the Ribbon");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonShowQuickAccessToolBarAboveString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Show Quick Access Toolbar Above the Ribbon");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonCustomizeDialogOptionsString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Options");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonCustomizeActionString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Customize the Ribbon...");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonMinimizeActionString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Minimize the Ribbon");

const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonRecentDocumentsString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Recent Documents");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonUntitledString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "Untitled");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonSeparatorString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "<Separator>");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonNewPageString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "New Page");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonNewGroupString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "New Group");
const char* QTITAN_PREPEND_NAMESPACE(QtnRibbonAddCommandWarningString) = QT_TRANSLATE_NOOP("Qtitan::RibbonBar", "One should add commands to custom groups. To create a group, choose page in list and press button 'Create group'.");

const char* QTITAN_PREPEND_NAMESPACE(getRibbonVersion)()
{
    return QTN_VERSION_RIBBON_STR;
}

#ifdef QTITAN_DEMO
#include "QtnDemo.h"
START_QTITANRIBBON_DEMO
#endif
