/****************************************************************************
** Meta object code from reading C++ file 'vistaprofilo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vistaprofilo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vistaprofilo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_modificaParametroUtente_t {
    QByteArrayData data[4];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modificaParametroUtente_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modificaParametroUtente_t qt_meta_stringdata_modificaParametroUtente = {
    {
QT_MOC_LITERAL(0, 0, 23), // "modificaParametroUtente"
QT_MOC_LITERAL(1, 24, 5), // "fatto"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17) // "modificaParametro"

    },
    "modificaParametroUtente\0fatto\0\0"
    "modificaParametro"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modificaParametroUtente[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void modificaParametroUtente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modificaParametroUtente *_t = static_cast<modificaParametroUtente *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fatto(); break;
        case 1: { bool _r = _t->modificaParametro();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (modificaParametroUtente::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modificaParametroUtente::fatto)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject modificaParametroUtente::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_modificaParametroUtente.data,
      qt_meta_data_modificaParametroUtente,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modificaParametroUtente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificaParametroUtente::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modificaParametroUtente.stringdata0))
        return static_cast<void*>(const_cast< modificaParametroUtente*>(this));
    return QWidget::qt_metacast(_clname);
}

int modificaParametroUtente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void modificaParametroUtente::fatto()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_modificaPassword_t {
    QByteArrayData data[3];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modificaPassword_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modificaPassword_t qt_meta_stringdata_modificaPassword = {
    {
QT_MOC_LITERAL(0, 0, 16), // "modificaPassword"
QT_MOC_LITERAL(1, 17, 17), // "modificaParametro"
QT_MOC_LITERAL(2, 35, 0) // ""

    },
    "modificaPassword\0modificaParametro\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modificaPassword[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void modificaPassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modificaPassword *_t = static_cast<modificaPassword *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->modificaParametro();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject modificaPassword::staticMetaObject = {
    { &modificaParametroUtente::staticMetaObject, qt_meta_stringdata_modificaPassword.data,
      qt_meta_data_modificaPassword,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modificaPassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificaPassword::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modificaPassword.stringdata0))
        return static_cast<void*>(const_cast< modificaPassword*>(this));
    return modificaParametroUtente::qt_metacast(_clname);
}

int modificaPassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = modificaParametroUtente::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_modificaPasswordPerAdmin_t {
    QByteArrayData data[3];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modificaPasswordPerAdmin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modificaPasswordPerAdmin_t qt_meta_stringdata_modificaPasswordPerAdmin = {
    {
QT_MOC_LITERAL(0, 0, 24), // "modificaPasswordPerAdmin"
QT_MOC_LITERAL(1, 25, 17), // "modificaParametro"
QT_MOC_LITERAL(2, 43, 0) // ""

    },
    "modificaPasswordPerAdmin\0modificaParametro\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modificaPasswordPerAdmin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void modificaPasswordPerAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modificaPasswordPerAdmin *_t = static_cast<modificaPasswordPerAdmin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->modificaParametro();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject modificaPasswordPerAdmin::staticMetaObject = {
    { &modificaPassword::staticMetaObject, qt_meta_stringdata_modificaPasswordPerAdmin.data,
      qt_meta_data_modificaPasswordPerAdmin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modificaPasswordPerAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificaPasswordPerAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modificaPasswordPerAdmin.stringdata0))
        return static_cast<void*>(const_cast< modificaPasswordPerAdmin*>(this));
    return modificaPassword::qt_metacast(_clname);
}

int modificaPasswordPerAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = modificaPassword::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_modificaLuogo_t {
    QByteArrayData data[3];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modificaLuogo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modificaLuogo_t qt_meta_stringdata_modificaLuogo = {
    {
QT_MOC_LITERAL(0, 0, 13), // "modificaLuogo"
QT_MOC_LITERAL(1, 14, 17), // "modificaParametro"
QT_MOC_LITERAL(2, 32, 0) // ""

    },
    "modificaLuogo\0modificaParametro\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modificaLuogo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void modificaLuogo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modificaLuogo *_t = static_cast<modificaLuogo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->modificaParametro();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject modificaLuogo::staticMetaObject = {
    { &modificaParametroUtente::staticMetaObject, qt_meta_stringdata_modificaLuogo.data,
      qt_meta_data_modificaLuogo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modificaLuogo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificaLuogo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modificaLuogo.stringdata0))
        return static_cast<void*>(const_cast< modificaLuogo*>(this));
    return modificaParametroUtente::qt_metacast(_clname);
}

int modificaLuogo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = modificaParametroUtente::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_modificaLuogoPerAdmin_t {
    QByteArrayData data[3];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modificaLuogoPerAdmin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modificaLuogoPerAdmin_t qt_meta_stringdata_modificaLuogoPerAdmin = {
    {
QT_MOC_LITERAL(0, 0, 21), // "modificaLuogoPerAdmin"
QT_MOC_LITERAL(1, 22, 17), // "modificaParametro"
QT_MOC_LITERAL(2, 40, 0) // ""

    },
    "modificaLuogoPerAdmin\0modificaParametro\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modificaLuogoPerAdmin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void modificaLuogoPerAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modificaLuogoPerAdmin *_t = static_cast<modificaLuogoPerAdmin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->modificaParametro();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject modificaLuogoPerAdmin::staticMetaObject = {
    { &modificaLuogo::staticMetaObject, qt_meta_stringdata_modificaLuogoPerAdmin.data,
      qt_meta_data_modificaLuogoPerAdmin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modificaLuogoPerAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificaLuogoPerAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modificaLuogoPerAdmin.stringdata0))
        return static_cast<void*>(const_cast< modificaLuogoPerAdmin*>(this));
    return modificaLuogo::qt_metacast(_clname);
}

int modificaLuogoPerAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = modificaLuogo::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_vistaProfilo_t {
    QByteArrayData data[8];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaProfilo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaProfilo_t qt_meta_stringdata_vistaProfilo = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vistaProfilo"
QT_MOC_LITERAL(1, 13, 22), // "confermaEliminaProfilo"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 18), // "modificaEffettuata"
QT_MOC_LITERAL(4, 56, 19), // "parametroModificato"
QT_MOC_LITERAL(5, 76, 20), // "cliccaEliminaProfilo"
QT_MOC_LITERAL(6, 97, 17), // "cliccaCambiaLuogo"
QT_MOC_LITERAL(7, 115, 20) // "cliccaCambiaPassword"

    },
    "vistaProfilo\0confermaEliminaProfilo\0"
    "\0modificaEffettuata\0parametroModificato\0"
    "cliccaEliminaProfilo\0cliccaCambiaLuogo\0"
    "cliccaCambiaPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaProfilo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x09 /* Protected */,
       6,    0,   48,    2, 0x09 /* Protected */,
       7,    0,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vistaProfilo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaProfilo *_t = static_cast<vistaProfilo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->confermaEliminaProfilo(); break;
        case 1: _t->modificaEffettuata(); break;
        case 2: _t->parametroModificato(); break;
        case 3: _t->cliccaEliminaProfilo(); break;
        case 4: _t->cliccaCambiaLuogo(); break;
        case 5: _t->cliccaCambiaPassword(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vistaProfilo::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaProfilo::confermaEliminaProfilo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (vistaProfilo::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaProfilo::modificaEffettuata)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject vistaProfilo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaProfilo.data,
      qt_meta_data_vistaProfilo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaProfilo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaProfilo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaProfilo.stringdata0))
        return static_cast<void*>(const_cast< vistaProfilo*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaProfilo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void vistaProfilo::confermaEliminaProfilo()const
{
    QMetaObject::activate(const_cast< vistaProfilo *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void vistaProfilo::modificaEffettuata()const
{
    QMetaObject::activate(const_cast< vistaProfilo *>(this), &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_vistaProfiloPerAdmin_t {
    QByteArrayData data[5];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaProfiloPerAdmin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaProfiloPerAdmin_t qt_meta_stringdata_vistaProfiloPerAdmin = {
    {
QT_MOC_LITERAL(0, 0, 20), // "vistaProfiloPerAdmin"
QT_MOC_LITERAL(1, 21, 20), // "cliccaEliminaProfilo"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 17), // "cliccaCambiaLuogo"
QT_MOC_LITERAL(4, 61, 20) // "cliccaCambiaPassword"

    },
    "vistaProfiloPerAdmin\0cliccaEliminaProfilo\0"
    "\0cliccaCambiaLuogo\0cliccaCambiaPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaProfiloPerAdmin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vistaProfiloPerAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaProfiloPerAdmin *_t = static_cast<vistaProfiloPerAdmin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cliccaEliminaProfilo(); break;
        case 1: _t->cliccaCambiaLuogo(); break;
        case 2: _t->cliccaCambiaPassword(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject vistaProfiloPerAdmin::staticMetaObject = {
    { &vistaProfilo::staticMetaObject, qt_meta_stringdata_vistaProfiloPerAdmin.data,
      qt_meta_data_vistaProfiloPerAdmin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaProfiloPerAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaProfiloPerAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaProfiloPerAdmin.stringdata0))
        return static_cast<void*>(const_cast< vistaProfiloPerAdmin*>(this));
    return vistaProfilo::qt_metacast(_clname);
}

int vistaProfiloPerAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = vistaProfilo::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
