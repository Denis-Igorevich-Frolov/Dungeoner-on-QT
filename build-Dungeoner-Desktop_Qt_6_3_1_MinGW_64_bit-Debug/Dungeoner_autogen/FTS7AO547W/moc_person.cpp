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
    uint offsetsAndSizes[152];
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
    char stringdata11[13];
    char stringdata12[13];
    char stringdata13[13];
    char stringdata14[11];
    char stringdata15[28];
    char stringdata16[12];
    char stringdata17[13];
    char stringdata18[11];
    char stringdata19[28];
    char stringdata20[12];
    char stringdata21[15];
    char stringdata22[12];
    char stringdata23[12];
    char stringdata24[17];
    char stringdata25[17];
    char stringdata26[10];
    char stringdata27[10];
    char stringdata28[13];
    char stringdata29[13];
    char stringdata30[9];
    char stringdata31[9];
    char stringdata32[16];
    char stringdata33[16];
    char stringdata34[25];
    char stringdata35[25];
    char stringdata36[22];
    char stringdata37[22];
    char stringdata38[26];
    char stringdata39[26];
    char stringdata40[23];
    char stringdata41[23];
    char stringdata42[33];
    char stringdata43[33];
    char stringdata44[32];
    char stringdata45[32];
    char stringdata46[18];
    char stringdata47[18];
    char stringdata48[19];
    char stringdata49[19];
    char stringdata50[18];
    char stringdata51[18];
    char stringdata52[12];
    char stringdata53[12];
    char stringdata54[12];
    char stringdata55[12];
    char stringdata56[18];
    char stringdata57[18];
    char stringdata58[17];
    char stringdata59[17];
    char stringdata60[15];
    char stringdata61[15];
    char stringdata62[20];
    char stringdata63[20];
    char stringdata64[33];
    char stringdata65[33];
    char stringdata66[14];
    char stringdata67[14];
    char stringdata68[11];
    char stringdata69[11];
    char stringdata70[14];
    char stringdata71[14];
    char stringdata72[9];
    char stringdata73[9];
    char stringdata74[17];
    char stringdata75[17];
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
        QT_MOC_LITERAL(162, 12),  // "createBackup"
        QT_MOC_LITERAL(175, 12),  // "loadALLStats"
        QT_MOC_LITERAL(188, 12),  // "saveStrength"
        QT_MOC_LITERAL(201, 10),  // "saveValues"
        QT_MOC_LITERAL(212, 27),  // "saveProgressBarCurrentValue"
        QT_MOC_LITERAL(240, 11),  // "saveBonuses"
        QT_MOC_LITERAL(252, 12),  // "loadStrength"
        QT_MOC_LITERAL(265, 10),  // "loadValues"
        QT_MOC_LITERAL(276, 27),  // "loadProgressBarCurrentValue"
        QT_MOC_LITERAL(304, 11),  // "loadBonuses"
        QT_MOC_LITERAL(316, 14),  // "emittedChanged"
        QT_MOC_LITERAL(331, 11),  // "saveAgility"
        QT_MOC_LITERAL(343, 11),  // "loadAgility"
        QT_MOC_LITERAL(355, 16),  // "saveIntelligence"
        QT_MOC_LITERAL(372, 16),  // "loadIntelligence"
        QT_MOC_LITERAL(389, 9),  // "saveMagic"
        QT_MOC_LITERAL(399, 9),  // "loadMagic"
        QT_MOC_LITERAL(409, 12),  // "saveBodyType"
        QT_MOC_LITERAL(422, 12),  // "loadBodyType"
        QT_MOC_LITERAL(435, 8),  // "saveWill"
        QT_MOC_LITERAL(444, 8),  // "loadWill"
        QT_MOC_LITERAL(453, 15),  // "saveMagicDamage"
        QT_MOC_LITERAL(469, 15),  // "loadMagicDamage"
        QT_MOC_LITERAL(485, 24),  // "saveResistPhysicalDamage"
        QT_MOC_LITERAL(510, 24),  // "loadResistPhysicalDamage"
        QT_MOC_LITERAL(535, 21),  // "saveResistMagicDamage"
        QT_MOC_LITERAL(557, 21),  // "loadResistMagicDamage"
        QT_MOC_LITERAL(579, 25),  // "saveResistPhysicalEffects"
        QT_MOC_LITERAL(605, 25),  // "loadResistPhysicalEffects"
        QT_MOC_LITERAL(631, 22),  // "saveResistMagicEffects"
        QT_MOC_LITERAL(654, 22),  // "loadResistMagicEffects"
        QT_MOC_LITERAL(677, 32),  // "saveStrengtheningPhysicalEffects"
        QT_MOC_LITERAL(710, 32),  // "loadStrengtheningPhysicalEffects"
        QT_MOC_LITERAL(743, 31),  // "saveStrengtheningMagicalEffects"
        QT_MOC_LITERAL(775, 31),  // "loadStrengtheningMagicalEffects"
        QT_MOC_LITERAL(807, 17),  // "saveMeleeAccuracy"
        QT_MOC_LITERAL(825, 17),  // "loadMeleeAccuracy"
        QT_MOC_LITERAL(843, 18),  // "saveRangedAccuracy"
        QT_MOC_LITERAL(862, 18),  // "loadRangedAccuracy"
        QT_MOC_LITERAL(881, 17),  // "saveMagicAccuracy"
        QT_MOC_LITERAL(899, 17),  // "loadMagicAccuracy"
        QT_MOC_LITERAL(917, 11),  // "saveEvasion"
        QT_MOC_LITERAL(929, 11),  // "loadEvasion"
        QT_MOC_LITERAL(941, 11),  // "saveStealth"
        QT_MOC_LITERAL(953, 11),  // "loadStealth"
        QT_MOC_LITERAL(965, 17),  // "saveAttentiveness"
        QT_MOC_LITERAL(983, 17),  // "loadAttentiveness"
        QT_MOC_LITERAL(1001, 16),  // "saveLoadCapacity"
        QT_MOC_LITERAL(1018, 16),  // "loadLoadCapacity"
        QT_MOC_LITERAL(1035, 14),  // "saveInitiative"
        QT_MOC_LITERAL(1050, 14),  // "loadInitiative"
        QT_MOC_LITERAL(1065, 19),  // "saveMagicCastChance"
        QT_MOC_LITERAL(1085, 19),  // "loadMagicCastChance"
        QT_MOC_LITERAL(1105, 32),  // "saveChanceOfUsingCombatTechnique"
        QT_MOC_LITERAL(1138, 32),  // "loadChanceOfUsingCombatTechnique"
        QT_MOC_LITERAL(1171, 13),  // "saveMoveRange"
        QT_MOC_LITERAL(1185, 13),  // "loadMoveRange"
        QT_MOC_LITERAL(1199, 10),  // "saveHealth"
        QT_MOC_LITERAL(1210, 10),  // "loadHealth"
        QT_MOC_LITERAL(1221, 13),  // "saveEndurance"
        QT_MOC_LITERAL(1235, 13),  // "loadEndurance"
        QT_MOC_LITERAL(1249, 8),  // "saveMana"
        QT_MOC_LITERAL(1258, 8),  // "loadMana"
        QT_MOC_LITERAL(1267, 16),  // "saveMagicDefense"
        QT_MOC_LITERAL(1284, 16)   // "loadMagicDefense"
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
    "createBackup",
    "loadALLStats",
    "saveStrength",
    "saveValues",
    "saveProgressBarCurrentValue",
    "saveBonuses",
    "loadStrength",
    "loadValues",
    "loadProgressBarCurrentValue",
    "loadBonuses",
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
    "loadWill",
    "saveMagicDamage",
    "loadMagicDamage",
    "saveResistPhysicalDamage",
    "loadResistPhysicalDamage",
    "saveResistMagicDamage",
    "loadResistMagicDamage",
    "saveResistPhysicalEffects",
    "loadResistPhysicalEffects",
    "saveResistMagicEffects",
    "loadResistMagicEffects",
    "saveStrengtheningPhysicalEffects",
    "loadStrengtheningPhysicalEffects",
    "saveStrengtheningMagicalEffects",
    "loadStrengtheningMagicalEffects",
    "saveMeleeAccuracy",
    "loadMeleeAccuracy",
    "saveRangedAccuracy",
    "loadRangedAccuracy",
    "saveMagicAccuracy",
    "loadMagicAccuracy",
    "saveEvasion",
    "loadEvasion",
    "saveStealth",
    "loadStealth",
    "saveAttentiveness",
    "loadAttentiveness",
    "saveLoadCapacity",
    "loadLoadCapacity",
    "saveInitiative",
    "loadInitiative",
    "saveMagicCastChance",
    "loadMagicCastChance",
    "saveChanceOfUsingCombatTechnique",
    "loadChanceOfUsingCombatTechnique",
    "saveMoveRange",
    "loadMoveRange",
    "saveHealth",
    "loadHealth",
    "saveEndurance",
    "loadEndurance",
    "saveMana",
    "loadMana",
    "saveMagicDefense",
    "loadMagicDefense"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Person[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      66,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  410,    2, 0x06,    1 /* Public */,
       3,    0,  411,    2, 0x06,    2 /* Public */,
       4,    0,  412,    2, 0x06,    3 /* Public */,
       5,    0,  413,    2, 0x06,    4 /* Public */,
       6,    0,  414,    2, 0x06,    5 /* Public */,
       7,    0,  415,    2, 0x06,    6 /* Public */,
       8,    0,  416,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  417,    2, 0x0a,    8 /* Public */,
      10,    1,  418,    2, 0x0a,    9 /* Public */,
      12,    0,  421,    2, 0x0a,   11 /* Public */,
      13,    4,  422,    2, 0x0a,   12 /* Public */,
      17,    4,  431,    2, 0x0a,   17 /* Public */,
      22,    4,  440,    2, 0x0a,   22 /* Public */,
      23,    4,  449,    2, 0x0a,   27 /* Public */,
      24,    4,  458,    2, 0x0a,   32 /* Public */,
      25,    4,  467,    2, 0x0a,   37 /* Public */,
      26,    4,  476,    2, 0x0a,   42 /* Public */,
      27,    4,  485,    2, 0x0a,   47 /* Public */,
      28,    4,  494,    2, 0x0a,   52 /* Public */,
      29,    4,  503,    2, 0x0a,   57 /* Public */,
      30,    4,  512,    2, 0x0a,   62 /* Public */,
      31,    4,  521,    2, 0x0a,   67 /* Public */,
      32,    1,  530,    2, 0x0a,   72 /* Public */,
      33,    0,  533,    2, 0x0a,   74 /* Public */,
      34,    1,  534,    2, 0x0a,   75 /* Public */,
      35,    0,  537,    2, 0x0a,   77 /* Public */,
      36,    1,  538,    2, 0x0a,   78 /* Public */,
      37,    0,  541,    2, 0x0a,   80 /* Public */,
      38,    1,  542,    2, 0x0a,   81 /* Public */,
      39,    0,  545,    2, 0x0a,   83 /* Public */,
      40,    1,  546,    2, 0x0a,   84 /* Public */,
      41,    0,  549,    2, 0x0a,   86 /* Public */,
      42,    1,  550,    2, 0x0a,   87 /* Public */,
      43,    0,  553,    2, 0x0a,   89 /* Public */,
      44,    1,  554,    2, 0x0a,   90 /* Public */,
      45,    0,  557,    2, 0x0a,   92 /* Public */,
      46,    1,  558,    2, 0x0a,   93 /* Public */,
      47,    0,  561,    2, 0x0a,   95 /* Public */,
      48,    1,  562,    2, 0x0a,   96 /* Public */,
      49,    0,  565,    2, 0x0a,   98 /* Public */,
      50,    1,  566,    2, 0x0a,   99 /* Public */,
      51,    0,  569,    2, 0x0a,  101 /* Public */,
      52,    1,  570,    2, 0x0a,  102 /* Public */,
      53,    0,  573,    2, 0x0a,  104 /* Public */,
      54,    1,  574,    2, 0x0a,  105 /* Public */,
      55,    0,  577,    2, 0x0a,  107 /* Public */,
      56,    1,  578,    2, 0x0a,  108 /* Public */,
      57,    0,  581,    2, 0x0a,  110 /* Public */,
      58,    1,  582,    2, 0x0a,  111 /* Public */,
      59,    0,  585,    2, 0x0a,  113 /* Public */,
      60,    1,  586,    2, 0x0a,  114 /* Public */,
      61,    0,  589,    2, 0x0a,  116 /* Public */,
      62,    1,  590,    2, 0x0a,  117 /* Public */,
      63,    0,  593,    2, 0x0a,  119 /* Public */,
      64,    1,  594,    2, 0x0a,  120 /* Public */,
      65,    0,  597,    2, 0x0a,  122 /* Public */,
      66,    1,  598,    2, 0x0a,  123 /* Public */,
      67,    0,  601,    2, 0x0a,  125 /* Public */,
      68,    1,  602,    2, 0x0a,  126 /* Public */,
      69,    0,  605,    2, 0x0a,  128 /* Public */,
      70,    1,  606,    2, 0x0a,  129 /* Public */,
      71,    0,  609,    2, 0x0a,  131 /* Public */,
      72,    1,  610,    2, 0x0a,  132 /* Public */,
      73,    0,  613,    2, 0x0a,  134 /* Public */,
      74,    1,  614,    2, 0x0a,  135 /* Public */,
      75,    0,  617,    2, 0x0a,  137 /* Public */,

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
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   11,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   18,   19,   20,   21,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   11,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   18,   19,   20,   21,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   11,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   18,   19,   20,   21,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   11,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   18,   19,   20,   21,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   11,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   18,   19,   20,   21,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,   11,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   18,   19,   20,   21,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   11,
    QMetaType::Bool,

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
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadStrength'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveAgility'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAgility'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveIntelligence'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadIntelligence'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMagic'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMagic'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveBodyType'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadBodyType'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveWill'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadWill'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMagicDamage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMagicDamage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveResistPhysicalDamage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadResistPhysicalDamage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveResistMagicDamage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadResistMagicDamage'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveResistPhysicalEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadResistPhysicalEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveResistMagicEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadResistMagicEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveStrengtheningPhysicalEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadStrengtheningPhysicalEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveStrengtheningMagicalEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadStrengtheningMagicalEffects'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMeleeAccuracy'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMeleeAccuracy'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveRangedAccuracy'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadRangedAccuracy'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMagicAccuracy'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMagicAccuracy'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveEvasion'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadEvasion'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveStealth'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadStealth'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveAttentiveness'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadAttentiveness'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveLoadCapacity'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadLoadCapacity'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveInitiative'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadInitiative'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMagicCastChance'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMagicCastChance'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveChanceOfUsingCombatTechnique'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadChanceOfUsingCombatTechnique'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMoveRange'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMoveRange'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveHealth'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadHealth'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveEndurance'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadEndurance'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMana'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMana'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveMagicDefense'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'loadMagicDefense'
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
        case 10: { bool _r = _t->saveStrength((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->loadStrength((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->saveAgility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->loadAgility((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->saveIntelligence((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->loadIntelligence((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->saveMagic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->loadMagic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->saveBodyType((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->loadBodyType((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->saveWill((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->loadWill((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->saveMagicDamage((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->loadMagicDamage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->saveResistPhysicalDamage((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->loadResistPhysicalDamage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: { bool _r = _t->saveResistMagicDamage((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->loadResistMagicDamage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: { bool _r = _t->saveResistPhysicalEffects((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: { bool _r = _t->loadResistPhysicalEffects();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: { bool _r = _t->saveResistMagicEffects((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 31: { bool _r = _t->loadResistMagicEffects();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 32: { bool _r = _t->saveStrengtheningPhysicalEffects((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: { bool _r = _t->loadStrengtheningPhysicalEffects();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: { bool _r = _t->saveStrengtheningMagicalEffects((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 35: { bool _r = _t->loadStrengtheningMagicalEffects();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 36: { bool _r = _t->saveMeleeAccuracy((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 37: { bool _r = _t->loadMeleeAccuracy();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { bool _r = _t->saveRangedAccuracy((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 39: { bool _r = _t->loadRangedAccuracy();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 40: { bool _r = _t->saveMagicAccuracy((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 41: { bool _r = _t->loadMagicAccuracy();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 42: { bool _r = _t->saveEvasion((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 43: { bool _r = _t->loadEvasion();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 44: { bool _r = _t->saveStealth((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 45: { bool _r = _t->loadStealth();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->saveAttentiveness((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->loadAttentiveness();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: { bool _r = _t->saveLoadCapacity((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 49: { bool _r = _t->loadLoadCapacity();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 50: { bool _r = _t->saveInitiative((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 51: { bool _r = _t->loadInitiative();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 52: { bool _r = _t->saveMagicCastChance((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 53: { bool _r = _t->loadMagicCastChance();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 54: { bool _r = _t->saveChanceOfUsingCombatTechnique((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 55: { bool _r = _t->loadChanceOfUsingCombatTechnique();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 56: { bool _r = _t->saveMoveRange((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 57: { bool _r = _t->loadMoveRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 58: { bool _r = _t->saveHealth((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 59: { bool _r = _t->loadHealth();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 60: { bool _r = _t->saveEndurance((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 61: { bool _r = _t->loadEndurance();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 62: { bool _r = _t->saveMana((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 63: { bool _r = _t->loadMana();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 64: { bool _r = _t->saveMagicDefense((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 65: { bool _r = _t->loadMagicDefense();
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
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 66)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 66;
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
