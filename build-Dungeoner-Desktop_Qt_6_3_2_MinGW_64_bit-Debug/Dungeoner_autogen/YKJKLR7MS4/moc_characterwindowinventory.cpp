/****************************************************************************
** Meta object code from reading C++ file 'characterwindowinventory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/Inventories/CharacterWindowInventory/characterwindowinventory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'characterwindowinventory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CharacterWindowInventory_t {
    uint offsetsAndSizes[48];
    char stringdata0[25];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[15];
    char stringdata5[5];
    char stringdata6[18];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[20];
    char stringdata10[17];
    char stringdata11[19];
    char stringdata12[18];
    char stringdata13[25];
    char stringdata14[30];
    char stringdata15[28];
    char stringdata16[6];
    char stringdata17[35];
    char stringdata18[38];
    char stringdata19[7];
    char stringdata20[26];
    char stringdata21[28];
    char stringdata22[4];
    char stringdata23[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CharacterWindowInventory_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_CharacterWindowInventory_t qt_meta_stringdata_CharacterWindowInventory = {
    {
        QT_MOC_LITERAL(0, 24),  // "CharacterWindowInventory"
        QT_MOC_LITERAL(25, 13),  // "RemoveTooltip"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 19),  // "moveCellToEquipment"
        QT_MOC_LITERAL(60, 14),  // "InventoryCell*"
        QT_MOC_LITERAL(75, 4),  // "cell"
        QT_MOC_LITERAL(80, 17),  // "lockOccupiedCells"
        QT_MOC_LITERAL(98, 11),  // "Item::Slots"
        QT_MOC_LITERAL(110, 12),  // "acceptedSlot"
        QT_MOC_LITERAL(123, 19),  // "unlockOccupiedCells"
        QT_MOC_LITERAL(143, 16),  // "checkLockedCells"
        QT_MOC_LITERAL(160, 18),  // "QList<Item::Slots>"
        QT_MOC_LITERAL(179, 17),  // "occupiedCellSlots"
        QT_MOC_LITERAL(197, 24),  // "addRowOfCellsToInventory"
        QT_MOC_LITERAL(222, 29),  // "removeRowOfCellsFromInventory"
        QT_MOC_LITERAL(252, 27),  // "InventoryScrollAreaScrolled"
        QT_MOC_LITERAL(280, 5),  // "value"
        QT_MOC_LITERAL(286, 34),  // "on_InventoryScrollBar_valueCh..."
        QT_MOC_LITERAL(321, 37),  // "on_InventoryScrollBar_actionT..."
        QT_MOC_LITERAL(359, 6),  // "action"
        QT_MOC_LITERAL(366, 25),  // "inventoryScrollingStarted"
        QT_MOC_LITERAL(392, 27),  // "checkingInventorySizeChange"
        QT_MOC_LITERAL(420, 3),  // "col"
        QT_MOC_LITERAL(424, 3)   // "row"
    },
    "CharacterWindowInventory",
    "RemoveTooltip",
    "",
    "moveCellToEquipment",
    "InventoryCell*",
    "cell",
    "lockOccupiedCells",
    "Item::Slots",
    "acceptedSlot",
    "unlockOccupiedCells",
    "checkLockedCells",
    "QList<Item::Slots>",
    "occupiedCellSlots",
    "addRowOfCellsToInventory",
    "removeRowOfCellsFromInventory",
    "InventoryScrollAreaScrolled",
    "value",
    "on_InventoryScrollBar_valueChanged",
    "on_InventoryScrollBar_actionTriggered",
    "action",
    "inventoryScrollingStarted",
    "checkingInventorySizeChange",
    "col",
    "row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterWindowInventory[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    1,   87,    2, 0x06,    2 /* Public */,
       6,    2,   90,    2, 0x06,    4 /* Public */,
       9,    1,   95,    2, 0x06,    7 /* Public */,
      10,    1,   98,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,  101,    2, 0x0a,   11 /* Public */,
      14,    0,  102,    2, 0x0a,   12 /* Public */,
      15,    1,  103,    2, 0x08,   13 /* Private */,
      17,    1,  106,    2, 0x08,   15 /* Private */,
      18,    1,  109,    2, 0x08,   17 /* Private */,
      20,    0,  112,    2, 0x08,   19 /* Private */,
      21,    2,  113,    2, 0x08,   20 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    5,    8,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Bool, 0x80000000 | 11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,

       0        // eod
};

void CharacterWindowInventory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacterWindowInventory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RemoveTooltip(); break;
        case 1: _t->moveCellToEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 2: _t->lockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Item::Slots>>(_a[2]))); break;
        case 3: _t->unlockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 4: { bool _r = _t->checkLockedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->addRowOfCellsToInventory(); break;
        case 6: _t->removeRowOfCellsFromInventory(); break;
        case 7: _t->InventoryScrollAreaScrolled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_InventoryScrollBar_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_InventoryScrollBar_actionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->inventoryScrollingStarted(); break;
        case 11: _t->checkingInventorySizeChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CharacterWindowInventory::*)();
            if (_t _q_method = &CharacterWindowInventory::RemoveTooltip; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CharacterWindowInventory::*)(InventoryCell * );
            if (_t _q_method = &CharacterWindowInventory::moveCellToEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CharacterWindowInventory::*)(InventoryCell * , Item::Slots );
            if (_t _q_method = &CharacterWindowInventory::lockOccupiedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CharacterWindowInventory::*)(InventoryCell * );
            if (_t _q_method = &CharacterWindowInventory::unlockOccupiedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = bool (CharacterWindowInventory::*)(QVector<Item::Slots> );
            if (_t _q_method = &CharacterWindowInventory::checkLockedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CharacterWindowInventory::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CharacterWindowInventory.offsetsAndSizes,
    qt_meta_data_CharacterWindowInventory,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CharacterWindowInventory_t
, QtPrivate::TypeAndForceComplete<CharacterWindowInventory, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<Item::Slots, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CharacterWindowInventory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacterWindowInventory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharacterWindowInventory.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "AbstractInventory"))
        return static_cast< AbstractInventory*>(this);
    return QWidget::qt_metacast(_clname);
}

int CharacterWindowInventory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CharacterWindowInventory::RemoveTooltip()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CharacterWindowInventory::moveCellToEquipment(InventoryCell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CharacterWindowInventory::lockOccupiedCells(InventoryCell * _t1, Item::Slots _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CharacterWindowInventory::unlockOccupiedCells(InventoryCell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
bool CharacterWindowInventory::checkLockedCells(QVector<Item::Slots> _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
