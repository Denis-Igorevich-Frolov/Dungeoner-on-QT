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
    const uint offsetsAndSize[38];
    char stringdata0[412];
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
QT_MOC_LITERAL(127, 33), // "on_verticalScrollBar_valueCha..."
QT_MOC_LITERAL(161, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(183, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(207, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(231, 29), // "on_StrengthValue_valueChanged"
QT_MOC_LITERAL(261, 4), // "arg1"
QT_MOC_LITERAL(266, 28), // "on_AgilityValue_valueChanged"
QT_MOC_LITERAL(295, 33), // "on_IntelligenceValue_valueCha..."
QT_MOC_LITERAL(329, 26), // "on_MagicValue_valueChanged"
QT_MOC_LITERAL(356, 29), // "on_BodyTypeValue_valueChanged"
QT_MOC_LITERAL(386, 25) // "on_WillValue_valueChanged"

    },
    "CharacterWindow\0ScrollAreaSecondarySkillsScrolled\0"
    "\0value\0ShowTooltip\0RemoveTooltip\0"
    "on_verticalScrollBar_actionTriggered\0"
    "action\0on_verticalScrollBar_valueChanged\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_StrengthValue_valueChanged\0arg1\0"
    "on_AgilityValue_valueChanged\0"
    "on_IntelligenceValue_valueChanged\0"
    "on_MagicValue_valueChanged\0"
    "on_BodyTypeValue_valueChanged\0"
    "on_WillValue_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x08,    1 /* Private */,
       4,    0,  101,    2, 0x08,    3 /* Private */,
       5,    0,  102,    2, 0x08,    4 /* Private */,
       6,    1,  103,    2, 0x08,    5 /* Private */,
       8,    1,  106,    2, 0x08,    7 /* Private */,
       9,    0,  109,    2, 0x08,    9 /* Private */,
      10,    0,  110,    2, 0x08,   10 /* Private */,
      11,    0,  111,    2, 0x08,   11 /* Private */,
      12,    1,  112,    2, 0x08,   12 /* Private */,
      14,    1,  115,    2, 0x08,   14 /* Private */,
      15,    1,  118,    2, 0x08,   16 /* Private */,
      16,    1,  121,    2, 0x08,   18 /* Private */,
      17,    1,  124,    2, 0x08,   20 /* Private */,
      18,    1,  127,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,

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
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_StrengthValue_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_AgilityValue_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_IntelligenceValue_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_MagicValue_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_BodyTypeValue_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_WillValue_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
