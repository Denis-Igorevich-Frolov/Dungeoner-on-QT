/****************************************************************************
** Meta object code from reading C++ file 'item.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/Item/item.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Item_t {
    uint offsetsAndSizes[26];
    char stringdata0[5];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[14];
    char stringdata5[22];
    char stringdata6[22];
    char stringdata7[23];
    char stringdata8[25];
    char stringdata9[25];
    char stringdata10[25];
    char stringdata11[25];
    char stringdata12[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Item_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Item_t qt_meta_stringdata_Item = {
    {
        QT_MOC_LITERAL(0, 4),  // "Item"
        QT_MOC_LITERAL(5, 19),  // "moveItemToEquipment"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 12),  // "styleRemoved"
        QT_MOC_LITERAL(39, 13),  // "styleAssigned"
        QT_MOC_LITERAL(53, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(75, 21),  // "on_pushButton_pressed"
        QT_MOC_LITERAL(97, 22),  // "on_pushButton_released"
        QT_MOC_LITERAL(120, 24),  // "on_StyleButton_1_clicked"
        QT_MOC_LITERAL(145, 24),  // "on_StyleButton_2_clicked"
        QT_MOC_LITERAL(170, 24),  // "on_StyleButton_3_clicked"
        QT_MOC_LITERAL(195, 24),  // "on_StyleButton_4_clicked"
        QT_MOC_LITERAL(220, 24)   // "on_StyleButton_5_clicked"
    },
    "Item",
    "moveItemToEquipment",
    "",
    "styleRemoved",
    "styleAssigned",
    "on_pushButton_clicked",
    "on_pushButton_pressed",
    "on_pushButton_released",
    "on_StyleButton_1_clicked",
    "on_StyleButton_2_clicked",
    "on_StyleButton_3_clicked",
    "on_StyleButton_4_clicked",
    "on_StyleButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Item[] = {

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
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,
       4,    0,   82,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Item *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveItemToEquipment(); break;
        case 1: _t->styleRemoved(); break;
        case 2: _t->styleAssigned(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_pressed(); break;
        case 5: _t->on_pushButton_released(); break;
        case 6: _t->on_StyleButton_1_clicked(); break;
        case 7: _t->on_StyleButton_2_clicked(); break;
        case 8: _t->on_StyleButton_3_clicked(); break;
        case 9: _t->on_StyleButton_4_clicked(); break;
        case 10: _t->on_StyleButton_5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Item::*)();
            if (_t _q_method = &Item::moveItemToEquipment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Item::*)();
            if (_t _q_method = &Item::styleRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Item::*)();
            if (_t _q_method = &Item::styleAssigned; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Item::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Item.offsetsAndSizes,
    qt_meta_data_Item,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Item_t
, QtPrivate::TypeAndForceComplete<Item, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Item::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Item.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Item::moveItemToEquipment()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Item::styleRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Item::styleAssigned()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
