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
    uint offsetsAndSizes[22];
    char stringdata0[25];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[30];
    char stringdata5[28];
    char stringdata6[6];
    char stringdata7[35];
    char stringdata8[38];
    char stringdata9[7];
    char stringdata10[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CharacterWindowInventory_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_CharacterWindowInventory_t qt_meta_stringdata_CharacterWindowInventory = {
    {
        QT_MOC_LITERAL(0, 24),  // "CharacterWindowInventory"
        QT_MOC_LITERAL(25, 13),  // "RemoveTooltip"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 24),  // "addRowOfCellsToInventory"
        QT_MOC_LITERAL(65, 29),  // "removeRowOfCellsFromInventory"
        QT_MOC_LITERAL(95, 27),  // "InventoryScrollAreaScrolled"
        QT_MOC_LITERAL(123, 5),  // "value"
        QT_MOC_LITERAL(129, 34),  // "on_InventoryScrollBar_valueCh..."
        QT_MOC_LITERAL(164, 37),  // "on_InventoryScrollBar_actionT..."
        QT_MOC_LITERAL(202, 6),  // "action"
        QT_MOC_LITERAL(209, 25)   // "inventoryScrollingStarted"
    },
    "CharacterWindowInventory",
    "RemoveTooltip",
    "",
    "addRowOfCellsToInventory",
    "removeRowOfCellsFromInventory",
    "InventoryScrollAreaScrolled",
    "value",
    "on_InventoryScrollBar_valueChanged",
    "on_InventoryScrollBar_actionTriggered",
    "action",
    "inventoryScrollingStarted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterWindowInventory[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    0,   58,    2, 0x0a,    3 /* Public */,
       5,    1,   59,    2, 0x08,    4 /* Private */,
       7,    1,   62,    2, 0x08,    6 /* Private */,
       8,    1,   65,    2, 0x08,    8 /* Private */,
      10,    0,   68,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void CharacterWindowInventory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacterWindowInventory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RemoveTooltip(); break;
        case 1: _t->addRowOfCellsToInventory(); break;
        case 2: _t->removeRowOfCellsFromInventory(); break;
        case 3: _t->InventoryScrollAreaScrolled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_InventoryScrollBar_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_InventoryScrollBar_actionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->inventoryScrollingStarted(); break;
        default: ;
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
    }
}

const QMetaObject CharacterWindowInventory::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CharacterWindowInventory.offsetsAndSizes,
    qt_meta_data_CharacterWindowInventory,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CharacterWindowInventory_t
, QtPrivate::TypeAndForceComplete<CharacterWindowInventory, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CharacterWindowInventory::RemoveTooltip()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
