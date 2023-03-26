/****************************************************************************
** Meta object code from reading C++ file 'weapongripbutton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/WeaponGripButton/weapongripbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapongripbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeaponGripButton_t {
    uint offsetsAndSizes[16];
    char stringdata0[17];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[30];
    char stringdata4[17];
    char stringdata5[15];
    char stringdata6[22];
    char stringdata7[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WeaponGripButton_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_WeaponGripButton_t qt_meta_stringdata_WeaponGripButton = {
    {
        QT_MOC_LITERAL(0, 16),  // "WeaponGripButton"
        QT_MOC_LITERAL(17, 30),  // "takeTwoHandedGripRightHandItem"
        QT_MOC_LITERAL(48, 0),  // ""
        QT_MOC_LITERAL(49, 29),  // "takeTwoHandedGripLeftHandItem"
        QT_MOC_LITERAL(79, 16),  // "useOneHandedGrip"
        QT_MOC_LITERAL(96, 14),  // "checkFreeHands"
        QT_MOC_LITERAL(111, 21),  // "on_GripButton_toggled"
        QT_MOC_LITERAL(133, 7)   // "checked"
    },
    "WeaponGripButton",
    "takeTwoHandedGripRightHandItem",
    "",
    "takeTwoHandedGripLeftHandItem",
    "useOneHandedGrip",
    "checkFreeHands",
    "on_GripButton_toggled",
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeaponGripButton[] = {

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
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,
       4,    0,   46,    2, 0x06,    3 /* Public */,
       5,    0,   47,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   48,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void WeaponGripButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WeaponGripButton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->takeTwoHandedGripRightHandItem(); break;
        case 1: _t->takeTwoHandedGripLeftHandItem(); break;
        case 2: _t->useOneHandedGrip(); break;
        case 3: { bool _r = _t->checkFreeHands();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_GripButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WeaponGripButton::*)();
            if (_t _q_method = &WeaponGripButton::takeTwoHandedGripRightHandItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WeaponGripButton::*)();
            if (_t _q_method = &WeaponGripButton::takeTwoHandedGripLeftHandItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WeaponGripButton::*)();
            if (_t _q_method = &WeaponGripButton::useOneHandedGrip; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = bool (WeaponGripButton::*)();
            if (_t _q_method = &WeaponGripButton::checkFreeHands; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject WeaponGripButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WeaponGripButton.offsetsAndSizes,
    qt_meta_data_WeaponGripButton,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WeaponGripButton_t
, QtPrivate::TypeAndForceComplete<WeaponGripButton, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *WeaponGripButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeaponGripButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeaponGripButton.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WeaponGripButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WeaponGripButton::takeTwoHandedGripRightHandItem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WeaponGripButton::takeTwoHandedGripLeftHandItem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WeaponGripButton::useOneHandedGrip()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
bool WeaponGripButton::checkFreeHands()
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
