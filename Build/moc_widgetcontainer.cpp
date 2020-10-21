/****************************************************************************
** Meta object code from reading C++ file 'widgetcontainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgetcontainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetcontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DWidgetContainer_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DWidgetContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DWidgetContainer_t qt_meta_stringdata_Dynamometer__DWidgetContainer = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Dynamometer::DWidgetContainer"
QT_MOC_LITERAL(1, 30, 7), // "inFocus"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "mode"
QT_MOC_LITERAL(4, 44, 8), // "outFocus"
QT_MOC_LITERAL(5, 53, 11), // "newGeometry"
QT_MOC_LITERAL(6, 65, 4) // "rect"

    },
    "Dynamometer::DWidgetContainer\0inFocus\0"
    "\0mode\0outFocus\0newGeometry\0rect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DWidgetContainer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       5,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QRect,    6,

       0        // eod
};

void Dynamometer::DWidgetContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DWidgetContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->outFocus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->newGeometry((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DWidgetContainer::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DWidgetContainer::inFocus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DWidgetContainer::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DWidgetContainer::outFocus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DWidgetContainer::*)(QRect );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DWidgetContainer::newGeometry)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DWidgetContainer::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DWidgetContainer.data,
    qt_meta_data_Dynamometer__DWidgetContainer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DWidgetContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DWidgetContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DWidgetContainer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Dynamometer::DWidgetContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Dynamometer::DWidgetContainer::inFocus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dynamometer::DWidgetContainer::outFocus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dynamometer::DWidgetContainer::newGeometry(QRect _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
