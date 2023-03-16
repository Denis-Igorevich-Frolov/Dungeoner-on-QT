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
    uint offsetsAndSizes[34];
    char stringdata0[25];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[15];
    char stringdata5[5];
    char stringdata6[25];
    char stringdata7[30];
    char stringdata8[28];
    char stringdata9[6];
    char stringdata10[35];
    char stringdata11[38];
    char stringdata12[7];
    char stringdata13[26];
    char stringdata14[28];
    char stringdata15[4];
    char stringdata16[4];
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
        QT_MOC_LITERAL(80, 24),  // "addRowOfCellsToInventory"
        QT_MOC_LITERAL(105, 29),  // "removeRowOfCellsFromInventory"
        QT_MOC_LITERAL(135, 27),  // "InventoryScrollAreaScrolled"
        QT_MOC_LITERAL(163, 5),  // "value"
        QT_MOC_LITERAL(169, 34),  // "on_InventoryScrollBar_valueCh..."
        QT_MOC_LITERAL(204, 37),  // "on_InventoryScrollBar_actionT..."
        QT_MOC_LITERAL(242, 6),  // "action"
        QT_MOC_LITERAL(249, 25),  // "inventoryScrollingStarted"
        QT_MOC_LITERAL(275, 27),  // "checkingInventorySizeChange"
        QT_MOC_LITERAL(303, 3),  // "col"
        QT_MOC_LITERAL(307, 3)   // "row"
    },
    "CharacterWindowInventory",
    "RemoveTooltip",
    "",
    "moveCellToEquipment",
    "InventoryCell*",
    "cell",
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
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    1,   69,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   72,    2, 0x0a,    4 /* Public */,
       7,    0,   73,    2, 0x0a,    5 /* Public */,
       8,    1,   74,    2, 0x08,    6 /* Private */,
      10,    1,   77,    2, 0x08,    8 /* Private */,
      11,    1,   80,    2, 0x08,   10 /* Private */,
      13,    0,   83,    2, 0x08,   12 /* Private */,
      14,    2,   84,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,

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
        case 2: _t->addRowOfCellsToInventory(); break;
        case 3: _t->removeRowOfCellsFromInventory(); break;
        case 4: _t->InventoryScrollAreaScrolled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_InventoryScrollBar_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_InventoryScrollBar_actionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->inventoryScrollingStarted(); break;
        case 8: _t->checkingInventorySizeChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
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
    }
}

const QMetaObject CharacterWindowInventory::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CharacterWindowInventory.offsetsAndSizes,
    qt_meta_data_CharacterWindowInventory,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CharacterWindowInventory_t
, QtPrivate::TypeAndForceComplete<CharacterWindowInventory, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
