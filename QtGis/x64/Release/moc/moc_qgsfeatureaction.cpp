/****************************************************************************
** Meta object code from reading C++ file 'qgsfeatureaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QGISFiles/qgsfeatureaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgsfeatureaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QgsFeatureAction_t {
    QByteArrayData data[15];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QgsFeatureAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QgsFeatureAction_t qt_meta_stringdata_QgsFeatureAction = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QgsFeatureAction"
QT_MOC_LITERAL(1, 17, 18), // "addFeatureFinished"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "execute"
QT_MOC_LITERAL(4, 45, 10), // "addFeature"
QT_MOC_LITERAL(5, 56, 15), // "QgsAttributeMap"
QT_MOC_LITERAL(6, 72, 17), // "defaultAttributes"
QT_MOC_LITERAL(7, 90, 9), // "showModal"
QT_MOC_LITERAL(8, 100, 26), // "QgsExpressionContextScope*"
QT_MOC_LITERAL(9, 127, 5), // "scope"
QT_MOC_LITERAL(10, 133, 25), // "setForceSuppressFormPopup"
QT_MOC_LITERAL(11, 159, 5), // "force"
QT_MOC_LITERAL(12, 165, 7), // "feature"
QT_MOC_LITERAL(13, 173, 10), // "QgsFeature"
QT_MOC_LITERAL(14, 184, 14) // "onFeatureSaved"

    },
    "QgsFeatureAction\0addFeatureFinished\0"
    "\0execute\0addFeature\0QgsAttributeMap\0"
    "defaultAttributes\0showModal\0"
    "QgsExpressionContextScope*\0scope\0"
    "setForceSuppressFormPopup\0force\0feature\0"
    "QgsFeature\0onFeatureSaved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QgsFeatureAction[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    3,   61,    2, 0x0a /* Public */,
       4,    2,   68,    2, 0x2a /* Public | MethodCloned */,
       4,    1,   73,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   76,    2, 0x2a /* Public | MethodCloned */,
      10,    1,   77,    2, 0x0a /* Public */,
      12,    0,   80,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 5, QMetaType::Bool, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Bool, 0x80000000 | 5, QMetaType::Bool,    6,    7,
    QMetaType::Bool, 0x80000000 | 5,    6,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   11,
    0x80000000 | 13,
    QMetaType::Void, 0x80000000 | 13,   12,

       0        // eod
};

void QgsFeatureAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QgsFeatureAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addFeatureFinished(); break;
        case 1: _t->execute(); break;
        case 2: { bool _r = _t->addFeature((*reinterpret_cast< const QgsAttributeMap(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QgsExpressionContextScope*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->addFeature((*reinterpret_cast< const QgsAttributeMap(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->addFeature((*reinterpret_cast< const QgsAttributeMap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->addFeature();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setForceSuppressFormPopup((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: { QgsFeature _r = _t->feature();
            if (_a[0]) *reinterpret_cast< QgsFeature*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->onFeatureSaved((*reinterpret_cast< const QgsFeature(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsFeature >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QgsFeatureAction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QgsFeatureAction::addFeatureFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QgsFeatureAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QAction::staticMetaObject>(),
    qt_meta_stringdata_QgsFeatureAction.data,
    qt_meta_data_QgsFeatureAction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QgsFeatureAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QgsFeatureAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QgsFeatureAction.stringdata0))
        return static_cast<void*>(this);
    return QAction::qt_metacast(_clname);
}

int QgsFeatureAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QgsFeatureAction::addFeatureFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
