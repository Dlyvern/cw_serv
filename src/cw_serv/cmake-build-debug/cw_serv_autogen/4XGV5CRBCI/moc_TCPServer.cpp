/****************************************************************************
** Meta object code from reading C++ file 'TCPServer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/cw_serv/modules/TCPServer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCPServer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPServer_t {
    QByteArrayData data[15];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPServer_t qt_meta_stringdata_TCPServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPServer"
QT_MOC_LITERAL(1, 10, 13), // "NewConnection"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 20), // "LogMessageFromClient"
QT_MOC_LITERAL(4, 46, 11), // "std::string"
QT_MOC_LITERAL(5, 58, 7), // "message"
QT_MOC_LITERAL(6, 66, 8), // "levelLog"
QT_MOC_LITERAL(7, 75, 11), // "SetOperator"
QT_MOC_LITERAL(8, 87, 10), // "TCPClient*"
QT_MOC_LITERAL(9, 98, 11), // "newOperator"
QT_MOC_LITERAL(10, 110, 9), // "NewAction"
QT_MOC_LITERAL(11, 120, 10), // "idOfClient"
QT_MOC_LITERAL(12, 131, 8), // "Command*"
QT_MOC_LITERAL(13, 140, 7), // "command"
QT_MOC_LITERAL(14, 148, 3) // "Run"

    },
    "TCPServer\0NewConnection\0\0LogMessageFromClient\0"
    "std::string\0message\0levelLog\0SetOperator\0"
    "TCPClient*\0newOperator\0NewAction\0"
    "idOfClient\0Command*\0command\0Run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    2,   40,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
      10,    2,   48,    2, 0x08 /* Private */,
      14,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,
    QMetaType::Void,

       0        // eod
};

void TCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCPServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->NewConnection(); break;
        case 1: _t->LogMessageFromClient((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->SetOperator((*reinterpret_cast< TCPClient*(*)>(_a[1]))); break;
        case 3: _t->NewAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Command*(*)>(_a[2]))); break;
        case 4: _t->Run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TCPClient* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TCPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<Module::staticMetaObject>(),
    qt_meta_stringdata_TCPServer.data,
    qt_meta_data_TCPServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer.stringdata0))
        return static_cast<void*>(this);
    return Module::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Module::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
