/****************************************************************************
** Meta object code from reading C++ file 'primaryskillsignature.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/PrimarySkillSignature/primaryskillsignature.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'primaryskillsignature.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrimarySkillSignature_t {
    const uint offsetsAndSize[18];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PrimarySkillSignature_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PrimarySkillSignature_t qt_meta_stringdata_PrimarySkillSignature = {
    {
QT_MOC_LITERAL(0, 21), // "PrimarySkillSignature"
QT_MOC_LITERAL(22, 11), // "ShowTooltip"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 14), // "QList<QLabel*>"
QT_MOC_LITERAL(50, 14), // "TooltipContent"
QT_MOC_LITERAL(65, 13), // "RemoveTooltip"
QT_MOC_LITERAL(79, 21), // "on_ButtonTop_released"
QT_MOC_LITERAL(101, 24), // "on_ButtonBottom_released"
QT_MOC_LITERAL(126, 14) // "slotTimerAlarm"

    },
    "PrimarySkillSignature\0ShowTooltip\0\0"
    "QList<QLabel*>\0TooltipContent\0"
    "RemoveTooltip\0on_ButtonTop_released\0"
    "on_ButtonBottom_released\0slotTimerAlarm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrimarySkillSignature[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       5,    0,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   48,    2, 0x08,    4 /* Private */,
       7,    0,   49,    2, 0x08,    5 /* Private */,
       8,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

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
        case 4: _t->slotTimerAlarm(); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrimarySkillSignature::ShowTooltip)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrimarySkillSignature::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrimarySkillSignature::RemoveTooltip)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PrimarySkillSignature::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PrimarySkillSignature.offsetsAndSize,
    qt_meta_data_PrimarySkillSignature,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PrimarySkillSignature_t
, QtPrivate::TypeAndForceComplete<PrimarySkillSignature, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<QLabel*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
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
