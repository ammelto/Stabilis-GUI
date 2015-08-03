/****************************************************************************
** Meta object code from reading C++ file 'configvehiclesettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Displays/config_materials/headers/configvehiclesettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configvehiclesettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_configvehiclesettings_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_configvehiclesettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_configvehiclesettings_t qt_meta_stringdata_configvehiclesettings = {
    {
QT_MOC_LITERAL(0, 0, 21), // "configvehiclesettings"
QT_MOC_LITERAL(1, 22, 10), // "globalSave"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "select"
QT_MOC_LITERAL(4, 41, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 58, 4), // "item"
QT_MOC_LITERAL(6, 63, 13) // "buttonHandler"

    },
    "configvehiclesettings\0globalSave\0\0"
    "select\0QListWidgetItem*\0item\0buttonHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_configvehiclesettings[] = {

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
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void configvehiclesettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        configvehiclesettings *_t = static_cast<configvehiclesettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->globalSave(); break;
        case 1: _t->select((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->buttonHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (configvehiclesettings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&configvehiclesettings::globalSave)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject configvehiclesettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_configvehiclesettings.data,
      qt_meta_data_configvehiclesettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *configvehiclesettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *configvehiclesettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_configvehiclesettings.stringdata0))
        return static_cast<void*>(const_cast< configvehiclesettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int configvehiclesettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void configvehiclesettings::globalSave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
