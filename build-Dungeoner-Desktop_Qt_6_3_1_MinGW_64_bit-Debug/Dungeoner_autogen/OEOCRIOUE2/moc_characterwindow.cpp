/****************************************************************************
** Meta object code from reading C++ file 'characterwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Dungeoner/Windows/CharacterWindow/characterwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'characterwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CharacterWindow_t {
    const uint offsetsAndSize[18];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CharacterWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CharacterWindow_t qt_meta_stringdata_CharacterWindow = {
    {
QT_MOC_LITERAL(0, 15), // "CharacterWindow"
QT_MOC_LITERAL(16, 33), // "ScrollAreaSecondarySkillsScro..."
QT_MOC_LITERAL(50, 0), // ""
QT_MOC_LITERAL(51, 5), // "value"
QT_MOC_LITERAL(57, 11), // "ShowTooltip"
QT_MOC_LITERAL(69, 13), // "RemoveTooltip"
QT_MOC_LITERAL(83, 36), // "on_verticalScrollBar_actionTr..."
QT_MOC_LITERAL(120, 6), // "action"
QT_MOC_LITERAL(127, 33) // "on_verticalScrollBar_valueCha..."

    },
    "CharacterWindow\0ScrollAreaSecondarySkillsScrolled\0"
    "\0value\0ShowTooltip\0RemoveTooltip\0"
    "on_verticalScrollBar_actionTriggered\0"
    "action\0on_verticalScrollBar_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x08,    1 /* Private */,
       4,    0,   47,    2, 0x08,    3 /* Private */,
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    1,   49,    2, 0x08,    5 /* Private */,
       8,    1,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void CharacterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacterWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ScrollAreaSecondarySkillsScrolled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->ShowTooltip(); break;
        case 2: _t->RemoveTooltip(); break;
        case 3: _t->on_verticalScrollBar_actionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_verticalScrollBar_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CharacterWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CharacterWindow.offsetsAndSize,
    qt_meta_data_CharacterWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CharacterWindow_t
, QtPrivate::TypeAndForceComplete<CharacterWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CharacterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharacterWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CharacterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
