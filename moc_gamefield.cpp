/****************************************************************************
** Meta object code from reading C++ file 'gamefield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamefield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamefield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameField_t {
    QByteArrayData data[62];
    char stringdata0[833];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameField_t qt_meta_stringdata_GameField = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameField"
QT_MOC_LITERAL(1, 10, 10), // "rowChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "rowNum"
QT_MOC_LITERAL(4, 29, 11), // "baseChanged"
QT_MOC_LITERAL(5, 41, 4), // "side"
QT_MOC_LITERAL(6, 46, 15), // "cemeteryChanged"
QT_MOC_LITERAL(7, 62, 15), // "handCardChanged"
QT_MOC_LITERAL(8, 78, 23), // "gameUnitChangedToClient"
QT_MOC_LITERAL(9, 102, 4), // "info"
QT_MOC_LITERAL(10, 107, 18), // "rowChangedToClient"
QT_MOC_LITERAL(11, 126, 19), // "baseChangedToClient"
QT_MOC_LITERAL(12, 146, 23), // "cemeteryChangedToClient"
QT_MOC_LITERAL(13, 170, 23), // "handCardChangedToClient"
QT_MOC_LITERAL(14, 194, 15), // "newCardDeployed"
QT_MOC_LITERAL(15, 210, 9), // "GameUnit*"
QT_MOC_LITERAL(16, 220, 13), // "cardDestroyed"
QT_MOC_LITERAL(17, 234, 15), // "gameUnitChanged"
QT_MOC_LITERAL(18, 250, 6), // "target"
QT_MOC_LITERAL(19, 257, 14), // "rowChangedSlot"
QT_MOC_LITERAL(20, 272, 15), // "baseChangedSlot"
QT_MOC_LITERAL(21, 288, 19), // "cemeteryChangedSlot"
QT_MOC_LITERAL(22, 308, 19), // "handCardChangedSlot"
QT_MOC_LITERAL(23, 328, 16), // "findWeakestInRow"
QT_MOC_LITERAL(24, 345, 23), // "std::vector<GameUnit*>*"
QT_MOC_LITERAL(25, 369, 3), // "vec"
QT_MOC_LITERAL(26, 373, 6), // "maxNum"
QT_MOC_LITERAL(27, 380, 18), // "findStrongestInRow"
QT_MOC_LITERAL(28, 399, 8), // "findNear"
QT_MOC_LITERAL(29, 408, 4), // "type"
QT_MOC_LITERAL(30, 413, 16), // "findWeakestInAll"
QT_MOC_LITERAL(31, 430, 18), // "findStrongestInAll"
QT_MOC_LITERAL(32, 449, 9), // "damageByN"
QT_MOC_LITERAL(33, 459, 1), // "N"
QT_MOC_LITERAL(34, 461, 25), // "damageByNUnseenProtection"
QT_MOC_LITERAL(35, 487, 8), // "boostByN"
QT_MOC_LITERAL(36, 496, 16), // "addProtectionByN"
QT_MOC_LITERAL(37, 513, 10), // "lockTarget"
QT_MOC_LITERAL(38, 524, 12), // "makePowerToN"
QT_MOC_LITERAL(39, 537, 13), // "destroyTarget"
QT_MOC_LITERAL(40, 551, 9), // "eatTarget"
QT_MOC_LITERAL(41, 561, 5), // "eator"
QT_MOC_LITERAL(42, 567, 10), // "moveTarget"
QT_MOC_LITERAL(43, 578, 5), // "toRow"
QT_MOC_LITERAL(44, 584, 18), // "peekNCardsFromBase"
QT_MOC_LITERAL(45, 603, 24), // "peekSpecificCardFromBase"
QT_MOC_LITERAL(46, 628, 11), // "deployCards"
QT_MOC_LITERAL(47, 640, 4), // "unit"
QT_MOC_LITERAL(48, 645, 5), // "index"
QT_MOC_LITERAL(49, 651, 17), // "putCardBackToBase"
QT_MOC_LITERAL(50, 669, 19), // "resurrectCardToHand"
QT_MOC_LITERAL(51, 689, 2), // "id"
QT_MOC_LITERAL(52, 692, 12), // "cemeterySide"
QT_MOC_LITERAL(53, 705, 13), // "resurrectSide"
QT_MOC_LITERAL(54, 719, 18), // "resurrectCardToRow"
QT_MOC_LITERAL(55, 738, 13), // "generateNCard"
QT_MOC_LITERAL(56, 752, 7), // "_target"
QT_MOC_LITERAL(57, 760, 32), // "generateNCardWithOutChooseTarget"
QT_MOC_LITERAL(58, 793, 6), // "getRow"
QT_MOC_LITERAL(59, 800, 19), // "deployCardsFromBase"
QT_MOC_LITERAL(60, 820, 8), // "clearRow"
QT_MOC_LITERAL(61, 829, 3) // "row"

    },
    "GameField\0rowChanged\0\0rowNum\0baseChanged\0"
    "side\0cemeteryChanged\0handCardChanged\0"
    "gameUnitChangedToClient\0info\0"
    "rowChangedToClient\0baseChangedToClient\0"
    "cemeteryChangedToClient\0handCardChangedToClient\0"
    "newCardDeployed\0GameUnit*\0cardDestroyed\0"
    "gameUnitChanged\0target\0rowChangedSlot\0"
    "baseChangedSlot\0cemeteryChangedSlot\0"
    "handCardChangedSlot\0findWeakestInRow\0"
    "std::vector<GameUnit*>*\0vec\0maxNum\0"
    "findStrongestInRow\0findNear\0type\0"
    "findWeakestInAll\0findStrongestInAll\0"
    "damageByN\0N\0damageByNUnseenProtection\0"
    "boostByN\0addProtectionByN\0lockTarget\0"
    "makePowerToN\0destroyTarget\0eatTarget\0"
    "eator\0moveTarget\0toRow\0peekNCardsFromBase\0"
    "peekSpecificCardFromBase\0deployCards\0"
    "unit\0index\0putCardBackToBase\0"
    "resurrectCardToHand\0id\0cemeterySide\0"
    "resurrectSide\0resurrectCardToRow\0"
    "generateNCard\0_target\0"
    "generateNCardWithOutChooseTarget\0"
    "getRow\0deployCardsFromBase\0clearRow\0"
    "row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  254,    2, 0x06 /* Public */,
       4,    1,  257,    2, 0x06 /* Public */,
       6,    1,  260,    2, 0x06 /* Public */,
       7,    1,  263,    2, 0x06 /* Public */,
       8,    1,  266,    2, 0x06 /* Public */,
      10,    1,  269,    2, 0x06 /* Public */,
      11,    1,  272,    2, 0x06 /* Public */,
      12,    1,  275,    2, 0x06 /* Public */,
      13,    1,  278,    2, 0x06 /* Public */,
      14,    1,  281,    2, 0x06 /* Public */,
      16,    1,  284,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,  287,    2, 0x0a /* Public */,
      19,    1,  290,    2, 0x0a /* Public */,
      20,    1,  293,    2, 0x0a /* Public */,
      21,    1,  296,    2, 0x0a /* Public */,
      22,    1,  299,    2, 0x0a /* Public */,
      23,    2,  302,    2, 0x0a /* Public */,
      23,    3,  307,    2, 0x0a /* Public */,
      27,    2,  314,    2, 0x0a /* Public */,
      27,    3,  319,    2, 0x0a /* Public */,
      28,    5,  326,    2, 0x0a /* Public */,
      30,    1,  337,    2, 0x0a /* Public */,
      30,    2,  340,    2, 0x0a /* Public */,
      31,    1,  345,    2, 0x0a /* Public */,
      31,    2,  348,    2, 0x0a /* Public */,
      32,    2,  353,    2, 0x0a /* Public */,
      34,    2,  358,    2, 0x0a /* Public */,
      35,    2,  363,    2, 0x0a /* Public */,
      36,    2,  368,    2, 0x0a /* Public */,
      37,    1,  373,    2, 0x0a /* Public */,
      38,    2,  376,    2, 0x0a /* Public */,
      39,    1,  381,    2, 0x0a /* Public */,
      39,    1,  384,    2, 0x0a /* Public */,
      40,    2,  387,    2, 0x0a /* Public */,
      42,    2,  392,    2, 0x0a /* Public */,
      44,    2,  397,    2, 0x0a /* Public */,
      45,    2,  402,    2, 0x0a /* Public */,
      46,    3,  407,    2, 0x0a /* Public */,
      46,    3,  414,    2, 0x0a /* Public */,
      49,    3,  421,    2, 0x0a /* Public */,
      50,    4,  428,    2, 0x0a /* Public */,
      54,    5,  437,    2, 0x0a /* Public */,
      55,    4,  448,    2, 0x0a /* Public */,
      55,    4,  457,    2, 0x0a /* Public */,
      57,    4,  466,    2, 0x0a /* Public */,
      58,    2,  475,    2, 0x0a /* Public */,
      59,    5,  480,    2, 0x0a /* Public */,
      60,    1,  491,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   18,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,    3,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int, QMetaType::Int,   25,    3,   26,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,    3,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int, QMetaType::Int,   25,    3,   26,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int, 0x80000000 | 15, QMetaType::Int, QMetaType::Int,   25,    3,   18,   29,   26,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   26,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   26,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   33,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   33,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   33,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   33,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   33,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 15,   18,
    QMetaType::Void, 0x80000000 | 24, 0x80000000 | 15,   25,   41,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   33,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   29,    5,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int, QMetaType::Int,   47,    3,   48,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int, 0x80000000 | 15,   47,    3,   18,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int, QMetaType::Bool,   47,   29,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, QMetaType::Int,   51,   52,   53,   29,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,   51,   52,    3,   48,   29,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   51,    3,   48,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 24, QMetaType::Int,   51,    3,   56,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   51,    3,   33,    5,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int,   51,    3,   48,    5,   29,
    QMetaType::Void, 0x80000000 | 24,   61,

       0        // eod
};

