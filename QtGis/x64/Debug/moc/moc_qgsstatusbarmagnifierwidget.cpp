/****************************************************************************
** Meta object code from reading C++ file 'qgsstatusbarmagnifierwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QGISFiles/qgsstatusbarmagnifierwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgsstatusbarmagnifierwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QgsStatusBarMagnifierWidget_t {
    QByteArrayData data[8];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QgsStatusBarMagnifierWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QgsStatusBarMagnifierWidget_t qt_meta_stringdata_QgsStatusBarMagnifierWidget = {
    {
QT_MOC_LITERAL(0, 0, 27), // "QgsStatusBarMagnifierWidget"
QT_MOC_LITERAL(1, 28, 20), // "magnificationChanged"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 6), // "factor"
QT_MOC_LITERAL(4, 57, 16), // "scaleLockChanged"
QT_MOC_LITERAL(5, 74, 19), // "updateMagnification"
QT_MOC_LITERAL(6, 94, 16), // "setMagnification"
QT_MOC_LITERAL(7, 111, 5) // "value"

    },
    "QgsStatusBarMagnifierWidget\0"
    "magnificationChanged\0\0factor\0"
    "scaleLockChanged\0updateMagnification\0"
    "setMagnification\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QgsStatusBarMagnifierWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    7,

       0        // eod
};

void QgsStatusBarMagnifierWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QgsStatusBarMagnifierWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->magnificationChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->scaleLockChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateMagnification((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setMagnification((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QgsStatusBarMagnifierWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QgsStatusBarMagnifierWidget::magnificationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QgsStatusBarMagnifierWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QgsStatusBarMagnifierWidget::scaleLockChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QgsStatusBarMagnifierWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QgsStatusBarMagnifierWidget.data,
    qt_meta_data_QgsStatusBarMagnifierWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QgsStatusBarMagnifierWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QgsStatusBarMagnifierWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QgsStatusBarMagnifierWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QgsStatusBarMagnifierWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QgsStatusBarMagnifierWidget::magnificationChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QgsStatusBarMagnifierWidget::scaleLockChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
