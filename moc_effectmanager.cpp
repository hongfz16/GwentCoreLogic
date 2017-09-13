/****************************************************************************
** Meta object code from reading C++ file 'effectmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "effectmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'effectmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EffectManager_t {
    QByteArrayData data[70];
    char stringdata0[841];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EffectManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EffectManager_t qt_meta_stringdata_EffectManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EffectManager"
QT_MOC_LITERAL(1, 14, 16), // "findWeakestInRow"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "std::vector<GameUnit*>*"
QT_MOC_LITERAL(4, 56, 3), // "vec"
QT_MOC_LITERAL(5, 60, 6), // "rowNum"
QT_MOC_LITERAL(6, 67, 6), // "maxNum"
QT_MOC_LITERAL(7, 74, 18), // "findStrongestInRow"
QT_MOC_LITERAL(8, 93, 8), // "findNear"
QT_MOC_LITERAL(9, 102, 9), // "GameUnit*"
QT_MOC_LITERAL(10, 112, 6), // "target"
QT_MOC_LITERAL(11, 119, 4), // "type"
QT_MOC_LITERAL(12, 124, 16), // "findWeakestInAll"
QT_MOC_LITERAL(13, 141, 18), // "findStrongestInAll"
QT_MOC_LITERAL(14, 160, 9), // "damageByN"
QT_MOC_LITERAL(15, 170, 1), // "N"
QT_MOC_LITERAL(16, 172, 25), // "damageByNUnseenProtection"
QT_MOC_LITERAL(17, 198, 8), // "boostByN"
QT_MOC_LITERAL(18, 207, 16), // "addProtectionByN"
QT_MOC_LITERAL(19, 224, 10), // "lockTarget"
QT_MOC_LITERAL(20, 235, 12), // "makePowerToN"
QT_MOC_LITERAL(21, 248, 13), // "destroyTarget"
QT_MOC_LITERAL(22, 262, 9), // "eatTarget"
QT_MOC_LITERAL(23, 272, 5), // "eator"
QT_MOC_LITERAL(24, 278, 10), // "moveTarget"
QT_MOC_LITERAL(25, 289, 5), // "toRow"
QT_MOC_LITERAL(26, 295, 18), // "peekNCardsFromBase"
QT_MOC_LITERAL(27, 314, 4), // "side"
QT_MOC_LITERAL(28, 319, 24), // "peekSpecificCardFromBase"
QT_MOC_LITERAL(29, 344, 17), // "putCardBackToBase"
QT_MOC_LITERAL(30, 362, 4), // "unit"
QT_MOC_LITERAL(31, 367, 13), // "generateNCard"
QT_MOC_LITERAL(32, 381, 2), // "id"
QT_MOC_LITERAL(33, 384, 7), // "_target"
QT_MOC_LITERAL(34, 392, 32), // "generateNCardWithOutChooseTarget"
QT_MOC_LITERAL(35, 425, 6), // "getRow"
QT_MOC_LITERAL(36, 432, 20), // "getRowIncludeWeather"
QT_MOC_LITERAL(37, 453, 19), // "deployCardsFromBase"
QT_MOC_LITERAL(38, 473, 5), // "index"
QT_MOC_LITERAL(39, 479, 24), // "deployRandomCardFromBase"
QT_MOC_LITERAL(40, 504, 11), // "deployCards"
QT_MOC_LITERAL(41, 516, 19), // "resurrectCardToHand"
QT_MOC_LITERAL(42, 536, 12), // "cemeterySide"
QT_MOC_LITERAL(43, 549, 13), // "resurrectSide"
QT_MOC_LITERAL(44, 563, 18), // "resurrectCardToRow"
QT_MOC_LITERAL(45, 582, 15), // "EffectChooseRow"
QT_MOC_LITERAL(46, 598, 12), // "QJsonObject*"
QT_MOC_LITERAL(47, 611, 4), // "info"
QT_MOC_LITERAL(48, 616, 18), // "EffectChooseTarget"
QT_MOC_LITERAL(49, 635, 16), // "EffectChooseCard"
QT_MOC_LITERAL(50, 652, 5), // "exist"
QT_MOC_LITERAL(51, 658, 5), // "bool*"
QT_MOC_LITERAL(52, 664, 2), // "re"
QT_MOC_LITERAL(53, 667, 11), // "findWeather"
QT_MOC_LITERAL(54, 679, 8), // "getRight"
QT_MOC_LITERAL(55, 688, 4), // "self"
QT_MOC_LITERAL(56, 693, 5), // "right"
QT_MOC_LITERAL(57, 699, 15), // "implementEffect"
QT_MOC_LITERAL(58, 715, 4), // "turn"
QT_MOC_LITERAL(59, 720, 11), // "updateTimer"
QT_MOC_LITERAL(60, 732, 10), // "resetTimer"
QT_MOC_LITERAL(61, 743, 9), // "chooseRow"
QT_MOC_LITERAL(62, 753, 12), // "chooseTarget"
QT_MOC_LITERAL(63, 766, 10), // "chooseCard"
QT_MOC_LITERAL(64, 777, 3), // "arr"
QT_MOC_LITERAL(65, 781, 7), // "getSelf"
QT_MOC_LITERAL(66, 789, 9), // "getUnitId"
QT_MOC_LITERAL(67, 799, 7), // "getSide"
QT_MOC_LITERAL(68, 807, 18), // "getNeedToBeDeleted"
QT_MOC_LITERAL(69, 826, 14) // "setDeleteLater"

    },
    "EffectManager\0findWeakestInRow\0\0"
    "std::vector<GameUnit*>*\0vec\0rowNum\0"
    "maxNum\0findStrongestInRow\0findNear\0"
    "GameUnit*\0target\0type\0findWeakestInAll\0"
    "findStrongestInAll\0damageByN\0N\0"
    "damageByNUnseenProtection\0boostByN\0"
    "addProtectionByN\0lockTarget\0makePowerToN\0"
    "destroyTarget\0eatTarget\0eator\0moveTarget\0"
    "toRow\0peekNCardsFromBase\0side\0"
    "peekSpecificCardFromBase\0putCardBackToBase\0"
    "unit\0generateNCard\0id\0_target\0"
    "generateNCardWithOutChooseTarget\0"
    "getRow\0getRowIncludeWeather\0"
    "deployCardsFromBase\0index\0"
    "deployRandomCardFromBase\0deployCards\0"
    "resurrectCardToHand\0cemeterySide\0"
    "resurrectSide\0resurrectCardToRow\0"
    "EffectChooseRow\0QJsonObject*\0info\0"
    "EffectChooseTarget\0EffectChooseCard\0"
    "exist\0bool*\0re\0findWeather\0getRight\0"
    "self\0right\0implementEffect\0turn\0"
    "updateTimer\0resetTimer\0chooseRow\0"
    "chooseTarget\0chooseCard\0arr\0getSelf\0"
    "getUnitId\0getSide\0getNeedToBeDeleted\0"
    "setDeleteLater"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EffectManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      37,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  259,    2, 0x06 /* Public */,
       1,    3,  264,    2, 0x06 /* Public */,
       7,    2,  271,    2, 0x06 /* Public */,
       7,    3,  276,    2, 0x06 /* Public */,
       8,    5,  283,    2, 0x06 /* Public */,
      12,    1,  294,    2, 0x06 /* Public */,
      12,    2,  297,    2, 0x06 /* Public */,
      13,    1,  302,    2, 0x06 /* Public */,
      13,    2,  305,    2, 0x06 /* Public */,
      14,    2,  310,    2, 0x06 /* Public */,
      16,    2,  315,    2, 0x06 /* Public */,
      17,    2,  320,    2, 0x06 /* Public */,
      18,    2,  325,    2, 0x06 /* Public */,
      19,    1,  330,    2, 0x06 /* Public */,
      20,    2,  333,    2, 0x06 /* Public */,
      21,    1,  338,    2, 0x06 /* Public */,
      22,    2,  341,    2, 0x06 /* Public */,
      24,    2,  346,    2, 0x06 /* Public */,
      26,    2,  351,    2, 0x06 /* Public */,
      28,    2,  356,    2, 0x06 /* Public */,
      29,    3,  361,    2, 0x06 /* Public */,
      31,    5,  368,    2, 0x06 /* Public */,
      34,    4,  379,    2, 0x06 /* Public */,
      35,    2,  388,    2, 0x06 /* Public */,
      36,    2,  393,    2, 0x06 /* Public */,
      37,    5,  398,    2, 0x06 /* Public */,
      39,    3,  409,    2, 0x06 /* Public */,
      40,    3,  416,    2, 0x06 /* Public */,
      40,    3,  423,    2, 0x06 /* Public */,
      41,    4,  430,    2, 0x06 /* Public */,
      44,    5,  439,    2, 0x06 /* Public */,
      45,    1,  450,    2, 0x06 /* Public */,
      48,    1,  453,    2, 0x06 /* Public */,
      49,    1,  456,    2, 0x06 /* Public */,
      50,    3,  459,    2, 0x06 /* Public */,
      53,    2,  466,    2, 0x06 /* Public */,
      54,    2,  471,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      57,    2,  476,    2, 0x0a /* Public */,
      57,    1,  481,    2, 0x2a /* Public | MethodCloned */,
      59,    0,  484,    2, 0x0a /* Public */,
      60,    0,  485,    2, 0x0a /* Public */,
      61,    0,  486,    2, 0x0a /* Public */,
      62,    0,  487,    2, 0x0a /* Public */,
      63,    1,  488,    2, 0x0a /* Public */,
      65,    0,  491,    2, 0x0a /* Public */,
      66,    0,  492,    2, 0x0a /* Public */,
      67,    0,  493,    2, 0x0a /* Public */,
      68,    0,  494,    2, 0x0a /* Public */,
      69,    0,  495,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 9, QMetaType::Int, QMetaType::Int,    4,    5,   10,   11,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   15,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   15,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   15,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   15,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   15,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    4,   23,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   15,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   27,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Bool,   30,   11,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,   32,    5,   33,   15,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   32,    5,   15,   27,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int,   32,    5,   38,   27,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    5,   38,   27,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int,   30,    5,   38,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, 0x80000000 | 9,   30,    5,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, QMetaType::Int,   32,   42,   43,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,   32,   42,    5,   38,   11,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 51, QMetaType::Int,   32,   52,   11,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   27,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 3,   55,   56,

 // slots: parameters
    QMetaType::Bool, QMetaType::Bool, QMetaType::Int,   58,   11,
    QMetaType::Bool, QMetaType::Bool,   58,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    0x80000000 | 3,
    QMetaType::Int, QMetaType::QJsonArray,   64,
    0x80000000 | 9,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void EffectManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EffectManager *_t = static_cast<EffectManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findWeakestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->findWeakestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->findStrongestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->findStrongestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->findNear((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< GameUnit*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->findWeakestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 6: _t->findWeakestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->findStrongestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 8: _t->findStrongestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->damageByN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->damageByNUnseenProtection((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->boostByN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->addProtectionByN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->lockTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 14: _t->makePowerToN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->destroyTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 16: _t->eatTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< GameUnit*(*)>(_a[2]))); break;
        case 17: _t->moveTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->peekNCardsFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 19: _t->peekSpecificCardFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->putCardBackToBase((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 21: _t->generateNCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 22: _t->generateNCardWithOutChooseTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 23: _t->getRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->getRowIncludeWeather((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->deployCardsFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 26: _t->deployRandomCardFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 27: _t->deployCards((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 28: _t->deployCards((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< GameUnit*(*)>(_a[3]))); break;
        case 29: _t->resurrectCardToHand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 30: _t->resurrectCardToRow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 31: _t->EffectChooseRow((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 32: _t->EffectChooseTarget((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 33: _t->EffectChooseCard((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 34: _t->exist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 35: _t->findWeather((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 36: _t->getRight((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[2]))); break;
        case 37: { bool _r = _t->implementEffect((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { bool _r = _t->implementEffect((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->updateTimer(); break;
        case 40: _t->resetTimer(); break;
        case 41: { int _r = _t->chooseRow();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 42: { std::vector<GameUnit*>* _r = _t->chooseTarget();
            if (_a[0]) *reinterpret_cast< std::vector<GameUnit*>**>(_a[0]) = std::move(_r); }  break;
        case 43: { int _r = _t->chooseCard((*reinterpret_cast< QJsonArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 44: { GameUnit* _r = _t->getSelf();
            if (_a[0]) *reinterpret_cast< GameUnit**>(_a[0]) = std::move(_r); }  break;
        case 45: { int _r = _t->getUnitId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->getSide();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->getNeedToBeDeleted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->setDeleteLater(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 36:
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
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findWeakestInRow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findWeakestInRow)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findStrongestInRow)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findStrongestInRow)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int , GameUnit * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findNear)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findWeakestInAll)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findWeakestInAll)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findStrongestInAll)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findStrongestInAll)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::damageByN)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::damageByNUnseenProtection)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::boostByN)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::addProtectionByN)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::lockTarget)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::makePowerToN)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::destroyTarget)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , GameUnit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::eatTarget)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::moveTarget)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::peekNCardsFromBase)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::peekSpecificCardFromBase)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(GameUnit * , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::putCardBackToBase)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , int , std::vector<GameUnit*> * , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::generateNCard)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , int , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::generateNCardWithOutChooseTarget)) {
                *result = 22;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::getRow)) {
                *result = 23;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::getRowIncludeWeather)) {
                *result = 24;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , int , int , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::deployCardsFromBase)) {
                *result = 25;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::deployRandomCardFromBase)) {
                *result = 26;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(GameUnit * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::deployCards)) {
                *result = 27;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(GameUnit * , int , GameUnit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::deployCards)) {
                *result = 28;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , bool , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::resurrectCardToHand)) {
                *result = 29;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , bool , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::resurrectCardToRow)) {
                *result = 30;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::EffectChooseRow)) {
                *result = 31;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::EffectChooseTarget)) {
                *result = 32;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::EffectChooseCard)) {
                *result = 33;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(int , bool * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::exist)) {
                *result = 34;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(std::vector<GameUnit*> * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::findWeather)) {
                *result = 35;
                return;
            }
        }
        {
            typedef void (EffectManager::*_t)(GameUnit * , std::vector<GameUnit*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EffectManager::getRight)) {
                *result = 36;
                return;
            }
        }
    }
}

