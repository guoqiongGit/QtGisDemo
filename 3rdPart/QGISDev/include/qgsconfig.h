
// QGSCONFIG.H

#ifndef QGSCONFIG_H
#define QGSCONFIG_H

// Version must be specified according to
// <int>.<int>.<int>-<any text>.
// or else upgrading old project file will not work
// reliably.
// TODO QGIS 4: remove in favor of _QGIS_VERSION
#define VERSION "3.22.3-Białowieża"
#define _QGIS_VERSION "3.22.3-Białowieża"

//used in vim src/core/qgis.cpp
//The way below should work but it resolves to a number like 0110 which the compiler treats as octal I think
//because debuggin it out shows the decimal number 72 which results in incorrect version status.
//As a short term fix I (Tim) am defining the version in top level cmake. It would be good to
//reinstate this more generic approach below at some point though
//#define VERSION_INT 3223
// TODO QGIS 4: Remove in favor of _QGIS_VERSION_INT
#define VERSION_INT 32203
#define _QGIS_VERSION_INT 32203
#define ABISYM(x) x ## 32203
//used in main.cpp and anywhere else where the release name is needed
#define RELEASE_NAME "Białowieża"

#define QGIS_PLUGIN_SUBDIR "plugins"
#define QGIS_DATA_SUBDIR "."
#define QGIS_LIBEXEC_SUBDIR "."
#define QGIS_LIB_SUBDIR "lib"
#define QGIS_QML_SUBDIR "qml"
#define CMAKE_INSTALL_PREFIX "C:/src/OSGeo4W/src/qgis/osgeo4w/install/apps/qgis"
#define CMAKE_SOURCE_DIR "C:/src/OSGeo4W/src/qgis/qgis"

#define QGIS_SERVER_MODULE_SUBDIR "server"

#if !defined(QSCINTILLA_VERSION_STR)
#define QSCINTILLA_VERSION_STR "2.11.5"
#endif

#if defined( __APPLE__ )
//used by Mac to find system or bundle resources relative to amount of bundling
#define QGIS_MACAPP_BUNDLE 
#endif

#define QT_PLUGINS_DIR "C:/src/OSGeo4W/src/qgis/osgeo4w/osgeo4w/apps/Qt5/plugins"

#define PYTHON_VERSION "3.9.5"
#define PYTHON_VERSION_MAJOR "3"
#define PYTHON_VERSION_MINOR "9"
#define PYTHON_VERSION_PATCH "5"

#define PROJ_VERSION_MAJOR 8
#define PROJ_VERSION_MINOR 2
#define PROJ_VERSION_PATCH 1

/* #undef USING_NMAKE */

#define USING_NINJA

#define HAVE_GUI

#define HAVE_SPATIALITE

#define HAVE_POSTGRESQL

#define HAVE_ORACLE

#define HAVE_HANA

#define SERVER_SKIP_ECW

#define HAVE_SERVER_PYTHON_PLUGINS

#define HAVE_OAUTH2_PLUGIN

#define HAVE_OPENCL
/* #undef OPENCL_USE_NEW_HEADER */

/* #undef ENABLE_MODELTEST */

#define HAVE_3D

#define HAVE_GSL

#define HAVE_GEOREFERENCER

#define USE_THREAD_LOCAL

/* #undef QGISDEBUG */

/* #undef HAVE_QUICK */

#define HAVE_QT5SERIALPORT

/* #undef HAVE_STATIC_PROVIDERS */

#define HAVE_EPT

#define HAVE_PDAL
#define PDAL_VERSION "2.3.0"
#define PDAL_VERSION_MAJOR_INT 2
#define PDAL_VERSION_MINOR_INT 3
#define PDAL_VERSION_MAJOR "2"
#define PDAL_VERSION_MINOR "3"
#define PDAL_VERSION_MICRO "0"

/* #undef ENABLE_TESTS */

#endif

