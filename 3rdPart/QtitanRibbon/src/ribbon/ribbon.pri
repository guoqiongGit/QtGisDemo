QTN_COMPONENT_VERSION = 5.8.1
DEFINES += QTN_VERSION_RIBBON=$$QTN_COMPONENT_VERSION

INCLUDEPATH += $$quote($$PWD/../../include)
INCLUDEPATH += $$quote($$PWD/../styles)
INCLUDEPATH += $$quote($$PWD/../base)

ALL_SOURCES = \
    $$PWD/QtnRibbonSliderPane.cpp \
    $$PWD/QtnRibbonStatusBar.cpp \
    $$PWD/QtnRibbonTabBar.cpp \
    $$PWD/QtnRibbonSystemMenu.cpp \
    $$PWD/QtnRibbonPage.cpp \
    $$PWD/QtnRibbonGroup.cpp \
    $$PWD/QtnRibbonBar.cpp \
    $$PWD/QtnRibbonPrivate.cpp \
    $$PWD/QtnRibbonMainWindow.cpp \
    $$PWD/QtnRibbonButtonPrivate.cpp \
    $$PWD/QtnRibbonTitleBarWidgetPrivate.cpp \
    $$PWD/QtnRibbonControls.cpp \
    $$PWD/QtnRibbonButtonControls.cpp \
    $$PWD/QtnRibbonInputControls.cpp \
    $$PWD/QtnRibbonGalleryControls.cpp \
    $$PWD/QtnRibbonKeyTip.cpp \
    $$PWD/QtnRibbonQuickAccessBar.cpp \
    $$PWD/QtnOfficePopupColorButton.cpp \
    $$PWD/QtnRibbonGallery.cpp \
    $$PWD/QtnOfficePopupMenu.cpp \
    $$PWD/QtnRibbonBackstageView.cpp \
    $$PWD/QtnOfficePopupWindow.cpp \
    $$PWD/QtnRibbonWorkspace.cpp \
    $$PWD/QtnRibbonCustomizeDialog.cpp \
    $$PWD/QtnRibbonCustomizePage.cpp \
    $$PWD/QtnRibbonCustomizeManager.cpp \
    $$PWD/QtnRibbonDef.cpp

INCLUDE_HEADERS = \
    $$PWD/../../include/QtitanRibbon.h \
    $$PWD/../../include/QtitanDef.h \
    $$PWD/../../include/QtnRibbonDef.h \
    $$PWD/../../include/QtnRibbonBackstageView.h \
    $$PWD/../../include/QtnRibbonBar.h \
    $$PWD/../../include/QtnRibbonGallery.h \
    $$PWD/../../include/QtnOfficePopupMenu.h \
    $$PWD/../../include/QtnOfficePopupColorButton.h \
    $$PWD/../../include/QtnOfficePopupWindow.h \
    $$PWD/../../include/QtnRibbonGroup.h \
    $$PWD/../../include/QtnRibbonMainWindow.h \
    $$PWD/../../include/QtnRibbonPage.h \
    $$PWD/../../include/QtnRibbonQuickAccessBar.h \
    $$PWD/../../include/QtnRibbonSliderPane.h \
    $$PWD/../../include/QtnRibbonStatusBar.h \
    $$PWD/../../include/QtnRibbonSliderPane.h \
    $$PWD/../../include/QtnRibbonSystemMenu.h \
    $$PWD/../../include/QtnRibbonInputControls.h \
    $$PWD/../../include/QtnRibbonButtonControls.h \
    $$PWD/../../include/QtnRibbonGalleryControls.h \
    $$PWD/../../include/QtnRibbonCustomizeManager.h \
    $$PWD/../../include/QtnRibbonCustomizeDialog.h \
    $$PWD/../../include/QtnRibbonCustomizePage.h \
    $$PWD/../../include/QtnRibbonWorkspace.h

PRIVATE_HEADERS = \
    $$PWD/QtnRibbonBarPrivate.h \
    $$PWD/QtnRibbonPagePrivate.h \
    $$PWD/QtnRibbonGroupPrivate.h \
    $$PWD/QtnRibbonPrivate.h \
    $$PWD/QtnRibbonStatusBarPrivate.h \
    $$PWD/QtnRibbonGalleryPrivate.h \
    $$PWD/QtnRibbonBackstageViewPrivate.h \
    $$PWD/QtnRibbonSliderPanePrivate.h \
    $$PWD/QtnRibbonSystemMenuPrivate.h \
    $$PWD/QtnRibbonTitleBarWidgetPrivate.h \
    $$PWD/QtnRibbonQuickAccessBarPrivate.h

PUBLIC_HEADERS = \
    $$PWD/QtnRibbonDef.h \
    $$PWD/QtnRibbonSliderPane.h \
    $$PWD/QtnRibbonStatusBar.h \
    $$PWD/QtnRibbonTabBar.h \
    $$PWD/QtnRibbonSystemMenu.h \
    $$PWD/QtnRibbonPage.h \
    $$PWD/QtnRibbonGroup.h \
    $$PWD/QtnRibbonBar.h \
    $$PWD/QtnRibbonMainWindow.h \
    $$PWD/QtnRibbonButtonPrivate.h \
    $$PWD/QtnRibbonControls.h \
    $$PWD/QtnRibbonControlsPrivate.h \
    $$PWD/QtnRibbonButtonControls.h \
    $$PWD/QtnRibbonInputControls.h \
    $$PWD/QtnRibbonGalleryControls.h \
    $$PWD/QtnRibbonKeyTipPrivate.h \
    $$PWD/QtnRibbonQuickAccessBar.h \
    $$PWD/QtnOfficePopupColorButton.h \
    $$PWD/QtnRibbonGallery.h \
    $$PWD/QtnOfficePopupMenu.h \
    $$PWD/QtnRibbonBackstageView.h \
    $$PWD/QtnOfficePopupWindow.h \
    $$PWD/QtnRibbonWorkspace.h \
    $$PWD/QtnRibbonCustomizeDialog.h \
    $$PWD/QtnRibbonCustomizeDialogPrivate.h \
    $$PWD/QtnRibbonCustomizePage.h \
    $$PWD/QtnRibbonCustomizeManager.h \
    $$PWD/QtnRibbonCustomizeManagerPrivate.h \

WINDOWS_HEADERS =
LINUX_HEADERS =
MACOSX_HEADERS =

WINDOWS_SOURCES =
LINUX_SOURCES =
MACOSX_SOURCES =


HEADERS += \
    $$PUBLIC_HEADERS \
    $$PRIVATE_HEADERS

SOURCES += \
    $$ALL_SOURCES

win32 {
  HEADERS += $$WINDOWS_HEADERS
  SOURCES += $$WINDOWS_SOURCES
}

linux* {
  HEADERS += $$LINUX_HEADERS
  SOURCES += $$LINUX_SOURCES
}

macx {
  HEADERS += $$MACOSX_HEADERS
  OBJECTIVE_SOURCES += $$MACOSX_SOURCES
}

FORMS += \
    $$PWD/QtnRibbonRenameDialog.ui \
    $$PWD/QtnRibbonQuickAccessBarCustomizePage.ui \
    $$PWD/QtnRibbonBarCustomizePage.ui

RESOURCES += \
    $$PWD/QtnRibbonResources.qrc \
    $$PWD/QtnRibbonTranslations.qrc
   

QT += xml

win32 {
    LIBS += -luser32 -lgdi32 -lshell32
}

macx {
    LIBS += -framework AppKit
}
DEFINES += QT_NO_DEPRECATED_WARNINGS

