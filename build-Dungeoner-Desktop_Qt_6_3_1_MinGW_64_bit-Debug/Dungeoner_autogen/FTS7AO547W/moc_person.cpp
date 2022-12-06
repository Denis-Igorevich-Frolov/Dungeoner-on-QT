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
    uint offsetsAndSizes[20];
    char stringdata0[7];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[27];
    char stringdata5[20];
    char stringdata6[23];
    char stringdata7[19];
    char stringdata8[28];
    char stringdata9[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Person_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Person_t qt_meta_stringdata_Person = {
    {
        QT_MOC_LITERAL(0, 6),  // "Person"
        QT_MOC_LITERAL(7, 22),  // "StrengthBonusesChanged"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 21),  // "AgilityBonusesChanged"
        QT_MOC_LITERAL(53, 26),  // "IntelligenceBonusesChanged"
        QT_MOC_LITERAL(80, 19),  // "MagicBonusesChanged"
        QT_MOC_LITERAL(100, 22),  // "BodyTypeBonusesChanged"
        QT_MOC_LITERAL(123, 18),  // "WillBonusesChanged"
        QT_MOC_LITERAL(142, 27),  // "FullReinitializationRequest"
        QT_MOC_LITERAL(170, 20)   // "fullReinitialization"
    },
    "Person",
    "StrengthBonusesChanged",
    "",
    "AgilityBonusesChanged",
    "IntelligenceBonusesChanged",
    "MagicBonusesChanged",
    "BodyTypeBonusesChanged",
    "WillBonusesChanged",
    "FullReinitializationRequest",
    "fullReinitialization"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Person[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    0,   64,    2, 0x06,    3 /* Public */,
       5,    0,   65,    2, 0x06,    4 /* Public */,
       6,    0,   66,    2, 0x06,    5 /* Public */,
       7,    0,   67,    2, 0x06,    6 /* Public */,
       8,    0,   68,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   69,    2, 0x0a,    8 /* Public */,

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
        // method 'StrengthBonusesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AgilityBonusesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'IntelligenceBonusesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MagicBonusesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BodyTypeBonusesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'WillBonusesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'FullReinitializationRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fullReinitialization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Person::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Person *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->StrengthBonusesChanged(); break;
        case 1: _t->AgilityBonusesChanged(); break;
        case 2: _t->IntelligenceBonusesChanged(); break;
        case 3: _t->MagicBonusesChanged(); break;
        case 4: _t->BodyTypeBonusesChanged(); break;
        case 5: _t->WillBonusesChanged(); break;
        case 6: _t->FullReinitializationRequest(); break;
        case 7: _t->fullReinitialization(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::StrengthBonusesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::AgilityBonusesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::IntelligenceBonusesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::MagicBonusesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::BodyTypeBonusesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Person::*)();
            if (_t _q_method = &Person::WillBonusesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
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
    (void)_a;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Person::StrengthBonusesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Person::AgilityBonusesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Person::IntelligenceBonusesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Person::MagicBonusesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Person::BodyTypeBonusesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Person::WillBonusesChanged()
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
