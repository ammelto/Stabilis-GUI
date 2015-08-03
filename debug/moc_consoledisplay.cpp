/****************************************************************************
** Meta object code from reading C++ file 'consoledisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Displays/headers/consoledisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consoledisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_consoledisplay_t {
    QByteArrayData data[19];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_consoledisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_consoledisplay_t qt_meta_stringdata_consoledisplay = {
    {
QT_MOC_LITERAL(0, 0, 14), // "consoledisplay"
QT_MOC_LITERAL(1, 15, 16), // "connectionWorked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "connectConsole"
QT_MOC_LITERAL(4, 48, 4), // "host"
QT_MOC_LITERAL(5, 53, 4), // "port"
QT_MOC_LITERAL(6, 58, 8), // "username"
QT_MOC_LITERAL(7, 67, 8), // "password"
QT_MOC_LITERAL(8, 76, 12), // "writeCommand"
QT_MOC_LITERAL(9, 89, 7), // "command"
QT_MOC_LITERAL(10, 97, 11), // "readMessage"
QT_MOC_LITERAL(11, 109, 16), // "sendFileCallback"
QT_MOC_LITERAL(12, 126, 6), // "status"
QT_MOC_LITERAL(13, 133, 23), // "remote_connection_data*"
QT_MOC_LITERAL(14, 157, 4), // "data"
QT_MOC_LITERAL(15, 162, 19), // "receiveFileCallback"
QT_MOC_LITERAL(16, 182, 15), // "connectCallback"
QT_MOC_LITERAL(17, 198, 20), // "writeCommandCallback"
QT_MOC_LITERAL(18, 219, 19) // "readMessageCallback"

    },
    "consoledisplay\0connectionWorked\0\0"
    "connectConsole\0host\0port\0username\0"
    "password\0writeCommand\0command\0readMessage\0"
    "sendFileCallback\0status\0remote_connection_data*\0"
    "data\0receiveFileCallback\0connectCallback\0"
    "writeCommandCallback\0readMessageCallback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_consoledisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    4,   62,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    2,   75,    2, 0x0a /* Public */,
      15,    2,   80,    2, 0x0a /* Public */,
      16,    2,   85,    2, 0x0a /* Public */,
      17,    2,   90,    2, 0x0a /* Public */,
      18,    2,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
    QMetaType::Int, QMetaType::QString,    9,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,

       0        // eod
};

void consoledisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        consoledisplay *_t = static_cast<consoledisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionWorked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = _t->connectConsole((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->writeCommand((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->readMessage();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->sendFileCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 5: _t->receiveFileCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 6: _t->connectCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 7: _t->writeCommandCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 8: _t->readMessageCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (consoledisplay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&consoledisplay::connectionWorked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject consoledisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_consoledisplay.data,
      qt_meta_data_consoledisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *consoledisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *consoledisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_consoledisplay.stringdata0))
        return static_cast<void*>(const_cast< consoledisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int consoledisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void consoledisplay::connectionWorked(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
