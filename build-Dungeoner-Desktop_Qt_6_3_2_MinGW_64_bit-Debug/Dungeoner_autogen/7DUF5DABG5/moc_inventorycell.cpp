/****************************************************************************
** Meta object code from reading C++ file 'inventorycell.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/InventoryCell/inventorycell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inventorycell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InventoryCell_t {
    uint offsetsAndSizes[46];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[20];
    char stringdata6[15];
    char stringdata7[5];
    char stringdata8[15];
    char stringdata9[30];
    char stringdata10[18];
    char stringdata11[12];
    char stringdata12[13];
    char stringdata13[20];
    char stringdata14[17];
    char stringdata15[19];
    char stringdata16[18];
    char stringdata17[12];
    char stringdata18[10];
    char stringdata19[10];
    char stringdata20[20];
    char stringdata21[13];
    char stringdata22[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_InventoryCell_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_InventoryCell_t qt_meta_stringdata_InventoryCell = {
    {
        QT_MOC_LITERAL(0, 13),  // "InventoryCell"
        QT_MOC_LITERAL(14, 13),  // "itemIsDropped"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 3),  // "col"
        QT_MOC_LITERAL(33, 3),  // "row"
        QT_MOC_LITERAL(37, 19),  // "moveCellToEquipment"
        QT_MOC_LITERAL(57, 14),  // "InventoryCell*"
        QT_MOC_LITERAL(72, 4),  // "cell"
        QT_MOC_LITERAL(77, 14),  // "moveItemAnyway"
        QT_MOC_LITERAL(92, 29),  // "reviseItemPositionInEquipment"
        QT_MOC_LITERAL(122, 17),  // "lockOccupiedCells"
        QT_MOC_LITERAL(140, 11),  // "Item::Slots"
        QT_MOC_LITERAL(152, 12),  // "acceptedSlot"
        QT_MOC_LITERAL(165, 19),  // "unlockOccupiedCells"
        QT_MOC_LITERAL(185, 16),  // "checkLockedCells"
        QT_MOC_LITERAL(202, 18),  // "QList<Item::Slots>"
        QT_MOC_LITERAL(221, 17),  // "occupiedCellSlots"
        QT_MOC_LITERAL(239, 11),  // "dragStarted"
        QT_MOC_LITERAL(251, 9),  // "cellSlots"
        QT_MOC_LITERAL(261, 9),  // "dragEnded"
        QT_MOC_LITERAL(271, 19),  // "moveItemToEquipment"
        QT_MOC_LITERAL(291, 12),  // "styleRemoved"
        QT_MOC_LITERAL(304, 13)   // "styleAssigned"
    },
    "InventoryCell",
    "itemIsDropped",
    "",
    "col",
    "row",
    "moveCellToEquipment",
    "InventoryCell*",
    "cell",
    "moveItemAnyway",
    "reviseItemPositionInEquipment",
    "lockOccupiedCells",
    "Item::Slots",
    "acceptedSlot",
    "unlockOccupiedCells",
    "checkLockedCells",
    "QList<Item::Slots>",
    "occupiedCellSlots",
    "dragStarted",
    "cellSlots",
    "dragEnded",
    "moveItemToEquipment",
    "styleRemoved",
    "styleAssigned"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InventoryCell[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   92,    2, 0x06,    1 /* Public */,
       5,    2,   97,    2, 0x06,    4 /* Public */,
       5,    1,  102,    2, 0x26,    7 /* Public | MethodCloned */,
       9,    2,  105,    2, 0x06,    9 /* Public */,
       9,    1,  110,    2, 0x26,   12 /* Public | MethodCloned */,
      10,    2,  113,    2, 0x06,   14 /* Public */,
      13,    1,  118,    2, 0x06,   17 /* Public */,
      14,    1,  121,    2, 0x06,   19 /* Public */,
      17,    1,  124,    2, 0x06,   21 /* Public */,
      19,    0,  127,    2, 0x06,   23 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    0,  128,    2, 0x08,   24 /* Private */,
      21,    0,  129,    2, 0x08,   25 /* Private */,
      22,    0,  130,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 11,    7,   12,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Bool, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   18,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InventoryCell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InventoryCell *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemIsDropped((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->moveCellToEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->moveCellToEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 3: _t->reviseItemPositionInEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->reviseItemPositionInEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 5: _t->lockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Item::Slots>>(_a[2]))); break;
        case 6: _t->unlockOccupiedCells((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 7: { bool _r = _t->checkLockedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->dragStarted((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>>>(_a[1]))); break;
        case 9: _t->dragEnded(); break;
        case 10: _t->moveItemToEquipment(); break;
        case 11: _t->styleRemoved(); break;
        case 12: _t->styleAssigned(); break;
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
        case 6:
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
            using _t = void (InventoryCell::*)(int , int );
            if (_t _q_method = &InventoryCell::itemIsDropped; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(InventoryCell * , bool );
            if (_t _q_method = &InventoryCell::moveCellToEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(InventoryCell * , bool );
            if (_t _q_method = &InventoryCell::reviseItemPositionInEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(InventoryCell * , Item::Slots );
            if (_t _q_method = &InventoryCell::lockOccupiedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(InventoryCell * );
            if (_t _q_method = &InventoryCell::unlockOccupiedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = bool (InventoryCell::*)(QVector<Item::Slots> );
            if (_t _q_method = &InventoryCell::checkLockedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(QVector<Item::Slots> );
            if (_t _q_method = &InventoryCell::dragStarted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)();
            if (_t _q_method = &InventoryCell::dragEnded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject InventoryCell::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_InventoryCell.offsetsAndSizes,
    qt_meta_data_InventoryCell,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_InventoryCell_t
, QtPrivate::TypeAndForceComplete<InventoryCell, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<Item::Slots, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *InventoryCell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InventoryCell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InventoryCell.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InventoryCell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void InventoryCell::itemIsDropped(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InventoryCell::moveCellToEquipment(InventoryCell * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void InventoryCell::reviseItemPositionInEquipment(InventoryCell * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void InventoryCell::lockOccupiedCells(InventoryCell * _t1, Item::Slots _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void InventoryCell::unlockOccupiedCells(InventoryCell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
bool InventoryCell::checkLockedCells(QVector<Item::Slots> _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
    return _t0;
}

// SIGNAL 8
void InventoryCell::dragStarted(QVector<Item::Slots> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void InventoryCell::dragEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
