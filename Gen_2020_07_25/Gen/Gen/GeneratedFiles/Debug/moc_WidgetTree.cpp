/****************************************************************************
** Meta object code from reading C++ file 'WidgetTree.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/WidgetTree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetTree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CWidgetTree[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x05,
      52,   42,   12,   12, 0x05,
      68,   42,   12,   12, 0x05,
      84,   12,   12,   12, 0x05,
      96,   42,   12,   12, 0x05,
     111,   12,   12,   12, 0x05,
     131,  122,   12,   12, 0x05,
     145,  122,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     177,  160,   12,   12, 0x0a,
     235,  223,   12,   12, 0x0a,
     277,   12,   12,   12, 0x0a,
     300,  292,   12,   12, 0x0a,
     324,   12,   12,   12, 0x0a,
     339,   12,   12,   12, 0x0a,
     360,   12,   12,   12, 0x0a,
     381,   12,   12,   12, 0x0a,
     400,   12,   12,   12, 0x0a,
     419,   12,   12,   12, 0x0a,
     439,   12,   12,   12, 0x0a,
     459,   12,   12,   12, 0x0a,
     479,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CWidgetTree[] = {
    "CWidgetTree\0\0newItem\0itemTreeChanged(int)\0"
    "numSourse\0copySourse(int)\0hideSourse(int)\0"
    "addSourse()\0delSourse(int)\0addMeteo()\0"
    "numMeteo\0delMeteo(int)\0copyMeteo(int)\0"
    "current,previous\0"
    "ChangePage(QTreeWidgetItem*,QTreeWidgetItem*)\0"
    "item,column\0OnItemDoubleClicked(QTreeWidgetItem*,int)\0"
    "EnterPressed()\0pointIn\0ShowContextMenu(QPoint)\0"
    "OnItemRename()\0OnCopySourseButton()\0"
    "OnHideSourseButton()\0OnAddMeteoButton()\0"
    "OnDelMeteoButton()\0OnAddSourseButton()\0"
    "OnDelSourseButton()\0OnCopyMeteoButton()\0"
    "OnHideMeteoButton()\0"
};

void CWidgetTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CWidgetTree *_t = static_cast<CWidgetTree *>(_o);
        switch (_id) {
        case 0: _t->itemTreeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->copySourse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->hideSourse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addSourse(); break;
        case 4: _t->delSourse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->addMeteo(); break;
        case 6: _t->delMeteo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->copyMeteo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ChangePage((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 9: _t->OnItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->EnterPressed(); break;
        case 11: _t->ShowContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->OnItemRename(); break;
        case 13: _t->OnCopySourseButton(); break;
        case 14: _t->OnHideSourseButton(); break;
        case 15: _t->OnAddMeteoButton(); break;
        case 16: _t->OnDelMeteoButton(); break;
        case 17: _t->OnAddSourseButton(); break;
        case 18: _t->OnDelSourseButton(); break;
        case 19: _t->OnCopyMeteoButton(); break;
        case 20: _t->OnHideMeteoButton(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CWidgetTree::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CWidgetTree::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_CWidgetTree,
      qt_meta_data_CWidgetTree, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWidgetTree::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWidgetTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWidgetTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWidgetTree))
        return static_cast<void*>(const_cast< CWidgetTree*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int CWidgetTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void CWidgetTree::itemTreeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CWidgetTree::copySourse(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CWidgetTree::hideSourse(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CWidgetTree::addSourse()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CWidgetTree::delSourse(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CWidgetTree::addMeteo()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void CWidgetTree::delMeteo(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CWidgetTree::copyMeteo(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
