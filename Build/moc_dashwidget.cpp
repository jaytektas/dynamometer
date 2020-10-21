/****************************************************************************
** Meta object code from reading C++ file 'dashwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dash/dashwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DDashWidget_t {
    QByteArrayData data[17];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DDashWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DDashWidget_t qt_meta_stringdata_Dynamometer__DDashWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Dynamometer::DDashWidget"
QT_MOC_LITERAL(1, 25, 6), // "undock"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "dock"
QT_MOC_LITERAL(4, 38, 15), // "showContextMenu"
QT_MOC_LITERAL(5, 54, 5), // "point"
QT_MOC_LITERAL(6, 60, 26), // "contextMenuChannelSelected"
QT_MOC_LITERAL(7, 87, 8), // "QAction*"
QT_MOC_LITERAL(8, 96, 6), // "action"
QT_MOC_LITERAL(9, 103, 16), // "changeBackground"
QT_MOC_LITERAL(10, 120, 13), // "undockFromTab"
QT_MOC_LITERAL(11, 134, 9), // "dockToTab"
QT_MOC_LITERAL(12, 144, 12), // "addDialGauge"
QT_MOC_LITERAL(13, 157, 14), // "addLinearGauge"
QT_MOC_LITERAL(14, 172, 12), // "addLCDNumber"
QT_MOC_LITERAL(15, 185, 8), // "addLabel"
QT_MOC_LITERAL(16, 194, 12) // "addHistogram"

    },
    "Dynamometer::DDashWidget\0undock\0\0dock\0"
    "showContextMenu\0point\0contextMenuChannelSelected\0"
    "QAction*\0action\0changeBackground\0"
    "undockFromTab\0dockToTab\0addDialGauge\0"
    "addLinearGauge\0addLCDNumber\0addLabel\0"
    "addHistogram"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DDashWidget[] = {

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
       6,    1,   79,    2, 0x08 /* Private */,
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
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
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

void Dynamometer::DDashWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DDashWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undock(); break;
        case 1: _t->dock(); break;
        case 2: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->contextMenuChannelSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->changeBackground(); break;
        case 5: _t->undockFromTab(); break;
        case 6: _t->dockToTab(); break;
        case 7: _t->addDialGauge(); break;
        case 8: _t->addLinearGauge(); break;
        case 9: _t->addLCDNumber(); break;
        case 10: _t->addLabel(); break;
        case 11: _t->addHistogram(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DDashWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DDashWidget::undock)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DDashWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DDashWidget::dock)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DDashWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DDashWidget.data,
    qt_meta_data_Dynamometer__DDashWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DDashWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DDashWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DDashWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Dynamometer::DDashWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Dynamometer::DDashWidget::undock()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Dynamometer::DDashWidget::dock()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
