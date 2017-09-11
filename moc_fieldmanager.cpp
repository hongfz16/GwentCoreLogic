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
    QByteArrayData data[44];
    char stringdata0[617];
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
QT_MOC_LITERAL(7, 129, 16), // "implementInstant"
QT_MOC_LITERAL(8, 146, 16), // "implementRoutine"
QT_MOC_LITERAL(9, 163, 17), // "implementDeadWish"
QT_MOC_LITERAL(10, 181, 21), // "implementUnitDeadWish"
QT_MOC_LITERAL(11, 203, 9), // "GameUnit*"
QT_MOC_LITERAL(12, 213, 4), // "unit"
QT_MOC_LITERAL(13, 218, 22), // "implementDeployPassive"
QT_MOC_LITERAL(14, 241, 20), // "implementBasePassive"
QT_MOC_LITERAL(15, 262, 24), // "implementCemeteryPassive"
QT_MOC_LITERAL(16, 287, 7), // "shuffle"
QT_MOC_LITERAL(17, 295, 9), // "firstDraw"
QT_MOC_LITERAL(18, 305, 10), // "secondDraw"
QT_MOC_LITERAL(19, 316, 9), // "thirdDraw"
QT_MOC_LITERAL(20, 326, 8), // "newRound"
QT_MOC_LITERAL(21, 335, 10), // "settlement"
QT_MOC_LITERAL(22, 346, 8), // "gameOver"
QT_MOC_LITERAL(23, 355, 9), // "addEffect"
QT_MOC_LITERAL(24, 365, 3), // "_id"
QT_MOC_LITERAL(25, 369, 6), // "target"
QT_MOC_LITERAL(26, 376, 4), // "type"
QT_MOC_LITERAL(27, 381, 14), // "initBaseEffect"
QT_MOC_LITERAL(28, 396, 4), // "side"
QT_MOC_LITERAL(29, 401, 12), // "deleteEffect"
QT_MOC_LITERAL(30, 414, 10), // "effectType"
QT_MOC_LITERAL(31, 425, 2), // "id"
QT_MOC_LITERAL(32, 428, 10), // "changeTurn"
QT_MOC_LITERAL(33, 439, 15), // "getFightFromVec"
QT_MOC_LITERAL(34, 455, 29), // "const std::vector<GameUnit*>*"
QT_MOC_LITERAL(35, 485, 3), // "vec"
QT_MOC_LITERAL(36, 489, 25), // "commonChooseCardAndDeploy"
QT_MOC_LITERAL(37, 515, 7), // "setPass"
QT_MOC_LITERAL(38, 523, 9), // "drawCards"
QT_MOC_LITERAL(39, 533, 22), // "receiveEffectChooseRow"
QT_MOC_LITERAL(40, 556, 4), // "info"
QT_MOC_LITERAL(41, 561, 25), // "receiveEffectChooseTarget"
QT_MOC_LITERAL(42, 587, 15), // "newCardDeployed"
QT_MOC_LITERAL(43, 603, 13) // "cardDestroyed"

    },
    "FieldManager\0effectChooseRowMyThread\0"
    "\0QJsonObject*\0effectChooseRowOpThread\0"
    "effectChooseTargetMyThread\0"
    "effectChooseTargetOpThread\0implementInstant\0"
    "implementRoutine\0implementDeadWish\0"
    "implementUnitDeadWish\0GameUnit*\0unit\0"
    "implementDeployPassive\0implementBasePassive\0"
    "implementCemeteryPassive\0shuffle\0"
    "firstDraw\0secondDraw\0thirdDraw\0newRound\0"
    "settlement\0gameOver\0addEffect\0_id\0"
    "target\0type\0initBaseEffect\0side\0"
    "deleteEffect\0effectType\0id\0changeTurn\0"
    "getFightFromVec\0const std::vector<GameUnit*>*\0"
    "vec\0commonChooseCardAndDeploy\0setPass\0"
    "drawCards\0receiveEffectChooseRow\0info\0"
    "receiveEffectChooseTarget\0newCardDeployed\0"
    "cardDestroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  164,    2, 0x06 /* Public */,
       4,    1,  167,    2, 0x06 /* Public */,
       5,    1,  170,    2, 0x06 /* Public */,
       6,    1,  173,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  176,    2, 0x0a /* Public */,
       8,    0,  177,    2, 0x0a /* Public */,
       9,    0,  178,    2, 0x0a /* Public */,
      10,    1,  179,    2, 0x0a /* Public */,
      13,    0,  182,    2, 0x0a /* Public */,
      14,    0,  183,    2, 0x0a /* Public */,
      15,    0,  184,    2, 0x0a /* Public */,
      16,    0,  185,    2, 0x0a /* Public */,
      17,    0,  186,    2, 0x0a /* Public */,
      18,    0,  187,    2, 0x0a /* Public */,
      19,    0,  188,    2, 0x0a /* Public */,
      20,    0,  189,    2, 0x0a /* Public */,
      21,    0,  190,    2, 0x0a /* Public */,
      22,    0,  191,    2, 0x0a /* Public */,
      23,    3,  192,    2, 0x0a /* Public */,
      27,    2,  199,    2, 0x0a /* Public */,
      29,    3,  204,    2, 0x0a /* Public */,
      32,    0,  211,    2, 0x0a /* Public */,
      33,    1,  212,    2, 0x0a /* Public */,
      36,    1,  215,    2, 0x0a /* Public */,
      37,    1,  218,    2, 0x0a /* Public */,
      38,    0,  221,    2, 0x0a /* Public */,
      39,    1,  222,    2, 0x0a /* Public */,
      41,    1,  225,    2, 0x0a /* Public */,
      42,    1,  228,    2, 0x0a /* Public */,
      43,    1,  231,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11, QMetaType::Int,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,   30,   31,   12,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 34,   35,
    QMetaType::Bool, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   40,
    QMetaType::Void, 0x80000000 | 3,   40,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,

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
        case 4: _t->implementInstant(); break;
        case 5: _t->implementRoutine(); break;
        case 6: _t->implementDeadWish(); break;
        case 7: _t->implementUnitDeadWish((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 8: _t->implementDeployPassive(); break;
        case 9: _t->implementBasePassive(); break;
        case 10: _t->implementCemeteryPassive(); break;
        case 11: _t->shuffle(); break;
        case 12: _t->firstDraw(); break;
        case 13: _t->secondDraw(); break;
        case 14: _t->thirdDraw(); break;
        case 15: _t->newRound(); break;
        case 16: { int _r = _t->settlement();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->gameOver(); break;
        case 18: _t->addEffect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GameUnit*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 19: _t->initBaseEffect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->deleteEffect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< GameUnit*(*)>(_a[3]))); break;
        case 21: _t->changeTurn(); break;
        case 22: { int _r = _t->getFightFromVec((*reinterpret_cast< const std::vector<GameUnit*>*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->commonChooseCardAndDeploy((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->setPass((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->drawCards(); break;
        case 26: _t->receiveEffectChooseRow((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 27: _t->receiveEffectChooseTarget((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 28: _t->newCardDeployed((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 29: _t->cardDestroyed((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 29:
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
