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
    uint offsetsAndSizes[24];
    char stringdata0[19];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[5];
    char stringdata5[18];
    char stringdata6[20];
    char stringdata7[18];
    char stringdata8[20];
    char stringdata9[27];
    char stringdata10[23];
    char stringdata11[28];
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
        QT_MOC_LITERAL(62, 17),  // "lockOccupiedCells"
        QT_MOC_LITERAL(80, 19),  // "QList<Item::Slots>*"
        QT_MOC_LITERAL(100, 17),  // "occupiedCellSlots"
        QT_MOC_LITERAL(118, 19),  // "unlockOccupiedCells"
        QT_MOC_LITERAL(138, 26),  // "on_OverArmorButton_clicked"
        QT_MOC_LITERAL(165, 22),  // "on_ArmorButton_clicked"
        QT_MOC_LITERAL(188, 27)   // "on_UnderArmorButton_clicked"
    },
    "CharacterEquipment",
    "moveCellFromEquipment",
    "",
    "InventoryCell*",
    "cell",
    "lockOccupiedCells",
    "QList<Item::Slots>*",
    "occupiedCellSlots",
    "unlockOccupiedCells",
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
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   53,    2, 0x0a,    3 /* Public */,
       8,    1,   56,    2, 0x0a,    5 /* Public */,
       9,    0,   59,    2, 0x08,    7 /* Private */,
      10,    0,   60,    2, 0x08,    8 /* Private */,
      11,    0,   61,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
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
        case 1: _t->lockOccupiedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>*>>(_a[1]))); break;
        case 2: _t->unlockOccupiedCells((*reinterpret_cast< std::add_pointer_t<QList<Item::Slots>*>>(_a[1]))); break;
        case 3: _t->on_OverArmorButton_clicked(); break;
        case 4: _t->on_ArmorButton_clicked(); break;
        case 5: _t->on_UnderArmorButton_clicked(); break;
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
    }
}

const QMetaObject CharacterEquipment::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CharacterEquipment.offsetsAndSizes,
    qt_meta_data_CharacterEquipment,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CharacterEquipment_t
, QtPrivate::TypeAndForceComplete<CharacterEquipment, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<InventoryCell *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots> *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Item::Slots> *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CharacterEquipment::moveCellFromEquipment(InventoryCell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