const QMetaObject EffectManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EffectManager.data,
      qt_meta_data_EffectManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EffectManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EffectManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EffectManager.stringdata0))
        return static_cast<void*>(const_cast< EffectManager*>(this));
    return QObject::qt_metacast(_clname);
}

int EffectManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void EffectManager::findWeakestInRow(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EffectManager::findWeakestInRow(std::vector<GameUnit*> * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EffectManager::findStrongestInRow(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EffectManager::findStrongestInRow(std::vector<GameUnit*> * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EffectManager::findNear(std::vector<GameUnit*> * _t1, int _t2, GameUnit * _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EffectManager::findWeakestInAll(std::vector<GameUnit*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EffectManager::findWeakestInAll(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EffectManager::findStrongestInAll(std::vector<GameUnit*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void EffectManager::findStrongestInAll(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void EffectManager::damageByN(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void EffectManager::damageByNUnseenProtection(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void EffectManager::boostByN(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void EffectManager::addProtectionByN(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void EffectManager::lockTarget(std::vector<GameUnit*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void EffectManager::makePowerToN(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void EffectManager::destroyTarget(std::vector<GameUnit*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void EffectManager::eatTarget(std::vector<GameUnit*> * _t1, GameUnit * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void EffectManager::moveTarget(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void EffectManager::peekNCardsFromBase(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void EffectManager::peekSpecificCardFromBase(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void EffectManager::putCardBackToBase(GameUnit * _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void EffectManager::generateNCard(int _t1, int _t2, std::vector<GameUnit*> * _t3, int _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void EffectManager::generateNCardWithOutChooseTarget(int _t1, int _t2, int _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void EffectManager::getRow(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void EffectManager::getRowIncludeWeather(std::vector<GameUnit*> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void EffectManager::deployCardsFromBase(int _t1, int _t2, int _t3, bool _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void EffectManager::deployRandomCardFromBase(int _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void EffectManager::deployCards(GameUnit * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void EffectManager::deployCards(GameUnit * _t1, int _t2, GameUnit * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void EffectManager::resurrectCardToHand(int _t1, bool _t2, bool _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void EffectManager::resurrectCardToRow(int _t1, bool _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void EffectManager::EffectChooseRow(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void EffectManager::EffectChooseTarget(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void EffectManager::EffectChooseCard(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void EffectManager::exist(int _t1, bool * _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void EffectManager::findWeather(std::vector<GameUnit*> * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void EffectManager::getRight(GameUnit * _t1, std::vector<GameUnit*> * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
