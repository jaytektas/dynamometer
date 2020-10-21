/****************************************************************************
** Meta object code from reading C++ file 'labelgauge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dash/labelgauge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labelgauge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DLabelGauge_t {
    QByteArrayData data[13];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DLabelGauge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DLabelGauge_t qt_meta_stringdata_Dynamometer__DLabelGauge = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Dynamometer::DLabelGauge"
QT_MOC_LITERAL(1, 25, 15), // "showContextMenu"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "point"
QT_MOC_LITERAL(4, 48, 14), // "labelConfigure"
QT_MOC_LITERAL(5, 63, 26), // "contextMenuChannelSelected"
QT_MOC_LITERAL(6, 90, 8), // "QAction*"
QT_MOC_LITERAL(7, 99, 6), // "action"
QT_MOC_LITERAL(8, 106, 12), // "bringToFront"
QT_MOC_LITERAL(9, 119, 10), // "sendToBack"
QT_MOC_LITERAL(10, 130, 5), // "label"
QT_MOC_LITERAL(11, 136, 9), // "labelFont"
QT_MOC_LITERAL(12, 146, 6) // "format"

    },
    "Dynamometer::DLabelGauge\0showContextMenu\0"
    "\0point\0labelConfigure\0contextMenuChannelSelected\0"
    "QAction*\0action\0bringToFront\0sendToBack\0"
    "label\0labelFont\0format"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DLabelGauge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00195103,
      11, QMetaType::QFont, 0x00195103,
      12, QMetaType::QByteArray, 0x00195103,

       0        // eod
};

void Dynamometer::DLabelGauge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DLabelGauge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->labelConfigure(); break;
        case 2: _t->contextMenuChannelSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->bringToFront(); break;
        case 4: _t->sendToBack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DLabelGauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getLabel(); break;
        case 1: *reinterpret_cast< QFont*>(_v) = _t->getLabelFont(); break;
        case 2: *reinterpret_cast< QByteArray*>(_v) = _t->getFormat(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DLabelGauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLabel(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLabelFont(*reinterpret_cast< QFont*>(_v)); break;
        case 2: _t->setFormat(*reinterpret_cast< QByteArray*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DLabelGauge::staticMetaObject = { {
    &DGauge::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DLabelGauge.data,
    qt_meta_data_Dynamometer__DLabelGauge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DLabelGauge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DLabelGauge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DLabelGauge.stringdata0))
        return static_cast<void*>(this);
    return DGauge::qt_metacast(_clname);
}

int Dynamometer::DLabelGauge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DGauge::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
