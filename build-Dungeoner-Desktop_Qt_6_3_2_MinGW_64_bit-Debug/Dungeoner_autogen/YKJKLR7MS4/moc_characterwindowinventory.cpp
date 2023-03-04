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
    uint offsetsAndSizes[20];
    char stringdata0[25];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[30];
    char stringdata4[28];
    char stringdata5[6];
    char stringdata6[35];
    char stringdata7[38];
    char stringdata8[7];
    char stringdata9[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CharacterWindowInventory_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_CharacterWindowInventory_t qt_meta_stringdata_CharacterWindowInventory = {
    {
        QT_MOC_LITERAL(0, 24),  // "CharacterWindowInventory"
        QT_MOC_LITERAL(25, 24),  // "addRowOfCellsToInventory"
        QT_MOC_LITERAL(50, 0),  // ""
        QT_MOC_LITERAL(51, 29),  // "removeRowOfCellsFromInventory"
        QT_MOC_LITERAL(81, 27),  // "InventoryScrollAreaScrolled"
        QT_MOC_LITERAL(109, 5),  // "value"
        QT_MOC_LITERAL(115, 34),  // "on_InventoryScrollBar_valueCh..."
        QT_MOC_LITERAL(150, 37),  // "on_InventoryScrollBar_actionT..."
        QT_MOC_LITERAL(188, 6),  // "action"
        QT_MOC_LITERAL(195, 25)   // "inventoryScrollingStarted"
    },
    "CharacterWindowInventory",
    "addRowOfCellsToInventory",
    "",
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
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    1,   52,    2, 0x08,    3 /* Private */,
       6,    1,   55,    2, 0x08,    5 /* Private */,
       7,    1,   58,    2, 0x08,    7 /* Private */,
       9,    0,   61,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void CharacterWindowInventory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacterWindowInventory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addRowOfCellsToInventory(); break;
        case 1: _t->removeRowOfCellsFromInventory(); break;
        case 2: _t->InventoryScrollAreaScrolled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_InventoryScrollBar_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_InventoryScrollBar_actionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->inventoryScrollingStarted(); break;
        default: ;
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
, QtPrivate::TypeAndForceComplete<CharacterWindowInventory, std::true_type>
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
