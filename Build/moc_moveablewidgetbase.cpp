/****************************************************************************
** Meta object code from reading C++ file 'moveablewidgetbase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Chart/moveablewidgetbase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moveablewidgetbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DMoveableWidgetBase_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DMoveableWidgetBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DMoveableWidgetBase_t qt_meta_stringdata_Dynamometer__DMoveableWidgetBase = {
    {
QT_MOC_LITERAL(0, 0, 32), // "Dynamometer::DMoveableWidgetBase"
QT_MOC_LITERAL(1, 33, 7), // "inFocus"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 4), // "mode"
QT_MOC_LITERAL(4, 47, 8), // "outFocus"
QT_MOC_LITERAL(5, 56, 11), // "newGeometry"
QT_MOC_LITERAL(6, 68, 4), // "rect"
QT_MOC_LITERAL(7, 73, 7), // "refresh"
QT_MOC_LITERAL(8, 81, 4) // "type"

    },
    "Dynamometer::DMoveableWidgetBase\0"
    "inFocus\0\0mode\0outFocus\0newGeometry\0"
    "rect\0refresh\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DMoveableWidgetBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QRect,    6,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QByteArray, 0x00195001,

       0        // eod
};

void Dynamometer::DMoveableWidgetBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DMoveableWidgetBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->outFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->newGeometry((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        case 3: _t->refresh(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DMoveableWidgetBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMoveableWidgetBase::inFocus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DMoveableWidgetBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMoveableWidgetBase::outFocus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DMoveableWidgetBase::*)(QRect );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMoveableWidgetBase::newGeometry)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DMoveableWidgetBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->type(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DMoveableWidgetBase::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DMoveableWidgetBase.data,
    qt_meta_data_Dynamometer__DMoveableWidgetBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DMoveableWidgetBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DMoveableWidgetBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DMoveableWidgetBase.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Dynamometer::DMoveableWidgetBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Dynamometer::DMoveableWidgetBase::inFocus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dynamometer::DMoveableWidgetBase::outFocus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dynamometer::DMoveableWidgetBase::newGeometry(QRect _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
