/****************************************************************************
** Meta object code from reading C++ file 'animationworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/CustomWidgets/AnimationInSeparateThread/animationworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animationworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnimationWorker_t {
    uint offsetsAndSizes[26];
    char stringdata0[16];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[27];
    char stringdata5[10];
    char stringdata6[5];
    char stringdata7[9];
    char stringdata8[11];
    char stringdata9[9];
    char stringdata10[7];
    char stringdata11[15];
    char stringdata12[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AnimationWorker_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_AnimationWorker_t qt_meta_stringdata_AnimationWorker = {
    {
        QT_MOC_LITERAL(0, 15),  // "AnimationWorker"
        QT_MOC_LITERAL(16, 8),  // "finished"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 17),  // "animationTransfer"
        QT_MOC_LITERAL(44, 26),  // "AnimationInSeparateThread*"
        QT_MOC_LITERAL(71, 9),  // "animation"
        QT_MOC_LITERAL(81, 4),  // "init"
        QT_MOC_LITERAL(86, 8),  // "fileName"
        QT_MOC_LITERAL(95, 10),  // "scaledSize"
        QT_MOC_LITERAL(106, 8),  // "QWidget*"
        QT_MOC_LITERAL(115, 6),  // "parent"
        QT_MOC_LITERAL(122, 14),  // "startAnimation"
        QT_MOC_LITERAL(137, 13)   // "stopAnimation"
    },
    "AnimationWorker",
    "finished",
    "",
    "animationTransfer",
    "AnimationInSeparateThread*",
    "animation",
    "init",
    "fileName",
    "scaledSize",
    "QWidget*",
    "parent",
    "startAnimation",
    "stopAnimation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationWorker[] = {

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
       3,    1,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    3,   50,    2, 0x0a,    5 /* Public */,
      11,    0,   57,    2, 0x0a,    9 /* Public */,
      12,    0,   58,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QSize, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnimationWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnimationWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->animationTransfer((*reinterpret_cast< std::add_pointer_t<AnimationInSeparateThread*>>(_a[1]))); break;
        case 2: _t->init((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[3]))); break;
        case 3: _t->startAnimation(); break;
        case 4: _t->stopAnimation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AnimationInSeparateThread* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AnimationWorker::*)(bool );
            if (_t _q_method = &AnimationWorker::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AnimationWorker::*)(AnimationInSeparateThread * );
            if (_t _q_method = &AnimationWorker::animationTransfer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AnimationWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AnimationWorker.offsetsAndSizes,
    qt_meta_data_AnimationWorker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AnimationWorker_t
, QtPrivate::TypeAndForceComplete<AnimationWorker, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<AnimationInSeparateThread *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QSize, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AnimationWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AnimationWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void AnimationWorker::finished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnimationWorker::animationTransfer(AnimationInSeparateThread * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
