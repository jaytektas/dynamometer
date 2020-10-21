/****************************************************************************
** Meta object code from reading C++ file 'statuspacket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Communications/statuspacket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statuspacket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DStatusPacket_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DStatusPacket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DStatusPacket_t qt_meta_stringdata_Dynamometer__DStatusPacket = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Dynamometer::DStatusPacket"
QT_MOC_LITERAL(1, 27, 12), // "statusUpdate"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "s_status"
QT_MOC_LITERAL(4, 50, 20), // "setAutoUpdateEnabled"
QT_MOC_LITERAL(5, 71, 17), // "autoUpdateEnabled"
QT_MOC_LITERAL(6, 89, 19), // "setAutoUpdateRateMs"
QT_MOC_LITERAL(7, 109, 16), // "autoUpdateRateMs"
QT_MOC_LITERAL(8, 126, 9), // "connected"
QT_MOC_LITERAL(9, 136, 10) // "autoUpdate"

    },
    "Dynamometer::DStatusPacket\0statusUpdate\0"
    "\0s_status\0setAutoUpdateEnabled\0"
    "autoUpdateEnabled\0setAutoUpdateRateMs\0"
    "autoUpdateRateMs\0connected\0autoUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DStatusPacket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void Dynamometer::DStatusPacket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DStatusPacket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusUpdate((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->setAutoUpdateEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setAutoUpdateRateMs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->autoUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DStatusPacket::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DStatusPacket::statusUpdate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DStatusPacket::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DStatusPacket.data,
    qt_meta_data_Dynamometer__DStatusPacket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DStatusPacket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DStatusPacket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DStatusPacket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Dynamometer::DStatusPacket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Dynamometer::DStatusPacket::statusUpdate(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
