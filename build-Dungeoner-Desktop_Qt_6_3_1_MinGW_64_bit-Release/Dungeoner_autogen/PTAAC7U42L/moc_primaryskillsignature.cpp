/****************************************************************************
** Meta object code from reading C++ file 'primaryskillsignature.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/PrimarySkillSignature/primaryskillsignature.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'primaryskillsignature.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_PrimarySkillSignature_t {
    uint offsetsAndSizes[22];
    char stringdata0[22];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[15];
    char stringdata5[14];
    char stringdata6[22];
    char stringdata7[25];
    char stringdata8[31];
    char stringdata9[13];
    char stringdata10[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PrimarySkillSignature_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PrimarySkillSignature_t qt_meta_stringdata_PrimarySkillSignature = {
    {
        QT_MOC_LITERAL(0, 21),  // "PrimarySkillSignature"
        QT_MOC_LITERAL(22, 11),  // "ShowTooltip"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 14),  // "QList<QLabel*>"
        QT_MOC_LITERAL(50, 14),  // "TooltipContent"
        QT_MOC_LITERAL(65, 13),  // "RemoveTooltip"
        QT_MOC_LITERAL(79, 21),  // "on_ButtonTop_released"
        QT_MOC_LITERAL(101, 24),  // "on_ButtonBottom_released"
        QT_MOC_LITERAL(126, 30),  // "clickModifierTooltipTimerAlarm"
        QT_MOC_LITERAL(157, 12),  // "valueChanged"
        QT_MOC_LITERAL(170, 5)   // "value"
    },
    "PrimarySkillSignature",
    "ShowTooltip",
    "",
    "QList<QLabel*>",
    "TooltipContent",
    "RemoveTooltip",
    "on_ButtonTop_released",
    "on_ButtonBottom_released",
    "clickModifierTooltipTimerAlarm",
    "valueChanged",
    "value"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PrimarySkillSignature[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       5,    0,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,
       8,    0,   56,    2, 0x08,    6 /* Private */,
       9,    1,   57,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject PrimarySkillSignature::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PrimarySkillSignature.offsetsAndSizes,
    qt_meta_data_PrimarySkillSignature,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PrimarySkillSignature_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PrimarySkillSignature, std::true_type>,
        // method 'ShowTooltip'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QLabel*>, std::false_type>,
        // method 'RemoveTooltip'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonTop_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonBottom_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clickModifierTooltipTimerAlarm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void PrimarySkillSignature::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PrimarySkillSignature *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ShowTooltip((*reinterpret_cast< std::add_pointer_t<QList<QLabel*>>>(_a[1]))); break;
        case 1: _t->RemoveTooltip(); break;
        case 2: _t->on_ButtonTop_released(); break;
        case 3: _t->on_ButtonBottom_released(); break;
        case 4: _t->clickModifierTooltipTimerAlarm(); break;
        case 5: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QLabel*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PrimarySkillSignature::*)(QVector<QLabel*> );
            if (_t _q_method = &PrimarySkillSignature::ShowTooltip; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrimarySkillSignature::*)();
            if (_t _q_method = &PrimarySkillSignature::RemoveTooltip; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *PrimarySkillSignature::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrimarySkillSignature::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrimarySkillSignature.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PrimarySkillSignature::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PrimarySkillSignature::ShowTooltip(QVector<QLabel*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrimarySkillSignature::RemoveTooltip()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
