/****************************************************************************
** Meta object code from reading C++ file 'fieldmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fieldmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fieldmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FieldManager_t {
    QByteArrayData data[53];
    char stringdata0[751];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FieldManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FieldManager_t qt_meta_stringdata_FieldManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FieldManager"
QT_MOC_LITERAL(1, 13, 23), // "effectChooseRowMyThread"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "QJsonObject*"
QT_MOC_LITERAL(4, 51, 23), // "effectChooseRowOpThread"
QT_MOC_LITERAL(5, 75, 26), // "effectChooseTargetMyThread"
QT_MOC_LITERAL(6, 102, 26), // "effectChooseTargetOpThread"
QT_MOC_LITERAL(7, 129, 24), // "effectChooseCardMyThread"
QT_MOC_LITERAL(8, 154, 24), // "effectChooseCardOpThread"
QT_MOC_LITERAL(9, 179, 16), // "implementInstant"
QT_MOC_LITERAL(10, 196, 16), // "implementRoutine"
QT_MOC_LITERAL(11, 213, 17), // "implementDeadWish"
QT_MOC_LITERAL(12, 231, 21), // "implementUnitDeadWish"
QT_MOC_LITERAL(13, 253, 9), // "GameUnit*"
QT_MOC_LITERAL(14, 263, 4), // "unit"
QT_MOC_LITERAL(15, 268, 22), // "implementDeployPassive"
QT_MOC_LITERAL(16, 291, 20), // "implementBasePassive"
QT_MOC_LITERAL(17, 312, 24), // "implementCemeteryPassive"
QT_MOC_LITERAL(18, 337, 7), // "shuffle"
QT_MOC_LITERAL(19, 345, 9), // "firstDraw"
QT_MOC_LITERAL(20, 355, 10), // "secondDraw"
QT_MOC_LITERAL(21, 366, 9), // "thirdDraw"
QT_MOC_LITERAL(22, 376, 8), // "newRound"
QT_MOC_LITERAL(23, 385, 10), // "settlement"
QT_MOC_LITERAL(24, 396, 2), // "re"
QT_MOC_LITERAL(25, 399, 5), // "count"
QT_MOC_LITERAL(26, 405, 8), // "gameOver"
QT_MOC_LITERAL(27, 414, 9), // "addEffect"
QT_MOC_LITERAL(28, 424, 3), // "_id"
QT_MOC_LITERAL(29, 428, 6), // "target"
QT_MOC_LITERAL(30, 435, 4), // "type"
QT_MOC_LITERAL(31, 440, 14), // "initBaseEffect"
QT_MOC_LITERAL(32, 455, 4), // "side"
QT_MOC_LITERAL(33, 460, 12), // "deleteEffect"
QT_MOC_LITERAL(34, 473, 10), // "effectType"
QT_MOC_LITERAL(35, 484, 2), // "id"
QT_MOC_LITERAL(36, 487, 10), // "changeTurn"
QT_MOC_LITERAL(37, 498, 15), // "getFightFromVec"
QT_MOC_LITERAL(38, 514, 29), // "const std::vector<GameUnit*>*"
QT_MOC_LITERAL(39, 544, 3), // "vec"
QT_MOC_LITERAL(40, 548, 25), // "commonChooseCardAndDeploy"
QT_MOC_LITERAL(41, 574, 7), // "setPass"
QT_MOC_LITERAL(42, 582, 9), // "drawCards"
QT_MOC_LITERAL(43, 592, 22), // "receiveEffectChooseRow"
QT_MOC_LITERAL(44, 615, 4), // "info"
QT_MOC_LITERAL(45, 620, 25), // "receiveEffectChooseTarget"
QT_MOC_LITERAL(46, 646, 23), // "receiveEffectChooseCard"
QT_MOC_LITERAL(47, 670, 15), // "newCardDeployed"
QT_MOC_LITERAL(48, 686, 13), // "cardDestroyed"
QT_MOC_LITERAL(49, 700, 12), // "throwOneCard"
QT_MOC_LITERAL(50, 713, 15), // "checkAllPassive"
QT_MOC_LITERAL(51, 729, 11), // "targetEaten"
QT_MOC_LITERAL(52, 741, 9) // "eatenside"

    },
    "FieldManager\0effectChooseRowMyThread\0"
    "\0QJsonObject*\0effectChooseRowOpThread\0"
    "effectChooseTargetMyThread\0"
    "effectChooseTargetOpThread\0"
    "effectChooseCardMyThread\0"
    "effectChooseCardOpThread\0implementInstant\0"
    "implementRoutine\0implementDeadWish\0"
    "implementUnitDeadWish\0GameUnit*\0unit\0"
    "implementDeployPassive\0implementBasePassive\0"
    "implementCemeteryPassive\0shuffle\0"
    "firstDraw\0secondDraw\0thirdDraw\0newRound\0"
    "settlement\0re\0count\0gameOver\0addEffect\0"
    "_id\0target\0type\0initBaseEffect\0side\0"
    "deleteEffect\0effectType\0id\0changeTurn\0"
    "getFightFromVec\0const std::vector<GameUnit*>*\0"
    "vec\0commonChooseCardAndDeploy\0setPass\0"
    "drawCards\0receiveEffectChooseRow\0info\0"
    "receiveEffectChooseTarget\0"
    "receiveEffectChooseCard\0newCardDeployed\0"
    "cardDestroyed\0throwOneCard\0checkAllPassive\0"
    "targetEaten\0eatenside"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x06 /* Public */,
       4,    1,  197,    2, 0x06 /* Public */,
       5,    1,  200,    2, 0x06 /* Public */,
       6,    1,  203,    2, 0x06 /* Public */,
       7,    1,  206,    2, 0x06 /* Public */,
       8,    1,  209,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  212,    2, 0x0a /* Public */,
      10,    0,  213,    2, 0x0a /* Public */,
      11,    0,  214,    2, 0x0a /* Public */,
      12,    1,  215,    2, 0x0a /* Public */,
      15,    0,  218,    2, 0x0a /* Public */,
      16,    0,  219,    2, 0x0a /* Public */,
      17,    0,  220,    2, 0x0a /* Public */,
      18,    0,  221,    2, 0x0a /* Public */,
      19,    0,  222,    2, 0x0a /* Public */,
      20,    0,  223,    2, 0x0a /* Public */,
      21,    0,  224,    2, 0x0a /* Public */,
      22,    0,  225,    2, 0x0a /* Public */,
      23,    2,  226,    2, 0x0a /* Public */,
      26,    1,  231,    2, 0x0a /* Public */,
      27,    3,  234,    2, 0x0a /* Public */,
      31,    2,  241,    2, 0x0a /* Public */,
      33,    3,  246,    2, 0x0a /* Public */,
      36,    0,  253,    2, 0x0a /* Public */,
      37,    1,  254,    2, 0x0a /* Public */,
      40,    1,  257,    2, 0x0a /* Public */,
      41,    1,  260,    2, 0x0a /* Public */,
      42,    0,  263,    2, 0x0a /* Public */,
      43,    1,  264,    2, 0x0a /* Public */,
      45,    1,  267,    2, 0x0a /* Public */,
      46,    1,  270,    2, 0x0a /* Public */,
      47,    1,  273,    2, 0x0a /* Public */,
      48,    1,  276,    2, 0x0a /* Public */,
      49,    1,  279,    2, 0x0a /* Public */,
      50,    0,  282,    2, 0x0a /* Public */,
      51,    1,  283,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 3, QMetaType::Int,   24,   25,
    QMetaType::Void, QMetaType::QJsonObject,   24,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13, QMetaType::Int,   28,   29,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   28,   32,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 13,   34,   35,   14,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 38,   39,
    QMetaType::Bool, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   44,
    QMetaType::Void, 0x80000000 | 3,   44,
    QMetaType::Void, 0x80000000 | 3,   44,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   52,

       0        // eod
};

void FieldManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FieldManager *_t = static_cast<FieldManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->effectChooseRowMyThread((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 1: _t->effectChooseRowOpThread((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 2: _t->effectChooseTargetMyThread((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 3: _t->effectChooseTargetOpThread((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 4: _t->effectChooseCardMyThread((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 5: _t->effectChooseCardOpThread((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 6: _t->implementInstant(); break;
        case 7: _t->implementRoutine(); break;
        case 8: _t->implementDeadWish(); break;
        case 9: _t->implementUnitDeadWish((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 10: _t->implementDeployPassive(); break;
        case 11: _t->implementBasePassive(); break;
        case 12: _t->implementCemeteryPassive(); break;
        case 13: _t->shuffle(); break;
        case 14: _t->firstDraw(); break;
        case 15: _t->secondDraw(); break;
        case 16: _t->thirdDraw(); break;
        case 17: _t->newRound(); break;
        case 18: { int _r = _t->settlement((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->gameOver((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 20: _t->addEffect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GameUnit*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 21: _t->initBaseEffect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->deleteEffect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< GameUnit*(*)>(_a[3]))); break;
        case 23: _t->changeTurn(); break;
        case 24: { int _r = _t->getFightFromVec((*reinterpret_cast< const std::vector<GameUnit*>*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->commonChooseCardAndDeploy((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->setPass((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->drawCards(); break;
        case 28: _t->receiveEffectChooseRow((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 29: _t->receiveEffectChooseTarget((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 30: _t->receiveEffectChooseCard((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 31: _t->newCardDeployed((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 32: _t->cardDestroyed((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 33: _t->throwOneCard((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->checkAllPassive(); break;
        case 35: _t->targetEaten((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FieldManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldManager::effectChooseRowMyThread)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FieldManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldManager::effectChooseRowOpThread)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FieldManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldManager::effectChooseTargetMyThread)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FieldManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldManager::effectChooseTargetOpThread)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FieldManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldManager::effectChooseCardMyThread)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (FieldManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldManager::effectChooseCardOpThread)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject FieldManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FieldManager.data,
      qt_meta_data_FieldManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FieldManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FieldManager.stringdata0))
        return static_cast<void*>(const_cast< FieldManager*>(this));
    return QObject::qt_metacast(_clname);
}

int FieldManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void FieldManager::effectChooseRowMyThread(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FieldManager::effectChooseRowOpThread(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FieldManager::effectChooseTargetMyThread(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FieldManager::effectChooseTargetOpThread(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FieldManager::effectChooseCardMyThread(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FieldManager::effectChooseCardOpThread(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
