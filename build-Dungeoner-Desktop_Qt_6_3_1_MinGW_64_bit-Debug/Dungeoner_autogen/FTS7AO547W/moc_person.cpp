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
    uint offsetsAndSizes[28];
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
    char stringdata13[15];
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
        QT_MOC_LITERAL(149, 12),  // "saveStrength"
        QT_MOC_LITERAL(162, 13),  // "createBackups"
        QT_MOC_LITERAL(176, 12),  // "loadStrength"
        QT_MOC_LITERAL(189, 14)   // "emittedChanged"
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
    "saveStrength",
    "createBackups",
    "loadStrength",
    "emittedChanged"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Person[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    0,   76,    2, 0x06,    3 /* Public */,
       5,    0,   77,    2, 0x06,    4 /* Public */,
       6,    0,   78,    2, 0x06,    5 /* Public */,
       7,    0,   79,    2, 0x06,    6 /* Public */,
       8,    0,   80,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   81,    2, 0x0a,    8 /* Public */,
      10,    1,   82,    2, 0x0a,    9 /* Public */,
      12,    1,   85,    2, 0x0a,   11 /* Public */,

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
    QMetaType::Bool, QMetaType::Bool,   13,

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
        // method 'saveStrength'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadStrength'
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
        case 8: { bool _r = _t->saveStrength((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->loadStrength((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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