void GameField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameField *_t = static_cast<GameField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->baseChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->cemeteryChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->handCardChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->gameUnitChangedToClient((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->rowChangedToClient((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 6: _t->baseChangedToClient((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 7: _t->cemeteryChangedToClient((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 8: _t->handCardChangedToClient((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 9: _t->newCardDeployed((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 10: _t->cardDestroyed((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 11: _t->gameUnitChanged((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 12: _t->rowChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->baseChangedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->cemeteryChangedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->handCardChangedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->findWeakestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->findWeakestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 18: _t->findStrongestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->findStrongestInRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 20: _t->findNear((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< GameUnit*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 21: _t->findWeakestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 22: _t->findWeakestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->findStrongestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 24: _t->findStrongestInAll((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->damageByN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->damageByNUnseenProtection((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: _t->boostByN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: _t->addProtectionByN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->lockTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 30: _t->makePowerToN((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->destroyTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
        case 32: _t->destroyTarget((*reinterpret_cast< GameUnit*(*)>(_a[1]))); break;
        case 33: _t->eatTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< GameUnit*(*)>(_a[2]))); break;
        case 34: _t->moveTarget((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->peekNCardsFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 36: _t->peekSpecificCardFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 37: _t->deployCards((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 38: _t->deployCards((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< GameUnit*(*)>(_a[3]))); break;
        case 39: _t->putCardBackToBase((*reinterpret_cast< GameUnit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 40: _t->resurrectCardToHand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 41: _t->resurrectCardToRow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 42: _t->generateNCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 43: _t->generateNCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 44: _t->generateNCardWithOutChooseTarget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 45: _t->getRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 46: _t->deployCardsFromBase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 47: _t->clearRow((*reinterpret_cast< std::vector<GameUnit*>*(*)>(_a[1]))); break;
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
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
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
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GameUnit* >(); break;
            }
            break;
        case 39:
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
            typedef void (GameField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::rowChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::baseChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::cemeteryChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::handCardChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::gameUnitChangedToClient)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::rowChangedToClient)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::baseChangedToClient)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::cemeteryChangedToClient)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::handCardChangedToClient)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(GameUnit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::newCardDeployed)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (GameField::*_t)(GameUnit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameField::cardDestroyed)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject GameField::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameField.data,
      qt_meta_data_GameField,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameField.stringdata0))
        return static_cast<void*>(const_cast< GameField*>(this));
    return QObject::qt_metacast(_clname);
}

int GameField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void GameField::rowChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameField::baseChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameField::cemeteryChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameField::handCardChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameField::gameUnitChangedToClient(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GameField::rowChangedToClient(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GameField::baseChangedToClient(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GameField::cemeteryChangedToClient(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GameField::handCardChangedToClient(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GameField::newCardDeployed(GameUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GameField::cardDestroyed(GameUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
