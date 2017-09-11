/****************************************************************************
** Meta object code from reading C++ file 'mythread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mythread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyThread_t {
    QByteArrayData data[21];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyThread_t qt_meta_stringdata_MyThread = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyThread"
QT_MOC_LITERAL(1, 9, 5), // "error"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(4, 40, 11), // "socketError"
QT_MOC_LITERAL(5, 52, 19), // "needToRemoveFromMap"
QT_MOC_LITERAL(6, 72, 7), // "qintptr"
QT_MOC_LITERAL(7, 80, 2), // "id"
QT_MOC_LITERAL(8, 83, 18), // "sendSignalToServer"
QT_MOC_LITERAL(9, 102, 4), // "mess"
QT_MOC_LITERAL(10, 107, 21), // "sendSignalTogameField"
QT_MOC_LITERAL(11, 129, 4), // "info"
QT_MOC_LITERAL(12, 134, 22), // "sendSignalToController"
QT_MOC_LITERAL(13, 157, 4), // "side"
QT_MOC_LITERAL(14, 162, 9), // "readyRead"
QT_MOC_LITERAL(15, 172, 12), // "disconnected"
QT_MOC_LITERAL(16, 185, 15), // "sendQJsonObject"
QT_MOC_LITERAL(17, 201, 33), // "sendQJsonObjectAndWaitForResp..."
QT_MOC_LITERAL(18, 235, 12), // "QJsonObject*"
QT_MOC_LITERAL(19, 248, 15), // "waitForDrawCard"
QT_MOC_LITERAL(20, 264, 13) // "waitForDeploy"

    },
    "MyThread\0error\0\0QTcpSocket::SocketError\0"
    "socketError\0needToRemoveFromMap\0qintptr\0"
    "id\0sendSignalToServer\0mess\0"
    "sendSignalTogameField\0info\0"
    "sendSignalToController\0side\0readyRead\0"
    "disconnected\0sendQJsonObject\0"
    "sendQJsonObjectAndWaitForResponde\0"
    "QJsonObject*\0waitForDrawCard\0waitForDeploy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       8,    2,   75,    2, 0x06 /* Public */,
      10,    1,   80,    2, 0x06 /* Public */,
      12,    2,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   88,    2, 0x0a /* Public */,
      15,    0,   89,    2, 0x0a /* Public */,
      16,    1,   90,    2, 0x0a /* Public */,
      17,    1,   93,    2, 0x0a /* Public */,
      19,    1,   96,    2, 0x0a /* Public */,
      20,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    9,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   13,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void, 0x80000000 | 18,   11,
    QMetaType::Void, 0x80000000 | 18,   11,
    QMetaType::Void, 0x80000000 | 18,   11,

       0        // eod
};

void MyThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyThread *_t = static_cast<MyThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->needToRemoveFromMap((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 2: _t->sendSignalToServer((*reinterpret_cast< qintptr(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendSignalTogameField((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->sendSignalToController((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->readyRead(); break;
        case 6: _t->disconnected(); break;
        case 7: _t->sendQJsonObject((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 8: _t->sendQJsonObjectAndWaitForResponde((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 9: _t->waitForDrawCard((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 10: _t->waitForDeploy((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyThread::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyThread::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyThread::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyThread::needToRemoveFromMap)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyThread::*_t)(qintptr , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyThread::sendSignalToServer)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyThread::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyThread::sendSignalTogameField)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyThread::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyThread::sendSignalToController)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MyThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyThread.data,
      qt_meta_data_MyThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyThread.stringdata0))
        return static_cast<void*>(const_cast< MyThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MyThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyThread::needToRemoveFromMap(qintptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyThread::sendSignalToServer(qintptr _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyThread::sendSignalTogameField(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyThread::sendSignalToController(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
