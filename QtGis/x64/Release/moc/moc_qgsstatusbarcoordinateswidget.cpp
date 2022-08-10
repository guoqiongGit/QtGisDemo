/****************************************************************************
** Meta object code from reading C++ file 'qgsstatusbarcoordinateswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QGISFiles/qgsstatusbarcoordinateswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgsstatusbarcoordinateswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QgsStatusBarCoordinatesWidget_t {
    QByteArrayData data[17];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QgsStatusBarCoordinatesWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QgsStatusBarCoordinatesWidget_t qt_meta_stringdata_QgsStatusBarCoordinatesWidget = {
    {
QT_MOC_LITERAL(0, 0, 29), // "QgsStatusBarCoordinatesWidget"
QT_MOC_LITERAL(1, 30, 18), // "coordinatesChanged"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 10), // "weAreBored"
QT_MOC_LITERAL(4, 61, 20), // "showMouseCoordinates"
QT_MOC_LITERAL(5, 82, 10), // "QgsPointXY"
QT_MOC_LITERAL(6, 93, 1), // "p"
QT_MOC_LITERAL(7, 95, 18), // "extentsViewToggled"
QT_MOC_LITERAL(8, 114, 4), // "flag"
QT_MOC_LITERAL(9, 119, 19), // "validateCoordinates"
QT_MOC_LITERAL(10, 139, 5), // "dizzy"
QT_MOC_LITERAL(11, 145, 5), // "world"
QT_MOC_LITERAL(12, 151, 12), // "contributors"
QT_MOC_LITERAL(13, 164, 9), // "hackfests"
QT_MOC_LITERAL(14, 174, 10), // "userGroups"
QT_MOC_LITERAL(15, 185, 10), // "showExtent"
QT_MOC_LITERAL(16, 196, 24) // "ensureCoordinatesVisible"

    },
    "QgsStatusBarCoordinatesWidget\0"
    "coordinatesChanged\0\0weAreBored\0"
    "showMouseCoordinates\0QgsPointXY\0p\0"
    "extentsViewToggled\0flag\0validateCoordinates\0"
    "dizzy\0world\0contributors\0hackfests\0"
    "userGroups\0showExtent\0ensureCoordinatesVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QgsStatusBarCoordinatesWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   76,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    0,   88,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QgsStatusBarCoordinatesWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QgsStatusBarCoordinatesWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coordinatesChanged(); break;
        case 1: _t->weAreBored(); break;
        case 2: _t->showMouseCoordinates((*reinterpret_cast< const QgsPointXY(*)>(_a[1]))); break;
        case 3: _t->extentsViewToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->validateCoordinates(); break;
        case 5: _t->dizzy(); break;
        case 6: _t->world(); break;
        case 7: _t->contributors(); break;
        case 8: _t->hackfests(); break;
        case 9: _t->userGroups(); break;
        case 10: _t->showExtent(); break;
        case 11: _t->ensureCoordinatesVisible(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QgsStatusBarCoordinatesWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QgsStatusBarCoordinatesWidget::coordinatesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QgsStatusBarCoordinatesWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QgsStatusBarCoordinatesWidget::weAreBored)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QgsStatusBarCoordinatesWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QgsStatusBarCoordinatesWidget.data,
    qt_meta_data_QgsStatusBarCoordinatesWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QgsStatusBarCoordinatesWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QgsStatusBarCoordinatesWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QgsStatusBarCoordinatesWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QgsStatusBarCoordinatesWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QgsStatusBarCoordinatesWidget::coordinatesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QgsStatusBarCoordinatesWidget::weAreBored()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
