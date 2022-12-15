/****************************************************************************
** Meta object code from reading C++ file 'person.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/Person/person.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'person.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Person_t {
    uint offsetsAndSizes[56];
    char stringdata0[7];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[20];
    char stringdata5[13];
    char stringdata6[16];
    char stringdata7[12];
    char stringdata8[28];
    char stringdata9[21];
    char stringdata10[13];
    char stringdata11[14];
    char stringdata12[13];
    char stringdata13[13];
    char stringdata14[11];
    char stringdata15[12];
    char stringdata16[13];
    char stringdata17[15];
    char stringdata18[12];
    char stringdata19[12];
    char stringdata20[17];
    char stringdata21[17];
    char stringdata22[10];
    char stringdata23[10];
    char stringdata24[13];
    char stringdata25[13];
    char stringdata26[9];
    char stringdata27[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Person_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Person_t qt_meta_stringdata_Person = {
    {
        QT_MOC_LITERAL(0, 6),  // "Person"
        QT_MOC_LITERAL(7, 15),  // "StrengthChanged"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 14),  // "AgilityChanged"
        QT_MOC_LITERAL(39, 19),  // "IntelligenceChanged"
        QT_MOC_LITERAL(59, 12),  // "MagicChanged"
        QT_MOC_LITERAL(72, 15),  // "BodyTypeChanged"
        QT_MOC_LITERAL(88, 11),  // "WillChanged"
        QT_MOC_LITERAL(100, 27),  // "FullReinitializationRequest"
        QT_MOC_LITERAL(128, 20),  // "fullReinitialization"
        QT_MOC_LITERAL(149, 12),  // "saveAllStats"
        QT_MOC_LITERAL(162, 13),  // "createBackups"
        QT_MOC_LITERAL(176, 12),  // "loadALLStats"
        QT_MOC_LITERAL(189, 12),  // "saveStrength"
        QT_MOC_LITERAL(202, 10),  // "saveValues"
        QT_MOC_LITERAL(213, 11),  // "saveBonuses"
        QT_MOC_LITERAL(225, 12),  // "loadStrength"
        QT_MOC_LITERAL(238, 14),  // "emittedChanged"
        QT_MOC_LITERAL(253, 11),  // "saveAgility"
        QT_MOC_LITERAL(265, 11),  // "loadAgility"
        QT_MOC_LITERAL(277, 16),  // "saveIntelligence"
        QT_MOC_LITERAL(294, 16),  // "loadIntelligence"
        QT_MOC_LITERAL(311, 9),  // "saveMagic"
        QT_MOC_LITERAL(321, 9),  // "loadMagic"
        QT_MOC_LITERAL(331, 12),  // "saveBodyType"
        QT_MOC_LITERAL(344, 12),  // "loadBodyType"
        QT_MOC_LITERAL(357, 8),  // "saveWill"
        QT_MOC_LITERAL(366, 8)   // "loadWill"
    },
    "Person",
    "StrengthChanged",
    "",
    "AgilityChanged",
    "IntelligenceChanged",
    "MagicChanged",
    "BodyTypeChanged",
    "WillChanged",
    "FullReinitializationRequest",
    "fullReinitialization",
    "saveAllStats",
    "createBackups",
    "loadALLStats",
    "saveStrength",
    "saveValues",
    "saveBonuses",
    "loadStrength",
    "emittedChanged",
    "saveAgility",
    "loadAgility",
    "saveIntelligence",
    "loadIntelligence",
    "saveMagic",
    "loadMagic",
    "saveBodyType",
    "loadBodyType",
    "saveWill",
    "loadWill"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Person[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  146,    2, 0x06,    1 /* Public */,
       3,    0,  147,    2, 0x06,    2 /* Public */,
       4,    0,  148,    2, 0x06,    3 /* Public */,
       5,    0,  149,    2, 0x06,    4 /* Public */,
       6,    0,  150,    2, 0x06,    5 /* Public */,
       7,    0,  151,    2, 0x06,    6 /* Public */,
       8,    0,  152,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  153,    2, 0x0a,    8 /* Public */,
      10,    1,  154,    2, 0x0a,    9 /* Public */,
      12,    0,  157,    2, 0x0a,   11 /* Public */,
      13,    3,  158,    2, 0x0a,   12 /* Public */,
      16,    1,  165,    2, 0x0a,   16 /* Public */,
      18,    3,  168,    2, 0x0a,   18 /* Public */,
      19,    1,  175,    2, 0x0a,   22 /* Public */,
      20,    3,  178,    2, 0x0a,   24 /* Public */,
      21,    1,  185,    2, 0x0a,   28 /* Public */,
      22,    3,  188,    2, 0x0a,   30 /* Public */,
      23,    1,  195,    2, 0x0a,   34 /* Public */,
      24,    3,  198,    2, 0x0a,   36 /* Public */,
      25,    1,  205,    2, 0x0a,   40 /* Public */,
      26,    3,  208,    2, 0x0a,   42 /* Public */,
      27,    1,  215,    2, 0x0a,   46 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   11,
    QMetaType::Bool, QMetaType::Bool,   17,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   11,
    QMetaType::Bool, QMetaType::Bool,   17,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   11,
    QMetaType::Bool, QMetaType::Bool,   17,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   11,
    QMetaType::Bool, QMetaType::Bool,   17,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   11,
    QMetaType::Bool, QMetaType::Bool,   17,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   11,
    QMetaType::Bool, QMetaType::Bool,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject Person::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Person.offsetsAndSizes,
    qt_meta_data_Person,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Person_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Person, std::true_type>,
        // method 'StrengthChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AgilityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'IntelligenceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MagicChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BodyTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'WillChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'FullReinitializationRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fullReinitialization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveAllStats'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadALLStats'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveStrength'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadStrength'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveAgility'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAgility'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveIntelligence'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadIntelligence'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMagic'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMagic'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveBodyType'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadBodyType'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveWill'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadWill'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void Person::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Person *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->StrengthChanged(); break;
        case 1: _t->AgilityChanged(); break;
        case 2: _t->IntelligenceChanged(); break;
        case 3: _t->MagicChanged(); break;
        case 4: _t->BodyTypeChanged(); break;
        case 5: _t->WillChanged(); break;
        case 6: _t->FullReinitializationRequest(); break;
        case 7: _t->fullReinitialization(); break;
        case 8: { bool _r = _t->saveAllStats((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->loadALLStats();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->saveStrength((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->loadStrength((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->saveAgility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->loadAgility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->saveIntelligence((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->loadIntelligence((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->saveMagic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->loadMagic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->saveBodyType((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->loadBodyType((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->saveWill((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->loadWill((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::StrengthChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::AgilityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::IntelligenceChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::MagicChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::BodyTypeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::WillChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::FullReinitializationRequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *Person::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Person::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Person.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Person::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Person::StrengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Person::AgilityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Person::IntelligenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Person::MagicChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Person::BodyTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Person::WillChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Person::FullReinitializationRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
