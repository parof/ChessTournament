/****************************************************************************
** Meta object code from reading C++ file 'vistatorneo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vistatorneo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vistatorneo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vistaMatch_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaMatch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaMatch_t qt_meta_stringdata_vistaMatch = {
    {
QT_MOC_LITERAL(0, 0, 10), // "vistaMatch"
QT_MOC_LITERAL(1, 11, 17), // "risultatoCliccato"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "vistaMatch\0risultatoCliccato\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaMatch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void vistaMatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaMatch *_t = static_cast<vistaMatch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->risultatoCliccato(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vistaMatch::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaMatch::risultatoCliccato)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject vistaMatch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaMatch.data,
      qt_meta_data_vistaMatch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaMatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaMatch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaMatch.stringdata0))
        return static_cast<void*>(const_cast< vistaMatch*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaMatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void vistaMatch::risultatoCliccato()const
{
    QMetaObject::activate(const_cast< vistaMatch *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_vistaTurno_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaTurno_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaTurno_t qt_meta_stringdata_vistaTurno = {
    {
QT_MOC_LITERAL(0, 0, 10), // "vistaTurno"
QT_MOC_LITERAL(1, 11, 22), // "risultatoMatchCliccato"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5) // "index"

    },
    "vistaTurno\0risultatoMatchCliccato\0\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaTurno[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void vistaTurno::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaTurno *_t = static_cast<vistaTurno *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->risultatoMatchCliccato((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vistaTurno::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaTurno::risultatoMatchCliccato)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject vistaTurno::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaTurno.data,
      qt_meta_data_vistaTurno,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaTurno::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaTurno::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaTurno.stringdata0))
        return static_cast<void*>(const_cast< vistaTurno*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaTurno::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void vistaTurno::risultatoMatchCliccato(int _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< vistaTurno *>(this), &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_vistaTurni_t {
    QByteArrayData data[4];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaTurni_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaTurni_t qt_meta_stringdata_vistaTurni = {
    {
QT_MOC_LITERAL(0, 0, 10), // "vistaTurni"
QT_MOC_LITERAL(1, 11, 17), // "risultatoCliccato"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2) // "id"

    },
    "vistaTurni\0risultatoCliccato\0\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaTurni[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void vistaTurni::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaTurni *_t = static_cast<vistaTurni *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->risultatoCliccato((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vistaTurni::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaTurni::risultatoCliccato)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject vistaTurni::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaTurni.data,
      qt_meta_data_vistaTurni,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaTurni::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaTurni::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaTurni.stringdata0))
        return static_cast<void*>(const_cast< vistaTurni*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaTurni::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void vistaTurni::risultatoCliccato(int _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< vistaTurni *>(this), &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_vistaTorneoV_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaTorneoV_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaTorneoV_t qt_meta_stringdata_vistaTorneoV = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vistaTorneoV"
QT_MOC_LITERAL(1, 13, 14), // "tentaVincitore"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "vistaTorneoV\0tentaVincitore\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaTorneoV[] = {

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
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void vistaTorneoV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaTorneoV *_t = static_cast<vistaTorneoV *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tentaVincitore(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject vistaTorneoV::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaTorneoV.data,
      qt_meta_data_vistaTorneoV,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaTorneoV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaTorneoV::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaTorneoV.stringdata0))
        return static_cast<void*>(const_cast< vistaTorneoV*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaTorneoV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_richiestaRisultato_t {
    QByteArrayData data[6];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_richiestaRisultato_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_richiestaRisultato_t qt_meta_stringdata_richiestaRisultato = {
    {
QT_MOC_LITERAL(0, 0, 18), // "richiestaRisultato"
QT_MOC_LITERAL(1, 19, 15), // "sceltoVincitore"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "sceltoUno"
QT_MOC_LITERAL(4, 46, 9), // "sceltoDue"
QT_MOC_LITERAL(5, 56, 13) // "sceltoNessuno"

    },
    "richiestaRisultato\0sceltoVincitore\0\0"
    "sceltoUno\0sceltoDue\0sceltoNessuno"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_richiestaRisultato[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void richiestaRisultato::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        richiestaRisultato *_t = static_cast<richiestaRisultato *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sceltoVincitore(); break;
        case 1: _t->sceltoUno(); break;
        case 2: _t->sceltoDue(); break;
        case 3: _t->sceltoNessuno(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (richiestaRisultato::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&richiestaRisultato::sceltoVincitore)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject richiestaRisultato::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_richiestaRisultato.data,
      qt_meta_data_richiestaRisultato,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *richiestaRisultato::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *richiestaRisultato::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_richiestaRisultato.stringdata0))
        return static_cast<void*>(const_cast< richiestaRisultato*>(this));
    return QWidget::qt_metacast(_clname);
}

int richiestaRisultato::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void richiestaRisultato::sceltoVincitore()const
{
    QMetaObject::activate(const_cast< richiestaRisultato *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_vistaAggiungiPartecipante_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaAggiungiPartecipante_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaAggiungiPartecipante_t qt_meta_stringdata_vistaAggiungiPartecipante = {
    {
QT_MOC_LITERAL(0, 0, 25), // "vistaAggiungiPartecipante"
QT_MOC_LITERAL(1, 26, 7), // "premuto"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "vistaAggiungiPartecipante\0premuto\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaAggiungiPartecipante[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void vistaAggiungiPartecipante::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaAggiungiPartecipante *_t = static_cast<vistaAggiungiPartecipante *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->premuto(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vistaAggiungiPartecipante::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaAggiungiPartecipante::premuto)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject vistaAggiungiPartecipante::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaAggiungiPartecipante.data,
      qt_meta_data_vistaAggiungiPartecipante,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaAggiungiPartecipante::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaAggiungiPartecipante::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaAggiungiPartecipante.stringdata0))
        return static_cast<void*>(const_cast< vistaAggiungiPartecipante*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaAggiungiPartecipante::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void vistaAggiungiPartecipante::premuto()const
{
    QMetaObject::activate(const_cast< vistaAggiungiPartecipante *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_vistaOperazioni_t {
    QByteArrayData data[6];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaOperazioni_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaOperazioni_t qt_meta_stringdata_vistaOperazioni = {
    {
QT_MOC_LITERAL(0, 0, 15), // "vistaOperazioni"
QT_MOC_LITERAL(1, 16, 20), // "prossimoTurnoPremuto"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 27), // "aggiungiPartecipantePremuto"
QT_MOC_LITERAL(4, 66, 13), // "iniziaPremuto"
QT_MOC_LITERAL(5, 80, 16) // "vincitorePremuto"

    },
    "vistaOperazioni\0prossimoTurnoPremuto\0"
    "\0aggiungiPartecipantePremuto\0iniziaPremuto\0"
    "vincitorePremuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaOperazioni[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vistaOperazioni::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaOperazioni *_t = static_cast<vistaOperazioni *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->prossimoTurnoPremuto(); break;
        case 1: _t->aggiungiPartecipantePremuto(); break;
        case 2: _t->iniziaPremuto(); break;
        case 3: _t->vincitorePremuto(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vistaOperazioni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaOperazioni::prossimoTurnoPremuto)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (vistaOperazioni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaOperazioni::aggiungiPartecipantePremuto)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (vistaOperazioni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaOperazioni::iniziaPremuto)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (vistaOperazioni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vistaOperazioni::vincitorePremuto)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject vistaOperazioni::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaOperazioni.data,
      qt_meta_data_vistaOperazioni,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaOperazioni::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaOperazioni::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaOperazioni.stringdata0))
        return static_cast<void*>(const_cast< vistaOperazioni*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaOperazioni::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void vistaOperazioni::prossimoTurnoPremuto()const
{
    QMetaObject::activate(const_cast< vistaOperazioni *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void vistaOperazioni::aggiungiPartecipantePremuto()const
{
    QMetaObject::activate(const_cast< vistaOperazioni *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void vistaOperazioni::iniziaPremuto()const
{
    QMetaObject::activate(const_cast< vistaOperazioni *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void vistaOperazioni::vincitorePremuto()const
{
    QMetaObject::activate(const_cast< vistaOperazioni *>(this), &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_vistaTorneoM_t {
    QByteArrayData data[10];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vistaTorneoM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vistaTorneoM_t qt_meta_stringdata_vistaTorneoM = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vistaTorneoM"
QT_MOC_LITERAL(1, 13, 22), // "risultatoMatchCliccato"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 2), // "id"
QT_MOC_LITERAL(4, 40, 18), // "risultatoMatchDato"
QT_MOC_LITERAL(5, 59, 18), // "tentaProssimoTurno"
QT_MOC_LITERAL(6, 78, 25), // "tentaAggiungiPartecipante"
QT_MOC_LITERAL(7, 104, 24), // "datiPartecipanteInseriti"
QT_MOC_LITERAL(8, 129, 11), // "tentaInizia"
QT_MOC_LITERAL(9, 141, 14) // "tentaVincitore"

    },
    "vistaTorneoM\0risultatoMatchCliccato\0"
    "\0id\0risultatoMatchDato\0tentaProssimoTurno\0"
    "tentaAggiungiPartecipante\0"
    "datiPartecipanteInseriti\0tentaInizia\0"
    "tentaVincitore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vistaTorneoM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vistaTorneoM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vistaTorneoM *_t = static_cast<vistaTorneoM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->risultatoMatchCliccato((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->risultatoMatchDato(); break;
        case 2: _t->tentaProssimoTurno(); break;
        case 3: _t->tentaAggiungiPartecipante(); break;
        case 4: _t->datiPartecipanteInseriti(); break;
        case 5: _t->tentaInizia(); break;
        case 6: _t->tentaVincitore(); break;
        default: ;
        }
    }
}

const QMetaObject vistaTorneoM::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vistaTorneoM.data,
      qt_meta_data_vistaTorneoM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vistaTorneoM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vistaTorneoM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vistaTorneoM.stringdata0))
        return static_cast<void*>(const_cast< vistaTorneoM*>(this));
    return QWidget::qt_metacast(_clname);
}

int vistaTorneoM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
