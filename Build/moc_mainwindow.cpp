/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[544];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "selectedRunsChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "connected"
QT_MOC_LITERAL(4, 42, 15), // "channelsChanged"
QT_MOC_LITERAL(5, 58, 20), // "configurationChanged"
QT_MOC_LITERAL(6, 79, 9), // "deleteRun"
QT_MOC_LITERAL(7, 89, 23), // "runCheckBoxStateChanged"
QT_MOC_LITERAL(8, 113, 5), // "state"
QT_MOC_LITERAL(9, 119, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(10, 146, 37), // "on_actionConnectionSettings_t..."
QT_MOC_LITERAL(11, 184, 31), // "on_actionNewChartView_triggered"
QT_MOC_LITERAL(12, 216, 17), // "tabCloseRequested"
QT_MOC_LITERAL(13, 234, 8), // "tabIndex"
QT_MOC_LITERAL(14, 243, 6), // "undock"
QT_MOC_LITERAL(15, 250, 4), // "dock"
QT_MOC_LITERAL(16, 255, 26), // "on_actionNewDash_triggered"
QT_MOC_LITERAL(17, 282, 32), // "on_channelListWidget_itemClicked"
QT_MOC_LITERAL(18, 315, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(19, 332, 4), // "item"
QT_MOC_LITERAL(20, 337, 38), // "on_channelListWidget_itemDoub..."
QT_MOC_LITERAL(21, 376, 34), // "on_channelDeletePushButton_cl..."
QT_MOC_LITERAL(22, 411, 31), // "on_channelAddPushButton_clicked"
QT_MOC_LITERAL(23, 443, 25), // "on_fileTree_doubleClicked"
QT_MOC_LITERAL(24, 469, 11), // "QModelIndex"
QT_MOC_LITERAL(25, 481, 5), // "index"
QT_MOC_LITERAL(26, 487, 32), // "on_actionConfiguration_triggered"
QT_MOC_LITERAL(27, 520, 23) // "on_actionOpen_triggered"

    },
    "MainWindow\0selectedRunsChanged\0\0"
    "connected\0channelsChanged\0"
    "configurationChanged\0deleteRun\0"
    "runCheckBoxStateChanged\0state\0"
    "on_actionConnect_triggered\0"
    "on_actionConnectionSettings_triggered\0"
    "on_actionNewChartView_triggered\0"
    "tabCloseRequested\0tabIndex\0undock\0"
    "dock\0on_actionNewDash_triggered\0"
    "on_channelListWidget_itemClicked\0"
    "QListWidgetItem*\0item\0"
    "on_channelListWidget_itemDoubleClicked\0"
    "on_channelDeletePushButton_clicked\0"
    "on_channelAddPushButton_clicked\0"
    "on_fileTree_doubleClicked\0QModelIndex\0"
    "index\0on_actionConfiguration_triggered\0"
    "on_actionOpen_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  115,    2, 0x0a /* Public */,
       4,    0,  118,    2, 0x0a /* Public */,
       5,    0,  119,    2, 0x0a /* Public */,
       6,    0,  120,    2, 0x08 /* Private */,
       7,    1,  121,    2, 0x08 /* Private */,
       9,    0,  124,    2, 0x08 /* Private */,
      10,    0,  125,    2, 0x08 /* Private */,
      11,    0,  126,    2, 0x08 /* Private */,
      12,    1,  127,    2, 0x08 /* Private */,
      14,    0,  130,    2, 0x08 /* Private */,
      15,    0,  131,    2, 0x08 /* Private */,
      16,    0,  132,    2, 0x08 /* Private */,
      17,    1,  133,    2, 0x08 /* Private */,
      20,    1,  136,    2, 0x08 /* Private */,
      21,    0,  139,    2, 0x08 /* Private */,
      22,    0,  140,    2, 0x08 /* Private */,
      23,    1,  141,    2, 0x08 /* Private */,
      26,    0,  144,    2, 0x08 /* Private */,
      27,    0,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectedRunsChanged(); break;
        case 1: _t->connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->channelsChanged(); break;
        case 3: _t->configurationChanged(); break;
        case 4: _t->deleteRun(); break;
        case 5: _t->runCheckBoxStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_actionConnect_triggered(); break;
        case 7: _t->on_actionConnectionSettings_triggered(); break;
        case 8: _t->on_actionNewChartView_triggered(); break;
        case 9: _t->tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->undock(); break;
        case 11: _t->dock(); break;
        case 12: _t->on_actionNewDash_triggered(); break;
        case 13: _t->on_channelListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->on_channelListWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: _t->on_channelDeletePushButton_clicked(); break;
        case 16: _t->on_channelAddPushButton_clicked(); break;
        case 17: _t->on_fileTree_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 18: _t->on_actionConfiguration_triggered(); break;
        case 19: _t->on_actionOpen_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::selectedRunsChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::selectedRunsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
