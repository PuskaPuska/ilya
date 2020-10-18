/****************************************************************************
** Meta object code from reading C++ file 'gen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/gen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x08,
      15,    4,    4,    4, 0x08,
      26,    4,    4,    4, 0x08,
      39,    4,    4,    4, 0x08,
      50,    4,    4,    4, 0x08,
      71,   63,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Gen[] = {
    "Gen\0\0NewCalc()\0LoadCalc()\0LoadParams()\0"
    "SaveCalc()\0SaveParams()\0numItem\0"
    "OnItemTreeChange(int)\0"
};

void Gen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Gen *_t = static_cast<Gen *>(_o);
        switch (_id) {
        case 0: _t->NewCalc(); break;
        case 1: _t->LoadCalc(); break;
        case 2: _t->LoadParams(); break;
        case 3: _t->SaveCalc(); break;
        case 4: _t->SaveParams(); break;
        case 5: _t->OnItemTreeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gen,
      qt_meta_data_Gen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gen))
        return static_cast<void*>(const_cast< Gen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
