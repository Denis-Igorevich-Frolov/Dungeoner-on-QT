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
    uint offsetsAndSizes[40];
    char stringdata0[19];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[5];
    char stringdata5[30];
    char stringdata6[15];
    char stringdata7[18];
    char stringdata8[12];
    char stringdata9[13];
    char stringdata10[20];
    char stringdata11[20];
    char stringdata12[19];
    char stringdata13[18];
    char stringdata14[12];
    char stringdata15[10];
    char stringdata16[10];
    char stringdata17[27];
    char stringdata18[23];
    char stringdata19[28];
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
        QT_MOC_LITERAL(62, 29),  // "reviseItemPositionInEquipment"
        QT_MOC_LITERAL(92, 14),  // "moveItemAnyway"
        QT_MOC_LITERAL(107, 17),  // "lockOccupiedCells"
        QT_MOC_LITERAL(125, 11),  // "Item::Slots"
        QT_MOC_LITERAL(137, 12),  // "acceptedSlot"
        QT_MOC_LITERAL(150, 19),  // "unlockOccupiedCells"
        QT_MOC_LITERAL(170, 19),  // "checkingLockedCells"
        QT_MOC_LITERAL(190, 18),  // "QList<Item::Slots>"
        QT_MOC_LITERAL(209, 17),  // "occupiedCellSlots"
        QT_MOC_LITERAL(227, 11),  // "dragStarted"
        QT_MOC_LITERAL(239, 9),  // "cellSlots"
        QT_MOC_LITERAL(249, 9),  // "dragEnded"
        QT_MOC_LITERAL(259, 26),  // "on_OverArmorButton_clicked"
        QT_MOC_LITERAL(286, 22),  // "on_ArmorButton_clicked"
        QT_MOC_LITERAL(309, 27)   // "on_UnderArmorButton_clicked"
    },
    "CharacterEquipment",
    "moveCellFromEquipment",
    "",
    "InventoryCell*",
    "cell",
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
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       5,    2,   83,    2, 0x06,    3 /* Public */,
       5,    1,   88,    2, 0x26,    6 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   91,    2, 0x0a,    8 /* Public */,
      10,    1,   96,    2, 0x0a,   11 /* Public */,
      11,    1,   99,    2, 0x0a,   13 /* Public */,
      14,    1,  102,    2, 0x0a,   15 /* Public */,
      16,    0,  105,    2, 0x0a,   17 /* Public */,
      17,    0,  106,    2, 0x08,   18 /* Private */,
      18,    0,  107,    2, 0x08,   19 /* Private */,
      19,    0,  108,    2, 0x08,   20 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    6,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    4,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   15,
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
        case 0: _t->moveCellFromEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 1: _t->reviseItemPositionInEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->reviseItemPositionInEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 3: _t->lockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Item::Slots>>(_a[2]))); break;
        case 4: _t->unlockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 5: { bool _r = _t->checkingLockedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->dragStarted((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1]))); break;
        case 7: _t->dragEnded(); break;
        case 8: _t->on_OverArmorButton_clicked(); break;
        case 9: _t->on_ArmorButton_clicked(); break;
        case 10: _t->on_UnderArmorButton_clicked(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CharacterEquipment::*)(InventoryCell * );
            if (_t _q_method = &CharacterEquipment::moveCellFromEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CharacterEquipment::*)(InventoryCell * , bool );
            if (_t _q_method = &CharacterEquipment::reviseItemPositionInEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
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
, QtPrivate::TypeAndForceComplete<CharacterEquipment, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<Item::Slots, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CharacterEquipment::moveCellFromEquipment(InventoryCell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CharacterEquipment::reviseItemPositionInEquipment(InventoryCell * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
