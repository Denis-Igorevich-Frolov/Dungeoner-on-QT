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
    uint offsetsAndSizes[26];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[20];
    char stringdata6[15];
    char stringdata7[5];
    char stringdata8[18];
    char stringdata9[20];
    char stringdata10[18];
    char stringdata11[20];
    char stringdata12[20];
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
        QT_MOC_LITERAL(77, 17),  // "lockOccupiedCells"
        QT_MOC_LITERAL(95, 19),  // "QList<Item::Slots>*"
        QT_MOC_LITERAL(115, 17),  // "occupiedCellSlots"
        QT_MOC_LITERAL(133, 19),  // "unlockOccupiedCells"
        QT_MOC_LITERAL(153, 19)   // "moveItemToEquipment"
    },
    "InventoryCell",
    "itemIsDropped",
    "",
    "col",
    "row",
    "moveCellToEquipment",
    "InventoryCell*",
    "cell",
    "lockOccupiedCells",
    "QList<Item::Slots>*",
    "occupiedCellSlots",
    "unlockOccupiedCells",
    "moveItemToEquipment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InventoryCell[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,
       5,    1,   49,    2, 0x06,    4 /* Public */,
       8,    1,   52,    2, 0x06,    6 /* Public */,
      11,    1,   55,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   58,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
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
        case 1: _t->moveCellToEquipment((*reinterpret_cast< std::add_pointer_t<InventoryCell*>>(_a[1]))); break;
        case 2: _t->lockOccupiedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>*>>(_a[1]))); break;
        case 3: _t->unlockOccupiedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>*>>(_a[1]))); break;
        case 4: _t->moveItemToEquipment(); break;
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
            using _t = void (InventoryCell::*)(InventoryCell * );
            if (_t _q_method = &InventoryCell::moveCellToEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(QVector<Item::Slots> * );
            if (_t _q_method = &InventoryCell::lockOccupiedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (InventoryCell::*)(QVector<Item::Slots> * );
            if (_t _q_method = &InventoryCell::unlockOccupiedCells; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
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
, QtPrivate::TypeAndForceComplete<InventoryCell, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots> *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots> *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


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

// SIGNAL 0
void InventoryCell::itemIsDropped(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InventoryCell::moveCellToEquipment(InventoryCell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InventoryCell::lockOccupiedCells(QVector<Item::Slots> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InventoryCell::unlockOccupiedCells(QVector<Item::Slots> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
