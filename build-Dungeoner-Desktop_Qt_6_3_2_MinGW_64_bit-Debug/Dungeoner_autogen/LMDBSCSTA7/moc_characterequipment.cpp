/****************************************************************************
** Meta object code from reading C++ file 'characterequipment.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/CharacterEquipment/characterequipment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'characterequipment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CharacterEquipment_t {
    uint offsetsAndSizes[48];
    char stringdata0[19];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[5];
    char stringdata5[10];
    char stringdata6[30];
    char stringdata7[15];
    char stringdata8[18];
    char stringdata9[12];
    char stringdata10[13];
    char stringdata11[20];
    char stringdata12[20];
    char stringdata13[19];
    char stringdata14[18];
    char stringdata15[12];
    char stringdata16[10];
    char stringdata17[10];
    char stringdata18[31];
    char stringdata19[30];
    char stringdata20[17];
    char stringdata21[27];
    char stringdata22[23];
    char stringdata23[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CharacterEquipment_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_CharacterEquipment_t qt_meta_stringdata_CharacterEquipment = {
    {
        QT_MOC_LITERAL(0, 18),  // "CharacterEquipment"
        QT_MOC_LITERAL(19, 21),  // "moveCellFromEquipment"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 14),  // "InventoryCell*"
        QT_MOC_LITERAL(57, 4),  // "cell"
        QT_MOC_LITERAL(62, 9),  // "playSound"
        QT_MOC_LITERAL(72, 29),  // "reviseItemPositionInEquipment"
        QT_MOC_LITERAL(102, 14),  // "moveItemAnyway"
        QT_MOC_LITERAL(117, 17),  // "lockOccupiedCells"
        QT_MOC_LITERAL(135, 11),  // "Item::Slots"
        QT_MOC_LITERAL(147, 12),  // "acceptedSlot"
        QT_MOC_LITERAL(160, 19),  // "unlockOccupiedCells"
        QT_MOC_LITERAL(180, 19),  // "checkingLockedCells"
        QT_MOC_LITERAL(200, 18),  // "QList<Item::Slots>"
        QT_MOC_LITERAL(219, 17),  // "occupiedCellSlots"
        QT_MOC_LITERAL(237, 11),  // "dragStarted"
        QT_MOC_LITERAL(249, 9),  // "cellSlots"
        QT_MOC_LITERAL(259, 9),  // "dragEnded"
        QT_MOC_LITERAL(269, 30),  // "takeTwoHandedGripRightHandItem"
        QT_MOC_LITERAL(300, 29),  // "takeTwoHandedGripLeftHandItem"
        QT_MOC_LITERAL(330, 16),  // "useOneHandedGrip"
        QT_MOC_LITERAL(347, 26),  // "on_OverArmorButton_clicked"
        QT_MOC_LITERAL(374, 22),  // "on_ArmorButton_clicked"
        QT_MOC_LITERAL(397, 27)   // "on_UnderArmorButton_clicked"
    },
    "CharacterEquipment",
    "moveCellFromEquipment",
    "",
    "InventoryCell*",
    "cell",
    "playSound",
    "reviseItemPositionInEquipment",
    "moveItemAnyway",
    "lockOccupiedCells",
    "Item::Slots",
    "acceptedSlot",
    "unlockOccupiedCells",
    "checkingLockedCells",
    "QList<Item::Slots>",
    "occupiedCellSlots",
    "dragStarted",
    "cellSlots",
    "dragEnded",
    "takeTwoHandedGripRightHandItem",
    "takeTwoHandedGripLeftHandItem",
    "useOneHandedGrip",
    "on_OverArmorButton_clicked",
    "on_ArmorButton_clicked",
    "on_UnderArmorButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterEquipment[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  104,    2, 0x06,    1 /* Public */,
       1,    1,  109,    2, 0x26,    4 /* Public | MethodCloned */,
       6,    2,  112,    2, 0x06,    6 /* Public */,
       6,    1,  117,    2, 0x26,    9 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,  120,    2, 0x0a,   11 /* Public */,
      11,    1,  125,    2, 0x0a,   14 /* Public */,
      12,    1,  128,    2, 0x0a,   16 /* Public */,
      15,    1,  131,    2, 0x0a,   18 /* Public */,
      17,    0,  134,    2, 0x0a,   20 /* Public */,
      18,    0,  135,    2, 0x0a,   21 /* Public */,
      19,    0,  136,    2, 0x0a,   22 /* Public */,
      20,    0,  137,    2, 0x0a,   23 /* Public */,
      21,    0,  138,    2, 0x08,   24 /* Private */,
      22,    0,  139,    2, 0x08,   25 /* Private */,
      23,    0,  140,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    7,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    4,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CharacterEquipment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacterEquipment *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveCellFromEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->moveCellFromEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 2: _t->reviseItemPositionInEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 3: _t->reviseItemPositionInEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 4: _t->lockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Item::Slots>>(_a[2]))); break;
        case 5: _t->unlockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 6: { bool _r = _t->checkingLockedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->dragStarted((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1]))); break;
        case 8: _t->dragEnded(); break;
        case 9: _t->takeTwoHandedGripRightHandItem(); break;
        case 10: _t->takeTwoHandedGripLeftHandItem(); break;
        case 11: _t->useOneHandedGrip(); break;
        case 12: _t->on_OverArmorButton_clicked(); break;
        case 13: _t->on_ArmorButton_clicked(); break;
        case 14: _t->on_UnderArmorButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< InventoryCell* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< InventoryCell* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< InventoryCell* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< InventoryCell* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< InventoryCell* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< InventoryCell* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CharacterEquipment::*)(InventoryCell * , bool );
            if (_t _q_method = &CharacterEquipment::moveCellFromEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CharacterEquipment::*)(InventoryCell * , bool );
            if (_t _q_method = &CharacterEquipment::reviseItemPositionInEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CharacterEquipment::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CharacterEquipment.offsetsAndSizes,
    qt_meta_data_CharacterEquipment,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CharacterEquipment_t
, QtPrivate::TypeAndForceComplete<CharacterEquipment, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<Item::Slots, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CharacterEquipment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacterEquipment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharacterEquipment.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CharacterEquipment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CharacterEquipment::moveCellFromEquipment(InventoryCell * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void CharacterEquipment::reviseItemPositionInEquipment(InventoryCell * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
