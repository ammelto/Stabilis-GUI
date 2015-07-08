/****************************************************************************
** Meta object code from reading C++ file 'securefileuploader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QSsh-master/examples/SecureUploader/securefileuploader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'securefileuploader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SecureFileUploader_t {
    QByteArrayData data[12];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SecureFileUploader_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SecureFileUploader_t qt_meta_stringdata_SecureFileUploader = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SecureFileUploader"
QT_MOC_LITERAL(1, 19, 11), // "onConnected"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "onConnectionError"
QT_MOC_LITERAL(4, 50, 14), // "QSsh::SshError"
QT_MOC_LITERAL(5, 65, 20), // "onChannelInitialized"
QT_MOC_LITERAL(6, 86, 14), // "onChannelError"
QT_MOC_LITERAL(7, 101, 3), // "err"
QT_MOC_LITERAL(8, 105, 12), // "onOpfinished"
QT_MOC_LITERAL(9, 118, 15), // "QSsh::SftpJobId"
QT_MOC_LITERAL(10, 134, 3), // "job"
QT_MOC_LITERAL(11, 138, 5) // "error"

    },
    "SecureFileUploader\0onConnected\0\0"
    "onConnectionError\0QSsh::SshError\0"
    "onChannelInitialized\0onChannelError\0"
    "err\0onOpfinished\0QSsh::SftpJobId\0job\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SecureFileUploader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       8,    2,   52,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x28 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,   11,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void SecureFileUploader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SecureFileUploader *_t = static_cast<SecureFileUploader *>(_o);
        switch (_id) {
        case 0: _t->onConnected(); break;
        case 1: _t->onConnectionError((*reinterpret_cast< QSsh::SshError(*)>(_a[1]))); break;
        case 2: _t->onChannelInitialized(); break;
        case 3: _t->onChannelError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onOpfinished((*reinterpret_cast< QSsh::SftpJobId(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->onOpfinished((*reinterpret_cast< QSsh::SftpJobId(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SecureFileUploader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SecureFileUploader.data,
      qt_meta_data_SecureFileUploader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SecureFileUploader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SecureFileUploader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SecureFileUploader.stringdata))
        return static_cast<void*>(const_cast< SecureFileUploader*>(this));
    return QObject::qt_metacast(_clname);
}

int SecureFileUploader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
