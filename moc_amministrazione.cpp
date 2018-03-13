/****************************************************************************
** Meta object code from reading C++ file 'amministrazione.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "amministrazione.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'amministrazione.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_bottoneIndice_t {
    QByteArrayData data[6];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bottoneIndice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bottoneIndice_t qt_meta_stringdata_bottoneIndice = {
    {
QT_MOC_LITERAL(0, 0, 13), // "bottoneIndice"
QT_MOC_LITERAL(1, 14, 7), // "premuto"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "size_t"
QT_MOC_LITERAL(4, 30, 6), // "indice"
QT_MOC_LITERAL(5, 37, 14) // "tentaPressione"

    },
    "bottoneIndice\0premuto\0\0size_t\0indice\0"
    "tentaPressione"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bottoneIndice[] = {

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

void bottoneIndice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bottoneIndice *_t = static_cast<bottoneIndice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->premuto((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 1: _t->tentaPressione(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bottoneIndice::*_t)(size_t ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bottoneIndice::premuto)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject bottoneIndice::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_bottoneIndice.data,
      qt_meta_data_bottoneIndice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bottoneIndice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bottoneIndice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bottoneIndice.stringdata0))
        return static_cast<void*>(const_cast< bottoneIndice*>(this));
    return QPushButton::qt_metacast(_clname);
}

int bottoneIndice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void bottoneIndice::premuto(size_t _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< bottoneIndice *>(this), &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_amministrazione_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_amministrazione_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_amministrazione_t qt_meta_stringdata_amministrazione = {
    {
QT_MOC_LITERAL(0, 0, 15), // "amministrazione"
QT_MOC_LITERAL(1, 16, 13), // "chiudiPremuto"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "profiloEliminato"
QT_MOC_LITERAL(4, 48, 13), // "schedaPremuta"
QT_MOC_LITERAL(5, 62, 6), // "size_t"
QT_MOC_LITERAL(6, 69, 1), // "i"
QT_MOC_LITERAL(7, 71, 7), // "ricerca"
QT_MOC_LITERAL(8, 79, 13) // "disegnaUtenti"

    },
    "amministrazione\0chiudiPremuto\0\0"
    "profiloEliminato\0schedaPremuta\0size_t\0"
    "i\0ricerca\0disegnaUtenti"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_amministrazione[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void amministrazione::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        amministrazione *_t = static_cast<amministrazione *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chiudiPremuto(); break;
        case 1: _t->profiloEliminato(); break;
        case 2: _t->schedaPremuta((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 3: _t->ricerca(); break;
        case 4: _t->disegnaUtenti(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (amministrazione::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&amministrazione::chiudiPremuto)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject amministrazione::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_amministrazione.data,
      qt_meta_data_amministrazione,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *amministrazione::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *amministrazione::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_amministrazione.stringdata0))
        return static_cast<void*>(const_cast< amministrazione*>(this));
    return QWidget::qt_metacast(_clname);
}

int amministrazione::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void amministrazione::chiudiPremuto()const
{
    QMetaObject::activate(const_cast< amministrazione *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
