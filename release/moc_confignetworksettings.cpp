/****************************************************************************
** Meta object code from reading C++ file 'confignetworksettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Displays/config_materials/headers/confignetworksettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'confignetworksettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_confignetworksettings_t {
    QByteArrayData data[10];
    char stringdata[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_confignetworksettings_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_confignetworksettings_t qt_meta_stringdata_confignetworksettings = {
    {
QT_MOC_LITERAL(0, 0, 21), // "confignetworksettings"
QT_MOC_LITERAL(1, 22, 15), // "startConnection"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "host"
QT_MOC_LITERAL(4, 44, 4), // "port"
QT_MOC_LITERAL(5, 49, 8), // "username"
QT_MOC_LITERAL(6, 58, 8), // "password"
QT_MOC_LITERAL(7, 67, 20), // "connectButtonHandler"
QT_MOC_LITERAL(8, 88, 10), // "returnCode"
QT_MOC_LITERAL(9, 99, 4) // "code"

    },
    "confignetworksettings\0startConnection\0"
    "\0host\0port\0username\0password\0"
    "connectButtonHandler\0returnCode\0code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_confignetworksettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   38,    2, 0x0a /* Public */,
       8,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void confignetworksettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        confignetworksettings *_t = static_cast<confignetworksettings *>(_o);
        switch (_id) {
        case 0: _t->startConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->connectButtonHandler(); break;
        case 2: _t->returnCode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (confignetworksettings::*_t)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&confignetworksettings::startConnection)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject confignetworksettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_confignetworksettings.data,
      qt_meta_data_confignetworksettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *confignetworksettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *confignetworksettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_confignetworksettings.stringdata))
        return static_cast<void*>(const_cast< confignetworksettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int confignetworksettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void confignetworksettings::startConnection(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
