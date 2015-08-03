/****************************************************************************
** Meta object code from reading C++ file 'console.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../console.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'console.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_console_thread_t {
    QByteArrayData data[8];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_console_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_console_thread_t qt_meta_stringdata_console_thread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "console_thread"
QT_MOC_LITERAL(1, 15, 16), // "sendFileCallback"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 23), // "remote_connection_data*"
QT_MOC_LITERAL(4, 57, 19), // "receiveFileCallback"
QT_MOC_LITERAL(5, 77, 15), // "connectCallback"
QT_MOC_LITERAL(6, 93, 20), // "writeCommandCallback"
QT_MOC_LITERAL(7, 114, 19) // "readMessageCallback"

    },
    "console_thread\0sendFileCallback\0\0"
    "remote_connection_data*\0receiveFileCallback\0"
    "connectCallback\0writeCommandCallback\0"
    "readMessageCallback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_console_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       4,    2,   44,    2, 0x06 /* Public */,
       5,    2,   49,    2, 0x06 /* Public */,
       6,    2,   54,    2, 0x06 /* Public */,
       7,    2,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,

       0        // eod
};

void console_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        console_thread *_t = static_cast<console_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFileCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 1: _t->receiveFileCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 2: _t->connectCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 3: _t->writeCommandCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        case 4: _t->readMessageCallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< remote_connection_data*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (console_thread::*_t)(int , remote_connection_data * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&console_thread::sendFileCallback)) {
                *result = 0;
            }
        }
        {
            typedef void (console_thread::*_t)(int , remote_connection_data * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&console_thread::receiveFileCallback)) {
                *result = 1;
            }
        }
        {
            typedef void (console_thread::*_t)(int , remote_connection_data * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&console_thread::connectCallback)) {
                *result = 2;
            }
        }
        {
            typedef void (console_thread::*_t)(int , remote_connection_data * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&console_thread::writeCommandCallback)) {
                *result = 3;
            }
        }
        {
            typedef void (console_thread::*_t)(int , remote_connection_data * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&console_thread::readMessageCallback)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject console_thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_console_thread.data,
      qt_meta_data_console_thread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *console_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *console_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_console_thread.stringdata0))
        return static_cast<void*>(const_cast< console_thread*>(this));
    return QThread::qt_metacast(_clname);
}

int console_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void console_thread::sendFileCallback(int _t1, remote_connection_data * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void console_thread::receiveFileCallback(int _t1, remote_connection_data * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void console_thread::connectCallback(int _t1, remote_connection_data * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void console_thread::writeCommandCallback(int _t1, remote_connection_data * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void console_thread::readMessageCallback(int _t1, remote_connection_data * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
