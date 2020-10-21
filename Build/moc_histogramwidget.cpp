/****************************************************************************
** Meta object code from reading C++ file 'histogramwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dash/histogramwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'histogramwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dynamometer__DHistogramWidget_t {
    QByteArrayData data[19];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dynamometer__DHistogramWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dynamometer__DHistogramWidget_t qt_meta_stringdata_Dynamometer__DHistogramWidget = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Dynamometer::DHistogramWidget"
QT_MOC_LITERAL(1, 30, 12), // "channelAdded"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "channelName"
QT_MOC_LITERAL(4, 56, 14), // "channelRemoved"
QT_MOC_LITERAL(5, 71, 15), // "showContextMenu"
QT_MOC_LITERAL(6, 87, 5), // "point"
QT_MOC_LITERAL(7, 93, 10), // "autoUpdate"
QT_MOC_LITERAL(8, 104, 12), // "bringToFront"
QT_MOC_LITERAL(9, 117, 10), // "sendToBack"
QT_MOC_LITERAL(10, 128, 13), // "deleteChannel"
QT_MOC_LITERAL(11, 142, 9), // "configure"
QT_MOC_LITERAL(12, 152, 5), // "reset"
QT_MOC_LITERAL(13, 158, 4), // "type"
QT_MOC_LITERAL(14, 163, 6), // "points"
QT_MOC_LITERAL(15, 170, 17), // "autoUpdateEnabled"
QT_MOC_LITERAL(16, 188, 16), // "autoUpdateRateMs"
QT_MOC_LITERAL(17, 205, 5), // "title"
QT_MOC_LITERAL(18, 211, 9) // "titleFont"

    },
    "Dynamometer::DHistogramWidget\0"
    "channelAdded\0\0channelName\0channelRemoved\0"
    "showContextMenu\0point\0autoUpdate\0"
    "bringToFront\0sendToBack\0deleteChannel\0"
    "configure\0reset\0type\0points\0"
    "autoUpdateEnabled\0autoUpdateRateMs\0"
    "title\0titleFont"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dynamometer__DHistogramWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       6,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   65,    2, 0x0a /* Public */,
       7,    0,   68,    2, 0x0a /* Public */,
       8,    0,   69,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QByteArray, 0x00195001,
      14, QMetaType::Int, 0x00195103,
      15, QMetaType::Bool, 0x00195003,
      16, QMetaType::Int, 0x00195103,
      17, QMetaType::QString, 0x00195103,
      18, QMetaType::QFont, 0x00195103,

       0        // eod
};

void Dynamometer::DHistogramWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DHistogramWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->channelAdded((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->channelRemoved((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->autoUpdate(); break;
        case 4: _t->bringToFront(); break;
        case 5: _t->sendToBack(); break;
        case 6: _t->deleteChannel(); break;
        case 7: _t->configure(); break;
        case 8: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DHistogramWidget::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DHistogramWidget::channelAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DHistogramWidget::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DHistogramWidget::channelRemoved)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DHistogramWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->type(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getPoints(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getAutoUpdateEnabled(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getAutoUpdateRateMs(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getTitle(); break;
        case 5: *reinterpret_cast< QFont*>(_v) = _t->getTitleFont(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DHistogramWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setPoints(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setAutoUpdateEnable(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setAutoUpdateRateMs(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setTitleFont(*reinterpret_cast< QFont*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Dynamometer::DHistogramWidget::staticMetaObject = { {
    &QChartView::staticMetaObject,
    qt_meta_stringdata_Dynamometer__DHistogramWidget.data,
    qt_meta_data_Dynamometer__DHistogramWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dynamometer::DHistogramWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dynamometer::DHistogramWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dynamometer__DHistogramWidget.stringdata0))
        return static_cast<void*>(this);
    return QChartView::qt_metacast(_clname);
}

int Dynamometer::DHistogramWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QChartView::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Dynamometer::DHistogramWidget::channelAdded(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dynamometer::DHistogramWidget::channelRemoved(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
