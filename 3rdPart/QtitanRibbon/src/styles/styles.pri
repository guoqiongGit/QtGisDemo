ALL_SOURCES = \
    $$PWD/QtnOfficeStyle.cpp \
    $$PWD/QtnPopupHelpers.cpp \
    $$PWD/QtnOffice2007Style.cpp \
    $$PWD/QtnOffice2010Style.cpp \
    $$PWD/QtnOffice2013Style.cpp \
    $$PWD/QtnOffice2016Style.cpp \
    $$PWD/QtnWindows7ScenicStyle.cpp \
    $$PWD/QtnAdobePhotoshopStyle.cpp \

INCLUDE_HEADERS = \
    $$PWD/../../include/QtnOfficeStyle.h \
    $$PWD/../../include/QtnOffice2007Style.h \
    $$PWD/../../include/QtnOffice2010Style.h \
    $$PWD/../../include/QtnOffice2013Style.h \
    $$PWD/../../include/QtnOffice2016Style.h \
    $$PWD/../../include/QtnWindows7ScenicStyle.h \
    $$PWD/../../include/QtnAdobePhotoshopStyle.h \

PRIVATE_HEADERS = \
    $$PWD/QtnOffice2007StylePrivate.h \
    $$PWD/QtnOffice2010StylePrivate.h \
    $$PWD/QtnOffice2013StylePrivate.h \
    $$PWD/QtnWindows7ScenicStylePrivate.h \
    $$PWD/QtnOfficeStylePrivate.h \

PUBLIC_HEADERS = \
    $$PWD/QtnPopupHelpers.h \
    $$PWD/QtnOfficeStyle.h \
    $$PWD/QtnOffice2007Style.h \
    $$PWD/QtnOffice2010Style.h \
    $$PWD/QtnOffice2013Style.h \
    $$PWD/QtnOffice2016Style.h \
    $$PWD/QtnWindows7ScenicStyle.h \
    $$PWD/QtnAdobePhotoshopStyle.h \

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

RESOURCES += \
    $$PWD/QtnOffice2007Style.qrc \
    $$PWD/QtnOffice2010Style.qrc \
    $$PWD/QtnOffice2013Style.qrc \
    $$PWD/QtnOffice2016Style.qrc \
    $$PWD/QtnWindows7ScenicStyle.qrc \
    $$PWD/QtnAdobePhotoshopStyle.qrc \

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
