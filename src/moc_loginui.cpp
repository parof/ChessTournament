/****************************************************************************
** Meta object code from reading C++ file 'loginui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "loginui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_loginUi_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loginUi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loginUi_t qt_meta_stringdata_loginUi = {
    {
QT_MOC_LITERAL(0, 0, 7), // "loginUi"
QT_MOC_LITERAL(1, 8, 10), // "provaLogin"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "creaNuovoProfilo"
QT_MOC_LITERAL(4, 37, 10) // "logPremuto"

    },
    "loginUi\0provaLogin\0\0creaNuovoProfilo\0"
    "logPremuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginUi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void loginUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loginUi *_t = static_cast<loginUi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->provaLogin(); break;
        case 1: _t->creaNuovoProfilo(); break;
        case 2: _t->logPremuto(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (loginUi::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&loginUi::provaLogin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (loginUi::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&loginUi::creaNuovoProfilo)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject loginUi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_loginUi.data,
      qt_meta_data_loginUi,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *loginUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginUi::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_loginUi.stringdata0))
        return static_cast<void*>(const_cast< loginUi*>(this));
    return QWidget::qt_metacast(_clname);
}

int loginUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void loginUi::provaLogin()const
{
    QMetaObject::activate(const_cast< loginUi *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void loginUi::creaNuovoProfilo()const
{
    QMetaObject::activate(const_cast< loginUi *>(this), &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_nuovoProfilo_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nuovoProfilo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nuovoProfilo_t qt_meta_stringdata_nuovoProfilo = {
    {
QT_MOC_LITERAL(0, 0, 12), // "nuovoProfilo"
QT_MOC_LITERAL(1, 13, 10), // "confermato"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "annullato"
QT_MOC_LITERAL(4, 35, 13) // "provaConferma"

    },
    "nuovoProfilo\0confermato\0\0annullato\0"
    "provaConferma"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nuovoProfilo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void nuovoProfilo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nuovoProfilo *_t = static_cast<nuovoProfilo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->confermato(); break;
        case 1: _t->annullato(); break;
        case 2: _t->provaConferma(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (nuovoProfilo::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nuovoProfilo::confermato)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (nuovoProfilo::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nuovoProfilo::annullato)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject nuovoProfilo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nuovoProfilo.data,
      qt_meta_data_nuovoProfilo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *nuovoProfilo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nuovoProfilo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_nuovoProfilo.stringdata0))
        return static_cast<void*>(const_cast< nuovoProfilo*>(this));
    return QWidget::qt_metacast(_clname);
}

int nuovoProfilo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void nuovoProfilo::confermato()const
{
    QMetaObject::activate(const_cast< nuovoProfilo *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void nuovoProfilo::annullato()const
{
    QMetaObject::activate(const_cast< nuovoProfilo *>(this), &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
