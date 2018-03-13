/****************************************************************************
** Meta object code from reading C++ file 'principale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "principale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'principale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ricerca_t {
    QByteArrayData data[3];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ricerca_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ricerca_t qt_meta_stringdata_ricerca = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ricerca"
QT_MOC_LITERAL(1, 8, 12), // "premutoCerca"
QT_MOC_LITERAL(2, 21, 0) // ""

    },
    "ricerca\0premutoCerca\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ricerca[] = {

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

void ricerca::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ricerca *_t = static_cast<ricerca *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->premutoCerca(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ricerca::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ricerca::premutoCerca)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ricerca::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ricerca.data,
      qt_meta_data_ricerca,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ricerca::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ricerca::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ricerca.stringdata0))
        return static_cast<void*>(const_cast< ricerca*>(this));
    return QWidget::qt_metacast(_clname);
}

int ricerca::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ricerca::premutoCerca()const
{
    QMetaObject::activate(const_cast< ricerca *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_visualizzatoreRicerche_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_visualizzatoreRicerche_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_visualizzatoreRicerche_t qt_meta_stringdata_visualizzatoreRicerche = {
    {
QT_MOC_LITERAL(0, 0, 22), // "visualizzatoreRicerche"
QT_MOC_LITERAL(1, 23, 13), // "disegnaTornei"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 13), // "eliminaTorneo"
QT_MOC_LITERAL(4, 52, 6), // "size_t"
QT_MOC_LITERAL(5, 59, 5) // "index"

    },
    "visualizzatoreRicerche\0disegnaTornei\0"
    "\0eliminaTorneo\0size_t\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_visualizzatoreRicerche[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void visualizzatoreRicerche::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        visualizzatoreRicerche *_t = static_cast<visualizzatoreRicerche *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disegnaTornei(); break;
        case 1: _t->eliminaTorneo((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject visualizzatoreRicerche::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_visualizzatoreRicerche.data,
      qt_meta_data_visualizzatoreRicerche,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *visualizzatoreRicerche::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *visualizzatoreRicerche::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_visualizzatoreRicerche.stringdata0))
        return static_cast<void*>(const_cast< visualizzatoreRicerche*>(this));
    return QWidget::qt_metacast(_clname);
}

int visualizzatoreRicerche::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_bottoneEliminazione_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bottoneEliminazione_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bottoneEliminazione_t qt_meta_stringdata_bottoneEliminazione = {
    {
QT_MOC_LITERAL(0, 0, 19), // "bottoneEliminazione"
QT_MOC_LITERAL(1, 20, 15), // "torneoEliminato"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "size_t"
QT_MOC_LITERAL(4, 44, 6), // "indice"
QT_MOC_LITERAL(5, 51, 7) // "premuto"

    },
    "bottoneEliminazione\0torneoEliminato\0"
    "\0size_t\0indice\0premuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bottoneEliminazione[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void bottoneEliminazione::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bottoneEliminazione *_t = static_cast<bottoneEliminazione *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->torneoEliminato((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 1: _t->premuto(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bottoneEliminazione::*_t)(size_t ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bottoneEliminazione::torneoEliminato)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject bottoneEliminazione::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_bottoneEliminazione.data,
      qt_meta_data_bottoneEliminazione,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bottoneEliminazione::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bottoneEliminazione::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bottoneEliminazione.stringdata0))
        return static_cast<void*>(const_cast< bottoneEliminazione*>(this));
    return QPushButton::qt_metacast(_clname);
}

int bottoneEliminazione::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void bottoneEliminazione::torneoEliminato(size_t _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< bottoneEliminazione *>(this), &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_bottoneTorneoModificabile_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bottoneTorneoModificabile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bottoneTorneoModificabile_t qt_meta_stringdata_bottoneTorneoModificabile = {
    {
QT_MOC_LITERAL(0, 0, 25), // "bottoneTorneoModificabile"
QT_MOC_LITERAL(1, 26, 7), // "premuto"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "bottoneTorneoModificabile\0premuto\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bottoneTorneoModificabile[] = {

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

void bottoneTorneoModificabile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bottoneTorneoModificabile *_t = static_cast<bottoneTorneoModificabile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->premuto(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject bottoneTorneoModificabile::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_bottoneTorneoModificabile.data,
      qt_meta_data_bottoneTorneoModificabile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bottoneTorneoModificabile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bottoneTorneoModificabile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bottoneTorneoModificabile.stringdata0))
        return static_cast<void*>(const_cast< bottoneTorneoModificabile*>(this));
    return QPushButton::qt_metacast(_clname);
}

int bottoneTorneoModificabile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_bottoneTorneoVisualizzabile_t {
    QByteArrayData data[3];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bottoneTorneoVisualizzabile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bottoneTorneoVisualizzabile_t qt_meta_stringdata_bottoneTorneoVisualizzabile = {
    {
QT_MOC_LITERAL(0, 0, 27), // "bottoneTorneoVisualizzabile"
QT_MOC_LITERAL(1, 28, 7), // "premuto"
QT_MOC_LITERAL(2, 36, 0) // ""

    },
    "bottoneTorneoVisualizzabile\0premuto\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bottoneTorneoVisualizzabile[] = {

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

void bottoneTorneoVisualizzabile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bottoneTorneoVisualizzabile *_t = static_cast<bottoneTorneoVisualizzabile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->premuto(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject bottoneTorneoVisualizzabile::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_bottoneTorneoVisualizzabile.data,
      qt_meta_data_bottoneTorneoVisualizzabile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bottoneTorneoVisualizzabile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bottoneTorneoVisualizzabile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bottoneTorneoVisualizzabile.stringdata0))
        return static_cast<void*>(const_cast< bottoneTorneoVisualizzabile*>(this));
    return QPushButton::qt_metacast(_clname);
}

int bottoneTorneoVisualizzabile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_nuovoTorneo_t {
    QByteArrayData data[4];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nuovoTorneo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nuovoTorneo_t qt_meta_stringdata_nuovoTorneo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "nuovoTorneo"
QT_MOC_LITERAL(1, 12, 15), // "confermaPremuto"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13) // "tentaConferma"

    },
    "nuovoTorneo\0confermaPremuto\0\0tentaConferma"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nuovoTorneo[] = {

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
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void nuovoTorneo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nuovoTorneo *_t = static_cast<nuovoTorneo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->confermaPremuto(); break;
        case 1: _t->tentaConferma(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (nuovoTorneo::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nuovoTorneo::confermaPremuto)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject nuovoTorneo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nuovoTorneo.data,
      qt_meta_data_nuovoTorneo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *nuovoTorneo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nuovoTorneo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_nuovoTorneo.stringdata0))
        return static_cast<void*>(const_cast< nuovoTorneo*>(this));
    return QWidget::qt_metacast(_clname);
}

int nuovoTorneo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void nuovoTorneo::confermaPremuto()const
{
    QMetaObject::activate(const_cast< nuovoTorneo *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_bottoni_t {
    QByteArrayData data[6];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bottoni_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bottoni_t qt_meta_stringdata_bottoni = {
    {
QT_MOC_LITERAL(0, 0, 7), // "bottoni"
QT_MOC_LITERAL(1, 8, 17), // "creaTorneoPremuto"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "profiloPremuto"
QT_MOC_LITERAL(4, 42, 13), // "logoutPremuto"
QT_MOC_LITERAL(5, 56, 22) // "amministrazionePremuto"

    },
    "bottoni\0creaTorneoPremuto\0\0profiloPremuto\0"
    "logoutPremuto\0amministrazionePremuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bottoni[] = {

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

void bottoni::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bottoni *_t = static_cast<bottoni *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->creaTorneoPremuto(); break;
        case 1: _t->profiloPremuto(); break;
        case 2: _t->logoutPremuto(); break;
        case 3: _t->amministrazionePremuto(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bottoni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bottoni::creaTorneoPremuto)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (bottoni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bottoni::profiloPremuto)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (bottoni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bottoni::logoutPremuto)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (bottoni::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bottoni::amministrazionePremuto)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject bottoni::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_bottoni.data,
      qt_meta_data_bottoni,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bottoni::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bottoni::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bottoni.stringdata0))
        return static_cast<void*>(const_cast< bottoni*>(this));
    return QWidget::qt_metacast(_clname);
}

int bottoni::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void bottoni::creaTorneoPremuto()const
{
    QMetaObject::activate(const_cast< bottoni *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void bottoni::profiloPremuto()const
{
    QMetaObject::activate(const_cast< bottoni *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void bottoni::logoutPremuto()const
{
    QMetaObject::activate(const_cast< bottoni *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void bottoni::amministrazionePremuto()const
{
    QMetaObject::activate(const_cast< bottoni *>(this), &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_principale_t {
    QByteArrayData data[9];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_principale_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_principale_t qt_meta_stringdata_principale = {
    {
QT_MOC_LITERAL(0, 0, 10), // "principale"
QT_MOC_LITERAL(1, 11, 6), // "logout"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 22), // "amministrazionePremuto"
QT_MOC_LITERAL(4, 42, 12), // "cercaPremuto"
QT_MOC_LITERAL(5, 55, 18), // "nuovoTorneoPremuto"
QT_MOC_LITERAL(6, 74, 18), // "datiTorneiInseriti"
QT_MOC_LITERAL(7, 93, 14), // "profiloPremuto"
QT_MOC_LITERAL(8, 108, 22) // "confermaEliminaProfilo"

    },
    "principale\0logout\0\0amministrazionePremuto\0"
    "cercaPremuto\0nuovoTorneoPremuto\0"
    "datiTorneiInseriti\0profiloPremuto\0"
    "confermaEliminaProfilo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_principale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void principale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        principale *_t = static_cast<principale *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logout(); break;
        case 1: _t->amministrazionePremuto(); break;
        case 2: _t->cercaPremuto(); break;
        case 3: _t->nuovoTorneoPremuto(); break;
        case 4: _t->datiTorneiInseriti(); break;
        case 5: _t->profiloPremuto(); break;
        case 6: _t->confermaEliminaProfilo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (principale::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&principale::logout)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (principale::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&principale::amministrazionePremuto)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject principale::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_principale.data,
      qt_meta_data_principale,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *principale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *principale::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_principale.stringdata0))
        return static_cast<void*>(const_cast< principale*>(this));
    return QWidget::qt_metacast(_clname);
}

int principale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void principale::logout()const
{
    QMetaObject::activate(const_cast< principale *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void principale::amministrazionePremuto()const
{
    QMetaObject::activate(const_cast< principale *>(this), &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
