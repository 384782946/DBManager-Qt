/****************************************************************************
** Meta object code from reading C++ file 'TestDBManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestDBManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestDBManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestDBManager_t {
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestDBManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestDBManager_t qt_meta_stringdata_TestDBManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TestDBManager"
QT_MOC_LITERAL(1, 14, 11), // "test_create"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "test_add"
QT_MOC_LITERAL(4, 36, 11), // "test_update"
QT_MOC_LITERAL(5, 48, 10), // "test_query"
QT_MOC_LITERAL(6, 59, 11), // "test_remove"
QT_MOC_LITERAL(7, 71, 12), // "initTestCase"
QT_MOC_LITERAL(8, 84, 15), // "cleanupTestCase"
QT_MOC_LITERAL(9, 100, 4), // "init"
QT_MOC_LITERAL(10, 105, 7) // "cleanup"

    },
    "TestDBManager\0test_create\0\0test_add\0"
    "test_update\0test_query\0test_remove\0"
    "initTestCase\0cleanupTestCase\0init\0"
    "cleanup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestDBManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
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

void TestDBManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestDBManager *_t = static_cast<TestDBManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->test_create(); break;
        case 1: _t->test_add(); break;
        case 2: _t->test_update(); break;
        case 3: _t->test_query(); break;
        case 4: _t->test_remove(); break;
        case 5: _t->initTestCase(); break;
        case 6: _t->cleanupTestCase(); break;
        case 7: _t->init(); break;
        case 8: _t->cleanup(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestDBManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestDBManager.data,
      qt_meta_data_TestDBManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestDBManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestDBManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestDBManager.stringdata0))
        return static_cast<void*>(const_cast< TestDBManager*>(this));
    return QObject::qt_metacast(_clname);
}

int TestDBManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
