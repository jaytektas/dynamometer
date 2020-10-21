/****************************************************************************
** Meta object code from reading C++ file 'channellist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Channels/channellist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'channellist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DChannelList_t {
    QByteArrayData data[12];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DChannelList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DChannelList_t qt_meta_stringdata_Dynamometer__DChannelList = {
    {
QT_MOC_LITERAL(0, 0, 25), // "Dynamometer::DChannelList"
QT_MOC_LITERAL(1, 26, 5), // "error"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "description"
QT_MOC_LITERAL(4, 45, 15), // "channelsChanged"
QT_MOC_LITERAL(5, 61, 12), // "statusUpdate"
QT_MOC_LITERAL(6, 74, 12), // "statusPacket"
QT_MOC_LITERAL(7, 87, 19), // "setEvaluationPacket"
QT_MOC_LITERAL(8, 107, 16), // "evaluationPacket"
QT_MOC_LITERAL(9, 124, 4), // "save"
QT_MOC_LITERAL(10, 129, 8), // "fileName"
QT_MOC_LITERAL(11, 138, 4) // "load"

    },
    "Dynamometer::DChannelList\0error\0\0"
    "description\0channelsChanged\0statusUpdate\0"
    "statusPacket\0setEvaluationPacket\0"
    "evaluationPacket\0save\0fileName\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DChannelList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
       9,    1,   54,    2, 0x0a /* Public */,
      11,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Bool, QMetaType::QString,   10,

       0        // eod
};

void Dynamometer::DChannelList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DChannelList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->channelsChanged(); break;
        case 2: _t->statusUpdate((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->setEvaluationPacket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: { bool _r = _t->save((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->load((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DChannelList::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DChannelList::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DChannelList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DChannelList::channelsChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DChannelList::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DChannelList.data,
    qt_meta_data_Dynamometer__DChannelList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DChannelList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DChannelList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DChannelList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Dynamometer::DChannelList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Dynamometer::DChannelList::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dynamometer::DChannelList::channelsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
