/****************************************************************************
** Meta object code from reading C++ file 'enemigos.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Proyecto_Final/enemigos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enemigos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Enemigos_t {
    const uint offsetsAndSize[18];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Enemigos_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Enemigos_t qt_meta_stringdata_Enemigos = {
    {
QT_MOC_LITERAL(0, 8), // "Enemigos"
QT_MOC_LITERAL(9, 15), // "disparoGenerado"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 9), // "Enemigos*"
QT_MOC_LITERAL(36, 5), // "enemy"
QT_MOC_LITERAL(42, 8), // "Disparo*"
QT_MOC_LITERAL(51, 7), // "disparo"
QT_MOC_LITERAL(59, 16), // "cambiarDireccion"
QT_MOC_LITERAL(76, 8) // "disparar"

    },
    "Enemigos\0disparoGenerado\0\0Enemigos*\0"
    "enemy\0Disparo*\0disparo\0cambiarDireccion\0"
    "disparar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enemigos[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   37,    2, 0x0a,    4 /* Public */,
       8,    0,   38,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Enemigos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enemigos *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->disparoGenerado((*reinterpret_cast< std::add_pointer_t<Enemigos*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Disparo*>>(_a[2]))); break;
        case 1: _t->cambiarDireccion(); break;
        case 2: _t->disparar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Disparo* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Enemigos* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Enemigos::*)(Enemigos * , Disparo * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Enemigos::disparoGenerado)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Enemigos::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Enemigos.offsetsAndSize,
    qt_meta_data_Enemigos,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Enemigos_t
, QtPrivate::TypeAndForceComplete<Enemigos, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Enemigos *, std::false_type>, QtPrivate::TypeAndForceComplete<Disparo *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Enemigos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enemigos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enemigos.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Enemigos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Enemigos::disparoGenerado(Enemigos * _t1, Disparo * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
