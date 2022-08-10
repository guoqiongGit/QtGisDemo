/****************************************************************************
** Meta object code from reading C++ file 'QtGis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtGis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtGis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtGis_t {
    QByteArrayData data[18];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtGis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtGis_t qt_meta_stringdata_QtGis = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QtGis"
QT_MOC_LITERAL(1, 6, 15), // "slot_fileSaveAs"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "slot_fileNew"
QT_MOC_LITERAL(4, 36, 13), // "slot_fileOpen"
QT_MOC_LITERAL(5, 50, 13), // "slot_fileSave"
QT_MOC_LITERAL(6, 64, 14), // "slot_fileClose"
QT_MOC_LITERAL(7, 79, 13), // "slot_fileExit"
QT_MOC_LITERAL(8, 93, 14), // "openRecentFile"
QT_MOC_LITERAL(9, 108, 4), // "file"
QT_MOC_LITERAL(10, 113, 23), // "updateRecentFileActions"
QT_MOC_LITERAL(11, 137, 18), // "slot_addRaterLayer"
QT_MOC_LITERAL(12, 156, 19), // "slot_addVectorLayer"
QT_MOC_LITERAL(13, 176, 17), // "projectCrsChanged"
QT_MOC_LITERAL(14, 194, 20), // "canvasRefreshStarted"
QT_MOC_LITERAL(15, 215, 21), // "canvasRefreshFinished"
QT_MOC_LITERAL(16, 237, 12), // "userRotation"
QT_MOC_LITERAL(17, 250, 12) // "showRotation"

    },
    "QtGis\0slot_fileSaveAs\0\0slot_fileNew\0"
    "slot_fileOpen\0slot_fileSave\0slot_fileClose\0"
    "slot_fileExit\0openRecentFile\0file\0"
    "updateRecentFileActions\0slot_addRaterLayer\0"
    "slot_addVectorLayer\0projectCrsChanged\0"
    "canvasRefreshStarted\0canvasRefreshFinished\0"
    "userRotation\0showRotation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtGis[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtGis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtGis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_fileSaveAs(); break;
        case 1: _t->slot_fileNew(); break;
        case 2: _t->slot_fileOpen(); break;
        case 3: _t->slot_fileSave(); break;
        case 4: _t->slot_fileClose(); break;
        case 5: _t->slot_fileExit(); break;
        case 6: _t->openRecentFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->updateRecentFileActions((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 8: _t->slot_addRaterLayer(); break;
        case 9: _t->slot_addVectorLayer(); break;
        case 10: _t->projectCrsChanged(); break;
        case 11: _t->canvasRefreshStarted(); break;
        case 12: _t->canvasRefreshFinished(); break;
        case 13: _t->userRotation(); break;
        case 14: _t->showRotation(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtGis::staticMetaObject = { {
    QMetaObject::SuperData::link<DemoRibbonWindow::staticMetaObject>(),
    qt_meta_stringdata_QtGis.data,
    qt_meta_data_QtGis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtGis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtGis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtGis.stringdata0))
        return static_cast<void*>(this);
    return DemoRibbonWindow::qt_metacast(_clname);
}

int QtGis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DemoRibbonWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
